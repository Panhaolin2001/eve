//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2020 Joel FALCOU
  Copyright 2020 Jean-Thierry LAPRESTE

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include <eve/function/derivative/atan2.hpp>
#include <type_traits>

TTS_CASE_TPL("Check derivative(atan2) return type", EVE_TYPE)
{
  if constexpr(eve::floating_value<T>)
  {
    TTS_EXPR_IS(eve::derivative(eve::atan2)(T(), T()), T);
  }
}

TTS_CASE_TPL("Check eve::derivative(eve::atan2) behavior", EVE_TYPE)
{

  if constexpr(eve::floating_value<T>)
  {
    TTS_EQUAL(eve::derivative_1st(eve::atan2)(T{3},T{4}), T(4.0/25.0));
    TTS_EQUAL(eve::derivative_2nd(eve::atan2)(T{3},T{4}), T(3.0/25.0));
  }
}
