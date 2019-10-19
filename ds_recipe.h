#pragma once
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

class Cooking {                //½öÖÖÀà
	friend std::string regredientchecking(Cooking &c);
private:
	std::unordered_map<std::string, unsigned int> regredienttype;
	std::vector<std::string> regredients;
public:
	Cooking() {
		regredienttype.insert({ std::string("meattype") ,0 });
		regredienttype.insert({ std::string("fishtype") ,0 });
		regredienttype.insert({ std::string("monsttype") ,0 });
		regredienttype.insert({ std::string("berriestype") ,0 });
		regredienttype.insert({ std::string("twigstype") ,0 });
		regredienttype.insert({ std::string("honeytype") ,0 });
	};
	Cooking(std::string s1, std::string s2, std::string s3, std::string s4);
	std::string getinfo() { std::cout <<"mnum"<< regredienttype["meattype"]; return regredients[1]; }

};
std::string regredientchecking(Cooking &c);