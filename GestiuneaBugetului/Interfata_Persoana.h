#pragma once
class Interfata_Persoana
{
public:
	virtual void print(std::ostream& os) const = 0;
	virtual void AfisareDateFacturi() = 0;
	virtual ~Interfata_Persoana() = default;
	friend std::ostream& operator<<(std::ostream& os, const Interfata_Persoana& obj)
	{
		obj.print(os);
		return os;
	}

};

