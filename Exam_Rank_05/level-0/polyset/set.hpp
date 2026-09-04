#pragma once

#include <cstddef>
#include "searchable_bag.hpp"

class set
{
 public:
	set();
	set(searchable_bag &b);
	set(const set &other);
	set &operator=(const set &other);
	~set();

	void insert(int item);
	void insert(int *items, int count);
	void print() const;
	void clear();
	bool has(int item) const;
	searchable_bag &get_bag() const;

 private:
	searchable_bag *_bag;
};
