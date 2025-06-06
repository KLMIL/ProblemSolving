/*
	Site		: BaekJoon Online Judge - https://www.acmicpc.net/
	Problem		: BOJ 17952
	URL			: https://www.acmicpc.net/problem/17952
	Date		: 2025-06-06 08:29 ~ 2025-06-06 08:55
	Refactoring	:
	Review
		- 자료구조 사용이 미숙했다.
		- 비효율적인 부분도 있는데, 코딩테스트니까 일단 넘어가긴 함.
			- 어차피 O(n^2) 정도? 라는데 변화는 없기 때문.
		- GPT 리뷰
			- currentTime을 저장하는건 불필요.
			  requireTime을 remainTime으로 명명하는게 더 간단함.
			- Task 구조체를 이용하는 방식은 공간적으로도, 직관성으로도 비효율.
			  시간 단위로 즉시 입력받아서 처리하는 방식이 적절함.
			- 스택 사용 시 조건 분기에 중복 있음.
			  구조 변경 필요.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


typedef struct Task {
	bool isExist;
	int score;
	int requireTime;
	int currentTime = 0;
};


int main(void)
{
	// Fast I/O
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// --------[Start]--------


	int semester;
	std::cin >> semester;

	std::vector<Task> task(semester);
	for (int i = 0; i < semester; i++) {
		std::cin >> task[i].isExist;
		if (task[i].isExist) {
			std::cin >> task[i].score >> task[i].requireTime;
		}
	}


	int scoreSum = 0;
	std::stack<Task> st;
	Task currTask = { 0, 0, 0, 0 };

	for (int i = 0; i < semester; i++) {
		if (currTask.isExist == 1) { // 작업중이던 과제가 있다면 push
			st.push(currTask);
		}

		currTask = task[i];
		if (currTask.isExist == 1) {
			currTask.currentTime++;

			if (currTask.currentTime == currTask.requireTime) {
				scoreSum += currTask.score;
				currTask = { 0, 0, 0, 0 };
			}
		}
		else {
			if (!st.empty()) {
				currTask = st.top();
				st.pop();

				currTask.currentTime++;

				if (currTask.currentTime == currTask.requireTime) {
					scoreSum += currTask.score;
					currTask = { 0, 0, 0, 0 };
				}
			}
		}
	}

	std::cout << scoreSum << "\n";


	// ---------[End]---------
	return 0;
}