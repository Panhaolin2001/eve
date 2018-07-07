//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2018 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef EVE_MEMORY_IS_ALIGNED_HPP_INCLUDED
#define EVE_MEMORY_IS_ALIGNED_HPP_INCLUDED

#include <cstdint>
#include <eve/memory/power_of_2.hpp>

namespace eve
{
  template<std::size_t Alignment,typename T> constexpr bool is_aligned(T value) noexcept
  {
    static_assert(is_power_of_2(Alignment), "[eve] Alignment must be a power of 2");
    return (value & (Alignment - 1)) == 0;
  }

  template<std::size_t Alignment,typename T> constexpr bool is_aligned(T* ptr) noexcept
  {
    static_assert(is_power_of_2(Alignment), "[eve] Alignment must be a power of 2");
    return is_aligned<Alignment>(reinterpret_cast<std::uintptr_t>(ptr));
  }
}

#endif