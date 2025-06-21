/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 11660
	URL			: https://www.acmicpc.net/problem/11660
	Date		: 2025-06-21 09:55 ~ 2025-06-21 10:24
	Refactoring	:
	Review
		- 의외로 시간부족이 안나오네? 좀 부족할지도 모르겠다고 예상했는데.
		- GPT 리뷰
			- 2차원 누적합을 구현하는게 좋다.
*/

#include <iostream>
#include <algorithm>
#include <vector>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	// 숫자는 10^6개, 횟수는 10^5회 -> 각 회차당 O(N)으로 끝내야한다. 
	int N; // size of matrix
	int M; // TestCases
	std::vector<std::vector<int>> matrix;

	{ // Input
		std::cin >> N >> M;
		// 1-based index로 좌표가 주어지므로, size + 1
		matrix.resize(N + 1, std::vector<int>(N + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				std::cin >> matrix[i][j];
			}
		}
	}


	// 한 줄마다 구간합을 구해서, 각 줄마다 합을 계산해서 더해도 될거같은데 시간?
	std::vector<std::vector<int>> sumMatrix(N + 1, std::vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		// 1-based라서 0번째 index 따로 처리 안해도 됨 -> 깔끔해져서 좋다.
		for (int j = 1; j <= N; j++) {
			sumMatrix[i][j] = sumMatrix[i][j - 1] + matrix[i][j];
		}
	}
	// (x1, y1)부터 (x1, y2)까지 숫자의 합 -> sumMatrix[x1][y2] - sumMatrix[x1][y1 - 1]

	int x1, y1;
	int x2, y2;
	for (int tc = 0; tc < M; tc++) {
		std::cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;
		for (int idx = x1; idx <= x2; idx++) {
			sum += (sumMatrix[idx][y2] - sumMatrix[idx][y1 - 1]);
		}

		std::cout << sum << "\n";
	}



	// ---------[End]---------
	return 0;
}
