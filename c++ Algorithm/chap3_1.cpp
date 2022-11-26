//"}}}}}}}}}"
#include"ArrayStack.h"
#include <iostream>
#pragma warning(disable:4996)
//주어진 파일을 읽어 괄호 매칭을 검사를 하고 결과를 출력하는 함수
bool checkMatching(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: 파일 존재하지 않습니다.\n");
	//플래그변수?
	int nLine = 1;	//읽은 라인의 개수
	int nChar = 0;	//읽은 문자 개수
	ArrayStack stack;
	char ch;
	int a = 0;
	while ((ch = getc(fp)) != EOF) {	//EOF=End Of File, -1이고, 파일의 마지막을 의미한다.
		if (ch == '\n')nLine++;
		nChar++;
		//작은따옴표 처리코드
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
		//큰따옴표 처리코드
		else if (ch == '\"') {
			while (true) {
				ch=getc(fp);			//변수가 어디에 영향을 끼치는 지 생각해보자.
				nChar++;
				if (ch == '\\') {
					ch=getc(fp);
					nChar++;
				}
				else if (ch == '\"')
					break;
			}
		}
		//주석 처리코드
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
			stack.push(ch);			//push 맨 위에 항목 삽입
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.pop();	//pop 맨 위의 항목을 반환하고 삭제, peek은 반환하되 삭제하지 않는다.
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				break;
			}
			//break은 반복문을 탈출할 때 사용된다.
		//여기서 break되면 stack에는 문자가 남아있게되므로 괄호 검사에서 실패한다.
		}


	}
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("Error: 문제발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf(" OK: 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

int main()
{
	checkMatching("ArrayStack.h");
	checkMatching("chap3_1.cpp");
}