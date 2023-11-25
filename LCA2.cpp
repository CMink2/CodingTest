#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, M;
int a, b;
queue<int>q;
vector<int> node[100001];
bool visited[100001];
int parent[100001][20];
int depth[100001];
int LCA(int a, int b);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	//tree setting.
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	visited[1] = true;
	q.push(1); // start root

	//BFS.
	while (!q.empty())
	{
		int x = q.front(); // parrent node. = current node.
		q.pop();
		for (int i = 0; i < node[x].size(); i++)
		{
			//child node = next node.
			int child = node[x][i];
			if (!visited[child]) //if not visited.
			{
				depth[child] = depth[x] + 1; // increase depth
				visited[child] = true; //visited.
				parent[child][0] = x;
				for (int j = 0; j < 20; j++) // set parent.
				{
					//set parent matrix.
					parent[child][j + 1] = parent[parent[child][j]][j];
					//fill up.
					if (parent[child][j + 1] == 0) break;
				}
				q.push(child); //push this queue.
			}
		}
	}
	//get test count
	cin >> M;
	//print result.
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout <<"result : " << LCA(a, b) << '\n';
	}
}

int LCA(int a, int b)
{
	//set ordering
	if (depth[a] > depth[b]) swap(a, b);
	while (depth[a] != depth[b])
	{
		int diff = depth[b] - depth[a];
		for (size_t i = 0; i < 20; i++)
		{
			//2, 4, 6, 8, 16 ...
			if (diff <= (2 << i))
			{
				b = parent[b][i];	//find parent.
				break;
			}
		}
	}
	//find LCA.
	while (a != b)
	{
		for (size_t i = 0; i < 20; i++)
		{
			//find a LCA
			if (parent[a][i + 1] == parent[b][i + 1])
			{
				//move parent.
				a = parent[a][i];
				b = parent[b][i];
				break;
			}			
		}
		return a;
	}
}