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
		hill.LoadBitmap(IDB_hill, RGB(0, 0, 0));
		stone1.LoadBitmap(IDB_stone1, RGB(0, 0, 0));
		stone2.LoadBitmap(IDB_stone2, RGB(0, 0, 0));
		stone3.LoadBitmap(IDB_stone3, RGB(0, 0, 0));
		arrowleft.LoadBitmap(IDB_arrowleft, RGB(255,255,255));
		arrowright.LoadBitmap(IDB_arrowright, RGB(255,255,255));
		box.LoadBitmap(IDB_bigbox, RGB(255, 255, 255));
		candle.LoadBitmap(IDB_candle, RGB(255, 255, 255));
	}
	void CGameMap::OnShow()
	{
		for (int i = (sx / 50); i <= ((sx + SIZE_X) / 50); i++)
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
		int gx = (x + 50) / 50; // 轉換為格座標(整數除法)
		int gy = (y + 90) / 50; // 轉換為格座標(整數除法)
		int ox = x / 50;
		return map[gx][gy] == 0 && map[ox][gy] == 0;// 0 代表空的
	}


}