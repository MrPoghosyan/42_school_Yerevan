#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src) : tree_bag(src)
{
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &src)
{
	if (this != &src)
		tree_bag::operator=(src);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool searchable_tree_bag::has(int item) const
{
	return has_node(tree, item);
}

bool searchable_tree_bag::has_node(node *current, int item) const
{
	if (current == NULL)
		return false;
	if (item == current->value)
		return true;
	if (item < current->value)
		return has_node(current->l, item);
	return has_node(current->r, item);
}
