#include"Currency.h"
#include<iostream>
#include<string>

void Currency::Input(unsigned int first, unsigned int second, char ind)
{
	_first_integer = first;
	_second_float = second;
	_index = ind;
}

char Currency::Index() const
{
	return _index;
}
unsigned int Currency::Integer() const
{
	return _first_integer;
}
unsigned int Currency::Float() const
{
	return _second_float;
}

void Currency::plus(Currency& object1, Currency& object2)
{

		unsigned int first_integer = object1._first_integer;
		unsigned int second_float = object1._second_float;

		const int maxSecond = 1000000;

		unsigned int first_integer_1 = object1._first_integer;
		unsigned int first_integer_2 = object2._first_integer;


		unsigned int second_float_1 = object1._second_float;
		unsigned int second_float_2 = object2._second_float;

		unsigned int temp = 0;
		unsigned int temp2 = 0;
		while (second_float_1 != 0)
		{
			temp++;
			second_float_1 /= 10;

		}

		while (second_float_2 != 0)
		{
			temp2++;
			second_float_2 /= 10;
		}

		while (temp != 6)
		{
			temp++;
			second_float *= 10;
		}


		while (temp2 != 6)
		{
			temp2++;
			object2._second_float *= 10;
		}

		if (temp == temp2)
		{
			if (object2._second_float + second_float >= maxSecond)
			{
				_first_integer = first_integer + 1+object2._first_integer;
			}
			else
			{
				_first_integer = first_integer + object2._first_integer;
			}
			_second_float = (object2._second_float + second_float) % maxSecond;
		}
		

	
	

}

void  Currency::minus( Currency& object1, Currency& object2)
{

		
			unsigned int first_integer = object1._first_integer;
			unsigned int second_float = object1._second_float;

			const int maxSecond = 1000000;

			unsigned int first_integer_1 = object1._first_integer;
			unsigned int first_integer_2 = object2._first_integer;


			unsigned int second_float_1 = object1._second_float;
			unsigned int second_float_2 = object2._second_float;

			unsigned int temp = 0;
			unsigned int temp2 = 0;
			while (second_float_1 != 0)
			{
				temp++;
				second_float_1 /= 10;

			}

			while (second_float_2 != 0)
			{
				temp2++;
				second_float_2 /= 10;
			}

			while (temp != 6)
			{
				temp++;
				second_float *= 10;
			}


			while (temp2 != 6)
			{
				temp2++;
				object2._second_float *= 10;
			}

			if (temp == temp2)
			{
				if (object2._second_float <= second_float)
				{
					_first_integer = first_integer - object2._first_integer;
					_second_float = second_float - object2._second_float;
				}
				else
				{
					_first_integer = first_integer - 1 - object2._first_integer;
					_second_float = second_float + 1000000 - object2._second_float;

				}

			}




}


std::string Dollar::Get_Currency(std::string _names) const
{
	return _names + ' ' + std::to_string(_first_integer) + '.' + std::to_string(_second_float) + " $"+'\n';
}

std::string Euro::Get_Currency(std::string _names) const
{
	return  _names + ' ' + std::to_string(_first_integer) + '.' + std::to_string(_second_float) + " Euro" + '\n';
}

std::string Pound::Get_Currency(std::string _names) const
{
	return _names + ' ' + std::to_string(_first_integer) + '.' + std::to_string(_second_float) + " Pound" + '\n';
}

void Purse::Calculate_wallet(char choice, float quanity,float course_roubles) const
{
	switch (choice)
	{
	case 'p':
		std::cout << quanity << " Pounds in Roubles: " << quanity * course_roubles << '\n';
		break;

	case 'e':
		std::cout << quanity << " Erous in Roubles: " << quanity * course_roubles << '\n';
		break;
	case 'd':
		std::cout << quanity << " Dollars in Roubles: " << quanity * course_roubles << '\n';
		break;

	default:
		std::cout << "Wrong wallet!\n";

	}
}