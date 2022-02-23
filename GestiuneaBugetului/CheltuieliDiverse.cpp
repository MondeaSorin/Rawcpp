#include "CheltuieliDiverse.h"
#include "CheltuieliAlimentare.h"

CheltuieliDiverse::CheltuieliDiverse()
	:dData(nullptr), dNrCheltuiliEfectuate(0), dValoareCheltuiala(nullptr), dDenumireProdus{ " " }
{
	this->dData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->dData, "Necunoscuta");

	this->dValoareCheltuiala = new double;
	*dValoareCheltuiala = 0;
}

CheltuieliDiverse::CheltuieliDiverse(const char* Data,
	int NrCheltuiliEfectuate,
	double* ValoareCheltuiala,
	const char DenumireProdus[50])
	:dData(nullptr), dNrCheltuiliEfectuate(0), dValoareCheltuiala(nullptr), dDenumireProdus{ " " }
{
	this->dData = new char[strlen(Data) + 1];
	strcpy(this->dData, Data);

	this->dNrCheltuiliEfectuate = NrCheltuiliEfectuate;

	this->dValoareCheltuiala = new double[NrCheltuiliEfectuate];
	for (int i = 0; i < NrCheltuiliEfectuate; i++)
	{
		this->dValoareCheltuiala[i] = ValoareCheltuiala[i];
	}

	strcpy(this->dDenumireProdus, DenumireProdus);
}

CheltuieliDiverse::CheltuieliDiverse(int NrCheltuiliEfectuate,
	double* ValoareCheltuiala)
	:dData(nullptr), dNrCheltuiliEfectuate(0), dValoareCheltuiala(nullptr), dDenumireProdus{ " " }
{
	this->dData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->dData, "Necunoscuta");

	this->dNrCheltuiliEfectuate = NrCheltuiliEfectuate;

	this->dValoareCheltuiala = new double[NrCheltuiliEfectuate];
	for (int i = 0; i < NrCheltuiliEfectuate; i++)
	{
		this->dValoareCheltuiala[i] = ValoareCheltuiala[i];
	}
}

CheltuieliDiverse::~CheltuieliDiverse()
{
	if (this->dData != nullptr)
		delete[] this->dData;
	if (this->dValoareCheltuiala != nullptr)
		delete[] this->dValoareCheltuiala;
}

CheltuieliDiverse::CheltuieliDiverse(const CheltuieliDiverse& source)
{
	this->dData = new char[strlen(source.dData) + 1];
	strcpy(this->dData, source.dData);

	this->dNrCheltuiliEfectuate = source.dNrCheltuiliEfectuate;

	this->dValoareCheltuiala = new double[source.dNrCheltuiliEfectuate];
	for (int i = 0; i < source.dNrCheltuiliEfectuate; i++)
	{
		this->dValoareCheltuiala[i] = source.dValoareCheltuiala[i];
	}

	strcpy(this->dDenumireProdus, source.dDenumireProdus);
}

CheltuieliDiverse& CheltuieliDiverse::operator=(const CheltuieliDiverse& rhs)
{
	if (this != &rhs)
	{
		if (this->dData != nullptr)
			delete[] this->dData;
		this->dData = new char[strlen(rhs.dData) + 1];
		strcpy(this->dData, rhs.dData);

		this->dNrCheltuiliEfectuate = rhs.dNrCheltuiliEfectuate;

		if (this->dValoareCheltuiala != nullptr)
			delete[] this->dValoareCheltuiala;
		this->dValoareCheltuiala = new double[rhs.dNrCheltuiliEfectuate];
		for (int i = 0; i < rhs.dNrCheltuiliEfectuate; i++)
		{
			this->dValoareCheltuiala[i] = rhs.dValoareCheltuiala[i];
		}

		strcpy(this->dDenumireProdus, rhs.dDenumireProdus);
	}

	return *this;
}


double CheltuieliDiverse::operator[](int index)
{
	if (index > 0 && index < this->dNrCheltuiliEfectuate)
	{
		return this->dValoareCheltuiala[index];
	}
	else
	{
		std::cerr << "Index negasit";
	}
}

double CheltuieliDiverse::operator+(const CheltuieliDiverse& rhs)
{
	double Suma{};

	for (int i = 0; i < this->dNrCheltuiliEfectuate; ++i)
	{
		Suma += this->dValoareCheltuiala[i];
	}

	for (int i = 0; i < rhs.dNrCheltuiliEfectuate; ++i)
	{
		Suma += rhs.dValoareCheltuiala[i];
	}

	return Suma;
}

CheltuieliDiverse& CheltuieliDiverse::operator--()
{
	int buff_size = this->dNrCheltuiliEfectuate - 1;
	double* buff = new double[buff_size];
	for (int i = 0; i < buff_size; ++i)
	{
		buff[i] = this->dValoareCheltuiala[i];
	}

	this->dNrCheltuiliEfectuate = buff_size;

	delete[] this->dValoareCheltuiala;
	this->dValoareCheltuiala = buff;

	return *this;
}

