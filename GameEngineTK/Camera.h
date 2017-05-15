/// <summary>
/// �J�����𐧌䂷��N���X
/// </summary>
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
class Camera
{
protected://�����o�ϐ�������

	//�J�����̈ʒu(���_���W)
	DirectX::SimpleMath::Vector3 m_eyepos;
	//�J�����̌��Ă����(�����_/�Q�Ɠ_)
	DirectX::SimpleMath::Vector3 m_refpos;
	//�J�����̏�����x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;

	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;

	//������������p
	float m_fovY ;
	//�A�X�y�N�g��
	float m_aspect;
	//�j�A�N���b�v
	float m_nearClip;
	//�t�@�[�N���b�v
	float m_farClip;

	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_proj;

public://�����o�֐�
	//�R���X�g���N�^
	Camera(int width, int height);
	//�f�X�g���N�^
	virtual ~Camera();

	//�X�V����
	virtual void Update();

	//�r���[�s��̎擾
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	//�ˉe�s��̎擾
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//���_���W�̐ݒ�
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	//�����_�̐ݒ�
	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	//������x�N�g���̐ݒ�
	void SetUpVec(DirectX::SimpleMath::Vector3 upvec);

	//������������p�̐ݒ�
	void SetFovY(float fovY);

	//�A�X�y�N�g��̐ݒ�
	void SetAspect(float aspect);

	//�j�A�N���b�v�ݒ�
	void SetNearClip(float nearClip);

	//�t�@�[�N���b�v�ݒ�
	void SetFarClip(float farClip);
};
