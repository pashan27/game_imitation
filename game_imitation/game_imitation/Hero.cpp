#include "Hero.h"

//����������� � �����������
Hero::Hero(std::string name, int hp,int damage)
{
	//������������ id ������
	++counter;
	id = counter;

	//��������� ��������� �������
	this->name = name;
	this->hp = hp;
	this->damage = damage;
}

Hero::Hero()
{
}

int Hero::get_id()
{
	return this->id;
}

std::string Hero::get_name()
{
	return this->name;
}

int Hero::get_hp()
{
	return this->hp;
}

int Hero::get_damage()
{
	return this->damage;
}

Hero Hero::operator=(Hero other)
{
	this->name = other.name;
	this->damage = other.damage;
	this->hp = other.hp;
	return *this;
}

std::string Hero::get_info()
{
	return std::to_string(id)+"\t"+name+"\t"+std::to_string(hp)+"\t"+ std::to_string(damage);
}

//������������ ������� ��������� ��'����
int Hero::counter = 0;

bool operator==(Hero& first, Hero& other)
{
	return first.name == other.name&& first.damage == other.damage&& first.hp == other.hp;
}