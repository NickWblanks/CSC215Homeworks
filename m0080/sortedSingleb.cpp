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

//void sortedSingle::print(ostream& out, string seperator = ", ")
//{
//
//}

