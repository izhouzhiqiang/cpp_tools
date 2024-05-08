#include <cstddef>

class string{
    // string(const char *str);
public:
    string(const string& str);
    string(string&& str);
    string(const char *str);
    string();
    ~string();
    inline size_t length() const;
    size_t find(const string& str);
    void concat(const string& str);
    inline bool isNull () const;
    string operator+(const string& str);
    string& operator=(const string& str);
    bool operator==(const string& str);
private:
    size_t  len;
    char *p_data;
};
