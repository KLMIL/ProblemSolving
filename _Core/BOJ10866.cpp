/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 10866
	URL			: https://www.acmicpc.net/problem/10866
	Date		: 2025-06-29 16:28 ~ 2025-06-29 17:21
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
	std::cin >> N;


	int* frontArr = new int[N];
	int* backArr = new int[N];
	int frontIdx = -1;
	int backIdx = -1;
	int frontSize = 0;
	int backSize = 0;


	std::string order;
	for (int o = 0; o < N; o++) {
		std::cin >> order;
		int input;

		if (order == "push_front") {
			std::cin >> input;
			frontArr[++frontIdx] = input;
			frontSize++;
		}
		if (order == "push_back") {
			std::cin >> input;
			backArr[++backIdx] = input;
			backSize++;
		}

		if (order == "pop_front") {
			if (frontSize == 0) {
				if (backSize == 0) {
					std::cout << "-1\n";
				}
				else {
					std::cout << backArr[backIdx - backSize + 1] << "\n";
					backSize--;
				}
			}
			else {
				std::cout << frontArr[frontIdx--] << "\n";
				frontSize--;
			}
		}
		if (order == "pop_back") {
			if (backSize == 0) {
				if (frontSize == 0) {
					std::cout << "-1\n";
				}
				else {
					std::cout << frontArr[frontIdx - frontSize + 1] << "\n";
					frontSize--;
				}
			}
			else {
				std::cout << backArr[backIdx--] << "\n";
				backSize--;
			}
		}

		if (order == "size") {
			std::cout << frontSize + backSize << "\n";
		}
		if (order == "empty") {
			if (frontSize == 0 && backSize == 0) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}

		if (order == "front") {
			if (frontSize == 0) {
				if (backSize == 0) {
					std::cout << "-1\n";
				}
				else {
					std::cout << backArr[backIdx - backSize + 1] << "\n";
				}
			}
			else {
				std::cout << frontArr[frontIdx] << "\n";
			}
		}
		if (order == "back") {
			if (backSize == 0) {
				if (frontSize == 0) {
					std::cout << "-1\n";
				}
				else {
					std::cout << frontArr[frontIdx - frontSize + 1] << "\n";
				}
			}
			else {
				std::cout << backArr[backIdx] << "\n";
			}
		}
	}


	// ---------[End]---------
	return 0;
}
