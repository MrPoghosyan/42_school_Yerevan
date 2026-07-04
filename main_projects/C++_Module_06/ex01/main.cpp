#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original;
	original.id = 42;
	original.label = "answer";
	original.value = 3.14;

	uintptr_t raw = Serializer::serialize(&original);
	Data *back = Serializer::deserialize(raw);

	std::cout << "original address : " << &original << std::endl;
	std::cout << "serialized value : " << raw << std::endl;
	std::cout << "deserialized addr: " << back << std::endl;

	if (&original == back)
		std::cout << "OK: pointers are equal" << std::endl;
	else
		std::cout << "KO: pointers differ" << std::endl;

	std::cout << "back->id    : " << back->id << std::endl;
	std::cout << "back->label : " << back->label << std::endl;
	std::cout << "back->value : " << back->value << std::endl;

	return (0);
}
