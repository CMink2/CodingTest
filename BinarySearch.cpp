#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//binary search.
void BinarySearch(int s, int e, int key);
static vector<int> A;
static bool isfind = false;
int main()
{
	//array size
	int N;
	cin >> N;
	//init vector
	A.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	//sorting
	sort(A.begin(), A.end());

	//test case size
	int M;
	cin >> M;
	//test.
	for (size_t i = 0; i < M; i++)
	{
		int checkNum;
		cin >> checkNum;
		//binary search
		BinarySearch(0, N - 1, checkNum);
		//check condition.
		if (isfind)
			cout << "1" << "\n";
		else
			cout << "0" << "\n";

		//init find condition
		isfind = false;
	}
	return 0;
}
void BinarySearch(int s, int e, int key)
{
	//start can't over than end point
	if (s > e)
		return;
	//caculate mid
	int mid = (s + e) / 2;
	//find case
	if (key == A[mid])
	{
		isfind = true;
		return;
	}
	//end point relotate
	else if (key < A[mid])
		BinarySearch(s, mid - 1, key);
	else
		BinarySearch(mid + 1, e, key);

}