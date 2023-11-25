#include<vector>
#include<iostream>
#include <queue>
#include<algorithm>
using namespace std;

static int N, M, K, X;
static vector<vector<int>> A;
static vector<int> visited;
static vector<int> answer;
void BFS(int x);
int main()
{
	//input 
	cin >> N >> M >> K >> X;
	//init vector.
	A.resize(N + 1);
	visited.resize(N + 1);
	
	//input startpoint, endpoint.
	for (size_t i = 0; i < M; i++)
	{
		//start point, endpoint.
		int s, e;
		cin >> s >> e;
		//add adjacency matrix
		A[s].push_back(e);
	}
	//init visited vector.
	for (size_t i = 0; i < N+1; i++)
	{
		visited[i] = -1;
	}
	//check weight 
	BFS(X);
	//add result
	for (int i = 0; i < N + 1; i++)
	{
		if (visited[i] == K)
		{
			answer.push_back(i);	//add result array.
		}
	}
	if (answer.empty())
		cout << -1;
	else
	{
		sort(answer.begin(), answer.end());
		for (size_t i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;
		}
	}
}

void BFS(int x)
{
	queue<int> myqueue;
	//start point's weight = 0
	visited[x]++;
	//add queue.
	myqueue.push(x);

	//bfs.
	while (!myqueue.empty())
	{
		int cNode = myqueue.front();
		myqueue.pop();

		for (int i : A[cNode])
		{
			//not visited
			if (visited[i] == -1)
			{
				//pastNode's weight+1 => becuase all weight = 1
				visited[i] = visited[cNode] + 1;
				myqueue.push(i);
			}
		}
	}
}