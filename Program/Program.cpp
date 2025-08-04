#include "Util.h"

#pragma region 정렬 알고리즘 (무식한 알고리즘(?))

#pragma region 버블 정렬
/*
* 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘
*/

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)		// 정렬이 다된건 더이상 안움직이니까 i만큼 빼야하는듯
		{
			if (arr[j] > arr[j + 1])			// 왜 여기에 ;를 붙였을까? 
			{
				swap(arr[j], arr[j + 1]);

			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
#pragma endregion

#pragma endregion

// 내일 할거 : 선택, 삽입 정렬, 수학문제? 
int main()
{
	cout << "버블 정렬" << endl;
	int arr[] = { 5,3,1,4,7,6,2 };		// 1, 3, 4, 5, 7
	
	int size = sizeof(arr) / sizeof(arr[0]);	// 이거 괜찮네 
	BubbleSort(arr, size);
	return 0;
}