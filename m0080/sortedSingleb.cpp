#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
    node* temp = new (nothrow) node;
    temp->theItem = item;
    node* prev = headptr;
    node* curr = headptr;
    if (empty())
    {
        temp->next = nullptr;
        headptr = temp;
        return true;
    }
    if (item < curr->theItem)
    {
        headptr = temp;
        temp->next = curr;
        return true;
    }
    while (curr != nullptr && curr->theItem <= item)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
    return true;
}

void sortedSingle::print(ostream &out, string seperator)
{
    node* temp;
    temp = headptr;
    if (headptr == nullptr)
    {
        return;
    }
    while (temp != nullptr)
    {
        if (temp->next == nullptr)
        {
            out << temp->theItem;
            out << "\n";
            return;
        }
        out << temp->theItem << seperator;   
        temp = temp->next;
    }
}

