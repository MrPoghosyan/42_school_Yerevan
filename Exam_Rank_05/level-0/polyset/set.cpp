#include "set.hpp"

set::set() : _bag(NULL)
{
}

set::set(searchable_bag &b) : _bag(&b)
{
}

set::set(const set &other) : _bag(other._bag)
{
}

set &set::operator=(const set &other)
{
	if (this != &other)
		_bag = other._bag;
	return *this;
}

set::~set()
{
}

void set::insert(int item)
{
	if (!_bag->has(item))
		_bag->insert(item);
}

void set::insert(int *items, int count)
{
	for (int i = 0; i < count; i++)
		insert(items[i]);
}

void set::print() const
{
	_bag->print();
}

void set::clear()
{
	_bag->clear();
}

bool set::has(int item) const
{
	return _bag->has(item);
}

searchable_bag &set::get_bag() const
{
	return *_bag;
}
