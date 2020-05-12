#pragma once

#include "Bindable.hpp"

template<typename T>
Bindable<T>::Bindable()
{
	m_Value = static_cast<T>(0.0);
	m_CachedValue = static_cast<T>(0.0);
}

template<typename T>
Bindable<T>::Bindable(const Bindable<T>& other)
{
	m_Value = other.m_Value;
	m_CachedValue = other.m_CachedValue;
	m_OnUpdate = other.m_OnUpdate;
}

template<typename T>
Bindable<T>::Bindable(const T& value)
{
	m_Value = value;
	m_CachedValue = value;
}

template<typename T>
template<typename U>
Bindable<T>::Bindable(const T& value, U& callback)
{
	m_Value = value;
	m_CachedValue = value;
	m_OnUpdate = std::bind(callback, std::placeholders::_1);
}

template<typename T>
Bindable<T>& Bindable<T>::operator=(const T& value)
{
	std::lock_guard lock(m_Mutex);

	m_Value = value;
	if (m_Value != m_CachedValue) {
		if (m_OnUpdate)
			m_OnUpdate(m_Value);
	}
	m_CachedValue = m_Value;

	return *this;
}

template<typename T>
void Bindable<T>::SetValue(const T& value)
{
	std::lock_guard lock(m_Mutex);

	m_Value = value;
	if (m_Value != m_CachedValue) {
		if (m_OnUpdate)
			m_OnUpdate(m_Value);
	}
	m_CachedValue = m_Value;
}

template<typename T>
const T& Bindable<T>::GetValue() const
{
	return m_Value;
}

template<typename T>
const T& Bindable<T>::GetCachedValue() const
{
	return m_CachedValue;
}