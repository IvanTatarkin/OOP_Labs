#include "solver.h"

unsigned char charToSeven(char c) {
    if (c >= '0' && c <= '6') return c - '0';
    throw std::invalid_argument("Неверный символ для семеричного числа");
}

char sevenToChar(unsigned char c) {
    if (c <= 6) return '0' + c;
    throw std::invalid_argument("Неверное значение для семеричной цифры");
}

// Array class methods
Array::Array() : _digits(nullptr), _capacity(0), _size(0) {}

Array::Array(size_t size) : _digits(new unsigned char[size]), _capacity(size), _size(size) {
    std::fill(_digits, _digits + size, '0');
}

Array::Array(const std::initializer_list<unsigned char>& digits) 
    : _capacity(digits.size()), _size(digits.size()) {
    _digits = new unsigned char[_capacity];
    std::copy(digits.begin(), digits.end(), _digits);
}

Array::Array(const Array& other) : _capacity(other._capacity), _size(other._size) {
    _digits = new unsigned char[_capacity];
    std::copy(other._digits, other._digits + _size, _digits);
}

Array::Array(Array&& other) noexcept : _digits(other._digits), _capacity(other._capacity), _size(other._size) {
    other._digits = nullptr;
    other._capacity = 0;
    other._size = 0;
}

Array::~Array() noexcept {
    delete[] _digits;
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;

    delete[] _digits;
    _capacity = other._capacity;
    _size = other._size;
    _digits = new unsigned char[_capacity];
    std::copy(other._digits, other._digits + _size, _digits);

    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this == &other) return *this;

    delete[] _digits;
    _digits = other._digits;
    _capacity = other._capacity;
    _size = other._size;

    other._digits = nullptr;
    other._capacity = 0;
    other._size = 0;

    return *this;
}

size_t Array::size() const {
    return _size;
}

unsigned char& Array::operator[](size_t index) {
    if (index >= _size) throw std::out_of_range("Индекс вне диапазона");
    return _digits[index];
}

const unsigned char& Array::operator[](size_t index) const {
    if (index >= _size) throw std::out_of_range("Индекс вне диапазона");
    return _digits[index];
}

Array& Array::operator+=(const Array& other) {
    if (_size != other._size) throw std::invalid_argument("Размеры массивов не совпадают");

    for (size_t i = 0; i < _size; ++i) {
        _digits[i] += other._digits[i];
    }

    return *this;
}

Array& Array::operator-=(const Array& other) {
    if (_size != other._size) throw std::invalid_argument("Размеры массивов не совпадают");

    for (size_t i = 0; i < _size; ++i) {
        _digits[i] -= other._digits[i];
    }

    return *this;
}

