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
	//입력 받기.
	std::cin >> n;
	int max = -1000;
	//숫자 입력 받기.
	for (int i = 1; i <= n; i++)
	{
		std::cin >> array[i];
	}
	dp[1] = array[1];
	max = dp[1];
	//연속합들 중 최댓값 구하기.
	for (int i = 2; i <= n; i++)
	{
		//이전까지의 최댓값에 지금 항을 더한 값 vs 지금 온 값.
		dp[i] = (dp[i - 1] + array[i]) > array[i] ? (dp[i - 1] + array[i]) : array[i];
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	return max;
}