#include "CheltuieliCuAsigurari.h"

CheltuieliCuAsigurari::CheltuieliCuAsigurari()
	:asData(nullptr), asNrMasini(0), asValoareAsigurare(nullptr), asValabilitate{ " " }
{
	this->asData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->asData, "Necunoscuta");

	this->asValoareAsigurare = new double;
	*asValoareAsigurare = 0;
}

CheltuieliCuAsigurari::CheltuieliCuAsigurari(const char* Data,
	int NrMasini,
	double* ValoareAsigurare,
	const char Valabilitate[20])
	:asData(nullptr), asNrMasini(0), asValoareAsigurare(nullptr), asValabilitate{ " " }
{
	this->asData = new char[strlen(Data) + 1];
	strcpy(this->asData, Data);

	this->asNrMasini = NrMasini;

	this->asValoareAsigurare = new double[NrMasini];
	for (int i = 0; i < NrMasini; i++)
	{
		this->asValoareAsigurare[i] = ValoareAsigurare[i];
	}

	strcpy(this->asValabilitate, Valabilitate);
}

CheltuieliCuAsigurari::CheltuieliCuAsigurari(int NrMasini,
	double* ValoareAsigurare)
	:asData(nullptr), asNrMasini(0), asValoareAsigurare(nullptr), asValabilitate{ " " }
{
	this->asData = new char[strlen("Necunoscuta") + 1];
	strcpy(this->asData, "Necunoscuta");

	this->asNrMasini = NrMasini;

	this->asValoareAsigurare = new double[NrMasini];
	for (int i = 0; i < NrMasini; i++)
	{
		this->asValoareAsigurare[i] = ValoareAsigurare[i];
	}
}

CheltuieliCuAsigurari::~CheltuieliCuAsigurari()
{
	if (this->asData != nullptr)
		delete[] this->asData;
	if (this->asValoareAsigurare != nullptr)
		delete[] this->asValoareAsigurare;
}

CheltuieliCuAsigurari::CheltuieliCuAsigurari(const CheltuieliCuAsigurari& source)
{
	this->asData = new char[strlen(source.asData) + 1];
	strcpy(this->asData, source.asData);

	this->asNrMasini = source.asNrMasini;

	this->asValoareAsigurare = new double[source.asNrMasini];
	for (int i = 0; i < source.asNrMasini; i++)
	{
		this->asValoareAsigurare[i] = source.asValoareAsigurare[i];
	}

	strcpy(this->asValabilitate, source.asValabilitate);
}

CheltuieliCuAsigurari& CheltuieliCuAsigurari::operator=(const CheltuieliCuAsigurari& rhs)
{
	if (this != &rhs)
	{
		if (this->asData != nullptr)
			delete[] this->asData;
		this->asData = new char[strlen(rhs.asData) + 1];
		strcpy(this->asData, rhs.asData);

		this->asNrMasini = rhs.asNrMasini;

		if (this->asValoareAsigurare != nullptr)
			delete[] this->asValoareAsigurare;
		this->asValoareAsigurare = new double[rhs.asNrMasini];
		for (int i = 0; i < rhs.asNrMasini; i++)
		{
			this->asValoareAsigurare[i] = rhs.asValoareAsigurare[i];
		}

		strcpy(this->asValabilitate, rhs.asValabilitate);
	}

	return *this;
}


double CheltuieliCuAsigurari::operator[](int index)
{
	if (index > 0 && index < this->asNrMasini)
	{
		return this->asValoareAsigurare[index];
	}
	else
	{
		std::cerr << "Index negasit";
	}
}

double CheltuieliCuAsigurari::operator+(const CheltuieliCuAsigurari& rhs)
{
	double Suma{};

	for (int i = 0; i < this->asNrMasini; ++i)
	{
		Suma += this->asValoareAsigurare[i];
	}

	for (int i = 0; i < rhs.asNrMasini; ++i)
	{
		Suma += rhs.asValoareAsigurare[i];
	}

	return Suma;
}

CheltuieliCuAsigurari& CheltuieliCuAsigurari::operator--()
{
	int buff_size = this->asNrMasini - 1;
	double* buff = new double[buff_size];
	for (int i = 0; i < buff_size; ++i)
	{
		buff[i] = this->asValoareAsigurare[i];
	}

	this->asNrMasini = buff_size;

	delete[] this->asValoareAsigurare;
	this->asValoareAsigurare = buff;

	return *this;
}

