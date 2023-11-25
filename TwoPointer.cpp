#include<iostream>
using namespace std;

int main()
{
	
	int N = 0;		//Input numbers
	int sum = 1;	//start Sum

	//two pointer use to finding Part Sum
	int startIndex = 1, endIndex = 1;

	//result 
	int count = 1;

	cin >> N;

	while (endIndex != N)
	{
		//find sum
		if (sum == N)
		{
			//adding correct case.
			count++;
			//move to endIndex forward
			endIndex++;
			//change current sum.
			sum = sum + endIndex;
		}
		//less than sum
		else if (sum > N)
		{
			//move to startIndex forward
			sum -= startIndex;
			//change current sum.
			startIndex++;
		}
		//more than sum
		else 
		{
			//move to endIndex forward
			endIndex++;
			//change current sum.
			sum += endIndex;
		}
	}
	cout << count << "\n";
	return 0;
}