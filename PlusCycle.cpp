#include<iostream>

void solution(int x, int y);

static int count = 0;
int n = 0;

void main()
{
	//�ԷµǴ� ����.
	
	int x, y = 0;
	std::cin >> n;
	//���� �ԷµǴ� ���ڰ� 0���� ���� ���.
	if (n < 10)
	{
		//���ڸ��� 0���� ä���.
		x = 0;
		y = n;
	}
	else
	{
		//���� �ڸ� , ���� �ڸ� ������� ������ �������� �Է�.
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