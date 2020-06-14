//
// Created by Yuno on 18/05/2020.
//

#include <Map/Generation.h>

Generation::Generation(const int &size) : _size(size)
{
    std::srand(std::time(nullptr));
    init_map();
}

std::vector<std::string> Generation::GetMap() const
{
    return this->_map;
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
    std::string wall = "";
    for (int i = 0; i < _size / 2; i++)
        wall += "1";
    for (int i = 0; i < _size / 2; i++)
        tmp += i % 2 == 0 ? "2" : "1";
    for (int i = 0; i < _size / 2; i++) {
        if (i % 2 == 0)
            _map.push_back(tmp);
        else
            _map.push_back(wall);
    }
    generate();
}

bool Generation::check_maze(std::vector<std::vector<int> > map_index)
{
    int fvalue = map_index[0][0];
    for (int i = 0; i < map_index.size(); i++) {
        for (int j = 0; j < map_index[i].size(); j++) {
            if (map_index[i][j] != fvalue && map_index[i][j] != map_index.size() - 1) return false;
        }
    }
    return true;
}

void Generation::generate_maze()
{
    int nb_tiles = _map.size() / 2 + (_map.size() % 2 == 0 ? 0 : 1);
    std::vector<std::vector<int> > map_index;
    int index = 0;
    for (int i = 0; i < nb_tiles; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < nb_tiles; j++)
            tmp.push_back(index++);
        map_index.push_back(tmp);
    }
    while (!check_maze(map_index)) {
        int x = 1 + std::rand() / ((RAND_MAX + 1u) / (map_index.size() - 1));
        int y = std::rand() / ((RAND_MAX + 1u) / (map_index.size() - 1));
        std::array<int, 2> dir;
        int rand_index = std::rand() / ((RAND_MAX + 1u) / 2);
        if (rand_index == 0)
            dir = { -1, 0 };
        else if (rand_index == 1)
            dir = { 0, 1 };
        if (map_index[x][y] == map_index[x + dir[0]][y + dir[1]])
            continue;
        int rvalue = map_index[x + dir[0]][y + dir[1]];
        for (int i = 0; i < map_index.size(); i++) {
            for (int j = 0; j < map_index[i].size(); j++) {
                if (map_index[i][j] == map_index[x][y])
                    map_index[i][j] = rvalue;
            }
        }
        _map[x * 2 + dir[0]][y * 2 + dir[1]] = '2';
    }

}

void Generation::generate()
{
    generate_maze();
    int m_size = _map.size() - 2;
    _map[m_size][m_size] = '0';
    _map[m_size][m_size - 1] = '0';
    _map[m_size - 1][m_size] = '0';
    _map[1][m_size] = '2';
	
    for (int i = 0; i < _map.size(); i++) {
        std::string tmp = _map[i];
        std::reverse(tmp.begin(), tmp.end());
        _map[i] = tmp + _map[i];
    }
    std::vector<std::string> tmp = _map;
    std::reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < _map.size(); i++)
    {
        tmp.push_back(_map[i]);
    }
    _map = tmp;
}