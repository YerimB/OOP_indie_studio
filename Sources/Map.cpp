/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
}

Map::Map(ISceneManager* smgr, video::IVideoDriver* driver, std::vector<irr::io::path> arr_asset)
{
    size_map = 20;
    _smgr = smgr;
    _driver = driver;
    _arrAsset = arr_asset;
    _generationMap = Generation(size_map);
    str = _generationMap.get_map();

    heightCamera = size_map * 10;
    std::string lenghtX = std::to_string(size_map);
    x = (int)lenghtX[1] - '0';
    if (x == 0) x = -40 * ((int)lenghtX[0] - '0');
    else x = -x * 10;
    xActual = x - 10;
    y = x - 10;
    actualAsset = 0;
}

Map::~Map()
{
}

void Map::createNewCube3D()
{
    _smgr->addCubeSceneNode(10.F, nullptr, nb, core::vector3df(x, 0, y));
    _smgr->getSceneNodeFromId(nb)->setMaterialTexture(0, _driver->getTexture(_arrAsset.at(actualAsset)));
    _smgr->getSceneNodeFromId(nb)->setMaterialFlag(video::EMF_LIGHTING, false);
}

void Map::CreateMap()
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            x = -90;
            y += 10;
        }

        if (str[i] == '1')
        {
            actualAsset = 0;
            createNewCube3D();
            nb += 1;
        }

        if (str[i] == '2')
        {
            actualAsset = 1;
            createNewCube3D();
            nb += 1;
        }

        if (str[i] == '3')
        {
            actualAsset = 2;
            createNewCube3D();
            nb += 1;
        }
        x += 10;
    }
    createFloor();
    addCamera();
}

void Map::createFloor()
{
    core::vector3df pos = _smgr->getSceneNodeFromId(size_map / 2)->getAbsolutePosition();

    std::cout << size_map << std::endl;
    _smgr->addCubeSceneNode(10.F, nullptr, -2, core::vector3df(pos.X, 0, pos.Y), core::vector3df(0, 0, 0), core::vector3df(size_map - 1, 0, size_map - 1));
    _smgr->getSceneNodeFromId(-2)->setMaterialTexture(0, _driver->getTexture(_arrAsset.at(3)));
    _smgr->getSceneNodeFromId(-2)->setMaterialFlag(video::EMF_LIGHTING, false);

}

void Map::addCamera()
{
    _smgr->addCameraSceneNode(0, vector3df(0, heightCamera, 10), vector3df(0,0,0));
}