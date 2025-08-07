#include "Util.h"

#pragma region Two Pointer Algorithm

#pragma endregion

#pragma region 이분? 이진? 탐색
// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를 좁혀나가는 방식으로 동작하는 알고리즘 two pointer랑 다른건가 

// for 써도 되고 재귀로 해도되고? 둘다 별론데
// pivot을 왜 가우ㅏㄴ데부터하지 

// 6 10 13 22 57
// 함수를 void로 하면 안됐나.. 
// 내가 한 풀이 
void BinarySearch(int list[], int left, int right, int data)
{
	if (left == right)
	{
		cout << "Not data found" << endl;
		return;
	}

	int mid = (left + right) / 2;

	if (list[mid] == data)
	{
		cout << "Found data" << endl;
		return;
	}
	else if (list[mid] > data)
	{
		return BinarySearch(list, left, mid, data);
	}
	else
	{
		return BinarySearch(list, right, mid, data);
	}
}

// 강사님 풀이 
void Search(int list[], int key, int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;

		if (list[pivot] == key)
		{
			cout << " found key" << endl;
			return;
		}
		else if (list[pivot] > key)
		{
			right = pivot - 1;
		}
		else
		{
			left = pivot + 1;
		}
	}

	cout << "not key found" << endl;
}

#pragma endregion


int main()
{
	int list[] = { 6,10,13,22,57 };
	int size = sizeof(list) / sizeof(list[0]);
	BinarySearch(list, 0, size - 1, 11);
	return 0;
}