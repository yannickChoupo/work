//
// Created by Thinkpad_T460s on 01.11.2020.
//

#include "CCounter.h"
#include "iostream"
using namespace std;

CCounter::CCounter(char *pName, int nStart, int nMax, int nDirection) {
    /*cout<<"objekt adresse "<<this<<endl;
    cout<<"m_nCount :"<<m_nCount<<" -Adresse : "<<&m_nCount<<endl;
    cout<<"m_nMax :"<<m_nMax<<endl;
    cout<<"m_nStart :"<<m_nStart<<endl;
    cout<<"m_Direction :"<<m_nDirection<<endl;
    m_pName=pName;
    cout<<"m_nPname :" <<&m_pName<<endl;
    cout<<"Pname :" <<&pName<<endl;*/
    if(nDirection<=0){
        m_nDirection=-1;
    } else{
        m_nDirection=1;
    }
    if(nMax>=1 && nMax<=10000*m_nDirection)
    {
        m_nMax=m_nDirection*nMax;
    }else{
        m_nMax=100000;
    }
    if(nStart<nMax && nStart>0){
       m_nStart=nStart;
    }else{
        m_nStart=1;
    }
    m_nCount =m_nStart;
    this->setName(pName);
}
void CCounter::setName(char *pName) {
    if(pName == nullptr){
        m_pName = nullptr;
    }else{
        int len=0;
        for(char *temp=pName;*temp!='\0';*temp++)
        {
            len++;
        }
        cout<<"aktuelle groesse des Arrays "<<len<<endl;
        m_pName = new char[len+1];
        for(int i=0;i<len;i++){
            m_pName[i]=pName[i];
        }
    }
}


bool CCounter::count() {
    m_nCount++;
    if(m_nCount>m_nMax){
        this->reset();
        return false;
    }
    return true;
}


void CCounter::reset() {
    m_nCount = m_nStart;
}

int CCounter::getCount() {
    return m_nCount;
}

void CCounter::print() {
    cout<<"Counter-name : ";
    if(m_pName == nullptr){
        cout<<"no-name";
    }else{
        for(char *temp=m_pName;*temp!='\0';*temp++)
        {
            cout<<*temp;
        }
    }
    cout<<endl;
    cout<<"m_nMax :"<<m_nMax<<endl;
    cout<<"m_nStart :"<<m_nStart<<endl;
    cout<<"m_nCount :"<<m_nCount<<endl;

}
CCounter::~CCounter() {
    delete [] m_pName;
}

void CCounter::setMax(int x) {
    m_nMax=x;
}



