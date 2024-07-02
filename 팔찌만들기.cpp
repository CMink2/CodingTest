#include<iostream>
#include<limits.h>

using namespace std;

//팔찌 만들기에서 특징이 있다. 바로 가장 큰 수와 가장 작은 수의 차의 2배가 
//팔찌를 만들 때 나타나는 최소 차의 합이라는 것이다.

int solution();

int main()
{
	cout << solution() << endl;
	return 0;
}

int solution()
{
	//몇 번 반복할 것인가?
	int n = 0;
	cin >> n;

	//현재 입력된 값.
	int curNum = 0;

	//최댓값, 최솟값. 초기화
	int min = INT_MAX;
	int max = 0;

	//반복해서 입력된 값중 최댓값, 최솟값 찾기.
	for (int i = 0; i < n; i++)
	{
		cin >> curNum;
		min = curNum < min ? curNum : min;
		max = curNum > max ? curNum : max;
	}

	//차이의 합 반환.
	return (max - min) * 2;
}