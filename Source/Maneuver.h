#ifndef MANEUVER_H
#define MANEUVER_H
#include "CSpell.h"
namespace game_framework {
	class Maneuver : public CSpell 
	{
	public:
		Maneuver(int x, int y, int time);
		void LoadBitmap(int number);
		void Initialize();
		void OnShow(Gamemap *m);
		void OnMove();
		bool CheckDuration(int time);
		bool HitSomething(CHero *hero);
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);
		bool HitSomething(CMonster *monster);
		void CalculateUnitVector(int x2, int y2);
	};

}
#endif