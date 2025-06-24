/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 12100 - 2048(Easy)
	URL			: https://www.acmicpc.net/problem/12100
	Date		: 2025-06-24 09:08 ~ 10:21
	Refactoring	:
	Review
		- 범위 잘못 생각해서 그런거였네 ..
		- size_t에 문제가 좀 있었다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


int MoveUp(std::vector<std::vector<int>> board, int depth);
int MoveDown(std::vector<std::vector<int>> board, int depth);
int MoveLeft(std::vector<std::vector<int>> board, int depth);
int MoveRight(std::vector<std::vector<int>> board, int depth);


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N; // length of on side. 1 <= N <= 20
	std::vector<std::vector<int>> board;

	{ // Input
		std::cin >> N;
		board.resize(N, std::vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cin >> board[i][j];
			}
		}
	}


	// 시간복잡도 계산이 어렵네 ... 알고리즘 분류 몰랐으면 아예 생각 못했을 듯.
	// 상, 하, 좌, 우로 움직일 수 있다.
	// 움직일 때, 이전 정보를 저장해두는 방법이 필요하다
	std::cout << std::max({ MoveUp(board, 1), MoveDown(board, 1), MoveLeft(board, 1), MoveRight(board, 1) }) << "\n";



	// ---------[End]---------
	return 0;
}


void printBoard(std::vector<std::vector<int>> board) {
	std::cout << "Print Board\n";
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "========================\n";
}


int MoveUp(std::vector<std::vector<int>> board, int depth) {
	//std::cout << "Move Up!\n";

	if (depth == 6) {
		int max = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				max = std::max(max, board[i][j]);
			}
		}
		//printBoard(board);
		return max;
	}

	// 위로 옮기는 연산 수행
	for (int i = 0; i < board.size(); i++) {
		int boardIdx = 0;

		// 큐에 세로 한 줄 모두 넣음
		std::queue<int> q;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] != 0) {
				q.push(board[j][i]);
			}
		}

		while (!q.empty()) {
			int currNum = q.front();
			q.pop();

			// 다음 수가 지금 수와 같다면 더해준다
			if (!q.empty() && q.front() == currNum) {
				q.pop();
				currNum *= 2;
			}

			// 위에서부터 채움
			board[boardIdx++][i] = currNum;
		}

		// 남은 칸을 0으로 채움
		for (int j = boardIdx; j < board.size(); j++) {
			board[j][i] = 0;
		}
	}

	// 다른 방향으로 탐색
	return std::max({ MoveUp(board, depth + 1), MoveDown(board, depth + 1), MoveLeft(board, depth + 1), MoveRight(board, depth + 1) });
}

int MoveDown(std::vector<std::vector<int>> board, int depth) {
	//std::cout << "Move Down!\n";

	if (depth == 6) {
		int max = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				max = std::max(max, board[i][j]);
			}
		}
		//printBoard(board);
		return max;
	}

	// 아래로 옮기는 연산 수행
	for (int i = 0; i < board.size(); i++) {
		int boardIdx = board.size() - 1;

		// 큐에 세로 한 줄 모두 넣음
		std::queue<int> q;
		for (int j = board.size() - 1; j >= 0; j--) {
			if (board[j][i] != 0) {
				q.push(board[j][i]);
			}
		}

		while (!q.empty()) {
			int currNum = q.front();
			q.pop();

			// 다음 수가 지금 수와 같다면 더해준다
			if (!q.empty() && q.front() == currNum) {
				q.pop();
				currNum *= 2;
			}

			// 아래에서부터 채움
			board[boardIdx--][i] = currNum;
		}

		// 남은 칸을 0으로 채움
		for (int j = boardIdx; j >= 0; j--) {
			board[j][i] = 0;
		}
	}

	return std::max({ MoveUp(board, depth + 1), MoveDown(board, depth + 1), MoveLeft(board, depth + 1), MoveRight(board, depth + 1) });
}

int MoveLeft(std::vector<std::vector<int>> board, int depth) {
	//std::cout << "Move Left!\n";

	if (depth == 6) {
		int max = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				max = std::max(max, board[i][j]);
			}
		}
		//printBoard(board);
		return max;
	}

	// 왼쪽으로 옮기는 연산 수행
	for (int i = 0; i < board.size(); i++) {
		int boardIdx = 0;

		// 큐에 세로 한 줄 모두 넣음
		std::queue<int> q;
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] != 0) {
				q.push(board[i][j]);
			}
		}

		while (!q.empty()) {
			int currNum = q.front();
			q.pop();

			// 다음 수가 지금 수와 같다면 더해준다
			if (!q.empty() && q.front() == currNum) {
				q.pop();
				currNum *= 2;
			}

			// 왼쪽부터 채움
			board[i][boardIdx++] = currNum;
		}

		// 남은 칸을 0으로 채움
		for (int j = boardIdx; j < board.size(); j++) {
			board[i][j] = 0;
		}
	}

	return std::max({ MoveUp(board, depth + 1), MoveDown(board, depth + 1), MoveLeft(board, depth + 1), MoveRight(board, depth + 1) });
}

int MoveRight(std::vector<std::vector<int>> board, int depth) {
	//std::cout << "Move Right!\n";

	if (depth == 6) {
		int max = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				max = std::max(max, board[i][j]);
			}
		}
		//printBoard(board);
		return max;
	}

	// 오른쪽으로 옮기는 연산 수행
	for (int i = 0; i < board.size(); i++) {
		int boardIdx = board.size() - 1;

		// 큐에 세로 한 줄 모두 넣음
		std::queue<int> q;
		for (int j = board.size() - 1; j >= 0; j--) {
			if (board[i][j] != 0) {
				q.push(board[i][j]);
			}
		}

		while (!q.empty()) {
			int currNum = q.front();
			q.pop();

			// 다음 수가 지금 수와 같다면 더해준다
			if (!q.empty() && q.front() == currNum) {
				q.pop();
				currNum *= 2;
			}

			// 왼쪽부터 채움
			board[i][boardIdx--] = currNum;
		}

		// 남은 칸을 0으로 채움
		for (int j = boardIdx; j >= 0; j--) {
			board[i][j] = 0;
		}
	}

	return std::max({ MoveUp(board, depth + 1), MoveDown(board, depth + 1), MoveLeft(board, depth + 1), MoveRight(board, depth + 1) });
}