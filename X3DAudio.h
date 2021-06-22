//==========================================================================
// �T�E���h[X3DAudio.h]
// author: MasyoLab
//==========================================================================
#pragma once

//==========================================================================
// include
//==========================================================================
#include <X3DAudio.h>

//==========================================================================
//
// class  : X3DAudio
// Content: X3DAudio
//
//==========================================================================
class X3DAudio
{
public:
    X3DAudio();
    ~X3DAudio();

    /**
    @brief ������
    */
    void Init(void);

    /**
    @brief �X�V
    */
    void Update(void);

    /**
    @brief �T�E���h����������Ώۍ��W�̓o�^
    @param Front [in] �O�����̌��� �x�N�g��
    @param Top [in] ������̌��� �x�N�g��
    @param Pos [in] ���[���h�P�ʂ̈ʒu �x�N�g��
    @param Velocity [in] ���[�U�[��`�̃��[���h�P��/�b�̃x���V�e�B �x�N�g��
    */
    void SetTargetPos(
        const X3DAUDIO_VECTOR & Front,
        const X3DAUDIO_VECTOR & Top, 
        const X3DAUDIO_VECTOR & Pos,
        const X3DAUDIO_VECTOR & Velocity);

    /**
    @brief �T�E���h�𔭂�����̂̈ʒu
    @param Front [in] �O�����̌��� �x�N�g��
    @param Top [in] ������̌��� �x�N�g��
    @param Pos [in] ���[���h�P�ʂ̈ʒu �x�N�g��
    @param Velocity [in] ���[�U�[��`�̃��[���h�P��/�b�̃x���V�e�B �x�N�g��
    */
    void SetSoundPos(
        const X3DAUDIO_VECTOR & Front,
        const X3DAUDIO_VECTOR & Top,
        const X3DAUDIO_VECTOR & Pos,
        const X3DAUDIO_VECTOR & Velocity);

    /**
    @brief �{�C�X�̍ŏI�o�͂̊e�`�����l���̃{�����[�����x���̎擾
    @return �{�����[�����x��
    */
    FLOAT32 * GetOutputMatrix(void);

    /**
    @brief �{�C�X�̎��g��������̎擾
    @return �{�C�X�̎��g��������
    */
    FLOAT32 * GetFrequencyRatio(void);
private:
    X3DAUDIO_HANDLE m_X3DInstance = { 0 }; // �X�s�[�J�[ �Z�b�g�A�b�v�������t���O
    X3DAUDIO_LISTENER m_Listener = { 0 }; // �T�E���h���������邷�ׂĂ̂��̂̈ʒu
    X3DAUDIO_EMITTER m_Emitter = { 0 }; // �T�E���h�𔭂�����̂̈ʒu
    X3DAUDIO_DSP_SETTINGS m_DSPSettings = { 0 }; // �v�Z���ꂽ����
    FLOAT32 m_Matrix[6] = { 0 };
};
