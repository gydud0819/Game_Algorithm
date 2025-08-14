#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define SIZE 8

#pragma region BFS (너비 우선 탐색)
// 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선적으로 방문하는 탐색이다.

// 더 이상 방문하지 않은 정점이 없을 때 까지 방문하지 않은 모든 정점들에 대해 너비 우선 탐색을 적용한다.
// 한번 방문한 곳은 다시 들리지 않아야 한다. (DFS랑 동일)
// queue를 활용한다. (선입선출)

class Graph
{
private:
	queue<int> q;
	vector<int> adj[SIZE];
	bool visited[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}
public:

	void insert(int i, int j)
	{
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	void search(int start)
	{
		q.push(start);
		visited[start] = true;

		// queue가 빌때까지 돌리면 while?
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout << temp << " ";

			for (int i = 0; i < adj[temp].size(); i++)
			{
				int next = adj[temp][i];

				if (visited[next] == false)
				{
					q.push(next);
					visited[next] = true;
				}

			}
		}
	}
};

#pragma endregion


int main()
{
	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.search(1);
	return 0;
}