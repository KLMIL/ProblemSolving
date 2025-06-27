/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 14503 - 로봇 청소기
	URL			: https://www.acmicpc.net/problem/14503
	Date		: 2025-06-27 09:25 ~ 2025-06-27 09:59
	Refactoring	:
	Review
		-
*/

#include <iostream>
#include <algorithm>
#include <vector>


std::pair<int, int> DIR[4] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1} // 0, 1, 2, 3
};

// 좌표 계산을 위한 std::pair의 연산자 오버라이딩
std::pair<int, int> operator+(std::pair<int, int> p1, std::pair<int, int> p2) {
	return std::make_pair(p1.first + p2.first, p1.second + p2.second);
}

// 방 바깥으로 나가는지 검사
bool IsValidDir(int N, int M, std::pair<int, int> p) {
	return (0 <= p.first && p.first < N) && (0 <= p.second && p.second < M);
}

// 벽이 아니고, 쓰레기가 있는 위치를 검사
bool IsThereWaste(int N, int M, std::pair<int, int> p, std::vector<std::vector<int>>& grid) {
	for (int d = 0; d < 4; d++) {
		std::pair<int, int> currDir = p + DIR[d];
		bool isGridIsWaste = (grid[currDir.first][currDir.second] == 0);
		if (IsValidDir(N, M, p) && isGridIsWaste) {
			return true;
		}
	}
	return false;
}

int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N, M; // vertical, horizontal len of room
	int r, c; // vertical, horizontal loc of vacuum
	int d; // 0 = (-1, 0) / 1 = (0, 1) / 2 = (1, 0) / 3 = (0, -1)
	std::vector<std::vector<int>> grid; // 0 = waste, 1 = wall, 2 = cleaned up

	{ // Input
		std::cin >> N >> M;
		std::cin >> r >> c >> d;
		grid.resize(N, std::vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cin >> grid[i][j];
			}
		}
	}


	std::pair<int, int> curr = { r, c }; // 관리하기 편하도록 pair로 변환
	std::pair<int, int> dir = DIR[d]; // 방향을 pair로 변환

	// 기본적으로 DFS의 느낌을 갖고 있다.
	// 경로나 방문 추적이 필요없으므로 stack까지 쓸 필요는 없고, DFS 느낌으로 구현만 하면 될 듯.
	int cnt = 0;
	while (true) { // 움직일 수 없을때까지 반복
		// 현재 칸에 있다면 청소
		if (grid[curr.first][curr.second] == 0) {
			cnt++;
			grid[curr.first][curr.second] = 2;
			//continue;
		}

		if (IsThereWaste(N, M, curr, grid)) { // 주변 4칸 중 청소할 곳이 있는 경우
			// 청소할 방향을 찾기 위해 반시계방향으로 회전
			for (int i = 0; i < 4; i++) {
				d = (d + 3) % 4;
				dir = DIR[d];
				std::pair<int, int> nextPos = curr + dir;
				if (grid[nextPos.first][nextPos.second] == 0) {
					//cnt++;
					//grid[nextPos.first][nextPos.second] = 2;
					curr = nextPos;
				}
				break;
			}
		}
		else { // 주변 4칸 중 청소할 곳이 없는 경우
			// 후진 좌표 계산
			std::pair<int, int> backDir = { dir.first * -1, dir.second * -1 };
			std::pair<int, int> backLoc = curr + backDir;
			if (grid[backLoc.first][backLoc.second] == 1) { // 뒤가 벽이라면 정지
				break;
			}
			else { // 후진
				curr = backLoc;
			}
		}
	}


	std::cout << cnt << "\n";


	// ---------[End]---------
	return 0;
}
