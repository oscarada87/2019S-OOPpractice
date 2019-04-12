#ifndef CMONSTER_H
#define CMONSTER_H

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
		virtual void Attack() = 0;					// ����
		virtual void Initialize() = 0;				// �]�w�Ǫ�����l��
		virtual void LoadBitmap() = 0;				// ���J�ϧ�
		int GetHP() { return _hp; };
		void SetHP(int hp) { _hp = hp; };
		int GetX1() { return _x; };
		void SetX1(int x) { _x = x; };
		int GetY1() { return _y; };
		void SetY1(int y) { _y = y; };
		virtual int GetX2() = 0;
		virtual int GetY2() = 0;
		int GetSpeed() { return _speed; };
		void SetSpeed(int speed) { _speed = speed; };

	protected:
		int _hp;					// ��q
		int format_state;			// �R���V(1�W2�U3��4�k)
		int _x, _y;					// ���l���W���y��
		int _speed;					// ���ʳt��
	};
}

#endif