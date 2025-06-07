/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 2805
	URL			: https://www.acmicpc.net/problem/2805
	Date		: 2025-06-07 08:30 ~ 2025-06-07 09:18
	Refactoring	:
	Review
		- 이분탐색의 "느낌"을 기억하고 있어서 그 방식으로 풀었다.
		  확신이 없어서 테스트 하느라 애먹음 ... 디버깅이 어려웠다.
		- GPT 리뷰
			- 결과값은 minIdx가 맞을 것. 주의해야함.
			- vector는 값을 복사해서 전달하니, 참조로 전달하면 효율적.
*/

#include <iostream>
#include <algorithm>
#include <vector>


long long CutTreeSum(std::vector<int> trees, int height) {
	long long sum = 0;
	for (size_t i = 0; i < trees.size(); i++) {
		sum += (trees[i] - height) <= 0 ? 0 : (trees[i] - height);
	}

	//std::cout << "sum: " << sum << " / ";
	return sum;
}


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N; // Number of trees. 1 <= N <= 1 000 000
	int M; // Required length of wood. 1 <= M <= 2 000 000 000
	std::cin >> N >> M;

	std::vector<int> trees(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> trees[i];
	}

	long long minIdx = 0;
	long long maxIdx = 2000000000;
	long long curIdx = 1000000000;

	while (minIdx + 1 < maxIdx) {
		if (CutTreeSum(trees, curIdx) < M) {
			maxIdx = curIdx;
			curIdx = (minIdx + maxIdx) / 2;
		}
		else {
			minIdx = curIdx;
			curIdx = (minIdx + maxIdx) / 2;
		}

		//std::cout << "min: " << minIdx << ", max: " << maxIdx << ", cur: " << curIdx << "\n";;
	}

	std::cout << curIdx;


	// ---------[End]---------
	return 0;
}