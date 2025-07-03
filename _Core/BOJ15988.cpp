/*
    Site		: BaekJoon Online Judge - https://www.acmicpc.net/
    Problem		: BOJ 15988
    URL			: https://www.acmicpc.net/problem/15988
    Date		: 2025-07-03 09:24 ~ 2025-07-03 09:43(BU)
    Refactoring	:
    Review
        - Top-Down으로 구현하니 n=3000은 가능하지만, n=4000은 오류
            - 원인은 스택 크기 문제.
        - 예외처리 문제로 다시 제출했음.
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000009


int TDsolution(int n) {
    std::vector<int> memo(n + 1, -1);
    memo[0] = 0; memo[1] = 1; memo[2] = 2; memo[3] = 4;

    auto rec = [&memo](auto&& self, int n) -> void {
        if (n <= 3) return;

        if (memo[n - 1] == -1) self(self, n - 1);
        if (memo[n - 2] == -1) self(self, n - 2);
        if (memo[n - 3] == -1) self(self, n - 3);

        long long res = 0;
        res += memo[n - 1];
        res += memo[n - 2];
        res += memo[n - 3];
        res %= MOD;

        memo[n] = (int)res;
        };
    rec(rec, n);

    return memo[n];
}

int BUsolution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    std::vector<long long> table(n + 1, -1);
    table[0] = 0; table[1] = 1; table[2] = 2; table[3] = 4;

    for (int i = 4; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2] + table[i - 3];
        table[i] %= MOD;
    }

    return table[n];
}


int main(void)
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // --------[Start]--------


    int T; // num of testcases
    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int n; // input integer. 1 <= n <= 10e6
        std::cin >> n;

        bool dpType = false;
        if (dpType) {
            std::cout << TDsolution(n) << "\n"; // 스택 크기 문제로 실패
        }
        else {
            std::cout << BUsolution(n) << "\n";
        }
    }


    // ---------[End]---------
    return 0;
}
