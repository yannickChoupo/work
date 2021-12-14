//
// Created by Thinkpad_T460s on 01.11.2020.
//

#ifndef MATRIX_CCOUNTER_H
#define MATRIX_CCOUNTER_H


class CCounter {
private:
    int m_nCount;
    int m_nStart;
    int m_nMax;
    int m_nDirection;
    char *m_pName;
public:
    ~CCounter();
    CCounter(char *pName = nullptr ,int nStart = 1, int nMax =10000, int nDirection = 1);
    void setName(char *pName);
    void setMax(int x);
    bool count();
    void reset();
    int getCount();
    void print();
};


#endif //MATRIX_CCOUNTER_H