CheltuieliDiverse CheltuieliDiverse::operator--(int)
{
	CheltuieliDiverse Temp(*this);
	CheltuieliDiverse::operator--();
	return Temp;
}

CheltuieliDiverse::operator int()
{
	return this->dNrCheltuiliEfectuate;
}

bool CheltuieliDiverse::operator<(const CheltuieliDiverse& rhs)
{
	return this->dNrCheltuiliEfectuate < rhs.dNrCheltuiliEfectuate;
}

bool CheltuieliDiverse::operator==(const CheltuieliDiverse& rhs)
{
	double suma1{}, suma2{};
	for (int i = 0; i < this->dNrCheltuiliEfectuate; ++i)
	{
		suma1 += this->dValoareCheltuiala[i];
	}

	for (int i = 0; i < rhs.dNrCheltuiliEfectuate; ++i)
	{
		suma2 += rhs.dValoareCheltuiala[i];
	}

	return (this->dNrCheltuiliEfectuate == rhs.dNrCheltuiliEfectuate && suma1 == suma2);
}

void CheltuieliDiverse::afisare()
{
	std::cout << "========================================" << std::endl;
	std::cout << "Data efectuarii cheluielii  : " << this->dData << std::endl
		<< "Nr de obiecte cumparate     : " << this->dNrCheltuiliEfectuate << std::endl
		<< "Pretul obiectelor  este     : ";

	std::cout << "[ ";
	for (int i = 0; i < this->dNrCheltuiliEfectuate; ++i)
	{
		std::cout << this->dValoareCheltuiala[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Denumirea este             : " << this->dDenumireProdus << std::endl;
	std::cout << "========================================" << std::endl << std::endl;
}

void CheltuieliDiverse::SetData(const char* Data)
{
	if (Data != nullptr)
	{
		this->dData = new char[strlen(Data) + 1];
		strcpy(this->dData, Data);
	}
	else
	{
		std::cerr << "Data invalida";
	}
}

void CheltuieliDiverse::SetNrCheltuiliEfectuate(int NrCheltuiliEfectuate)
{
	if (NrCheltuiliEfectuate > 0)
	{
		this->dNrCheltuiliEfectuate = NrCheltuiliEfectuate;
	}
	else
	{
		std::cerr << "Nr alimente nu poate fi negativ!";
	}
}

void CheltuieliDiverse::SetValoareCheltuiala(double* ValoareCheltuiala)
{
	if (ValoareCheltuiala != nullptr)
	{
		this->dValoareCheltuiala = new double[this->dNrCheltuiliEfectuate];
		for (int i = 0; i < this->dNrCheltuiliEfectuate; i++)
		{
			this->dValoareCheltuiala[i] = ValoareCheltuiala[i];
		}
	}
}

void CheltuieliDiverse::SetDenumireProdus(char DenumireProdus[50])
{
	strcpy(this->dDenumireProdus, DenumireProdus);
}

std::ostream& operator<<(std::ostream& os, const CheltuieliDiverse& rhs)
{
	os << "========================================" << std::endl;
	os << "Data efectuarii cheluielii  : " << rhs.dData << std::endl
		<< "Nr de obiecte  cumparate    : " << rhs.dNrCheltuiliEfectuate << std::endl
		<< "Pretul obiectelor  este     : ";

	os << "[ ";
	for (int i = 0; i < rhs.dNrCheltuiliEfectuate; ++i)
	{
		std::cout << rhs.dValoareCheltuiala[i] << " ";
	}
	os << "]" << std::endl;
	os << "Denumirea produsului este  : " << rhs.dDenumireProdus << std::endl;
	os << "========================================" << std::endl << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, CheltuieliDiverse& rhs)
{
	std::cout<< std::endl << "Introduceti data efectuarii cheltuielii: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.dData;
	rhs.dData = new char[strlen(buff) + 1];
	strcpy(rhs.dData, buff);

	std::cout << "Introduceti nr de obiecte cumparate: "; is >> rhs.dNrCheltuiliEfectuate;
	std::cout << "Introduceti pretul obiectelor:" << std::endl;
	delete[] rhs.dValoareCheltuiala;
	rhs.dValoareCheltuiala = new double[rhs.dNrCheltuiliEfectuate];
	for (int i = 0; i < rhs.dNrCheltuiliEfectuate; ++i)
	{
		std::cout << "\tProdusul nr." << i + 1 << ": ";
		is >> rhs.dValoareCheltuiala[i];
	}

	std::cout << "Introduceti denumirea: "; is >> rhs.dDenumireProdus;

	return is;
}
