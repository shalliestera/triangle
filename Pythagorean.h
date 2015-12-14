#ifndef PYTHAGOREAN_H_
#define PYTHAGOREAN_H_
#include <iostream>
class Pythagorean {
public:
	// 打印出边长小于 n 的符合勾股定理的三角形的三边长度
	// print right triangles' sides (sides < n)
	// 可以指定输出流，默认为std::cout
	std::ostream& operator()(int n, std::ostream& os = std::cout);
};

#endif // PYTHAGOREAN_H_
