#include "solver.h"
#include <cmath>

// Figure class methods
double Figure::getArea() const {
    if (!_areaCalculated) {
        _area = static_cast<double>(*this); 
        _areaCalculated = true;
    }
    return _area;
}

std::pair<double, double> Figure::getFigureCenter() const {
    if (!_centerCalculated) {
        calculateFigureCenter();
        _centerCalculated = true;
    }
    return {_centerX, _centerY};
}
// Array class methods
Array::Array() : _capacity(10), _size(0) {
    _elements = new Figure*[_capacity];
}

Array::Array(size_t capacity) : _capacity(capacity), _size(0) {
    _elements = new Figure*[_capacity];
}

Array::~Array() noexcept {
    for (size_t i = 0; i < _size; ++i) {
        delete _elements[i];
    }
    delete[] _elements;
}

void Array::addFigure(Figure* figure) {
    if (_size >= _capacity) {
        _capacity *= 2;
        Figure** newElements = new Figure*[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newElements[i] = _elements[i];
        }
        delete[] _elements;
        _elements = newElements;
    }
    _elements[_size++] = figure;
}

void Array::removeFigure(size_t index) {
    if (index < _size) {
        delete _elements[index];
        for (size_t i = index; i < _size - 1; ++i) {
            _elements[i] = _elements[i + 1];
        }
        --_size;
    }
}

void Array::printFigures() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << *_elements[i] << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        total += _elements[i]->getArea();
    }
    return total;
}

// Square class methods
void Square::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}

Square::operator double() const {
    double side = std::sqrt(std::pow(__x2 - __x1, 2) + std::pow(__y2 - __y1, 2));
    return side * side;
}


std::ostream& operator<<(std::ostream& os, const Square& square) {
    os << "Square: ((" << square.__x1 << ", " << square.__y1 << "), ("
       << square.__x2 << ", " << square.__y2 << "), ("
       << square.__x3 << ", " << square.__y3 << "), ("
       << square.__x4 << ", " << square.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.__x1 >> square.__y1
       >> square.__x2 >> square.__y2
       >> square.__x3 >> square.__y3
       >> square.__x4 >> square.__y4;
    return is;
}

// Rectangle class methods
void Rectangle::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}

Rectangle::operator double() const {
    double width = std::sqrt(std::pow(__x2 - __x1, 2) + std::pow(__y2 - __y1, 2));
    double height = std::sqrt(std::pow(__x3 - __x2, 2) + std::pow(__y3 - __y2, 2));
    return width * height;
}


std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
    os << "Rectangle: ((" << rectangle.__x1 << ", " << rectangle.__y1 << "), ("
       << rectangle.__x2 << ", " << rectangle.__y2 << "), ("
       << rectangle.__x3 << ", " << rectangle.__y3 << "), ("
       << rectangle.__x4 << ", " << rectangle.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    is >> rectangle.__x1 >> rectangle.__y1
       >> rectangle.__x2 >> rectangle.__y2
       >> rectangle.__x3 >> rectangle.__y3
       >> rectangle.__x4 >> rectangle.__y4;
    return is;
}

// Trapezoid class methods
void Trapezoid::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}
Trapezoid::operator double() const {
    // Применяем формулу площади многоугольника через координаты вершин
    double area = 0.5 * std::abs(
        __x1 * __y2 + __x2 * __y3 + __x3 * __y4 + __x4 * __y1 - 
        (__y1 * __x2 + __y2 * __x3 + __y3 * __x4 + __y4 * __x1)
    );

    return area;
}





std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
    os << "Trapezoid: ((" << trapezoid.__x1 << ", " << trapezoid.__y1 << "), ("
       << trapezoid.__x2 << ", " << trapezoid.__y2 << "), ("
       << trapezoid.__x3 << ", " << trapezoid.__y3 << "), ("
       << trapezoid.__x4 << ", " << trapezoid.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.__x1 >> trapezoid.__y1
       >> trapezoid.__x2 >> trapezoid.__y2
       >> trapezoid.__x3 >> trapezoid.__y3
       >> trapezoid.__x4 >> trapezoid.__y4;
    return is;
}
