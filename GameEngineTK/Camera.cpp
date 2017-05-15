#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


Camera::Camera(int width, int height)
{
//__メンバ変数の初期化/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

	//カメラノ位置(視点座標)
	m_eyepos = Vector3(0, 0, 5);
	//カメラノ見テイル先(注視点/参照点)
	m_refpos = Vector3(0, 0, 0);
	//カメラノ上方向ベクトル
	m_upvec = Vector3(0, 1, 0);

	//垂直方向視野角
	m_fovY = XMConvertToRadians(60.0f);
	//アスペクト比
	m_aspect = (float)width / (float)height;
	//ニアクリップ
	m_nearClip = 0.1f;
	//ファークリップ
	m_farClip = 1000.0f;


	//ビュー行列の生成
	m_view = Matrix::CreateLookAt(
		m_eyepos,m_refpos,m_upvec);

	//射影行列（プレジェクション行列）の生成
	m_proj = Matrix::CreatePerspectiveFieldOfView(
		m_fovY,//視野角(上下方向)
		m_aspect,
		m_nearClip,//ニアクリップ
		m_farClip//ファークリップ
	);
}


Camera::~Camera()
{
}

void Camera::Update()
{
	//ビュー行列の生成
	m_view = Matrix::CreateLookAt(
		m_eyepos, m_refpos, m_upvec);

	//射影行列（プレジェクション行列）の生成
	m_proj = Matrix::CreatePerspectiveFieldOfView(
		m_fovY,//視野角(上下方向)
		m_aspect,
		m_nearClip,//ニアクリップ
		m_farClip//ファークリップ
	);
}

const Matrix& Camera::GetViewMatrix()
{
	//ビュー行列を返す
	return m_view;
}

const Matrix& Camera::GetProjectionMatrix()
{
	//射影行列を返す
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
