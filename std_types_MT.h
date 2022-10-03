/************************************************/
/* Title       : NTI Embedded C final project   */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : August 11, 2022                */
/************************************************/
/************************Standard data types file*************************/
#ifndef STD_TYPES_MT_H_
#define STD_TYPES_MT_H_

typedef unsigned char uint8;
typedef char sint8;
typedef unsigned short uint16;
typedef short sint16;
typedef unsigned long uint32;
typedef long sint32;
typedef unsigned char boolean;
typedef float FB32;
typedef double FB64; 
typedef char * ptr2char;

typedef unsigned char       u8 ; 
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;

typedef signed char         s8 ;
typedef signed short int    s16;
typedef signed long int     s32;

typedef float               f32;
typedef double              f64;
typedef long double         f96;

#define BYTE sint8
#define TRUE 1
#define FALSE 0

#define FAILURE  0
#define SUCESS   1
#endif /* STD_TYPE_H_ */
