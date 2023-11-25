#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//binary search function
void BinarySearch(int s, int e, int key);
//lesson array
static vector<int> A;
static int N, M;
int main()
{
	//lesson's count, blueray count
	cin >> N >> M;
	A.resize(N);
	//startpoint, endpoint
	int startPoint = 0;
	int endPoint = 0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
		if (startPoint < A[i])
			startPoint = A[i];

		//caculate part sum. = endPoint
		endPoint += A[i];
	}
	BinarySearch(startPoint, endPoint, M);
}
void BinarySearch(int s, int e, int key)
{
	//start can't over than end point
	while (s <= e)
	{
		int mid = (s + e) / 2;	//mid point.
		//lesson's length sum, Blueray count
		int sum = 0, count = 0;
		for (size_t i = 0; i < N; i++)
		{
			//over than blueray length => can't save
			if (sum + A[i] > mid)
			{
				count++;	//new blueray
				sum = 0;	//init sum;
			}
			//can add this lesson
			sum += A[i];
		}
		//rest process
		if (sum != 0)
			count++;
		//over than Max Blueray count	=> increase Blueray Length
		if (count > M)
			s = mid + 1;
		//can save => reduce Blueray Length
		else
			e = mid - 1;
	}
	cout << s << "\t";
}