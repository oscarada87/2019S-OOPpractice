#ifndef CGAMEMAP_H
#define CGAMEMAP_H
#include "CMonster.h"
namespace game_framework {
	class CGameMap {
	public:
		CGameMap();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetSX(int nx);
		void SetSY(int ny);
		int GetSX();
		int GetSY();
		int Getmapx();
		int Getmapy();
		int ScreenX(int x);
		int ScreenY(int y);
		bool monsterIsEmpty(int x, int y, CMonster *monster);
		bool IsEmpty(int x, int y);
	private:
		CMovingBitmap background0;
		CMovingBitmap background1;
		CMovingBitmap background2;
		CMovingBitmap background3;
		CMovingBitmap hill;
		CMovingBitmap stone1;
		CMovingBitmap stone2;
		CMovingBitmap stone3;
		CMovingBitmap arrowright;
		CMovingBitmap arrowleft;
		CMovingBitmap box;
		CMovingBitmap candle;
		int map[40][40];
		int sx, sy; // (sx, sy)為螢幕(的左上角)在地圖上的點座標
	};
}

#endif