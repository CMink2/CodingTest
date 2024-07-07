#include<iostream>
int n;
int dp[5001] = { 0, };
void solution();

int main()
{
	//설탕 개수 입력받기.
	std::cin >> n;
	solution();
	return 0;
}

//dp[i] = min(dp[i-3] + 1, dp[i-5] +1) 이전 항에 값이 저장되어 있다면 그 값 +1해서 뽑기.
//3작은 수에서 +1 나오는 경우 or 5 작은 경우에서 5 추가되서 나오는 경우.
void solution()
{	
	dp[3] = 1;
	dp[4] = 0;
	dp[5] = 1;
	if (n >= 6)
	{
		for (int i = 6; i <= n; i++)
		{
			//0이 아닌 경우만 갱신.
			if (dp[i - 3])
				dp[i] = dp[i - 3] + 1;
			//0이 아닌 경우만 갱신.
			if (dp[i - 5])
			{
				if (dp[i])
				{
					dp[i] = dp[i] < dp[i - 5] + 1 ? dp[i] : dp[i - 5] + 1;
				}
				else
				{
					dp[i] = dp[i - 5] + 1;
				}
			}
		}
	}
	if (dp[n])
	{
		std::cout << dp[n];
	}
	else
	{
		std::cout << -1;
	}

	
}