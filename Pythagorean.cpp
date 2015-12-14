#include <iostream>
#include "Pythagorean.h"
std::ostream& Pythagorean::operator()(int limit, std::ostream& os){
	int shorter;
	int longer;
	int hypotenuse;
	unsigned int loops = 0;  // loops count
	int valid = 0;  // valid data
	// shorter < longer < hypotenuse
	int powLimit = limit*limit;
	// shorter < limit
	// 最短边，初始值是 1，最大值是limit，递增
	for(shorter = 1; shorter <= limit; shorter++){
		// 第二条直角边，初始值是最短边+1,
		for(longer = shorter + 1;(longer*longer)+(shorter*shorter)<= powLimit; longer++){
			// 两条直角边各自平方后相加
			int sumPow = shorter*shorter + longer*longer;
			// 斜边，初始值 更长的直角边+1，
			for(hypotenuse = longer + 1; ++loops && hypotenuse <= limit; hypotenuse++){
				if(sumPow == hypotenuse*hypotenuse){
					valid++;
					os << shorter << ','
					<< longer << ','
					<< hypotenuse << ";\n";
				}
				else if(sumPow < hypotenuse*hypotenuse){
					break;
				}
			}
		}
	}
	os << std::endl;
	os << loops << " loops are executed." << std::endl;
	os << valid << " valid data found." << std::endl;
	return os;
}
