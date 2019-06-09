#ifndef CMONSTER_H
#define CMONSTER_H

#include <random>

#include "CGameMap.h"
#include "CHero.h"

//class Gamemap;
//class CHero;

namespace game_framework {
	class CMonster
	{
	public:
		CMonster() 
		{
			//throw("This Monster Don't Have HP!");
		};
		CMonster(int hp) 
		{
			_hp = hp;
		};
		~CMonster() {};
		virtual int Skill(int counter) = 0;			// �ޯ�
		virtual void Initialize() = 0;				// �]�w�Ǫ�����l��
		virtual void LoadBitmap() = 0;				// ���J�ϧ�
		virtual void HitAnimation(int counter) = 0;	// �Q�����S��
		virtual void OnMove(int x, int y, Gamemap * m, int counter) = 0;
		virtual void OnShow(int x, int y, Gamemap * m, CHero *hero) = 0;
		virtual void SetHitted(int dmg, int time) = 0; // �Q����
		int GetHP() { return _hp; };
		void MinusHP(int dmg) { _hp -= dmg; };
		virtual int GetX1() = 0;
		void SetX1(int x) { _x = x; };
		virtual int GetY1() = 0;
		void SetY1(int y) { _y = y; };
		virtual int GetX2() = 0;
		virtual int GetY2() = 0;
		virtual int GetCenterX() = 0;
		virtual int GetCenterY() = 0;
		int GetSpeed() { return _speed; };
		void SetSpeed(int speed) { _speed = speed; };
		//virtual int GetX2() = 0;
		//virtual int GetY2() = 0;

	protected:
		int _hp;					// ��q
		int format_state;			// �R���V(1�W2�U3��4�k)
		int _x, _y;					// �Ǫ����W���y��
		int _speed;					// ���ʳt��
		int _hittime;				// �Q�����ɶ�
		vector <int> _castTime;		// �I��ɶ�
		int getRandomNumber(int min, int max)
		{
			std::random_device rd;  //�H������
			std::mt19937 gen(rd()); //�ؤl
			std::uniform_int_distribution<> dis(min, max);
			return dis(gen);
		};
	};
}

#endif