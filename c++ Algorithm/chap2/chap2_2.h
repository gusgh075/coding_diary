#pragma warning(disable:4996)
#include <cstdio>
#define MAX_TERMS 10
struct Term {	//�ϳ��� ���� ǥ���ϴ� Ŭ����
	int expon;	//���� ����
	float coeff;//���� ���
};
class SparasePoly {
	int nTerms = 0;	//����� 0�� �ƴ� ���� ����
	Term term[MAX_TERMS];

public:
	SparasePoly() { nTerms = 0; }
	void read() {
		printf("�Է��� ���� ������ : ");
		scanf("%d", &nTerms);
		if (nTerms > 10) {
			printf("10�� ������ ���� �Է��Ͻÿ�.");
			return;
		}
		for (int i = 0; i < nTerms; i++) {
			printf("%d��° ���� ����� ���� : ", i);
			scanf("%f %d", &term[i].coeff, &term[i].expon);
		}
	}
	void add(SparasePoly a, SparasePoly b) {
		SparasePoly c;
		*this = c;
		nTerms = 0;
		int i = 0, k = 0;//a�� b���� ���° �׸��� ������������ �ּ�
		while (i < a.nTerms || k < b.nTerms) {
			if (a.term[i].expon == b.term[k].expon) {//�������� �׸���� ������ ���� ��
				term[nTerms].coeff = a.term[i].coeff + b.term[k].coeff;
				term[nTerms].expon = a.term[i].expon;
				i++; k++; nTerms++;
			}
			else if (a.term[i].expon > b.term[k].expon)//������ a���� �� Ŭ ��
			{
				term[nTerms].coeff = a.term[i].coeff;
				term[nTerms].expon = a.term[i].expon;
				i++; nTerms++;
			}
			else										//������ b���� �� Ŭ ��
			{
				term[nTerms].coeff = b.term[k].coeff;
				term[nTerms].expon = b.term[k].expon;
				k++; nTerms++;
			}
			while (i == a.nTerms && k < b.nTerms) {		//�ּ��� a�� ������ ���� ��
				term[nTerms].coeff = b.term[k].coeff;
				term[nTerms].expon = b.term[k].expon;
				k++; nTerms++;
			}
			while (k == b.nTerms && i < a.nTerms) {		//�ּ��� b�� ������ ���� ��
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