#pragma once

#include <functional>
#include <mutex>
#include <memory>
#include <cstdlib>
#include <ctime>

#include <Bindable/IBindable.h>

template<typename T>
class Bindable : public IBindable
{
	using Callback = std::function<void(T)>;

	public:
		Bindable();
		~Bindable() override = default;

	public:
		Bindable(const Bindable<T>& other);
		Bindable(const T& value);
		Bindable(const unsigned int& id, const std::string& name, const T& value);
		Bindable(const unsigned int& id, const T& value);
		Bindable(const std::string& name, const T& value);

		template<typename U>
		Bindable(const T& value, U& callback);
		template<typename U>
		Bindable(const T& value, U& callback, const unsigned int& id);
		template<typename U>
		Bindable(const T& value, U& callback, const unsigned int& id, const std::string& name);

	public:
		void SetValue(const T& value);
		
		template<typename U>
		void SetCallback(U& callback);

	public:
		const T& GetValue() const;
		const T& GetCachedValue() const;
		const std::string& GetName() const;
		const unsigned int& GetId() const;

	public:
		Bindable& operator=(const T& value);

	private:
		void Create(const unsigned int& id, const std::string& name, const T& value);

		template<typename U>
		void Create(const unsigned int& id, const std::string& name, const T& value, U& callback);

	private:
		unsigned int m_Id;
		std::string m_Name;
		T m_Value;
		T m_CachedValue;
		std::mutex m_Mutex;
		Callback m_OnUpdate;
};

using UniqueBindable = std::unique_ptr<IBindable>;

template<typename T, typename ... Args>
constexpr UniqueBindable CreateBindable(Args&& ... args)
{
	return std::make_unique<Bindable<T>>(std::forward<Args>(args)...);
}

#include "Bindable.inl"