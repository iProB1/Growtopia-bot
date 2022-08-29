#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include "enet/include/enet.h"
#include "GameUpdatePacket.h"
#include "proton/variant.hpp"

namespace Utils {
	std::vector<std::string> Split(const std::string &str,const std::string &delimiter);
	int GetMessageType(ENetPacket* packet)
	gameupdatepacket_t* GetStruct(ENetPacket* packet);
};
