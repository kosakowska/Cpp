//by Małgorzata Kosakowska
#include "Player.h"
#include <iostream>

string Player::Get_name() const { return name; }
string Player::Get_surname() const { return surname; }
int Player::Get_age() const { return age; }
int Player::Get_height() const { return height; }

Player::Volley_position Player::Get_position() const { return pos; }


void Player::Set_name(string n) { name = n; }
void Player::Set_surname(string s) { surname = s; }
void Player::Set_age(int a) { age = a; }
void Player::Set_height(int h) { height = h; }

void Player::Set_position(Volley_position p) { pos = p; }


