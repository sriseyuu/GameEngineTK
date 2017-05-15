/// <summary>
/// �Ǐ]����J�����N���X
/// </summary>
#pragma once

#include "Camera.h"
class FollowCamera : public Camera 
{
private:
	//�Ǐ]�Ώۂ̍��W
	DirectX::SimpleMath::Vector3 m_targetPos;
	//�Ǐ]�Ώۂ̉�]�p
	float m_targetAngle;


public:
	//�Ǐ]�ΏۂƃJ�����̋���
	static const float CAMERA_DISTANCE;

	FollowCamera(int width, int height);

	void Update() override;

	//�Ǐ]�Ώۂ̍��W��ݒ�
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetPos);

	//�Ǐ]�Ώۂ̉�]�p��ݒ�
	void SetTargetAngle(const float& targetAngle);
};