#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


Camera::Camera(int width, int height)
{
//__�����o�ϐ��̏�����/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

	//�J�����m�ʒu(���_���W)
	m_eyepos = Vector3(0, 0, 5);
	//�J�����m���e�C����(�����_/�Q�Ɠ_)
	m_refpos = Vector3(0, 0, 0);
	//�J�����m������x�N�g��
	m_upvec = Vector3(0, 1, 0);

	//������������p
	m_fovY = XMConvertToRadians(60.0f);
	//�A�X�y�N�g��
	m_aspect = (float)width / (float)height;
	//�j�A�N���b�v
	m_nearClip = 0.1f;
	//�t�@�[�N���b�v
	m_farClip = 1000.0f;


	//�r���[�s��̐���
	m_view = Matrix::CreateLookAt(
		m_eyepos,m_refpos,m_upvec);

	//�ˉe�s��i�v���W�F�N�V�����s��j�̐���
	m_proj = Matrix::CreatePerspectiveFieldOfView(
		m_fovY,//����p(�㉺����)
		m_aspect,
		m_nearClip,//�j�A�N���b�v
		m_farClip//�t�@�[�N���b�v
	);
}


Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��̐���
	m_view = Matrix::CreateLookAt(
		m_eyepos, m_refpos, m_upvec);

	//�ˉe�s��i�v���W�F�N�V�����s��j�̐���
	m_proj = Matrix::CreatePerspectiveFieldOfView(
		m_fovY,//����p(�㉺����)
		m_aspect,
		m_nearClip,//�j�A�N���b�v
		m_farClip//�t�@�[�N���b�v
	);
}

const Matrix& Camera::GetViewMatrix()
{
	//�r���[�s���Ԃ�
	return m_view;
}

const Matrix& Camera::GetProjectionMatrix()
{
	//�ˉe�s���Ԃ�
	return m_proj;
}

void Camera::SetEyePos(DirectX::SimpleMath::Vector3 eyepos)
{
	m_eyepos = eyepos;
}

void Camera::SetRefPos(DirectX::SimpleMath::Vector3 refpos)
{
	m_refpos = refpos;
}

void Camera::SetUpVec(DirectX::SimpleMath::Vector3 upvec)
{
	m_upvec = upvec;
}

void Camera::SetFovY(float fovY)
{
	m_fovY = fovY;
}

void Camera::SetAspect(float aspect)
{
	m_aspect = aspect;
}

void Camera::SetNearClip(float nearClip)
{
	m_nearClip = nearClip;
}

void Camera::SetFarClip(float farClip)
{
	m_farClip = farClip;
}
