#include<iostream>

int solution();
int n = 0;
//배열.
int dp[1000][3] = { 0 };

int main()
{
	std::cout << solution();
	return 0;
}


//r, g, b로 시작했을 때 최솟 값을 모두 구해야 한다.
/*
만약 r로 칠하면 다음은 b,g가 칠해지고 b로 칠하면 r,g가 칠해지고 g로 칠하면 r,b가 칠해진다
각각 칠해질 수 있는 루트에서 최소가 되는 값만 저장해나간다.
*/
int solution()
{
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < 3; c++)
		{
			//색 받아오기.
			std::cin >> dp[i][c];
		}
	}
	for (int i = 1; i < n; i++)
	{
		//이전에 R으로 칠해져있다면. (G, B에서 최소 더하기)
		dp[i][0] += dp[i-1][1] < dp[i-1][2] ? dp[i-1][1] : dp[i-1][2];
		//이전이 G로 칠해져 있다면 (R, B에서 최소 더하기)
		dp[i][1] += dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2];
		//이전이 B로 칠해져 있다면. (R, G에서 최소 더하기)
		dp[i][2] += dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
	}
	
	//3개의 경우 중 최소값 찾기.
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