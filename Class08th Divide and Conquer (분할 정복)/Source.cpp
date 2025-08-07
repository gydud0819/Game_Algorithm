#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#pragma region 분할 정복
// 주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분 문제에 대한 답을 재귀 호출을 이용하여 계산한 다음 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘 어이구 길다

// 분할 (Divide) : 주어진 문제를 2개 혹은 그 이상의 형식으로 나눈다.
// 정복 (Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를 더 이상 나누어서 문제가 필요없을 때까지 계속 분할한다.
// 통합 (Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성한다. 

// 20 15 99 1	-> 20 15	|	99 1	->
int max(int list[], int left, int right)		// left right는 list 배열의 왼쪽과 오른쪽 크기
{
	// 조건이 저게 다라고? 
	// for문같은거 안써도 되나 if문만? 코드 몇줄안된다매
	// 재귀함수 써야하니까.. ㅇㅅㅇ
	// 탈출조건? 쪼갠다음 비교해서 큰걸 올려야하니까 크면 탈출인가 오쒸 어렵네 

	if (left == right)
	{
		return list[left];		//이거 맞음? 뭐야 이게 
	}

	// 변수 잇어야해용..? 
	int mid = (left + right) / 2;
	int leftMax = max(list, left, mid);
	int rightMax = max(list, mid + 1, right);

	if (leftMax < rightMax)
	{
		return rightMax;
	}
	else
	{
		return leftMax;
	}

}
#pragma endregion


int main()
{
	int list[] = { 20,15,99,1 };
	int size = sizeof(list) / sizeof(list[0]);


	cout << max(list, 0, size - 1);
	return 0;
}