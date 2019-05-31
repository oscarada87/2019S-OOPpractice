#ifndef COW_H
#define COW_H

#include "CMonster.h"

namespace game_framework {
	class Cow : public CMonster {
	public:
		Cow(int HP) : CMonster(HP){}
		Cow() : CMonster() {}
		void Initialize();
		void LoadBitmap();
		void HitAnimation(int counter);
		int Skill(int counter);
		void OnShow(int x, int y, Gamemap * m, CHero *hero);    //主角現在位置x y
		void OnMove(int x, int y, Gamemap * m);
		int GetX2();					
		int GetY2();
		void SetHitted(int dmg, int time);				//被打到
		bool GetHitted();
		int GetCenterX();
		int GetCenterY();
	protected:
		CAnimation normal_left;
		CAnimation normal_right;
		CAnimation move_left;
		CAnimation move_right;
		CAnimation atk_1_left;
		CAnimation atk_1_right;
		CAnimation atk_2_left;
		CAnimation atk_2_right;
		CAnimation death_left;
		CAnimation death_right;
		CMovingBitmap hitted;
		bool isHitted;
		bool active;
		bool isNear;
		bool format;
	};
}

#endif