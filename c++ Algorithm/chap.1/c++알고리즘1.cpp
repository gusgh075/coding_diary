#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int sumAlgorithmA(int n) {
	//bigO O(1)
	int a = 0;
	a = n * (n + 1) / 2;
	return a;
}
int sumAlgorithmB(int n) {
	//bigO O(n)
	int a = 0;
	for (int i = 0; i < n; i++) {
		a += i + 1;
	}
	return a;
}
int sumAlgorithmC(int n) {
	//bigO O(n!)
	int a = 0;
	for (int i = 0; i <= n; i++) {
		for (int b = 0; b < i; b++) {
			a++;
		}
	}
	return a;
}
int main() {
	int a = 100;
	clock_t start, finish;
	double duration;
	start = clock();
	sumAlgorithmA(a);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "첫번째 알고리즘 실행 시간 : " << duration << endl;

	start = clock();
	sumAlgorithmB(a);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "두번째 알고리즘 실행 시간 : " << duration << endl;

	start = clock();
	sumAlgorithmC(a);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "세번째 알고리즘 실행 시간 : " << duration << endl;

	// 1: 0초  2: 0초   3:7.808    -십만을 넣었을 때
	//3번째 알고리즘은 시간이 기하급수적으로 늘어난다

	// 1:0초   2:0.24초  -1억을 넣었을 때
	//2번째 알고리즘에 굉장히 큰 수를 대입하면 1번째 알고리즘에 비해 어느정도 실행시간이 증가한다.
}