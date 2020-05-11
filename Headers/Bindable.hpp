#pragma once

#include <functional>
#include <mutex>

template<typename T, typename U>
class Bindable
{
	using Callback = std::function<void(T)>;

	public:
		Bindable();
		Bindable(const T& value);

		Bindable(const T& value, U& callback);
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
		std::mutex m_Mutex;
};

#include "Bindable.inl"