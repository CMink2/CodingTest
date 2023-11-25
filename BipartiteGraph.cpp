#include<iostream>
#include<vector>
using namespace std;
static vector<vector<int>> A;	//adjacency list
static vector<int> check;
static vector<bool> visited;
static bool isEven;
void DFS(int n);
int main()
{
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		//vertex edge
		int V, E;
		cin >> V >> E;
		//resize all vectors
		check.clear();
		check.resize(V + 1);
		visited.clear();
		visited.resize(V + 1);
		A.clear();
		A.resize(V + 1);
		//BipartiteGraph check condition.
		isEven = true;
		for (size_t t = 0; t < E; t++)
		{
			int s, e;
			cin >> s >> e;
			//no direction graph
			A[s].push_back(e);
			A[e].push_back(s);
		}
		for(int node = 1; node<=V; node++ )
		{
			//check Graph connection / group.
			DFS(node);
		}		
		if (isEven)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}
void DFS(int n)
{
	//visit.
	visited[n] = true;
	for (int i : A[n])
	{
		//visti node ande set differnet group.
		if (!visited[i])
		{
			//set different group.
			check[i] = (check[n] + 1) % 2;
			//recursive.
			DFS(i);
		}
		//same group parent node. child node's group != Parent node's group => !BipartiteGraph
		else if (check[n] == check[i])
		{
			isEven = false;
		}
	}
}