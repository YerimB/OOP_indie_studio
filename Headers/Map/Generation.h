#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Generation
{
    public:
        Generation();
        Generation(int size);

    public:
        void Refresh();
        const std::vector<std::string>& GetMap() const;

    private:
        void InitMap();
        void Generate();

    private:
        int _size;
        std::vector<std::string> _map;

};
