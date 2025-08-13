#include "Util.h"
#define SIZE 8
#pragma region 깊이 우선 탐색 (Depth First Search == DFS)
// root 노드에서부터 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법
// 깊이 우선 탐색은 스택을 활용한다.

class Graph
{
private:
	//vector<pair<int, int>> adj;		// 이건 보류
	vector<int> adj[SIZE];
	bool visited[SIZE];					// 방문 여부 체크			방문 안했으면 0, 했으면 1
	
public:
	// 초기화 어케함..?
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
		// ? ㅓ.....
		// 방문했다는 증거가 필요한거같은데 이게 증거야? 
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	// 1 2 3 6 7 4 5 
	void search(int start)		// 재귀로 한다고? 
	{
		visited[start] = true;		// 아마도 방문한 흔적
		cout << start << " " << endl;
		// 다시 재방문은 못하나? 그래서 표시하는건가

		// for? while? 둘다 아닌가 뭐지 
		for (auto i : adj[i])
		{
			if (visited[i] == false)
			{
				search(i);
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

	graph.insert(2, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.insert(4, 5);
	graph.insert(6, 7);

	graph.search(8);
	return 0;
}