#include<iostream>
int solution();
int n;
int dp[1000001] = { 0, };
int main()
{
	std::cout << solution();
	return 0;
}

int solution()
{
	std::cin >> n;
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int i = 4;
	while (i <= n)
	{
		//일단 -1은 무조건 가능하다.
		dp[i] = dp[i - 1] + 1;
		//2로 나눠질 경우.
		if (i % 2 == 0)
		{
			dp[i] = dp[i / 2] + 1 < dp[i] ? dp[i / 2] + 1 : dp[i];
		}
		//3으로 나눠질 경우.
		if (i % 3 == 0)
		{
			dp[i] = dp[i / 3] + 1 < dp[i] ? dp[i / 3] + 1 : dp[i];
		}
		//해당 경우에서 연산이 최소가 되는 것을 찾아 저장한다.
		
		i++;
	}
	
	
	return dp[n];
}
