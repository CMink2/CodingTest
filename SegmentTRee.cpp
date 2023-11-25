#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
static int N, M, K;
static vector<long long> tree;
//get vector size function
int GetSize();
void SetTree(int i);
void Change(int i, long value);
long long GetSum(int s, int e);
int main()
{
	cin >> N >> M >> K;
	int size = N;
	int height = 0;
	while (size != 0)
	{
		size /= 2;
		height++;
	}
	int treesize = pow(2, height+1);
	int leafPoint = treesize / 2 - 1;
	tree.resize(treesize+1);
	
	//set leaf node.
	for (int i = leafPoint + 1; i <= leafPoint + N; i++)
	{
		cin >> tree[i];
	}
	//set segment tree.
	SetTree(treesize - 1);
	for (size_t i = 0; i < M+K; i++)
	{
		int con;
		long long s, e;
		cin >> con >> s >> e;
		if (con == 1)
		{//change value.
			Change(s, e);
		}
		else
		{//get sum.
			cout << GetSum(s, e) << "\n";
		}
	}
}

int GetSize()
{
	int length = N;
	int height = 0;
	while (length != 0)
	{
		length /= 2;
		height++;
	}
	return height;
}

void SetTree(int i)
{
	while (i != 1)
	{
		tree[i / 2] += tree[i];
		i--;
	}
}

void Change(int i, long value)
{
	//reneawl tree.
	long long diff = value - tree[i];
	while (i > 0)
	{
		tree[i] = tree[i] + diff;
		i /= 2;
	}
}
long long GetSum(int s, int e)
{
	long long partSum = 0;
	//start point < end point.
	while (s <= e)
	{
		//set startpos. 
		if (s % 2 == 1)
		{
			partSum += tree[s];
			//move back node.
			s++;
		}
		//move parent.
		else { s /= 2; }
		//set endpos.
		if (e % 2 == 0)
		{
			partSum += tree[e];
			//move front node.
			e--;
		}
		//move parent.
		else { e /= 2; }
		
	}
	return partSum;
}