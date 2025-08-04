#include <iostream>
using namespace std;

#pragma region 완전 탐색 알고리즘 (브루트 포스(?))
/*
* 가능한 모든 경우의 수를 탐색하면서 결과를 찾아내는 알고리즘
*/
#pragma endregion

// 비밀번호 찍어맞추기 문제풀기(?)
// 조건이 있나..? 
// 세자리 비번? 
// 뺸치나 니빠로 그냥 끊으면 안돼요? 

int main()
{
	int passWord[3] = { 6,1,7 };		// 배열로 해서 
	// 단순하게 생각해보자 000-999까지 돌리면 된다매

	// 그게 표현이 안되네용;;;;;;;;;;;;;;;;;;;
	for (int i = 0; i < 10; i++)		// i< 10 말고 i<passWord[0] 아님 passWord[i] 이거넣어서 풀수잇을거같은데 int passWord[3]; 이래야하나 
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (passWord[0] == i && passWord[1] == j && passWord[2] == k)
				{
					cout << "passWord : " << i << " " << j << " " << k;

					return 0;
				}
			}
		}
	}


	return 0;
}