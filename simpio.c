#include <stdio.h>
#include <string.h>

#include "smalloc.h"
#include "strlib.h"
#include "simpio.h"

/*
 * Constants:
 * ----------
 * InitialBufferSize -- Initial buffer size for ReadLine
 */

#define InitialBufferSize 120

/* Exported entries */

int GetInteger(void)
{
    string line;
    int value;
    char termch;

    while (TRUE) {
        line = GetLine();
        if (line == NULL) Error("GetInteger: unexpected end of file");
        switch (sscanf(line, " %d %c", &value, &termch)) {
          case 1:
            Free(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        Free(line);
        printf("Retry: ");
    }
}

long GetLong(void)
{
    string line;
    long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        if (line == NULL) Error("GetLong: unexpected end of file");
        switch (sscanf(line, " %ld %c", &value, &termch)) {
          case 1:
            Free(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        Free(line);
        printf("Retry: ");
    }
}

double GetReal(void)
{
    string line;
    double value;
    char termch;

    while (TRUE) {
        line = GetLine();
        if (line == NULL) Error("GetReal: unexpected end of file");
        switch (sscanf(line, " %lf %c", &value, &termch)) {
          case 1:
            Free(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter a real number\n");
            break;
        }
        Free(line);
        printf("Retry: ");
    }
}

/*
 * Function: GetLine
 * -----------------
 * This function is a simple wrapper; all the work is done by
 * ReadLine.
 * 
 * 此函数简单包装自 Readline。
 */

string GetLine(void)
{
    return (ReadLine(stdin));
}
/*
 * Function: ReadLine
 * ------------------
 * This function operates by reading characters from the file
 * into a dynamically allocated buffer.  If the buffer becomes
 * full before the end of the line is reached, a new buffer
 * twice the size of the previous one is allocated.
 * 
 * 此函数从文件读取字符到静态的buffer中，完成后返回一个字符串。
 * 如果读取过程中，buffer满了，那么会重新分配两倍长的新buffer，
 * 把旧buffer内容转移到新buffer中，然后再开始读取。
 */

string ReadLine(FILE *infile)
{
    string line, nline;
    int n, size;
    char ch;

    n = 0;
    size = InitialBufferSize;
    line = (string)smalloc(size + 1);
    while ((ch = getc(infile)) != '\n' && ch != EOF) {
        if (n == size) {
            size *= 2;
            nline = (string) smalloc(size + 1);
            strncpy(nline, line, n);
            Free(line);
            line = nline;
        }
        line[n++] = ch;
    }
    if (n == 0 && ch == EOF) {
        Free(line);
        return (NULL);
    }
    line[n] = '\0';
    nline = (string) smalloc(n + 1);
    strcpy(nline, line);
    Free(line);
    return (nline);
}
