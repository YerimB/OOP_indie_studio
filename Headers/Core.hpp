#pragma once

#include <memory>
#include <string>
#include <Irrlicht/irrlicht.h>
#include <ECS/Hash.h>

// Irrlicht

using Vector2f = irr::core::vector2df;
using Vector2i = irr::core::vector2di;

using Vector3f = irr::core::vector3df;
using Vector3i = irr::core::vector3di;

using Dimension2f = irr::core::dimension2df;
using Dimension2i = irr::core::dimension2di;
using Dimension2u = irr::core::dimension2du;

using Rectf = irr::core::rectf;
using Recti = irr::core::recti;

using GuiFont = irr::gui::IGUIFont;
using GuiText = irr::gui::IGUIStaticText;

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
