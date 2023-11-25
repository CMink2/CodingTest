#include<vector>
#include<queue>
#include<iostream>
using namespace std;
static vector <vector<int>> A;
static vector<int>inDegree;
static vector<int>BuildTime;
int main()
{
	int N;
	cin >> N;
	A.resize(N + 1);
	inDegree.resize(N + 1);
	BuildTime.resize(N + 1);
	for (size_t i = 1; i < N+1; i++)
	{
		//input build time.
		cin >> BuildTime[i];
		while (true)
		{
			//add gruaph edge data.
			int con = 0;
			cin >> con;
			//break condition.
			if (con == -1)
				break;
			A[con].push_back(i);
			inDegree[i]++;
		}
	}
	//topology sorting
	queue<int> mq;
	for (size_t i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
			mq.push(i);
	}
	vector<int> result(N + 2, 0);
	while (!mq.empty())
	{
		int now = mq.front();
		mq.pop();
		for (int next : A[now])
		{
			//visit node => decrease indegree.
			inDegree[next]--;
			//change result bigger value 
			result[next] = result[next] < BuildTime[now] + result[now] ? result[now] + BuildTime[now] : result[next];
			//add queue.
			if (inDegree[next] == 0)
				mq.push(next);
		}
	}
	//result = self buildtime + past node's build time.
	for (size_t i = 1; i <= N; i++)
	{
		//add self buildtime + past node's build time.
		cout << result[i]+BuildTime[i] << "\t";
	}
	return 0;
}