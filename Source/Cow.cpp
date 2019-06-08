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
		const int LEFT = 0;
		const int RIGHT = 1;
		_x = X_POS;
		_y = Y_POS;
		active = isNear = true;
		isattacking = false;
		format = RIGHT;
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
		return false;
		//return isHitted;
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
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT1, RGB(0, 0, 0));
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT2, RGB(0, 0, 0));
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT3, RGB(0, 0, 0));
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT4, RGB(0, 0, 0));
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT5, RGB(0, 0, 0));
		atk_2_left.AddBitmap(IDB_COW_ATK_2_LEFT6, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT1, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT2, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT3, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT4, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT5, RGB(0, 0, 0));
		atk_2_right.AddBitmap(IDB_COW_ATK_2_RIGHT6, RGB(0, 0, 0));
		normal_left.AddBitmap(IDB_COW_NORMAL_LEFT1, RGB(0, 0, 0));
		normal_left.AddBitmap(IDB_COW_NORMAL_LEFT2, RGB(0, 0, 0));
		normal_left.AddBitmap(IDB_COW_NORMAL_LEFT3, RGB(0, 0, 0));
		normal_right.AddBitmap(IDB_COW_NORMAL_RIGHT1, RGB(0, 0, 0));
		normal_right.AddBitmap(IDB_COW_NORMAL_RIGHT2, RGB(0, 0, 0));
		normal_right.AddBitmap(IDB_COW_NORMAL_RIGHT3, RGB(0, 0, 0));
		move_left.AddBitmap(IDB_COW_MOVE_LEFT1, RGB(0, 0, 0));
		move_left.AddBitmap(IDB_COW_MOVE_LEFT2, RGB(0, 0, 0));
		move_left.AddBitmap(IDB_COW_MOVE_LEFT3, RGB(0, 0, 0));
		move_left.AddBitmap(IDB_COW_MOVE_LEFT4, RGB(0, 0, 0));
		move_left.AddBitmap(IDB_COW_MOVE_LEFT5, RGB(0, 0, 0));
		move_right.AddBitmap(IDB_COW_MOVE_RIGHT1, RGB(0, 0, 0));
		move_right.AddBitmap(IDB_COW_MOVE_RIGHT2, RGB(0, 0, 0));
		move_right.AddBitmap(IDB_COW_MOVE_RIGHT3, RGB(0, 0, 0));
		move_right.AddBitmap(IDB_COW_MOVE_RIGHT4, RGB(0, 0, 0));
		death_left.AddBitmap(IDB_COW_DEATH_LEFT1, RGB(0, 0, 0));
		death_left.AddBitmap(IDB_COW_DEATH_LEFT2, RGB(0, 0, 0));
		death_left.AddBitmap(IDB_COW_DEATH_LEFT3, RGB(0, 0, 0));
		death_left.AddBitmap(IDB_COW_DEATH_LEFT4, RGB(0, 0, 0));
		death_left.AddBitmap(IDB_COW_DEATH_LEFT5, RGB(0, 0, 0));
		death_right.AddBitmap(IDB_COW_DEATH_RIGHT1, RGB(0, 0, 0));
		death_right.AddBitmap(IDB_COW_DEATH_RIGHT2, RGB(0, 0, 0));
		death_right.AddBitmap(IDB_COW_DEATH_RIGHT3, RGB(0, 0, 0));
		death_right.AddBitmap(IDB_COW_DEATH_RIGHT4, RGB(0, 0, 0));
		death_right.AddBitmap(IDB_COW_DEATH_RIGHT5, RGB(0, 0, 0));

		//hitted.LoadBitmap(IDB_SLIME_HIT, RGB(255, 255, 255));
	}

	void Cow::HitAnimation(int counter)
	{
		if (counter - _hittime >= 10)
		{
			//isHitted = false;
		}
	}

	void Cow::DecideFormat(int x, int y, Gamemap * m)
	{
		const int NMR = 0;
		const int NML = 1;
		const int MR = 2;
		const int ML = 3;
		const int ATK1R = 4;
		const int ATK1L = 5;
		const int ATK2R = 6;
		const int ATK2L = 7;
		const int DL = 8;
		const int DR = 9;
		int speed = 2;
		int judgeX = _x + 20;
		int judgeY = _y + 40;

		if (active && isNear && !isattacking)
		{
			if (x > _x && m->IsEmpty(_x + speed, _y)) {
				_x += speed;
				format = MR;
			}
			else if (x < _x && m->IsEmpty(_x - speed, _y)) {
				_x -= speed;
				format = ML;
			}
			if (y > _y && m->IsEmpty(_x, _y + speed)) {
				_y += speed;
			}
			else if (y < _y && m->IsEmpty(_x, _y - speed)) {
				_y -= speed;
			}
			if (x == _x && y == _y) {
				format = NML;
			}
		}
		else
		{
			format = NML;
		}
	}

	void Cow::OnMove(int x, int y, Gamemap * m)
	{
		DecideFormat(x, y, m);
		const int NMR = 0;
		const int NML = 1;
		const int MR = 2;
		const int ML = 3;
		const int ATK1R = 4;
		const int ATK1L = 5;
		const int ATK2R = 6;
		const int ATK2L = 7;
		const int DL = 8;
		const int DR = 9;
		switch (format)
		{
		case NMR:
			normal_right.OnMove();
			break;
		case NML:
			normal_left.OnMove();
			break;
		case MR:
			move_right.OnMove();
			break;
		case ML:
			move_left.OnMove();
			break;
		case ATK1R:
			atk_1_right.OnMove();
			break;
		case ATK1L:
			atk_1_left.OnMove();
			break;
		case ATK2R:
			atk_2_right.OnMove();
			break;
		case ATK2L:
			atk_2_left.OnMove();
			break;
		case DR:
			death_right.OnMove();
			break;
		case DL:
			death_left.OnMove();
			break;
		}
	}

	void Cow::OnShow(int x,int y, Gamemap * m, CHero *hero)
	{
		const int NMR = 0;
		const int NML = 1;
		const int MR = 2;
		const int ML = 3;
		const int ATK1R = 4;
		const int ATK1L = 5;
		const int ATK2R = 6;
		const int ATK2L = 7;
		const int DL = 8;
		const int DR = 9;
		switch (format)
		{
		case NMR:
			normal_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			normal_right.OnShow();
			break;
		case NML:
			normal_left.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			normal_left.OnShow();
			break;
		case MR:
			move_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			move_right.OnShow();
			break;
		case ML:
			move_left.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			move_left.OnShow();
			break;
		case ATK1R:
			atk_1_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			atk_1_right.OnShow();
			break;
		case ATK1L:
			atk_1_left.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			atk_1_left.OnShow();
			break;
		case ATK2R:
			atk_2_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			atk_2_right.OnShow();
			break;
		case ATK2L:
			atk_2_left.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			atk_2_left.OnShow();
			break;
		case DR:
			death_right.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			death_right.OnShow();
			break;
		case DL:
			death_left.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
			death_left.OnShow();
			break;
		}
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
