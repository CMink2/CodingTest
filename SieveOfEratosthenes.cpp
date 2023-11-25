#include<iostream>
#include<vector>
using namespace std;
//sieve array.
vector<bool> A;
void SieveOfEratosthenes(int start);
int main()
{
	int M, N;
	cin >> M >> N;
	//init vector.
	A.resize(N+1, true);
	//0, 1 are not prime number.
	A[0] = false;
	A[1] = false;
	//Sieve of Eratostenes 
	SieveOfEratosthenes(M);

	return 0;
}

void SieveOfEratosthenes(int start)
{
	//start index = 2 because 1 is not prime number.
	for (size_t i = 2; i < A.size(); i++)
	{
		//Except in case = divide itself
		for (size_t j = 2; i*j < A.size(); j++)
		{
			A[i*j] = false;
		}
	}

	//less than start => except
	for (size_t i = start; i < A.size(); i++)
	{
		if (A[i])
			cout << i << "\n";
	}
}