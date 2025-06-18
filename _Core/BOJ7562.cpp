/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 7562
	URL			: https://www.acmicpc.net/problem/7562
	Date		: 2025-06-18 09:03 ~ 2025-06-18 10:03
	Refactoring	:
	Review
		- 큰 수라고 적은게 너무 작아서 생긴 문제였다. 문제 입력 조건 잘 보기 ...
		- 통화좀 하고, 커피 사오느라 시간 길어짐. 20분 정도에 풀긴 한듯.
		- GPT 리뷰
			- 최단거리를 따로 계산하고 있는데, 이 문제는 BFS에 들어가는 순간이 최단임
			- 최적화를 위해 목적지 도착시 break 하는거 좋음
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


std::pair<int, int> MOVE_KNIGHT[] = {
	{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
	{2, -1}, {1, -2}, {2, 1}, {1, 2}
};

std::pair<int, int> operator+ (std::pair<int, int> p1, std::pair<int, int> p2) {
	return std::make_pair(p1.first + p2.first, p1.second + p2.second);
}

bool IsValidPosition(std::pair<int, int> p, int l) {
	return (0 <= p.first && p.first < l) && (0 <= p.second && p.second < l);
}


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	// 전형적인 BFS 문제다. 주어지는 입력은 0-based index 친화적이다.
	// queue를 이용해서 이동 횟수, 좌표를 기록하는 BFS를 수행하면 되겠네.

	int TC; // Num of testcases
	std::cin >> TC;

	for (int tc = 0; tc < TC; tc++) { // 좀 헷갈리는 변수지만, 여기서만 쓸거고 실수 여지 없음
		int L; // length of side of board
		std::cin >> L;

		std::pair<int, int> currPos; // current knight position
		std::pair<int, int> destPos; // position of destination

		std::cin >> currPos.first >> currPos.second;
		std::cin >> destPos.first >> destPos.second;

		if (currPos == destPos) {
			std::cout << "0\n";
			continue;
		}

		std::queue<std::pair<std::pair<int, int>, int>> q; // ({x, y}, distance) pair
		// TODO: 이런 구조 쓰는게 맞나? 좀 복잡하긴 한데

		std::vector<std::vector<int>> visit(L, std::vector<int>(L, 1000));
		// TODO: INF 어떻게 쓰더라... 일단 적당히 큰 수 입력
		q.push({ currPos, 0 });

		while (!q.empty()) {
			auto curr = q.front();
			auto pos = curr.first;
			auto dist = curr.second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				auto next = curr.first + MOVE_KNIGHT[i];
				if (IsValidPosition(next, L)) {
					if (visit[next.first][next.second] > curr.second + 1) {
						q.push({ next, curr.second + 1 });
						visit[next.first][next.second] = curr.second + 1;
					}
				}
			}
		}

		std::cout << visit[destPos.first][destPos.second] << "\n";
	}


	// ---------[End]---------
	return 0;
}