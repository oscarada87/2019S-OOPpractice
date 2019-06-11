#ifndef CGAMEMAP_H
#define CGAMEMAP_H

//#include "CMonster.h"
//class CMonster;

namespace game_framework {
	class Gamemap
	{
	public:
		Gamemap(){};
		virtual void Initialize() = 0;
		virtual void LoadBitmap() = 0;
		virtual void OnShow() = 0;
		virtual void OnShowonhero() = 0;
		virtual int Getmapx() = 0;
		virtual int Getmapy() = 0;
		void OnMove() {};
		void SetSX(int nx) {
			sx = sx + nx;
			OnShow();
		};
		void SetSY(int ny) {
			sy = sy + ny;
			OnShow();
		};
		int GetSX() { return sx; };
		int GetSY() { return sy; };
		int ScreenX(int x) {
			return x - sx; // 回傳螢幕的 x 點座標
		};
		int ScreenY(int y) {
			return y - sy; // 回傳螢幕的 x 點座標 
		};
		/*
		bool monsterIsEmpty(int x, int y, vector<int> monsterloc) {		
			int x1 = x + 20;
			int x2 = x + 60;
			int y1 = y;
			int y2 = y + 74;
			//bool mos = (monster->GetX2() >= x1 && monster->GetX1() <= x2 && monster->GetY2() >= y1 && (monster->GetY1() + 50) <= y2);
			bool mos = (monsterloc[2] >= x1 && monsterloc[0] <= x2 && monsterloc[3] >= y1 && monsterloc[1] <= y2);
			return IsEmpty(x, y) && mos == false;
		};
		*/
		bool IsEmpty(int x, int y) {
			int gx = (x + 60) / 50; // 轉換為格座標(整數除法)
			int gy = (y + 84) / 50; // 轉換為格座標(整數除法)
			int ox = (x + 20) / 50;

			//return map[gx][gy] == 0 && map[ox][gy] == 0 || map[gx][gy] == 4 && map[ox][gy] == 4;// 0 代表空的
			return (map[gx][gy] == 0 || map[gx][gy] == 4) && (map[ox][gy] == 0 || map[ox][gy] == 4);
		};
		bool Istrap(int x, int y) {
			int gx = (x + 60) / 50; // 轉換為格座標(整數除法)
			int gy = (y + 84) / 50; // 轉換為格座標(整數除法)
			int ox = (x + 20) / 50;
			return  map[gx][gy] == 4 && map[ox][gy] == 4;
		};
	protected:
		int map[40][40];
		int sx, sy;
	};
	class CGameMap : public Gamemap {
	public:
		CGameMap() : Gamemap() {};
		void Initialize();
		void LoadBitmap();
		//void OnMove();
		void OnShow();
		void OnShowonhero();
		//void SetSX(int nx);
		//void SetSY(int ny);
		//int GetSX();
		//int GetSY();
		int Getmapx();
		int Getmapy();
		//int ScreenX(int x);
		//int ScreenY(int y);
		//bool monsterIsEmpty(int x, int y, CMonster *monster);
		//bool IsEmpty(int x, int y);
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

		//int map[40][40];
		//int sx, sy; // (sx, sy)為螢幕(的左上角)在地圖上的點座標
	};
	class CGameMap2 : public Gamemap {
	public:
		CGameMap2() : Gamemap() {};
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void OnShowonhero();
		int Getmapx();
		int Getmapy();
	private:
		CMovingBitmap background0;
		CMovingBitmap background1;
		CMovingBitmap background2;
		CMovingBitmap background3;
		CMovingBitmap background4;
		CMovingBitmap snowtree;
		CMovingBitmap snoww;
	};

	class CGameMap3 : public Gamemap {
	public:
		CGameMap3() : Gamemap() {};
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void OnShowonhero();
		int Getmapx();
		int Getmapy();
	private:
		CMovingBitmap background0;
		CMovingBitmap background1;
		CMovingBitmap background2;
		CMovingBitmap background3;
		CMovingBitmap background4;
	};

}

#endif