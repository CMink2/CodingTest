#include<iostream>

//동적 배열.
int dp[500][500] = { 0, };
int array[500][500] = { 0, };
int solution();

int main()
{
	std::cout << solution();
	return 0;
}


/*
	아래부터 위로 올라가면 된다. ->  dp[x][y] = max(dp[x][y+1] +dp[x][y], dp[x+1][y+1] + dp[x][y]) 
					1
				2		3
			4		5		6
		7		8		9		10
	11		12		13		14		15

	로 입력되면
	1
	2	3
	4	5	6
	7	8	9	10
	11	12	13	14	15 로 저장되고 빈 곳은 0임.

	연산은
	11, 12, 13, 14, 15가 위에 있는 7, 8, 9, 10을 더한 값을 다시 저장한다.
	ex
	11 +7의 값과 12+7의 값 중 더 큰 값을 저장한다. 그럼 19가 올라가 저장된다.
	
*/
int solution()
{
	//입력되는 줄의 개수.
	int n = 0;
	std::cin >> n;
	//배열에 값 저장하기,
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cin >> dp[i][j];
			array[i][j] = dp[i][j];
		}
		
	}
	//y축 순회 n-1부터 0까지 올라가야함,
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			//std::cout << dp[i][j] + dp[i - 1][j] << "\t" << dp[i][j + 1] + dp[i - 1][j] << "\t";
			//std::cout << dp[i][j] + array[i - 1][j] << "\t" << dp[i][j + 1] + array[i - 1][j] << "\t";
			dp[i - 1][j] = dp[i][j] + array[i - 1][j] > dp[i][j + 1] + array[i - 1][j] ? dp[i][j] + array[i - 1][j] : dp[i][j + 1] + array[i - 1][j];
			//std::cout << dp[i - 1][j] << "\t";
		}
		//std::cout << std::endl;
	}

	return dp[0][0];
}