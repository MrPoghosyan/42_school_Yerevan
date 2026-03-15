#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	public:
		void complain( std::string level );
};

typedef struct s_map
{
	std::string level;
	void (Harl::*func)( void );
}	t_map;

#endif /* HARL_HPP */
