//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright 2018 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef EVE_MODULE_CORE_FUNCTION_SIMD_PPC_VMX_MAKE_HPP_INCLUDED
#define EVE_MODULE_CORE_FUNCTION_SIMD_PPC_VMX_MAKE_HPP_INCLUDED

#include <eve/detail/abi.hpp>
#include <eve/detail/alias.hpp>
#include <eve/detail/compiler.hpp>
#include <eve/as.hpp>

#if defined(EVE_COMP_IS_GNUC)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
#endif

namespace eve { namespace detail
{
  template< typename T,typename... Vs>
  EVE_FORCEINLINE auto make(as_<T> const&, eve::ppc_ const&, Vs... vs) noexcept
  {
    using type = ext::as_register_t<T,sizeof...(vs),eve::ppc_>;
    type that = { static_cast<T>(vs)... };
    return that;
  }

  template< typename T,typename V>
  EVE_FORCEINLINE auto make(as_<T> const&, eve::ppc_ const&, V v) noexcept
  {
    using type = ext::as_register_t<T,expected_cardinal_v<T>,eve::ppc_>;
    type that = { v };
    return vec_splat(that, 0);
  }
} }

#if defined(EVE_COMP_IS_GNUC)
#pragma GCC diagnostic pop
#endif

#endif