#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int value;

	Node *right, *left;
	
};

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(Node *root)
{
	if(root == NULL) return;

	cout << root->value << " ";

	preorder(root->left);

	preorder(root->right);
}

void inorder(Node *root)
{
	if(!root) return;

	inorder(root->left);

	cout << root->value << " ";

	inorder(root->right);
}

void postorder(Node *root)
{
	if(!root) return;

	postorder(root->left);

	postorder(root->right);

	cout << root->value << " ";
}

vector<int> levelorder(Node *root, vector<int> &v)
{
	queue<Node*> q;

	q.push(root);

	while(!q.empty())
	{
		Node *n = q.front();

		q.pop();

		v.push_back(n->value);

		if(n->left) q.push(n->left);

		if(n->right) q.push(n->right);
	}

	return v;
}

int main()
{
	int n;

	cin>>n;

	Node* root = CreateNode(n);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
	cout << '\n';

	vector<int> v;

	vector<int> vec = levelorder(root,v);

	for(auto i:vec)
	{
		cout << i << " ";
	}
	cout << '\n';
}