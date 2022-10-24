#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node *curr, *prev;
    node *temp;
    temp = headptr;
    curr = headptr;
    prev = headptr;
    if (empty())
    {
        return false;
    }
    if (temp->theItem == item)
    {
        headptr = headptr->next;
        delete temp;
        return true;
    }
    if (find(item) == false)
    {
        return false;
    }
    while (curr != nullptr && curr->theItem != item)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return true;
}

