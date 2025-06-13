/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 11724
	URL			: https://www.acmicpc.net/problem/11724
	Date		: 2025-06-13 08:57 ~ 2025-06-13 09:42
	Refactoring	:
	Review
		- 어떤 알고리즘을 써야 하는지는 알겠는데, 구현이 어렵네. 포기. 찾아보자.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------

	{ // 문제 풀이 1트. Union-Find 쓰려고 했으나, 실패. 검색 후 BFS로 다시 시도해보기로 함. 
		// TODO: 연결 요소가 뭐야?
		// TODO: vector resize 하는법. 컨테이너를 원소로 한다면? 용어도 찾아보기
		// TODO: Union Find 이론 한번 찾아보기.
	}

	int N; // num of vertice
	int M; // num of edges
	std::vector<std::vector<int>> graph;

	{ // Input
		std::cin >> N >> M;

		// 노드 편의를 위해 1-indexed로 생성
		// TODO: 희소 행렬이라고 하던가? 0 아닌 요소만 저장하는데 유리한거. 그거 만드려는거임.
		graph.resize(N + 1, std::vector<int>());

		int from, to;
		for (int i = 0; i < M; i++) {
			std::cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
	}

	// Check Input
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < graph[i].size(); j++) {
	//		std::cout << graph[i][j] << " ";
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";

	std::queue<int> q;
	std::vector<int> visited(N + 1, 0);



	auto AllVisited = [&visited]() -> bool {
		for (size_t i = 1; i < visited.size(); i++) {
			if (visited[i] == 0) {
				return false;
			}
		}
		return true;
		};

	int mass = 0;
	while (!AllVisited()) {
		for (size_t i = 1; i < visited.size(); i++) {
			if (visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
				break;
			}
		}
		mass++;
		while (!q.empty()) {
			//std::cout << "Cur Node: " << q.front() << "\n";
			int cur = q.front();
			q.pop();

			for (size_t i = 0; i < graph[cur].size(); i++) {
				if (visited[graph[cur][i]] == 0) {
					//std::cout << "Push: " << graph[cur][i] << "\n";
					q.push(graph[cur][i]);
					visited[graph[cur][i]] = 1;
				}
			}
		}
	}


	std::cout << mass << "\n";


	// ---------[End]---------
	return 0;
}