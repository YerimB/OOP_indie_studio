//
// Created by Yuno on 18/05/2020.
//

#include "Generation.hpp"

Generation::Generation(int size) : _size(size)
{
    std::srand(std::time(nullptr));
    init_map();
    generate();
}
std::string Generation::get_map()
{
    std::string tmp;
    for (int i = 0; i < _map.size(); i++) {
    	tmp += _map[i] + "\n";
    }
	return tmp;
}

void Generation::refresh()
{
    _map.clear();
    init_map();
    generate();
}

void Generation::init_map()
{
    std::string tmp = "";
    for (int i = 0; i < _size / 4; i++)
        tmp += "0";
    for (int i = 0; i < _size / 4; i++)
        _map.push_back(tmp);
    generate();
}

void Generation::generate()
{
    int tmp_size = _size / 4;
    for (int i = 0; i < _size / 2; i++) {
        _map[std::rand() / ((RAND_MAX + 1u) / tmp_size)][std::rand() / ((RAND_MAX + 1u) / tmp_size)] = \
            i < _size / 4 ? '1' : '2';
    }
    for (int i = 0; i < _map.size(); i++) {
        std::string tmp = _map[i];
        std::reverse(tmp.begin(), tmp.end());
        _map[i] += tmp;
    }
    for (int i = _map.size() - 1; i >= 0; i--) {
        _map.push_back(_map[i]);
    }
}