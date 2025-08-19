#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define SIZE 7
#pragma region 서로소 집합
// 서로 공통된 원소를 가지고 있지 않은 2개 이상의 집합을 의미한다.

// union (합집합) : 두 집합을 하나로 합치는 연산
// find (찾기) : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산

// 서로소 부분 집합들로 나누어진 원소들의 데이터를 처리하기 위한 자료구조 

// 1. 합집합 연산을 확인하여 서로 연결된 두 노드를 확인한다.
// 1-1. A와 B의 루트 노드를 A'와 B'를 각각 찾는다.
// 1-2. A'와 B'의 부모 노드를 설정한다.

// 2. 모든 합집합 연산을 처리할 때 까지 1번 과정을 반복한다.

// what is 경로 압축 기법

// class 쓸랫는데 그냥 함수가 나을듯 

// root node를 찾는 함수
int parentIndex[SIZE];

int Find(int x)
{
	// 배열의 인덱스와 값이 같다면 root node 발견했다고 출력? 하기

	// 부모 노드의 번호를 전달하면서 root node를 찾을 때 까지 재귀함수를 호출하여 반복하기 (for 쓰면 될거같은데)
	// 찾을때까지면 아닌게 있을수도 있다는건가

	// 이게 아닌거 같은데 
	if (parentIndex[x] != x)
	{
		parentIndex[x] = Find(parentIndex[x]);
	}
	return parentIndex[x];

}

// 합치는 함수
void Union(int x, int y)
{
	// 어케 합침? 
	int parentX = Find(x);
	int parentY = Find(y);

	if (parentX < parentY)
	{
		parentIndex[parentY] = parentX;
	}

	else if (parentX > parentY)
	{
		parentIndex[parentX] = parentY;
	}
}

bool Same(int x, int y)
{
	if (Find(x) == Find(y))		// ? 
	{
		return true;
	}
	else
	{
		return false;
	}
}

#pragma endregion

int main()
{
	// 0 1 2 3 4 5 6 
	for (int i = 0; i < SIZE; i++)
	{
		parentIndex[i] = i;
	}

	Union(0, 1);
	Union(0, 3);
	Union(1, 2);
	Union(4, 5);

	for (int i : parentIndex)
	{
		cout << i << " ";
	}

	cout << endl << (Same(0, 2) ? "true" : "false");

	return 0;
}