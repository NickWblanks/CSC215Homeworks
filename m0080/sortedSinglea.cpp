#include "sortedSingle.h"


sortedSingle::sortedSingle()
{
    headptr = nullptr;
}

bool sortedSingle::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }
    return false;
}

int sortedSingle::size()
{
    node* temp;
    temp = headptr;
    int count = 0;
    if (headptr == nullptr)
    {
        return count;
    }
    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}


bool sortedSingle::find(int item)
{
    node* temp;
    temp = headptr;
    if (headptr == nullptr)
    {
        return false;
    }
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int sortedSingle::retrievePosition(int item)
{
    int count = 1;
    node* temp;
    temp = headptr;
    if (headptr == nullptr)
    {
        return 0;
    }
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return 0;
}

sortedSingle::~sortedSingle()
{
    clear();
    delete headptr;
}
