// 1002: 너의 학번을 알려주마
/*
 * 한기대의 학번은 총 10자리로, {학번}{학부/과 구분}{일련번호} 로 이루어져 있습니다. 예를 들여 2014136900 이면 14학번, 컴퓨터공학부, 가나다 순으로 900번째 학생임을 뜻 합니다.
 * 학번이 입력으로 주어졌을 때, 몇 학번 인지를 출력하는 프로그램을 만들어 주세요.
*/
// https://judge.koreatech.ac.kr/problem.php?id=1002

// 메모리 사용량: 1216 KB
// 실행 시간: 2 ms
// 코드 용량: 1822 bytes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentID
{
    char ID[11];

    char year[5];
    char year2[3];
    char major[4];
    char serial[4];
};
typedef struct StudentID* StudentID;

StudentID createStudentID(char ID[]);
void deleteStudentID(StudentID this);

int main(void)
{
    int n;
    scanf("%d", &n);

    StudentID *sIDs = (StudentID*)malloc(n * sizeof(StudentID));
    for (int i = 0; i < n; i++)
    {
        char sID[11] = "";
        scanf("%s", sID);

        sIDs[i] = createStudentID(sID);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sIDs[i]->year2);
    }

    for (int i = 0; i < n; i++)
    {
        deleteStudentID(sIDs[i]);
    }
    free(sIDs);

    return 0;
}

StudentID createStudentID(char ID[])
{
    StudentID this = (StudentID)malloc(sizeof(struct StudentID));

    strcpy(this->ID, ID);

    strncpy(this->year, &ID[0], 4);
    strncpy(this->year2, &ID[2], 2);
    strncpy(this->major, &ID[4], 3);
    strncpy(this->serial, &ID[7], 3);

    this->year[sizeof(this->year) - 1] = '\0';
    this->year2[sizeof(this->year2) - 1] = '\0';
    this->major[sizeof(this->major) - 1] = '\0';
    this->serial[sizeof(this->serial) - 1] = '\0';

    return this;
}

void deleteStudentID(StudentID this)
{
    free(this);
}