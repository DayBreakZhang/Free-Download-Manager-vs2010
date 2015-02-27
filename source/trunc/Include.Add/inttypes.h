#ifndef __INTTYPES_H_
#define __INTTYPES_H_

/* Use [u]intN_t if you need exactly N bits.
   XXX - doesn't handle the -mint8 option.  */

typedef signed char int8_t;
typedef unsigned char uint8_t;
 
typedef int int16_t;
typedef unsigned int uint16_t;
 
typedef long int32_t;
typedef unsigned long uint32_t;
 
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
 
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;

typedef __int64 int64_t_C;
 
#endif
