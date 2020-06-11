/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <Irrlicht/irrlicht.h>
#include <Irrlicht/driverChoice.h>
#include <Core.hpp>
#include <Thread/Thread.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


#include "./Generation/Generation.hpp"

class Map {
    public:
        Map();
        Map(ISceneManager* smgr, video::IVideoDriver* driver, std::vector<irr::io::path> arr_asset);
        ~Map();
        void CreateMap();

    protected:
    private:
        void createNewCube3D();
        void createFloor();
        void addCamera();
        Generation _generationMap;
        ISceneManager* _smgr;
        video::IVideoDriver* _driver;
        std::vector<irr::io::path> _arrAsset;
        int heightCamera = 0;
        int x = 0;
        int xActual = 0;
        int y = 0;
        int nb = 0;
        int actualAsset;
        int size_map;
        std::string str;
};

#endif /* !MAP_HPP_ */
