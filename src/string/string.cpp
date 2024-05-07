#include "string.hpp"
#include <cstdlib>
#include <cstring>

string::string():p_data(nullptr),len(0)
{
    // pass
};

bool string::isNull () const
{
    return p_data;
}

string::string(const string& str)
{
    if(str.isNull())
    {
        p_data = nullptr;
        len = 0;
    }
    else
    {
        p_data = (char *)malloc(str.len + 1);
        strcpy(p_data,str.p_data);
        len = str.len;
    }
}

int string::length() const
{
    return len;
}

