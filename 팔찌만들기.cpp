#include<iostream>
#include<limits.h>

using namespace std;

//���� ����⿡�� Ư¡�� �ִ�. �ٷ� ���� ū ���� ���� ���� ���� ���� 2�谡 
//��� ���� �� ��Ÿ���� �ּ� ���� ���̶�� ���̴�.

int solution();

int main()
{
	cout << solution() << endl;
	return 0;
}

int solution()
{
	//�� �� �ݺ��� ���ΰ�?
	int n = 0;
	cin >> n;

	//���� �Էµ� ��.
	int curNum = 0;

	//�ִ�, �ּڰ�. �ʱ�ȭ
	int min = INT_MAX;
	int max = 0;

	//�ݺ��ؼ� �Էµ� ���� �ִ�, �ּڰ� ã��.
	for (int i = 0; i < n; i++)
	{
		cin >> curNum;
		min = curNum < min ? curNum : min;
		max = curNum > max ? curNum : max;
	}

	//������ �� ��ȯ.
	return (max - min) * 2;
}