#include <string_operation.h>
#include <expectation.h>
#include <iostream>

void testStrlen()
{
    char s[6] = "hello";
    expect(strlen(s)).to_be(5);
}

void testCharCmp()
{
    char s[6] = "hello";
    char t[6] = "googl";
    char u[7] = "python";
    expect(charcmp(s, s)).to_be_truthy();
    expect(charcmp(s, t)).to_be_falsy();
    expect(charcmp(s, u)).to_be_falsy();
}

void testInplaceReverse()
{

    char a[2] = "a";
    char b[2] = "a";
    char s[6] = "hello";
    char t[6] = "olleh";
    char r[7] = "python";
    char p[7] = "nohtyp";

    inplace_reverse(a);
    inplace_reverse(t);
    inplace_reverse(p);
    expect(charcmp(a, b)).to_be_truthy();
    expect(charcmp(s, t)).to_be_truthy();
    expect(charcmp(r, p)).to_be_truthy();
}

void testAtoi()
{
    char a[7] = "123456";
    char b[8] = "+123456";
    char c[8] = "-123456";
    char d[11] = "12Hoge3456";
    char e[11] = "    123456";
    char f[17] = "\t\n\v\f\r123456";
    char g[11] = "0000123456";
    char h[12] = "-2147483648";
    char i[11] = "2147483647";

    expect(f_atoi(a)).to_be(123456);
    expect(f_atoi(b)).to_be(123456);
    expect(f_atoi(c)).to_be(-123456);
    expect(f_atoi(d)).to_be(12);
    expect(f_atoi(e)).to_be(123456);
    expect(f_atoi(f)).to_be(123456);
    expect(f_atoi(g)).to_be(123456);
    expect(f_atoi(h)).to_be(-2147483648);
    expect(f_atoi(i)).to_be(2147483647);
}

int main()
{
    executeTestSuite("strlenのテスト", testStrlen);
    executeTestSuite("charcmpのテスト", testCharCmp);
    executeTestSuite("反転のテスト", testInplaceReverse);
    executeTestSuite("atoiのテスト", testAtoi);
    return 0;
}