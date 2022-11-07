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
    headptr = nullptr;
    node* copy = list.headptr;
    node* paste;

    headptr = new (nothrow) node;
    headptr->theItem = copy->theItem;//copy 1 item in.
    headptr->next = nullptr;

    copy = list.headptr->next; //seek next item
    paste = headptr;
    while (copy != nullptr) //if next is null drop out
    {
        paste->next = new (nothrow) node;
        paste = paste->next;
        paste->theItem = copy->theItem;
        paste->next = nullptr;
        copy = copy->next;
    }
}

