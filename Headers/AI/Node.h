#pragma once
#include <vector>
#include <array>
#include <cmath> 

class Node {
    public:
        Node(std::array<int, 2> pos, std::vector<std::array<int, 2> > path, int pGcost, std::array<int, 2> f_pos);
        int getGcost(); //distance from stat node
        int getHcost(); //distance from end node
        int getFcost(); //Gcost + Hcost
        std::array<int, 2> getPos();
        std::vector<std::array<int, 2> > getPath();
    private:
        int _gCost;
        int _hCost;
        int _fCost;
        std::array<int, 2> _pos;
        std::vector<std::array<int, 2> >_path;
};