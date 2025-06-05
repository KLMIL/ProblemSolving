/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 1026
	URL			: https://www.acmicpc.net/problem/1026
	Date		: 2025-06-05 09:34 ~ 2025-06-05 09:44
	Refactoring	:
	Review
		- 간단~
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
	std::vector<int> A;
	std::vector<int> B;

	std::cin >> N;
	A.resize(N, 0);
	B.resize(N, 0);

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}


	// 단순하게, 가장 큰 수에 가장 작은 수를 곱하면 가장 작은 값이 되지 않나?
	// 증명은 안해봤지만, 그런거 같으니 트라이.
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end(), [](int a, int b) { return a > b; });

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}


	std::cout << sum;


	// ---------[End]---------
	return 0;
}