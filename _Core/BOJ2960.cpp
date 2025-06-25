/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 2960
	URL			: https://www.acmicpc.net/problem/2960
	Date		: 2025-06-25 09:55 ~ 2025-06-25 10:06
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


	// 7, 3 -> 6 // 2부터 7까지 수 중, 
	//		2 -> 2 4 6 지움, 
	//		3 -> 3 6 지움(실패), 
	//		5 -> (실패) 뭐지..?
	// 15, 12 -> 7 // 2부터 15까지 수 중,
	//		2 -> 2, 4, 6, 8, 10, 12, 14 (7개)
	//		3 -> 3, 6, 9, 12, 15 -> (5개 중 2개 실패)
	//		5 -> 5, 10, 15 -> (3개 중 2개 실패)
	//		7 -> 7, 14 -> (2개 중 1개 실패)

	// 아, 소수인 첫 숫자도 지우는거에 포함이구나.

	int N, K;
	std::cin >> N >> K;

	std::vector<int> seive(N + 1, 0);

	int cnt = 0;
	bool found = false;
	for (int i = 2; i <= N && !found; i++) {
		//std::cout << "i: " << i << "\n";
		if (seive[i] == 0) {
			for (int j = i; j <= N && !found; j += i) {
				if (seive[j] == 0) {
					cnt++;
					seive[j] = 1;

					//std::cout << "Remove " << j << "\n";

					if (cnt == K) {
						found = true;
						std::cout << j << "\n";
					}
				}
			}
		}
	}



	// ---------[End]---------
	return 0;
}
