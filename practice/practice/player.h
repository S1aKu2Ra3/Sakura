#pragma once
class Player {          //定义玩家类
public:
	int health{ 100 };  //定义player数据

	void printHealth();      //定义player 功能
	~Player();
};