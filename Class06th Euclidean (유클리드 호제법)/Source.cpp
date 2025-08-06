#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 유클리드 호제법
// 2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘
// 요약 : 최대 공약수 구하는 알고리즘

void Function(int x, int y)
{
	// 1. 2개의 자연수 x, y가 있을 때 x와 y를 나눈 나머지를 r이라 한다.
	// 2. r이 0이 아니라면 x와 y의 최대공약수가 y가 된다.
	// 3. r이 0이 아니라면, x와 y의 최대공약수는 y와 r의 최대공약수와 같기 때문에 x에는 y, y에는 r을 대입한 후 1번으로 돌아가기 (재귀함수 호출 방식)

	/*int r = x % y;*/
	// 이거 for문 돌려야하나 아님 진짜 grd함수를가져와야하나 
	if (y == 0)
	{
		cout << "최대공약수 : " << x << endl;
		return;
	}
	else
	{
		return Function(y, y % x);
	}


}
#pragma endregion


int main()
{
#pragma region 최대공약수
	//int a;
	//int b;
	//int n;			// 값이 잇어야하나? 
	//// if, while 써야할거같긴한데 ㅇㅅㅇ
	//
	//cin >> a;
	//cin >> b;
	//
	//for (int i = 1; i <= a && i <= b; i++)
	//{
	//	if (a % i == 0 && b % i == 0)
	//	{
	//		n = i;
	//	}
	//}
	//
	//cout << "최대 공약수 " << n << endl;

#pragma endregion


	Function(270, 192);
	return 0;
}