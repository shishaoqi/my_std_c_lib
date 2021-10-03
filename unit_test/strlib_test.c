#include <stdio.h>
#include "simpio.h"
#include "strlib.h"

int main() {
    string firstStr, secondStr;

    // printf("input first string:\n");
    // firstStr = GetLine();
    // printf("input second string:\n");
    // secondStr = GetLine();
    firstStr = "hello";
    secondStr = "world";

    string concatenateStr;
    concatenateStr = Concat(firstStr, secondStr);
    printf("join first with second string end to end: %s\n", concatenateStr);

    char character;
    character = IthChar(concatenateStr, 4);
    printf("the character at position 4 is: %c\n", character);

    int p1 = 0, p2 = 4;
    string subStr = SubString(concatenateStr, p1, p2);
    printf("a copy of the substring is: %s\n", subStr);

    string charStr = CharToString(character);
    printf("a one-character string consisting of that character: %s\n", charStr);

    int strLength = StringLength(concatenateStr);
    printf("the length of string：%d\n", strLength);

    string copyStr = CopyString(concatenateStr);
    printf("opyString copies the string s into dynamically allocated storage and returns the new string: %s\n", copyStr);

    bool equalRst = StringEqual(firstStr, secondStr);
    printf("the strings firstStr and secondStr are equal? %d\n", equalRst);

    int number = StringCompare(firstStr, secondStr);
    printf("firstStr compare secondStr: %d\n", number);

    char character2 = 'l';
    int charIdx = FindChar('l', firstStr, 0);
    printf("find l in firstStr: %d\n", charIdx);

    int find = FindString("ld", secondStr, 0);
    printf("find result: %d\n", find);

    int integer = 100;
    printf("integer to string: %s\n", IntegerToString(integer));

    string integerStr = "12345f";
    printf("string to Integer: %d\n", StringToInteger(integerStr));

}