#include<iostream>
using namespace std;

int main()
{
	//Values 
	int N = 0;	//Input numbers count
	string numbers;	//Input numbers to String
	int sum = 0;	// output result

	//input data
	cin >> N;
	cin >> numbers;

	//caculating result
	for (size_t i = 0; i < N; i++)
	{
		//loop until i < N
		sum += numbers[i] - '0';
	}

	//print result
	cout << sum << endl;
	return 0;
}