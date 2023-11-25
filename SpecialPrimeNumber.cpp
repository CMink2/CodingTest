#include<iostream>
#include<vector>
using namespace std;
//DFS function
void DFS(int v, int digit, int n);
//checkPrimeNumber
bool isPrimeNumber(int n);
static vector<vector<int>> A;
static vector<bool> visited;
int main()
{
	//digit count
	int N;
	cin >> N;
	//digits of 1's value = 2, 3, 5, 7
	DFS(2, 1, N);
	DFS(3, 1, N);
	DFS(5, 1, N);
	DFS(7, 1, N);
	return 0;
}
void DFS(int v, int digit, int n)
{
	//digit same N =>find special prime number
	if (digit == n)
	{
		//find prime number
		if (isPrimeNumber(v))
			cout << v << "\n";
		//excape this function
		return;
	}
	//add digit
	for (int i = 1; i < 10; i++)	//x0 can't be prime number.
	{
		//even number can't be prime number. x5 can't be prime number.
		if (i % 2 == 0 || i == 5)
			continue;	
		//check prime number
		if (isPrimeNumber(v * 10 + i))
			DFS(v * 10 + i, digit+1, n);
	}
}
bool isPrimeNumber(int n) 
{
	//find prime number
	for (size_t i = 2; i < n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}