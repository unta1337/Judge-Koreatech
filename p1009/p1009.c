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
            this->value <<= 8;
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

    unsigned int value_ = (unsigned int)value;
    for (int i = 0; i < 4; i++)
    {
        this->values[i] = value_ % 0x100;
        value_ >>= 8;
    }
    this->value = value;

    this->convert_endian = si32_convert_endian;
    this->print = si32_print;

    return this;
}

void delete_si32(si32* this)
{
    free(this);
}

int main()
{
    int T;
    scanf("%d", &T);

    si32** inputs = (si32**)malloc(T * sizeof(si32*));

    for (int i = 0; i < T; i++)
    {
        int input;
        scanf("%d", &input);

        inputs[i] = create_si32(input);
        inputs[i]->convert_endian(inputs[i]);
    }

    for (int i = 0; i < T; i++)
        printf("%d\n", inputs[i]->value);

    for (int i = 0; i < T; i++)
        delete_si32(inputs[i]);
    free(inputs);

    return 0;
}