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
		ismove = false;
		//_HP = 100;
	}
	
	void Slime::Attack()
	{
	
	}

	void Slime::LoadBitmap()
	{
		move.AddBitmap(IDB_ERASER1, RGB(255, 255, 255));
		move.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
		move.AddBitmap(IDB_ERASER3, RGB(255, 255, 255));
		move.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
	}
	void Slime::OnMove(int x, int y, CGameMap * m)
	{
		int speed = 2;
		if (ismove) {
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
	}
	void Slime::OnShow(int x,int y, CGameMap * m)
	{
		if (_HP != 0) {
			if (abs(x - _x) < 200 && abs(y - _y) < 200) {
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
				ismove = true;
			}
			else  {
				ismove = false;
				move.SetTopLeft(m->ScreenX(_x), m->ScreenY(_y));
				move.OnShow();
			}
		}
	}
}
