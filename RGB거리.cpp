#include<iostream>

int solution();
int n = 0;
//�迭.
int dp[1000][3] = { 0 };

int main()
{
	std::cout << solution();
	return 0;
}


//r, g, b�� �������� �� �ּ� ���� ��� ���ؾ� �Ѵ�.
/*
���� r�� ĥ�ϸ� ������ b,g�� ĥ������ b�� ĥ�ϸ� r,g�� ĥ������ g�� ĥ�ϸ� r,b�� ĥ������
���� ĥ���� �� �ִ� ��Ʈ���� �ּҰ� �Ǵ� ���� �����س�����.
*/
int solution()
{
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < 3; c++)
		{
			//�� �޾ƿ���.
			std::cin >> dp[i][c];
		}
	}
	for (int i = 1; i < n; i++)
	{
		//������ R���� ĥ�����ִٸ�. (G, B���� �ּ� ���ϱ�)
		dp[i][0] += dp[i-1][1] < dp[i-1][2] ? dp[i-1][1] : dp[i-1][2];
		//������ G�� ĥ���� �ִٸ� (R, B���� �ּ� ���ϱ�)
		dp[i][1] += dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2];
		//������ B�� ĥ���� �ִٸ�. (R, G���� �ּ� ���ϱ�)
		dp[i][2] += dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
	}
	
	//3���� ��� �� �ּҰ� ã��.
	if (dp[n - 1][0] < dp[n - 1][1])
	{
		if (dp[n - 1][0] < dp[n - 1][2])
		{
			return dp[n - 1][0];
		}
		else
			return dp[n - 1][2];
	}
	else
	{
		if (dp[n - 1][1] < dp[n - 1][2])
		{
			return dp[n - 1][1];
		}
		else
			return dp[n - 1][2];
	}
}