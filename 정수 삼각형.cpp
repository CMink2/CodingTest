#include<iostream>

//���� �迭.
int dp[500][500] = { 0, };
int array[500][500] = { 0, };
int solution();

int main()
{
	std::cout << solution();
	return 0;
}


/*
	�Ʒ����� ���� �ö󰡸� �ȴ�. ->  dp[x][y] = max(dp[x][y+1] +dp[x][y], dp[x+1][y+1] + dp[x][y]) 
					1
				2		3
			4		5		6
		7		8		9		10
	11		12		13		14		15

	�� �ԷµǸ�
	1
	2	3
	4	5	6
	7	8	9	10
	11	12	13	14	15 �� ����ǰ� �� ���� 0��.

	������
	11, 12, 13, 14, 15�� ���� �ִ� 7, 8, 9, 10�� ���� ���� �ٽ� �����Ѵ�.
	ex
	11 +7�� ���� 12+7�� �� �� �� ū ���� �����Ѵ�. �׷� 19�� �ö� ����ȴ�.
	
*/
int solution()
{
	//�ԷµǴ� ���� ����.
	int n = 0;
	std::cin >> n;
	//�迭�� �� �����ϱ�,
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cin >> dp[i][j];
			array[i][j] = dp[i][j];
		}
		
	}
	//y�� ��ȸ n-1���� 0���� �ö󰡾���,
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