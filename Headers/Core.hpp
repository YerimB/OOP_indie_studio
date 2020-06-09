#pragma once

#include <memory>
#include <string>

#include <Irrlicht/irrlicht.h>
#include <ECS/Hash.h>

// Irrlicht

using SceneManager = irr::scene::ISceneManager;

using Vector2f = irr::core::vector2df;
using Vector2i = irr::core::vector2di;

using Vector3f = irr::core::vector3df;
using Vector3i = irr::core::vector3di;

using Dimension2f = irr::core::dimension2df;
using Dimension2i = irr::core::dimension2di;
using Dimension2u = irr::core::dimension2du;

using Position2i = irr::core::position2di;

using Rectf = irr::core::rectf;
using Recti = irr::core::recti;

using GuiEnvironment = irr::gui::IGUIEnvironment;
using GuiFont = irr::gui::IGUIFont;
using GuiText = irr::gui::IGUIStaticText;
using GuiImage = irr::gui::IGUIImage;
using GuiButton = irr::gui::IGUIButton;

using Color = irr::video::SColor;
using Colorf = irr::video::SColorf;
using Texture = irr::video::ITexture;

// C++

typedef unsigned int EntityId;
typedef unsigned int ComponentId;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Unique<T> CreateUnique(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Shared<T> CreateShared(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T>
using Weak = std::weak_ptr<T>;

// GLOBAL VARIABLES

typedef struct GameGlobalVariables_s
{
	bool sceneChanged = false;
	uint newScene = (-1);
	// Add vars if needed.
} GameVars_t;

static GameVars_t GLOBALVARS;