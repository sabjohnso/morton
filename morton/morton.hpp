#pragma once

//
// ... morton header files
//
#include <morton/bits/Bit_Conveyor.hpp>
#include <morton/bits/Mask.hpp>
#include <morton/bits/Natural.hpp>
#include <morton/bits/Shift.hpp>
#include <morton/bits/Type.hpp>
#include <morton/bits/expansion_masks.hpp>

namespace morton {

  using details::Bit_Conveyor;
  using details::mask;
  using details::natural;
  using details::shift;
  using details::type;

  using details::bits_per_index;
  using details::num_indices;

  using details::duplicate;

} // end of namespace morton
