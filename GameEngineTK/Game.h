//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Keyboard.h>
#include "DebugCamera.h"

#include "FollowCamera.h"

#define MAX_DISTANCE 100

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//PrimitiveBatch�̍쐬
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;

	//BasicEffect�̍쐬
	std::unique_ptr<DirectX::BasicEffect> m_effect;

	//���̓��C�A�E�g�̍쐬
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	//�ėp�X�e�[�g�ݒ�
	std::unique_ptr<DirectX::CommonStates> m_states;

	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//�v���W�F�N�V�����s��
	DirectX::SimpleMath::Matrix m_proj;

	//�f�o�b�O�J����
	std::unique_ptr<DebugCamera> m_debugCamera;

	//�G�t�F�N�g�t�@�N�g���[
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	
	//�X�J�C�h�[�����f��
	std::unique_ptr<DirectX::Model> m_modelSkyDome;
	//�n�ʃ��f��
	std::unique_ptr<DirectX::Model> m_modelGround;
	//�e�B�[�|�b�g���f��
	std::unique_ptr<DirectX::Model> m_modelTeapot;
	//�������f��
	std::unique_ptr<DirectX::Model> m_modelHead;
	DirectX::SimpleMath::Vector3 m_headPos;
	float m_headRote;

	//�������[���h���W
	DirectX::SimpleMath::Matrix m_worldHead;

	int m_count;

	//���_����̊p�x
	float m_rotation[20];
	//�e�B�[�|�b�g�̌��_����̋���
	int m_distance[20];
	//�{��
	float m_magnification;
	//�L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	std::unique_ptr<FollowCamera> m_camera;
};