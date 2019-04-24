#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"

#include "FireBall.h"

namespace game_framework {
	FireBall::FireBall(int x, int y, int time):CSpell(x, y, time)
	{
		Initialize();
	}

	void FireBall::Initialize()
	{
		_speed = 2;
		_damage = 2;
		_duration = 30 * 5;
		_direction = "right";
	}
	void FireBall::LoadBitmap()
	{
		_start_img.LoadBitmapA(IDB_FIREBALL, RGB(255, 255, 255));
	}

	void FireBall::OnShow(CGameMap *m)
	{
		_start_img.SetTopLeft(m->ScreenX(_initX), m->ScreenY(_initY));
		_start_img.ShowBitmap();
	}

	void FireBall::OnMove()
	{
		if (_direction == "right")
		{
			_initX = _initX + _speed;
		}
	}

	
	bool FireBall::HitSomething(CMonster *monster)
	{
		return HitRectangle(monster->GetX1(), monster->GetY1(), monster->GetX2(), monster->GetY2());
	}
	

	bool FireBall::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = _initX;				// ���W��x�y��
		int y1 = _initY;				// ���W��y�y��
		int x2 = x1 + _start_img.Width();	// �k�U��x�y��
		int y2 = y1 + _start_img.Height();	// �k�U��y�y��
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool FireBall::HitSomething(CHero *hero)
	{
		return HitRectangle(hero->GetX1(), hero->GetY1(), hero->GetX2(), hero->GetY2());
	}

	bool FireBall::CheckDuration(int time) 
	{
		if ((time - _initTime) > _duration)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}