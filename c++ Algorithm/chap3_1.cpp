//"}}}}}}}}}"
#include"ArrayStack.h"
#include <iostream>
#pragma warning(disable:4996)
//�־��� ������ �о� ��ȣ ��Ī�� �˻縦 �ϰ� ����� ����ϴ� �Լ�
bool checkMatching(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: ���� �������� �ʽ��ϴ�.\n");
	//�÷��׺���?
	int nLine = 1;	//���� ������ ����
	int nChar = 0;	//���� ���� ����
	ArrayStack stack;
	char ch;
	int a = 0;
	while ((ch = getc(fp)) != EOF) {	//EOF=End Of File, -1�̰�, ������ �������� �ǹ��Ѵ�.
		if (ch == '\n')nLine++;
		nChar++;
		//��������ǥ ó���ڵ�
		if (ch == '\'') {
			while (true) {
				ch = getc(fp);
				nChar++;
				if (ch == '\\') {
					ch = getc(fp);
					nChar++;
				}
				else if (ch == '\'') {
					break;
				}
			}
		}
		//ū����ǥ ó���ڵ�
		else if (ch == '\"') {
			while (true) {
				ch=getc(fp);			//������ ��� ������ ��ġ�� �� �����غ���.
				nChar++;
				if (ch == '\\') {
					ch=getc(fp);
					nChar++;
				}
				else if (ch == '\"')
					break;
			}
		}
		//�ּ� ó���ڵ�
		else if (ch == '/') {
			ch = getc(fp);
			nChar++;
			if (ch == '/')
				while (true) {
					ch = getc(fp);
					nChar++;
					if (ch == '\n')nLine++;

					if (ch == '\n') {
						break;
					}
				}
			else if(ch=='*')
				while (true) {
					ch = getc(fp);
					nChar++;
					if (ch == '\n')nLine++;

					if (ch == '*') {
						ch=getc(fp);
						nChar++;
						if (ch == '\n')nLine++;

						if (ch == '/') {
							break;
						}
					}
				}

		}
		if (ch == '[' || ch == '(' || ch == '{')
			stack.push(ch);			//push �� ���� �׸� ����
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.pop();	//pop �� ���� �׸��� ��ȯ�ϰ� ����, peek�� ��ȯ�ϵ� �������� �ʴ´�.
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				break;
			}
			//break�� �ݺ����� Ż���� �� ���ȴ�.
		//���⼭ break�Ǹ� stack���� ���ڰ� �����ְԵǹǷ� ��ȣ �˻翡�� �����Ѵ�.
		}


	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("Error: �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf(" OK: ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

int main()
{
	checkMatching("ArrayStack.h");
	checkMatching("chap3_1.cpp");
}