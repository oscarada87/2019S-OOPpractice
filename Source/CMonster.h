#ifndef CMONSTER_H
#define CMONSTER_H

#include <random>

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
		virtual int Skill(int counter) = 0;					// ����
		virtual void Initialize() = 0;				// �]�w�Ǫ�����l��
		virtual void LoadBitmap() = 0;				// ���J�ϧ�
		virtual void HitAnimation(int counter) = 0;	// �Q�����S��
		int GetHP() { return _hp; };
		void MinusHP(int dmg) { _hp -= dmg; };
		int GetX1() { return _x; };
		void SetX1(int x) { _x = x; };
		int GetY1() { return _y; };
		void SetY1(int y) { _y = y; };
		virtual int GetX2() = 0;
		virtual int GetY2() = 0;
		int GetSpeed() { return _speed; };
		void SetSpeed(int speed) { _speed = speed; };
		//virtual int GetX2() = 0;
		//virtual int GetY2() = 0;

	protected:
		int _hp;					// ��q
		int format_state;			// �R���V(1�W2�U3��4�k)
		int _x, _y;					// ���l���W���y��
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