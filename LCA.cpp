#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static vector<vector<int>> tree;
static vector<int> parent;
static vector<bool> visited;
static vector<int> depth;
static int depthCount = 1;
static int N, M;
int LCA(int a, int b);
void BFS(int x);
int main()
{
	cin >> N;
	//resize vector.
	tree.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1, false);
	depth.resize(N + 1, 0);
	//set tree.
	for (size_t i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	//set depth, visited, parent.
	queue<int> mq;
	mq.push(1);
	visited[1] = true;
	int count = 0;
	int size = 1;
	while (!mq.empty())
	{
		//get current node.
		int current = mq.front();
		mq.pop();
		//get next depth level node.
		for (int next : tree[current])
		{
			if (!visited[next])
			{
				visited[next] = true;
				//set parent.
				parent[next] = current;
				//set depthCount.
				depth[next] = depth[current] + 1;
				//push queue.
				mq.push(next);
			}
		}
	}

	//get test count.
	cin >> M;
	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << "result : " <<  LCA(a, b) << endl;
	}
	return 0;
}
void BFS(int x)
{
	
}
int LCA(int a, int b)
{
	//swap.
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	//set depth condition.
	while (depth[a] != depth[b])
		a = parent[a];
	//find LCA = parent node same 
	while (a != b)
	{
		//move parent node.
		a = parent[a];
		b = parent[b];
	}
	return a;
}