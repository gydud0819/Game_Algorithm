#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define SIZE 8

#pragma region 위상 정렬
// 병합 그래프에 존재하는 각 정점들의 선행 순서를 지키고, 모든 정점을 차례대로 진행하는 알고리즘이다.

// 사이클이 발생하는 경우 위상 정렬을 수행할 수 없다. (사이클이 뭐야 계속 돈다는건가)
// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프
// 시간 복잡도 : O(V + E) Vertex + Edge

// 예시면... 모두의 마블 건물지을때..? 

// 1. 진입 차수가 0인 정점을 Queue에 삽입한다.

// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거한다.

// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입한다.

// 4. Queue가 비어있을 때까지 2-3번 작업을 반복한다.

class Graph
{
private:
	queue<int> q;
	vector<int> adj[SIZE];
	//degree?
	int degree[SIZE];	// ? 이게 아닌가 


public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			degree[i] = 0;
		}
	}
public:
	void insert(int vertex, int edge)
	{
		adj[vertex].push_back(edge);
		degree[edge]++;
		// q.front() 이걸 왜 지금 썻을까.. 다해놓고 이게 머고 하고잇네 
	}

	void search(int vertex)		// 인자는 없나요.. insert에 다 만드는건가? 
	{
		// 진입차수를 이렇게 설정해줘야 하는거구나 
		for (int i = 1; i < SIZE; i++)
		{
			if (degree[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout << temp << " ";

			for (int i = 0; i < adj[temp].size(); i++)
			{
				int next = adj[temp][i];
				degree[next]--;
				if (degree[next] == 0)
				{
					q.push(next);

				}
			}
		}

	}
};

#pragma endregion

#pragma region Backtracking (퇴각검색)
// 모든 가능한 경우의 수를 탐색해서 정답을 찾는 알고리즘이다.
// 완전 탐색과 같이 모든 경우를 탐색하는 것과 비슷하지만
// 답이 될 만한지 판단하고 그렇지 않으면 그 부분까지 탐색을 하지않고 가지치기를 한다.

// 가지치기 : 해를 찾아가는 도중, 지금의 경로가 해가 될 것 같지 않으면 그 경로를 더이상 가지않고 되돌아가는 것. (불필요한 탐색을 막는다)

// 재귀 형식으로 많이 작성한다. 

// 체스 문제 : 백준 9663번 N-Queen 문제
// 팁 : 퀸은 앞, 뒤, 대각선으로 움직일 수 있다. 
class N_Queen
{
private:
	int count;					// 퀸의 개수
	int queen[SIZE];			// 퀸의 위치를 저장하는 배열

public:
	N_Queen() : count(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			queen[i] = 0;
		}
	}
public:
	// 퀸을 놓을 수 있는지 확인하는 함수
	bool QueenGo(int down, int up)
	{
		for (int i = 0; i < down; i++)
		{
			if (queen[i] == up || abs(queen[i] - up) == abs(i - down))
			{
				return false; // 퀸을 놓을 수 없다면 false 반환
			}
		}
		return true; // 퀸을 놓을 수 있다면 true 반환

	}

	void NQueen(int down)
	{
		if (down == SIZE) // 모든 퀸을 놓았다면
		{
			count++; // 퀸의 개수 증가
			return; // 종료
		}

		// DFS 기반
		for (int i = 0; i < SIZE; i++)
		{
			if (QueenGo(down, i))
			{
				queen[down] = i; // 퀸을 놓는다
				NQueen(down + 1); // 다음 퀸을 놓기 위해 재귀 호출
			}
		}
	}

	int GetCount() const
	{
		return count; // 퀸의 개수를 반환
	}

};

#pragma endregion


int main()
{
	// 1 2 5 3 4 6 7
	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 5);

	graph.insert(2, 3);
	graph.insert(3, 4);

	graph.insert(4, 6);
	graph.insert(5, 6);

	graph.insert(6, 7);

	graph.search(1);

	cout << endl;

	N_Queen nQueen;

	nQueen.NQueen(0); // 0번째 퀸부터 시작
	cout << nQueen.GetCount() << " " << endl; // 퀸의 개수를 출력

	return 0;
}
