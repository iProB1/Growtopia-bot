#pragma once
#include "enet/include/enet.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "proton/variant.hpp"
#include "GameUpdatePacket.h"
#include "World/ObjectData.h"

class GrowtopiaBot {
public:
  	ENetPeer *peer;
  	ENetHost *client;
    World *world;
    
    std::string ServerIP;
    std::string WorldName;
    int Port;
    int TimeEnter = 0;
    
    void ConnectClient();
    void ConnectClient(std::string ServerIP, int Port);
  
    void ClientHost();
    void Init();
    void Loop();
  
    void OnConnected();
    void OnDisconnected();
    
    void OnLoginRequest();
    void OnGenericText(ENetPacket *packet);
    void OnGameMessage(std::string text);
    void OnProcessPacket(ENetEvent* event, ENetPeer* peer);
}
