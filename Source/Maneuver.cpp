#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Maneuver.h"
namespace game_framework {
	Maneuver::Maneuver(int x, int y, int time):CSpell(x, y, time)
	{
		Initialize();
	}

	void Maneuver::Initialize()
	{
		_speed = 7;
		_damage = 1;
		_duration = 30 * 1;
	}
	void Maneuver::LoadBitmap(int number)
	{
		switch (number)
		{
		case 0:
			_start_img.LoadBitmapA(IDB_MANEUVER, RGB(255, 255, 255));
			break;
		}
	}

	void Maneuver::OnShow(Gamemap *m)
	{
		_start_img.SetTopLeft(m->ScreenX(_initX), m->ScreenY(_initY));
		_start_img.ShowBitmap();
	}

	void Maneuver::OnMove()
	{

	}
	bool Maneuver::HitSomething(CMonster *monster)
	{
		return HitRectangle(monster->GetX1(), monster->GetY1(), monster->GetX2(), monster->GetY2());
	}
	bool Maneuver::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = _initX;				// ���W��x�y��
		int y1 = _initY;				// ���W��y�y��
		int x2 = x1 + _start_img.Width();	// �k�U��x�y��
		int y2 = y1 + _start_img.Height();	// �k�U��y�y��
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool Maneuver::HitSomething(CHero *hero)
	{
		return HitRectangle(hero->GetX1(), hero->GetY1(), hero->GetX2(), hero->GetY2());
	}

	bool Maneuver::CheckDuration(int time) 
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
	void Maneuver::CalculateUnitVector(int x2, int y2)
	{
	}
}