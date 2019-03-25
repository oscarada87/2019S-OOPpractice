#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Slime.h"

namespace game_framework {
	void Slime::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 350;
		_x = X_POS;
		_y = Y_POS;
	}
	
	void Slime::Attack()
	{
	
	}

	void Slime::LoadBitmap()
	{
	
	}
}
