#pragma once

#include <memory>
#include <Irrlicht/irrlicht.h>

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

// C++

typedef unsigned long EntityId;
typedef unsigned long ComponentId;

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

// Auto Counter

struct ComponentAutoCounter {};

#define COUNTER_READ_CRUMB( TAG, RANK, ACC ) counter_crumb( TAG(), constant_index< RANK >(), constant_index< ACC >() )
#define COUNTER_READ( TAG ) COUNTER_READ_CRUMB( TAG, 1, COUNTER_READ_CRUMB( TAG, 2, COUNTER_READ_CRUMB( TAG, 4, COUNTER_READ_CRUMB( TAG, 8, \
    COUNTER_READ_CRUMB( TAG, 16, COUNTER_READ_CRUMB( TAG, 32, COUNTER_READ_CRUMB( TAG, 64, COUNTER_READ_CRUMB( TAG, 128, 0 ) ) ) ) ) ) ) )

#define COUNTER_INC( TAG ) \
constexpr \
constant_index< COUNTER_READ( TAG ) + 1 > \
counter_crumb( TAG, constant_index< ( COUNTER_READ( TAG ) + 1 ) & ~ COUNTER_READ( TAG ) >, \
                                                constant_index< ( COUNTER_READ( TAG ) + 1 ) & COUNTER_READ( TAG ) > ) { return {}; }

#define COUNTER_LINK_NAMESPACE( NS ) using NS::counter_crumb;

template< std::size_t n >
struct constant_index : std::integral_constant< std::size_t, n > {};

template< typename id, std::size_t rank, std::size_t acc >
constexpr constant_index< acc > counter_crumb(id, constant_index< rank >, constant_index< acc >) { return {}; }