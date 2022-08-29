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
}
