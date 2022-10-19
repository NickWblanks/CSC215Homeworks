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

sortedSingle::~sortedSingle()
{

}

