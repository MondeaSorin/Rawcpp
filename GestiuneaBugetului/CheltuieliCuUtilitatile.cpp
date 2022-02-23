#include "CheltuieliCuUtilitatile.h"

CheltuieliCuUtilitatile::CheltuieliCuUtilitatile()
	:uData(nullptr), uNrFacturi(0), uValoareFactura(nullptr), uCodClient{ " " }
{
	this->uData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->uData, "Necunoscuta");

	this->uValoareFactura = new double;
	*uValoareFactura = 0;
}

CheltuieliCuUtilitatile::CheltuieliCuUtilitatile(const char* Data,
	int NrFacturi,
	double* ValoareFactura,
	const char CodClient[25])
	:uData(nullptr), uNrFacturi(0), uValoareFactura(nullptr), uCodClient{ " " }
{
	this->uData = new char[strlen(Data) + 1];
	strcpy(this->uData, Data);

	this->uNrFacturi = NrFacturi;

	this->uValoareFactura = new double[NrFacturi];
	for (int i = 0; i < NrFacturi; i++)
	{
		this->uValoareFactura[i] = ValoareFactura[i];
	}

	strcpy(this->uCodClient, CodClient);
}

CheltuieliCuUtilitatile::CheltuieliCuUtilitatile(int NrFacturi,
	double* ValoareFactura)
	: uData(nullptr), uNrFacturi(0), uValoareFactura(nullptr), uCodClient{ " " }
{
	this->uData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->uData, "Necunoscuta");

	this->uNrFacturi = NrFacturi;

	this->uValoareFactura = new double[NrFacturi];
	for (int i = 0; i < NrFacturi; i++)
	{
		this->uValoareFactura[i] = ValoareFactura[i];
	}
}

CheltuieliCuUtilitatile::~CheltuieliCuUtilitatile()
{
	if (this->uData != nullptr)
		delete[] this->uData;
	if (this->uValoareFactura != nullptr)
		delete[] this->uValoareFactura;
}

CheltuieliCuUtilitatile::CheltuieliCuUtilitatile(const CheltuieliCuUtilitatile& source)
{
	this->uData = new char[strlen(source.uData) + 1];
	strcpy(this->uData, source.uData);

	this->uNrFacturi = source.uNrFacturi;

	this->uValoareFactura = new double[source.uNrFacturi];
	for (int i = 0; i < source.uNrFacturi; i++)
	{
		this->uValoareFactura[i] = source.uValoareFactura[i];
	}

	strcpy(this->uCodClient, source.uCodClient);
}

CheltuieliCuUtilitatile& CheltuieliCuUtilitatile::operator=(const CheltuieliCuUtilitatile& rhs)
{
	if (this != &rhs)
	{
		if (this->uData != nullptr)
			delete[] this->uData;
		this->uData = new char[strlen(rhs.uData) + 1];
		strcpy(this->uData, rhs.uData);

		this->uNrFacturi = rhs.uNrFacturi;

		if (this->uValoareFactura != nullptr)
			delete[] this->uValoareFactura;
		this->uValoareFactura = new double[rhs.uNrFacturi];
		for (int i = 0; i < rhs.uNrFacturi; i++)
		{
			this->uValoareFactura[i] = rhs.uValoareFactura[i];
		}

		strcpy(this->uCodClient, rhs.uCodClient);
	}

	return *this;
}


double CheltuieliCuUtilitatile::operator[](int index)
{
	if (index > 0 && index < this->uNrFacturi)
	{
		return uValoareFactura[index];
	}
	else
	{
		std::cerr << "Index negasit";
	}
}

double CheltuieliCuUtilitatile::operator+(const CheltuieliCuUtilitatile& rhs)
{
	double Suma{};

	for (int i = 0; i < this->uNrFacturi; ++i)
	{
		Suma += this->uValoareFactura[i];
	}

	for (int i = 0; i < rhs.uNrFacturi; ++i)
	{
		Suma += rhs.uValoareFactura[i];
	}

	return Suma;
}

CheltuieliCuUtilitatile& CheltuieliCuUtilitatile::operator--()
{
	int buff_size = this->uNrFacturi - 1;
	double* buff = new double[buff_size];
	for (int i = 0; i < buff_size; ++i)
	{
		buff[i] = this->uValoareFactura[i];
	}

	this->uNrFacturi = buff_size;

	delete[] this->uValoareFactura;
	this->uValoareFactura = buff;

	return *this;
}

