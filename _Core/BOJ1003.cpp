/*
    Site		: BaekJoon Online Judge - https://www.acmicpc.net/
    Problem		: BOJ 1003
    URL			: https://www.acmicpc.net/problem/1003
    Date		: 2025-06-30 09:17 ~ 09:37(TD) ~ 09:48(BU)
    Refactoring	:
    Review
        - TD는 시간초과가 나왔다.
        - BU는 통과.
        - TD 살짝 개선해도 시간초과네 .. 흠 ...
*/

#include <iostream>
#include <algorithm>
#include <vector>


int FibonacciBU(int N, std::vector<int>& cntBU) {
    if (N == 0) {
        cntBU[0] = 1;
        cntBU[1] = 0;
        return 0;
    }

    std::vector<int> preprev = { 0, 0, 0 };
    std::vector<int> prev = { 0, 1, 0 };
    std::vector<int> curr = { 1, 0, 1 };

    for (int i = 1; i < N; i++) {
        preprev[0] = prev[0];
        preprev[1] = prev[1];
        preprev[2] = prev[2];

        prev[0] = curr[0];
        prev[1] = curr[1];
        prev[2] = curr[2];

        curr[0] = preprev[0] + prev[0];
        curr[1] = preprev[1] + prev[1];
        curr[2] = preprev[2] + prev[2];
    }
    cntBU[0] = curr[1];
    cntBU[1] = curr[2];

    return curr[0];
}


int FibonacciTD(std::vector<int>& fibo, int N, std::vector<int>& cntTD) {
    if (N == 0) {
        cntTD[0]++;
        return 0;
    }
    if (N == 1) {
        cntTD[1]++;
        return 1;
    }

    if (fibo[N - 2] == 0) FibonacciTD(fibo, N - 2, cntTD);
    if (fibo[N - 1] == 0) FibonacciTD(fibo, N - 1, cntTD);

    fibo[N] = fibo[N - 2] + fibo[N - 1];
    return fibo[N - 2] + fibo[N - 1];
}


int main(void)
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // --------[Start]--------


    int T;
    std::cin >> T;

    bool type = false; // BottomUp, TopDown을 결정하는 변수
    for (int tc = 0; tc < T; tc++) {
        int N;
        std::cin >> N;

        if (type) { // Button-Up Solution
            std::vector<int> cntBU(2, 0);
            FibonacciBU(N, cntBU);

            std::cout << cntBU[0] << " " << cntBU[1] << "\n";
        }
        else { // Top-Down Solution
            std::vector<int> fiboTD(N + 1, 0); // 1-based
            std::vector<int> cntTD(2, 0);
            FibonacciTD(fiboTD, N, cntTD);

            std::cout << cntTD[0] << " " << cntTD[1] << "\n";
        }
    }



    // ---------[End]---------
    return 0;
}
