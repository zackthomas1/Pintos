#include <stdint.h>

#define F 16384     /* 1 in the fix-point format */

int tofxpt(int); 
int tointfloor(int); 
int tointround(int);
int addint(int, int); 
int addfx(int, int); 
int subint(int, int); 
int subfx(int, int); 
int multint(int, int); 
int multfx(int, int); 
int divint(int, int); 
int divfx(int, int);

/* Convert int n to fix-point. */
int 
tofxpt(int n)
{
    return n * F;
} 

/* Convert fix-point x to int (rounding toward zero). */
int 
tointfloor(int x)
{
    return x / F;
}

/* Convert fix-point x to int (rounding to nearest). */
int 
tointround(int x)
{ 
    if (x >= 0)
        return (x + F / 2) / F;
    else    
        return (x - F / 2) / F; 
}

/* Add int n to fix-point x. */
int 
addint(int x, int n)
{
    return x + (n * F);
} 

/* Add fix-point y to fix-point x. */
int 
addfx(int x, int y)
{
    return x + y;
}

/* Subtract int n from fix-point x. */
int
subint(int x, int n)
{
    return x - (n * F);
}

/* Subtract fix-point y from fix-point x. */
int 
subfx(int x, int y)
{
    return x - y;
}

/* Multiple fix-point x by int n. */
int 
multint(int x, int n)
{
    return (int64_t)x * n;
}

/* Multiple fix-point x by fix-point y. */
int 
multfx(int x, int y)
{
    return ((int64_t)x) * y / F;
}

/* Divide fix-point x by int n.*/
int 
divint(int x, int n)
{
    return (int64_t)x / n;
}

/* Divide fix-point x by fix-point y. */
int 
divfx(int x, int y)
{
    return ((int64_t)x) * F / y;
}