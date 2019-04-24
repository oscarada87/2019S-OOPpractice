#ifndef FIREBALL_H
#define FIREBALL_H

#include "CSpell.h"

namespace game_framework {
	class FireBall : public CSpell 
	{
	public:
		FireBall(int x, int y, int time);
		void LoadBitmap();
		void Initialize();
		void OnShow(CGameMap *m);
		void OnMove();
		bool CheckDuration(int time);
		bool HitSomething(CHero *hero);
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);
		bool HitSomething(CMonster *monster);
	private:
		string _direction;
	};

}


#endif