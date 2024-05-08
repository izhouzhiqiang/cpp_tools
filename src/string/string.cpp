#include "string.hpp"
#include <cstdlib>
#include <cstring>

bool string::isNull () const
{
    return p_data;
}

size_t string::length() const
{
    return len;
}

string::string():len(0),p_data(nullptr)
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
        p_data = (char *)malloc(str.length() + 1);
        strcpy(p_data,str.p_data);
        len = str.length();
    }
}

string::string(string&& str)
{
    len = str.length();
    p_data = str.p_data;
    str.len = 0;
    str.p_data = nullptr;
}

string::string(const char* str) :len(0),p_data(nullptr)
{
    if(str)
    {
        this->len = strlen(str);
        this->p_data = (char*)malloc(len + 1);
    }
}

string::~string()
{
    if(p_data) free(p_data);
}

void string::concat(const string& str)
{
    if(this->p_data && str.p_data)
    {
        size_t new_len = strlen(this->p_data) + strlen(str.p_data) + 1;
        char * new_data = (char *)malloc(new_len);
        strcpy(new_data,this->p_data);
        strcpy(new_data + strlen(this->p_data),str.p_data);
        new_data[new_len-1] = '\0';
        free(this->p_data);
        this->p_data=new_data;
    }
    else if((!(this->p_data))&&(!(str.p_data)))
    {
        // pass
    }
    else if(this->p_data)
    {
        // pass
    }
    else if(str.p_data)
    {
        this->len = str.length() + 1;
        this->p_data = (char *)malloc(this->len);
        strcpy(this->p_data,str.p_data);
        this->p_data[len - 1] = '\0';
    }
    else
    {
        // can not reach
    }
}

string string::operator+(const string& str)
{
    this->concat(str);
    return *this;
}
string& string::operator=(const string& str)
{
    if(this != &str)
    {
        this->len = str.length();
        this->p_data = (char *)malloc(this->len+1);
        strcpy(this->p_data,str.p_data);
        this->p_data[this->len] = '\0';
    }
    return *this;
}
bool string::operator==(const string& str)
{
    size_t i = 0;
    if(this->len != str.length())
        return false;
    for(;i<this->len;i++)
    {
        if(this->p_data[i] != str.p_data[i])
            return false;
    }
    return true;
}
