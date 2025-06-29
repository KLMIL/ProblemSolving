/*
    Site		: LeetCode - https://leetcode.com/problemset/
    Problem		: 1498. Number of Subsequences That Satisfy the Given Sum Condition
    Date		: 2025-06-29 19:14 ~ 2025-06-29 20:20
    Refactoring	:
    Review
        - 최적화 실패가 마지막 케이스 실패 원인이었다.
*/

#include <iostream>
#include <algorithm>
#include <vector>


// --------[Start]--------

class Solution {
private:
    const int MOD = 1e9 + 7;

    int ModPow(int base, int expo, int mod) {
        if (expo == 0) return 1;
        if (expo == 1) return base;

        long long llResult = 1;
        long long llBase = base;
        long long llexpo = expo;

        while (llexpo > 1) {
            if (llexpo % 2 == 1) {
                llexpo--;
                llResult *= llBase;
                llResult %= mod;
            }
            else {
                llexpo /= 2;
                llBase *= llBase;
                llBase %= mod;
            }
        }

        return (llResult * llBase) % mod;
    }

public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int start = 0; start < nums.size(); start++) {
            if (nums[start] + nums[start] > target) {
                break;
            }

            //int end = start;
            //while (end < nums.size() && nums[start] + nums[end] <= target) {
            //    end++;
            //}
            //end--; // 마지막 값은 넘은 순간이므로, 하나 빼줘야함.
            // 이진 탐색으로 end 구하기
            int l = start, r = nums.size() - 1, end = start - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[start] + nums[mid] <= target) {
                    end = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }

            //std::cout << "ModPow res: " << ModPow(2, end - start, MOD) << "\n";

            int expo = end - start;
            if (expo >= 0) {
                cnt += ModPow(2, expo, MOD);
                cnt %= MOD;
            }
        }

        return cnt;
    }
};

// ---------[End]---------


int main(void)
{
    Solution s;

    // Run test cases for the implemented solution
    std::vector<int> v = { 2, 4, 6 };
    std::cout << s.numSubseq(v, 2);

    return 0;
}

/*
* 최소, 최대값을 더해서 목표값 이하인 부분수열의 개수를 구하는 문제.
* 수를 정렬한 뒤에, 최소-최대값을 더해서 목표값 이하인 지점을 구하고,
* 각 수를 사용한다 vs 사용하지 않는다로 개수를 세야할 것 같은데 ...
* 일단 최소, 최대 index를 구한 뒤에, 최소 index는 무조건 들어가는 상태에서
* 다른 index를 사용할지 말지에 대해서 각 2가지 경우라고 생각하자.
*
* 그럼, 하나는 빼놓고(최소한 1개),
* 2개면 쓴다 안쓴다 -> 2가지
* 3개면 OO OX XO OO -> 4가지
* 4개면 OOO OOX OXO XOO OXX XOX XXO XXX -> 8가지
* 즉, 2^(n - 1)개. n = 1일 때, 0개까지 맞네.
*
* 여기서 문제는, pow 중에 값을 넘을수도 있다는 점.
* input이 10^5이기 떄문에, 2^100000 니까.
* 그렇다면, 적당한 값이 될 수 있도록 중간중간 Mod 해가면서 계산해야 한다.
*
* 중복 수열은 빼야한다. 어떻게 중복을 검증하지?
*/
