#ifndef PROTOZERO_BYTESWAP_HPP
#define PROTOZERO_BYTESWAP_HPP

/*****************************************************************************

protozero - Minimalistic protocol buffer decoder and encoder in C++.

This file is from https://github.com/mapbox/protozero where you can find more
documentation.

*****************************************************************************/

/**
 * @file byteswap.hpp
 *
 * @brief Contains functions to swap bytes in values (for different endianness).
 */

#include <cstdint>
#include <cassert>
#include <type_traits>

#include <protozero/config.hpp>

namespace protozero {
namespace detail {

inline uint32_t byteswap_impl(uint32_t value) noexcept {
#ifdef PROTOZERO_USE_BUILTIN_BSWAP
    return __builtin_bswap32(value);
#else
    return ((value & 0xff000000) >> 24) |
           ((value & 0x00ff0000) >>  8) |
           ((value & 0x0000ff00) <<  8) |
           ((value & 0x000000ff) << 24);
#endif
}

inline uint64_t byteswap_impl(uint64_t value) noexcept {
#ifdef PROTOZERO_USE_BUILTIN_BSWAP
    return __builtin_bswap64(value);
#else
    return ((value & 0xff00000000000000ULL) >> 56) |
           ((value & 0x00ff000000000000ULL) >> 40) |
           ((value & 0x0000ff0000000000ULL) >> 24) |
           ((value & 0x000000ff00000000ULL) >>  8) |
           ((value & 0x00000000ff000000ULL) <<  8) |
           ((value & 0x0000000000ff0000ULL) << 24) |
           ((value & 0x000000000000ff00ULL) << 40) |
           ((value & 0x00000000000000ffULL) << 56);
#endif
}

template <typename T>
inline void byteswap_inplace(T& value) noexcept {
    value = static_cast<T>(byteswap_impl(static_cast<typename std::make_unsigned<T>::type>(value)));
}

} // end namespace detail
} // end namespace protozero

#endif // PROTOZERO_BYTESWAP_HPP
