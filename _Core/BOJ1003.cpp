/*
    Site		: BaekJoon Online Judge - https://www.acmicpc.net/
    Problem		: BOJ 1003
    URL			: https://www.acmicpc.net/problem/1003
    Date		: 2025-06-30 09:17 ~ 09:37(TD) ~ 09:48(BU)
    Refactoring	: 2025-07-01 10:21(BU) ~ 10:21(TD)
    Review
        - TD는 시간초과가 나왔다.
        - BU는 통과.
        - TD 살짝 개선해도 시간초과네 .. 흠 ...
*/

#include <iostream>
#include <algorithm>
#include <vector>



// BU는 작은 문제부터 차례로 해결해나가는 방법
std::vector<int> BU_Fibonacci(int N) {
    // 예외 입력에 대한 처리
    if (N == 0) return { 1, 0 };
    if (N == 1) return { 0, 1 };

    std::vector<int> prev = { 1, 0 };
    std::vector<int> curr = { 0, 1 };

    for (int i = 2; i <= N; i++) {
        std::vector<int> next = { prev[0] + curr[0], prev[1] + curr[1] };
        prev = curr;
        curr = next;
    }

    return curr;
}


std::vector<int> TD_Fibonacci(int N) {
    if (N == 0) return { 1, 0 };
    if (N == 1) return { 0, 1 };

    std::vector<std::vector<int>> memo(N + 1, std::vector<int>(3)); // { Found, 0, 1 }
    memo[0] = { 1, 1, 0 };
    memo[1] = { 1, 0, 1 };

    auto rec = [&memo](auto&& self, int curr) -> std::vector<int> {
        if (memo[curr][0] != 0) return memo[curr];

        std::vector<int> p1 = self(self, curr - 1);
        std::vector<int> p2 = self(self, curr - 2);

        memo[curr] = { 1, p1[1] + p2[1], p1[2] + p2[2] };
        return memo[curr];
        };

    std::vector<int> result = rec(rec, N);

    return { result[1], result[2] };
}


int main(void)
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // --------[Start]--------


    int T;
    std::cin >> T;

    bool type = false; // true = BU / false = TD
    for (int tc = 0; tc < T; tc++) {
        int N;
        std::cin >> N;

        if (type) { // Button-Up Solution
            std::vector<int> resBU = BU_Fibonacci(N);
            std::cout << resBU[0] << " " << resBU[1] << "\n";
        }
        else { // Top-Down Solution
            std::vector<int> resTD = TD_Fibonacci(N);
            std::cout << resTD[0] << " " << resTD[1] << "\n";
        }
    }



    // ---------[End]---------
    return 0;
}

/* Think
* - 확장성 있는 함수 구조를 위해서, 기본 Fibonacci를 구현한 뒤에, 필요한 부분을 추가하는 식으로 만들어보자.
*/
