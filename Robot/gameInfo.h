#pragma once
#include <iostream>
#include <string>
#include "define.h"
class Card
{
public:
	std::string name;
	std::string explain;
	std::string behavior;
	int spend;
	int attack;
	int life;
	std::string type;
	int x, y;//λ��
	bool taugh;//�Ƿ񳰷�
	Card(){}
	/*Card(const Card& card)
	{
		name = card.name;
		explain = card.explain;
		behavior = card.behavior;
		spend = card.spend;
		attack = card.attack;
		life = card.life;
		type = card.type;
	}*/
};
class GameInfo
{
public:
	GameInfo()
	{
		state = STATE_SELFTURN_PLAY;
		currentSpend = 0;
	}
	STATE state;
	Card handCard[10];//���ƴ�С
	Card selfMonster[10];//�Լ����ϵ����
	Card otherMonster[10];//�Է��������
	int currentNum;//������Ŀ
	int selfMonsterNum;
	int otherMonsterNum;
	bool first;//�Ⱥ���
	int currentSpend;//��ǰˮ����
	int couldUseSpend;

};