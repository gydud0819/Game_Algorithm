#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region Merge Sort (병합 정렬)
// 하나의 리스트를 2개의 균일한 크기로 분할하고
// 분할된 부분 리스트를 정렬한 다음, 2개의 정렬된 부분 리스트를
// 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.

// 1. 리스트의 길이가 0 or 1이 되면 이미 정렬된 것으로 간주한다.
// 2. 그렇지 않은 경우
// 2-1. 정렬되지 않은 리스트를 반으로 나눈 다음 비슷한 크기의 두 부분 리스트로 나눈다.
// 2-2. 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬한다.
// 2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합한다.

void Merge(int list[], int start, int mid, int end)
{
	// mid = (start + end) / 2		// 이게 피봇인가 
	int* container = new int[end - start + 1];		//
	int count = 0;
	int left = start;		// start? start + 1 ? 둘중 하나 같은디 
	int right = mid + 1;		// mid + 1? t.....q end? 머고 진짜 

	// while?
	// 재귀를 안쓴다구요...? ㅏ..
	// 두 부분의 배열 병합하기
	while (left <= mid && right <= end)
	{
		// 왼쪽 값이 오른쪽값보다 작거나같다? ㅓ <= 어케 해석하더라 '<=' 이게...어케 해석하더라..? 작거나같다..? ???
		if (list[left] <= list[right])
		{
			container[count++] = list[left++];
		}
		else
		{
			container[count++] = list[right++];
		}

	}

	// while을 한번더? 어케씀? 3번정도 쓴다고? 
	// 남은 왼쪽 배열의 요소들 복사하기
	while (left <= mid)
	{
		container[count++] = list[left++];
	}

	while (right <= end)
	{
		container[count++] = list[right++];
	}

	// 원본 배열에 정렬된 임시 배열의 값 복사하기
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = container[i];
	}

	// 해제하기
	delete[] container;
}

//  3 5 2 7 4 1 8 6 
void MergeSort(int list[], int start, int end)
{
	// 어케 쪼개요..? 이렇게 쪼개면 되구나 
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(list, start, mid);
		MergeSort(list, mid + 1, end);

		Merge(list, start, mid, end);		// 이렇게 호출하는건가? 
	}

}


#pragma endregion

int main()
{
	int list[] = { 3,5,2,7,4,1,8,6 };
	int size = sizeof(list) / sizeof(list[0]);
	MergeSort(list, 0, size - 1);

	for (auto& elem : list)
	{
		cout << elem << " ";
	}
	return 0;
}