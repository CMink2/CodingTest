#include<iostream>
#include<vector>
using namespace std;
static int DP[10001][10001] = { 0, };
int main()
{
	int N, K;
	cin >> N >> K;
	for (size_t i = 1; i <= N; i++)
	{
		DP[i][1] = i;	//1 select = 1*i;
		DP[i][0] = 1;	//zero select. = 1
		DP[i][i] = 1;	//all select. = 1
	}
	//set matrix.
	for (size_t i = 2; i <= N; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			//mod this value.
			DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % 10007;
		}
	}
	cout << DP[N][K];
}