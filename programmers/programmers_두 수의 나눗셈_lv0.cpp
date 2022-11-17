#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    answer=(float)num1/num2*1000;
    return answer;
}
//실수형 자료가 정수형 자료에 들어갈 때 실수의 소수부분은 자동으로 사라지는 것을 배웠다.
