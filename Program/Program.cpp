#include "Util.h"

#pragma region Merge Sort (병합 정렬)
// 하나의 리스트를 2개의 균일한 크기로 분할하고
// 분할된 부분 리스트를 정렬한 다음, 2개의 정렬된 부분 리스트를
// 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.

// 1. 리스트의 길이가 0 or 1이 되면 이미 정렬된 것으로 간주한다.
// 2. 그렇지 않은 경우
// 2-1. 정렬되지 않은 리스트를 반으로 나눈 다음 비슷한 크기의 두 부분 리스트로 나눈다.
// 2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬한다.
// 2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합한다.

//  3 5 2 7 4 1 8 6 
void MergeSort(int list[], int start, int end)
{
	// 어케 쪼개요..? 이렇게 쪼개면 되구나 
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(list, start, mid);
		MergeSort(list, mid + 1, end);
	}

}

void Merge(int list[], int mid, int end)
{
	// 
	int count = 0;
}
#pragma endregion

int main()
{
	int list[] = { 3,5,2,7,4,1,8,6 };
	int size = sizeof(list) / sizeof(list[0]);
	MergeSort(list, 0, size - 1);
	return 0;
}