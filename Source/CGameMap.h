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
		void OnShowonhero();
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

		CMovingBitmap aman;
		CMovingBitmap tree;
		CMovingBitmap treepot;

		int map[40][40];
		int sx, sy; // (sx, sy)���ù�(�����W��)�b�a�ϤW���I�y��
	};
	class CGameMap2 {
	public:
		CGameMap2();
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

		int map[40][40];
		int sx, sy; // (sx, sy)���ù�(�����W��)�b�a�ϤW���I�y��
	};

	class CGameMap3 {
	public:
		CGameMap3();
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

		int map[40][40];
		int sx, sy; // (sx, sy)���ù�(�����W��)�b�a�ϤW���I�y��
	};

}

#endif