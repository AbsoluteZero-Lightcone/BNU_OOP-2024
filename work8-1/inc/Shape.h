/**
  ******************************************************************************
  * @file    Shape.h
  * @author  ���෨ 202311998186
  * @date    2024-04-19
  * @brief   Shape ����
  ******************************************************************************
  */
#ifndef __SHAPE_H
#define __SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
public:

	Shape() {}
	virtual ~Shape() {}

	void GetInfo() const {
		cout << "����һ��";
		Show();
		cout << "���������" << Area() << endl;
		cout << "�����ܳ���" << Perimeter() << endl;
	}
	virtual void Show()const = 0;
	virtual double Area()const = 0;
	virtual double Perimeter()const = 0;

};

#endif // !__SHAPE_H

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/