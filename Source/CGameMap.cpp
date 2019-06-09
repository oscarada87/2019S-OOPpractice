#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
//#include "CMonster.h"

namespace game_framework {

	void CGameMap::Initialize()
	{
		const int X_POS = 0;
		const int Y_POS = 1500;
		sx = X_POS;
		sy = Y_POS;
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
		aman.LoadBitmap(IDB_aman, RGB(255, 255, 255));
		tree.LoadBitmap(IDB_tree, RGB(255, 255, 255));
		treepot.LoadBitmap(IDB_pottree, RGB(255, 255, 255));
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
				case -1:
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
	void CGameMap::OnShowonhero()
	{
		// aman tree//
		aman.SetTopLeft(550 - sx, 1800 - sy);
		aman.ShowBitmap();
		aman.SetTopLeft(400 - sx, 1800 - sy);
		aman.ShowBitmap();
		aman.SetTopLeft(250 - sx, 1800 - sy);
		aman.ShowBitmap();
		aman.SetTopLeft(100 - sx, 1800 - sy);
		aman.ShowBitmap();
		tree.SetTopLeft(1650 - sx, 1350 - sy);
		tree.ShowBitmap();
		treepot.SetTopLeft(1600 - sx, 1650 - sy);
		treepot.ShowBitmap();
		candle.SetTopLeft(950 - sx, 1550 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(1050 - sx, 1550 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(1150 - sx, 1550 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(1000 - sx, 1550 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(1100 - sx, 1550 - sy);
		candle.ShowBitmap();
		candle.SetTopLeft(900 - sx, 1550 - sy);
		candle.ShowBitmap();

		// 地圖圖層 //
		for (int i = 2; i <= 12; i++) {
			background2.SetTopLeft((i * 50) - sx, 1900 - sy);
			background2.ShowBitmap();
		}
		for (int i = 19; i <= 23; i++) {
			background2.SetTopLeft((i * 50) - sx, 1600 - sy);
			background2.ShowBitmap();
		}
		for (int i = 24; i <= 37; i++) {
			background2.SetTopLeft((i * 50) - sx, 1750 - sy);
			background2.ShowBitmap();
		}
	}
	int CGameMap::Getmapx()
	{
		return background0.Width() * 40;
	}

	int CGameMap::Getmapy()
	{
		return background0.Height() * 40;
	}




	void CGameMap2::Initialize()
	{
		const int X_POS = 800;/*要改*/
		const int Y_POS = 1500;
		sx = X_POS;
		sy = Y_POS;
		int init[40][40] =
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
			{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
		for (int i = 0; i < 40; i++)
			for (int j = 0; j < 40; j++)
				map[j][i] = init[i][j];
	}
	void CGameMap2::LoadBitmap()
	{
		snowtree.LoadBitmap(IDB_snow, RGB(255,255,255));
		snoww.LoadBitmap(IDB_snoww, RGB(255, 255, 255));
		background0.LoadBitmap(IDB_stage20);
		background1.LoadBitmap(IDB_BACKGROUND1);
		background2.LoadBitmap(IDB_stage2);
		background3.LoadBitmap(IDB_stage3);
		
		/*candle.LoadBitmap(IDB_candle, RGB(255, 255, 255));*/
	}
	void CGameMap2::OnShow()
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
				case -1:
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
		/*candle.SetTopLeft(1000 - sx, 225 - sy);
		candle.ShowBitmap();*/
		snoww.SetTopLeft(100 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(300 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(400 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(900 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(1200 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(1500 - sx, 1350 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(600 - sx, 950 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(700 - sx, 950 - sy);
		snoww.ShowBitmap();
		snoww.SetTopLeft(1000 - sx, 950 - sy);
		snoww.ShowBitmap();

	}
	void CGameMap2::OnShowonhero()
	{
		snowtree.SetTopLeft(100 - sx, 1800 - sy);
		snowtree.ShowBitmap();
		snowtree.SetTopLeft(1800 - sx, 1800 - sy);
		snowtree.ShowBitmap();
		snowtree.SetTopLeft(1700 - sx, 700 - sy);
		snowtree.ShowBitmap();
		snowtree.SetTopLeft(1400 - sx, 700 - sy);
		snowtree.ShowBitmap();
	}
	int CGameMap2::Getmapx()
	{
		return background0.Width() * 40;
	}

	int CGameMap2::Getmapy()
	{
		return background0.Height() * 40;
	}

	void CGameMap3::Initialize()
	{
		const int X_POS = 800;/*要改*/
		const int Y_POS = 1500;
		sx = X_POS;
		sy = Y_POS;
		int init[40][40] =
		{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1},
		{1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 2, 2, 1, 1},
		{1, 1, 1, 1, 2, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 2, 1, 1},
		{1, 1, 1, 1, 2, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 4, 0, 4, 4, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 0, 0, 0, 0, 4, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 2, 1, 1},
		{1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1},
		{1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		};
		for (int i = 0; i < 40; i++)
			for (int j = 0; j < 40; j++)
				map[j][i] = init[i][j];
	}
	void CGameMap3::LoadBitmap()
	{
		background0.LoadBitmap(IDB_final2);
		background1.LoadBitmap(IDB_BACKGROUND1);
		background2.LoadBitmap(IDB_final0);
		background3.LoadBitmap(IDB_final3);
		background4.LoadBitmap(IDB_trap);
		/*candle.LoadBitmap(IDB_candle, RGB(255, 255, 255));*/
	}
	void CGameMap3::OnShow()
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
				case -1:
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
				case 4:
					background4.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background4.ShowBitmap();
					break;
				case 3:
					background3.SetTopLeft(x, y); // 指定第(i, j)這一格的座標
					background3.ShowBitmap();
					break;
				default:
					ASSERT(1);
				}
			}
		/*candle.SetTopLeft(1000 - sx, 225 - sy);
		candle.ShowBitmap();*/

	}
	void CGameMap3::OnShowonhero()
	{

	}
	int CGameMap3::Getmapx()
	{
		return background0.Width() * 40;
	}

	int CGameMap3::Getmapy()
	{
		return background0.Height() * 40;
	}
}