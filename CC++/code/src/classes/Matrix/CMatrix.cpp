//
// Created by Thinkpad_T460s on 01.11.2020.
//
#include "iostream"
#include "CMatrix.h"
#include "iomanip"

using namespace std;
CMatrix::CMatrix(int M, int N) {
    if(M>0){
        m_M=M;
    } else{
        m_M=2;
    }
    if(N>0){
        m_N=N;
    } else{
        m_N=2;
    }
    m_size=m_M*m_N;
    m_pA = new int[m_size];
    for(int i=0;i<m_size;i++){
        m_pA[i]=0;
    }
    counter.setMax(m_N);
}

CMatrix::CMatrix(int dim, INI_MODE mode) {
    if(dim>0){
        m_N=dim;
        m_M=dim;
        m_size=m_M*m_N;
        counter.setMax(dim);

    }else{
        m_N=2;
        m_M=2;
        m_size=m_N*m_M;
        counter.setMax(4);
    }
    m_pA =new int[m_size];
        switch (mode) {
            case INIT_ZEROS:
                for(int i=0;i<m_size;i++){
                    m_pA[i]=0;
                }
                break;
            case INIT_UNIT:
                for(int i=0;i<m_M;i++){
                    for(int j=0;j<m_N;j++){
                        if(i==j){
                            this->setElementAt(i,j,1);
                        }else{
                            this->setElementAt(i,j,0);
                        }
                    }
                }
                break;
            case INIT_RAND:
                for(int i=0;i<m_size;i++){
                    m_pA[i]=rand() %9 + 1;
                }
                break;
        }

}

CMatrix::CMatrix(const CMatrix &orig) {
    m_pA = new int[orig.m_size];
    for(int i=0;i<orig.m_size;i++){
        m_pA[i]=orig.m_pA[i];
    }
    m_M=orig.m_M;
    m_N=orig.m_N;
    m_size=orig.m_size;
    counter.setMax(orig.m_N);
}

int CMatrix::getElementAt(int m, int n, bool &bRet) {
    if(m<=m_M&&n<=m_N){
        bRet=true;
        return *(m_pA+(m-1)*m_N+n-1);
    } else{
        bRet=false;
        return 0;
    }
}
bool CMatrix::setElementAt(int m, int n, int value) {
    if(m>m_M||n>m_N){
        return false;
    }
    *(m_pA+m*m_N+n)=value;
    return true;
}

void CMatrix::print() {
    cout<<"("<<m_M<<"x"<<m_N<<") -CMatrix @"<<this<<": m_pA @"<<m_pA<<"( Groesse "<<m_size<<" Elemente )"<<endl;
    for(int i=0;i<m_size;i++){
        if(counter.getCount()==m_N){
            cout<<setw(2)<<m_pA[i]<<"|\n";
        }else{
            cout<<setw(2)<<m_pA[i]<<"|";
        }
        counter.count();
    }
}
ostream& operator << (ostream& lOp,CMatrix& rOp){
    lOp<<"("<<rOp.m_M<<"x"<<rOp.m_N  <<") -CMatrix @"<<&rOp<<endl;
    for(int i=0;i<rOp.m_size;i++){
        if(rOp.counter.getCount()==rOp.m_N){
            lOp<<setw(2)<<rOp.m_pA[i]<<"|\n";
        }else{
            lOp<<setw(2)<<rOp.m_pA[i]<<"|";
        }
        rOp.counter.count();
    }
    lOp<<endl;
    return lOp;
}

CMatrix::~CMatrix() {
    delete [] m_pA;
}

void CMatrix::mulMatrix(int factor) {
    for(int i=0;i<m_size;i++){
        int x=m_pA[i]*factor;
        m_pA[i]=x;
    }
}

void CMatrix::operator*=(int rop) {
    for(int i=0;i<m_size;i++){
        m_pA[i]*=rop;
    }
}

CMatrix &CMatrix::operator=(CMatrix &rOp) {
    if(m_size!=rOp.m_size){
        cout<<"veraendere groesse der Matrix !"<<endl;
        cout<<*this<<endl;
    }else{
        for(int i=0;i<rOp.m_size;i++){
            m_pA[i]=rOp.m_pA[i];
        }
    }
    return *this;
}

void CMatrix::getDimension(int &M, int &N) {
    M=m_M;
    N=m_N;
}

CMatrix CMatrix::operator+(const CMatrix &rOp) const {
    if(m_N!=rOp.m_N||m_M!=rOp.m_M){
        cout<<"Addition nicht moglich...."<<endl;
        return *this;
    }
    for(int i=0;i<m_size;i++){
        m_pA[i]+=rOp.m_pA[i];
    }
    return *this;
}


