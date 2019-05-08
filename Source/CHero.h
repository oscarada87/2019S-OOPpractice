#ifndef CHERO_H
#define CHERO_H

#include "CGameMap.h"
#include "CMonster.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class CHero
	{
	public:
		CHero();
		void OnMove(Gamemap * m, CMonster *monster);					// ���ʭ^��
		void OnShow(Gamemap * m);					// �N�^���ϧζK��e��
		int  GetX1();					// �^�����W�� x �y��
		int  GetY1();					// �^�����W�� y �y��
		int  GetX2();					// �^���k�U�� x �y��
		int  GetY2();					// �^���k�U�� y �y��
		int  GetCenterX();					// �^������ x �y��
		int  GetCenterY();					// �^������ y �y��
		int	 Get_format_state();		// �R���V(1�W2�U3��4�k)
		void Initialize();				// �]�w�^������l��
		void LoadBitmap();				// ���J�ϧ�
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w�^�����W���y��
		void what_format_show(int x, int y);		// ��ܭ��Ӥ�V
		void Set_format_state(int x);		// �]�w��V
		void SpeedUp();					// �[�t
		void SpeedInit();				// �^��쥻
		bool HitMonster(CMonster *monster);
		bool HitSomething(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��F��(��J���W�k�U�y��)
		void SetHit(bool flag);
		bool GetHit();						// �]�w�������A
		void Sethp(int attack);				// ���h�֦�
		void SetHeal(bool flag);			// �]�w�O�_���b�^��
		int  Gethp();						// �o���q
		void Teleport();					//����
		void SetCastTime(int number, int time);		//�]�w�N�o�ɶ� (1�򥻧��� 2�ޯ�A 3�ޯ�B 4�ޯ�C)
		bool CheckCooldown(int number, int counter, int cooldown);	//�ˬd�N�o�ɶ� (1�򥻧��� 2�ޯ�A 3�ޯ�B 4�ޯ�C)
	protected:
		CAnimation animation1;		// ���l���ʵe
		CAnimation animation2;		// ���l���ʵe
		CAnimation animation3;		// ���l���ʵe
		CAnimation animation4;		// ���l���ʵe
		CMovingBitmap down_format;  // �}�l�H����m
		CMovingBitmap right_format;  // �k�R���m
		CMovingBitmap left_format;	// ���R���m
		CMovingBitmap up_format;		// �W�R���m
		CAnimation up_hit_format;// �W������m
		CAnimation down_hit_format;// �U������m
		CAnimation left_hit_format;// ��������m
		CAnimation right_hit_format;// �k������m
		CAnimation heal_format;		// �^��ʵe
		int format_state;			// �R���V(1�W2�U3��4�k)
		int x, y;					// ���l���W���y��
		int speed;					// ���ʳt��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isHitting;				// �O�_���b����
		vector <int> castTime;		// �N�o�ɶ� (1�򥻧��� 2�ޯ�A 3�ޯ�B 4�ޯ�C)
		int  hp;					// ��q
		bool heal;
	};
}

#endif