#pragma once

#include <functional>
#include <mutex>
#include <memory>

#include <Bindable/IBindable.h>

template<typename T>
class Bindable : public IBindable
{
	using Callback = std::function<void(T)>;

	public:
		Bindable();
		Bindable(const Bindable<T>& other);
		Bindable(const T& value);

		template<typename U>
		Bindable(const T& value, U& callback);
		~Bindable() override = default;

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

using UniqueBindable = std::unique_ptr<IBindable>;

template<typename T, typename ... Args>
constexpr UniqueBindable CreateBindable(Args&& ... args)
{
	return std::make_unique<Bindable<T>>(std::forward<Args>(args)...);
}

#include "Bindable.inl"