bool Array::operator==(const Array& other) const {
    if (_size != other._size) return false;
    for (size_t i = 0; i < _size; ++i) {
        if (_digits[i] != other._digits[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

bool Array::operator<(const Array& other) const {
    size_t minSize = std::min(_size, other._size);
    for (size_t i = 0; i < minSize; ++i) {
        if (_digits[i] < other._digits[i]) return true;
        if (_digits[i] > other._digits[i]) return false;
    }
    return _size < other._size;
}

bool Array::operator>(const Array& other) const {
    return other < *this;
}

// Seven class methods
Seven::Seven() : Array() {}

Seven::Seven(const std::string& sevenStr) : Array(sevenStr.size()) {
    for (size_t i = 0; i < sevenStr.size(); ++i) {
        _digits[i] = charToSeven(sevenStr[i]);
    }
}

Seven::Seven(const Seven& other) : Array(other) {}

Seven::Seven(Seven&& other) noexcept : Array(std::move(other)) {}

Seven::~Seven() noexcept {}

Seven& Seven::operator=(const Seven& other) {
    Array::operator=(other);
    return *this;
}

Seven& Seven::operator=(Seven&& other) noexcept {
    Array::operator=(std::move(other));
    return *this;
}

Seven& Seven::operator+=(const Seven& other) {
    std::string sevenStr1 = this->toString();
    std::string sevenStr2 = other.toString();
    size_t maxLength = std::max(sevenStr1.size(), sevenStr2.size());

    // Добавляем нули слева для выравнивания длины чисел
    while (sevenStr1.size() < maxLength) sevenStr1 = '0' + sevenStr1;
    while (sevenStr2.size() < maxLength) sevenStr2 = '0' + sevenStr2;
    // std::cout << "sevenStr1 после дополнения: " << sevenStr1 << std::endl;
    // std::cout << "sevenStr2 после дополнения: " << sevenStr2 << std::endl;
    int carry = 0;
    std::string result;

    for (int i = maxLength - 1; i >= 0; --i) {
        unsigned char digit1 = charToSeven(sevenStr1[i]);
        unsigned char digit2 = charToSeven(sevenStr2[i]);
        int sum = digit1 + digit2 + carry;
        // std::cout << "сумма цифр" << sum << std::endl;
        result += sevenToChar(sum % 7);  // Добавляем текущий разряд
        carry = sum / 7;  
    }
    
    if (carry > 0) {
        result += sevenToChar(carry);
    }

    std::reverse(result.begin(), result.end());

    if (result.size() > _capacity) {
        delete[] _digits;
        _capacity = result.size();
        _digits = new unsigned char[_capacity];
    }

    _size = result.size();
    for (size_t i = 0; i < _size; ++i) {
        _digits[i] = charToSeven(result[i]);
    }

    return *this;
}





Seven& Seven::operator-=(const Seven& other) {
    std::string sevenStr1 = this->toString();
    std::string sevenStr2 = other.toString();
    size_t maxLength = std::max(sevenStr1.size(), sevenStr2.size());

    sevenStr1;
    sevenStr2;
    while (sevenStr1.size() < maxLength) sevenStr1 = '0' + sevenStr1;
    while (sevenStr2.size() < maxLength) sevenStr2 = '0' + sevenStr2;
    std::cout << "sevenStr1 после дополнения: " << sevenStr1 << std::endl;
    std::cout << "sevenStr2 после дополнения: " << sevenStr2 << std::endl;
    //std::reverse(sevenStr1.begin(), sevenStr1.end());
    //std::reverse(sevenStr2.begin(), sevenStr2.end());



    bool borrow = false;
    std::string result = "";

    for (size_t i = 0; i < maxLength; ++i) {
        unsigned char digit1 = charToSeven(sevenStr1[i]);
        unsigned char digit2 = charToSeven(sevenStr2[i]);

        if (borrow) {
            if (digit1 > 0) {
                digit1 -= 1;
                borrow = false;
            } else {
                digit1 = 6;
                borrow = true;
            }
        }

        if (digit1 < digit2) {
            digit1 += 7;
            borrow = true;
        }

        result += sevenToChar(digit1 - digit2);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());

    size_t newSize = result.size();
    if (newSize > _capacity) {
        throw std::overflow_error("Seven: Переполнение массива после вычитания.");
    }
    _size = newSize;

    for (size_t i = 0; i < newSize; ++i) {
        _digits[i] = charToSeven(result[i]);
    }

    return *this;
}

bool Seven::operator==(const Seven& other) const {
    return this->toString() == other.toString();
}

bool Seven::operator!=(const Seven& other) const {
    return !(*this == other);
}

bool Seven::operator<(const Seven& other) const {
    return sevenCompare(this->toString(), other.toString()) < 0;
}

bool Seven::operator>(const Seven& other) const {
    return sevenCompare(this->toString(), other.toString()) > 0;
}

std::string Seven::toString() const {
    std::ostringstream oss;
    for (size_t i = 0; i < size(); i++) {
        oss << sevenToChar(_digits[i]);
    }
    return oss.str();
}

unsigned char Seven::charToSeven(char c) const {
    if (c >= '0' && c <= '6') return c - '0';
    throw std::invalid_argument("Неверный символ для семеричного числа");
}

char Seven::sevenToChar(unsigned char sevenVal) const {
    return '0' + sevenVal;
}

int Seven::sevenCompare(const std::string& seven1, const std::string& seven2) const {
    if (seven1.size() > seven2.size()) return 1;
    if (seven1.size() < seven2.size()) return -1;

    for (size_t i = 0; i < seven1.size(); ++i) {
        if (seven1[i] > seven2[i]) return 1;
        if (seven1[i] < seven2[i]) return -1;
    }
    return 0;
}
