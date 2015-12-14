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
	// ��̱ߣ���ʼֵ�� 1�����ֵ��limit������
	for(shorter = 1; shorter <= limit; shorter++){
		// �ڶ���ֱ�Ǳߣ���ʼֵ����̱�+1,
		for(longer = shorter + 1;(longer*longer)+(shorter*shorter)<= powLimit; longer++){
			// ����ֱ�Ǳ߸���ƽ�������
			int sumPow = shorter*shorter + longer*longer;
			// б�ߣ���ʼֵ ������ֱ�Ǳ�+1��
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
