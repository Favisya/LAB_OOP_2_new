#pragma once
#include<iostream>
class Currency {

public:

	Currency():_first_integer(0),_second_float(0), _index('0'){}
	Currency(const unsigned int first_integer,const unsigned int second_float,const char index):_first_integer(first_integer), _second_float(second_float), _index(index){}
	char Index() const;
	unsigned int Integer() const;
	unsigned int Float() const;
	void minus(Currency& object1, Currency& object2);
	void plus(Currency& object1, Currency& object2);
	void Input(unsigned int fisrt,unsigned second,char ind);
	virtual std::string Get_Currency(std::string _names) const = 0;
protected:
	unsigned int _first_integer;
	unsigned int _second_float;
	char _index;
};

class Dollar : public Currency {
public:
	Dollar() :Currency(){}
	Dollar(unsigned int _first_integer,unsigned int _second_float,char _index):Currency(_first_integer, _second_float, _index){}
	virtual std::string Get_Currency(std::string _names) const override;
};

class Euro : public Currency {
public:
	Euro() :Currency() {}
	Euro(unsigned int _first_integer, unsigned int _second_float, char _index): Currency(_first_integer, _second_float, _index) {}
	virtual std::string Get_Currency(std::string _names) const override;
};

class Pound : public Currency {
public:
	Pound():Currency(){}
	Pound(unsigned int _first_integer, unsigned int _second_float, char _index) : Currency(_first_integer, _second_float, _index) {}
	virtual std::string Get_Currency(std::string _names) const override;
};

class Purse {
public:
	void Calculate_wallet(char choice, float quanity, float course_roubles) const;

};
