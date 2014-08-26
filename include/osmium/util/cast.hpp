#ifndef OSMIUM_UTIL_CAST_HPP
#define OSMIUM_UTIL_CAST_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013,2014 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <cassert>
#include <limits>
#include <type_traits>

namespace osmium {

    template <typename T, typename F, typename std::enable_if<std::is_signed<F>::value, int>::type = 0>
    inline T static_cast_with_assert(const F value) {
        assert(value >= std::numeric_limits<T>::min() && value <= std::numeric_limits<T>::max());
        return static_cast<T>(value);
    } 

    template <typename T, typename F, typename std::enable_if<std::is_unsigned<F>::value, int>::type = 0>
    inline T static_cast_with_assert(const F value) {
        assert(value <= std::numeric_limits<T>::max());
        return static_cast<T>(value);
    } 

} // namespace osmium

#endif // OSMIUM_UTIL_CAST_HPP
