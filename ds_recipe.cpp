#include "ds_recipe.h"
using namespace std;
string regredientchecking(Cooking &c) {
	unordered_map <string, string>typechecking{
		{"meat","meattype"},{"froglegs","meattype"}
	};
	string errinfo = " is inedible!";
	for (int i = 0; i < 4; i++) {
		if (typechecking.find(c.regredients[i]) != typechecking.end())
			c.regredienttype[typechecking[c.regredients[i]]] += 1;
		else
			return c.regredients[i] + errinfo;

	}
	return "cooking!";
}
Cooking::Cooking(std::string s1, std::string s2, std::string s3, std::string s4) {
	regredients.push_back(s1);
	regredients.push_back(s2);
	regredients.push_back(s3);
	regredients.push_back(s4);
}