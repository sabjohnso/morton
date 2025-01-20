#pragma once

//
// ... morton header files
//
#include <morton/bits/Decoder.hpp>
#include <morton/bits/Encoder.hpp>
#include <morton/bits/Mask.hpp>
#include <morton/bits/Natural.hpp>
#include <morton/bits/Shift.hpp>
#include <morton/bits/Simple_Permutation.hpp>
#include <morton/bits/Type.hpp>

namespace morton {

  using details::left;
  using details::make_decoder;
  using details::make_encoder;
  using details::mask;
  using details::natural;
  using details::right;
  using details::shift;
  using details::Simple_Permutation;
  using details::type;

  using details::bits_per_index;
  using details::num_indices;

  using details::duplicate;

  using details::codomain_bits;
  using details::domain_bits;

  using details::column_major;

  using details::row_major;

} // end of namespace morton
