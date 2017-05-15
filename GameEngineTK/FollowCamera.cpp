#include "FollowCamera.h"

//�ÓI�����o�ϐ��̏�����
const float FollowCamera::CAMERA_DISTANCE = 5.0f;

using namespace DirectX;
using namespace DirectX::SimpleMath;

FollowCamera::FollowCamera(int width, int height)
	:Camera(width, height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
}

void FollowCamera::Update()
{
	//���_�A�Q�Ɠ_
	Vector3 eyepos, refpos;

	//�^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i������ɏ����Y�����j
	refpos = m_targetPos + Vector3(0, 2.0f, 0);
	//�^�[�Q�b�g���W����J�������W�ւ̍���
	Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);

	//�J�����̎��������̋t�����ɉ�]
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	cameraV = Vector3::TransformNormal(cameraV, rotmat);

	//�J�������W���v�Z
	eyepos = refpos + cameraV;

	//�J���������Z�b�g
	SetEyePos(eyepos);
	SetRefPos(refpos);

	//���N���X�̍X�V
	Camera::Update();
}

void FollowCamera::SetTargetPos(const Vector3 & targetPos)
{
	m_targetPos = targetPos;
}

void FollowCamera::SetTargetAngle(const float & targetAngle)
{
	m_targetAngle = targetAngle;
}
