#ifndef CHERO_H
#define CHERO_H

#include "CGameMap.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class CHero
	{
	public:
		CHero();
		void OnMove(CGameMap * m);					// �������l
		void OnShow(CGameMap * m);					// �N���l�ϧζK��e��
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void what_format_show(int x, int y);		// ��ܭ��Ӥ�V
		void Set_format_state(int x);		// �]�w��V
		void SpeedUp();					// �[�t
		void SpeedInit();				// �^��쥻
	protected:
		CAnimation animation1;		// ���l���ʵe
		CAnimation animation2;		// ���l���ʵe
		CAnimation animation3;		// ���l���ʵe
		CAnimation animation4;		// ���l���ʵe
		CMovingBitmap start_fomat;  // �}�l�H����m
		CMovingBitmap right_fomat;  // �k�R���m
		CMovingBitmap left_fomat;	// ���R���m
		CMovingBitmap up_fomat;		// �W�R���m
		int format_state;			// �R���V(1�W2�U3��4�k)
		int x, y;					// ���l���W���y��
		int speed;					// ���ʳt��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
	};
}

#endif