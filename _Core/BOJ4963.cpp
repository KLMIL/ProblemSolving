/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 4963
	URL			: https://www.acmicpc.net/problem/4963
	Date		: 2025-06-17 08:42 ~ 2025-06-17 09:14
	Refactoring	:
	Review
		- 시간복잡도를 고려하지 않고, 알고리즘 풀이만을 생각하면서 풀긴 했다. 이게 맞는건가?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


void InputCheck(int h, int w, std::vector<std::vector<int>>& map) {
	std::cout << "Input Check\n";
	std::cout << "Height: " << h << ", Width: " << w << "\n";
	for (auto h : map) {
		for (int w : h) {
			std::cout << w << " ";
		}
		std::cout << "\n";
	}
}

bool IsValidLocation(std::pair<int, int> loc, int h, int w) {
	return (0 <= loc.first && loc.first < h) && (0 <= loc.second && loc.second < w);
}


std::pair<int, int> operator+(std::pair<int, int> p1, std::pair<int, int> p2) {
	return std::make_pair(p1.first + p2.first, p1.second + p2.second);
}

const std::pair<int, int> DIR[8] = { // 시계 방향으로 8방향
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int w; // width of map
	int h; // height of map
	while (true) {
		std::cin >> w >> h;
		if (w == 0 && h == 0) break;

		// TODO: map이 최선의 이름일까? 좋은 변수 이름 짓기. 특히 코테에서.
		std::vector<std::vector<int>> map(h, std::vector<int>(w, -1));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				std::cin >> map[i][j]; // 1: ground / 0: sea
			}
		}

		//InputCheck(h, w, map);

		// Union-Find 써볼까 했는데, 이 문제는 BFS가 낫겠는데? 정확도가 1번, 빠른 구현이 2번, 효율성이 3번
		// TODO: 어제 GPT가 알려준 덩어리 갯수 찾는 BFS 알고리즘 뭐더라 .. 좀 읽어둘걸.
		std::queue<std::pair<int, int>> q;
		std::vector<std::vector<int>> visit(h, std::vector<int>(w, 0));

		int island = 0;

		while (true) {
			if (q.empty()) {
				bool found = false;
				for (int i = 0; i < h && !found; i++) {
					for (int j = 0; j < w && !found; j++) {
						if (map[i][j] == 1 && visit[i][j] == 0) { // 방문하지 않은 곳 push
							//std::cout << "Search From: (" << i << ", " << j << ")\n";
							q.push({ i, j });
							visit[i][j] = 1;
							found = true;
						}
					}
				}
				if (q.empty()) {
					break; // 탐색 완료
				}
			}
			else {
				island++;
				while (!q.empty()) {
					std::pair<int, int> curr = q.front();
					q.pop();
					//std::cout << "Curr Node: (" << curr.first << ", " << curr.second << ")\n"; 
					// TODO: 가독성 좋은 디버깅 출력 방법? 띄어쓰기?

					for (int i = 0; i < 8; i++) {
						std::pair<int, int> next = curr + DIR[i];
						if (!IsValidLocation(next, h, w)) continue;
						if (map[next.first][next.second] == 1 && visit[next.first][next.second] == 0) {
							//std::cout << "Push: (" << next.first << ", " << next.second << ")\n";
							q.push(next);
							visit[next.first][next.second] = 1;
						}
					}
				}
			}
		}

		std::cout << island << "\n";
	} // while (h != 0 && w != 0); 
	// TODO: Do-While은 뭔가 까다롭단 말이지
	// TODO: ! & ! 랑 ||랑 같나? 대우 조건에 대해 알아보기.


	// ---------[End]---------
	return 0;
}