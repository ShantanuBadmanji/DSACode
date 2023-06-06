#include <iostream>
// #include <ctype.h>
#define size 10
using namespace std;
class TreeNode
{
public:
	char data;
	TreeNode *right, *left;
	TreeNode(char _data = '\0')
	{
		data = _data;
		right = NULL;
		left = NULL;
	}
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

class Tree
{
	TreeNode *root;

public:
	Tree() : root(NULL) {}

	TreeNode* const getRoot() const;
	void postOdr_createTree();
	void preOdr_createTree();

	void preOrderTrav(TreeNode *node);
	void inOrderTrav(TreeNode *node);
	void postOrderTrav(TreeNode *node);
	void non_preOrderTrav(TreeNode *node);
	void non_inOrderTrav(TreeNode *node);
	void non_postOrderTrav(TreeNode *node);
};
TreeNode * const Tree::getRoot() const
{
	return root;
}
void Tree::postOdr_createTree()
{
	// char exp[10];
	string exp;
	TreeNode *temp, *temp1, *temp2;
	stack s;
	cout << "Enter the postfix expression: " << endl;
	cin >> exp;
	// exp = "ab+cd-*";
	// 	cout << exp << endl;
	// char ch;
	// int i = 0;
	for (char ch : exp)
	{
		if (isalnum(ch))
		{
			temp = new TreeNode(ch);
			s.push(temp);
		}
		else
		{
			temp2 = s.pop();
			temp1 = s.pop();
			temp = new TreeNode(ch);
			temp->left = temp1;
			temp->right = temp2;
			s.push(temp);
		}
	}
	root = s.pop();
	// exp.clear();
}
void Tree::preOdr_createTree()
{
	string exp;
	TreeNode *temp, *temp1, *temp2;
	stack s;
	cout << "Enter the prefix expression: " << endl;
	cin >> exp;
	// exp = "ab+cd-+";
	cout << exp << endl;
	char ch;
	int i = 0;
	while ((ch = exp[exp.length() - 1 - i++]) != '\0')
	{
		if (isalnum(ch))
		{
			temp = new TreeNode(ch);
			s.push(temp);
		}
		else

		{
			temp2 = s.pop();
			temp1 = s.pop();
			temp = new TreeNode(ch);
			temp->left = temp2;
			temp->right = temp1;
			s.push(temp);
		}
	}
	root = s.pop();
	// exp.clear();
}

void Tree::preOrderTrav(TreeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << " ";
	preOrderTrav(node->left);
	preOrderTrav(node->right);
}
void Tree::inOrderTrav(TreeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	inOrderTrav(node->left);
	cout << node->data << " ";
	inOrderTrav(node->right);
}
void Tree::postOrderTrav(TreeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	postOrderTrav(node->left);
	postOrderTrav(node->right);
	cout << node->data << " ";
}

void Tree::non_preOrderTrav(TreeNode *root)
{
	TreeNode *node = root;
	stack s;
	while (node != NULL)
	{
		cout << node->data << " ";
		s.push(node);
		node = node->left;
	}
	while (!s.empty())
	{
		node = s.pop();
		node = node->right;
		while (node != NULL)
		{
			cout << node->data << " ";
			s.push(node);
			node = node->left;
		}
	}
	cout << endl;
}
void Tree::non_inOrderTrav(TreeNode *root)
{
	stack s;
	TreeNode *node = root;
	while (node != NULL)
	{
		s.push(node);
		node = node->left;
	}
	while (!s.empty())
	{
		node = s.pop();
		cout << node->data << " ";
		node = node->right;
		while (node != NULL)
		{
			s.push(node);
			node = node->left;
		}
	}
	cout << endl;
}
void Tree::non_postOrderTrav(TreeNode *root)
{
	stack s, flag;
	TreeNode *node = root;
	while (node != NULL)
	{
		s.push(node);
		flag.push(NULL);
		node = node->left;
	}
	while (!s.empty())
	{

		if (flag.pop() == NULL)
		{
			flag.push((TreeNode *)1);
			node = s.peek()->right;

			while (node != NULL)
			{
				s.push(node);
				flag.push(NULL);
				node = node->left;
			}
		}
		else
		{
			cout << s.pop()->data << " ";
		}
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	// Tree t;
	// // CREATE tree
	// t.postOdr_createTree();

	// t.inOrderTrav(t.root);
	// cout << endl;
	// t.preOrderTrav(t.root);
	// cout << endl;
	// t.postOrderTrav(t.root);
	// cout << endl;

	// // NON_REC
	// cout << endl;
	// t.non_inOrderTrav(t.root);
	// t.non_preOrderTrav(t.root);
	// t.non_postOrderTrav(t.root);
	bool is_on = true;
	Tree t;
	do
	{
		string menu = "----------------- MENU ---------------------";
		cout << endl
			 << menu << endl;
		char op;
		cout << "1. Create a new Tree\n2. Recursive Inorder traversal\n3. Recursive Preorder traversal\n4. Recursive Postorder traversal\n5. Iterative Inorder traversal\n6. Iterative Preorder traversal\n7. Iterative Postorder traversal\n8. EXIT" << endl;
		cout << "Select an option: " << endl;
		cin >> op;
		switch (op)
		{
		case '1':
			t.postOdr_createTree();
			break;

		case '2':
			t.inOrderTrav(t.getRoot());
			break;

		case '3':
			t.preOrderTrav(t.getRoot());
			break;

		case '4':
			t.postOrderTrav(t.getRoot());
			break;

		case '5':
			t.non_inOrderTrav(t.getRoot());
			break;

		case '6':
			t.non_preOrderTrav(t.getRoot());
			break;

		case '7':
			t.non_postOrderTrav(t.getRoot());
			break;

		case '8':
			cout << "Thank You" << endl;
			is_on = false;
			break;
		}
	} while (is_on);

	return 0;
}