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

	// ������ �߰��ؼ� 1�̶� �� ���� ��� �̵��̴ϱ�,
	// ������ �ڿ� ������ �������� ū ���� ã���� �ǰڴµ�?

	std::sort(lope.begin(), lope.end());
	int max = 0;
	for (int i = 0; i < N; i++) {
		max = std::max(max, lope[i] * (N - i));
	}

	std::cout << max;


	// ---------[End]---------
	return 0;
}
