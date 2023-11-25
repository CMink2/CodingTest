#include<iostream>
#include<vector>
#define INF 9999
//node struct
typedef struct node
{
	int start = 0;
	int end = 0;

}node;
using namespace std;
static int n, m, a, b, c;
static vector<pair<node, int>> edgeList;
static vector<int> Distance;
static vector<int> visited;
void BellmanFord();
int main()
{
	//node's count, edge's count.
	cin >> n >> m;
	//init vectors
	Distance.resize(n + 1);
	visited.resize(n + 1);
	for (size_t i = 1; i <= n; i++)
	{
		Distance[i] = INF;
	}
	for (size_t i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		node n;
		n.start = a;
		n.end = b;
		edgeList.push_back(make_pair(n, c));
	}
	BellmanFord();
}
void BellmanFord()
{
	//start point's distance = 0
	Distance[1] = 0;
	for (size_t i = 1; i <= n-1; i++)
	{
		for (size_t j = 0; j < edgeList.size(); j++)
		{
			//get startpoint.
			int from = edgeList[i].first.start;
			//get endpoint.
			int to = edgeList[i].first.end;
			//get weight
			int weight = edgeList[i].second;
			//not visited => skip this node.
			if (Distance[from] == INF) continue;
			//renewal distance.
			Distance[to] = Distance[to] > Distance[from] + weight ? Distance[from] + weight : Distance[to];
		}
	}
	for (size_t i = 0; i < edgeList.size(); i++)
	{
		//startpoint.
		int from = edgeList[i].first.start;
		//endpoint.
		int to = edgeList[i].first.end;
		//weight
		int weight = edgeList[i].second;
		//not visited => skip this node.
		if (Distance[from] == INF) continue;
		//minus cycle. check.
		if (Distance[to] > Distance[from] + weight)
		{
			cout << -1 << endl;
			return;
		}
	}
	
	//except start node.
	for (int i = 2; i <= n; i++)
	{
		//no route condition.
		if (Distance[i] == INF) cout << "-1" << "\t";
		//find route condition.
		else cout << Distance[i] << "\t";
	}
}