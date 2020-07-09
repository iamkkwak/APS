#include <iostream>
#include <string>
#include <stack>
using namespace std;

int len;
string str;

bool is_open(char c) {
	if (c == '(' || c == '{' || c == '[' || c == '<')
		return true;
	else
		return false;
}

int answer() {
	stack<char> myStack;
	cin >> str;
	int ret = 1;
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (is_open(c)) {
			myStack.push(c);
		}
		else {
			char s;
			switch (c) {
			case ')': s = '('; break;
			case '}': s = '{'; break;
			case ']': s = '['; break;
			case '>': s = '<'; break;
			default: break;
			}
			if (myStack.top() == s)
				myStack.pop();
			else
				return 0;
		}
	}
	if (!myStack.empty())
		return 0;
	return 1;
}

int main() {
	int T = 10;
	while (T--) {
		cin >> len;
		cout << "#" << 10 - T << " " << answer() << endl;
	}
	return 0;
}
