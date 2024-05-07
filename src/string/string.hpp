class string{
    // string(const char *str);
public:
    string(const string& str);
    string(string&& str);
    string(const char *str);
    string();
    ~string();
    int length() const;
    int find(const string& str);
    void concat(const string& str);
    bool isNull () const;
    string operator+(const string& str);
    string operator=(const string& str);
    bool operator==(const string& str);
private:
    char *p_data;
    int len;
};