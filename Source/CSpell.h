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
		CSpell(int x1, int y1, int time)
		{
			_initX = x1;
			_initY = y1;
			_initTime = time;
		}
		virtual void LoadBitmap() = 0;
		virtual void Initialize() = 0;
		virtual void OnShow(CGameMap *m) = 0;
		virtual void OnMove() = 0;
		virtual bool CheckDuration(int time) = 0;
		virtual bool HitSomething(CHero *hero) = 0;
		virtual bool HitSomething(CMonster *monster) = 0;
		virtual void CalculateUnitVector(int x2, int y2) = 0;
	protected :
		int _initX;
	    int _initY;
		int _initTime;
		int _duration;
		int _damage;
		int _speed;
		int _unitVectorX;
		int _unitVectorY;
		CMovingBitmap _start_img;
		//int _direction; // 靜止方向(1上2下3左4右)
	};
}

#endif