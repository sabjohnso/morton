#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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

typedef struct morton64bitx2_s{
  morton64bit indices[2];
} morton64bitx2;

// 32bits/index

#define MORTON_EXPORT

MORTON_EXPORT morton64bit
morton64bit_encode2d_32bits_per_index(morton64bit i, morton64bit j);

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_32bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_32bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_32bits_per_index_1(morton64bit m);

// 16bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_16bits_per_index(morton64bit i, morton64bit j);

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_16bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_16bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_16bits_per_index_1(morton64bit m);

// 8bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_8bits_per_index(morton64bit i, morton64bit j);

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_8bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_8bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_8bits_per_index_1(morton64bit m);

// 4bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_4bits_per_index(morton64bit i, morton64bit j);

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_4bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_4bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_4bits_per_index_1(morton64bit m);

// 2bits/index

MORTON_EXPORT morton64bit
morton64bit_encode2d_2bits_per_index(morton64bit i, morton64bit j);

MORTON_EXPORT morton64bitx2
morton64bit_decode2d_2bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_2bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode2d_2bits_per_index_1(morton64bit m);

//
// ... 3-Dimensional
//
typedef struct morton64bitx3_s{
  morton64bit indices[3];
} morton64bitx3;

// 22bits/index
MORTON_EXPORT morton64bit
morton64bit_encode3d_22bits_per_index(morton64bit i, morton64bit j, morton64bit k);

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_22bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_1(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_22bits_per_index_2(morton64bit m);

// 16bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_16bits_per_index(morton64bit i, morton64bit j, morton64bit k);

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_16bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_1(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_16bits_per_index_2(morton64bit m);

// 8bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_8bits_per_index(morton64bit i, morton64bit j, morton64bit k);

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_8bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_1(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_8bits_per_index_2(morton64bit m);

// 4bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_4bits_per_index(morton64bit i, morton64bit j, morton64bit k);

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_4bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_1(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_4bits_per_index_2(morton64bit m);

// 2bits/index

MORTON_EXPORT morton64bit
morton64bit_encode3d_2bits_per_index(morton64bit i, morton64bit j, morton64bit k);

MORTON_EXPORT morton64bitx3
morton64bit_decode3d_2bits_per_index(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_0(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_1(morton64bit m);

MORTON_EXPORT morton64bit
morton64bit_decode3d_2bits_per_index_2(morton64bit m);


////////////////////////////////////////////////////////////////////////
//
//  32bit
//

//
// ... 2-dimensional
//

typedef struct morton32bitx2_s{
  morton32bit indices[2];
} morton32bitx2;

// 16bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_16bits_per_index(morton32bit i, morton32bit j);

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_16bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_16bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_16bits_per_index_1(morton32bit m);

// 8bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_8bits_per_index(morton32bit i, morton32bit j);

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_8bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_8bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_8bits_per_index_1(morton32bit m);

// 4bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_4bits_per_index(morton32bit i, morton32bit j);

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_4bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_4bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_4bits_per_index_1(morton32bit m);

// 2bits/index

MORTON_EXPORT morton32bit
morton32bit_encode2d_2bits_per_index(morton32bit i, morton32bit j);

MORTON_EXPORT morton32bitx2
morton32bit_decode2d_2bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_2bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode2d_2bits_per_index_1(morton32bit m);

//
// ... 3-Dimensional
//
typedef struct morton32bitx3_s{
  morton32bit indices[3];
} morton32bitx3;

// 10bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_10bits_per_index(morton32bit i, morton32bit j, morton32bit k);

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_10bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_1(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_10bits_per_index_2(morton32bit m);

// 8bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_8bits_per_index(morton32bit i, morton32bit j, morton32bit k);

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_8bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_1(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_8bits_per_index_2(morton32bit m);

// 4bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_4bits_per_index(morton32bit i, morton32bit j, morton32bit k);

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_4bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_1(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_4bits_per_index_2(morton32bit m);

// 2bits/index

MORTON_EXPORT morton32bit
morton32bit_encode3d_2bits_per_index(morton32bit i, morton32bit j, morton32bit k);

MORTON_EXPORT morton32bitx3
morton32bit_decode3d_2bits_per_index(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_0(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_1(morton32bit m);

MORTON_EXPORT morton32bit
morton32bit_decode3d_2bits_per_index_2(morton32bit m);


////////////////////////////////////////////////////////////////////////
//
//  16bit
//

//
// ... 2-dimensional
//

typedef struct morton16bitx2_s{
  morton16bit indices[2];
} morton16bitx2;

// 8bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_8bits_per_index(morton16bit i, morton16bit j);

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_8bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_8bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_8bits_per_index_1(morton16bit m);

// 4bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_4bits_per_index(morton16bit i, morton16bit j);

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_4bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_4bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_4bits_per_index_1(morton16bit m);

// 2bits/index

MORTON_EXPORT morton16bit
morton16bit_encode2d_2bits_per_index(morton16bit i, morton16bit j);

MORTON_EXPORT morton16bitx2
morton16bit_decode2d_2bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_2bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode2d_2bits_per_index_1(morton16bit m);

//
// ... 3-Dimensional
//
typedef struct morton16bitx3_s{
  morton16bit indices[3];
} morton16bitx3;


// 5bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_5bits_per_index(morton16bit i, morton16bit j, morton16bit k);

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_5bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_1(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_5bits_per_index_2(morton16bit m);

// 4bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_4bits_per_index(morton16bit i, morton16bit j, morton16bit k);

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_4bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_1(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_4bits_per_index_2(morton16bit m);

// 2bits/index

MORTON_EXPORT morton16bit
morton16bit_encode3d_2bits_per_index(morton16bit i, morton16bit j, morton16bit k);

MORTON_EXPORT morton16bitx3
morton16bit_decode3d_2bits_per_index(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_0(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_1(morton16bit m);

MORTON_EXPORT morton16bit
morton16bit_decode3d_2bits_per_index_2(morton16bit m);


////////////////////////////////////////////////////////////////////////
//
//  8bit
//

//
// ... 2-dimensional
//

typedef struct morton8bitx2_s{
  morton8bit indices[2];
} morton8bitx2;

// 4bits/index

MORTON_EXPORT morton8bit
morton8bit_encode2d_4bits_per_index(morton8bit i, morton8bit j);

MORTON_EXPORT morton8bitx2
morton8bit_decode2d_4bits_per_index(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode2d_4bits_per_index_0(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode2d_4bits_per_index_1(morton8bit m);

// 2bits/index

MORTON_EXPORT morton8bit
morton8bit_encode2d_2bits_per_index(morton8bit i, morton8bit j);

MORTON_EXPORT morton8bitx2
morton8bit_decode2d_2bits_per_index(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode2d_2bits_per_index_0(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode2d_2bits_per_index_1(morton8bit m);

//
// ... 3-Dimensional
//
typedef struct morton8bitx3_s{
  morton8bit indices[3];
} morton8bitx3;

// 2bits/index

MORTON_EXPORT morton8bit
morton8bit_encode3d_2bits_per_index(morton8bit i, morton8bit j, morton8bit k);

MORTON_EXPORT morton8bitx3
morton8bit_decode3d_2bits_per_index(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_0(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_1(morton8bit m);

MORTON_EXPORT morton8bit
morton8bit_decode3d_2bits_per_index_2(morton8bit m);

#ifdef __cplusplus
} // end of extern "C"
#endif
