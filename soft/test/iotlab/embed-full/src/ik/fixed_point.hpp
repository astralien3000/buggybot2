#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

template<typename T, unsigned int SHIFT>
class FixedPoint {
private:
  T _value;
  
public:
  constexpr inline FixedPoint(void) : _value(0) {}
  constexpr inline FixedPoint(long long val) : _value((T)val << SHIFT) {}
  constexpr inline FixedPoint(int val) : _value((T)val << SHIFT) {}
  constexpr inline FixedPoint(short val) : _value((T)val << SHIFT) {}
  constexpr inline FixedPoint(char val) : _value((T)val << SHIFT) {}
  constexpr inline FixedPoint(float val) : _value((T)(val *  (float)((T)1 << SHIFT))) {}
  constexpr inline FixedPoint(double val) : _value((T)(val *  (double)((T)1 << SHIFT))) {}

  constexpr inline FixedPoint(T val, int) : _value((T)val) {}
  
  constexpr inline operator float(void) {
    return ((float)_value) / ((float)((T)1 << SHIFT));
  }

  constexpr inline operator double(void) {
    return ((double)_value) / ((double)((T)1 << SHIFT));
  }
  
  constexpr inline operator long long(void) {
    return _value >> SHIFT;
  }
  
  constexpr inline operator int(void) {
    return _value >> SHIFT;
  }
  
  constexpr inline operator short(void) {
    return _value >> SHIFT;
  }
  
  constexpr inline operator char(void) {
    return _value >> SHIFT;
  }
  
  constexpr inline T raw(void) {
    return _value;
  }
};

// Arithmetic

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator-(const FixedPoint<T, SHIFT>& a) {
  return FixedPoint<T, SHIFT>(-a.raw(), 0);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator+(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(a.raw() + b.raw(), 0);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator-(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(a.raw() - b.raw(), 0);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator*(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(((a.raw() >> (SHIFT/2)) * (b.raw() >> (SHIFT-SHIFT/2))), 0);
}

template<typename T, unsigned int SHIFT>
constexpr inline FixedPoint<T, SHIFT> operator/(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return FixedPoint<T, SHIFT>(((a.raw() << (SHIFT/2)) / (b.raw() >> (SHIFT-SHIFT/2))), 0);
}

// Comparison

template<typename T, unsigned int SHIFT>
constexpr inline bool operator==(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return a.raw() == b.raw();
}

template<typename T, unsigned int SHIFT>
constexpr inline bool operator!=(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return a.raw() != b.raw();
}

template<typename T, unsigned int SHIFT>
constexpr inline bool operator<=(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return a.raw() <= b.raw();
}

template<typename T, unsigned int SHIFT>
constexpr inline bool operator>=(const FixedPoint<T, SHIFT>& a, const FixedPoint<T, SHIFT>& b) {
  return a.raw() >= b.raw();
}

#endif//FIXED_POINT_HPP