CheltuieliCuAsigurari CheltuieliCuAsigurari::operator--(int)
{
	CheltuieliCuAsigurari Temp(*this);
	CheltuieliCuAsigurari::operator--();
	return Temp;
}

CheltuieliCuAsigurari::operator int()
{
	return this->asNrMasini;
}

bool CheltuieliCuAsigurari::operator<(const CheltuieliCuAsigurari& rhs)
{
	return this->asNrMasini < rhs.asNrMasini;
}

bool CheltuieliCuAsigurari::operator==(const CheltuieliCuAsigurari& rhs)
{
	double suma1{}, suma2{};
	for (int i = 0; i < this->asNrMasini; ++i)
	{
		suma1 += this->asValoareAsigurare[i];
	}

	for (int i = 0; i < rhs.asNrMasini; ++i)
	{
		suma2 += rhs.asValoareAsigurare[i];
	}

	return (this->asNrMasini == rhs.asNrMasini && suma1 == suma2);
}

void CheltuieliCuAsigurari::afisare()
{
	std::cout << "========================================" << std::endl;
	std::cout << "Data efectuarii cheluielii  : " << this->asData << std::endl
		<< "Nr de masini asigurate      : " << this->asNrMasini << std::endl
		<< "Pretul asigurarilor este    : ";

	std::cout << "[ ";
	for (int i = 0; i < this->asNrMasini; ++i)
	{
		std::cout << this->asValoareAsigurare[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Valabilitate        : " << this->asValabilitate << std::endl;
	std::cout << "========================================" << std::endl << std::endl;
}

void CheltuieliCuAsigurari::SetData(const char* Data)
{
	if (Data != nullptr)
	{
		this->asData = new char[strlen(Data) + 1];
		strcpy(this->asData, Data);
	}
	else
	{
		std::cerr << "Data invalida";
	}
}

void CheltuieliCuAsigurari::SetNrMasini(int NrMasini)
{
	if (NrMasini > 0)
	{
		this->asNrMasini = NrMasini;
	}
	else
	{
		std::cerr << "Nr masini nu poate fi negativ!";
	}
}

void CheltuieliCuAsigurari::SetValoareAsigurare(double* ValoareAsigurare)
{
	if (ValoareAsigurare != nullptr)
	{
		this->asValoareAsigurare = new double[this->asNrMasini];
		for (int i = 0; i < this->asNrMasini; i++)
		{
			this->asValoareAsigurare[i] = ValoareAsigurare[i];
		}
	}
}

void CheltuieliCuAsigurari::SetValabilitate(char Valabilitate[20])
{
	strcpy(this->asValabilitate, Valabilitate);
}

std::ostream& operator<<(std::ostream& os, const CheltuieliCuAsigurari& rhs)
{
	os << "========================================" << std::endl;
	os << "Data efectuarii cheluielii  : " << rhs.asData << std::endl
		<< "Nr de asigurari cumparate   : " << rhs.asNrMasini << std::endl
		<< "Pretul asigurarilor este    : ";

	os << "[ ";
	for (int i = 0; i < rhs.asNrMasini; ++i)
	{
		std::cout << rhs.asValoareAsigurare[i] << " ";
	}
	os << "]" << std::endl;
	os << "Valabilitatea este         : " << rhs.asValabilitate << std::endl;
	os << "========================================" << std::endl << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, CheltuieliCuAsigurari& rhs)
{
	std::cout << std::endl << "Introduceti data efectuarii cheltuielii: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.asData;
	rhs.asData = new char[strlen(buff) + 1];
	strcpy(rhs.asData, buff);

	std::cout << "Introduceti nr de asigurari cumparate: "; is >> rhs.asNrMasini;
	std::cout << "Introduceti pretul asigurarilor:" << std::endl;
	delete[] rhs.asValoareAsigurare;
	rhs.asValoareAsigurare = new double[rhs.asNrMasini];
	for (int i = 0; i < rhs.asNrMasini; ++i)
	{
		std::cout << "\tAsigurarea nr." << i + 1 << ": ";
		is >> rhs.asValoareAsigurare[i];
	}

	std::cout << "Introduceti intervalul de valabilitate: "; is >> rhs.asValabilitate;

	return is;
}
