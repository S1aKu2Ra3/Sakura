//The fisrts practice of "add" function
#include<iostream>
int add(int a, int b) {      //定义函数
	return a + b;
}
int main() {
	int result{ add(3 , 5) };
	std::cout << "reslut=" << result << std::endl;
}