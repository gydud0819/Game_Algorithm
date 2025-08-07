#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#pragma region 에라토스테네스의 체 
/*
* 2 3 5 7 11 13 17 19 23
* 2~N(50) 브루트 포스로 해결하기
*/

// O(n^1/2)
void sieve(int n)
{
	// 내가 한거 
	// 동적할당해서(?) new 쓰기 아니 근데 써도 그 다음 진행을 내가 할 수 잇..나? 
	// 데이터 값 넣기(?)
	// 소수가 아닌 값은 0으로 처리하기		2의배수 3의배수 얘네를 0으로? 	
	// 특정한 숫자의 제곱근이면 4 9 16?

	//bool* data = new bool[n + 1];

	//for (int i = 0; i <= n; i++)
	//{
	//	// 요기에 값넣는건가
	//	data[i] = true;		// 모든 숫자를 소수라고 하기 
	//}
	//data[0] = data[1] = false;	// 0과 1은 소수가 아닌게 맞는데  -> 아닌 거 맞음, 0은 0이고 1은 자연수가 맞긴하지만 이거 설명하려면 삼단논법같은걸로 논리정연하게 풀어야함;;

	//// 특정 숫자의 제곱근까지 돌리기(i * i <= n)
	//for (int i = 2; i * i <= n; i++)
	//{
	//	if (data[i])	// i 값이 소수로 남아있다면
	//	{
	//		// i의 제곱부터 i의 배수들은 전부 소수 아님 처리
	//		// i 이전에 이미 지워졌던 애들 겹치는 건 건너뛰기 (최적화를 위해서)
	//		for (int j = i * i; j <= n; j += i)		
	//		{
	//			data[j] = false;					// 돌렸을 때 소수가 아닌 거 처리하기 
	//		}
	//	}
	//}

	//// 소수 출력하기
	//for (int i = 2; i <= n; i++)
	//{
	//	if (data[i]) 
	//	{
	//		cout << i << " ";
	//	}
	//}
	//cout << endl;

	//delete[] data;	// 메모리 해제

	// 풀이 버전 
	int* container = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		container[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0)
		{
			continue;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			container[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (container[i] != 0)
		{
			cout << container[i] << " ";
		}
	}

	delete[] container;

}
#pragma endregion


int main()
{
	// 2 3 5 7 11 13 17 19 23
	// 소수판별기 만들기 1과 자기자신만 나와야한다매...
	// 무식? 
	// 그럼 또 for써야하나? 이중..?

	int n = 50;

	//for (int i = 2; i <= n; i++)
	//{
	//	// n-1? 이게 잇어야하나? 
	//	for (j = 2; j < i; j++)
	//	{
	//		// 오웅 모르겠당 
	//		if (i % j == 0) // 이게 아닌가? 
	//		{
	//			break;
	//		}
	//	}

	//	if (i == j)
	//	{
	//		cout << i << " ";
	//	}
	//}

	/*for (int i = 2; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}

		}
		if (count == 2)
		{
			cout << i << " ";
		}
	}*/

	sieve(50);
	return 0;
}