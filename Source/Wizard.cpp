#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
#include "CHero.h"
#include "Wizard.h"
#include "math.h"

namespace game_framework {
	void Wizard::Initialize()
	{
		const int X_POS = 1000;
		const int Y_POS = 500;
		_x = X_POS;
		_y = Y_POS;
		active = isNear = isHitted = false;
		//active = isNear = true;
		isattacking = false;
		_hittime = 0;
		_speed = 1;
	}
	
	int Wizard::Skill(int counter)
	{
		if (counter % 90 == 0 && isNear && !isHitted && !isattacking)
		{
			int result = getRandomNumber(1, 4);
			if (result == 1) {
				isattacking = true;
				attacktimer = counter;
			}
			else if (result == 2 && _speed < 15) {
				_speed++;
			}
			else if (result == 3 && _speed > 1) {
				_speed--;
			}
			else if (result == 4) {
				_x += getRandomNumber(-200, 200);
				_y += getRandomNumber(-200, 200);
			}
			return result;
		}
			
		else
			return 0;
	}

	bool Wizard::GetHitted()
	{
		return isHitted;
	}

	int Wizard::GetX2()
	{
		return _x + 280;
	}

	int Wizard::GetY2()
	{
		return _y + 320; 
	}

	int Wizard::GetCenterX()
	{
		return _x + 80;
	}

	int Wizard::GetCenterY()
	{
		return _y + 120;
	}

	void Wizard::LoadBitmap()
	{
		normal.AddBitmap(IDB_WIZARD_NORMAL1, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL2, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL3, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL4, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL5, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL6, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL7, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL8, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL9, RGB(58, 64, 65));
		normal.AddBitmap(IDB_WIZARD_NORMAL10, RGB(58, 64, 65));
		normal.SetDelayCount(8);
		move.AddBitmap(IDB_WIZARD_MOVE1, RGB(58, 64, 65));
		move.AddBitmap(IDB_WIZARD_MOVE2, RGB(58, 64, 65));
		move.AddBitmap(IDB_WIZARD_MOVE3, RGB(58, 64, 65));
		move.AddBitmap(IDB_WIZARD_MOVE4, RGB(58, 64, 65));
		move.AddBitmap(IDB_WIZARD_MOVE5, RGB(58, 64, 65));
		move.AddBitmap(IDB_WIZARD_MOVE6, RGB(58, 64, 65));
		move.SetDelayCount(8);
		atk.AddBitmap(IDB_WIZARD_ATK1, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK2, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK3, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK4, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK5, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK6, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK7, RGB(58, 64, 65));
		atk.AddBitmap(IDB_WIZARD_ATK8, RGB(58, 64, 65));
		atk.SetDelayCount(3);
		hitted.LoadBitmap(IDB_WIZARD_DEATH2, RGB(58, 64, 65));
	}

	void Wizard::HitAnimation(int counter)
	{
		if (counter - _hittime >= 10)
		{
			isHitted = false;
		}
	}

	void Wizard::OnMove(int x, int y, Gamemap * m, int counter)
	{
		AtkAnimation(counter);
		if (isattacking) {
			atk.OnMove();
		}
		else if (active && isNear)
		{
			move.OnMove();
			if (x > _x && m->IsEmpty(_x + _speed, _y)) {
				_x += _speed;
			}
			else if (x < _x && m->IsEmpty(_x - _speed, _y)) {
				_x -= _speed;
			}
			if (y > _y && m->IsEmpty(_x, _y + _speed)) {
				_y += _speed;
			}
			else if (y < _y && m->IsEmpty(_x, _y - _speed)) {
				_y -= _speed;
			}
		}
		else
		{
			normal.OnMove();
		}
	}

	void Wizard::OnShow(int x,int y, Gamemap * m, CHero *hero)
	{
		if (!isHitted)
		{
			if (isattacking) {
				atk.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				atk.OnShow();
			}
			else if (hero->HitSomething(_x, _y, _x + move.Width(), _y + move.Height())) {
				active = false;
				normal.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				normal.OnShow();
			}
			else if (abs(x - _x) < 600 && abs(y - _y) < 600) {
				isNear = active = true;
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
			}
			else if (abs(x - _x) > 1000 && abs(y - _y) > 1000) {
				active = false;
				normal.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				normal.OnShow();
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
	}

	void Wizard::SetHitted(int dmg, int time)
	{
		if (!isHitted)
		{
			isHitted = true;
			_hittime = time;
			_hp -= dmg;
		}
	}

	void Wizard::AtkAnimation(int counter) {
		if (isattacking) {
			if ((counter - attacktimer) > 12) {
				isattacking = false;
			}
		}
	}
}
