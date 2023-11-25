#include<iostream>
#include<vector>
using namespace std;
static vector<vector<int>> treeList;
static vector<bool> visited;
static int result = 0;	//leaf node count.
static int N, D, root;	//node's count, delete node, root node.
void DFS(int x);
int main()
{
	//node's cont.
	cin >> N;
	visited.resize(N, false);
	treeList.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		int node;
		cin >> node;
		//root node condition
		if (node == -1)
			root = i;
		else
		{
			//tree data.
			treeList[i].push_back(node);
			treeList[node].push_back(i);
		}
	}
	//delete node.
	cin >> D;
	//excpt condition. -> empty
	if (D == root)
		cout << 0;
	else
	{
		DFS(root);
		cout << result;
	}
}
void DFS(int x)
{
	visited[x] = true;
	int child = 0;	//child node's count.
	for (int i : treeList[x])
	{
		//delate node = next node => ignore
		if (!visited[i] && i != D)
		{
			child++;
			DFS(i);
		}
	}
	//leaf node condition.
	if (child == 0)
		result++;
}