#ifndef WIZARD_H
#define WIZARD_H

#include "CMonster.h"

namespace game_framework {
	class Wizard : public CMonster {
	public:
		Wizard(int HP) : CMonster(HP){}
		Wizard() : CMonster() {}
		void Initialize();
		void LoadBitmap();
		void HitAnimation(int counter);
		int Skill(int counter);
		void OnShow(int x, int y, Gamemap * m, CHero *hero);    //主角現在位置x y
		void OnMove(int x, int y, Gamemap * m, int counter);
		int GetX1() { return _x + 30; };
		int GetY1() { return _y + 60; };
		int GetX2();
		int GetY2();
		void SetHitted(int dmg, int time);				//被打到
		bool GetHitted();
		int GetCenterX();
		int GetCenterY();
		void DecideFormat(int x, int y, Gamemap * m, int counter);

	protected:
		CAnimation normal;
		CAnimation move;
		CAnimation atk;
		CMovingBitmap hitted;
		bool isHitted;
		bool active;
		bool isNear;
		int format;
		bool isattacking;
		int attacktimer;
		void AtkAnimation(int counter);
	};
}

#endif