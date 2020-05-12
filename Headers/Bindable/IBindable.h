#pragma once

#include <Bindable/Bindable.hpp>

class IBindable
{
    public:
        virtual ~IBindable() = default;

    public:
        template<typename T>
        void SetValue(const T& value)
        {
            dynamic_cast<Bindable<T>&>(*this).SetValue(value);
        }
};
