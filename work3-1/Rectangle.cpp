/**
  ******************************************************************************
  * @file    Rectangle.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Rectangle.h"

/* Constructors & Deconstructor --------------------------------------------- */
Rectangle::Rectangle() :
	m_pointCenter(0, 0),
	m_dWidth(1),
	m_dHeight(1)
{}

Rectangle::Rectangle(Point t_pointCenter, double t_dWidth, double t_dHeight) :
	m_pointCenter(t_pointCenter),
	m_dWidth(t_dWidth),
	m_dHeight(t_dHeight)
{}

Rectangle::Rectangle(const Rectangle& source) :
	m_pointCenter(source.m_pointCenter),
	m_dWidth(source.m_dWidth),
	m_dHeight(source.m_dHeight)
{}

Rectangle::~Rectangle() {}

/* Getters & Setters -------------------------------------------------------- */
Point Rectangle::getCenter()const { return m_pointCenter; }
void Rectangle::setCenter(Point t_pointCenter) { m_pointCenter = t_pointCenter; }
double Rectangle::getWidth()const { return m_dWidth; }
void Rectangle::setWidth(double t_dWidth) { m_dWidth = t_dWidth; }
double Rectangle::getHeight()const { return m_dHeight; }
void Rectangle::setHeight(double t_dHeight) { m_dHeight = t_dHeight; }

/**
  * @brief 返回矩形的主对角线
  * @param 无
  * @retval 矩形的主对角线
  */
Line Rectangle::getDiagonal()const {
	return Line(
		Point(m_pointCenter.m_dCoordinateX - m_dWidth / 2, m_pointCenter.m_dCoordinateY - m_dHeight / 2),
		Point(m_pointCenter.m_dCoordinateX + m_dWidth / 2, m_pointCenter.m_dCoordinateY + m_dHeight / 2)
	);
}

/**
  * @brief 通过主对角线给矩形对象赋值
  * @param const Line& Diagonal : 矩形的主对角线
  * @retval 无
  */
void Rectangle::setDiagonal(const Line& Diagonal) {
	m_dWidth = abs(Diagonal.m_pointP1.m_dCoordinateX - Diagonal.m_pointP2.m_dCoordinateX);
	m_dHeight = abs(Diagonal.m_pointP1.m_dCoordinateY - Diagonal.m_pointP2.m_dCoordinateY);
	m_pointCenter.setXY(
		(Diagonal.m_pointP1.m_dCoordinateX + Diagonal.m_pointP2.m_dCoordinateX) / 2,
		(Diagonal.m_pointP1.m_dCoordinateY + Diagonal.m_pointP2.m_dCoordinateY) / 2
	);
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 求面积
  * @param 无
  * @retval 面积
  */
double Rectangle::area()const {
	return m_dWidth * m_dHeight;
}

/**
  * @brief 求周长
  * @param 无
  * @retval 周长
  */
double Rectangle::perimeter()const {
	return (m_dWidth + m_dHeight) * 2;
}

/**
  * @brief 长宽可以为0，但为零时不构成矩形，用此函数判断是否能构成矩形
  * @param 无
  * @retval bool, 1 for 能构成矩形
  */
bool Rectangle::isRectangle()const {
	if (m_dWidth == 0 || m_dHeight == 0)return false;
	return true;
}

/**
  * @brief 移动矩形
  * @param double dx, double dy : 偏移量
  * @retval 无
  */
void Rectangle::offset(double dx, double dy) {
	m_pointCenter.m_dCoordinateX += dx;
	m_pointCenter.m_dCoordinateY += dy;
}

Shape InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	double center_dx, center_dy;
	center_dx = abs(n1.m_pointCenter.m_dCoordinateX - n2.m_pointCenter.m_dCoordinateX);
	center_dy = abs(n1.m_pointCenter.m_dCoordinateY - n2.m_pointCenter.m_dCoordinateY);
	if (n1.m_dWidth / 2 + n2.m_dWidth / 2 > center_dx || n1.m_dHeight / 2 + n2.m_dHeight / 2 > center_dy)return Empty();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == center_dx && n1.m_dHeight / 2 + n2.m_dHeight / 2 == center_dy)return Point();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == center_dx)return Line();
	else if (n1.m_dHeight / 2 + n2.m_dHeight / 2 == center_dy)return Line();
	else return Rectangle();
}

/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Rectangle& source : 待赋的值
  * @retval 无
  */
void Rectangle::operator=(const Rectangle& source) {
	m_pointCenter = source.m_pointCenter;
	m_dWidth = source.m_dWidth;
	m_dHeight = source.m_dHeight;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Rectangle& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Rectangle& source) {
	out << "Rect(" << source.getDiagonal() << ")";
	return out;
}

/**
  * @brief 重载等于运算符
  * @param const Rectangle& n1 : 运算符左边的值
  * @param const Rectangle& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Rectangle& n1, const Rectangle& n2) {
	if (n1.m_pointCenter != n2.m_pointCenter)return false;
	if (n1.m_dWidth != n2.m_dWidth)return false;
	if (n1.m_dHeight != n2.m_dHeight)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
