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
    
    std::string WorldName;
    int TimeEnter = 0;
      
    void ClientHost();
    void Init();
    void Loop();
  
    void OnConnected();
    void OnDisconnected();
    
    void OnLoginRequest();
    void OnGenericText(ENetPacket *packet);
    void OnGameMessage(std::string text);
    void OnProcessPacket(ENetEvent* event, ENetPeer* peer);
    void OnPlayerState(gameupdatepacket_t* packet);
    void OnPacketCallFunction(gameupdatepacket_t* packet);
    void OnTileChangeRequest(gameupdatepacket_t* packet);
    void OnSendMapData(gameupdatepacket_t* packet);
    void OnSendTileUpdateData(gameupdatepacket_t* packet);
    void OnSendInventoryState(gameupdatepacket_t* packet);
    void OnSendTreeState(gameupdatepacket_t* packet);
    void OnModifyItemInventory(gameupdatepacket_t* packet);
    void OnItemChangeObject(gameupdatepacket_t* packet);
}
