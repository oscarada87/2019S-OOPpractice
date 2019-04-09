#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "FireBall.h"

namespace game_framework {
	FireBall::FireBall(int x, int y):CSpell(x, y)
	{
		Initialize();
	}

	void FireBall::Initialize()
	{
		_speed = 2;
		_damage = 2;
		_duration = 3;
		_direction = "right";
	}
	void FireBall::LoadBitmap()
	{
		_start_img.LoadBitmapA(IDB_FIREBALL, RGB(255, 255, 255));
	}

	void FireBall::OnShow()
	{
		if (_duration > 0)
		{
			if (_direction == "right") 
			{
				_initX = _initX + _speed;
			}
			_start_img.SetTopLeft(_initX, _initY);
			_start_img.ShowBitmap();
		}
	}

	void FireBall::OnMove()
	{
	
	}
}