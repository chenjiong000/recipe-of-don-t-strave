#include "ds_recipe.h"
#include<array>
#include <algorithm>
using namespace std;
int regredientchecking(Cooking &c) {
	unordered_map <string, string>typechecking{
		{"meat","meattype"},{"froglegs","meattype"},{"twigs","filltype"},{"berries","berriestype"}
	};
	string errinfo = " is inedible!";
	for (int i = 0; i < 4; i++) {
		if (typechecking.find(c.regredients[i]) != typechecking.end())
			c.regredienttype[typechecking[c.regredients[i]]] += 1;
		else {
			cout << c.regredients[i] + errinfo<<endl;
			return 1;
		}
	}
	cout<<"cooking!"<<endl;
	return 0;
}
Cooking::Cooking(std::string s1, std::string s2, std::string s3, std::string s4) {
	regredients.push_back(s1);
	regredients.push_back(s2);
	regredients.push_back(s3);
	regredients.push_back(s4);
}
void Cooking::Food() {
	if (regredienttype["meattype"] > 0 && regredienttype["honeytype"] > 0) //最多两种食材决定食物种类，两种之外的食材视为填充物
		cout<<HoneyMeattype();                                            //存在食材重叠的食物，按if语句从上至下优先级递减
	else if (regredienttype["monsttype"] >= 2)
		cout << Monsttype();
	else if (regredienttype["meattype"] > 0)
		cout << Meattype();
	else if (regredienttype["berriestype"] >= 0)
		cout << Berriestype();
	
}
string Cooking::HoneyMeattype() {
	array < string, 2 > food={"honeyham", "honeynuggets", };
	string s_food = food[0];
	if (regredienttype["meattype"] >= 3)
		s_food = food[1];
	return s_food;
}
string Cooking::Meattype() {
	array < string, 4 > food = { "meatballs", "bonestew","kabobs","frogglebunwich" };
	string s_food = food[0];
	if (find(regredients.begin(), regredients.end(), "twigs") != regredients.end())
		s_food = food[2];
	else if (find(regredients.begin(), regredients.end(), "froglegs") != regredients.end())
		s_food = food[3];
	else if(regredienttype["meattype"] >= 3)
		s_food = food[1];
	return s_food;
}
string Cooking::Monsttype() {
	array < string, 2 > food = { "honeyham", "honeynuggets", };
	return food[0];
}
string Cooking::Berriestype() {
	array < string, 2 > food = { "honeyham", "honeynuggets", };
	return food[0];
}