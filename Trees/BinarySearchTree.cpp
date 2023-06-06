#include <iostream>
#include <climits>
// #include <ctype.h>
#define size 50
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class stack
{
	TreeNode *arr[size];
	int top;

public:
	stack() : top(-1) {}

	bool empty()
	{
		return (top == -1);
	}
	bool full()
	{
		return (top == size - 1);
	}
	void push(TreeNode *node)
	{
		arr[++top] = node;
	}
	TreeNode *pop()
	{
		TreeNode *temp = arr[top--];
		return temp;
	}
	const TreeNode *peek()
	{
		const TreeNode *temp = arr[top];
		return temp;
	}
};

class queue
{
	int front;
	int rear;
	TreeNode *arr[size];

public:
	queue() : front(-1), rear(-1) {}

	bool isempty()
	{
		return rear == -1;
	}
	void reset()
	{
		front = rear = -1;
	}
	bool isfull()
	{
		return front == (rear + 1) % size;
	}
	bool enque(TreeNode *node)
	{
		if (isfull())
			return false;
		if (front == -1)
			front++;
		rear = (rear + 1) % size;
		arr[rear] = node;
		return true;
	}
	const TreeNode *infront() const
	{
		return arr[front];
	}
	TreeNode *deque()
	{
		if (isempty())
			return nullptr;

		TreeNode *temp = arr[front];
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (++front) % size;
		}
		return temp;
	}
};

class BinarySearchTree
{
	int *arr;

	void inorder(TreeNode *root, string &s);
	TreeNode *mirror(TreeNode *curr);
	TreeNode *copy(TreeNode *curr);

public:
	TreeNode *root;
	BinarySearchTree() : root(NULL), arr(NULL) {}
	TreeNode *&get_root()
	{
		return root;
	}
	TreeNode *getMinOfSubtree(TreeNode *root);
	TreeNode *popMinOfSubtree(TreeNode *curr);
	TreeNode *popMaxOfSubtree(TreeNode *curr);
	TreeNode *getMaxOfSubtree(TreeNode *root);
	void createBST();
	void insertInBST(TreeNode *curr, int data);
	int deleteInBsT(TreeNode *root, int data);
	bool searchForElement(TreeNode *curr, int data);
	bool getParentAndCurr(TreeNode *&curr, TreeNode *&parent, int data);
	void breathFirstSearch(TreeNode *curr);
	bool checkBST();
	void mirrorBst(TreeNode *&new_root);
	void copyBst(TreeNode *&new_root);
};

void BinarySearchTree::breathFirstSearch(TreeNode *curr)
{
	if (!curr)
	{
		return;
	}
	queue parent, child;
	// one queue
	parent.enque(curr);
	cout << "BFS start" << endl;
	int i = 1;
	while (!parent.isempty())
	{
		parent.enque(NULL);
		cout << "layer " << i++ << " :";
		while (parent.infront() != NULL)
		{
			TreeNode *temp = parent.deque();
			cout << temp->val << " ";
			if (temp->left)
				parent.enque(temp->left);
			if (temp->right)
				parent.enque(temp->right);
		}
		parent.deque();
		cout << endl; // layer over
	}
	cout << "BFS end" << endl;

	// two queue
	// parent.enque(curr);
	// cout << "start" << endl;
	// while (!parent.isempty())
	// {
	// 	while (!parent.isempty())
	// 	{
	// 		TreeNode *temp = parent.deque();
	// 		cout << temp->val << " ";
	// 		if (temp->left)
	// 			child.enque(temp->left);
	// 		if (temp->right)
	// 			child.enque(temp->right);
	// 	}
	// 	parent = child;
	// 	child.reset();
	// 	cout << endl;
	// }
	// cout << "end" << endl;
}
bool BinarySearchTree::searchForElement(TreeNode *curr, int data)
{
	if (!curr)
	{
		cout << "node not found :(" << endl;
		return false;
	}
	if (curr->val == data)
	{
		cout << "node found !!" << endl;
		return true;
	}
	if (data < curr->val)
	{
		return searchForElement(curr->left, data);
	}
	else
	{
		return searchForElement(curr->right, data);
	}
}

