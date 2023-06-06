#include <iostream>
#include <ctype.h>
#define size 50
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
	bool islth;
	bool isrth;
	TreeNode() : data(0), left(nullptr), right(nullptr), islth(true), isrth(true) {}
	TreeNode(int x) : data(x), left(nullptr), right(nullptr), islth(true), isrth(true) {}
	TreeNode(int x, TreeNode *left, TreeNode *right, bool lth, bool rth) : data(x), left(left), right(right), islth(lth), isrth(rth) {}
};

class Thread
{
public:
	TreeNode *_root, *_dummy;
	Thread();
	TreeNode *getLeftLeaf(TreeNode *parent, int data);
	TreeNode *getRightLeaf(TreeNode *parent, int data);
	void insertNode(TreeNode *curr, int data);
	void createTBST();
	void inorderTrev();
};

Thread ::Thread()
{
	_root = NULL;
	_dummy = new TreeNode(-1);
	_dummy->left = _dummy->right = _dummy;
	_dummy->islth = _dummy->isrth = false;
}

TreeNode *Thread::getLeftLeaf(TreeNode *parent, int data)
{
	return new TreeNode(data, parent->left, parent, true, true);
}

TreeNode *Thread ::getRightLeaf(TreeNode *parent, int data)
{
	return new TreeNode(data, parent, parent->right, true, true);
}

void Thread ::insertNode(TreeNode *curr, int data)
{
	/**
	 * insert  a node in Treaded BST.
	 */
	if (_root == NULL) // root node absent
	{
		_root = getLeftLeaf(_dummy, data);
		_dummy->left = _root;
		return;
	}
	if (data < curr->data)
	{
		if (curr->islth)
		{
			curr->left = getLeftLeaf(curr, data);
			curr->islth = false;
		}
		else
		{
			insertNode(curr->left, data);
		}
	}
	else
	{
		if (curr->isrth)
		{
			curr->right = getRightLeaf(curr, data);
			curr->isrth = false;
		}
		else
		{
			insertNode(curr->right, data);
		}
	}
}

void Thread ::createTBST()
{
	int numNodes;
	cout << "The number of nodes in threaded binary tree:" << endl;
	cin >> numNodes;

	int data;
	while (numNodes--)
	{
		cin >> data;
		insertNode(_root, data);
	}
}

void Thread ::inorderTrev()
{
	TreeNode *curr = _root;
	while (!curr->islth)
	{
		curr = curr->left;
	}
	// cout << curr->data << " ";
	// curr = curr->right;
	while (curr != _dummy)
	{
		cout << curr->data << " ";
		if (curr->isrth)
		{
			curr = curr->right;
			// continue;
		}
		else
		{
			curr = curr->right;
			while (!curr->islth)
			{
				curr = curr->left;
			}
			cout << curr->data << " ";
			curr = curr->right;
		}
	}
}

int main(int argc, char const *argv[])
{
	Thread t;
	// cout << t._dummy->left->data << " " << bool(t._dummy->left == t._dummy) << " " << t._dummy->isrth << endl;
	// t.insertNode(t._root, 6);
	// t.insertNode(t._root, 3);
	// t.insertNode(t._root, 6);
	t.createTBST();
	// cout << t._dummy->left->data << " " << bool(t._dummy->left == t._dummy) << " " << t._dummy->isrth << endl;
	// cout << t._root->data << " " << t._root->left->data << " " << t._root->right->data << endl;
	cout<<"inorder traversal: ";
	t.inorderTrev();
	return 0;
}