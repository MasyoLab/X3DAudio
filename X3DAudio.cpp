//==========================================================================
// �T�E���h[X3DAudio.cpp]
// author: MasyoLab
//==========================================================================
#include "X3DAudio.h"

X3DAudio::X3DAudio()
{
}

X3DAudio::~X3DAudio()
{
}

//==========================================================================
/**
@brief ������
*/
void X3DAudio::Init(void)
{
    // �X�s�[�J�[ �Z�b�g�A�b�v
    X3DAudioInitialize(
        SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |
        SPEAKER_LOW_FREQUENCY | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT,
        X3DAUDIO_SPEED_OF_SOUND, this->m_X3DInstance);

    // �Q�[�� ���[�v�ōX�V����Ȃ��\���̂̃����o�[�́A�����ŏ�����
    this->m_Emitter.ChannelCount = 1;
    this->m_Emitter.CurveDistanceScaler = FLT_MIN;

    // �\���̂̃C���X�^���X���쐬
    this->m_DSPSettings.SrcChannelCount = 1;
    this->m_DSPSettings.DstChannelCount = 6;
    this->m_DSPSettings.pMatrixCoefficients = this->m_Matrix;
}

//==========================================================================
/**
@brief �X�V
*/
void X3DAudio::Update(void)
{
    X3DAudioCalculate(this->m_X3DInstance, &this->m_Listener, &this->m_Emitter, X3DAUDIO_CALCULATE_MATRIX | X3DAUDIO_CALCULATE_DOPPLER, &this->m_DSPSettings);
}

//==========================================================================
/**
@brief �T�E���h����������Ώۍ��W�̓o�^
@param Front [in] �O�����̌��� �x�N�g��
@param Top [in] ������̌��� �x�N�g��
@param Pos [in] ���[���h�P�ʂ̈ʒu �x�N�g��
@param Velocity [in] ���[�U�[��`�̃��[���h�P��/�b�̃x���V�e�B �x�N�g��
*/
void X3DAudio::SetTargetPos(const X3DAUDIO_VECTOR & Front, const X3DAUDIO_VECTOR & Top, const X3DAUDIO_VECTOR & Pos, const X3DAUDIO_VECTOR & Velocity)
{
    this->m_Listener.OrientFront = Front;
    this->m_Listener.OrientTop = Top;
    this->m_Listener.Position = Pos;
    this->m_Listener.Velocity = Velocity;
}

//==========================================================================
/**
@brief �T�E���h�𔭂�����̂̈ʒu
@param Front [in] �O�����̌��� �x�N�g��
@param Top [in] ������̌��� �x�N�g��
@param Pos [in] ���[���h�P�ʂ̈ʒu �x�N�g��
@param Velocity [in] ���[�U�[��`�̃��[���h�P��/�b�̃x���V�e�B �x�N�g��
*/
void X3DAudio::SetSoundPos(const X3DAUDIO_VECTOR & Front, const X3DAUDIO_VECTOR & Top, const X3DAUDIO_VECTOR & Pos, const X3DAUDIO_VECTOR & Velocity)
{
    this->m_Emitter.OrientFront = Front;
    this->m_Emitter.OrientTop = Top;
    this->m_Emitter.Position = Pos;
    this->m_Emitter.Velocity = Velocity;
}

//==========================================================================
/**
@brief �{�C�X�̍ŏI�o�͂̊e�`�����l���̃{�����[�����x���̎擾
@return �{�����[�����x��
*/
FLOAT32 * X3DAudio::GetOutputMatrix(void)
{
    return this->m_DSPSettings.pMatrixCoefficients;
}

//==========================================================================
/**
@brief �{�C�X�̎��g��������̎擾
@return �{�C�X�̎��g��������
*/
FLOAT32 * X3DAudio::GetFrequencyRatio(void)
{
    return &this->m_DSPSettings.DopplerFactor;
}

