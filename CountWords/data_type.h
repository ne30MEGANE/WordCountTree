#pragma once

/*  �f�[�^�͂��̍\���̂��g���Ă��������B  */
struct tnode {
	char* word;  /*  �P��ւ̃|�C���^  */
	int count;  /*  �o����  */
	struct tnode* left;  /*  ���̎q��  */
	struct tnode* right;  /*  �E�̎q��  */

	/*  2021 �N�x�A���܂�g��Ȃ����Ȃ̂ŃR�����g�A�E�g  */
//	struct tnode* parent;  /*  �������J������ɂ͐e�����������ق������������A�����ɂ���Ă͎g��Ȃ�  */
};


