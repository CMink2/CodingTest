#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> parent;
int find(int x);
void Union(int x, int y);
bool same(int x, int y);
struct node
{
	int start;
	int end;
	
};
inline bool operator<(const node& lhs, const node& rhs)
{
	return lhs.start < rhs.start;
}
vector<pair<int, node>> edges;
int main()
{
	int v, e, result = 0;
	cin >> v >> e;
	//make a edge list.
	for (size_t i = 0; i < e; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		node n;
		n.start = from;
		n.end = to;
		edges.push_back(make_pair(weight, n));
	}
	sort(edges.begin(), edges.end());

	//resize parent vector. and init.
	parent.resize(v + 1);
	for (size_t i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (!same(edges[i].second.start, edges[i].second.end))
		{
			//add edge.
			Union(edges[i].second.start, edges[i].second.end);
			result += edges[i].first;
		}
	}
	cout << "result : " << result;
}
//check parent function
bool same(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	else return false;
}
int find(int x)
{
	//find parent.
	if (parent[x] == x)
		return x;
	else return parent[x] = find(parent[x]);
}
void Union(int x, int y)
{
	int X = find(x);
	int Y = find(y);
	//union.
	if (X < Y)
		parent[y] = X;
	else
		parent[x] = Y;

}