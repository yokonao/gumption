#ifndef DOUBLY_LIKED_LIST_HPP
#define DOUBLY_LIKED_LIST_HPP

template <typename T>
class DoublyLinkedItem
{
public:
    T body;
    DoublyLinkedItem *prev;
    DoublyLinkedItem *next;
    bool isDummy;

    DoublyLinkedItem()
    {
        body = T();
        prev = this;
        next = this;
        isDummy = true;
    }

    DoublyLinkedItem(T body, DoublyLinkedItem *prev, DoublyLinkedItem *next)
    {
        this->body = body;
        this->prev = prev;
        this->next = next;
        isDummy = false;
    }
};

#endif
