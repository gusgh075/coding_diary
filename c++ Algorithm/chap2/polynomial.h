#pragma warning(disable:4996)
#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
	int degree;
	float coef[MAX_DEGREE];
public:
	Polynomial() { degree = 0; }

	void read() {
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}

	void display(const char* str = " Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++) {
			if (coef[i] != 0)
				printf("%5.1f x^%d ", coef[i], degree - i);
			if (coef[i + 1] != 0)
				printf("+ ");
		}
		if (coef[degree] != 0)
			printf("%4.1f\n", coef[degree]);
	}

	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i < b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
	bool isZero() { return degree == 0; }
	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}
	void sub(Polynomial a, Polynomial b) {
		//a의 차수가 더 클 때
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] -= b.coef[i];
			//i+ (degree-b.dgree)가 의미하는 바는 a와 b의 차수 차이를 메꾸는 것
		}
		//b의 차수가 더 클 때
		else {
			*this = a;
			for (int i = 0; i <= degree; i++) {
				coef[i] -= b.coef[i + (b.degree - degree)];
			}
		}
	}
	void mult(Polynomial a, Polynomial b) {
		Polynomial c;
		*this = c;
		degree = a.degree + b.degree;
		for (int i = 0; i <= degree; i++)
			coef[i] = 0;
		for (int i = 0; i <= a.degree; i++)
			for (int k = 0; k <= b.degree; k++)
				coef[degree - (i + k)] = coef[degree - (i + k)] + a.coef[a.degree - i] * b.coef[b.degree - k];
		//가장 낮은 차수부터 곱하기 시작, a의 상수 곱하기 b의 모든 차수-> a의 차수 1부터 이런식으로 계속
	}
	void trim() {
		int a = 0;
		for (int i = 0; i <= degree; i++) {
			if (coef[i] == 0)
				a++;
			else
				break;
		}
		degree -= a;
		for (int i = 0; i <= degree; i++) {
			coef[i] = coef[a + i];
		}

	}
};
