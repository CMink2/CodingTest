#include<iostream>
//swap method
#define swap(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;
int gcd(int x, int y);
int main()
{
	//test case count.
	int t;
	cin >> t;

	//test case
	for (size_t i = 0; i < t; i++)
	{
		//test case nums
		int n1, n2;
		cin >> n1 >> n2;

		//n1 * n2 / GCD = LCM
		cout << n1 * n2 / gcd(n1, n2) << "\n";
	}
}
int gcd(int x, int y)
{
	//less than y = swap this value.
	if (x < y)
		swap(x, y);
	//find common division.
	if (y == 0)
		return x;
	//recursive 
	return gcd(y, x % y);
}