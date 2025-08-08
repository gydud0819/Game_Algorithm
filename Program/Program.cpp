#include "Util.h"

#pragma region 계수 정렬
// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는지 개수를 세고 저장한 다음 정렬하는 알고리즘

void Counting(int list[], int size)
{
	int count[6] = {0};		// 이게 아닌가 
	
	// 전체적으로 한번 돌려야한다했나..? 그럼 list안에 있는걸 돌려야하나..? ??????????????????????????????
	for (int i = 0; i < size; i++)
	{
		count[list[i]]++;		// ? 
	}

	// 이제 정렬해야할거같은데 
	for (int i = 0; i < 6; i++)		// 이게 아닌가 
	{
		// 뭘 더 써야하는거지
		// for? while????????????????
		while (count[i] > 0)
		{
			// 출력은 어디다 하지 여긴가
			cout << i << " ";
			count[i]--;
			
		}
			
	}
}
#pragma endregion




int main()
{
	int list[] = { 1,3,2,2,4,5,1,2 };
	// sort써도되나? 그럼 벡터써야할거같은데 ㅇㅅㅇ
	// 1 1 2 2 2 3 4 5
	// 카운트 변수? 이게 배열이어야하는건가 
	int size = sizeof(list) / sizeof(list[0]);	
	Counting(list, size);

	return 0;
}