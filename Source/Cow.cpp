#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
#include "CHero.h"
#include "Cow.h"
#include "math.h"

namespace game_framework {
	void Cow::Initialize()
	{
		const int X_POS = 1600;
		const int Y_POS = 500;
		_x = X_POS;
		_y = Y_POS;
		active = isNear = isHitted = false;
		_hp = 5;
		_hittime = 0;
	}
	
	
	int Cow::Skill(int counter)
	{
		if (counter % 30 == 0 && isNear)
		{
			int result = getRandomNumber(1, 2);
			if (result == 1 && _hp >= 10)
				return 2;
			return result;
		}
			
		else
			return 0;
	}

	bool Cow::GetHitted()
	{
		return isHitted;
	}

	int Cow::GetX2()
	{
		return _x; //+ move.Width();
	}

	int Cow::GetY2()
	{
		return _y; //+ move.Height();
	}

	int Cow::GetCenterX()
	{
		return _x; //+ move.Width()/2;
	}

	int Cow::GetCenterY()
	{
		return _y; //+ move.Height()/2;
	}

	void Cow::LoadBitmap()
	{
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT1, RGB(0, 0, 0));
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT2, RGB(0, 0, 0));
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT3, RGB(0, 0, 0));
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT4, RGB(0, 0, 0));
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT5, RGB(0, 0, 0));
		atk_1_left.AddBitmap(IDB_COW_ATK_1_LEFT6, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT1, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT2, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT3, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT4, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT5, RGB(0, 0, 0));
		atk_1_right.AddBitmap(IDB_COW_ATK_1_RIGHT6, RGB(0, 0, 0));
		
		//hitted.LoadBitmap(IDB_SLIME_HIT, RGB(255, 255, 255));
	}

	void Cow::HitAnimation(int counter)
	{
		if (counter - _hittime >= 10)
		{
			isHitted = false;
		}
	}

	void Cow::OnMove(int x, int y, Gamemap * m)
	{
		const int LEFT = 0;
		const int RIGHT = 1;
		int speed = 2;
		int judgeX = _x + 20;
		int judgeY = _y + 40;
		atk_1_right.OnMove();
		/*
		if (active && isNear) 
		{
			move.OnMove();
			if (x > _x && m->IsEmpty(_x + speed, _y)) {
				_x += speed;
				format = RIGHT;
			}
			else if(x <= _x && m->IsEmpty(_x - speed, _y)) {
				_x -= speed;
				format = LEFT;
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
		*/
	}

	void Cow::OnShow(int x,int y, Gamemap * m, CHero *hero)
	{
		atk_1_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
		atk_1_right.OnShow();
		/*
		if (!isHitted) 
		{
			if (hero->HitSomething(_x, _y, _x + move.Width(), _y + move.Height())) {
				active = false;
				still.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				still.OnShow();
			}
			else if (abs(x - _x) < 200 && abs(y - _y) < 200) {
				isNear = active = true;
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
			}
			else if (abs(x - _x) > 500 && abs(y - _y) > 500){
				active = false;
				still.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				still.OnShow();
			}
			else {
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
			}
		}
		else
		{
			hitted.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			hitted.ShowBitmap();
		}
		*/
	}

	void Cow::SetHitted(int dmg, int time)
	{
		/*
		if (!isHitted)
		{
			isHitted = true;
			_hittime = time;
			_hp -= dmg;
		}
		*/
	}

}
