#pragma once
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
/*食谱规则
四个食材（可重复）合成一个食物，而食材一共有42种，故有42^4共200多万种组合方式，由于不区分四个食材顺序，除去重复项，依旧有10余万种食材搭配。而已知的食物为30种。
有效的食材搭配远远超过30种（如果是一对一的关系，食物烹饪的可玩性自然会大幅降低），也就是说食物与食材是一个一对多的匹配。比如说：
1块肉和3个浆果  1*肉+3*浆果=肉丸
肉换成怪物肉      1*怪物肉+3*浆果=肉丸
一个浆果换成肉    2*肉+2*浆果=肉丸
一个浆果换成玉米  1*肉+2*浆果+1*玉米=肉丸
……
但是如果有3 个肉及以上，食物就变成了炖肉汤，有一个树枝则变成了烤串，有两个肉是怪物肉则变成了怪物千层饼。

尝试使用两层匹配来实现食谱，首先为食物与食材加入一个父类型，如肉、鸡腿、蛙腿属于肉系食材，肉丸、肉串、炖肉汤属于肉系食物。
通过食材类型激活食物类型，再在同一类型的几个食物中判定具体食物。如：

If meat()一个肉类型，激活肉系食物，初始值为肉丸，存在树枝则为肉串，存在3个肉则为炖肉汤
If honey()一个蜂蜜，激活糖系食物，初始为太妃糖，存在冰则激活为冰淇淋
两个怪物肉为怪物类型，则激活怪物系食物……
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