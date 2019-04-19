#ifndef CSPELL_H
#define CSPELL_H

#include "CHero.h"
#include "CGameMap.h"

namespace game_framework {
	class CSpell
	{
	public:
		CSpell()
		{
			throw("This Spell Don't Have Location!");
		}
		CSpell(int x, int y)
		{
			_initX = x;
			_initY = y;
		}
		virtual void LoadBitmap() = 0;
		virtual void Initialize() = 0;
		virtual void OnShow(CGameMap * m) = 0;
		virtual void OnMove() = 0;
		virtual bool HitSomething(CHero *hero) = 0;
		//virtual bool HitSomething(CMonster *monster) = 0;
	protected :
		int _initX;
	    int _initY;
		int _duration;
		int _damage;
		int _speed;
		CMovingBitmap _start_img;
	};
}

#endif