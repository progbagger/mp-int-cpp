#ifndef MP_INT_CPP_MP_UNSIGNED_INT_H_
#define MP_INT_CPP_MP_UNSIGNED_INT_H_

#include <string>
#include <vector>

namespace mp {

class MpUnsignedInt final {
 public:
  MpUnsignedInt();
  MpUnsignedInt(unsigned long long);
  explicit MpUnsignedInt(const std::string& str);

  operator unsigned long long() const;
  explicit operator std::string() const;

  unsigned long long ToUll() const;
  std::string ToString() const;

  bool operator[](std::size_t pos) const;
  void SetBit(std::size_t pos, bool value = true);

  MpUnsignedInt operator~() const;

  MpUnsignedInt& operator+=(const MpUnsignedInt& r);
  MpUnsignedInt& operator-=(const MpUnsignedInt& r);
  MpUnsignedInt& operator*=(const MpUnsignedInt& r);
  MpUnsignedInt& operator/=(const MpUnsignedInt& r);

  MpUnsignedInt& operator&=(const MpUnsignedInt& r);
  MpUnsignedInt& operator|=(const MpUnsignedInt& r);
  MpUnsignedInt& operator^=(const MpUnsignedInt& r);

  MpUnsignedInt& operator<<=(unsigned long long shift);
  MpUnsignedInt& operator>>=(unsigned long long shift);

  friend MpUnsignedInt operator+(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);
  friend MpUnsignedInt operator-(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);
  friend MpUnsignedInt operator*(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);
  friend MpUnsignedInt operator/(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);

  friend MpUnsignedInt operator&(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);
  friend MpUnsignedInt operator|(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);
  friend MpUnsignedInt operator^(const MpUnsignedInt& l,
                                 const MpUnsignedInt& r);

  friend MpUnsignedInt operator<<(const MpUnsignedInt& l,
                                  unsigned long long shift);
  friend MpUnsignedInt operator>>(const MpUnsignedInt& l,
                                  unsigned long long shift);

 private:
  std::size_t high_bit_;
  std::vector<bool> bits_;
};

MpUnsignedInt operator""_UMP(unsigned long long number);
MpUnsignedInt operator""_UMP(const char* str);

}  // namespace mp

#endif  // MP_INT_CPP_MP_UNSIGNED_INT_H_
