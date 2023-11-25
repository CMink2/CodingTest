#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//coin's count, desire amount.
	int N, K;
	cin >> N >> K;
	vector<int> A(N);

	for (size_t i = 0; i < N; i++)
		cin >> A[i];
	//rest Amount
	int restAmount = K;
	//coin's count => result
	int coinCount = 0;
	for (size_t i = N-1; i >= 0; i--)
	{
		//can divide this coin
		if (A[i] <= restAmount)
		{
			coinCount += restAmount / A[i];
			restAmount %= A[i];
		}
		if (restAmount == 0)
			break;
	}
	cout << coinCount << "\t";

	return 0;
}