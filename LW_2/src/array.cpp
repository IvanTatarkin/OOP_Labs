#include "solver.h"

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