/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 2167
	URL			: https://www.acmicpc.net/problem/2167
	Date		: 2025-06-23 10:02 ~ 2025-06-23 10:14
	Refactoring	:
	Review
		-
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


	int N;
	int M;
	std::vector<std::vector<int>> v;
	int K;

	{ // Input
		std::cin >> N >> M;
		v.resize(N + 1, std::vector<int>(M + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				std::cin >> v[i][j];
			}
		}
		std::cin >> K;
	}

	std::vector<std::vector<int>> partSum(N + 1, std::vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			partSum[i][j] = v[i][j] + (partSum[i - 1][j] + partSum[i][j - 1]) - partSum[i - 1][j - 1];
		}
	}

	//std::cout << "partsum check\n";
	//for (size_t i = 0; i < v.size(); i++) {
	//	for (size_t j = 0; j < v[0].size(); j++) {
	//		std::cout << partSum[i][j] << " ";
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";

	int i, j, x, y;
	for (int tc = 0; tc < K; tc++) {
		std::cin >> i >> j >> x >> y;
		std::cout << partSum[x][y] - (partSum[i - 1][y] + partSum[x][j - 1]) + partSum[i - 1][j - 1] << "\n";
	}




	// ---------[End]---------
	return 0;
}
