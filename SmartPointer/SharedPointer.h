#pragma once


struct Refcounter
{
	int count = 1;
};


template <typename T> class SharedPointer
{
private:
	T* ptr;
	Refcounter* refcount;

public:

	SharedPointer(T* generic);
	~SharedPointer();
	T& operator *();
	T& operator ->();

	SharedPointer(const SharedPointer<T>& generic);
	T& operator=(const SharedPointer<T>& generic);;
};

template<typename T>
inline SharedPointer<T>::SharedPointer(T* generic) : ptr(generic), refcount(new Refcounter())
{
}

template<typename T>
inline SharedPointer<T>::SharedPointer(const SharedPointer<T>& generic) : ptr(generic.ptr), refcount(generic.refcount)
{
	++refcount->count;
}

template<typename T>
inline SharedPointer<T>::~SharedPointer()
{
	if (--refcount->count == 0)
	{
		delete refcount;
		delete ptr;
	}
	
}

template<typename T>
inline T& SharedPointer<T>::operator*()
{
	return *ptr;
}

template<typename T>
inline T& SharedPointer<T>::operator->()
{
	return ptr;
}

template<typename T>
inline T& SharedPointer<T>::operator=(const SharedPointer<T>& generic)
{
	// TODO: insert return statement here
}
