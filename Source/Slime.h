#ifndef SLIME_H
#define SLIME_H

#include "CMonster.h"

namespace game_framework {
	class Slime : public CMonster {
	public:
		Slime(int HP) : CMonster(HP){}

		void Initialize();
		void LoadBitmap();
		void Attack();
		int GetX2();
		int GetY2();
	};
}

#endif