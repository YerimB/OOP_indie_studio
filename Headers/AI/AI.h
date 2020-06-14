#pragma once
#include "Astar.h"
#include<algorithm>
#define BOMBRANGE 5

class AI {
    public:
        AI(std::vector<std::string> map);
        std::array<int, 2> getDir();
    private:
        bool isInBombRange();
        void getSafePath();
        void updateBombMap(std::vector<std::string> &map, std::array<int, 2> bpos);
        std::vector<std::string> _map;
        std::vector<std::string> _cleanMap;
        std::vector<std::array<int, 2> > _path;

};