#include<iostream>

void solution(int x, int y);

static int count = 0;
int n = 0;

void main()
{
	//입력되는 숫자.
	
	int x, y = 0;
	std::cin >> n;
	//만약 입력되는 숫자가 0보다 작을 경우.
	if (n < 10)
	{
		//앞자리에 0으로 채우기.
		x = 0;
		y = n;
	}
	else
	{
		//십의 자리 , 일의 자리 나누기와 나머지 연산으로 입력.
		x = n / 10;
		y = n % 10;
	}

	solution(x, y);

	std::cout << count;
}

void solution(int x, int y)
{
	count++;
	int newX = y;
	int newY = (x + y) % 10;
	if (((newX * 10) + (newY)) == n)
	{
		return;
	}
	else
	{
		solution(newX, newY);
	}
}