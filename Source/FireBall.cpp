#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"

#include "FireBall.h"

namespace game_framework {
	FireBall::FireBall(int x, int y, int time):CSpell(x, y, time)
	{
		Initialize();
	}

	void FireBall::Initialize()
	{
		_speed = 10;
		_damage = 1;
		_duration = 30 * 5;
	}
	void FireBall::LoadBitmap()
	{
		_start_img.LoadBitmapA(IDB_FIREBALL, RGB(255, 255, 255));
	}

	void FireBall::OnShow(CGameMap *m)
	{
		_start_img.SetTopLeft(m->ScreenX(_initX), m->ScreenY(_initY));
		_start_img.ShowBitmap();
	}

	void FireBall::OnMove()
	{
		// 靜止方向(1上2下3左4右)
		_initX += _unitVectorX;
		_initY += _unitVectorY;
	}

	
	bool FireBall::HitSomething(CMonster *monster)
	{
		return HitRectangle(monster->GetX1(), monster->GetY1(), monster->GetX2(), monster->GetY2());
	}
	

	bool FireBall::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = _initX;				// 左上角x座標
		int y1 = _initY;				// 左上角y座標
		int x2 = x1 + _start_img.Width();	// 右下角x座標
		int y2 = y1 + _start_img.Height();	// 右下角y座標
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool FireBall::HitSomething(CHero *hero)
	{
		return HitRectangle(hero->GetX1(), hero->GetY1(), hero->GetX2(), hero->GetY2());
	}

	bool FireBall::CheckDuration(int time) 
	{
		if ((time - _initTime) > _duration)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void FireBall::CalculateUnitVector(int x2, int y2)
	{
		int tempX = int(pow((x2 - _initX), 2));
		int tempY = int(pow((y2 - _initY), 2));
		int temp1 = tempX + tempY;
		double temp2 = sqrt(temp1);
		temp2 = _speed / temp2;
		_unitVectorX = int((x2 - _initX) / temp2 + 0.5);
		_unitVectorY = int((y2 - _initY) / temp2 + 0.5);
	}
}