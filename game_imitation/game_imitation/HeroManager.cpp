#include "HeroManager.h"
#include "string"

//�����������
HeroManager::HeroManager()
{
	//������� 10 ����� � ���������� ������ 
	for (int i = 0; i < 10; ++i)
		heroes.push_back(Hero("hero" + std::to_string(i),rand()%100+1,rand()%100+1));
}

//��������� �����
Hero& HeroManager::create_hero()
{
	//��������� ���������� ����� � ������
	return heroes[rand()%heroes.size()];
}

//����� ����� �� ������
Hero* HeroManager::get_hero_by_name(std::string name)
{
	//������ ����� �� ��������� ��������� �� �����
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i].get_name() == name)
			return &heroes[i];

	//���� �� ���������, ��������� �������� ��������
	return nullptr;
}

//����� ������ �� id
Hero* HeroManager::get_hero_by_id(int id)
{
	//���� ������ id �� ����, ��������� �������� ��������
	if (id > heroes.size()||id<0)
		return nullptr;

	//������ ��������� ��������� �� �����
	return &heroes[id - 1];
}

//��������� �����
void HeroManager::delete_hero(Hero hero)
{
	//����������� �� ��� ������ �� ������ �������� �����
	for (int i = 0; i < heroes.size(); ++i)
		if (heroes[i] == hero)
		{
			//���� �������, ��������� ����
			heroes.erase(heroes.begin()+i);
			return;
		}
}

//���� ���������� ��� �����
void HeroManager::show_hero_info()
{
	//���� �� ����� ���������� ��� ��� �����
	for (int i = 0; i < heroes.size(); ++i)
		std::cout << heroes[i].get_info() << std::endl;
}

//����������
HeroManager::~HeroManager()
{
	//�������� ���'��
	heroes.clear();
}
