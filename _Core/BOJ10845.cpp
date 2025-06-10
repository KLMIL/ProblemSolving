/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 10845
	URL			: https://www.acmicpc.net/problem/10845
	Date		: 2025-06-11 08:26 ~ 2025-06-11 08:39
	Refactoring	:
	Review
		- 실제 사용하는 부분의 흐름을 깔끔하게 유지하기 위해 함수를 사용하는게 옳을까?
		- GPT 리뷰
			- 함수 호출에도 오버헤드가 있으므로, 짧은 함수는 작성하지 않는게 맞다.
			  코딩테스트에서는 문제없음.
			- 초보단계 실수를 줄이고, 흐름 보기 쉽다는 점에서는 옳다.
*/

#include <iostream>
#include <algorithm>
#include <queue>

void CustomPush(std::queue<int>& q) {
	int input;
	std::cin >> input;
	q.push(input);
}

void CustomPop(std::queue<int>& q) {
	if (q.empty()) {
		std::cout << "-1\n";
	}
	else {
		std::cout << q.front() << "\n";
		q.pop();
	}
}

void CustomSize(std::queue<int>& q) {
	std::cout << q.size() << "\n";
}

void CustomEmpty(std::queue<int>& q) {
	if (q.empty()) {
		std::cout << "1\n";
	}
	else {
		std::cout << "0\n";
	}
}

void CustomFront(std::queue<int>& q) {
	if (q.empty()) {
		std::cout << "-1\n";
	}
	else {
		std::cout << q.front() << "\n";
	}
}

void CustomBack(std::queue<int>& q) {
	if (q.empty()) {
		std::cout << "-1\n";
	}
	else {
		std::cout << q.back() << "\n";
	}
}


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N; // Num of input commnads
	std::queue<int> q;

	{ // Input
		std::cin >> N;
	}

	std::string cmd = "";

	for (int i = 0; i < N; i++) {
		std::cin >> cmd;

		if (cmd == "push") CustomPush(q);
		if (cmd == "pop") CustomPop(q);
		if (cmd == "size") CustomSize(q);
		if (cmd == "empty") CustomEmpty(q);
		if (cmd == "front") CustomFront(q);
		if (cmd == "back") CustomBack(q);
	}


	// ---------[End]---------
	return 0;
}