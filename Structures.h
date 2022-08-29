struct Players {
    std::string name;
    std::string country;
    int NetID = -1;
    int UserID = -1;
    int x = -1;
    int y = -1;
    bool gone = false;
    bool local = false;
    bool mod = false;
};

class World {
public:
     std::string name;
     int Width = 0;
     int Height = 0;
     std::vector<Players> players;
}
