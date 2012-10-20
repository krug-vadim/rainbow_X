#ifndef FIXMATH_H
#define FIXMATH_H

typedef int fix_t;
typedef long int fixd_t;

#define FIX_INT_SIZE   16U
#define FIX_INT_MAX    (1UL << FIX_INT_SIZE)
#define FIX_INT_MASK   (FIX_INT_MAX - 1)

#define FIX_FRACT_SIZE 8U
#define FIX_FRACT_MAX  (1UL << FIX_FRACT_SIZE)
#define FIX_FRACT_MASK (FIX_FRACT_MAX - 1)

#define FIX_MASK  (((FIX_INT_MASK)<<(FIX_FRACT_SIZE))|(FIX_FRACT_MASK))

#define FIX_INT(x)     (((x) >> FIX_FRACT_SIZE)&FIX_INT_MASK)
#define FIX_FRACT(x)   ((x)&FIX_FRACT_MASK)

#define FIX_FROM_INT(x) ((x)<<FIX_FRACT_SIZE)
#define FIX_TO_INT(x)   ((x)>>FIX_FRACT_SIZE)

#define FIX_ONE FIX_FROM_INT(1)

#define FIX_PI         0x200
#define FIX_PI_2       0x100
#define FIX_PI_4       0x080
#define FIX_ANGLE_MASK 0x3FF

fix_t fix_mod(fix_t, fix_t);
fix_t fix_add(fix_t, fix_t);
fix_t fix_sub(fix_t, fix_t);
fix_t fix_mul(fix_t, fix_t);
fix_t fix_div(fix_t, fix_t);

fix_t fix_sqrt(fix_t);

fix_t fix_sin(fix_t);
fix_t fix_cos(fix_t);

fix_t fix_atan(fix_t);
fix_t fix_atan2(fix_t, fix_t);

#endif // FIXMATH_H
