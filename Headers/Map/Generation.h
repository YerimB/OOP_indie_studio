#pragma once
//
// Created by Yuno on 18/05/2020.
//

#ifndef TEK2_GENERATION_HPP
#define TEK2_GENERATION_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <array>

class Generation {
    public:
        Generation(const int &size);
        void refresh();
        std::vector<std::string> GetMap() const;

    private:
        void generate_maze();
        bool check_maze(std::vector<std::vector<int> > maze_index);
        void init_map();
        void generate();
        int _size;
        std::vector<std::string> _map;

};


#endif //TEK2_GENERATION_HPP