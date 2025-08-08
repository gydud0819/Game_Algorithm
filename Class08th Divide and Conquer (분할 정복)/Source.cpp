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

#pragma region Two Pointer Algorithm
// 배열에서 2개의 포인터를 움직이면서 원하는 값을 찾는 알고리즘
// 백준 3273 문제 두 수의 합
// 문제요약 : 정렬된 배열에서 양쪽 끝 숫자 더해가며 목표값을 찾는다
// 시간복잡도 : O(n)

void TwoPointer(int list[], int n, int target)
{
	sort(list, list + n);	// 배열의 원소들이 정렬이 되어있지 않기 때문에 sort를 사용해서 정렬시켜주기
	// 재귀로 할랫는데 안되나보다 그렇다면 for이나 while로 해봐야겠다
	int left = 0;
	int right = n - 1;
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
	int list[] = { 20,15,99,1 };
	int size = sizeof(list) / sizeof(list[0]);


	cout << max(list, 0, size - 1);

	int list1[] = { 5,12,7,10,9,1,2,3,11 };
	int size1 = sizeof(list1) / sizeof(list1[0]);
	TwoPointer(list1, size1, 13);

	cout << endl;

	vector<int> vector = { 5,12,7,10,9,1,2,3,11 };
	TwoPointer(vector, 13);
	return 0;
}