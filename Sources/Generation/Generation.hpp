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

class Generation {
public:
    Generation();
    Generation(int size);
    void refresh();
    std::string get_map();

private:
    void init_map();
    void generate();
    int _size;
    std::vector<std::string> _map;

};


#endif //TEK2_GENERATION_HPP