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
		virtual int Skill(int counter) = 0;			// 技能
		virtual void Initialize() = 0;				// 設定怪物為初始值
		virtual void LoadBitmap() = 0;				// 載入圖形
		virtual void HitAnimation(int counter) = 0;	// 被攻擊特效
		virtual void OnMove(int x, int y, Gamemap * m, int counter) = 0;
		virtual void OnShow(int x, int y, Gamemap * m, CHero *hero) = 0;
		virtual void SetHitted(int dmg, int time) = 0; // 被打到
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
		int _hp;					// 血量
		int format_state;			// 靜止方向(1上2下3左4右)
		int _x, _y;					// 怪物左上角座標
		int _speed;					// 移動速度
		int _hittime;				// 被攻擊時間
		vector <int> _castTime;		// 施放時間
		int getRandomNumber(int min, int max)
		{
			std::random_device rd;  //隨機引擎
			std::mt19937 gen(rd()); //種子
			std::uniform_int_distribution<> dis(min, max);
			return dis(gen);
		};
	};
}

#endif