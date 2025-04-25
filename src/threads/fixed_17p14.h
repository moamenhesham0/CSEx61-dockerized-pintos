#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H


typedef int fixed_17p14_t;
typedef long long int64_t;

#define PERCISION 14

// int -> fixed_point
#define CONVERT_TO_FIXED_POINT(int_) ((fixed_17p14_t)(int_ << PERCISION))

// fixed_point -> int
#define CONVERT_TO_INT(fp_) ((int)(fp_ >> FP))

// round(fixed_point) -> int
#define CONVERT_TO_INT_ROUNDING(fp_) ((fp_  +(fp_>=0? (1 << PERCISION-1): -(1 << PERCISION-1))) >> PERCISION)

// Adds two fixed points -> fp
#define ADD_FIXED_POINTS(fp_1  , fp_2) (fp_1 + fp_2)

// Subtracts two fixed points -> fp
#define SUBTRACT_FIXED_POINTS(fp_1  , fp_2) (fp_1 - fp_2)

// Adds a fixed_point to an int -> fp
#define ADD_FIXED_POINT_TO_INT(fp_ , int_) (fp_ + CONVERT_TO_FIXED_POINT(int_))

// Subtracts an int from a fixed_point  -> fp
#define SUBTRACT_INT_FROM_FIXED_POINT(fp_ , int_) (fp_ - CONVERT_TO_FIXED_POINT(int_))

// Subtracts a fixed_point from an int  -> int
#define SUBTRACT_FIXED_POINT_FROM_INT(fp_ , int_) (CONVERT_TO_FIXED_POINT(int_) - fp_)

// Multiplies two fixed_points -> fp
#define MULTIPLY_FIXED_POINTS(fp_1 , fp_2) ((fixed_17p14_t)((int64_t)fp_1 * CONVERT_TO_INT(fp_2)))

// Multiplies a fixed_point with an int -> int
#define MULTIPLY_INT_BY_FIXED_POINT(fp_ , int_) (fp_ * int_)

// Divides a fixed_point by a fixed_point -> fp
#define DIVIDE_FIXED_POINTS(fp_1 , fp_2) ((fixed_17p14_t)(((int64_t)fp_1  << PERCISION) * (fp_2)))

// Divides a fixed_point by an int -> fp
#define DIVIDE_FIXED_POINT_BY_INT(fp_ , int_) (fp_ / int_)


#endif