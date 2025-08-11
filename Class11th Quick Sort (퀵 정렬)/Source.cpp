#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#pragma region 퀵 정렬(Quick Sort)
// 기준점을 획득한 다음 기준점을 기준으로 배열을 나누고 한 쪽에는 
// 기준점보다 작은 값들이 위치하게 한 다음 다른 한 쪽에는 기준점보다 큰 값들이 위치하도록 정렬한다. 
// 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여 모든 배열이 기본 배열이 될때까지 반복하면서 정렬하는 알고리즘.

// Two pointer, 분할 정복 알고리즘 사용
// 5 3 8 4 1 6 2 7
// 일단 보류하기 
void QuickSort(int list[], int start, int end)
{
	// 이 조건이었구나 
	if (start >= end)
	{
		return;
	}

	int pivot = start;
	int left = start + 1;
	int right = end;				// end거나 end - 1 둘중 하나같은데 end 인듯

	// left가 right보다 클 때 까지 반복
	while (left <= right)
	{

		// pivot 값보다 left값이 작으면 오른쪽으로 이동
		while (left <= end && list[pivot] >= list[left])	// 조건이 더 있어야할거같은데 혹쉬.. if 쓰는게 아닌가? 머고 
		{
			left++;		// 얘가 증가하는게 아닌거 같은데? 맞는건가

		}
		// pivot 값보다 right값이 크면 왼쪽으로 이동
		while (right > start && list[pivot] <= list[right])
		{
			right--;
		}

		// 이게 아닌가봄ㅜ
		if (left > right)	// 엇갈려도 swap해야하는거 아닌가? 뭘 swap 해야하더라 
		{
			swap(list[right], list[pivot]); // 이건가
		}
		else
		{
			// 엇갈린 상태가 아니라면 swap하기 (left와 right swap)
			swap(list[left], list[right]);
		}

	}

	// 모르겟네 ㅇㅅㅇ
	QuickSort(list, start, right - 1);		// 이게왼쪽?
	QuickSort(list, right + 1, end);						// 그럼 이게 오른쪽?

}


#pragma endregion


int main()
{
	int list[] = { 5,3,8,11,4,1,10,6,2,7,9 };
	int size = sizeof(list) / sizeof(list[0]);		// 머쓱하넹;;
	// size를ㄹ 넣을수가..없는데..?
	QuickSort(list, 0, size - 1);		// 이렇게 넣으면 되구나? 

	for (const auto& elem : list)
	{
		cout << elem << " ";
	}

	return 0;
}