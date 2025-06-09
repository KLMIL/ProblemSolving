/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 2512
	URL			: https://www.acmicpc.net/problem/2512
	Date		: 2025-06-09 08:53 ~ 2025-06-09 09:14
	Refactoring	:
	Review
		- 살짝 긴가민가한 부분이 있다. maxBudget에 +1을 해줬는데 답이 되는 부분 ...
		- 범위의 최소값과 최대값을 결정하는 데 조금의 애로사항이 있긴 했다. 헷갈렸음.
		- GPT 리뷰
			- 구조, 성능 모두 적절함
			- min/max 경계값 명확성, 자료형 일관성, 람다/함수 사용 목적성 점검
			- "왜 이렇게 했는지" 근거 남기면 완성도 올라감
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


	int N; // num of cities, 3 <= N <= 10,000. 
	std::vector<int> requires; // required budget for each city. 1 <= r[n] <= 100,000
	int M; // sum of budget. N <= M <= 1,000,000,000

	// TODO: Input을 Rambda로 감싸는 스타일 어떤가? 이건 일회용 함수야, 라는걸 알려주는 느낌.
	std::cin >> N;
		requires.resize(N, 0);
	for (int i = 0; i < N; i++) {
		std::cin >> requires[i];
	}
	std::cin >> M;


	long long minBudget = 1; // TODO: long long과 long과 int의 차이 찾아보기
	long long maxBudget = *std::max_element(requires.begin(), requires.end()) + 1; // TODO: min max 함수 찾아보기
	long long curBudget = (minBudget + maxBudget) / 2;

	auto IsBudgetRemain = [requires, N, M](int curBudget) -> bool {
		int curSum = 0;
		for (int i = 0; i < N; i++) {
			curSum += requires[i] >= curBudget ? curBudget : requires[i];
		}

		return M >= curSum;
		};

	while (minBudget + 1 < maxBudget) {
		if (IsBudgetRemain(curBudget)) {
			// calculate on upper range
			minBudget = curBudget;
			curBudget = (minBudget + maxBudget) / 2;
		}
		else {
			// calculate on downer range
			maxBudget = curBudget;
			curBudget = (minBudget + maxBudget) / 2;
		}
	}


	std::cout << minBudget << "\n";


	// ---------[End]---------
	return 0;
}