/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 11047
	URL			: https://www.acmicpc.net/problem/11047
	Date		: 2025-06-19 08:55 ~ 2025-06-19 09:00
	Refactoring	:
	Review
		- 쫌 쉽네 ㅎ
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


	int N; // num of coin variations
	int K; // target price
	std::vector<int> worth;
	// TODO: 가치가 영어로 뭐더라 ... 변수이름짓기 ...

	{ // Input
		std::cin >> N >> K;
		worth.resize(N);
		for (int i = 0; i < N; i++) {
			std::cin >> worth[i];
		}
	}


	int rest = K;
	int coinCnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (worth[i] > rest) continue;

		int currCoin = rest / worth[i];
		rest -= (worth[i] * currCoin);
		coinCnt += currCoin;

		if (rest == 0) break;
	}


	std::cout << coinCnt << "\n";


	// ---------[End]---------
	return 0;
}