#ifndef CMONSTER_H
#define CMONSTER_H

namespace game_framework {
	class CMonster
	{
	public:
		CMonster() 
		{
			throw("This Monster Don't Have HP!");
		};
		CMonster(int HP) 
		{
			_HP = HP;
		};
		~CMonster() {};
		virtual void Attack() = 0;					// ����
		virtual void Initialize() = 0;				// �]�w�Ǫ�����l��
		virtual void LoadBitmap() = 0;				// ���J�ϧ�
		int GetHP() { return _HP; };
		void SetHP(int HP) { _HP = HP; };
		int GetX() { return _x; };
		void SetX(int x) { _x = x; };
		int GetY() { return _y; };
		void SetY(int y) { _y = y; };
		int GetSpeed() { return _speed; };
		void SetSpeed(int speed) { _speed = speed; };

	protected:
		int _HP;					// ��q
		int format_state;			// �R���V(1�W2�U3��4�k)
		int _x, _y;					// ���l���W���y��
		int _speed;					// ���ʳt��
	};
}

#endif