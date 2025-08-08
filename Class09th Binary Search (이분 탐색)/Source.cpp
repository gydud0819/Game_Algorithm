#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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
			cout << "found key" << endl;
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

#pragma region Two Pointer Algorithm
// 배열에서 2개의 포인터를 움직이면서 원하는 값을 찾는 알고리즘
// 백준 3273 문제 두 수의 합
// 문제요약 : 정렬된 배열에서 양쪽 끝 숫자 더해가며 목표값을 찾는다
// 시간복잡도 : O(n)

void TwoPointer(int list[], int size, int target)
{
	sort(list, list + size);	// 배열의 원소들이 정렬이 되어있지 않기 때문에 sort를 사용해서 정렬시켜주기
	// 재귀로 할랫는데 안되나보다 그렇다면 for이나 while로 해봐야겠다
	int left = 0;
	int right = size - 1;
	int count = 0;		// 개수 세는거니까 일단 0으로

	while (left < right)
	{
		int sum = list[left] + list[right];

		// 돌렸는데 같다면
		if (sum == target)
		{
			count++;	// 정답수(?) 늘리기
			left++;		// 왼쪽 포인터값 늘리기
			right--;	// 오른쪽 포인터값은 감소시키기
		}
		// 각각의 값이 타겟보다 값이 작다면
		else if (sum < target)
		{
			left++;		// 왼쪽 포인터값 증가하기 
		}
		else
		{
			right--;	// 오른쪽 포인터값 감소하기
		}
	}

	cout << "총 개수 : " << count << endl;

}

// 벡터 버전
void TwoPointer(vector<int>& list, int target)		// n : 배열 크기인데 벡터를 썼기 때문에 필요없다 느껴서 제거함
{
	sort(list.begin(), list.end());
	int left = 0;
	int right = list.size() - 1;
	int count = 0;

	while (left < right)
	{
		int sum = list[left] + list[right];

		if (sum == target)
		{
			count++;
			left++;
			right--;
		}
		else if (sum < target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << "총 개수 : " << count << endl;
}
#pragma endregion

int main()
{
	int list[] = { 6,10,13,22,57 };
	int size = sizeof(list) / sizeof(list[0]);
	BinarySearch(list, 0, size, 10);
	Search(list, 10, size);


	int list1[] = { 5,12,7,10,9,1,2,3,11 };
	int size1 = sizeof(list1) / sizeof(list1[0]);
	TwoPointer(list1, size1, 13);

	cout << endl;

	vector<int> vector = { 5,12,7,10,9,1,2,3,11 };
	TwoPointer(vector, 13);
}