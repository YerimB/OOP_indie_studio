#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include "Node.h"

class Astar {
    public:
        Astar(std::vector<std::string> map);
        std::vector<std::array<int, 2> > getPath(); 
    private:
        void openCloseNode(Node n);
        void getClosestNode();
        void start();
        std::vector<std::string> _map;
        std::vector<Node> _openList;
        bool noway;
        std::vector<std::array<int, 2> > _closedList;
        std::array<int, 2> s_pos;
        Node _curentNode;
        std::array<int, 2> f_pos;
};