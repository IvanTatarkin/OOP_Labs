#pragma once

#include <cmath>
#include <type_traits>

template <class T>
concept Scalar = std::is_scalar_v<T>;

;


template <Scalar T>


template <Scalar T>


template <Scalar T>
Point<T>::Point(const Point &other) = default;

template <Scalar T>
Point<T>::Point(Point &&other) noexcept = default;

template <Scalar T>
Point<T>& Point<T>::operator=(const Point &other) = default;

template <Scalar T>
Point<T>& Point<T>::operator=(Point &&other) noexcept = default;

template <Scalar T>


template <Scalar T>


template <Scalar T>


template <Scalar T>
