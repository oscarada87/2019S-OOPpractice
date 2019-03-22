#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
#include "CHero.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CHero: Eraser class
	/////////////////////////////////////////////////////////////////////////////
	
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
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
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
		//animation.AddBitmap(IDB_ERASER1, RGB(255, 255, 255));
		//animation.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
		//animation.AddBitmap(IDB_ERASER3, RGB(255, 255, 255));
		//animation.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_UP, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_DOWN, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_LEFT, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_RIGHT, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT, RGB(255, 255, 255));
		start_fomat.LoadBitmap(IDB_DOWN, RGB(255, 255, 255));
		right_fomat.LoadBitmap(IDB_RIGHT, RGB(255, 255, 255));
		left_fomat.LoadBitmap(IDB_LEFT, RGB(255, 255, 255));
		up_fomat.LoadBitmap(IDB_UP, RGB(255, 255, 255));
	}

	void CHero::OnMove(CGameMap * m)
	{
		//animation.OnMove();
		if (isMovingLeft)
		{
			animation3.OnMove();
			if (m->IsEmpty(x - 1, y)) {
				x -= speed;
				if (m->GetSX() > 0) {
					m->SetSX(-speed);
				}
			}
		}
		if (isMovingRight)
		{
			animation4.OnMove();
			if (m->IsEmpty(x + 1, y)) {
				x += speed;
				if (m->GetSX() < m->Getmapx() - SIZE_X) {
					m->SetSX(speed);
				}
			}
		}
		if (isMovingUp)
		{
			animation1.OnMove();
			if (m->IsEmpty(x, y - 1)) {
				y -= speed;
				if (m->GetSY() > 0) {
					m->SetSY(-speed);
				}
			}
		}
		if (isMovingDown)
		{
			animation2.OnMove();
			if (m->IsEmpty(x, y + 1)) {
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
	void CHero::what_format_show(int x,int y)
	{
		if (format_state == 1)
		{
			up_fomat.SetTopLeft(x,y);
			up_fomat.ShowBitmap();
		}
		if (format_state == 2)
		{
			start_fomat.SetTopLeft(x, y);
			start_fomat.ShowBitmap();
		}
		if (format_state == 3)
		{
			left_fomat.SetTopLeft(x, y);
			left_fomat.ShowBitmap();
		}
		if (format_state == 4)
		{
			right_fomat.SetTopLeft(x, y);
			right_fomat.ShowBitmap();
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