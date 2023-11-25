#include<iostream>
#include<vector>
using namespace std;
static vector<int> A;
void Union(int a, int b);
int Find(int n);

int main()
{
	int N, M;
	cin >> N >> M;
	//init vector
	A.resize(N + 1);
	for (size_t i = 0; i < N+1; i++)
	{
		//set root node.
		A[i] = i;
	}
	for (size_t i = 0; i < M; i++)
	{
		int q,a, b;
		cin >> q >> a >> b;
		//union
		if (q == 0)
			Union(a, b);
		else
		{
			if (Find(a) == Find(b))
				cout << "YES";
			else
				cout << "NO";
		}
	}
	return 0;
}
void Union(int a, int b)
{
	//find rootNode.
	int rootA = Find(a);
	int rootB = Find(b);

	//set rootnode.
	if (rootA < rootB)
	{
		A[b] = rootA;
	}
	else
		A[a] = rootB;
}
int Find(int n)
{
	//index and value are not same => recursive
	if (A[n] != n)
	{
		return A[n] = Find(A[n]);
	}
	else
		return n;	//find root node.
	
}