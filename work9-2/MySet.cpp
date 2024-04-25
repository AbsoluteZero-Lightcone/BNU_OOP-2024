/**
  ******************************************************************************
  * @file    MySet.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   MySet class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "MySet.h"

/* Constructors & Deconstructor --------------------------------------------- */
/**
  * @brief �޲ι��캯�����������ϣ���Ԫ�ظ�����Ϊ0.
  * @param None
  */
MySet::MySet() :_count(0) {}
MySet::MySet(const MySet & source) :_count(source._count) {
	for (int  i = 0; i < _count; i++){
		_array[i] = source._array[i];
	}
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief �����±������
  */
const int& MySet::operator[](unsigned i)const {
	// ���ﷵ�ص���const int& ����ҵ��Ҫ���Ƿ���int&���������������ɣ�
	// 1.���ﷵ��int&�����൱Σ�գ��൱��ֱ�ӱ�¶�����˽�г�Ա��
	//   ͨ�����ص�����������޸ļ���Ԫ��ʱ���޷���鼯����Ԫ�صĺϷ���
	// 2.ʹ��const���εĶ����޷�ʹ�÷�const�ĳ�Ա����
	if (i >= 0 && i < _count) {
		return _array[i];
	}
	else throw "Index Error.";
}

/**
  * @brief �ж�����x�Ƿ��Ǽ��ϵ�Ԫ��
  * @param int x
  * @retval bool
  */
bool MySet::IsInSet(int x) const{
	for (int i = 0; i < _count; i++)
		if (x == _array[i])
			return true;
	return false;
}

void MySet::append(int n) {
	if (!IsInSet(n)) {
		_array[_count] = n;
		_count++;
	}throw "is already in the set.";
}

/**
  * @brief �������϶���ļӷ����㡱+���������Ǻϲ���������
  */
MySet MySet::operator+(const MySet& n2) const{
	// n2 ��ֵ���ݸ�����һЩ�����ô�����ʱ����
	// ������ҵҪ���Ǵ������ã����ֵ���ݶ�һ�����ã�Ҳ����
	MySet temp(*this);
	for (int i = 0; i < n2._count; i++)
		if (!temp.IsInSet(n2[i])) {
			temp.append(n2[i]);
		}
	return temp;	
}

/**
  * @brief �������϶���ļ������㡱-�����������������1�еĲ����ڼ���2��Ԫ��
	��������Ҫ����ο�����ע�͡�
  */
MySet MySet::operator-(const MySet& n2) const{}

/**
  * @brief ���ϵġ�ǰ��++�����㣬�����ǽ������е�ÿһ��Ԫ������1��ǰ��������
  * @param
  * @retval
  */
MySet& MySet::operator++(){}
/**
  * @brief ���ϵġ�����++�����㣬�����ǽ������е�ÿһ��Ԫ������1������������
  * @param
  * @retval
  */
MySet MySet::operator++(int){}
/**
  * @brief ��Ԫ�����ϵġ�ǰ��--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1��ǰ���Լ���
  * @param
  * @retval
  */
MySet& operator--(MySet& source){}
/**
  * @brief ��Ԫ�����ϵġ�����--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1�������Լ���
  * @param
  * @retval
  */
MySet operator--(MySet& source, int){}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const MySet& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const MySet& source){
}
/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param MySet& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, MySet& target){
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/