/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 2217
	URL			: https://www.acmicpc.net/problem/2217
	Date		: 2025-06-22 12:14 ~ 2025-06-22 12:21
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
	std::vector<int> lope;

	{ // Input
		std::cin >> N;
		lope.resize(N);
		for (int i = 0; i < N; i++) {
			std::cin >> lope[i];
		}
	}

	// 로프를 추가해서 1이라도 더 많이 들면 이득이니까,
	// 정렬한 뒤에 선택한 갯수보다 큰 값을 찾으면 되겠는데?

	std::sort(lope.begin(), lope.end());
	int max = 0;
	for (int i = 0; i < N; i++) {
		max = std::max(max, lope[i] * (N - i));
	}

	std::cout << max;


	// ---------[End]---------
	return 0;
}
