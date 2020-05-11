#pragma once

#include "Bindable.hpp"

template<typename T, typename U, typename ... UArgs>
Bindable<T, U, UArgs ...>::Bindable()
{
	m_Value = static_cast<T>(0.0);
	m_CachedValue = static_cast<T>(0.0);
}

template<typename T, typename U, typename ... UArgs>
Bindable<T, U, UArgs ...>::Bindable(const T& value)
{
	m_Value = value;
	m_CachedValue = value;
}

template<typename T, typename U, typename ... UArgs>
Bindable<T, U, UArgs ...>::Bindable(const T& value, U& callback, UArgs&& ... args)
{
	m_Value = value;
	m_CachedValue = value;
	m_OnUpdate = std::bind(callback, this, std::placeholders::_1, std::forward<UArgs>(args)...);
}

template<typename T, typename U, typename ... UArgs>
Bindable<T, U, UArgs ...>& Bindable<T, U, UArgs ...>::operator=(const T& value)
{
	m_Value = value;

	if (m_Value != m_CachedValue)
		m_OnUpdate();

	m_CachedValue = m_Value;

	return *this;
}

template<typename T, typename U, typename ... UArgs>
void Bindable<T, U, UArgs ...>::SetValue(const T& value)
{
	m_Value = value;

	if (m_Value != m_CachedValue)
		m_OnUpdate();

	m_CachedValue = m_Value;
}

template<typename T, typename U, typename ... UArgs>
const T& Bindable<T, U, UArgs ...>::GetValue() const
{
	return m_Value;
}

template<typename T, typename U, typename ... UArgs>
const T& Bindable<T, U, UArgs ...>::GetCachedValue() const
{
	return m_CachedValue;
}