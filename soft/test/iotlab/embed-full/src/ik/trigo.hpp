#ifndef FLASH_TRIGO_HPP
#define FLASH_TRIGO_HPP

#include <math.h>
#include "fixed_point.hpp"

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator+(const FixedPoint<T, SHIFT>& a, const double& b) {
  return a + FixedPoint<T, SHIFT>(b);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator-(const FixedPoint<T, SHIFT>& a, const double& b) {
  return a - FixedPoint<T, SHIFT>(b);
}


template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator*(const double& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(a) * b;
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator*(const FixedPoint<T, SHIFT>& a, const double& b) {
  return a * FixedPoint<T, SHIFT>(b);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator*(const int& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(a) * b;
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator*(const FixedPoint<T, SHIFT>& a, const int& b) {
  return a * FixedPoint<T, SHIFT>(b);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator/(const double& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(a) / b;
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator/(const FixedPoint<T, SHIFT>& a, const double& b) {
  return a / FixedPoint<T, SHIFT>(b);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator/(const FixedPoint<T, SHIFT>& a, const int& b) {
  return a / FixedPoint<T, SHIFT>(b);
}

template<typename T, unsigned int SHIFT>
constexpr inline bool operator!=(const FixedPoint<T, SHIFT>& a, const int& b) {
  return a != FixedPoint<T, SHIFT>(b);
}

//using real = float;
//using real = FixedPoint<long long, 34>;
using real = FixedPoint<long long, 33>;

namespace MyCos {

  real cos(real val);
  real sin(real val);
  
}

#define my_cos(x) MyCos::cos(x)
#define my_sin(x) MyCos::sin(x)

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> sqrt(const FixedPoint<T, SHIFT>& val) {
  return sqrt((float)val);
}

#endif//FLASH_TRIGO_HPP
