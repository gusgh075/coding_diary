#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<string> babbling) {
	int answer = 0;
	vector<string> can_pron = { "aya", "ye", "woo", "ma" };
	for (int a = 0; a < babbling.size(); a++) {
		int len = 0;
		for (int b = 0; b < 4; b++) {
			if (babbling[a].find(can_pron[b]) != string::npos) {
				babbling[a].replace(babbling[a].find(can_pron[b]), can_pron[b].size(), " ");
			}
		}

		while (babbling[a].find(' ') != string::npos) {
			babbling[a].erase(babbling[a].find(' '), 1);
		}
		if (babbling[a].size() == 0)
			answer++;
	}
	return answer;
}
int main() {
	cout << solution({ "aya", "yee", "u", "maa", "wyeoo" });
	return 0;
}
