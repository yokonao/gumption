#ifndef EXPECTATION_HPP
#define EXPECTATION_HPP

#include <stdexcept>
#include <iostream>
#include <functional>
#include <typeinfo>

template <class T>
class Expectation
{
    T e;

public:
    Expectation(T e)
    {
        this->e = e;
    }

    void to_be(T to)
    {
        if (e == to)
        {
            return;
        }
        else
        {
            std::cout << "Test Failed!" << std::endl;
            std::cout << "expected:" << to << std::endl;
            std::cout << "actual:" << e << std::endl;
            throw std::logic_error("テストに失敗しました");
        }
    }

    void to_be_truthy()
    {
        if (e)
        {
            return;
        }
        else
        {
            std::cout << "Test Failed!" << std::endl;
            std::cout << "true expected" << std::endl;
            throw std::logic_error("テストに失敗しました");
        }
    }

    void to_be_falsy()
    {
        if (e)
        {
            std::cout << "Test Failed!" << std::endl;
            std::cout << "false expected" << std::endl;
            throw std::logic_error("テストに失敗しました");
        }
        else
        {
            return;
        }
    }
};

template <class T>
Expectation<T> expect(T e)
{
    return Expectation<T>(e);
}

template <class E>
void expect_error(std::function<void()> lambda)
{
    try
    {
        lambda();
    }
    catch (E &e)
    {
        return;
    }
    throw std::logic_error("想定した例外が発生しませんでした");
}

#endif
