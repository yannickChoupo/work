#ifndef UTILS_H_
#define UTILS_H_

#include "limits.h"
#include "stdint.h"
#include "cmath"
#include <iostream>
#include <string>

using namespace std;

#define ADDCALL __cdecl

#ifdef __cplusplus
extern "C"
{
#endif /* C++ */

#ifdef UTILS_EXPORTS
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

    /*void UTILS_API swap(int *a, int *b);
    long UTILS_API double summe(long double *f, int n);
    long UTILS_API double durchnitt(long double *f, int n);
    bool UTILS_API input(long double *f, int n);
    bool UTILS_APIoutput(long *f, long n);
    long UTILS_API maximum(long *f, long n);
    //UTILS_API long double maximum(long double *f, int n);
    void UTILS_API sort(long double *f, int n);

    
    int UTILS_API bits(unsigned long value);
    bool UTILS_API iseven(long value);
    void UTILS_API deztobin(unsigned long value);
    int UTILS_API groupSize(unsigned long value);
    unsigned UTILS_API long bitReverse(unsigned long value);
    unsigned UTILS_API long bitReverseX(unsigned long value);
    UTILS_API int ADDCALL bitPos(uint32_t value);*/
    UTILS_API void ADDCALL Hallo();

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* UTILS_H_ */