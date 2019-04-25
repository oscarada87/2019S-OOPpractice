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
		CSpell(int x, int y, int time,int direction)
		{
			_initX = x;
			_initY = y;
			_initTime = time;
			_direction = direction;
		}
		virtual void LoadBitmap() = 0;
		virtual void Initialize() = 0;
		virtual void OnShow(CGameMap *m) = 0;
		virtual void OnMove() = 0;
		virtual bool CheckDuration(int time) = 0;
		virtual bool HitSomething(CHero *hero) = 0;
		virtual bool HitSomething(CMonster *monster) = 0;
	protected :
		int _initX;
	    int _initY;
		int _initTime;
		int _duration;
		int _damage;
		int _speed;
		CMovingBitmap _start_img;
		int _direction; // �R���V(1�W2�U3��4�k)
	};
}

#endif