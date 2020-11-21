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

int main()
{
    executeTestSuite("strlenのテスト", testStrlen);
    executeTestSuite("charcmpのテスト", testCharCmp);
    executeTestSuite("反転のテスト", testInplaceReverse);
    return 0;
}