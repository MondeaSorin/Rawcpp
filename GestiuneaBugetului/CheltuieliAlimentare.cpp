#include "CheltuieliAlimentare.h"

CheltuieliAlimentare::CheltuieliAlimentare()
	:aData(nullptr), aNrAlimente(0), aPretAliment(nullptr), aNrBonFiscal{" "}
{
	this->aData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->aData, "Necunoscuta");

	this->aPretAliment = new double;
	*aPretAliment = 0;
}

CheltuieliAlimentare::CheltuieliAlimentare(const char* Data,
	int NrAlimente,
	double* PretAliment,
	const char NrBonFiscal[10])
	:aData(nullptr), aNrAlimente(0), aPretAliment(nullptr), aNrBonFiscal{ " " }
{
	this->aData = new char[strlen(Data) + 1];
	strcpy(this->aData, Data);

	this->aNrAlimente = NrAlimente;

	this->aPretAliment = new double[NrAlimente];
	for (int i = 0; i < NrAlimente; i++)
	{
		this->aPretAliment[i] = PretAliment[i];
	}

	strcpy(this->aNrBonFiscal, NrBonFiscal);
}

CheltuieliAlimentare::CheltuieliAlimentare(int NrAlimente,
	double* PretAliment)
	: aData(nullptr), aNrAlimente(0), aPretAliment(nullptr), aNrBonFiscal{ " " }
{
	this->aData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->aData, "Necunoscuta");

	this->aNrAlimente = NrAlimente;

	this->aPretAliment = new double[NrAlimente];
	for (int i = 0; i < NrAlimente; i++)
	{
		this->aPretAliment[i] = PretAliment[i];
	}
}

CheltuieliAlimentare::~CheltuieliAlimentare()
{
	if (this->aData != nullptr)
		delete[] this->aData;
	if (this->aPretAliment != nullptr)
		delete[] this->aPretAliment;
}

CheltuieliAlimentare::CheltuieliAlimentare(const CheltuieliAlimentare& source)
{
	this->aData = new char[strlen(source.aData) + 1];
	strcpy(this->aData, source.aData);

	this->aNrAlimente = source.aNrAlimente;

	this->aPretAliment = new double[source.aNrAlimente];
	for (int i = 0; i < source.aNrAlimente; i++)
	{
		this->aPretAliment[i] = source.aPretAliment[i];
	}

	strcpy(this->aNrBonFiscal, source.aNrBonFiscal);
}

CheltuieliAlimentare& CheltuieliAlimentare::operator=(const CheltuieliAlimentare& rhs)
{
	if (this != &rhs)
	{
		if (this->aData != nullptr)
			delete[] this->aData;
		this->aData = new char[strlen(rhs.aData) + 1];
		strcpy(this->aData, rhs.aData);

		this->aNrAlimente = rhs.aNrAlimente;

		if (this->aPretAliment != nullptr)
			delete[] this->aPretAliment;
		this->aPretAliment = new double[rhs.aNrAlimente];
		for (int i = 0; i < rhs.aNrAlimente; i++)
		{
			this->aPretAliment[i] = rhs.aPretAliment[i];
		}

		strcpy(this->aNrBonFiscal, rhs.aNrBonFiscal);
	}

	return *this;
}


double CheltuieliAlimentare::operator[](int index)
{
	if (index > 0 && index < this->aNrAlimente)
	{
		return aPretAliment[index];
	}
	else
	{
		std::cerr << "Index negasit";
	}
}

double CheltuieliAlimentare::operator+(const CheltuieliAlimentare& rhs)
{
	double Suma{};

	for (int i = 0; i < this->aNrAlimente; ++i)
	{
		Suma += this->aPretAliment[i];
	}

	for (int i = 0; i < rhs.aNrAlimente; ++i)
	{
		Suma += rhs.aPretAliment[i];
	}

	return Suma;
}

CheltuieliAlimentare& CheltuieliAlimentare::operator--()
{
	int buff_size = this->aNrAlimente - 1;
	double* buff = new double[buff_size];
	for (int i = 0; i < buff_size; ++i)
	{
		buff[i] = this->aPretAliment[i];
	}

	this->aNrAlimente = buff_size;

	delete[] this->aPretAliment;
	this->aPretAliment = buff;

	return *this;
}

