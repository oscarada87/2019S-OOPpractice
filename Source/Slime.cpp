#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Slime.h"
#include "math.h" 
#include "CGameMap.h"

namespace game_framework {
	void Slime::Initialize()
	{
		const int X_POS = 1600;
		const int Y_POS = 500;
		_x = X_POS;
		_y = Y_POS;
		ismove = isHitted = false;
		_hp = 5;
		_hittime = 0;
	}
	
	
	int Slime::Skill(int counter)
	{
		if (counter % 30 == 0 && ismove)
		{
			int result = getRandomNumber(1, 2);
			if (result == 1 && _hp >= 10)
				return 2;
			return result;
		}
			
		else
			return 0;
	}

	bool Slime::GetHitted()
	{
		return isHitted;
	}

	int Slime::GetX2()
	{
		return _x + move.Width();
	}

	int Slime::GetY2()
	{
		return _y + move.Height();
	}

	void Slime::LoadBitmap()
	{
		still.AddBitmap(IDB_SLIME1, RGB(255, 255, 255));
		still.AddBitmap(IDB_SLIME2, RGB(255, 255, 255));
		still.AddBitmap(IDB_SLIME3, RGB(255, 255, 255));
		move.AddBitmap(IDB_SLIMEJUMP1, RGB(255, 255, 255));
		move.AddBitmap(IDB_SLIMEJUMP2, RGB(255, 255, 255));
		move.AddBitmap(IDB_SLIMEJUMP3, RGB(255, 255, 255));
		move.AddBitmap(IDB_SLIMEJUMP4, RGB(255, 255, 255));
		move.AddBitmap(IDB_SLIMEJUMP5, RGB(255, 255, 255));
		move.SetDelayCount(5);
		hitted.LoadBitmap(IDB_SLIME_HIT, RGB(255, 255, 255));
	}

	void Slime::HitAnimation(int counter)
	{
		if (counter - _hittime >= 10)
		{
			isHitted = false;
		}
	}

	void Slime::OnMove(int x, int y, CGameMap * m)
	{
		int speed = 2;
		if (ismove) 
		{
			move.OnMove();
			if (x > _x && m->IsEmpty(_x + speed, _y)) {
				_x += speed;
			}
			else if(x <= _x && m->IsEmpty(_x - speed, _y)) {
				_x -= speed;
			}
			if (y > _y && m->IsEmpty(_x, _y + speed)) {
				_y += speed;
			}
			else if(y <= _y && m->IsEmpty(_x, _y - speed)) {
				_y -= speed;
			}
		}
		else 
		{
			still.OnMove();
		}
	}

	void Slime::OnShow(int x,int y, CGameMap * m, CHero *hero)
	{
		if (!isHitted) 
		{
			if (hero->HitSomething(_x, _y, _x + move.Width(), _y + move.Height())) {
				ismove = false;
				still.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				still.OnShow();
			}
			else /*if (abs(x - _x) < 200 && abs(y - _y) < 200)*/ {
				ismove = true;
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
			}
			/*
			else  {
				ismove = false;
				still.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				still.OnShow();
			}
			*/
		}
		else
		{
			hitted.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			hitted.ShowBitmap();
		}
	}

	void Slime::SetHitted(int dmg, int time)
	{
		if (!isHitted)
		{
			isHitted = true;
			_hittime = time;
			_hp -= dmg;
		}
	}

}
