#pragma once

template <typename T> class SmartPointer
{
private:
	T* ptr;

public:
	SmartPointer(T* generic);
	~SmartPointer();
	T& operator *();
	T& operator ->();
	


};

template<typename T>
inline SmartPointer<T>::SmartPointer(T* generic) : ptr(generic)
{}

template<typename T>
inline SmartPointer<T>::~SmartPointer()
{
	delete ptr;
}

template<typename T>
inline T& SmartPointer<T>::operator*()
{
	return *ptr;
}

template<typename T>
inline T& SmartPointer<T>::operator->()
{
	return ptr;
}
