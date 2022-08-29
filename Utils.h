#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include "enet/include/enet.h"
#include "GameUpdatePacket.h"
#include "proton/variant.hpp"

namespace Utils {
	std::vector<std::string> Split(const std::string &str,const std::string &delimiter);
	std::string Random(int len);
	std::string GenerateMac();
	int GetMessageType(ENetPacket* packet)
	gameupdatepacket_t* GetStruct(ENetPacket* packet);
	bool Replace(std::string& str, const std::string& from, const std::string& to);
	bool HandleDelay(uint64_t& alpha, int beta);
	uint64_t GetTime();
	bool is_number(const std::string& s);
};
