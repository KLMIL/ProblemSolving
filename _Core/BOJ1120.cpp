/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 1120
	URL			: https://www.acmicpc.net/problem/1120
	Date		: 2025-06-04 08:47 ~ 2025-06-04 09:08
	Refactoring	:
	Review
		- 오랜만에 풀려니까 진짜 안풀림 ...
		- 그래도 고무적인 점 = 문법은 얼추 다 기억한다.
*/

#include <iostream>
#include <algorithm>
#include <string>


int FindMinDiff(std::string str1, std::string str2, int startIdx) {
	int diffCnt = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i + startIdx]) {
			diffCnt++;
		}
	}
	return diffCnt;
}


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;


	int gap = str2.size() - str1.size();
	int minDiff = str1.size();
	for (int i = 0; i <= gap; i++) {
		minDiff = std::min(minDiff, FindMinDiff(str1, str2, i));
	}


	std::cout << minDiff;


	// ---------[End]---------
	return 0;
}