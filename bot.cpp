#pragma once
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include <limits>
#include <math.h>
#include <string>
#include <iostream>
#include <regex>
#include <iterator>
#include <algorithm>
#include <ctime>
#include "Utils.h"
#include "bot.h"
#include "enet/include/enet.h"
#include "proton/rtparam.hpp"

void GrowtopiaBot::ClientHost()
{
    ENetEvent event;
    while (enet_host_service(client, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_NONE: break;
            case ENET_EVENT_TYPE_CONNECT: OnConnected(); break;
            case ENET_EVENT_TYPE_DISCONNECT: OnDisconnected(); break;
            case ENET_EVENT_TYPE_RECEIVE: OnProcessPacket(&event, peer); enet_packet_destroy(event.packet); break;
            default: break;
        }
    }
    Loop();
}
void GrowtopiaBot::Init() {
	ConnectClient(); // Connect to Client
	std::cout << std::flush;
}

void GrowtopiaBot::Loop() {
   if (TimeEnter > 200 && world.name != WorldName) {
	if (WorldName == "" || WorldName == "-") {
	  TimeEnter = 0;
	} else {
  	  SendPacket(3, "action|join_request\nname|" + WorldName, peer); // sends join request
    	  world.players.clear(); // Clears World player's data
	}
     TimeEnter = 0;
     world.name = WorldName; // sets world name
   }
}

void GrowtopiaBot::OnConnected()
{
        std::cout << "Bot Connected Successfully!\n"; // bot connection
}

void GrowtopiaBot::OnDisconnected()
{
	Init(); // Reconnect to game if disconnected
}

