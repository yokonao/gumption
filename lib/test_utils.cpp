#include <iostream>
#include <operation.h>
#include <expectation.h>

void testfloorlog()
{
    expect(floorlog(257) == 8).to_be_truthy();
    expect(floorlog(17) == 4).to_be_truthy();
    expect_error<std::invalid_argument>([] {
        int n = floorlog(0);
    });
}
int main()
{
    std::cout << "TEST START" << std::endl;
    testfloorlog();
    std::cout << "ALL GREEN" << std::endl;
    return 0;
}