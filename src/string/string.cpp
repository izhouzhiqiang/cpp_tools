#include "string.hpp"
#include <cstdlib>
#include <cstring>

bool string::isNull () const
{
    return p_data;
}

int string::length() const
{
    return len;
}

string::string():p_data(nullptr),len(0)
{
    // pass
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

string::string(string&& str)
{
    len = str.len;
    p_data = str.p_data;
    str.len = 0;
    str.p_data = nullptr;
}

string::string(const char* str) :len(0),p_data(nullptr)
{
    if(str)
    {
        len = strlen(str);
        p_data = (char*)malloc(len + 1);
    }
}

string::~string()
{
    if(p_data) free(p_data);
}

void string::concat(const string& str)
{
    // TO DO
}

string string::operator+(const string& str)
{

}
string string::operator=(const string& str)
{

}
bool string::operator==(const string& str)
{
    
}
