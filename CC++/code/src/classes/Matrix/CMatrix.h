//
// Created by Thinkpad_T460s on 01.11.2020.
//

#ifndef MATRIX_CMATRIX_H
#define MATRIX_CMATRIX_H
#include  "iostream"
#include "CCounter.h"
#include "cstdlib"
enum INI_MODE {INIT_ZEROS , INIT_UNIT , INIT_RAND};
using namespace std;

class CMatrix {
private:
    int m_M;
    int m_N;
    int m_size;
    int *m_pA;
    CCounter counter;
public:

    CMatrix(int M=2,int N=2);
    CMatrix(int dim=2 , INI_MODE mode=INIT_ZEROS);
    CMatrix(const CMatrix &orig);
    ~CMatrix();
    void getDimension(int &M,int &N);
    bool setElementAt(int m,  int n ,int  value);
    void mulMatrix(int factor);
    int getArrayIndex(int m,int n);
    void operator *= (int rop);
    CMatrix& operator = ( CMatrix &rOp);
    CMatrix operator + (const CMatrix &rOp) const;
    CMatrix operator * (const CMatrix &rOp) const;
    void print();
    int getElementAt(int m, int n, bool &bRet);
    friend ostream& operator << (ostream& lOp,CMatrix& rOp);
};


#endif //MATRIX_CMATRIX_H