CheltuieliCuUtilitatile CheltuieliCuUtilitatile::operator--(int)
{
	CheltuieliCuUtilitatile Temp(*this);
	CheltuieliCuUtilitatile::operator--();
	return Temp;
}

CheltuieliCuUtilitatile::operator int()
{
	return this->uNrFacturi;
}

bool CheltuieliCuUtilitatile::operator<(const CheltuieliCuUtilitatile& rhs)
{
	return this->uNrFacturi < rhs.uNrFacturi;
}

bool CheltuieliCuUtilitatile::operator==(const CheltuieliCuUtilitatile& rhs)
{
	double suma1{}, suma2{};
	for (int i = 0; i < this->uNrFacturi; ++i)
	{
		suma1 += this->uValoareFactura[i];
	}

	for (int i = 0; i < rhs.uNrFacturi; ++i)
	{
		suma2 += rhs.uValoareFactura[i];
	}

	return (this->uNrFacturi == rhs.uNrFacturi && suma1 == suma2);
}

void CheltuieliCuUtilitatile::afisare()
{
	std::cout << "========================================" << std::endl;
	std::cout << "Data efectuarii cheluielii  : " << this->uData << std::endl
		<< "Nr de facturi platite       : " << this->uNrFacturi << std::endl
		<< "Pretul facturilor este      : ";

	std::cout << "[ ";
	for (int i = 0; i < this->uNrFacturi; ++i)
	{
		std::cout << this->uValoareFactura[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Codul clientului este      : " << this->uCodClient << std::endl;
	std::cout << "========================================" << std::endl << std::endl;
}

void CheltuieliCuUtilitatile::SetData(const char* Data)
{
	if (Data != nullptr)
	{
		this->uData = new char[strlen(Data) + 1];
		strcpy(this->uData, Data);
	}
	else
	{
		std::cerr << "Data invalida";
	}
}

void CheltuieliCuUtilitatile::SetNrFacturi(int NrFacturi)
{
	if (NrFacturi > 0)
	{
		this->uNrFacturi = NrFacturi;
	}
	else
	{
		std::cerr << "Nr alimente nu poate fi negativ!";
	}
}

void CheltuieliCuUtilitatile::SetValoareFactura(double* ValoareFactura)
{
	if (ValoareFactura != nullptr)
	{
		this->uValoareFactura = new double[this->uNrFacturi];
		for (int i = 0; i < this->uNrFacturi; i++)
		{
			this->uValoareFactura[i] = ValoareFactura[i];
		}
	}
}

void CheltuieliCuUtilitatile::SetCodClient(char CodClient[25])
{
	strcpy(this->uCodClient, CodClient);
}

std::ostream& operator<<(std::ostream& os, const CheltuieliCuUtilitatile& rhs)
{
	os << "========================================" << std::endl;
	os << "Data efectuarii cheluielii  : " << rhs.uData << std::endl
		<< "Nr de facturi cumparate     : " << rhs.uNrFacturi << std::endl
		<< "Pretul facturilor  este     : ";

	os << "[ ";
	for (int i = 0; i < rhs.uNrFacturi; ++i)
	{
		std::cout << rhs.uValoareFactura[i] << " ";
	}
	os << "]" << std::endl;
	os << "Cod client este             : " << rhs.uCodClient << std::endl;
	os << "========================================" << std::endl << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, CheltuieliCuUtilitatile& rhs)
{
	std::cout <<std::endl<< "Introduceti data efectuarii cheltuielii: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.uData;
	rhs.uData = new char[strlen(buff) + 1];
	strcpy(rhs.uData, buff);

	std::cout << "Introduceti nr de facturi platite: "; is >> rhs.uNrFacturi;
	std::cout << "Introduceti pretul facturilor:" << std::endl;
	delete[] rhs.uValoareFactura;
	rhs.uValoareFactura = new double[rhs.uNrFacturi];
	for (int i = 0; i < rhs.uNrFacturi; ++i)
	{
		std::cout << "\tFactura nr." << i + 1 << ": ";
		is >> rhs.uValoareFactura[i];
	}

	std::cout << "Introduceti nr cod client: "; is >> rhs.uCodClient;

	return is;
}
