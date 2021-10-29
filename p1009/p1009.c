// 1009: Endian
/*
 * 빅 엔디안 또는 리틀 엔디안의 데이터가 주어졌을 때, 이를 리틀 엔디언 또는 빅 엔디언으로 변환하여라.
 */
// https://judge.koreatech.ac.kr/problem.php?id=1009

// 메모리 사용량: KB
// 실행 시간: ms
// 코드 용량: bytes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Signed_Integer_32
{
    int values[4];
    int value;

    void (*convert_endian)(struct Signed_Integer_32* this);
    void (*print)(struct Signed_Integer_32* this);
} si32;

void si32_convert_endian(si32* this)
{
    for (int i = 0; i < 2; i++)
    {
        int temp = this->values[i];
        this->values[i] = this->values[3 - i];
        this->values[3 - i] = temp;
    }

    this->value = 0;
    for (int i = 3; i >= 0; i--)
    {
        this->value += this->values[i];
        if (i != 0)
            this->value *= 0x100;
    }
}

void si32_print(si32* this)
{
    for (int i = 0; i < 4; i++)
        printf("%02X ", this->values[i]);
    printf("\n");
}

si32* create_si32(int value)
{
    si32* this = (si32*)malloc(sizeof(si32));

    int value_ = value;
    for (int i = 0; i < 4; i++)
    {
        this->values[i] = value_ % 0x100;
        value_ /= 0x100;
    }
    this->value = value;

    this->convert_endian = si32_convert_endian;
    this->print = si32_print;

    return this;
}

si32* delete_si32(si32* this)
{
    free(this);
}

int main()
{

    return 0;
}