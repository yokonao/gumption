#ifndef S_ITEM_HPP
#define S_ITEM_HPP

#include <string>

struct SItem
{
    std::string e;
    std::string value;
    SItem *next;
    bool isDummy;

    SItem();

    SItem(std::string e, std::string value, SItem *next);
};

#endif
