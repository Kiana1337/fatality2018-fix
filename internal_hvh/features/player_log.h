#pragma once

class player_log : public singleton<player_log>
{
public:
	void log( const ClientFrameStage_t stage );
	player_log_t& get_log( const int index );
	
	//�����ǹ������еļ�¼? ��aimbot��ʼ������¼֮ǰ������һ��
	void filter_records( bool cm = false );
private:
	player_log_t logs[ 65 ];
};