#pragma once

class player_log : public singleton<player_log>
{
public:
	void log( const ClientFrameStage_t stage );
	player_log_t& get_log( const int index );
	
	//好像是过滤所有的记录? 在aimbot开始遍历记录之前调用了一次
	void filter_records( bool cm = false );
private:
	player_log_t logs[ 65 ];
};