#include "mp_unsigned_int.h"

#include <limits>

namespace mp {

MpUnsignedInt::MpUnsignedInt() : MpUnsignedInt(0, kDefaultBitCount) {}

MpUnsignedInt::MpUnsignedInt(unsigned long long number)
    : MpUnsignedInt(number, kDefaultBitCount) {}

MpUnsignedInt::MpUnsignedInt(unsigned long long number, std::size_t bits_count)
    : high_bit_(), bits_(bits_count) {
  for (std::size_t i = 0; i < std::min(kDefaultBitCount, bits_count); ++i) {
    bool r = number & (1ULL << i);
    bits_[i] = r;
    if (r) high_bit_ = i;
  }
}

MpUnsignedInt::MpUnsignedInt(const std::string& str) : MpUnsignedInt() {
  // TODO
}

MpUnsignedInt::operator unsigned long long() const { return ToUll(); }

MpUnsignedInt::operator std::string() const { return ToString(); }

unsigned long long MpUnsignedInt::ToUll() const {
  if (high_bit_ >= kDefaultBitCount)
    return std::numeric_limits<unsigned long long>::max();

  unsigned long long result = 0;
  for (std::size_t i = 0; i <= high_bit_; ++i)
    if (bits_[i]) result |= (1ULL << i);
  return result;
}

std::string MpUnsignedInt::ToString() const { return std::string(); }

bool MpUnsignedInt::operator[](std::size_t pos) const { return bits_[pos]; }

void MpUnsignedInt::SetBit(std::size_t pos, bool value) { bits_[pos] = value; }

std::size_t MpUnsignedInt::BitsCount() const { return bits_.size(); }

MpUnsignedInt MpUnsignedInt::operator~() const {
  MpUnsignedInt result(*this);
  for (std::size_t i = 0; i < bits_.size(); ++i) result.SetBit(i, !result[i]);
  return result;
}

MpUnsignedInt& MpUnsignedInt::operator+=(const MpUnsignedInt& r) {
  if (this == &r) {
    *this += MpUnsignedInt(r);
    return *this;
  }

  bits_.resize(std::max(BitsCount(), r.BitsCount()));
  std::size_t edge = std::max(high_bit_, r.high_bit_);
  for (std::size_t i = 0; i < edge; ++i) {
    if (bits_[i] && r[i]) {
      std::size_t j = i + 1;
      for (; j < edge && bits_[j]; ++j) {
        bits_[j] = false;
      }
      bits_[j] = true;
    }
    bits_[i] = bits_[i] ^ r[i];
    if (bits_[i]) high_bit_ = i;
  }
  return *this;
}

}  // namespace mp