bool BinarySearchTree::getParentAndCurr(TreeNode *&curr, TreeNode *&parent, int data)
{
	// bool is_present = searchForElement(curr,data);
	// if(is_present){
	while (curr != NULL)
	{
		if (data == curr->val)
		{
			cout << "curr->val: " << curr->val << endl;
			cout << " parent->val: ";
			if (parent != NULL)
				cout << parent->val << endl;
			else
				cout << "parent==NULL" << endl;
			return true;
		}
		if (data < curr->val)
		{
			if (curr->left == NULL)
			{
				break;
			}
			parent = curr;
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
			{
				break;
			}
			parent = curr;
			curr = curr->right;
		}
	}
	cout << "node missed!!!!" << endl;
	// }
	return false;
}

TreeNode *BinarySearchTree::getMinOfSubtree(TreeNode *curr)
{
	TreeNode *min = curr;
	while (min->left != NULL)
	{
		min = min->left;
	}
	cout << "the lowest node-value of the subtree: " << min->val << endl;
	return min;
}
TreeNode *BinarySearchTree::popMinOfSubtree(TreeNode *curr)
{
	TreeNode *parent = curr;
	TreeNode *min = curr->right;
	while (min->left != NULL)
	{
		parent = min;
		min = min->left;
	}
	cout << "the lowest node-value of the subtree: " << min->val << endl;
	if (parent != curr)
		parent->left = NULL;
	else
		parent->right = NULL;
	return min;
}
TreeNode *BinarySearchTree::getMaxOfSubtree(TreeNode *curr)
{
	TreeNode *max = curr;
	while (max->right != NULL)
	{
		max = max->right;
	}
	cout << "the higest node-value of the subtree: " << max->val << endl;
	return max;
}
TreeNode *BinarySearchTree::popMaxOfSubtree(TreeNode *root)
{
	TreeNode *parent = root;
	TreeNode *max = root->left;
	while (max->right != NULL)
	{
		parent = max;
		max = max->right;
	}
	cout << "the higest node-value of the subtree: " << max->val << endl;
	if (parent != root)
		parent->right = NULL;
	else
		parent->left = NULL;
	return max;
}

void BinarySearchTree::inorder(TreeNode *root, string &inorder_op)
{
	if (root)
	{
		inorder(root->left, inorder_op);
		cout << root->val << " ";
		inorder_op.push_back(root->val);
		inorder(root->right, inorder_op);
	}
}

bool BinarySearchTree::checkBST()
{
	string inorder_op = "";
	inorder(root, inorder_op);
	for (int i = 1; i < inorder_op.length(); i++)
	{
		if (inorder_op.at(i - 1) > inorder_op.at(i))
		{
			cout << endl
				 << "the BST is not generated correctly :(." << endl;
			return false;
		}
	}
	cout << endl
		 << "the BST is generated perfectly!!." << endl;
	return true;
}

void BinarySearchTree::insertInBST(TreeNode *curr, int data)
{
	if (curr == NULL)
	{
		curr = new TreeNode(data);
		if (root == NULL)
			root = curr;
		return;
	}
	if (data < curr->val)
	{
		if (curr->left == NULL)
		{
			curr->left = new TreeNode(data);
		}
		else
			insertInBST(curr->left, data);
	}
	else
	{
		if (curr->right == NULL)
		{
			curr->right = new TreeNode(data);
		}
		else
			insertInBST(curr->right, data);
	}
}

void BinarySearchTree::createBST()
{
	int no_nodes;
	cout << "the number of nodes in BST: " << endl;
	cin >> no_nodes;
	arr = new int[no_nodes];
	for (int i = 0; i < no_nodes; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < no_nodes; i++)
	{
		insertInBST(root, arr[i]);
	}
}

