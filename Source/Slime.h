#ifndef SLIME_H
#define SLIME_H
#include "CMonster.h"
namespace game_framework {
	class Slime : public CMonster {
	public:
		Slime(int HP) : CMonster(HP){}
		Slime() : CMonster() {}
		void Initialize();
		void LoadBitmap();
		void HitAnimation(int counter);
		int Skill(int counter);
		void OnShow(int x, int y, Gamemap * m, CHero *hero);    //�D���{�b��mx y
		void OnMove(int x, int y, Gamemap * m, int counter);
		int GetX1() { return _x + 20; };
		int GetY1() { return _y + 50; };
		int GetX2();					//�k�U���y��
		int GetY2();
		void SetHitted(int dmg, int time);				//�Q����
		bool GetHitted();
		int GetCenterX();
		int GetCenterY();
		void setactive();	// setfalse
	protected:
		CAnimation still;			 // ����
		CAnimation move;			 //���ʧ���
		CMovingBitmap hitted;
		bool isHitted;
		bool active;
		bool isNear;
	};
}

#endif