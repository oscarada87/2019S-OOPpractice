#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CEraser::CEraser()
	{
		Initialize();
		format_state = 2;
	}

	int CEraser::GetX1()
	{
		return x;
	}

	int CEraser::GetY1()
	{
		return y;
	}

	int CEraser::GetX2()
	{
		return x + animation1.Width();
	}

	int CEraser::GetY2()
	{
		return y + animation1.Height();
	}

	void CEraser::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CEraser::LoadBitmap()
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

	void CEraser::OnMove()
	{
		const int STEP_SIZE = 2;
		//animation.OnMove();
		if (isMovingLeft)
		{
			animation3.OnMove();
			x -= STEP_SIZE;
		}
		if (isMovingRight)
		{
			animation4.OnMove();
			x += STEP_SIZE;
		}
		if (isMovingUp)
		{
			animation1.OnMove();
			y -= STEP_SIZE;
		}
		if (isMovingDown)
		{
			animation2.OnMove();
			y += STEP_SIZE;
		}
	}

	void CEraser::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CEraser::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CEraser::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CEraser::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CEraser::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}
	void CEraser::what_format_show()
	{
		if (format_state == 1)
		{
			up_fomat.SetTopLeft(x, y);
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
	void CEraser::Set_format_state(int x)
	{
		format_state = x;
	}
	void CEraser::OnShow()
	{
		//animation.SetTopLeft(x, y);
		//animation.OnShow();
		if (isMovingUp == false && isMovingDown == false && isMovingLeft == false && isMovingRight == false)
		{
			what_format_show();
		}
		if (isMovingLeft)
		{
			animation3.SetTopLeft(x, y);
			animation3.OnShow();
		}
		else if (isMovingRight)
		{
			animation4.SetTopLeft(x, y);
			animation4.OnShow();
		}
		else if (isMovingUp)
		{
			animation1.SetTopLeft(x, y);
			animation1.OnShow();
		}
		else if (isMovingDown)
		{
			animation2.SetTopLeft(x, y);
			animation2.OnShow();
		}
	}
}