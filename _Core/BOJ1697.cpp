/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 1697
	URL			: https://www.acmicpc.net/problem/1697
	Date		: 2025-06-12 08:37 ~ 2025-06-12 09:02
	Refactoring	:
	Review
		- 사실 완전탐색이랑 다를게 없다 ... 효율성에 대한 고민?
			- N = 10^5라서 O(N^2)에서 2초면 시간 충분하겠다 판단해서 사용한 알고리즘이긴 함.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	// 이건 이분탐색 아냐? 경우의 수를 봐야하니 아니구나. 
	int N; // Location of "Subin". 0 <= N <= 100,000
	int K; // Location of "Brother". 0 <= K <= 100,000

	{ // Input
		std::cin >> N >> K;
	}


	std::queue<std::pair<int, int>> q; // (Location, Distance) pair queue for BFS
	std::map<int, int> dist; // Distance map
	q.push({ N, 0 });
	dist[N] = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		//std::cout << "front: " << front.first << ", dist: " << front.second << "\n";

		int teleportLoc = front.first * 2;
		int walkbackLoc = front.first - 1;
		int walkfrontLoc = front.first + 1;

		// TODO: std::map에서 특정 원소 존재하는지 찾는법 등
		// TODO: if문 조건의 분리에 대해서. 가독성 좋은 코드
		if (teleportLoc <= 100000 && (dist.find(teleportLoc) == dist.end() || dist[teleportLoc] > front.second + 1)) {
			dist[teleportLoc] = front.second + 1;
			q.push({ teleportLoc, dist[teleportLoc] });
		}
		if (walkbackLoc >= 0 && (dist.find(walkbackLoc) == dist.end() || dist[walkbackLoc] > front.second + 1)) {
			dist[walkbackLoc] = front.second + 1;
			q.push({ walkbackLoc, dist[walkbackLoc] });
		}
		if (walkfrontLoc <= 100000 && (dist.find(walkfrontLoc) == dist.end() || dist[walkfrontLoc] > front.second + 1)) {
			dist[walkfrontLoc] = front.second + 1;
			q.push({ walkfrontLoc, dist[walkfrontLoc] });
		}
	}


	std::cout << dist[K] << "\n";


	// ---------[End]---------
	return 0;
}