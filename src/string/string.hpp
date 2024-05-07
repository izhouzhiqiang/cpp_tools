class string{
    // string(const char *str);
public:
    string(const string& str);
    string(const string&& str);
    string(const char *str,...);
    string();
    ~string();
    int length() const;
    int find (const char* str);
    int concat(const char* str);
    bool isNull () const;
private:
    char *p_data;
    int len;
};