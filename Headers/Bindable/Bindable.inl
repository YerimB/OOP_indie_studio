#pragma once

#include "Bindable.hpp"

template<typename T>
Bindable<T>::Bindable()
{
	Create(0, "Unknown #0", static_cast<T>(0))
}

template<typename T>
Bindable<T>::Bindable(const Bindable<T>& other)
{
	Create(other.m_Id, other.m_Name, other.m_Value, other.m_OnUpdate);
}

template<typename T>
Bindable<T>::Bindable(const T& value)
{
	int randomId = std::rand();

	Create(randomId, "Unknown #" + std::to_string(randomId));
}

template<typename T>
Bindable<T>::Bindable(const unsigned int& id, const std::string& name, const T& value)
{
	Create(id, name, value);
}

template<typename T>
inline Bindable<T>::Bindable(const unsigned int& id, const T& value)
{
	Create(id, "Unknown #" + std::to_string(id), value);
}

template<typename T>
inline Bindable<T>::Bindable(const std::string& name, const T& value)
{
	int randomId = std::rand();

	Create(randomId, name, value);
}

template<typename T>
template<typename U>
Bindable<T>::Bindable(const T& value, U& callback)
{
	int randomId = std::rand();

	Create(randomId, "Unknown #" + std::to_string(randomId), value, callback);
}

template<typename T>
template<typename U>
inline Bindable<T>::Bindable(const T& value, U& callback, const unsigned int& id)
{
	Create(id, "Unknown #" + std::to_string(id), value, callback);
}

template<typename T>
template<typename U>
inline Bindable<T>::Bindable(const T& value, U& callback, const unsigned int& id, const std::string& name)
{
	Create(id, name, value, callback);
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
template<typename U>
inline void Bindable<T>::SetCallback(U& callback)
{
	m_OnUpdate = std::bind(callback, std::placeholders::_1);
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

template<typename T>
inline const std::string& Bindable<T>::GetName() const
{
	return m_Name;
}

template<typename T>
inline const unsigned int& Bindable<T>::GetId() const
{
	return m_Id;
}

template<typename T>
void Bindable<T>::Create(const unsigned int& id, const std::string& name, const T& value)
{
	m_Id = id;
	m_Name = name;
	m_Value = value;
	m_CachedValue = value;
}

template<typename T>
template<typename U>
void Bindable<T>::Create(const unsigned int& id, const std::string& name, const T& value, U& callback)
{
	m_Id = id;
	m_Name = name;
	m_Value = value;
	m_CachedValue = value;
	m_OnUpdate = std::bind(callback, std::placeholders::_1);
}