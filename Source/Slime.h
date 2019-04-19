#ifndef SLIME_H
#define SLIME_H

#include "CMonster.h"
#include "CGameMap.h"
namespace game_framework {
	class Slime : public CMonster {
	public:
		Slime(int HP) : CMonster(HP){}
		Slime() : CMonster() {}
		void Initialize();
		void LoadBitmap();
		void Attack();
		void OnShow(int x,int y, CGameMap * m);    //主角現在位置x y
		void OnMove(int x, int y, CGameMap * m);
		int GetX2();					//右下角座標
		int GetY2();
		void SetHitted(bool flag);
		bool GetHitted();
	protected:
		CAnimation still;			 // 不動
		CAnimation move;			 //移動攻擊
		CMovingBitmap hitted;
		bool isHitted;
		bool ismove;
	};
}

#endif