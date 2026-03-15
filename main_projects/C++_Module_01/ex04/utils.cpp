#include "header.hpp"

bool	check_empty(const std::string& str, const std::string& name)
{
	if (str.empty()){
		std::cerr << "Error: " << name << " cannot be empty\n";
		return true;
	}

	return false;
}

bool ft_replace(std::ifstream& infile, std::ofstream& outfile,
const std::string& s1, const std::string& s2)
{
	std::string line;
	bool replaced = false;
	size_t pos;
	size_t found;

	while (std::getline(infile, line)) {
		std::string result;
		pos = 0;

		while ((found = line.find(s1, pos)) != std::string::npos){
			result.append(line.substr(pos, found - pos));
			result.append(s2);
			pos = found + s1.length();
			replaced = true;
		}
		result.append(line.substr(pos));
		outfile << result;
		if (!outfile)
			return false;

		if (!infile.eof())
			outfile << "\n";
	}
	if (!infile.eof())
		return false;
	if (!replaced)
		std::cout << "No occurrences found!" << std::endl;

	return true;
}
