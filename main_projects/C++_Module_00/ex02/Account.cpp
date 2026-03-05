#include  "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

/*  static variables  */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "["
			  << 1900 + ltm->tm_year
			  << (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon +1
			  << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
			  << "_"
			  << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
			  << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
			  << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
			  << "] ";
}

/*   object methods   */
int Account::checkAmount(void) const
{
	return _amount;
}

	// constructor formatting
Account::Account(int initial_deposit)
	:_accountIndex(_nbAccounts),
	 _amount(initial_deposit),
	 _nbDeposits(0),
	 _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";created" << std::endl;
}

	// destructor formatting
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << checkAmount()
			  << ";closed" << std::endl;
}

/*   static getters   */
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

// static display function
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
			  << ";amount:" << checkAmount()
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << checkAmount();

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
			  << ";amount:" << checkAmount()
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << checkAmount();

	if (withdrawal > checkAmount()){
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << checkAmount()
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;

	return true;
}
