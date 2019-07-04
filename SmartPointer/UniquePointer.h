#pragma once
#include <memory>

template <typename T> class UniquePointer
{
private:
	T* ptr;

public:

	// constructor with nullptr
	UniquePointer(); 
	UniquePointer(std::nullptr_t);

	//explicit constructor
	UniquePointer(T* generic);

	// copy constructor and operator
	UniquePointer(const UniquePointer<T>& generic) = delete;
	T& operator=(const UniquePointer<T>& generic) = delete;

	// move constructor and operator
	UniquePointer(UniquePointer<T>&& generic);
	T& operator =(UniquePointer<T>&& generic);

	//destructor
	~UniquePointer();

	//operators
	T& operator *() const; 
	T& operator ->() const;

	//Modifiers
	T* release();
	void reset();
	void swap(UniquePointer<T>& generic);

	//Observers

	T* get() const;
	explicit operator bool() const;
	
};

template<typename T>
inline UniquePointer<T>::UniquePointer() : ptr(nullptr)
{
}

template<typename T>
inline UniquePointer<T>::UniquePointer(std::nullptr_t) : ptr(nullptr)
{
}

template<typename T>
inline UniquePointer<T>::UniquePointer(T* generic) : ptr(generic)
{
}

template<typename T>
inline UniquePointer<T>::~UniquePointer()
{
	delete ptr;
}

template<typename T>
inline T& UniquePointer<T>::operator*() const
{
	return *ptr;
}

template<typename T>
inline T& UniquePointer<T>::operator->() const
{
	return ptr;
}

template<typename T>
inline T* UniquePointer<T>::release()
{
	T* release = nullptr;
	std::swap(release, ptr);
	return release;
}

template<typename T>
inline void UniquePointer<T>::reset()
{
	T* tmp = release();
	delete tmp;
}

template<typename T>
inline void UniquePointer<T>::swap(UniquePointer<T>& generic)
{
	std::swap(ptr, generic.ptr);
}

template<typename T>
inline T* UniquePointer<T>::get() const
{
	return ptr;
}

template<typename T>
inline UniquePointer<T>::operator bool() const
{
}

template<typename T>
inline UniquePointer<T>::UniquePointer(UniquePointer<T>&& generic)
{
	//use swap?
}

template<typename T>
inline T& UniquePointer<T>::operator=(UniquePointer<T>&& generic)
{
	//use swap?
}


