#include <stdio.h>
#include "simpio.h"

int main()
{
    string str;
    printf("input a string:");
    str = GetLine();
    printf("what you input:  %s\n", str);

    int integer;
    printf("input a integer");
    integer = GetInteger();
    printf("integer that you input: %d\n", integer);

    long longNum;
    printf("input long number");
    longNum = GetLong();
    printf("long number that you input: %ld\n", longNum);

    double doubleNum;
    printf("input float number");
    doubleNum = GetReal();
    printf("float number that you input: %f\n", doubleNum);
}