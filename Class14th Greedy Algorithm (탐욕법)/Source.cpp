#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#pragma region Greedy Algorithm (탐욕법) 7대 죄악 아니냐 이거 
// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중 하나를 검색해야 할 때마다
// 그 순간에 최적이라고 생각되는 것을 선택해 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘.

// 1. 탐욕 선택 속성
// 각 단계에서 '최적의 선택'을 했을 때 전체 문제에 대한 최적의 해를 구할 수 있는 경우의 

// 2. 최적 부분 구조
// 전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성'될 수 있는 경우

// 탐욕 알고리즘으로 문제를 해결하는 방법

// 1. 선택 절차 (Selection Procedure)
// 현재 상태에서의 최적의 해답을 선택한다.

// 2. 적절성 검사 (Feasibility Check)
// 선택된 해가 문제의 조건을 만족하는지 검사한다.

// 3. 해답 검사 (Solution Check)
// 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면 선택 절차로 돌아가 위의 과정을 반복한다. 
#pragma endregion

void CoinGiveBack(int amount)
{
	// 노가다해야하나요? 

	//int won = amount;
	//
	//int a = won / 1000;
	//cout << "1000원 : " << a << endl;
	//won -= a * 1000;

	//int b = won / 500;
	//cout << "500원 : " << b << endl;
	//won -= b * 500;

	//int c = won / 100;
	//cout << "100원 : " << c << endl;
	//won -= c * 100;

	//int d = won / 50;
	//cout << "50원 : " << d << endl;
	//won -= d * 50;

	//int e = won / 10;
	//cout << "10원 : " << e << endl;
	//won -= e * 10;

	//// 총 개수
	//int count = a + b + c + d + e;
	//cout << "총 개수 : " << count << endl;

	int n = amount;
	int count = 0;

	while (n >= 10)
	{
		if (n >= 1000)
		{
			n -= 1000;
			count++;
		}
		else if (n >= 500)
		{
			n -= 500;
			count++;
		}
		else if (n >= 100)
		{
			n -= 100;
			count++;
		}
		else if (n >= 50)
		{
			n -= 50;
			count++;
		}
		else if (n >= 10)
		{
			n -= 10;
			count++;
		}
	}

	cout << "count : " << count << endl;
}

int main()
{
	// 1370원? 1000+100*3+50+10*2 = 7

	// vector써도되나..? 

	// 1. 선택 절차
	// 거스름돈의 동전 개수를 줄이기 위해 현재 가장 가치가 높은 동전 우선 선택하기

	// 2. 적절성 검사
	// 1번 과정을 통해 선택된 동전들이 합이 거슬러 줄 금액을 초과하는지 검사하기

	// 2-1. 초과하면 가장 마지막에 선택한 동전을 삭제하고 1번으로 되돌아간 다음, 한 단계 작은 동전 선택하기

	// 3. 해답 검사
	// 선택된 동전들의 합이거슬러 줄 금액과 일치하는지 검사한다. 
	// 액수가 부족하면 1번으로 돌아가 다시 반복한다. 

	CoinGiveBack(8720);
	return 0;
}