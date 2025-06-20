/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 1158
	URL			: https://www.acmicpc.net/problem/1158
	Date		: 2025-06-20 10:02 ~ 2025-06-20 10:07
	Refactoring	:
	Review
		-
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


	// 그냥 큐 문젠데? 
	int N; // Num of people
	int K; // Remove index for each turn

	{ // Input
		std::cin >> N >> K;
	}

	std::queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}


	// TODO: 출력할 때 양식 문제때문에, 이걸 어떻게든 짜맞출지, 그냥 저장하고 한번에 출력할지 고민.
	std::vector<int> result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		result.push_back(q.front());
		q.pop();
	}


	std::cout << "<";
	std::cout << result[0];
	for (size_t i = 1; i < result.size(); i++) {
		std::cout << ", " << result[i];
	}
	std::cout << ">\n";


	// ---------[End]---------
	return 0;
}