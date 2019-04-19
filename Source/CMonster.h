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
		virtual void Attack() = 0;					// 攻擊
		virtual void Initialize() = 0;				// 設定怪物為初始值
		virtual void LoadBitmap() = 0;				// 載入圖形
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
		int _hp;					// 血量
		int format_state;			// 靜止方向(1上2下3左4右)
		int _x, _y;					// 擦子左上角座標
		int _speed;					// 移動速度
	};
}

#endif