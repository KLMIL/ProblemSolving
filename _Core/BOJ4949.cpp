/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 4949
	URL			: https://www.acmicpc.net/problem/4949
	Date		: 2025-06-10 08:57 ~ 2025-06-10 09:44
	Refactoring	:
	Review
		- 문자 입력, 문자 버퍼, 이런게 엄청 난해하네. 쉬운 문젠데 풀기가 어려웠다.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>


// TODO: enum과 enum class 차이
enum BracketType {
	Small = 0, // () 
	Middle = 1, // {}
	Large = 2 // []
};

int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	std::string inputStr;
	// TODO: <string>은 어디에 속해있는거지? iostream에 포함인가? io 헤더도 체크.

	while (true) {
		// TODO: 갑자기 떠오른건데, string builder에 대해 알아보기. C#.
		inputStr.clear();
		char inputChar = ' ';
		bool isCorrect = true;
		std::stack<BracketType> st;

		// TODO: 입력 버퍼에 대한 부분 체크 필요
		std::cin.ignore();
		while (inputChar != '.') {
			// TODO: 공백문자로 받는 std::cin >> char, string에서 특정 문자를 기준으로 입력받기
			std::cin.get(inputChar);
			inputStr.push_back(inputChar);

			// TODO: enum으로 바로 넣으려고 하니까 안되네?
			// .이 아니라 :: 로 넣어야한다. enum과 enum class가 다른건가?
			if (inputChar == '(') {
				st.push(BracketType::Small);
			}
			else if (inputChar == ')') {
				if (!st.empty() && st.top() == BracketType::Small) {
					st.pop();
				}
				else {
					isCorrect = false;
				}
			}
			else if (inputChar == '[') {
				st.push(BracketType::Large);
			}
			else if (inputChar == ']') {
				if (!st.empty() && st.top() == BracketType::Large) {
					st.pop();
				}
				else {
					isCorrect = false;
				}
			}
		}

		//std::cout << "|" << inputStr << "|\n";

		if ((inputStr.length() == 1 && inputStr[0] == '.')) {
			break;
		}
		else {
			(isCorrect == true && st.empty()) ? std::cout << "yes\n" : std::cout << "no\n";
		}
	}
	// TODO: C++의 string에 대해서. ''와 "" 차이 확인.


	// ---------[End]---------
	return 0;
}