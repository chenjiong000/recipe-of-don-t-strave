#pragma once
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
/*ʳ�׹���
�ĸ�ʳ�ģ����ظ����ϳ�һ��ʳ���ʳ��һ����42�֣�����42^4��200��������Ϸ�ʽ�����ڲ������ĸ�ʳ��˳�򣬳�ȥ�ظ��������10������ʳ�Ĵ��䡣����֪��ʳ��Ϊ30�֡�
��Ч��ʳ�Ĵ���ԶԶ����30�֣������һ��һ�Ĺ�ϵ��ʳ����⿵Ŀ�������Ȼ�������ͣ���Ҳ����˵ʳ����ʳ����һ��һ�Զ��ƥ�䡣����˵��
1�����3������  1*��+3*����=����
�⻻�ɹ�����      1*������+3*����=����
һ������������    2*��+2*����=����
һ��������������  1*��+2*����+1*����=����
����
���������3 ���⼰���ϣ�ʳ��ͱ��������������һ����֦�����˿��������������ǹ����������˹���ǧ�����

����ʹ������ƥ����ʵ��ʳ�ף�����Ϊʳ����ʳ�ļ���һ�������ͣ����⡢���ȡ�����������ϵʳ�ģ����衢�⴮��������������ϵʳ�
ͨ��ʳ�����ͼ���ʳ�����ͣ�����ͬһ���͵ļ���ʳ�����ж�����ʳ��磺

If meat()һ�������ͣ�������ϵʳ���ʼֵΪ���裬������֦��Ϊ�⴮������3������Ϊ������
If honey()һ�����ۣ�������ϵʳ���ʼΪ̫���ǣ����ڱ��򼤻�Ϊ�����
����������Ϊ�������ͣ��򼤻����ϵʳ���
*/
class Cooking {                
	friend int regredientchecking(Cooking &c);
private:
	std::unordered_map<std::string, unsigned int> regredienttype;
	std::vector<std::string> regredients;
public:
	Cooking() {
		regredienttype.insert({ std::string("meattype") ,0 });
		regredienttype.insert({ std::string("fishtype") ,0 });
		regredienttype.insert({ std::string("monsttype") ,0 });
		regredienttype.insert({ std::string("berriestype") ,0 });
		regredienttype.insert({ std::string("honeytype") ,0 });
	};
	Cooking(std::string s1, std::string s2, std::string s3, std::string s4);
	void Food();
	std::string HoneyMeattype();
	std::string Meattype();
	std::string Monsttype();
	std::string Berriestype();
};
int regredientchecking(Cooking &c);