#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<int> s;

	int count = 0;

	// ( 일 때는, stack에 넣기
	// ) 일 때는, 레이저인지 막대기인지 판단해서
	// 레이저일 경우 stack의 사이즈만큼 더해주기
	// 막대기일 경우 +1만 해주고 해당 막대기를 pop 해주기

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() + 1 == i) {	// 1 차이가 난다 = 인접한 문자
				s.pop();
				count += s.size();
			}
			else {
				s.pop();
				count++;
			}
		}
	}

	cout << count << '\n';

	return 0;
}
