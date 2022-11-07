/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle(sortedSingle &list)
{
    if (list.empty() == true)
    {
        headptr = nullptr;
        return;
    }
    node* copy;
    node* paste = headptr;
    headptr = new (nothrow) node;
    headptr->theItem = list.headptr->theItem;
    headptr->next = nullptr;
    copy = list.headptr->next;
    while (copy != nullptr)
    {
        paste->next = new (nothrow) node;
        paste = paste->next;
        paste->theItem = copy->theItem;
        paste->next = nullptr;
    }
}