CheltuieliAlimentare CheltuieliAlimentare::operator--(int)
{
	CheltuieliAlimentare Temp(*this);
	CheltuieliAlimentare::operator--();
	return Temp;
}

CheltuieliAlimentare::operator int()
{
	return this->aNrAlimente;
}

bool CheltuieliAlimentare::operator<(const CheltuieliAlimentare& rhs)
{
	return this->aNrAlimente < rhs.aNrAlimente;
}

bool CheltuieliAlimentare::operator==(const CheltuieliAlimentare& rhs)
{
	double suma1{}, suma2{};
	for (int i = 0; i < this->aNrAlimente; ++i)
	{
		suma1 += this->aPretAliment[i];
	}

	for (int i = 0; i < rhs.aNrAlimente; ++i)
	{
		suma2 += rhs.aPretAliment[i];
	}

	return (this->aNrAlimente == rhs.aNrAlimente && suma1 == suma2);
}

void CheltuieliAlimentare::afisare()
{
	std::cout << "========================================" << std::endl;
	std::cout << "Data efectuarii cheluielii  : " << this->aData << std::endl
		<< "Nr de alimente cumparate    : " << this->aNrAlimente << std::endl
		<< "Pretul alimentelor este     : ";

	std::cout << "[ ";
	for (int i = 0; i < this->aNrAlimente; ++i)
	{
		std::cout << this->aPretAliment[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Nr bonului este             : " << this->aNrBonFiscal << std::endl;
	std::cout << "========================================" << std::endl << std::endl;
}

void CheltuieliAlimentare::SetData(const char* Data)
{
	if (Data != nullptr)
	{
		this->aData = new char[strlen(Data) + 1];
		strcpy(this->aData, Data);
	}
	else
	{
		std::cerr << "Data invalida";
	}
}

void CheltuieliAlimentare::SetNrAlimente(int NrAlimente)
{
	if (NrAlimente > 0)
	{
		this->aNrAlimente = NrAlimente;
	}
	else
	{
		std::cerr << "Nr alimente nu poate fi negativ!";
	}
}

void CheltuieliAlimentare::SetPretAliment(double* PretAliment)
{
	if (PretAliment != nullptr)
	{
		this->aPretAliment = new double[this->aNrAlimente];
		for (int i = 0; i < this->aNrAlimente; i++)
		{
			this->aPretAliment[i] = PretAliment[i];
		}
	}
}

void CheltuieliAlimentare::SetNrBonFiscal(char NrBonFiscal[10])
{
	strcpy(this->aNrBonFiscal, NrBonFiscal);
}
 
std::ostream& operator<<(std::ostream& os, const CheltuieliAlimentare& rhs)
{
	os << "========================================" << std::endl;
	os << "Data efectuarii cheluielii  : " << rhs.aData << std::endl
		<< "Nr de alimente cumparate    : " << rhs.aNrAlimente << std::endl
		<< "Pretul alimentelor este     : ";

	os << "[ ";
	for (int i = 0; i < rhs.aNrAlimente; ++i)
	{
		std::cout << rhs.aPretAliment[i] << " ";
	}
	os << "]" << std::endl;
	os << "Nr bonului este             : " << rhs.aNrBonFiscal << std::endl;
	os << "========================================" << std::endl << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, CheltuieliAlimentare& rhs)
{
	std::cout << std::endl << "Introduceti data efectuarii cheltuielii: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.aData;
	rhs.aData = new char[strlen(buff) + 1];
	strcpy(rhs.aData, buff);

	std::cout << "Introduceti nr de alimente cumparate: "; is >> rhs.aNrAlimente;
	std::cout << "Introduceti pretul alimentelor:" << std::endl;
	delete[] rhs.aPretAliment;
	rhs.aPretAliment = new double[rhs.aNrAlimente];
	for (int i = 0; i < rhs.aNrAlimente; ++i)
	{
		std::cout << "\tAlimentul nr." << i + 1 << ": ";
		is >> rhs.aPretAliment[i];
	}

	std::cout << "Introduceti nr bonului fiscal: "; is >> rhs.aNrBonFiscal;

	return is;
}
