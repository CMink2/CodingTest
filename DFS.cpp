#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//Depth First Search function
void DepthFirstSearch(int v);

//visited node value
static vector<bool> visited;

//nodes
static vector<vector<int>> nodes;

int main()
{
	//Node count Edge count
	int N, M;
	cin >> N >> M;
	//connection Graph count
	int count = 0;
	//initialized vectors
	nodes.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	//enter edge data.
	for (size_t i = 0; i < M; i++)
	{
		//start node, end node
		int start, end;
		cin >> start >> end;

		//no direction
		nodes[start].push_back(end);
		nodes[end].push_back(start);
	}
	//all node visited?
	for (size_t i = 1; i < N + 1; i++)	//nods's start index = 1
	{
		//Once visited nodes are not visited again.
		if (visited[i])
			continue;

		//start Searching
		count++;
		DepthFirstSearch(i);
	}
	//result
	cout << count << "\n";
	return 0;
}

//Depth First Search
void DepthFirstSearch(int v)
{
	//excape condition => visited node
	if (visited[v])
		return;

	//visit node
	visited[v] = true;

	//go to connected node 
	for (int i : nodes[v])	//touring connection node
	{
		DepthFirstSearch(i);
	}
}