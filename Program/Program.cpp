#include "Util.h"

#pragma region 동적 계획법 (Dynamic Programming)
// 특정 범위까지의 값을 구하기 위해 그것과 다른 범위 까지의 값을 이용하여 효율적으로 값을 구하는 알고리즘이다.

// 겹치는 부분 문제 (Overlapping Subproblems)
// 동일한 작은 문제들이 반복하여 나타나는 경우를 의미한다.

// 최적 부분 구조 (Optimal Substructure)
// 부분 문제의 최적 결과 값을 사용하여 전체 문제의 최적의 결과를 낼 수 있는 경우를 의미한다. 

// 메모이재이션 (Memoization)
// 프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써 
// 동일한 계산을 반복 수행하는 작업을 제거하여 프로그램이 실행 속도를 향상시키는 방법.
#pragma endregion

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 980 1590 2570...
int fibonacci(int n)
{
	// 탙ㄹ출조건?
	// 이게 탈출조건..?
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);		// <- 점화식				 리턴하겟군
}

// 동적 계획법으로하는 피보나치 왜 이따구로 풀었지? 
int fibonacci(int n, int list[])
{
	list[0] = 0;
	list[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		list[i] = list[i - 1] + list[i - 2];
	}
	return list[n];

}

int fibonacci(int n, int list[])
{
	if (list[n] <= 1)
		return list[n] + 1;


}

int main()
{
	// 출력이..없어서 그런가? 
	//cout << fibonacci(45);

	// 내가 출력을 못하나? 
	int list[10001];
	cout << fibonacci(100, list);

	return 0;
}