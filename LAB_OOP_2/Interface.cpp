#pragma once
#include <iostream>
#include "Interface.h"

Interface::Interface()
{	
	std::cout << "Input quanity of pairs:";
	std::cin >> quanity;
	quanity *= 3;
	_names = new std::string[quanity];
	_cases = new Currency*[quanity];
}

Interface::~Interface()
{
	delete[] _names;
	delete[] _cases;
}


int Interface::GetIndex(const std::string name) const
{
	for (int i = 0; i < quanity; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}

void Interface::Int_Input() const
{

	bool isEnoughtSpace = false;
	int index;

	for (int i = 0; i < quanity && !isEnoughtSpace; i++)
	{

		if (_names[i].empty())
		{
			isEnoughtSpace = true;
			index = i;
			break;
		}

	}

	if (isEnoughtSpace)
	{

		std::cout << "Which wallet you want to edit?(e|d|p): ";

		char choice;
		std::cin >> choice;
		if (choice == 'd' || choice == 'e' || choice == 'p')
		{
			unsigned int first;
			unsigned int second;
			std::cout << "Input integer: ";
			std::cin >> first;
			std::cout << "input after dot:";
			std::cin >> second;


			Currency* newElement = nullptr;
			switch (choice)
			{
			case 'p':
				newElement = new Pound(first, second, choice);
				std::cout << "Enter name of object: ";
				std::cin >> _names[index];
				_cases[index] = newElement;
				std::cout << "Complete!\n";
				break;

			case 'e':
				newElement = new Euro(first, second, choice);
				std::cout << "Enter name of object: ";
				std::cin >> _names[index];
				_cases[index] = newElement;
				std::cout << "Complete!\n";
				break;

			case 'd':
				newElement = new Dollar(first, second, choice);
				std::cout << "Enter name of object: ";
				std::cin >> _names[index];
				_cases[index] = newElement;
				std::cout << "Complete!\n";
				break;

			default:
				std::cout << "Wrong wallet!\n";

			}


		}
		else
		{
			std::cout << "Wrong wallet!\n";
		}
	}
	else
	{
		std::cout << "Not enought space!\n";
	}
}

void Interface::Help() const
{
	std::cout << "\"1\" - Call help\n\"2\" - Input Object of wallet\n\"3\" - Minus\n\"4\" - Plus\n\"5\" - Check Wallet`s\n\"6\" - Calculate wallet to Roubles\n\"0\" - Exit\n";
}

void Interface::Int_Minus() const
{
	std::string name1;
	std::string name2;
	std::string name3;

	std::cout << "enter two names(name1 name2):";

	std::cin >> name1 >> name2;

	int index1 = GetIndex(name1);
	int index2 = GetIndex(name2);

	if ((index1 != -1 && index2 != -1) && (_cases[index1]->Index() == _cases[index2]->Index()))
	{
		if (((_cases[index1]->Integer() >= _cases[index2]->Integer()) && (_cases[index1]->Float() >= _cases[index2]->Float()))||(_cases[index1]->Integer() > _cases[index2]->Integer()))
		{
			std::cout << "enter the name of result: ";
			std::cin >> name3;


			bool isEnoughtSpace = false;
			int index;

			for (int i = 0; i < quanity && !isEnoughtSpace; i++)
			{

				if (_names[i].empty())
				{
					isEnoughtSpace = true;
					index = i;
				}
			}

			if (isEnoughtSpace)
			{
				_names[index] = name3;
				Currency* newElement = nullptr;
				newElement = new Euro(0, 0, _cases[index1]->Index());
				_cases[index] = newElement;
				_cases[index]->minus(*_cases[index1], *_cases[index2]);

				std::cout << "Complete\n";
				std::cout << "Result = " + _cases[index]->Get_Currency(name3) + "\n";
			}
			else
			{
				std::cout << "Not enoough space!\n";
			}
		}
		else
		{
			std::cout << "Wrong wallet || different wallets || first object smaller than second!\n";
		}
	}

		


}

void Interface::Int_Plus() const
{
	std::string name1;
	std::string name2;
	std::string name3;
	std::cout << "enter two names(name1 name2):";
	std::cin >> name1 >> name2;
	std::cout << "enter the name of result: ";
	std::cin >> name3;
	int index1 = GetIndex(name1);
	int index2 = GetIndex(name2);
	if ((index1 != -1 && index2 != -1) && (_cases[index1]->Index() == _cases[index2]->Index()))
	{
		bool isEnoughtSpace = false;
		int index;

		for (int i = 0; i < quanity && !isEnoughtSpace; i++)
		{

			if (_names[i].empty())
			{
				isEnoughtSpace = true;
				index = i;
			}
		}

		if (isEnoughtSpace)
		{
			_names[index] = name3;
			Currency* newElement = nullptr;
			newElement = new Euro(0, 0, _cases[index1]->Index());
			_cases[index] = newElement;
			_cases[index]->plus(*_cases[index1], *_cases[index2]);
			
			std::cout << "Complete\n";
			std::cout << "Result = " + _cases[index]->Get_Currency(name3) + "\n";
		}
		else
		{
			std::cout << "Not enoough space!\n";
		}
	}
	else
	{
		std::cout << "Wrong wallet!\n";
	}

}

void Interface::Int_Check_money()const
{
	
	for (int i = 0; i < quanity; i++)
	{
		if (_names[i].empty())
		{
			
		}
		else
		{
			std::cout << _cases[i]->Get_Currency(_names[i]) << '\n';
		}
		
	}
}

void Interface::Int_Calculate_wallets() const
{
	float quanity;
	char choice;
	float course;
	Purse rub;
	std::cout << "Choose the wallet to calculate to Roubles. (e|p|d): ";
	std::cin >> choice;
	if (choice == 'e' || choice == 'p' || choice == 'd')
	{
		std::cout << "Enter the quanity of " << choice << ": ";

		std::cin >> quanity;
		std::cout << "Enter the course " << choice << " to roubles: ";
		std::cin >> course;
		rub.Calculate_wallet(choice, quanity, course);
	}
	else
	{
		std::cout << "Wrong wallet!\n";
	}
}

void Interface::Init() const
{
	std::cout << "Here you can work with emulated wallets.\n";
	std::cout << "For example: add or take money for any wallet (Euro,Dollar,Pound).\n";
	std::cout << "Also you can calculate these wallets into Roubles.\n";
	std::cout << "Enter \"1\" - Help\n";

	char code;
	bool fl = true;
	while (fl)
	{

		std::cout << ">> ";
		std::cin >> code;

		switch (code)
		{
		case '1':
			Help();
			break;

		case '2':
			Int_Input();
			break;

		case '3':
			Int_Minus();
			break;

		case '4':
			Int_Plus();
			break;

		case '5':
			Int_Check_money();
			break;

		case '6':
			Int_Calculate_wallets();
			break;

		case '0':
			fl = false;
			break;

		default:
			std::cout << "Wrong command\n";
			break;
		}
	}
}
