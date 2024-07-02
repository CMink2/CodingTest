#include<iostream>
#define BLACK 2
#define WHITE 1
using namespace std;

//체스판은 N * N 형태로 구성
// 퀸은 가로 세로 대각선 이동이 가능하다. 
// 즉 한 행당 퀸은 단 하나만 존재 시키기.
// 같은 열에 저장되면 안됨. -> 해당 열 제외하고 배치하기.
// 그럼 대각선은? x 값 끼리의 차. y 값 끼리의 차가 같으면 대각선임.
//백 트래킹으로 해결해보자.
// 모든 경우의 수를 다 도전 해보는 방법.
//재귀 형태로 작성해보자.

//체스판
int board[15];

int n, answer = 0;


//몇번째 행을 체우고 있는지 확인하기.
bool isSpawnable(int y);
//열 채우기.
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
	//지금까지 배치된 애들 중에 겹치는 애가 있는지 확인하기. 
	//ex 3열까지 배치됬으면 0~ 3까지 순회하며 겹치는 퀸 찾기.
	for (int i = 0; i < y; i++)
	{
		//행이 다른지 확인하기. 대각선에 있는지 확인하기. 있다면 false 없다면  true.
		//board[i]는 x좌표. i는 y 좌표이다.
		if (board[i] == board[y] || abs(board[y] - board[i]) == y - i)
			return false;
	}
	return true;
}

//x로 열값 하나씩 증가시키기.
void solution(int x) 
{
	//N개를 모두 배치했으면 경우의 수 증가시키기.
	if (x == n)
		++answer;
	else
	{
		//열 값 순회하며 배치하기.
		for (int i = 0; i < n; i++)
		{
			//x열 i행에 배치.
			board[x] = i;
			//설치한 개수만큼 스폰체크하기. 만약 스폰 가능하면 다음으로 넘기기.
			if (isSpawnable(x))
				solution(x+1);
		}
	}
}
