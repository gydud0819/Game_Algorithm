#include <iostream>

using namespace std;

#define INFINITY 10000000
#define SIZE 6

#pragma region 다익스트라 알고리즘
// 그래프 알고리즘 기반
// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘이다.

// 1. 거리 배열에서 weight[시작 노드]의 값들로 초기화 한다.

// 2. 시작점을 방문 처리한다.

// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리한다. (단, 이미 방문한 노드는 제외한다.)

// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신한다. 

// 5. 모든 노드를 방문할 때 까지 3-4번을 반복한다.

// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를 방문하고, 그 노드와 연결된 다른 노드까지의 거리를 계산한다.

class Dijkstra
{
private:
	// 이거뭐냐 미친듯
	int graph[SIZE][SIZE] = {		// 6x6 행렬

		{0, 2, 5, 1, INFINITY,        INFINITY},
		{2, 0, 3, 2, INFINITY,        INFINITY},
		{5, 3, 0, 3, 1,	              5       },
		{1, 2, 3, 0, 1,		          INFINITY},
		{INFINITY, INFINITY,        1, 1, 0, 2},
		{INFINITY, INFINITY,5, INFINITY , 2, 0},
	};
	bool visited[SIZE];
	int distance[SIZE];

public:
	Dijkstra()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			distance[i] = 0;
		}
	}
public:
	void Update(int start)
	{
		distance[start] = 0;

		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = graph[start][i];
		}

		visited[start] = true;

		for (int i = 0; i < SIZE - 1; i++)
		{
			int minNode = find();

			visited[minNode] = true;

			for (int j = 0; j < SIZE; j++)
			{
				if (!visited[j])
				{
					if (distance[minNode] + graph[minNode][j] < distance[j])
					{
						distance[j] = distance[minNode] + graph[minNode][j];
					}
				}
			}

		}

		for (const auto& elem : distance)
		{
			cout << elem << " ";
		}

	}

	// 최솟값 찾는 함수 int니까 return 해줘야할거같은데 
	const int& find()
	{
		// 이러면 안됐나..
		int min = INFINITY;		// 이게 최소비용노드(?)
		// 변수 하나 더? 
		int minIndex = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (distance[i] < min && !visited[i])
			{
				// 제외?
				min = distance[i];
				minIndex = i;
			}
		}
		return minIndex;			// 뭘 반환해야할까 최솟값이겠지?
	}
};
#pragma endregion


int main()
{
	Dijkstra dij;
	dij.Update(0);
	return 0;
}