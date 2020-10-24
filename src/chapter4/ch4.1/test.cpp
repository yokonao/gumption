#include <iostream>
#include <s_linked_list.h>
#include "chaining_hash.h"
#include "expectation.h"

void testHash()
{
    expect(hashPrime("a")).to_be(1);
    expect(hashPrime("b")).to_be(2);
    expect(hashPrime("z")).to_be(26);
    expect(hashPrime("az")).to_be(52);
    expect(hashPrime("ruby")).to_be(330641);
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("Ruby");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("ruビー");
    });
    expect_error<std::invalid_argument>([] {
        unsigned long long N = hashPrime("るびー");
    });
    expect_error<std::length_error>([] {
        unsigned long long N = hashPrime("rubyonrails");
    });
    expect(hash("ruby", 1000)).to_be(641);
    expect(hash("zzzzzz", 10)).to_be(6);
}

void testChainingHash()
{
    ChainingHash ch;
    expect(ch.find("ruby")).to_be("");

    ch.insert("ruby", "rails");
    ch.insert("python", "django");
    ch.insert("dart", "flutter");

    expect(ch.find("ruby")).to_be("ruby");
    expect(ch["ruby"]).to_be("rails");
    expect(ch.find("python")).to_be("python");
    expect(ch["python"]).to_be("django");
    expect(ch.find("dart")).to_be("dart");
    expect(ch["dart"]).to_be("flutter");
    expect(ch.find("java")).to_be("");
    expect(ch["java"]).to_be("");

    ch.remove("python");
    expect(ch.find("python")).to_be("");
    ch.remove("ruby");
    expect(ch.find("ruby")).to_be("");
    ch.remove("dart");
    expect(ch.find("dart")).to_be("");
}

int main()
{
    std::cout << "TEST START" << std::endl;
    testHash();
    testChainingHash();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}
