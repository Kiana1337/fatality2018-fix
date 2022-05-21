#pragma once

class INetChannel;
class INetMessage
{
public:
	virtual	~INetMessage() {};

	// Use these to setup who can hear whose voice.
	// Pass in client indices (which are their ent indices - 1).

	virtual void	SetNetChannel( INetChannel * netchan ) = 0; // netchannel this message is from/for
	virtual void	SetReliable( bool state ) = 0;	// set to true if it's a reliable message

	virtual bool	Process( void ) = 0; // calles the recently set handler to process this message

	virtual	bool	ReadFromBuffer( bf_read &buffer ) = 0; // returns true if parsing was OK
	virtual	bool	WriteToBuffer( void* buffer ) = 0;	// returns true if writing was OK

	virtual bool	IsReliable( void ) const = 0;  // true, if message needs reliable handling

	virtual int				GetType( void ) const = 0; // returns module specific header tag eg svc_serverinfo
	virtual int				GetGroup( void ) const = 0;	// returns net message group of this message
	virtual const char		*GetName( void ) const = 0;	// returns network message name, eg "svc_serverinfo"
	virtual INetChannel		*GetNetChannel( void ) const = 0;
	virtual const char		*ToString( void ) const = 0; // returns a human readable string about message content
};



class CClockDriftMgr
{
public:
	float m_ClockOffsets[ 17 ];   //0x0000
	uint32_t m_iCurClockOffset; //0x0044
	uint32_t m_nServerTick;     //0x0048
	uint32_t m_nClientTick;     //0x004C
}; //Size: 0x0050

class IClientState
{
public:
	void ForceFullUpdate()
	{
		m_nDeltaTick = -1;
	};

	char pad_0000[156];
	INetChannel* m_NetChannel;
	int m_nChallengeNr;
	char pad_00A4[100];
	int m_nSignonState;
	int signon_pads[2];
	float m_flNextCmdTime;
	int m_nServerCount;
	int m_nCurrentSequence;
	int musor_pads[2];
	CClockDriftMgr m_ClockDriftMgr;
	int m_nDeltaTick;
	bool m_bPaused;
	char paused_align[3];
	int m_nViewEntity;
	int m_nPlayerSlot;
	int bruh;
	char m_szLevelName[260];
	char m_szLevelNameShort[80];
	char m_szGroupName[80];
	char pad_032[92];
	int m_nMaxClients;
	char pad_0314[18828];
	float m_nLastServerTickTime;
	bool m_bInSimulation;
	char pad_4C9D[3];
	int m_nOldTickCount;
	float m_flTickReminder;
	float m_flFrametime;
	int m_nLastOutgoingCommand;
	int m_nChokedCommands;
	int m_nLastCommandAck;
	int m_nPacketEndTickUpdate;
	int m_nCommandAck;
	int m_nSoundSequence;
	char pad_4CCD[76];
	QAngle viewangles;
	int pads[54];
	CEventInfo* m_Events;
}; 

extern IClientState* g_pClientState;