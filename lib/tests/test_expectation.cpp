#include "../expectation.h"
#include <string.h>

void testExpectation()
{
    Expectation<int> one = Expectation<int>(1);
    one.to_be(1);
    try
    {
        one.to_be(2);
        throw;
    }
    catch (std::logic_error &e)
    {
        if (strcmp(e.what(), "テストに失敗しました") != 0)
        {
            throw;
        }
    }
    one.to_be_truthy();
    try
    {
        one.to_be_falsy();
        throw;
    }
    catch (std::logic_error &e)
    {
        if (strcmp(e.what(), "テストに失敗しました") != 0)
        {
            throw;
        }
    }

    Expectation<bool> f = Expectation<bool>(false);
    f.to_be_falsy();
    try
    {
        f.to_be_truthy();
        throw;
    }
    catch (std::logic_error &e)
    {
        if (strcmp(e.what(), "テストに失敗しました") != 0)
        {
            throw;
        }
    }
}
void testExpectError()
{
    expect_error<std::logic_error>([] { throw std::logic_error("logic_error"); });
    expect_error<std::domain_error>([] { throw std::domain_error("domain_error"); });
    expect_error<std::invalid_argument>([] { throw std::invalid_argument("invalid_argument"); });

    try
    {
        expect_error<std::logic_error>([] {});
    }
    catch (std::logic_error &e)
    {
        if (strcmp(e.what(), "想定した例外が発生しませんでした") != 0)
        {
            throw;
        }
    }

    try
    {
        expect_error<std::domain_error>([] { throw std::invalid_argument("invalid_argument"); });
    }
    catch (std::invalid_argument &e)
    {
        if (strcmp(e.what(), "invalid_argument") != 0)
        {
            throw;
        }
    }
}
int main()
{

    std::cout << "TEST START" << std::endl;
    testExpectation();
    testExpectError();
    std::cout << "ALL GREEN" << std::endl;

    return 0;
}
