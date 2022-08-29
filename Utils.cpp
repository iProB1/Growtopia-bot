#include "Utils.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <regex>

std::vector<std::string> Utils::Split(const std::string& str, const std::string& delimiter) {
	std::vector<std::string> arr;
	int strleng = str.length();
	int delleng = delimiter.length();
	if (delleng == 0) return arr;
	int i = 0;
	int k = 0;
	while (i < strleng) {
		int j = 0;
		while (i + j < strleng && j < delleng && str[i + j] == delimiter[j]) j++;
		if (j == delleng) {
			arr.push_back(str.substr(k, i - k));
			i += delleng;
			k = i;
		}
		else i++;
	}
	arr.push_back(str.substr(k, i - k));
	return arr;
}

int Utils::GetMessageType(ENetPacket* packet) {
     int result;
     if (packet->dataLength > 3u) {
        result = *(packet->data);
     } else {
	cout << "Bad packet length, ignoring message" << endl;
       	result = 0;
     }
     return result;
}

gameupdatepacket_t* Utils::GetStruct(ENetPacket* packet) {
    if (packet->dataLength < sizeof(gameupdatepacket_t) - 4)
        return nullptr;
    gametankpacket_t* tank = reinterpret_cast<gametankpacket_t*>(packet->data);
    gameupdatepacket_t* gamepacket = reinterpret_cast<gameupdatepacket_t*>(packet->data + 4);
    if (gamepacket->m_packet_flags & 8) {
        if (packet->dataLength < gamepacket->m_data_size + 60) {
            printf("got invalid packet. (too small)\n");
            return nullptr;
        }
        return reinterpret_cast<gameupdatepacket_t*>(&tank->m_data);
    } else
        gamepacket->m_data_size = 0;
    return gamepacket;
}
