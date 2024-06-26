/**
  ******************************************************************************
  * @file    Fraction.h
  * @author  张亦法 202311998186
  * @date    2024-04-20
  * @brief   分数类型
  ******************************************************************************
  */

#ifndef __FRACTION_H
#define __FRACTION_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include "Sum.h"

/* Class ---------------------------------------------------------------------*/
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
	// 正负号给分子
	void Format();
public:
	Fraction(const Fraction& n);
	Fraction(int n = 0, int d = 1);
	~Fraction();


	// 规定动作
	void Show();
	void Add(Sum* num);

	friend ostream& operator<<(ostream& out, const Fraction& source);
	friend Fraction operator+(const Fraction& n1, const Fraction& n2);
};
ostream& operator<<(ostream& out, const Fraction& source);
Fraction operator+(const Fraction& n1, const Fraction& n2);

/* Exported functions ------------------------------------------------------- */
int GCD(int, int);

#endif // !__FRACTION_H

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
