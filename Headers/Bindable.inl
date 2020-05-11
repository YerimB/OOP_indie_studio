#pragma once

#include "Bindable.hpp"

template<typename T, typename U>
Bindable<T, U>::Bindable()
{
	m_Value = static_cast<T>(0.0);
	m_CachedValue = static_cast<T>(0.0);
}

template<typename T, typename U>
Bindable<T, U>::Bindable(const T& value)
{
	m_Value = value;
	m_CachedValue = value;
}

template<typename T, typename U>
Bindable<T, U>::Bindable(const T& value, U& callback)
{
	m_Value = value;
	m_CachedValue = value;
	m_OnUpdate = std::bind(callback, std::placeholders::_1);
}

template<typename T, typename U>
Bindable<T, U>& Bindable<T, U>::operator=(const T& value)
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

template<typename T, typename U>
void Bindable<T, U>::SetValue(const T& value)
{
	std::lock_guard lock(m_Mutex);

	m_Value = value;
	if (m_Value != m_CachedValue) {
		if (m_OnUpdate)
			m_OnUpdate(m_Value);
	}
	m_CachedValue = m_Value;
}

template<typename T, typename U>
const T& Bindable<T, U>::GetValue() const
{
	return m_Value;
}

template<typename T, typename U>
const T& Bindable<T, U>::GetCachedValue() const
{
	return m_CachedValue;
}