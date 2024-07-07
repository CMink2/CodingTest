#include<iostream>
int n;
int dp[5001] = { 0, };
void solution();

int main()
{
	//���� ���� �Է¹ޱ�.
	std::cin >> n;
	solution();
	return 0;
}

//dp[i] = min(dp[i-3] + 1, dp[i-5] +1) ���� �׿� ���� ����Ǿ� �ִٸ� �� �� +1�ؼ� �̱�.
//3���� ������ +1 ������ ��� or 5 ���� ��쿡�� 5 �߰��Ǽ� ������ ���.
void solution()
{	
	dp[3] = 1;
	dp[4] = 0;
	dp[5] = 1;
	if (n >= 6)
	{
		for (int i = 6; i <= n; i++)
		{
			//0�� �ƴ� ��츸 ����.
			if (dp[i - 3])
				dp[i] = dp[i - 3] + 1;
			//0�� �ƴ� ��츸 ����.
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