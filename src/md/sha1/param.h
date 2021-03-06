#pragma once

#define _COMPARE_SHA1(x) x

#define SHA1_DIGEST_LENGTH 20
#define SHA1_BLOCK_LENGTH 64
#define SHA1_WORD_SIZE 32
#define SHA1_STATE_WORDS 5
#define SHA1_ENDIAN __ORDER_BIG_ENDIAN__

#define SHA1_IV { \
  0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0 \
}

#define SHA1_IMPL_PRIO \
(cryptogams_shaext, CRYPTOGAMS_SHAEXT), \
(intel_shaext, INTEL_SHAEXT), \
(dispatch, DISPATCH), \
(intel_avx2, INTEL_AVX2), \
(intel_avx, INTEL_AVX), \
(cryptogams_ssse3, CRYPTOGAMS_SSSE3), \
(intel_ssse3, INTEL_SSSE3), \
(cryptogams_gen, CRYPTOGAMS_GEN), \
(native, NATIVE), \
(nayuki64, NAYUKI64), \
(generic, GENERIC)

#define SHA1_USING_GENERIC             0
#define SHA1_USING_NATIVE              1
#define SHA1_USING_NAYUKI64            2
#define SHA1_USING_INTEL_SSSE3         3
#define SHA1_USING_INTEL_AVX           4
#define SHA1_USING_INTEL_AVX2          5
#define SHA1_USING_INTEL_SHAEXT        6
#define SHA1_USING_CRYPTOGAMS_GEN      7
#define SHA1_USING_CRYPTOGAMS_SSSE3    8
#define SHA1_USING_CRYPTOGAMS_SHAEXT   9
#define SHA1_USING_DISPATCH           10

#define SHA1_ENABLE_GENERIC           (1<<SHA1_USING_GENERIC)
#define SHA1_ENABLE_NATIVE            (1<<SHA1_USING_NATIVE)
#define SHA1_ENABLE_NAYUKI64          (1<<SHA1_USING_NAYUKI64)
#define SHA1_ENABLE_INTEL_SSSE3       (1<<SHA1_USING_INTEL_SSSE3)
#define SHA1_ENABLE_INTEL_AVX         (1<<SHA1_USING_INTEL_AVX)
#define SHA1_ENABLE_INTEL_AVX2        (1<<SHA1_USING_INTEL_AVX2)
#define SHA1_ENABLE_INTEL_SHAEXT      (1<<SHA1_USING_INTEL_SHAEXT)
#define SHA1_ENABLE_CRYPTOGAMS_GEN    (1<<SHA1_USING_CRYPTOGAMS_GEN)
#define SHA1_ENABLE_CRYPTOGAMS_SSSE3  (1<<SHA1_USING_CRYPTOGAMS_SSSE3)
#define SHA1_ENABLE_CRYPTOGAMS_SHAEXT (1<<SHA1_USING_CRYPTOGAMS_SHAEXT)
#define SHA1_ENABLE_DISPATCH          (1<<SHA1_USING_DISPATCH)

#define SHA1_DESC_GENERIC             "llhash (C)"
#define SHA1_DESC_NATIVE              "llhash (C, -march=native)"
#define SHA1_DESC_NAYUKI64            "Nayuki (x64 asm)"
#define SHA1_DESC_INTEL_SSSE3         "Intel SSSE3 (x64 asm)"
#define SHA1_DESC_INTEL_AVX           "Intel AVX (x64 asm)"
#define SHA1_DESC_INTEL_AVX2          "Intel AVX2 (x64 asm)"
#define SHA1_DESC_INTEL_SHAEXT        "Intel SHA-NI (x64 asm)"
#define SHA1_DESC_CRYPTOGAMS_GEN      "Cryptogams Generic (x64 asm)"
#define SHA1_DESC_CRYPTOGAMS_SSSE3    "Cryptogams SSSE3 (x64 asm)"
#define SHA1_DESC_CRYPTOGAMS_SHAEXT   "Cryptogams SHA-NI (x64 asm)"
#define SHA1_DESC_DISPATCH            "Cryptogams SSSE3/Intel AVX2"
