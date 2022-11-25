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
	cout << "ù��° �˰��� ���� �ð� : " << duration << endl;

	start = clock();
	sumAlgorithmB(a);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "�ι�° �˰��� ���� �ð� : " << duration << endl;

	start = clock();
	sumAlgorithmC(a);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "����° �˰��� ���� �ð� : " << duration << endl;

	// 1: 0��  2: 0��   3:7.808    -�ʸ��� �־��� ��
	//3��° �˰����� �ð��� ���ϱ޼������� �þ��

	// 1:0��   2:0.24��  -1���� �־��� ��
	//2��° �˰��� ������ ū ���� �����ϸ� 1��° �˰��� ���� ������� ����ð��� �����Ѵ�.
}