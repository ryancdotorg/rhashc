#pragma once

#define _COMPARE_RIPEMD160(x) x

#define RIPEMD160_DIGEST_LENGTH 20
#define RIPEMD160_BLOCK_LENGTH 64
#define RIPEMD160_WORD_SIZE 32
#define RIPEMD160_STATE_WORDS 5
#define RIPEMD160_ENDIAN __ORDER_LITTLE_ENDIAN__

#define RIPEMD160_IV { \
  0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0 \
}

#define RIPEMD160_IMPL_PRIO \
(native, NATIVE), \
(generic, GENERIC)

#define RIPEMD160_USING_GENERIC              0
#define RIPEMD160_USING_NATIVE               1

#define RIPEMD160_ENABLE_GENERIC             (1<<RIPEMD160_USING_GENERIC)
#define RIPEMD160_ENABLE_NATIVE              (1<<RIPEMD160_USING_NATIVE)

#define RIPEMD160_DESC_GENERIC               "llhash (C)"
#define RIPEMD160_DESC_NATIVE                "llhash (C, -march=native)"
