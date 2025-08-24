#include "Util.h"
#define SIZE 4
#define SIZE2 3

#pragma region 시뮬레이션 알고리즘
// 특정 알고리즘을 요구하기 보단 문제의 지시사항을 차례대로 따르고 그 결과를 정확하게 도출하는 알고리즘

// 명확한 규칙과 조건이 주어진다.

// 문제 접근 방법
// 1. 문제에서 요구하는 출력과 조건을 명확히 이해한다.
// 2. 초기 변수 값이나 시작점, 방향 등을 명확하게 정의한다.
// 3. 스켈레톤 코드 작성하기 (기본 뼈대 코드 설계하기)
// 4. 규칙에 따라 단계별로 세부 구현 하기

// ※ 주의 사항
// 1) 범위를 명확하게 하기
// 2) 예외 처리 신경 쓰기
// 3) 효율성 고려하기
// 4) 코너 케이스 테스트하기

/*
* 백준 14503 로봇 청소기
*
* 로봇 청소기 동작법
*
* 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
*
* 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
* 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
* 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
*
* 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
* 3-1. 반시계 방향으로 90도 회전한다.
* 3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
* 3-3. 1번으로 돌아간다.
*
* 0 = 청소되지 않은 빈칸
* 1 = 벽
*/

class robotCleaner
{public:
	int dir;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int room[SIZE][SIZE2] = {
		{1,1,0},
		{1,1,1},
		{1,0,1},
		{1,1,1}
	};
	bool clear[SIZE][SIZE2];
	
public:
	robotCleaner() : dir(0) // 초기화
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE2; j++)
				clear[i][j] = false; // 청소되지 않은 상태로 초기화
	}


public:
	void Clean(int x, int y)
	{
		int cleaned = 0;

		while (true) // 시뮬레이션 반복
		{
			// 1. 현재 칸이 아직 청소되지 않은 경우 청소
			if (!clear[x][y])
			{
				clear[x][y] = true;
				cleaned++;
			}

			// 2. 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
			bool found = false;

			for (int i = 0; i < 4; ++i)
			{
				// 반시계 방향으로 회전
				int ndir = (dir + 3) % 4;
				int nx = x + dx[ndir];
				int ny = y + dy[ndir];
				dir = ndir;

				// 청소되지 않은 빈 칸이 존재한다면 이동
				if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE2 &&
					room[nx][ny] == 0 && !clear[nx][ny])
				{
					x = nx;
					y = ny;
					found = true;
					break;
				}
			}

			// 3. 주변에 청소할 칸이 있다면 다시 1번으로
			if (found) continue;

			// 4. 청소할 칸이 없다면 후진 가능한지 확인
			int back = (dir + 2) % 4;
			int bx = x + dx[back];
			int by = y + dy[back];

			// 후진할 수 있으면 이동
			if (bx >= 0 && by >= 0 && bx < SIZE && by < SIZE2 &&
				room[bx][by] == 0)
			{
				x = bx;
				y = by;
			}
			else
			{
				// 뒤가 벽이면 작동 종료
				cout << "청소한 칸 수: " << cleaned << endl;
				break;
			}
		}
	}

};

#pragma endregion


int main()
{
	robotCleaner rc;
	rc.Clean(0, 2); // 시작 위치 (0,2) 방향은 북(0) 가정

	return 0;
}