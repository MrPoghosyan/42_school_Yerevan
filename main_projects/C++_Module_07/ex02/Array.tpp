template <typename T>
Array<T>::Array(void)
{
	this->_size = 0;
	this->_data = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_data = new T[n]();
}

template <typename T>
Array<T>::Array(Array const &src)
{
	unsigned int	i;

	this->_size = src._size;
	this->_data = new T[this->_size]();
	i = 0;
	while (i < this->_size)
	{
		this->_data[i] = src._data[i];
		i++;
	}
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] this->_data;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)
{
	if (this == &rhs)
		return (*this);

	T* newData = new T[rhs._size]();

	for(unsigned int i = 0; i < rhs._size; ++i)
		newData[i] = rhs._data[i];

	delete[] this->_data;
	this->_data = newData;
	this->_size = rhs._size;

	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (typename Array<T>::OutOfBoundsException());
	return (this->_data[index]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw (typename Array<T>::OutOfBoundsException());
	return (this->_data[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("Array: index is out of bounds");
}
