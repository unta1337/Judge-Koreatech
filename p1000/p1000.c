// 1000: a+b
/*
 * 숫자 두 개가 표준 입력으로 주어질 때, 두 수의 합을 출력하는 프로그램을 만들어 주세요.
*/
// https://judge.koreatech.ac.kr/problem.php?id=1000

// 메모리 사용량: 1200 KB
// 실행 시간: 11 ms
// 코드 용량: 328 bytes

#include <stdio.h>

int main(void)
{
    int i, j;
    scanf("%d %d", &i, &j);

    printf("%d\n", i + j);

    return 0;
}