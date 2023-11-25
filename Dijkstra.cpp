#include<iostream>
#include<vector>
#include<queue>
#define INF 99999999	//INF value.
using namespace std;
//start point : [endpoint, weight]
static int weight[999][999];
static vector<int> Distance;
static vector<bool> visited;
static int V, E, S;
int GetSmaallNode();
void Dijkstra(int start);
int main()
{
	cin >> V >> E;
	cin >> S;
	
	Distance.resize(V + 1);
	visited.resize(V + 1);
	//weight init
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		for (size_t j = 1; j <= V; j++)
		{
			weight[i][j] = INF;
		}
	}
	for (int i = 1; i <= E; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		weight[s][e] = w;
	}
	//Dijkstara 
	Dijkstra(S);
}
//find next node. (smallest node.)
int GetSmaallNode()
{
	int min = INF;
	int minpoint = 1;
	for (size_t i = 1; i <= V; i++)
	{
		if (Distance[i] < min && !visited[i])
		{
			min = Distance[i];
			minpoint = i;
		}
	}
	return minpoint;
}
void Dijkstra(int start)
{
	//start point's weight = 0;
	weight[S][S] = 0;
	for (size_t i = 1; i <= V; i++)
	{
		//init distance array;
		Distance[i] = weight[start][i];
	}
	//visit startpoint.
	visited[start] = true;
	for (size_t i = 1; i <= V; i++)
	{
		int minNode = GetSmaallNode();
		//not visited and small weight node.
		visited[minNode] == true;
		//renewal weight
		for (size_t j = 1; j <= V; j++)
		{
			if (!visited[j])
			{
				if (Distance[minNode]+ weight[minNode][j] < Distance[j])
				{
					Distance[j] = Distance[minNode] + weight[minNode][j];
				}
			}
			
		}
	}
	for (size_t i = 1; i <= V; i++)
	{
		cout << Distance[i] << "\t";
	}
}