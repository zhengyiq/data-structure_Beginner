#pragma once
#include <utility> 
template<class K, size_t M>
struct BTreeNode
{
	//K _keys[M - 1];
	//BTreeNode<K, M>* _subs[M];
	
	// 为了方便插入之后再分裂，多给一个空间
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];
	BTreeNode<K, M>* _parent;
	size_t _n;

	BTreeNode()
	{
		for (size_t i = 0; i < M; ++i)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}
		_subs[M] = nullptr;
		_parent = nullptr;
		_n = 0;
	}
};


// 数据存储在磁盘，K是磁盘地址
template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:

	std::pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			// 在一个节点中进行搜索
			size_t i = 0;
			while (i < cur->_n)
			{
				if (key < cur->_keys[i])
				{
					break;
				}
				else if (key > cur->_keys[i])
				{
					++i;
				}
				else return std::make_pair(cur, i);
			}
			// 往孩子去跳
			parent = cur;
			cur = cur->_subs[i];
		}
		return std::make_pair(parent, -1);
	}

	void InsertKey(Node* node, const K& key, Node* child)
	{
		int end = node->_n - 1;
		while (end >= 0)
		{
			if (key < node->_keys[end])
			{
				// 挪动key和它的右孩子
				node->_keys[end + 1] = node->_keys[end];
				node->_subs[end + 2] = node->_subs[end + 1];
				--end;
			}
			else
			{
				break;
			}
		}

		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child;
		if (child)
		{
			child->_parent = node;
		}
		node->_n++;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;

			return true;
		}

		// key已经存爱，不允许插入
		std::pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		// 如果没有，find顺便带回要插入的叶子结点

		// 循环每次往cur插入newkey和child
		Node* parent = ret.first;
		K newKey = key;
		Node* child = nullptr;

		while (1)
		{
			InsertKey(parent, newKey, child);
			// 满了就需要分裂
			// 没有就插入结束
			if (parent->_n < M) return true;
			else
			{
				size_t mid = M / 2;
				// 分裂一半[mid + 1, M - 1]给兄弟
				Node* brother = new Node;
				size_t j = 0;
				size_t i = mid + 1;
				for (; i <= M - 1; ++i)
				{
					// key和key的左孩子
					brother->_keys[j++] = parent->_keys[i];
					brother->_subs[j++] = parent->_subs[i];
					if (parent->_subs[i])
					{
						parent->_subs[i]->_parent = brother;
					}
					++j;

					// 拷走重置方便观察
					parent->_keys[i] = K();
					parent->_subs[i] = nullptr;
				}

				//还有最后一个右孩子 M - 1
				brother->_subs[j] = parent->_subs[i];
				if (parent->_subs[i])
				{
					parent->_subs[i]->_parent = brother;
				}

				parent->_subs[i] = nullptr;
				brother->_n = j;
				parent->_n -= (brother->_n + 1);


				K midKey = parent->_keys[mid];
				parent->_keys[mid] = K();
				// 说明刚刚分裂的是根节点
				if (parent->_parent == nullptr)
				{
					_root = new Node;
					_root->_keys[0] = midKey;
					_root->_subs[0] = parent;
					_root->_subs[1] = brother;
					parent->_parent = _root;
					brother->_parent = _root;
					_root->_n = 1;
					break;
				}
				else
				{
					// 转换为往parent->parent 去插入parent->[mid] 和 brother
					newKey = midKey;
					child = brother;
					parent = parent->_parent;
				}
			}
		}
		return true;
	}
private:
	Node* _root = nullptr;
};

void TestBTree()
{
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
}
