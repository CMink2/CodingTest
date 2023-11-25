#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static int N;
//tree. => array's index = ascii code's value (A-Z)
pair <char, char> tree[26];

void preorder(char x);
void inorder(char x);
void postorder(char x);

class node
{
public :
	char data;
	node* left;
	node* right;

	node(char v)
	{
		data = v;
		left = NULL;
		right = NULL;
	}
};
node* CreateTree()
{
	
	for (size_t i = 0; i < N; i++)
	{
		char A, B, C;
		cin >> A >> B >> C;
		if (i == 0)
		{
			node* root = new node(A);
		}
	}
}
node* CreateNode(char data)
{
	node* newnode = new node(data);
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
node* InsertNode(node* root, char c)
{
	if (root == NULL)
	{
		root = CreateNode(c);
		return root;
	}
	queue<node*> q;
	q.push(root);
	while (q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp->left == NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = CreateNode(c);
			return root;
		}
		if (temp->right == NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = CreateNode(c);
			return root;
		}
	}
}
void Preorder(node* n)
{
	if (n != NULL)
	{
		cout << n->data << "->";
		Preorder(n->left);
		Preorder(n->right);
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		
		//set index = ascii code value.
		tree[(parent - 'A')].first = left;
		tree[(parent - 'A')].second = right;
	}
	//preorder
	preorder('A');
	cout << endl;
	//inorder
	inorder('A');
	cout << endl;
	//postorder
	postorder('A');
}

void preorder(char x)
{
	//if not null.
	if (x != '.')
	{
		//result
		cout << x << "\t";
		//move left.
		preorder(tree[x - 'A'].first);
		//move right
		preorder(tree[x - 'A'].second);
	}
}
void inorder(char x)
{
	//if not null.
	if (x != '.')
	{
		//move left.
		inorder(tree[x - 'A'].first);
		//result
		cout << x << "\t";
		//move right
		inorder(tree[x - 'A'].second);
	}
}
void postorder(char x)
{
	//if not null.
	if (x != '.')
	{
		//move left.
		postorder(tree[x - 'A'].first);
		//move right
		postorder(tree[x - 'A'].second);
		//result
		cout << x << "\t";
	}
}