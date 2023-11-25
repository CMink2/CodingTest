#include<iostream>
#include<vector>
using namespace std;

int N, K;
static vector<int> A;
int cnt(int v);
int main()
{
	
	cin >> N >> K;
	//init vector.
	for (size_t i = 1; i <= N; i++)
	{
		//init vector's value
		for (size_t j = 1; j <= N; j++)
		{
			A.push_back(i * j);
		}
	}
	

	//start point, end point.
	int startPoint = 1;
	int endPoint = N*N;
	//result value
	int result = 0;

	//binary search
	while (startPoint <= endPoint)
	{
		//caculate mid
		int mid = (startPoint + endPoint) / 2;
		//numbers(less than mid) < K
		if (cnt(mid) < K)
			startPoint = mid + 1;
		//numbers(more than mid) > K
		else
		{
			//set result find value.
			result = mid;
			endPoint = mid - 1;
		}
	}

	cout << result << "\t";
	return 0;
}

//caculate less than v.
int cnt(int v)
{
	int sum = 0;
	for (size_t i = 1; i <= N; i++)
	{
		/*
			1	2	3		N = 3, v / 1 = 5
			2	4	6		N = 3, v / 2 = 2
			3	6	9		N = 2, v / 3 = 0 

			= 7
		*/
		sum += N < v / i ? N : v / i;
	}
	return sum;
}

