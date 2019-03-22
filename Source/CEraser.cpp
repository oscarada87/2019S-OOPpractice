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
	CGameMap::CGameMap()
	{
		sx = sy = 0;//
		int init[40][40] =
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 3, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 3, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 2, 1, 1, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 2, 1, 1, 1, 1, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
		for (int i = 0; i < 40; i++)
			for (int j = 0; j < 40; j++)
				map[j][i] = init[i][j];
	}
	void CGameMap::OnMove()
	{

		//		if (sy <= SIZE_Y) {
		//			sx += 3;
		//			sy += 3;
		//		}
		//		else {
		//			sx = sy = 0;
		//		}

	}
	void CGameMap::LoadBitmap()
	{
		background0.LoadBitmap(IDB_BACKGROUND0);
		background1.LoadBitmap(IDB_BACKGROUND1);
		background2.LoadBitmap(IDB_BACKGROUND2);
		background3.LoadBitmap(IDB_BACKGROUND3);
	}
	void CGameMap::OnShow()
	{
		for (int i = (sx / 50); i <= ((sx + SIZE_X)/ 50); i++)
			for (int j = (sy / 50); j <= ((sy + SIZE_Y) / 50); j++)
			{
				int x = i * 50 - sx; // 算出第(i, j)這一格的 x 螢幕座標
				int y = j * 50 - sy; // 算出第(i, j)這一格的 y 螢幕座標
				switch (map[i][j])
				{
				case 0:
					background0.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background0.ShowBitmap();
					break;
				case 1:
					background1.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background1.ShowBitmap();
					break;
				case 2:
					background2.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background2.ShowBitmap();
					break;
				case 3:
					background3.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background3.ShowBitmap();
				default:
					ASSERT(1);
				}
			}
	}
	void CGameMap::SetSX(int nx)
	{
		sx = sx + nx;
		OnShow();
		//pic.SetTopLeft(-sx, -sy);
	}
	void CGameMap::SetSY(int ny)
	{
		sy = sy + ny;
		OnShow();
		//pic.SetTopLeft(-sx, -sy);
	}
	int CGameMap::ScreenX(int x) // x 為地圖的點座標
	{
		return x - sx; // 回傳螢幕的 x 點座標
	}
	int CGameMap::ScreenY(int y) // y 為地圖的 y 點座標
	{
		return y - sy; // 回傳螢幕的點座標
	}
	int CGameMap::GetSX()
	{
		
		return sx;
	}

	int CGameMap::GetSY()
	{
		return sy;
	}
	int CGameMap::Getmapx()
	{
		return background0.Width() * 40;
	}

	int CGameMap::Getmapy()
	{
		return background0.Height() * 40;
	}
	bool CGameMap::IsEmpty(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = (x + 48) / 50; // 轉換為格座標(整數除法)
		int gy = (y + 90) / 50; // 轉換為格座標(整數除法)
		int ox = x / 50;
		return map[gx][gy] == 0 && map[ox][gy] == 0;// 0 代表空的
	}

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
		const int X_POS = 300;
		const int Y_POS = 350;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		speed = 5;
	}

	void CEraser::SpeedUp() 
	{
		speed = 15;
	}

	void CEraser::SpeedInit()
	{
		speed = 5;
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

	void CEraser::OnMove(CGameMap * m)
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
	void CEraser::what_format_show(int x,int y)
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
	void CEraser::Set_format_state(int x)
	{
		format_state = x;
	}
	void CEraser::OnShow(CGameMap * m)
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