#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameMap.h"
#include "CHero.h"

namespace game_framework {
	
	CHero::CHero()
	{
		Initialize();
		format_state = 2;
	}

	int CHero::GetX1()
	{
		return x;
	}

	int CHero::GetY1()
	{
		return y;
	}

	int CHero::GetX2()
	{
		return x + animation1.Width();
	}

	int CHero::GetY2()
	{
		return y + animation1.Height();
	}

	int CHero::GetCenterX()
	{
		return x + 42;
	}

	int CHero::GetCenterY()
	{
		return y + 42;
	}

	int CHero::Get_format_state()
	{
		return format_state;
	}

	void CHero::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 1600;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isHitting = heal = false;
		speed = 10;
		hp = 10;
		castTime.clear();
		for (int i = 0; i < 3; i++) 
		{
			castTime.push_back(-1000);
		}
	}

	void CHero::SpeedUp() 
	{
		speed = 20;
	}

	void CHero::SpeedInit()
	{
		speed = 10;
	}

	void CHero::LoadBitmap()
	{
		animation1.AddBitmap(IDB_MOVEUP0, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP1, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP2, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP3, RGB(255, 255, 255));
		animation1.AddBitmap(IDB_MOVEUP4, RGB(255, 255, 255));

		animation2.AddBitmap(IDB_MOVEDOWN0, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN1, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN2, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN3, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_MOVEDOWN4, RGB(255, 255, 255));

		animation3.AddBitmap(IDB_MOVELEFT0, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT1, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT2, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT3, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT4, RGB(255, 255, 255));
		animation3.AddBitmap(IDB_MOVELEFT5, RGB(255, 255, 255));

		animation4.AddBitmap(IDB_MOVERIGHT0, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT1, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT2, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT3, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT4, RGB(255, 255, 255));
		animation4.AddBitmap(IDB_MOVERIGHT5, RGB(255, 255, 255));

		animation1.SetDelayCount(5);
		animation2.SetDelayCount(5);
		animation3.SetDelayCount(5);
		animation4.SetDelayCount(5);


		down_format.LoadBitmap(IDB_DOWN, RGB(255, 255, 255));
		right_format.LoadBitmap(IDB_RIGHT, RGB(255, 255, 255));
		left_format.LoadBitmap(IDB_LEFT, RGB(255, 255, 255));
		up_format.LoadBitmap(IDB_UP, RGB(255, 255, 255));

		//right_hit_format.AddBitmap(IDB_RIGHT_HIT0, RGB(255, 255, 255));
		right_hit_format.AddBitmap(IDB_RIGHT_HIT1, RGB(255, 255, 255));
		right_hit_format.AddBitmap(IDB_RIGHT_HIT2, RGB(255, 255, 255));

		//left_hit_format.AddBitmap(IDB_LEFT_HIT0, RGB(255, 255, 255));
		left_hit_format.AddBitmap(IDB_LEFT_HIT1, RGB(255, 255, 255));
		left_hit_format.AddBitmap(IDB_LEFT_HIT2, RGB(255, 255, 255));

		//down_hit_format.AddBitmap(IDB_DOWN_HIT0, RGB(255, 255, 255));
		down_hit_format.AddBitmap(IDB_DOWN_HIT1, RGB(255, 255, 255));
		down_hit_format.AddBitmap(IDB_DOWN_HIT2, RGB(255, 255, 255));

		//up_hit_format.AddBitmap(IDB_UP_HIT0, RGB(255, 255, 255));
		up_hit_format.AddBitmap(IDB_UP_HIT1, RGB(255, 255, 255));
		up_hit_format.AddBitmap(IDB_UP_HIT2, RGB(255, 255, 255));

		right_hit_format.SetDelayCount(5);
		left_hit_format.SetDelayCount(5);
		up_hit_format.SetDelayCount(5);
		down_hit_format.SetDelayCount(5);

		heal_format.AddBitmap(IDB_HEAL1, RGB(0, 0, 0));
		heal_format.AddBitmap(IDB_HEAL2, RGB(0, 0, 0));
		heal_format.AddBitmap(IDB_HEAL3, RGB(0, 0, 0));

		heal_format.SetDelayCount(5);
	}

	void CHero::OnMove(Gamemap * m, CMonster *monster)
	{
		//animation.OnMove();
		if (isMovingUp == false && isMovingDown == false && isMovingLeft == false && isMovingRight == false && isHitting == true)
		{
			if (format_state == 1)
			{
				up_hit_format.OnMove();
			}
			if (format_state == 2)
			{
				down_hit_format.OnMove();
			}
			if (format_state == 3)
			{
				left_hit_format.OnMove();
			}
			if (format_state == 4)
			{
				right_hit_format.OnMove();
			}
		}
		if (isMovingLeft){
			if (isHitting) {
				left_hit_format.OnMove();
			}
			else {
				animation3.OnMove();
			}
			if (m->monsterIsEmpty(x - speed, y, monster)) {
				x -= speed;
				if (m->GetSX() > 0) {
					m->SetSX(-speed);
				}
			}
		}
		if (isMovingRight){
			if (isHitting) {
				right_hit_format.OnMove();
			}
			else {
				animation4.OnMove();
			}
			if (m->monsterIsEmpty(x + speed, y, monster)) {
				x += speed;
				if (m->GetSX() < m->Getmapx() - SIZE_X) {
					m->SetSX(speed);
				}
			}
		}
		if (isMovingUp){
			if (isHitting) {
				up_hit_format.OnMove();
			}
			else {
				animation1.OnMove();
			}
			if (m->monsterIsEmpty(x, y - speed, monster)) {
				y -= speed;
				if (m->GetSY() > 0) {
					m->SetSY(-speed);
				}
			}
		}
		if (isMovingDown){
			if (isHitting){
				down_hit_format.OnMove();
			}
			else {
				animation2.OnMove();
			}
			if (m->monsterIsEmpty(x, y + speed, monster)) {
				y += speed;
				if (m->GetSY() < m->Getmapy() - SIZE_Y) {
					m->SetSY(speed);
				}
			}
		}
	}

	void CHero::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CHero::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CHero::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CHero::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CHero::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CHero::SetHit(bool flag)
	{
		isHitting = flag;
	}

	bool CHero::GetHit()
	{
		return isHitting;
	}
	void CHero::Sethp(int attack)
	{
		hp = hp - attack;
	}
	int  CHero::Gethp()
	{
		return hp;
	}

	void CHero::SetHeal(bool flag)
	{
		heal = flag;
	}

	bool CHero::HitMonster(CMonster *monster)
	{
		// �˴��^���O�_����Ǫ�
		return HitSomething(monster->GetX1(), monster->GetY1(),
			monster->GetX2(), monster->GetY2());
	}

	bool CHero::HitSomething(int tx1, int ty1, int tx2, int ty2)	//GetX,GetY,GetX2,GetY2
	{
		int x1 = x ;				// ���W��x�y��
		int y1 = y ;				// ���W��y�y��
		int x2 = x1 + animation1.Width();	// �k�U��x�y��
		int y2 = y1 + animation1.Height();	// �k�U��y�y��

		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	void CHero::SetCastTime(int number, int time)
	{
		castTime.at(number - 1) = time;
	}

	bool CHero::CheckCooldown(int number, int counter, int cooldown)
	{
		if (counter - castTime.at(number - 1) >= cooldown)
			return true;
		else
			return false;
	}

	void CHero::Teleport()
	{

		if (format_state == 1)
		{
			y -= 100;
			//up_format.ShowBitmap();
		}
		if (format_state == 2)
		{
			y += 100;
			//down_format.ShowBitmap();
		}
		if (format_state == 3)
		{
			x -= 100;
			//left_format.ShowBitmap();
		}
		if (format_state == 4)
		{
			x += 100;
			//right_format.ShowBitmap();
		}
	}

	void CHero::what_format_show(int x,int y)
	{
		if (!isHitting) 
		{
			if (format_state == 1)
			{
				up_format.SetTopLeft(x, y);
				up_format.ShowBitmap();
			}
			if (format_state == 2)
			{
				down_format.SetTopLeft(x, y);
				down_format.ShowBitmap();
			}
			if (format_state == 3)
			{
				left_format.SetTopLeft(x, y);
				left_format.ShowBitmap();
			}
			if (format_state == 4)
			{
				right_format.SetTopLeft(x, y);
				right_format.ShowBitmap();
			}
		}
		else if (isHitting)
		{
			if (format_state == 1)
			{
				up_hit_format.SetTopLeft(x, y);
				up_hit_format.OnShow();
			}
			if (format_state == 2)
			{
				down_hit_format.SetTopLeft(x, y);
				down_hit_format.OnShow();
			}
			if (format_state == 3)
			{
				left_hit_format.SetTopLeft(x, y);
				left_hit_format.OnShow();
			}
			if (format_state == 4)
			{
				right_hit_format.SetTopLeft(x, y);
				right_hit_format.OnShow();
			}
		}
	}

	void CHero::Set_format_state(int x)
	{
		format_state = x;
	}

	void CHero::OnShow(Gamemap * m)
	{
		if (isMovingUp == false && isMovingDown == false && isMovingLeft == false && isMovingRight == false)
		{
			what_format_show(m->ScreenX(x), m->ScreenY(y));
		}
		if (isMovingLeft)
		{
			if (isHitting) 
			{
				left_hit_format.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				left_hit_format.OnShow();
			}
			else {
				animation3.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				animation3.OnShow();
			}
		}
		else if (isMovingRight)
		{
			if (isHitting) 
			{
				right_hit_format.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				right_hit_format.OnShow();
			}
			else {
				animation4.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				animation4.OnShow();
			}
		}
		else if (isMovingDown)
		{
			if (isHitting) 
			{
				down_hit_format.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				down_hit_format.OnShow();
			}
			else {
				animation2.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				animation2.OnShow();
			}
		}
		else if (isMovingUp)
		{
			if (isHitting) 
			{
				up_hit_format.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				up_hit_format.OnShow();
			}
			else {
				animation1.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				animation1.OnShow();
			}
		}
		if (heal)
		{
			heal_format.SetTopLeft(m->ScreenX(x + 60), m->ScreenY(y));
			heal_format.OnShow();
		}
	}
}