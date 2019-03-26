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
		CMonster(int HP) 
		{
			_HP = HP;
		};
		~CMonster() {};
		virtual void Attack() = 0;					// 攻擊
		virtual void Initialize() = 0;				// 設定怪物為初始值
		virtual void LoadBitmap() = 0;				// 載入圖形
		int GetHP() { return _HP; };
		void SetHP(int HP) { _HP = HP; };
		int GetX() { return _x; };
		void SetX(int x) { _x = x; };
		int GetY() { return _y; };
		void SetY(int y) { _y = y; };
		int GetSpeed() { return _speed; };
		void SetSpeed(int speed) { _speed = speed; };

	protected:
		int _HP;					// 血量
		int format_state;			// 靜止方向(1上2下3左4右)
		int _x, _y;					// 擦子左上角座標
		int _speed;					// 移動速度
	};
}

#endif