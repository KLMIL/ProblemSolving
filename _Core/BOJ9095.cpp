/*
    Site		: BaekJoon Online Judge - https://www.acmicpc.net/
    Problem		: BOJ 9095
    URL			: https://www.acmicpc.net/problem/9095
    Date		: 2025-07-02 8:53 ~ 2025-07-02 09:52(TD) ~ 2025-07-02 09:55(BU)
    Refactoring	:
    Review
        - 점화식 만드는게 굉장히 어렵네.
*/

#include <iostream>
#include <algorithm>
#include <vector>


int TD_solution(int n) {
    std::vector<int> memo(n + 1, -1);
    memo[1] = 1; memo[2] = 2; memo[3] = 4;

    auto f = [&memo](auto&& self, int n) -> void {
        if (n == 1 || n == 2 || n == 3) return;

        if (memo[n - 1] == -1) self(self, n - 1);
        if (memo[n - 2] == -1) self(self, n - 2);
        if (memo[n - 3] == -1) self(self, n - 3);

        memo[n] = memo[n - 1] + memo[n - 2] + memo[n - 3];
        };
    f(f, n);

    return memo[n];
}

int BU_solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    int preprev = 1;
    int pre = 2;
    int curr = 4;

    for (int i = 4; i <= n; i++) {
        int next = preprev + pre + curr;
        preprev = pre;
        pre = curr;
        curr = next;
    }

    return curr;
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
        int n; // input integer. 1 <= n < 11
        std::cin >> n;

        bool DpType = false;
        if (DpType) { // TD solution
            std::cout << TD_solution(n) << "\n";
        }
        else { // BU solution
            std::cout << BU_solution(n) << "\n";
        }
    }


    // ---------[End]---------
    return 0;
}
