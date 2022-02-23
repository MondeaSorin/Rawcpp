#pragma once
#include <iostream>

class Mystring
{
	friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
	friend std::istream& operator>>(std::istream& is, Mystring& rhs);
private:
	char* str;
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char* s);                                     // Overloaded constructor
    Mystring(const Mystring& source);                    // Copy constructor
    Mystring(Mystring&& source);                         // Move constructor
    ~Mystring();                                                     // Destructor

    Mystring& operator=(const Mystring& rhs);     // Copy assignment
    Mystring& operator=(Mystring&& rhs);           // Move assignment

    void display() const;

    int get_length() const;                                      // getters
    const char* get_str() const;

    Mystring operator-() const;                                         // make lowercase
    Mystring operator+(const Mystring& rhs) const;         // concatenate
    bool operator==(const Mystring& rhs) const;             // equals
    bool operator!=(const Mystring& rhs) const;              //not equals
    bool operator<(const Mystring& rhs) const;               //less than
    bool operator>(const Mystring& rhs) const;               //greater than
    Mystring& operator+=(const Mystring& rhs);            // s1 += s2;  concat and assign
    Mystring operator*(int n) const;                                // s1 = s2 * 3;  repeat s2 n times
    Mystring& operator*=(int n);                                    // s1 *= 3;   s1 = s1 * 3;    
    Mystring& operator++();                                          // pre-increment    ++s1;
    Mystring operator++(int);
};

