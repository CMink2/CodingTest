#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//dfs function
void DFS(int v);
//bfs function
void BFS(int v);
static int Start;
static vector<bool> visited;
static vector<vector<int>> nodes;
int main()
{
	//node count, edge count
	int N, M;
	cin >> N >> M >> Start;
	//init vector
	nodes.resize(N + 1);
	visited.resize(N + 1, false);
	//graph data init
	for (int i = 1; i < M + 1; i++)
	{
		//start node, end node
		int start, end;
		cin >> start >> end;
		//no direction
		nodes[start].push_back(end);
		nodes[end].push_back(start);
	}
	//sort graph
	for (size_t i = 1; i < N+1; i++)
		sort(nodes[i].begin(), nodes[i].end());
	
	cout << "DFS" << "\t";
	DFS(Start);
	cout <<"\n";
	//init visited vector.
	fill(visited.begin(), visited.end(), false);
	cout << "BFS" << "\t";
	BFS(Start);
	
	return 0;
}
void BFS(int v)
{
	if (visited[v])
		return;
	queue<int> myQueue;
	myQueue.push(v);
	//visit
	visited[v] = true;
	cout << v << "\t";
	//queue empty = end this process
	while (!myQueue.empty())
	{
		//next node
		int next = myQueue.front();
		//deleate current node
		myQueue.pop();
		for (int i : nodes[next])
		{
			if (visited[i])
				continue;
			//add queue = not visited.
			visited[i] = true;
			cout << i << "\t";
			myQueue.push(i);
		}
	}
}
void DFS(int v)
{
	//excape condition => visited node
	if (visited[v])
		return;
	//visit node
	visited[v] = true;
	//print visit node
	cout << v << "\t";
	//go to connected node 
	for (int i : nodes[v])	//touring connection node
	{
		if (visited[i])
			continue;
		DFS(i);
	}
}
