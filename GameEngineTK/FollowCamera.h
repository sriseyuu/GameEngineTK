/// <summary>
/// ’Ç]‚·‚éƒJƒƒ‰ƒNƒ‰ƒX
/// </summary>
#pragma once

#include "Camera.h"
class FollowCamera : public Camera 
{
private:
	//’Ç]‘ÎÛ‚ÌÀ•W
	DirectX::SimpleMath::Vector3 m_targetPos;
	//’Ç]‘ÎÛ‚Ì‰ñ“]Šp
	float m_targetAngle;


public:
	//’Ç]‘ÎÛ‚ÆƒJƒƒ‰‚Ì‹——£
	static const float CAMERA_DISTANCE;

	FollowCamera(int width, int height);

	void Update() override;

	//’Ç]‘ÎÛ‚ÌÀ•W‚ğİ’è
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetPos);

	//’Ç]‘ÎÛ‚Ì‰ñ“]Šp‚ğİ’è
	void SetTargetAngle(const float& targetAngle);
};