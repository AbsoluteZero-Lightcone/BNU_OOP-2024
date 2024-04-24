/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;

class Fish{};

int random() {
    time_t now;
    time(&now);
    srand(now);
    return rand();
}

bool isContinue() {
    string command;
    cout << "��Ҫ����������(Y/N) : ";
    cin >> command;
    if (command == "y" || command == "Y")
        return 1;
    else if (command == "n" || command == "N")
        return 0;
    else {
        cerr << "Invalid command." << endl;
        return isContinue();
    }
}

int main(){
    do {
        cout << "��Ҫ�������㣨N>=5��: ";
        int N;
        cin >> N;
        Fish** fish = new Fish * [N];
        string name, color;
        for (int i = 0; i < N; i++) {
            cout << "�������" << i + 1 << "��������֡���ɫ��";
            cin >> name >> color;
            fish[i] = new Fish(name, color);
        }
        cout << "��ʼ�����ˣ�" << endl;
        int day = 1;
        cout << "��" << day << "�죺";
        fish[random() % N]->eat();
    } while (isContinue());
    return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/