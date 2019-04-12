#ifndef FIREBALL_H
#define FIREBALL_H

#include "CSpell.h"


namespace game_framework {
	class FireBall : public CSpell 
	{
	public:
		FireBall(int x, int y);
		void LoadBitmap();
		void Initialize();
		void OnShow();
		void OnMove();
		bool HitSomething(CHero *hero);
		//bool HitSomething(CMonster *monster);
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);
		string _direction;
	};

}


#endif