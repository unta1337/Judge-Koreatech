#include <stdio.h>
#include <stdlib.h>

struct ID
{
    char yearOfAdmission[5];
    char majorID[4];
    char serialNo[4];
};

typedef struct ID* ID;

ID newID(char *id)
{
    ID this = (ID)malloc(sizeof(ID));

    int index = 0;
    for (int i = 0; i < 4; i++)
        this->yearOfAdmission[i] = id[index++];
    this->yearOfAdmission[4] = 0;
    for (int i = 0; i < 3; i++)
        this->majorID[i] = id[index++];
    this->majorID[3] = 0;
    for (int i = 0; i < 3; i++)
        this->serialNo[i] = id[index++];
    this->serialNo[3] = 0;

    return this;
}

void delID(ID this)
{
    free(this);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    ID *ids = (ID*)malloc(n * sizeof(ID));
    for (int i = 0; i < n; i++)
    {
        char input[11];
        scanf("%s", input);

        ids[i] = newID(input);
    }

    for (int i = 0; i < n; i++)
        printf("%s\n", &ids[i]->yearOfAdmission[2]);

    for (int i = 0; i < n; i++)
        delID(ids[i]);
    free(ids);

    return 0;
}