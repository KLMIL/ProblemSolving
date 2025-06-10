/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 10773
	URL			: https://www.acmicpc.net/problem/10773
	Date		: 2025-06-10 08:51 ~ 2025-06-10 08:55
	Refactoring	:
	Review
		- 정말 간단한, 스택 자체 사용법에 대한 문제.
*/

#include <iostream>
#include <algorithm>
#include <stack>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int K; // number of numbers
	std::stack<int> st;
	// TODO: std::vector와 std::stack의 속도, 공간 차이?

	{ // Input
		std::cin >> K;
	}


	int input = 0;
	for (int i = 0; i < K; i++) {
		std::cin >> input;
		if (input == 0) {
			st.pop();
		}
		else {
			st.push(input);
		}
	}

	int result = 0;
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}


	std::cout << result << "\n";


	// ---------[End]---------
	return 0;
}