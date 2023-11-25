#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> A;

int main()
{
	//meeting count
	int N;
	cin >> N;
	//meeting vector
	A.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		//start time, end time.
		int s, e;
		cin >> s >> e;
		//end time base vector.
		A[i] = make_pair(e, s);
	}

	//sorting vector. => end time value.
	sort(A.begin(), A.end());

	int count = 0;
	int end = -1;

	for (size_t i = 0; i < N; i++)
	{
		//can meeting
		if (A[i].second > end)
		{
			end = A[i].first;//end time = current meeting's end time.
			count++;
		}
	}

	cout << count;
	return 0;
}

