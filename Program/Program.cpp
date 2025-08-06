#include "Util.h"

#pragma region 에라토스테네스의 체 
/*
* 2 3 5 7 11 13 17 19 23
* 2~N(50) 브루트 포스로 해결하기 
*/

// O(n^1/2)
void sieve(int n)
{
	// 동적할당해서(?) new 쓰기 아니 근데 써도 그 다음 진행을 내가 할 수 잇..나? 
	// 데이터 값 넣기(?)
	// 소수가 아닌 값은 0으로 처리하기		2의배수 3의배수 얘네를 0으로? 	
	// 특정한 숫자의 제곱근이면 4 9 16?
	int i = 0;
	bool* data = new bool[n + 1];

	for (i = 1; i <= n; i++)
	{
		// 요기에 값넣는건가
		data[i] = true;
	}
	data[0] = data[1] = false;	// 0과 1은 소수가 아닌게 맞는데 

	// 이게 뭔 소리여 내가 했는데 내가 모르겠네 
	for (int j = i * i; j < n; j+=i)
	{
		if (data[j] % 2 == 0)
		{
			return;
		}
	}

	delete[] data;

}
#pragma endregion


int main()
{
	// 2 3 5 7 11 13 17 19 23
	// 소수판별기 만들기 1과 자기자신만 나와야한다매...
	// 무식? 
	// 그럼 또 for써야하나? 이중..?

	int n = 50;

	//for (int i = 2; i <= n; i++)
	//{
	//	// n-1? 이게 잇어야하나? 
	//	for (j = 2; j < i; j++)
	//	{
	//		// 오웅 모르겠당 
	//		if (i % j == 0) // 이게 아닌가? 
	//		{
	//			break;
	//		}
	//	}

	//	if (i == j)
	//	{
	//		cout << i << " ";
	//	}
	//}

	/*for (int i = 2; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
			
		}
		if (count == 2)
		{
			cout << i << " ";
		}
	}*/
	

	return 0;
}