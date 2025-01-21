//
// ... morton header files
//
#include <morton/capi.h>
#include <morton/morton.hpp>

extern "C" {

typedef unsigned long long morton64bit;
typedef unsigned morton32bit;
typedef unsigned short morton16bit;
typedef unsigned char morton8bit;

////////////////////////////////////////////////////////////////////////
//
//  64bit
//

//
// ... 2-dimensional
//

// 32bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_32bits_per_index(morton64bit i, morton64bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<32>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_32bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<2>, row_major);
  return morton64bitx2{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_32bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_32bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 16bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_16bits_per_index(morton64bit i, morton64bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<16>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_16bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return morton64bitx2{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_16bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_16bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 8bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_8bits_per_index(morton64bit i, morton64bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_8bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return morton64bitx2{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_8bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_8bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 4bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_4bits_per_index(morton64bit i, morton64bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_4bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return morton64bitx2{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_4bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_4bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 2bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_2bits_per_index(morton64bit i, morton64bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_2bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return morton64bitx2{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_2bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode2d_2bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

//
// ... 3-Dimensional
//

// 22bits/index
MORTON_EXPORT morton64bit
morton64bit_encode3d_22bits_per_index(morton64bit i, morton64bit j, morton64bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<32>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_22bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<3>, row_major);
  return morton64bitx3{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
              decode(natural<2>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_2(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<32>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 16bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_16bits_per_index(morton64bit i, morton64bit j, morton64bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<16>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_16bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return morton64bitx3{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
              decode(natural<2>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_2(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 8bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_8bits_per_index(morton64bit i, morton64bit j, morton64bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_8bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return morton64bitx3{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
              decode(natural<2>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_2(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 4bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_4bits_per_index(morton64bit i, morton64bit j, morton64bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_4bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return morton64bitx3{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
              decode(natural<2>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_2(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 2bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_2bits_per_index(morton64bit i, morton64bit j, morton64bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_2bits_per_index(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return morton64bitx3{
      .indices =
          {
              decode(natural<0>, m),
              decode(natural<1>, m),
              decode(natural<2>, m),
          },
  };
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_0(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_1(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_2(morton64bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

////////////////////////////////////////////////////////////////////////
//
//  32bit
//

//
// ... 2-dimensional
//

// 16bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_16bits_per_index(morton32bit i, morton32bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<16>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_16bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return morton32bitx2{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_16bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_16bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 8bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_8bits_per_index(morton32bit i, morton32bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_8bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return morton32bitx2{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_8bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_8bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 4bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_4bits_per_index(morton32bit i, morton32bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_4bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return morton32bitx2{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_4bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}
MORTON_EXPORT morton32bit
morton32bit_decode2d_4bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 2bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_2bits_per_index(morton32bit i, morton32bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_2bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return morton32bitx2{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_2bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode2d_2bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

//
// ... 3-Dimensional
//

// 10bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_10bits_per_index(morton32bit i, morton32bit j, morton32bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<16>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_10bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return morton32bitx3{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
              morton32bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_2(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<16>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 8bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_8bits_per_index(morton32bit i, morton32bit j, morton32bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_8bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return morton32bitx3{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
              morton32bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_2(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 4bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_4bits_per_index(morton32bit i, morton32bit j, morton32bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_4bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return morton32bitx3{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
              morton32bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_2(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 2bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_2bits_per_index(morton32bit i, morton32bit j, morton32bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_2bits_per_index(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return morton32bitx3{
      .indices =
          {
              morton32bit(decode(natural<0>, m)),
              morton32bit(decode(natural<1>, m)),
              morton32bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_0(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_1(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_2(morton32bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

////////////////////////////////////////////////////////////////////////
//
//  16bit
//

//
// ... 2-dimensional
//

// 8bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_8bits_per_index(morton16bit i, morton16bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_8bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return morton16bitx2{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_8bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_8bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 4bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_4bits_per_index(morton16bit i, morton16bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_4bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return morton16bitx2{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_4bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_4bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 2bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_2bits_per_index(morton16bit i, morton16bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_2bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return morton16bitx2{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_2bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode2d_2bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

//
// ... 3-Dimensional
//

// 5bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_5bits_per_index(morton16bit i, morton16bit j, morton16bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<8>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_5bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return morton16bitx3{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
              morton16bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_2(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<8>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 4bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_4bits_per_index(morton16bit i, morton16bit j, morton16bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_4bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return morton16bitx3{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
              morton16bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_2(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

// 2bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_2bits_per_index(morton16bit i, morton16bit j, morton16bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_2bits_per_index(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return morton16bitx3{
      .indices =
          {
              morton16bit(decode(natural<0>, m)),
              morton16bit(decode(natural<1>, m)),
              morton16bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_0(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_1(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_2(morton16bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

////////////////////////////////////////////////////////////////////////
//
//  8bit
//

//
// ... 2-dimensional
//

// 4bits/index

MORTON_EXPORT morton8bit
morton8bit_encode2d_4bits_per_index(morton8bit i, morton8bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<4>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton8bitx2
morton8bit_decode2d_4bits_per_index(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return morton8bitx2{
      .indices =
          {
              morton8bit(decode(natural<0>, m)),
              morton8bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton8bit
morton8bit_decode2d_4bits_per_index_0(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton8bit
morton8bit_decode2d_4bits_per_index_1(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<4>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

// 2bits/index

MORTON_EXPORT morton8bit
morton8bit_encode2d_2bits_per_index(morton8bit i, morton8bit j) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<2>, row_major);
  return encode(i, j);
}

MORTON_EXPORT morton8bitx2
morton8bit_decode2d_2bits_per_index(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return morton8bitx2{
      .indices =
          {
              morton8bit(decode(natural<0>, m)),
              morton8bit(decode(natural<1>, m)),
          },
  };
}

MORTON_EXPORT morton8bit
morton8bit_decode2d_2bits_per_index_0(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton8bit
morton8bit_decode2d_2bits_per_index_1(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<2>, row_major);
  return decode(natural<1>, m);
}

//
// ... 3-Dimensional
//

// 2bits/index

MORTON_EXPORT morton8bit
morton8bit_encode3d_2bits_per_index(morton8bit i, morton8bit j, morton8bit k) {
  using namespace morton;
  constexpr auto encode = make_encoder(bits_per_index<2>, num_indices<3>, row_major);
  return encode(i, j, k);
}

MORTON_EXPORT morton8bitx3
morton8bit_decode3d_2bits_per_index(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return morton8bitx3{
      .indices =
          {
              morton8bit(decode(natural<0>, m)),
              morton8bit(decode(natural<1>, m)),
              morton8bit(decode(natural<2>, m)),
          },
  };
}

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_0(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<0>, m);
}

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_1(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<1>, m);
}

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_2(morton8bit m) {
  using namespace morton;
  constexpr auto decode = make_decoder(bits_per_index<2>, num_indices<3>, row_major);
  return decode(natural<2>, m);
}

} // end of extern "C"
