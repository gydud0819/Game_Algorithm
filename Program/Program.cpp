#include "Util.h"
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
		q.push(vertex);

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout << temp << " ";

			for (int i = 0; i < adj[temp].size(); i++)
			{
				int next = adj[temp][i];
				if (degree[next] == 0)
				{
					degree[vertex]--;
					q.push(next);

				}
			}
		}

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
	return 0;
}