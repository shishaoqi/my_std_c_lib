#ifndef _simpio_h
#define _simpio_h

#include "smalloc.h"

/*
 * Function: GetInteger
 * Usage: i = GetInteger();
 * ------------------------
 * GetInteger reads a line of text from standard input and scans
 * it as an integer.  The integer value is returned.  If an
 * integer cannot be scanned or if more characters follow the
 * number, the user is given a chance to retry.
 * 
 * GetInteger 从标准输入读取一行文本，并扫描出整数。成功则返回整数，
 * 如果未能扫描出整数或带有多余字符，则让用户重新输入一次
 */

int GetInteger(void);

/*
 * Function: GetLong
 * Usage: l = GetLong();
 * ---------------------
 * GetLong reads a line of text from standard input and scans
 * it as a long integer.  The value is returned as a long.
 * If an integer cannot be scanned or if more characters follow
 * the number, the user is given a chance to retry.
 * 
 * GetLong 从标准输入读取一行文本，并扫描出整数。成功则返回整数，
 * 如果未能扫描出整数或带有多余字符，则让用户重新输入一次
 */

long GetLong(void);

/*
 * Function: GetReal
 * Usage: x = GetReal();
 * ---------------------
 * GetReal reads a line of text from standard input and scans
 * it as a double.  If the number cannot be scanned or if extra
 * characters follow after the number ends, the user is given
 * a chance to reenter the value.
 * 
 * GetReal 从标准输入读取一行文本，并从该文本中读取格式化的浮点数。
 * 成功则返回浮点数。如果未能扫描出浮点数或带有多余字符，则让用户重
 * 新输入一次
 */

double GetReal(void);

/*
 * Function: GetLine
 * Usage: s = GetLine();
 * ---------------------
 * GetLine reads a line of text from standard input and returns
 * the line as a string.  The newline character that terminates
 * the input is not stored as part of the string.
 * GetLine 从标准输入读取一行文本，后把文本转化成字符串返回。回车表示结束
 * 标准输入，它不会被存入字符串中。
 */

string GetLine(void);

/*
 * Function: ReadLine
 * Usage: s = ReadLine(infile);
 * ----------------------------
 * ReadLine reads a line of text from the input file and
 * returns the line as a string.  The newline character
 * that terminates the input is not stored as part of the
 * string.  The ReadLine function returns NULL if infile
 * is at the end-of-file position.
 * 
 * ReadLine 从文件读取一行文本，并将它以字符串形式返回。回车符不做为
 * 字符串的一部分，只表示字符串输出结束。读取的文件是文件结尾，则返回 NULL。
 */

string ReadLine(FILE *infile);

#endif
