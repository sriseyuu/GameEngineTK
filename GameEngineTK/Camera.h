/// <summary>
/// カメラを制御するクラス
/// </summary>
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
class Camera
{
protected://メンバ変数を書く

	//カメラの位置(視点座標)
	DirectX::SimpleMath::Vector3 m_eyepos;
	//カメラの見ている先(注視点/参照点)
	DirectX::SimpleMath::Vector3 m_refpos;
	//カメラの上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upvec;

	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;

	//垂直方向視野角
	float m_fovY ;
	//アスペクト比
	float m_aspect;
	//ニアクリップ
	float m_nearClip;
	//ファークリップ
	float m_farClip;

	//射影行列
	DirectX::SimpleMath::Matrix m_proj;

public://メンバ関数
	//コンストラクタ
	Camera(int width, int height);
	//デストラクタ
	virtual ~Camera();

	//更新処理
	virtual void Update();

	//ビュー行列の取得
	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	//射影行列の取得
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//視点座標の設定
	void SetEyePos(DirectX::SimpleMath::Vector3 eyepos);

	//注視点の設定
	void SetRefPos(DirectX::SimpleMath::Vector3 refpos);

	//上方向ベクトルの設定
	void SetUpVec(DirectX::SimpleMath::Vector3 upvec);

	//垂直方向視野角の設定
	void SetFovY(float fovY);

	//アスペクト比の設定
	void SetAspect(float aspect);

	//ニアクリップ設定
	void SetNearClip(float nearClip);

	//ファークリップ設定
	void SetFarClip(float farClip);
};
