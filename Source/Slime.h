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
		void OnShow(int x,int y, CGameMap * m);    //�D���{�b��mx y
		void OnMove(int x, int y, CGameMap * m);
		int GetX2();					//�k�U���y��
		int GetY2();
		void SetHitted(bool flag);
		bool GetHitted();
		void DmgToSlime(int dmg);
	protected:
		CAnimation still;			 // ����
		CAnimation move;			 //���ʧ���
		CMovingBitmap hitted;
		bool isHitted;
		bool ismove;
	};
}

#endif