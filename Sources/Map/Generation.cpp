#include <Map/Generation.h>

Generation::Generation()
{
    _size = 0;
}

Generation::Generation(int size) : _size(size)
{
    std::srand(std::time(nullptr));
    InitMap();
    Generate();
}

const std::vector<std::string>& Generation::GetMap() const
{
    return _map;
}

void Generation::Refresh()
{
    _map.clear();
    InitMap();
    Generate();
}

void Generation::InitMap()
{
    std::string tmp = "";
    for (int i = 0; i < _size / 4; i++)
        tmp += "0";
    for (int i = 0; i < _size / 4; i++)
        _map.push_back(tmp);
    Generate();
}

void Generation::Generate()
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