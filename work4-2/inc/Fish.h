/**
  ******************************************************************************
  * @file    Fish.h
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-04-25
  * @brief   Fish class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FISH_H
#define __FISH_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Fish {
private:
	string m_strName;
	string m_strColor;
	int m_nWeight;
	int m_nLastFedDey;
	bool m_bAlive;
	
	static int s_nTotal;
	static int s_nAlive;
	static int s_nCurrentDay;

public:
	static void nextDay();
	static int getCurrentDay();
	static int getTotal();
	static int getAlive();

	// Constructors & Deconstructor
	Fish();
	Fish(string t_strName, string t_strColor);
	~Fish();

	void update(bool isFed);

	// Getter & Setter
	string getName()const;
	string getColor()const;
	int getWeight()const;
	int getLastFedDey()const;
	bool isAlive()const;
	void set(string t_strName, string t_strColor);

	// ���������
	friend ostream& operator<<(ostream& out, const Fish& source);
};
/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Fish& source);
#endif /* !__FISH_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
