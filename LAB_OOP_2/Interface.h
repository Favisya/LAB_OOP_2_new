#pragma once
#include"currency.h"
class Interface {

public:
	Interface();
	~Interface();

	void Init() const;
private:
	void Int_Minus() const;
	void Int_Plus() const;
	void Int_Check_money() const;
	void Help() const;
	void Int_Calculate_wallets() const;
	void Int_Input() const;
	int GetIndex(const std::string name) const;

	int quanity=0;
	std::string* _names = nullptr;
	Currency** _cases = nullptr;
};