int BinarySearchTree::deleteInBsT(TreeNode *root, int data)
{
	TreeNode *curr = root, *parent = NULL;
	bool is_present = getParentAndCurr(curr, parent, data);
	if (is_present)
	{
		// node is present in the tree
		if (curr->left == NULL && curr->right == NULL)
		{
			// its a leaf node
			if (parent && curr->val < parent->val)
			{
				parent->left = NULL;
			}
			else if (parent)
			{
				parent->right = NULL;
			}
			if (root == curr)
			{
				this->root = NULL;
			}
			int temp = curr->val;
			delete curr;
			return temp;
		}
		else if (curr->left != NULL && curr->right == NULL)
		{
			// curr has only left child
			if (parent && curr->val < parent->val)
			{
				parent->left = curr->left;
			}
			else if (parent)
			{
				parent->right = curr->left;
			}
			if (root == curr)
			{
				this->root = curr->left;
			}
			int temp = curr->val;
			delete curr;
			return temp;
		}
		else if (curr->left == NULL && curr->right != NULL)
		{
			// curr has only right
			if (parent && curr->val < parent->val)
			{
				parent->left = curr->right;
			}
			else if (parent)
			{
				parent->right == curr->right;
			}
			if (root == curr || parent == NULL)
			{
				this->root = curr->right;
			}
			int temp = curr->val;
			delete curr;
			return temp;
		}
		else
		{
			// curr has both child
			char replacement;
			cout << "It's an intermidiate node with 2 childs.\nSo to select the replacement:\n\
1. for inorder predecessor: 'p' or 'P'\n2. for inorder successor: 's' or 'S'"
				 << endl;
			cin >> replacement;
			if (replacement == 'p' || replacement == 'P')
			{
				TreeNode *inodr_pre = popMaxOfSubtree(curr);

				if (parent && curr->val < parent->val)
				{
					parent->left = inodr_pre;
				}
				else if (parent)
				{
					parent->right = inodr_pre;
				}
				if (root == curr || parent == NULL)
				{
					this->root = inodr_pre;
				}
				inodr_pre->left = curr->left;
				inodr_pre->right = curr->right;
				int temp = curr->val;
				delete curr;
				return temp;
			}
			else
			{
				TreeNode *inodr_succ = popMinOfSubtree(curr);

				if (parent && curr->val < parent->val)
				{
					parent->left = inodr_succ;
				}
				else if (parent)
				{
					parent->right = inodr_succ;
				}
				if (root == curr)
				{
					this->root = inodr_succ;
				}
				inodr_succ->left = curr->left;
				inodr_succ->right = curr->right;
				int temp = curr->val;
				delete curr;
				return temp;
			}
		}
	}
	return 0;
}

TreeNode *BinarySearchTree::mirror(TreeNode *curr)
{
	if (!curr)
	{
		return NULL;
	}
	TreeNode *lft = mirror(curr->left);
	TreeNode *rgt = mirror(curr->right);
	curr->left = rgt;
	curr->right = lft;
	return curr;
}
void BinarySearchTree::mirrorBst(TreeNode *&new_root)
{
	TreeNode *temp = mirror(root);
	new_root = temp;
}
TreeNode *BinarySearchTree::copy(TreeNode *curr)
{
	if (!curr)
	{
		return NULL;
	}
	TreeNode *lft = copy(curr->left);
	TreeNode *rgt = copy(curr->right);
	TreeNode *node = new TreeNode(curr->val);
	node->left = rgt;
	node->right = lft;
	return node;
}
void BinarySearchTree::copyBst(TreeNode *&new_root)
{
	TreeNode *temp = copy(root);
	new_root = temp;
}

int main(int argc, char const *argv[])
{
	BinarySearchTree bst;
	bst.createBST();
	bst.checkBST();

	bst.breathFirstSearch(bst.get_root());
	BinarySearchTree mirr, cpy;
	int node;
	cout<<"Enter the element ot be searched"<<endl;
	cin>>node;
	bst.searchForElement(bst.get_root(),node);
	cout<<"Enter the element ot be deleted"<<endl;
	cin>>node;
	bst.deleteInBsT(bst.get_root(),node);
	bst.mirrorBst(mirr.root);
	mirr.breathFirstSearch(mirr.root);
	bst.copyBst(cpy.root);
	mirr.breathFirstSearch(cpy.root);
	return 0;
}
// 11 22 14 30 18 17 20 15 14 15 17 19
// 13 4 2 8 0 3 6 10 1 5 7 9 12 11