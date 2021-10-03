#ifndef _strlib_h
#define _strlib_h

#include "smalloc.h"

/* Section 1 -- Basic string operations */
/* 第一部分：字符串的基本操作 */

/*
 * Function: Concat
 * Usage: s = Concat(s1, s2);
 * --------------------------
 * This function concatenates two strings by joining them end
 * to end.  For example, Concat("ABC", "DE") returns the string
 * "ABCDE".
 * 
 * 此函数把两个字符串首尾相接。例如，Concat("abc", "de") 返回 "abcde"
 */

string Concat(string s1, string s2);

/*
 * Function: IthChar
 * Usage: ch = IthChar(s, i);
 * --------------------------
 * This function returns the character at position i in the
 * string s.  It is included in the library to make the type
 * string a true abstract type in the sense that all of the
 * necessary operations can be invoked using functions. Calling
 * IthChar(s, i) is like selecting s[i], except that IthChar
 * checks to see if i is within the range of legal index
 * positions, which extend from 0 to StringLength(s).
 * IthChar(s, StringLength(s)) returns the null character
 * at the end of the string.
 * 
 * 此函数返回在字符串中位置 i 的字符。
 */

char IthChar(string s, int i);

/*
 * Function: SubString
 * Usage: t = SubString(s, p1, p2);
 * --------------------------------
 * SubString returns a copy of the substring of s consisting
 * of the characters between index positions p1 and p2,
 * inclusive.  The following special cases apply:
 *
 * 1. If p1 is less than 0, it is assumed to be 0.
 * 2. If p2 is greater than the index of the last string
 *    position, which is StringLength(s) - 1, then p2 is
 *    set equal to StringLength(s) - 1.
 * 3. If p2 < p1, SubString returns the empty string.
 * 
 * SubString 函数返回字符串s的子字符串，子字符开始于s字符索引p1~p2位置。
 * 以下是特殊情况的处理：
 * 1. 如果 p1 小于0，它会被设置为0
 * 2. 如果 p2 大于s字符串的最大长度 StringLength(s) -1，那么p2会被设置为StringLength(s) -1
 * 3. 如果 p2 < p1, SubString 会返回一个空字符串
 */

string SubString(string s, int p1, int p2);

/*
 * Function: CharToString
 * Usage: s = CharToString(ch);
 * ----------------------------
 * This function takes a single character and returns a
 * one-character string consisting of that character.  The
 * CharToString function is useful, for example, if you
 * need to concatenate a string and a character.  Since
 * Concat requires two strings, you must first convert
 * the character into a string.
 * 
 * 此函数把单个字符转换为单个字符的字符串。CharToString是很有作用的，
 * 例如当你需要连接一个字符串与一个字符时，若你使用 Concat 函数，就可
 * 通过 CharToString 把单个字符转换成一个单字符的字符串
 */

string CharToString(char ch);

/*
 * Function: StringLength
 * Usage: len = StringLength(s);
 * -----------------------------
 * This function returns the length of s.
 * 
 * 此函数返回字符串的总字符数
 */

int StringLength(string s);

/*
 * Function: CopyString
 * Usage: newstr = CopyString(s);
 * ------------------------------
 * CopyString copies the string s into dynamically allocated
 * storage and returns the new string.  This function is not
 * ordinarily required if this package is used on its own,
 * but is often necessary when you are working with more than
 * one string package.
 * 
 * CopyString 复制字符串s到动态分配的内存中，并返回新生成的字符串。
 * 若只是包内使用，这个函数不是通常需要。但当有多个同样字符串变量需
 * 求时，它会被所调用。
 */

string CopyString(string s);

/* Section 2 -- String comparison functions */
/* 第二部分：字符串的比较函数 */

/*
 * Function: StringEqual
 * Usage: if (StringEqual(s1, s2)) ...
 * -----------------------------------
 * This function returns TRUE if the strings s1 and s2 are
 * equal.  For the strings to be considered equal, every
 * character in one string must precisely match the
 * corresponding character in the other.  Uppercase and
 * lowercase characters are considered to be different.
 * 
 * 当s1等同于s2时，StringEqual返回true。为了使字符串被认为是相等的，
 * 每个一个字符串中的字符必须精确匹配另一个对应的字符。大写和小写字符
 * 被认为是不同的
 */

bool StringEqual(string s1, string s2);

/*
 * Function: StringCompare
 * Usage: if (StringCompare(s1, s2) < 0) ...
 * -----------------------------------------
 * This function returns a number less than 0 if string s1
 * comes before s2 in alphabetical order, 0 if they are equal,
 * and a number greater than 0 if s1 comes after s2.  The
 * ordering is determined by the internal representation used
 * for characters, which is usually ASCII.
 */

int StringCompare(string s1, string s2);

/* Section 3 -- Search functions */

/*
 * Function: FindChar
 * Usage: p = FindChar(ch, text, start);
 * -------------------------------------
 * Beginning at position start in the string text, this
 * function searches for the character ch and returns the
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindChar(char ch, string text, int start);

/*
 * Function: FindString
 * Usage: p = FindString(str, text, start);
 * ----------------------------------------
 * Beginning at position start in the string text, this
 * function searches for the string str and returns the
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindString(string str, string text, int start);

/* Section 4 -- Case-conversion functions */

/*
 * Function: ConvertToLowerCase
 * Usage: s = ConvertToLowerCase(s);
 * ---------------------------------
 * This function returns a new string with all
 * alphabetic characters converted to lower case.
 */

string ConvertToLowerCase(string s);

/*
 * Function: ConvertToUpperCase
 * Usage: s = ConvertToUpperCase(s);
 * ---------------------------------
 * This function returns a new string with all
 * alphabetic characters converted to upper case.
 */

string ConvertToUpperCase(string s);

/* Section 5 -- Functions for converting numbers to strings */

/*
 * Function: IntegerToString
 * Usage: s = IntegerToString(n);
 * ------------------------------
 * This function converts an integer into the corresponding
 * string of digits.  For example, IntegerToString(123)
 * returns "123" as a string.
 */

string IntegerToString(int n);

/*
 * Function: StringToInteger
 * Usage: n = StringToInteger(s);
 * ------------------------------
 * This function converts a string of digits into an integer.
 * If the string is not a legal integer or contains extraneous
 * characters, StringToInteger signals an error condition.
 */

int StringToInteger(string s);

/*
 * Function: RealToString
 * Usage: s = RealToString(d);
 * ---------------------------
 * This function converts a floating-point number into the
 * corresponding string form.  For example, calling
 * RealToString(23.45) returns "23.45".  The conversion is
 * the same as that used for "%G" format in printf.
 */

string RealToString(double d);

/*
 * Function: StringToReal
 * Usage: d = StringToReal(s);
 * ---------------------------
 * This function converts a string representing a real number
 * into its corresponding value.  If the string is not a
 * legal floating-point number or if it contains extraneous
 * characters, StringToReal signals an error condition.
 */

double StringToReal(string s);

#endif
