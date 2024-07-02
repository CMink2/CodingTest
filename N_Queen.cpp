#include<iostream>
#define BLACK 2
#define WHITE 1
using namespace std;

//ü������ N * N ���·� ����
// ���� ���� ���� �밢�� �̵��� �����ϴ�. 
// �� �� ��� ���� �� �ϳ��� ���� ��Ű��.
// ���� ���� ����Ǹ� �ȵ�. -> �ش� �� �����ϰ� ��ġ�ϱ�.
// �׷� �밢����? x �� ������ ��. y �� ������ ���� ������ �밢����.
//�� Ʈ��ŷ���� �ذ��غ���.
// ��� ����� ���� �� ���� �غ��� ���.
//��� ���·� �ۼ��غ���.

//ü����
int board[15];

int n, answer = 0;


//���° ���� ü��� �ִ��� Ȯ���ϱ�.
bool isSpawnable(int y);
//�� ä���.
void solution(int x);

int main()
{
	cin >> n;
	solution(0);
	cout << answer << endl;

	return 0;
}

bool isSpawnable(int y)
{
	//���ݱ��� ��ġ�� �ֵ� �߿� ��ġ�� �ְ� �ִ��� Ȯ���ϱ�. 
	//ex 3������ ��ġ������ 0~ 3���� ��ȸ�ϸ� ��ġ�� �� ã��.
	for (int i = 0; i < y; i++)
	{
		//���� �ٸ��� Ȯ���ϱ�. �밢���� �ִ��� Ȯ���ϱ�. �ִٸ� false ���ٸ�  true.
		//board[i]�� x��ǥ. i�� y ��ǥ�̴�.
		if (board[i] == board[y] || abs(board[y] - board[i]) == y - i)
			return false;
	}
	return true;
}

//x�� ���� �ϳ��� ������Ű��.
void solution(int x) 
{
	//N���� ��� ��ġ������ ����� �� ������Ű��.
	if (x == n)
		++answer;
	else
	{
		//�� �� ��ȸ�ϸ� ��ġ�ϱ�.
		for (int i = 0; i < n; i++)
		{
			//x�� i�࿡ ��ġ.
			board[x] = i;
			//��ġ�� ������ŭ ����üũ�ϱ�. ���� ���� �����ϸ� �������� �ѱ��.
			if (isSpawnable(x))
				solution(x+1);
		}
	}
}
