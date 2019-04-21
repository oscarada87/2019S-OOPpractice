#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"

namespace game_framework {

	CGameMap::CGameMap()
	{
		sx = 0;
		sy = 1500;
		int init[40][40] =
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 1, 2,-1, 0, 0,-1,-1,-1,-1,-1, 0, 0,-1, 3, 3, 3, 3, 3, 3, 3, 2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2, 0, 0, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2,-1, 0, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 2, 2, 2, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 2, 1, 1, 2, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
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
			{1, 2, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0,-1,-1, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 2,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
		hill.LoadBitmap(IDB_hill, RGB(0, 0, 0));
		stone1.LoadBitmap(IDB_stone1, RGB(0, 0, 0));
		stone2.LoadBitmap(IDB_stone2, RGB(0, 0, 0));
		stone3.LoadBitmap(IDB_stone3, RGB(0, 0, 0));
		arrowleft.LoadBitmap(IDB_arrowleft, RGB(255, 255, 255));
		arrowright.LoadBitmap(IDB_arrowright, RGB(255, 255, 255));
		box.LoadBitmap(IDB_bigbox, RGB(255, 255, 255));
		candle.LoadBitmap(IDB_candle, RGB(255, 255, 255));
	}
	void CGameMap::OnShow()
	{
		for (int i = (sx / 50); i <= ((sx + SIZE_X) / 50); i++)
			for (int j = (sy / 50); j <= ((sy + SIZE_Y) / 50); j++)
			{
				int x = i * 50 - sx; // ��X��(i, j)�o�@�檺 x �ù��y��
				int y = j * 50 - sy; // ��X��(i, j)�o�@�檺 y �ù��y��
				switch (map[i][j])
				{
				case 0:
					background0.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background0.ShowBitmap();
					break;
				case -1:
					background0.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background0.ShowBitmap();
					break;
				case 1:
					background1.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background1.ShowBitmap();
					break;
				case 2:
					background2.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background2.ShowBitmap();
					break;
				case 3:
					background3.SetTopLeft(x, y); // ���w��(i, j)�o�@�檺�y��
					background3.ShowBitmap();
				default:
					ASSERT(1);
				}
			}
		//hill//
		hill.SetTopLeft(150 - sx, 200 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(150 - sx, 300 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(150 - sx, 400 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(150 - sx, 500 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(150 - sx, 600 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(650 - sx, 200 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(650 - sx, 400 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(650 - sx, 500 - sy);
		hill.ShowBitmap();
		hill.SetTopLeft(650 - sx, 600 - sy);
		hill.ShowBitmap();
		// stone //
		stone1.SetTopLeft(400 - sx, 1300 - sy);
		stone1.ShowBitmap();
		stone2.SetTopLeft(200 - sx, 1300 - sy);
		stone2.ShowBitmap();
		stone3.SetTopLeft(1200 - sx, 250 - sy);
		stone3.ShowBitmap();
		stone3.SetTopLeft(1800 - sx, 250 - sy);
		stone3.ShowBitmap();
		// arrow //
		arrowleft.SetTopLeft(400 - sx, 1400 - sy);
		arrowleft.ShowBitmap();
		arrowleft.SetTopLeft(400 - sx, 1500 - sy);
		arrowleft.ShowBitmap();
		arrowleft.SetTopLeft(400 - sx, 1600 - sy);
		arrowleft.ShowBitmap();
		arrowright.SetTopLeft(200 - sx, 1400 - sy);
		arrowright.ShowBitmap();
		arrowright.SetTopLeft(200 - sx, 1500 - sy);
		arrowright.ShowBitmap();
		arrowright.SetTopLeft(200 - sx, 1600 - sy);
		arrowright.ShowBitmap();
		// candle box //
		box.SetTopLeft(1350 - sx, 250 - sy);
		box.ShowBitmap();
		box.SetTopLeft(1500 - sx, 250 - sy);
		box.ShowBitmap();
		box.SetTopLeft(1650 - sx, 250 - sy);
		box.ShowBitmap();
		candle.SetTopLeft(750 - sx, 225 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(850 - sx, 225 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(950 - sx, 225 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(800 - sx, 225 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(900 - sx, 225 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(1000 - sx, 225 - sy);
		candle.ShowBitmap();




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
	int CGameMap::ScreenX(int x) // x ���a�Ϫ��I�y��
	{
		return x - sx; // �^�ǿù��� x �I�y��
	}
	int CGameMap::ScreenY(int y) // y ���a�Ϫ� y �I�y��
	{
		return y - sy; // �^�ǿù����I�y��
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
	bool CGameMap::monsterIsEmpty(int x, int y, CMonster *monster) /*y1�ڥ��S������ �{�ɳB�z monster->GetY1() + 50,�٭n�B�z*/
	{
		/*hero*/
		int x1 = x + 20;
		int x2 = x + 60;
		int y1 = y;
		int y2 = y + 74;
		bool mos = (monster->GetX2() >= x1 && monster->GetX1() <= x2 && monster->GetY2() >= y1 && (monster->GetY1() + 50) <= y2);
		return IsEmpty(x, y) && mos == false;
	}
	bool CGameMap::IsEmpty(int x, int y) // (x, y) ���a�Ϫ��I�y��
	{
		int gx = (x + 60) / 50; // �ഫ����y��(��ư��k)
		int gy = (y + 84) / 50; // �ഫ����y��(��ư��k)
		int ox = (x + 20) / 50;

		return map[gx][gy] == 0 && map[ox][gy] == 0;// 0 �N��Ū�
	}


}