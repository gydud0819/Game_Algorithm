#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 선택 정렬
/*
* 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서 결과를 교체하는 방식으로 정렬하는 알고리즘
*/

// 6 4 8 3 1
void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];		// 가장 작은 최솟값 min 저장(?)

		// int index 변수 만들어서 수정하기 
		int index = i;
		// 다 꼬이는데용..?

		for (int j = i + 1; j < size; j++)	// i보다 +1 값이어야하니까 i가 0부터 시작해서 
		{
			if (min > arr[j])		// 최소값 비교해서 min이 j보다 크면
			{
				min = arr[j];
				index = j;				// j가 min(?) 해석이 이상한데 min에 j 대입하기(?) => 저장하기(?)
			}

		}
		//// swap함 (최소값을 찾고 그게 같지 않으면 swap하기) 
		//if (arr[i] != arr[min])		// 둘이 같지 않으면(?) 않으면???????????????????????????
		//{
		//	swap(arr[i], arr[min]);	// 숫자를 증가시키니까 swap이 덜되는데 큰일났네 -> for문 바깥으로 빼야 정렬되는군 
		//}
		swap(arr[i], arr[index]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}

// vector Version 하지말자 하지마 때려쳐 
//void SelectionSort(vector<int> nums)
//{
//	for (int i = 0; i < nums.size() - 1; i++)
//	{
//		int minIndex = i;
//		for (int j = i+1; j < nums.size(); j++)
//		{
//			if (nums[minIndex] > nums[j])
//			{
//				minIndex = j;
//			}
//
//			
//		}
//		if (nums[i] != nums[minIndex])
//		{
//			swap(nums[i], nums[minIndex]);
//		}
//	}
//}

#pragma endregion


int main()
{
	cout << "선택 정렬" << endl;
	int arr[] = { 3, 6, 1, 4, 9, 7, 2, 5, 0, 8 };		// 

	int size = sizeof(arr) / sizeof(arr[0]);	// 이거 괜찮네 
	SelectionSort(arr, size);

	cout << endl;

	cout << "vector 버전 선택 정렬" << endl;
	vector<int> vector = { 6,4,8,3,1 };
	//SelectionSort(vector);
	return 0;
}