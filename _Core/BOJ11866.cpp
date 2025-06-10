/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 11866
	URL			: https://www.acmicpc.net/problem/11866
	Date		: 2025-06-11 08:44 ~ 2025-06-11 08:54
	Refactoring	:
	Review
		- 적절한 자료구조 생각하는데 시간 씀 ... queue 파트에서 들어갔으면서 deque 쓰려했네.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int N;
	int K;
	std::queue<int> q;

	{ // Input
		std::cin >> N >> K;
	}

	// TODO: 범위는 항상 이상 ~ 미만으로 하는게 낫지 않을까? 실수 방지
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	// TODO: deque에서는 begin()에 ++만 하면 자동으로 계속 도나? 컨테이너 정보
	// 생각해보니, queue에서 pop하고 push하면 될 일이구나. 중간에서 꺼내려고 deque로 잘못생각함.

	std::vector<int> result;
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		result.push_back(q.front());
		q.pop();
	}


	std::cout << "<" << result[0];
	for (size_t i = 1; i < result.size(); i++) {
		std::cout << ", " << result[i];
	}
	std::cout << ">\n";


	// ---------[End]---------
	return 0;
}