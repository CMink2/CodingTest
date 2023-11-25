#include<iostream>
#include<vector>
#define INF 9999
using namespace std;
static int N, E;
static vector<vector<int>> D;
void initVector();
void FloydWarshall();
int main()
{
	initVector();
	FloydWarshall();
	return 0;
}

void initVector()
{
	cin >> N >> E;
	D.resize(N+1);
	for (int i = 1; i < N+1; i++)
	{
		D[i].resize(N+1, INF);
		D[i][i] = 0;
	}
	for (int i = 1; i < E + 1; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		//same Route check condition.
		D[s][e] = min(D[s][e],w);
	}

}
void FloydWarshall()
{
	//transit node
	for (size_t k = 1; k < N+1; k++)
	{
		//start node.
		for (int i = 1; i < N + 1; i++)
		{
			//end node.
			for (int j = 1; j < N + 1; j++)
			{
				//direct Route vs transit Route => change shortest Route 
				D[i][j] = min(D[i][j] ,D[i][k] + D[k][j]);
			}
		}
	}
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= N; j++)
		{
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	
}
