
#include <AI/Astar.h>

Astar::Astar(std::vector<std::string> map): 
_map(map), 
_curentNode(Node(std::array<int, 2>({0, 0}), std::vector<std::array<int, 2> >(), 0, std::array<int, 2>({0, 0}))),
noway(false)
{
    std::vector<std::array<int, 2> > path;
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].length(); j++) {
            if (_map[i][j] == 'E')
                f_pos = std::array<int, 2>({i, j});
            if (_map[i][j] == 'O')
                s_pos = std::array<int, 2>({i, j});
        }
    }
    _curentNode = Node(s_pos, path, 0, f_pos);
    start();
}

std::vector<std::array<int, 2> > Astar::getPath()
{
    if (noway) {
        std::vector<std::array<int, 2> > tmp;
        tmp.push_back(s_pos);
        return tmp;
    }
    return _curentNode.getPath();
}

void Astar::openCloseNode(Node n)
{
    std::array<int, 2> pos = n.getPos();
    if (_map[pos[0] - 1][pos[1]] != '1' && _map[pos[0] - 1][pos[1]] != 'B')
        if (!_closedList.size() || !(std::find(_closedList.begin(), _closedList.end(), std::array<int, 2>({pos[0] - 1, pos[1]})) != _closedList.end()))
            _openList.push_back(Node(std::array<int, 2>({pos[0] - 1, pos[1]}), 
            _curentNode.getPath(), 
            _curentNode.getGcost() + 10, 
        f_pos));
    if (_map[pos[0] + 1][pos[1]] != '1' && _map[pos[0] + 1][pos[1]] != 'B')
        if (!_closedList.size() || !(std::find(_closedList.begin(), _closedList.end(), std::array<int, 2>({pos[0] + 1, pos[1]})) != _closedList.end()))
            _openList.push_back(Node(std::array<int, 2>({pos[0] + 1, pos[1]}), 
            _curentNode.getPath(), 
            _curentNode.getGcost() + 10, 
        f_pos));
    if (_map[pos[0]][pos[1] - 1] != '1' && _map[pos[0]][pos[1] - 1] != 'B')
        if (!_closedList.size() || !(std::find(_closedList.begin(), _closedList.end(), std::array<int, 2>({pos[0], pos[1] - 1})) != _closedList.end()))
            _openList.push_back(Node(std::array<int, 2>({pos[0], pos[1] - 1}),
            _curentNode.getPath(),
            _curentNode.getGcost() + 10,
        f_pos));
    if (_map[pos[0]][pos[1] + 1] != '1' && _map[pos[0]][pos[1] + 1] != 'B')
        if (!_closedList.size() || !(std::find(_closedList.begin(), _closedList.end(), std::array<int, 2>({pos[0], pos[1] + 1})) != _closedList.end()))
            _openList.push_back(Node(std::array<int, 2>({pos[0], pos[1] + 1}),
            _curentNode.getPath(),
            _curentNode.getGcost() + 10,
        f_pos));
}

void Astar::getClosestNode()
{
    int index = 0;
    int min_fcost = _openList[0].getFcost();
    int min_hcost = _openList[0].getHcost();
    for (int i = 0; i < _openList.size(); i++)
    {
        if (_openList[i].getFcost() < min_fcost || 
        (_openList[i].getFcost() == min_fcost && 
        _openList[i].getHcost() < min_hcost)) {
            index = i;
            min_fcost = _openList[i].getFcost();
            min_hcost = _openList[i].getHcost();
        }
    }
    _curentNode = _openList[index];
    _closedList.push_back(_curentNode.getPos());
    _openList.erase(_openList.begin() + index);
}


void Astar::start() 
{
    while (_curentNode.getPos() != f_pos) {
        openCloseNode(_curentNode);
        if (_openList.size() == 0) {
            noway = true;
            return;
        }
        getClosestNode();
    }
    std::vector<std::array<int, 2> >path = _curentNode.getPath();
}