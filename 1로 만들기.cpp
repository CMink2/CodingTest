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
		//�ϴ� -1�� ������ �����ϴ�.
		dp[i] = dp[i - 1] + 1;
		//2�� ������ ���.
		if (i % 2 == 0)
		{
			dp[i] = dp[i / 2] + 1 < dp[i] ? dp[i / 2] + 1 : dp[i];
		}
		//3���� ������ ���.
		if (i % 3 == 0)
		{
			dp[i] = dp[i / 3] + 1 < dp[i] ? dp[i / 3] + 1 : dp[i];
		}
		//�ش� ��쿡�� ������ �ּҰ� �Ǵ� ���� ã�� �����Ѵ�.
		
		i++;
	}
	
	
	return dp[n];
}
