#include<iostream>
int solution();
int n;
int array[100001] = { 0, };
int dp[100001] = { 0, };

int main()
{
	std::cout<< solution();
	return 0;
}

int solution()
{
	//�Է� �ޱ�.
	std::cin >> n;
	int max = -1000;
	//���� �Է� �ޱ�.
	for (int i = 1; i <= n; i++)
	{
		std::cin >> array[i];
	}
	dp[1] = array[1];
	max = dp[1];
	//�����յ� �� �ִ� ���ϱ�.
	for (int i = 2; i <= n; i++)
	{
		//���������� �ִ񰪿� ���� ���� ���� �� vs ���� �� ��.
		dp[i] = (dp[i - 1] + array[i]) > array[i] ? (dp[i - 1] + array[i]) : array[i];
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	return max;
}