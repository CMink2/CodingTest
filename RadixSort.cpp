#include<iostream>
using namespace std;

int main()
{
	//num's count
	int N;
	cin >> N;

	//inputnumber;
	int number;

	//radix array => count array's index = number(input datas)'s count
	int count[10001] = { 0 };

	for (size_t i = 1; i <= N; i++)
	{
		cin >> number;
		//sorting raidx array point
		count[number]++;
	}

	//print count's index one by one
	for (size_t i = 1; i <= 10000; i++)
	{
		//pass condition => count[i] = empty
		if (count[i] == 0)
			continue;
		//repeat same value print.
		for (size_t j = 0; j < count[i]; j++)
		{
			cout << i << "\n";
		}

	}
	return 0;
}