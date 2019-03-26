#ifndef CSPELL_H
#define CSPELL_H

namespace game_framework {
	class CSpell
	{
	public:
		CSpell()
		{
			throw("This Spell Don't Have Location!");
		}
		CSpell(int x, int y)
		{
			_initX = x;
			_initY = y;
		}
		virtual void LoadBitmap() = 0;
		virtual void Initialize() = 0;
		virtual void OnShow() = 0;
		virtual void OnMove() = 0;
	protected :
		int _initX;
	    int _initY;
		int _duration;
		int _damage;
		int _speed;
		CMovingBitmap _start_img;
	};
}

#endif