/**
  ******************************************************************************
  * @file    Fraction.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Fraction class
  * @encode  GB2312
  ******************************************************************************
  */

#include "Fraction.h"

/* Constructors & Deconstructor --------------------------------------------- */
Fraction::Fraction(int n, int d) {
	Set(n,d);
}

Fraction::Fraction(const Fraction& n) {
	m_nNum = n.m_nNum;
	m_nDen = n.m_nDen;
}

Fraction::~Fraction() {}

/* Private functions -------------------------------------------------------- */
/**
  * @brief 约分
  * @param None
  * @retval None
  */
void Fraction::Standardize() {
	if (m_nNum == 0)m_nDen = 1;
	else {
		int gcd = GCD(m_nNum, m_nDen);
		m_nNum /= gcd;
		m_nDen /= gcd;
	}
}
/* Exported functions ------------------------------------------------------- */

// 规定动作
void Fraction::Show()const {
	cout << *this;
}

void Fraction::Set(int n, int d) {
	if (d == 0) {
		//cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
		//	<< "分母不能为0"
		//	<< endl;
		//abort();
		throw "Den can’t be 0.";
	}
	m_nNum = n;
	m_nDen = d;
	Standardize();
}

/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Fraction& source : 待赋的值
  * @retval 无
  */
void Fraction::operator=(const Fraction& source) {
	m_nNum = source.m_nNum;
	m_nDen = source.m_nDen;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Fraction& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fraction& source) {
	if (source.m_nDen == 1) {
		out << source.m_nNum;
		return out;
	}
	else {
		out << source.m_nNum << "/" << source.m_nDen;
		return out;
	}
}

/**
  * @brief 重载等于运算符
  * @param const Fraction& n1 : 运算符左边的值
  * @param const Fraction& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Fraction& n1, const Fraction& n2) {
	if (n1.m_nNum != n2.m_nNum)return false;
	if (n1.m_nDen != n2.m_nDen)return false;
	return false;
}

/**
  * @brief 重载加法运算符
  * @param const Fraction& n1 : 加号左边的值
  * @param const Fraction& n2 : 加号右边的值
  * @retval n1 + n2
  */
Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief 重载负号
  * @param Fraction n : 值传递待取反的值
  * @retval -n
  */
Fraction operator-(Fraction n) {
	n.m_nNum = -n.m_nNum;
	return n;
}

/**
  * @brief 重载减法运算符
  * @param const Fraction& n1 : 减号左边的值
  * @param const Fraction& n2 : 减号右边的值
  * @retval n1 - n2
  */
Fraction operator-(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen - n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief 重载乘法运算符
  * @param const Fraction& n1 : 乘号左边的值
  * @param const Fraction& n2 : 乘号右边的值
  * @retval n1 * n2
  */
Fraction operator*(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nNum = n1.m_nNum * n2.m_nNum;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.Standardize();
	return f;
}

/**
  * @brief 重载除法运算符
  * @param const Fraction& n1 : 除号左边的值
  * @param const Fraction& n2 : 除号右边的值，不能为0
  * @retval n1 / n2
  */
Fraction operator/(const Fraction& n1, const Fraction& n2) {
	if (n2.m_nNum == 0) {
		//cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
		//	<< "除数不能为0"
		//	<< endl;
		//abort();
		throw "Can’t divide by 0 .";
	}
	Fraction f;
	f.m_nNum = n1.m_nNum * n2.m_nDen;
	f.m_nDen = n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief 辗转相除法求出两数的最大公因数，可接受负数，其中任一不能为零
  * @param n1, n2 : 非零整数
  * @retval 最大公因数
  */
int GCD(int n1, int n2) {
	if (n1 == 0 || n2 == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "参与最大公因数计算的数值不能为0"
			<< endl;
		abort();
	}
	if (n1 < 0)n1 = -n1;
	if (n2 < 0)n2 = -n2;
	if (n1 > n2)swap(n1, n2);// 保证  n1 < n2
	int n0;
	while (1) {
		if (n1 % n2 == 0)return n2;
		// GCD 步骤 滚动数组： 
		// 变量	n0	n1   n2   
		//		    a1 , a2 , a3 = a1%a2 , a4 = a2%(a1%a2) , ... , an = a(n-2)%a(n-1) , ... , GCD , 0
		// 数组向 <-- 方向移动
		n0 = n1;
		n1 = n2;
		n2 = n0 % n1;
	}
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
