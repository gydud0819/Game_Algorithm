#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define SIZE 8

#pragma region 크루스칼
// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프로,
// 그래프의 모든 정점을 최소 비용으로 연결하는 트리이다.

// 그래프의 정점의 개수가 n개 일 때, 간선의 수는 n-1개 이다.

// 요약 : 가장 적은 비용으로 모든 노드를 연결하기 위해 사용되는 알고리즘

int parent[SIZE];

class Kruskal
{
private:
	class Edge
	{
	private:
		int x;		//
		int y;
		int weight; // 가중치

	public:
		Edge(int _x, int _y, int _weight)
		{
			x = _x;
			y = _y;
			weight = _weight;
		}

		const int& X() { return x; }
		const int& Y() { return y; }
		const int& WEIGHT() { return weight; }

		const bool& operator < (const Edge& edge)			// 이거부터 난관이네;;;   내 엣지랑 상대방 엣지?
		{
			return weight < edge.weight;
		}
	};

	vector<Edge> nodelist;
	int cost;		// 최소 비용 신장 트리 

public:
	Kruskal() : cost(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = i;
		}
		// 얜 초기화 어케함..?
	}

public:
	void insert(int vertexX, int vertexY, int weight)
	{
		nodelist.push_back(Edge(vertexX, vertexY, weight));

	}

	void calculate()
	{
		// 1. 정렬된 순서에 맞게 그래프에 포함시키기 (sort함수 써서 정렬하기)
		sort(nodelist.begin(), nodelist.end());

		//for (int i = 0; i < nodelist.size(); i++)
		//{
		//	cout << nodelist[i].X() << endl;
		//	cout << nodelist[i].Y() << endl;
		//	cout << nodelist[i].WEIGHT() << endl;
		//	cout << endl;
		//}

		// 2. 포함시키기 전에 사이클이 형성되는지 확인하기
		for (Edge e : nodelist)
		{
			// 3. 사이클을 생성하는 경우 간선을 포함하지 않기

			if (Find(e.X()) != Find(e.Y()))
			{
				Union(e.X(), e.Y());
				cost += e.WEIGHT();		 //edge 총 더한 값(12 + 13 + 15 + 18 + 23 + 36)

			}
		}
		cout << "최소 비용 : " << cost << endl;
	}


	// 일단 갖고는 왔는데 어케 적용하지 ㅇㅅㅇ
	int Find(int x)
	{
		if (parent[x] != x)
		{
			parent[x] = Find(parent[x]);
		}
		return parent[x];

	}

	// 합치는 함수
	void Union(int x, int y)
	{
		int parentX = Find(x);
		int parentY = Find(y);

		if (parentX < parentY)
		{
			parent[parentY] = parentX;
		}

		else if (parentX > parentY)
		{
			parent[parentX] = parentY;
		}
	}

};
#pragma endregion


int main()
{
	Kruskal krus;
	krus.insert(1, 7, 12);
	krus.insert(4, 7, 13);

	krus.insert(1, 4, 30);
	krus.insert(2, 4, 23);

	krus.insert(1, 2, 71);
	krus.insert(1, 5, 15);



	krus.insert(5, 7, 79);
	krus.insert(3, 5, 18);

	krus.insert(3, 6, 36);
	krus.insert(5, 6, 44);



	krus.calculate();

	return 0;
}