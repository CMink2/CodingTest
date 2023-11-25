#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//student list.
static vector<vector<int>> A;
static vector<int> inDegree;
int main()
{
	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	inDegree.resize(N + 1);
	for (size_t i = 0; i < M; i++)
	{
		int s1, s2;
		cin >> s1 >> s2;
		A[s1].push_back(s2);
		inDegree[s2]++;
	}

	queue<int> mque;
	for (size_t i = 1; i <= N; i++)
	{
		//push queue in degree = 0 
		if (inDegree[i] == 0)
			mque.push(i);
	}
	while (!mque.empty())
	{
		//move next node
		int nowNode = mque.front();
		mque.pop();
		cout << nowNode << "\t";
		//renewal the indegree list.
		for (int i : A[nowNode])
		{
			inDegree[i]--;
			//push this node.
			if(inDegree[i] == 0)
				mque.push(i);
		}
	}
}