#pragma once

typedef unsigned int CRC32_t;
class IInput
{
public:
	class CVerifiedUserCmd
	{
	public:
		CUserCmd	m_cmd;
		CRC32_t		m_crc;
	};
public:
	void* pvftable;						//0x0000 
	bool m_fTrackIRAvailable;			//0x0004 
	bool m_fMouseInitialized;			//0x0005 
	bool m_fMouseActive;				//0x0006 
	bool m_fJoystickAdvancedInit;		//0x0007 
	char pad_0x0008[0xA0];				//0x0008
	bool m_fCameraInterceptingMouse;	//0x00A8
	bool m_fCameraInThirdPerson;		//0x00A9
	bool m_fCameraMovingWithMouse;		//0x00AA
	//bool unknown;						//AB
	Vector m_vecCameraOffset;			//AC
	//char pad3[0x38];
	bool m_fCameraDistanceMove;			//B8
	int m_nCameraOldX;					//B9
	int m_nCameraOldY;					//BD
	int m_nCameraX;						//C1
	int m_nCameraY;						//C5
	bool m_CameraIsOrthographic;		//C9
	Vector m_angPreviousViewAngles;		//CA
	Vector m_angPreviousViewAnglesTilt;	//D6
	float m_flLastForwardMove;			//DA
	int m_nClearInputState;				//DE
	CUserCmd* m_pCommands;				// 
	CVerifiedUserCmd* m_pVerifiedCommands;
	VFUNC( 8, GetUserCmd( int slot, int seq ), CUserCmd*( __thiscall* )( void*, int, int ) )( slot, seq )
};

extern IInput* g_pInput;
