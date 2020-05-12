#pragma once

#include <InputManager/InputManager.h>

template<typename T>
void InputManager::AddBindable(IBindable* bindable)
{
    m_Bindables.emplace(std::make_pair(bindable->GetName<T>(), CreateBindable(bindable)));
}

template<typename T>
void InputManager::AddBindable(std::unique_ptr<IBindable>& bindable)
{
    m_Bindables.emplace(std::make_pair(bindable->GetName<T>(), std::move(bindable)));
}