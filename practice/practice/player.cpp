#include<iostream>
#include"player.h"
void Player::printHealth() {
	std::cout << "Health = " << health << std::endl;
}
Player::~Player() {
	std::cout << "Player Destroyed" << std::endl;
}
