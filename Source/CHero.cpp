#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
#include "CHero.h"

namespace game_framework {
	
	CHero::CHero()
	{
		Initialize();
		format_state = 2;
	}

	int CHero::GetX1()
	{
		return x;
	}

	int CHero::GetY1()
	{
		return y;
	}

	int CHero::GetX2()
	{
		return x + animation1.Width();
	}

	int CHero::GetY2()
	{
		return y + animation1.Height();
	}

	void CHero::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 350;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isHitting = false;
		speed = 5;
	}

	void CHero::SpeedUp() 
	{
		speed = 15;
	}

	void CHero::SpeedInit()
	{
		speed = 5;
	}

	void CHero::LoadBitmap()
	{
		animation1.AddBitmap(IDB_UP, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_DOWN, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_LEFT, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_RIGHT, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT, RGB(255, 255, 255));
		down_format.LoadBitmap(IDB_DOWN, RGB(255, 255, 255));
		right_format.LoadBitmap(IDB_RIGHT, RGB(255, 255, 255));
		left_format.LoadBitmap(IDB_LEFT, RGB(255, 255, 255));
		up_format.LoadBitmap(IDB_UP, RGB(255, 255, 255));
		right_hit_format.LoadBitmap(IDB_RIGHT_HIT, RGB(255, 255, 255));
		left_hit_format.LoadBitmap(IDB_LEFT_HIT, RGB(255, 255, 255));
		down_hit_format.LoadBitmap(IDB_DOWN_HIT, RGB(255, 255, 255));
		up_hit_format.LoadBitmap(IDB_UP_HIT, RGB(255, 255, 255));
	}

	void CHero::OnMove(CGameMap * m)
	{
		//animation.OnMove();
		if (isMovingLeft)
		{
			animation3.OnMove();
			if (m->IsEmpty(x - speed, y)) {
				x -= speed;
				if (m->GetSX() > 0) {
					m->SetSX(-speed);
				}
			}
		}
		if (isMovingRight)
		{
			animation4.OnMove();
			if (m->IsEmpty(x + speed, y)) {
				x += speed;
				if (m->GetSX() < m->Getmapx() - SIZE_X) {
					m->SetSX(speed);
				}
			}
		}
		if (isMovingUp)
		{
			animation1.OnMove();
			if (m->IsEmpty(x, y - speed)) {
				y -= speed;
				if (m->GetSY() > 0) {
					m->SetSY(-speed);
				}
			}
		}
		if (isMovingDown)
		{
			animation2.OnMove();
			if (m->IsEmpty(x, y + speed)) {
				y += speed;
				if (m->GetSY() < m->Getmapy() - SIZE_Y) {
					m->SetSY(speed);
				}
			}
		}
	}

	void CHero::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CHero::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CHero::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CHero::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CHero::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CHero::SetHit(bool flag)
	{
		isHitting = flag;
	}

	void CHero::Hit()
	{
		isHitting = true;
	}

	bool CHero::HitSomething(int tx1, int ty1, int tx2, int ty2)	//GetX,GetY,GetX2,GetY2
	{
		int x1 = x ;				// 左上角x座標
		int y1 = y ;				// 左上角y座標
		int x2 = x1 + animation1.Width();	// 右下角x座標
		int y2 = y1 + animation1.Height();	// 右下角y座標

		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}
	void CHero::what_format_show(int x,int y)
	{
		if (!isHitting) 
		{
			if (format_state == 1)
			{
				up_format.SetTopLeft(x, y);
				up_format.ShowBitmap();
			}
			if (format_state == 2)
			{
				down_format.SetTopLeft(x, y);
				down_format.ShowBitmap();
			}
			if (format_state == 3)
			{
				left_format.SetTopLeft(x, y);
				left_format.ShowBitmap();
			}
			if (format_state == 4)
			{
				right_format.SetTopLeft(x, y);
				right_format.ShowBitmap();
			}
		}
		else if (isHitting)
		{
			if (format_state == 1)
			{
				up_hit_format.SetTopLeft(x, y);
				up_hit_format.ShowBitmap();
			}
			if (format_state == 2)
			{
				down_hit_format.SetTopLeft(x, y);
				down_hit_format.ShowBitmap();
			}
			if (format_state == 3)
			{
				left_hit_format.SetTopLeft(x, y);
				left_hit_format.ShowBitmap();
			}
			if (format_state == 4)
			{
				right_hit_format.SetTopLeft(x, y);
				right_hit_format.ShowBitmap();
			}
			//Sleep(500);
			//isHitting = false;
		}
	}
	void CHero::Set_format_state(int x)
	{
		format_state = x;
	}
	void CHero::OnShow(CGameMap * m)
	{
		//animation.SetTopLeft(x, y);
		//animation.OnShow();
		if (isMovingUp == false && isMovingDown == false && isMovingLeft == false && isMovingRight == false)
		{
			what_format_show(m->ScreenX(x), m->ScreenY(y));
		}
		if (isMovingLeft)
		{
			animation3.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			animation3.OnShow();
		}
		else if (isMovingRight)
		{
			animation4.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			animation4.OnShow();
		}
		else if (isMovingDown)
		{
			animation2.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			animation2.OnShow();
		}
		else if (isMovingUp)
		{
			animation1.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			animation1.OnShow();
		}
	}
}