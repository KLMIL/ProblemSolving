/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 1541
	URL			: https://www.acmicpc.net/problem/1541
	Date		: 2025-06-19 09:01 ~ 2025-06-19 09:40
	Refactoring	:
	Review
		- +가 여러번 이어지는 케이스를 고려 안했었다.
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


	std::string inputStr;
	std::cin >> inputStr;

	//{ // [DEBUG]
	//	std::cout << "Input Str Check\n";
	//	std::cout << inputStr << "\n";
	//}


	// TODO: 입력값을 가공하는 작업. string을 받아서 숫자랑 문자로 분리? or 그냥 바로 사용하기?
	std::vector<int> inputNum;
	std::vector<char> inputOp;

	int currNum = 0;
	for (size_t i = 0; i < inputStr.size(); i++) {
		//{ // [DEBUG]
		//	std::cout << "Curr Char: " << inputStr[i] << "\n";
		//}

		if (inputStr[i] == '+' || inputStr[i] == '-') {
			inputOp.push_back(inputStr[i]);
			inputNum.push_back(currNum);
			currNum = 0;
		}
		else {
			currNum *= 10;
			currNum += (inputStr[i] - '0');
		}
	}
	inputNum.push_back(currNum);

	//{ // [DEBUG]
	//	std::cout << "Input Check\n";
	//	for (size_t i = 0; i < inputNum.size(); i++) {
	//		std::cout << inputNum[i] << " ";
	//	}
	//	std::cout << "\n";
	//	for (size_t i = 0; i < inputOp.size(); i++) {
	//		std::cout << inputOp[i] << " ";
	//	}
	//	std::cout << "\n";
	//}

	int currSum = inputNum[0];
	int currMinus = 0;

	// 잘못 생각했다... 최대값이 아니라 최소값 만들기였다. 
	for (size_t i = 0; i < inputOp.size(); i++) {
		// 더하기면 그냥 더하는게 좋고. 빼기면, 뒤에 더하기가 있다면 계속 묶는게 좋다. 
		if (inputOp[i] == '+') {
			currSum += inputNum[i + 1];
		}
		if (inputOp[i] == '-') {
			currMinus += inputNum[i + 1];
			while (i < inputOp.size() - 1 && inputOp[i + 1] == '+') { // 뒤에 연산자가 있다면
				currMinus += inputNum[i + 2];
				i++;
			}
		}
	}

	std::cout << currSum - currMinus << "\n";



	// ---------[End]---------
	return 0;
}