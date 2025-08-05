#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 삽입 정렬
// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여, 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘

// 8 5 6 2 4
// key가 있어야함 int key;
// 비교할 변수도 있어야 하는건가? 
void InsertSort(int arr[], int size)		// 뭔소리야 이게 
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];	// 값 저장

		int j = i - 1;  // 비교할 인덱스 변수를 만들어야하나? 

		//// while로 써도되나용 
		//
		//while (j >= 0 && arr[j] > key)		// j가 0보다 크거나 같거나 배열의 인덱스가(?) 값이(?) key보다 크면
		//{
		//	arr[j + 1] = arr[j];			// 
		//	j--;							// j 감소시키기
		//}
		//
		//arr[j + 1] = key;

		// 이중은 에바인거같은데						진짜 진짜 진짜 모르겠어요ㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜ
		for (j; j >= 0 && arr[j] > key; j--)		// 와 무슨말이야 이게 역순으로 돌아야한다고? -> j >= 0 && arr[j] > key 이 조건이 들어가야햇군
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
#pragma endregion


int main()
{
	cout << "삽입 정렬" << endl;
	int arr[] = { 8,5,6,2,4,1,0,9,7,3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	InsertSort(arr, size);
	return 0;
}