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

    public:
        template<typename T>
        T& GetValue()
        {
            return dynamic_cast<Bindable<T>&>(*this).GetValue();
        }

        template<typename T>
        const std::string& GetName() const
        {
            return dynamic_cast<const Bindable<T>&>(*this).GetName();
        }

        template<typename T>
        const unsigned int& GetId() const
        {
            return dynamic_cast<const Bindable<T>&>(*this).GetId();
        }
};
