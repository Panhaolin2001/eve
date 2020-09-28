//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2020 Joel FALCOU
  Copyright 2020 Jean-Thierry LAPRESTE

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#pragma once

#include <eve/detail/implementation.hpp>
#include <eve/concept/value.hpp>

namespace eve::detail
{
  // -----------------------------------------------------------------------------------------------
  // 128 bits implementation
  template<signed_integral_scalar_value T, typename N>
  EVE_FORCEINLINE wide<T, N, x86_128_> negate_(EVE_SUPPORTS(ssse3_)
                              , wide<T, N, x86_128_> const &a0, wide<T, N, x86_128_> const &a1) noexcept
  {
    if (sizeof(T) == 8) return  map(negate, a0, a1);
    else if (sizeof(T) == 4) return  _mm_sign_epi32(a0, a1);
    else if (sizeof(T) == 2) return  _mm_sign_epi16(a0, a1);
    else if (sizeof(T) == 1) return  _mm_sign_epi8(a0, a1);
  }

   // -----------------------------------------------------------------------------------------------
  // 256 bits implementation
  template<signed_integral_scalar_value T, typename N>
  EVE_FORCEINLINE wide<T, N, x86_256_> negate_(EVE_SUPPORTS(avx2_)
                              , wide<T, N, x86_256_> const &a0, wide<T, N, x86_256_> const &a1) noexcept
  {
    if (sizeof(T) == 8) return  negate_(EVE_RETARGET(sse2_), a0, a1);
    else if (sizeof(T) == 4) return  _mm256_sign_epi32(a0, a1);
    else if (sizeof(T) == 2) return  _mm256_sign_epi16(a0, a1);
    else if (sizeof(T) == 1) return  _mm256_sign_epi8(a0, a1);
  }
}

