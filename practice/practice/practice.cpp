//The fisrts practice of "add" function 
#include<iostream>
#include"math.h"
#include"player.h"
int main() {
	int result{ add(3 , 5) };
	std::cout << "reslut=" << result << std::endl;
	{
		Player player;
		player.printHealth();
	}
	return 0;
}