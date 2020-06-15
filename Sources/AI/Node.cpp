#include <AI/Node.h>

Node::Node(std::array<int, 2> pos, std::vector<std::array<int, 2> > path, int pGcost, std::array<int, 2> f_pos): _path(path)
{
    _pos = pos;
    _gCost = path.size() * 10;
    _path.push_back(pos);

    _hCost = 10 * static_cast<int>(sqrt(pow(pos[0] - f_pos[0], 2) + pow(pos[1] - f_pos[1], 2)));
    _fCost = _hCost + _gCost;
}

int Node::getGcost()
{
    return _gCost;
}

int Node::getHcost()
{
    return _hCost;
}

int Node::getFcost()
{
    return _fCost;
}

std::array<int, 2> Node::getPos()
{
    return _pos;
}

std::vector<std::array<int, 2> >Node::getPath() 
{
    return _path;
}