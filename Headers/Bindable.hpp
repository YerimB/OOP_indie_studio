#pragma once

#include <functional>
#include <tuple>

template<typename T, typename U, typename ... UArgs>
class Bindable
{
	using Callback = std::function<U(UArgs...)>;

	public:
		Bindable();
		Bindable(const T& value);

		Bindable(const T& value, U& callback, UArgs&& ... args);
		~Bindable() = default;

	public:
		void SetValue(const T& value);

	public:
		const T& GetValue() const;
		const T& GetCachedValue() const;

	public:
		Bindable& operator=(const T& value);

	private:
		Callback m_OnUpdate;
		T m_Value;
		T m_CachedValue;
};

#include "Bindable.inl"