#ifndef CGAMEMAP_H
#define CGAMEMAP_H
#include "CMonster.h"
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
			return x - sx; // �^�ǿù��� x �I�y��
		};
		int ScreenY(int y) {
			return y - sy; // �^�ǿù��� x �I�y�� 
		};
		bool monsterIsEmpty(int x, int y, CMonster *monster) {		/*hero*/
			int x1 = x + 20;
			int x2 = x + 60;
			int y1 = y;
			int y2 = y + 74;
			bool mos = (monster->GetX2() >= x1 && monster->GetX1() <= x2 && monster->GetY2() >= y1 && (monster->GetY1() + 50) <= y2);
			return IsEmpty(x, y) && mos == false;
		};
		bool IsEmpty(int x, int y) {
			int gx = (x + 60) / 50; // �ഫ����y��(��ư��k)
			int gy = (y + 84) / 50; // �ഫ����y��(��ư��k)
			int ox = (x + 20) / 50;

			return map[gx][gy] == 0 && map[ox][gy] == 0;// 0 �N��Ū�
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
		//int sx, sy; // (sx, sy)���ù�(�����W��)�b�a�ϤW���I�y��
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
	};

}

#endif