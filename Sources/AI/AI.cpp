#include <AI/AI.h>

AI::AI(std::vector<std::string> map): _map(map), _cleanMap(map)
{
    for (int i = 0; i < _cleanMap.size(); i++) {
        for (int j = 0; j < _cleanMap[i].length(); j++)
            if (_cleanMap[i][j] == 'E') _cleanMap[i][j] = '0';
    }
    if (isInBombRange()) {
        getSafePath();
    }
    else
    {
        Astar toto(_map);
        _path = toto.getPath();
    }

}

std::array<int, 2> AI::getDir()
{
    if (_path.size() < 2)
        return std::array<int, 2>({ 0, 0 });
    return std::array<int, 2>({
		_path[0][0] - _path[1][0],
        _path[0][1] - _path[1][1]
    });
}

void AI::updateBombMap(std::vector<std::string> &bmap, std::array<int, 2> b_pos) 
{
    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;
    for (int i = 0; i < BOMBRANGE ; i++) {
        if (down && bmap[b_pos[0] + i][b_pos[1]] == '0') bmap[b_pos[0] + i][b_pos[1]] = 'W';
        if (down && bmap[b_pos[0] + i][b_pos[1]] == '1') down = false;
        if (up && bmap[b_pos[0] - i][b_pos[1]] == '0') bmap[b_pos[0] - i][b_pos[1]] = 'W';
        if (up && bmap[b_pos[0] - i][b_pos[1]] == '1') up = false;
        if (right && bmap[b_pos[0]][b_pos[1] + i] == '0') bmap[b_pos[0]][b_pos[1] + i] = 'W';
        if (right && bmap[b_pos[0]][b_pos[1] + i] == '1') right = false;
        if (left && bmap[b_pos[0]][b_pos[1] - i] == '0') bmap[b_pos[0]][b_pos[1] - i] = 'W';
        if (left && bmap[b_pos[0]][b_pos[1] - i] == '1') left = false;
    }
}

void AI::getSafePath()
{
    std::vector<std::string> bomb_map = _map;
    for(int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < bomb_map[i].length(); j++) {
            if (bomb_map[i][j] == 'B') {
                updateBombMap(bomb_map, std::array<int, 2>({i, j}));
            }
        }
    }


    std::vector<std::vector<std::array<int, 2> > > paths;
    for (int i = 0; i < bomb_map.size(); i++) {
        for (int j = 0; j < bomb_map[i].length(); j++) {
            if (bomb_map[i][j] == '0') {
                _cleanMap[i][j] = 'E';
                Astar tmp(_cleanMap);
                paths.push_back(tmp.getPath());
                _cleanMap[i][j] = ' ';
            }
        }
    }
    int index = 0;
    if (paths.size() == 0) return;
    int min = paths[0].size();
    for (int i = 0; i < paths.size(); i++){
        if (paths[i].size() < min) {
            index = i;
            min = paths[i].size();
        }
    }
    _path = paths[index];
}

bool AI::isInBombRange() 
{
    std::array<int, 2> p_pos;
    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;
    for (int i = 0; i < _map.size(); i++){
        for (int j = 0; j < _map[i].length(); j++)
            if (_map[i][j] == 'O')
                p_pos = std::array<int, 2>({i, j});
    }
    if (p_pos[0] < 0 && p_pos[1] < 0)
        return false;
    for (int i = 0; i < BOMBRANGE ; i++) {
        if (down && _map[p_pos[0] + i][p_pos[1]] == 'B') return true;
        if (down && _map[p_pos[0] + i][p_pos[1]] == '1') down = false;
        if (up && _map[p_pos[0] - i][p_pos[1]] == 'B') return true;
        if (up && _map[p_pos[0] - i][p_pos[1]] == '1') up = false;
        if (right && _map[p_pos[0]][p_pos[1] + i] == 'B') return true;
        if (right && _map[p_pos[0]][p_pos[1] + i] == '1') right = false;
        if (left && _map[p_pos[0]][p_pos[1] - i] == 'B') return true;
        if (left && _map[p_pos[0]][p_pos[1] - i] == '1') left = false;
    }
    return false;
}