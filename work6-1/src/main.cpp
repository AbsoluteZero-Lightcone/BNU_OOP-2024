/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "WorldClock.h"

int main() {
	bool isOver = 0;
	while (!isOver) {
		cout << "Conversion / Subtraction / End :";
		char mode;
		cin >> mode;
		switch (mode) {
		case 'c': {
			string city, targetCity;
			int h, m, s;
			cout << "Input City:";
			cin >> city;
			cout << "Input hour minute second:";
			cin >> h >> m >> s;
			cout << "Input Conversion City:";
			cin >> targetCity;
			WorldClock c(h, m, s, city);
			cout << "Time is  " << c << endl;
			cout << "		 " << c.toRegion(targetCity) << endl;
			break;
		}
		case 's': {
			string city;
			int h, m, s;
			cout << "Input City:";
			cin >> city;
			cout << "Input hour minute second:";
			cin >> h >> m >> s;
			WorldClock c1(h, m, s, city);
			cout << "Input City:";
			cin >> city;
			cout << "Input hour minute second:";
			cin >> h >> m >> s;
			WorldClock c2(h, m, s, city);
			cout << c1 << " – " << c2 << " = " << c1 - c2 << endl;
			// 此处样例使用的是" – "符号而非" - "符号，这里按样例来
			break;
		}
		case 'e':
			cout << "Byebye~" << endl;
			isOver = 1;
			break;
		default:
			cerr << "Invaild Command." << endl;
			break;
		}
	}
	return 0;
}
/*
* 样例：
Conversion / Subtraction / End : c
Input City: bj
Input hour minute second:  20 30 45
Input Conversion City: sy
Time is  Bejing 20:30:45
		 Sydney 22:30:45
Conversion / Subtraction / End : s
Input City: bj
Input hour minute second:  20 30 45
Input City: ld
Input hour minute second:  10 25 5
Beijing 20:30:45 – London 10:25:05 = Beijing 02:05:40
Conversion / Subtraction / End : c
Input City: ca
Input hour minute second:  8 12 50
Input Conversion City: ha
Time is Cario 08:12:50
		Hawaii 20:12:50
Conversion / Subtraction / End : s
Input City: bk
Input hour minute second:  15 26 30
Input City: ny
Input hour minute second:  18 55 5
Bangkok 15:26:30 – NewYork 18:55:05 = Bangkok 08:31:25
Conversion / Subtraction / End : e
Byebye~

*/
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
