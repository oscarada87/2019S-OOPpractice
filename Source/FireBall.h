#ifndef FIREBALL_H
#define FIREBALL_H

#include "CSpell.h"

namespace game_framework {
	class FireBall : public CSpell 
	{
	public:
		FireBall(int x, int y);
		void LoadBitmap();
		void Initialize();
		void OnShow();
		void OnMove();
	private:
		string _direction;
	};

}


#endif