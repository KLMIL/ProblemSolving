/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 11725
	URL			: https://www.acmicpc.net/problem/11725
	Date		: 2025-06-16 09:24 ~ 2025-06-16 09:40
	Refactoring	:
	Review
		- 살짝 비효율적인 맛이 있는것도 같은데, 괜찮네.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N; // Num of nodes
	std::vector<std::vector<int>> g; // adj. matrix graph

	{ // Input
		std::cin >> N;
		g.resize(N + 1, std::vector<int>());

		std::pair<int, int> input;
		for (int i = 0; i < N - 1; i++) {
			std::cin >> input.first >> input.second;
			g[input.first].push_back(input.second);
			g[input.second].push_back(input.first);
		}
	}


	std::vector<std::pair<int, int>> visited(N + 1, { 0, 0 }); // { visited, parentNode } pair
	std::queue<int> q;

	q.push(1);
	visited[1] = { 1, 0 };

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int node : g[curNode]) {
			if (visited[node].first == 0) {
				q.push(node);
				visited[node].first = 1;
				visited[node].second = curNode;
			}
		}
	}


	for (int i = 2; i <= N; i++) {
		std::cout << visited[i].second << "\n";
	}


	// ---------[End]---------
	return 0;
}