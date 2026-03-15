#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <string>
#include <fstream>

bool	check_empty(const std::string& str, const std::string& name);
bool	ft_replace(std::ifstream& infile, std::ofstream& outfile, const std::string& s1, const std::string& s2);

#endif /* HEADER_HPP */
