#ifndef LAB2_H
#define LAB2_H

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>

unsigned char charToSeven(char c);
char sevenToChar(unsigned char c);

class Array {
protected:
    unsigned char* _digits;
    size_t _capacity;
    size_t _size;

public:
    Array(); 
    Array(size_t capacity); 
    Array(const std::initializer_list<unsigned char>& digits);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    size_t size() const;
    unsigned char& operator[](size_t index);
    const unsigned char& operator[](size_t index) const;

    Array& operator+=(const Array& other);
    Array& operator-=(const Array& other);

    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator>(const Array& other) const;
};

class Seven : public Array {
public:
    Seven();
    Seven(const std::string& sevenStr);
    Seven(const Seven& other);
    Seven(Seven&& other) noexcept;
    virtual ~Seven() noexcept;

    Seven& operator=(const Seven& other);
    Seven& operator=(Seven&& other) noexcept;

    Seven& operator+=(const Seven& other);
    Seven& operator-=(const Seven& other);

    bool operator==(const Seven& other) const;
    bool operator!=(const Seven& other) const;
    bool operator<(const Seven& other) const;
    bool operator>(const Seven& other) const;

    std::string toString() const;

private:
    unsigned char charToSeven(char c) const;
    char sevenToChar(unsigned char sevenVal) const;

    std::string sevenOperation(const std::string& seven1, const std::string& seven2, char operation);
    int sevenCompare(const std::string& seven1, const std::string& seven2) const;
};

#endif
