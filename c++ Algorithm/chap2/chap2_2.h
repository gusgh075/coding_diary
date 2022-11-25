#pragma warning(disable:4996)
#include <cstdio>
#define MAX_TERMS 10
struct Term {	//하나의 항을 표현하는 클래스
	int expon;	//항의 지수
	float coeff;//항의 계수
};
class SparasePoly {
	int nTerms = 0;	//계수가 0이 아닌 항의 개수
	Term term[MAX_TERMS];

public:
	SparasePoly() { nTerms = 0; }
	void read() {
		printf("입력할 항의 개수는 : ");
		scanf("%d", &nTerms);
		if (nTerms > 10) {
			printf("10개 이하의 항을 입력하시오.");
			return;
		}
		for (int i = 0; i < nTerms; i++) {
			printf("%d번째 항의 계수와 지수 : ", i);
			scanf("%f %d", &term[i].coeff, &term[i].expon);
		}
	}
	void add(SparasePoly a, SparasePoly b) {
		SparasePoly c;
		*this = c;
		nTerms = 0;
		int i = 0, k = 0;//a와 b에서 몇번째 항목을 조사중인지의 주석
		while (i < a.nTerms || k < b.nTerms) {
			if (a.term[i].expon == b.term[k].expon) {//조사중인 항목들의 지수가 같을 때
				term[nTerms].coeff = a.term[i].coeff + b.term[k].coeff;
				term[nTerms].expon = a.term[i].expon;
				i++; k++; nTerms++;
			}
			else if (a.term[i].expon > b.term[k].expon)//지수가 a쪽이 더 클 때
			{
				term[nTerms].coeff = a.term[i].coeff;
				term[nTerms].expon = a.term[i].expon;
				i++; nTerms++;
			}
			else										//지수가 b쪽이 더 클 때
			{
				term[nTerms].coeff = b.term[k].coeff;
				term[nTerms].expon = b.term[k].expon;
				k++; nTerms++;
			}
			while (i == a.nTerms && k < b.nTerms) {		//주석이 a가 끝까지 갔을 때
				term[nTerms].coeff = b.term[k].coeff;
				term[nTerms].expon = b.term[k].expon;
				k++; nTerms++;
			}
			while (k == b.nTerms && i < a.nTerms) {		//주석이 b가 끝까지 갔을 때
				term[nTerms].coeff = a.term[i].coeff;
				term[nTerms].expon = a.term[i].expon;
				i++; nTerms++;
			}

		}
		
	}
	void display(const char* str = " sPoly = ") {
		printf("\t%s", str);
		for (int i = 0; i < nTerms - 1; i++) {
			printf("%5.1fx^%d + ", term[i].coeff, term[i].expon);
		}
		if (term[nTerms - 1].expon == 0)
			printf("%5.1f", term[nTerms - 1].coeff);
		else
			printf("%5.1fx^%d", term[nTerms - 1].coeff, term[nTerms - 1].expon);
	}

};