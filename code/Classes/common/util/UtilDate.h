#pragma execution_character_set("utf-8")

#ifndef __COMMON_UTIL_UTIL_DATE_H__
#define __COMMON_UTIL_UTIL_DATE_H__

#include "cocos2d.h"

USING_NS_CC;

class UtilDate
{
public:
	//��ʽ��ʱ�䷵��
	static std::string getCurrentTime(const char *format);
	//��ȡϵͳ����ʱ��
	static double getMillSecond();
	//��ȡϵͳ��ʱ��
	static double getSecond();
	//����������ȡʱ���֣����ʽ�ַ�
	static std::string timeFormat(double value, bool isHourShow = true, bool isMinuteShow = true);
	//������ֵ������λ
	static std::string fullDouble(int value);
	
private:

};

#endif