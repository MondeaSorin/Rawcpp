#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Persoana.h"

Persoana::Persoana()
	:pCNP("Fara CNP"),
	pNume(nullptr),
	pSurseVenit(0),
	pVenit(nullptr),
	pCodPostal("000000"),
	pCheltuieliCuUtilitatile(),
	pCheltuieliAlimentare(),
	pCheltuieliCuAsigurari(),
	pCheltuieliDiverse()
{
	this->pNume = new char[strlen("Anonim") + 1];
	strcpy(this->pNume, "Anonim");

	this->pVenit = new double;
	*pVenit = 0;
}

Persoana::Persoana(const std::string CNP,
	const char* Nume,
	int SurseVenit,
	double* Venit,
	const char CodPostal[7],
	CheltuieliCuUtilitatile CheltuieliCuUtilitatile,
	CheltuieliAlimentare CheltuieliAlimentare,
	CheltuieliCuAsigurari CheltuieliCuAsigurari,
	CheltuieliDiverse CheltuieliDiverse)
	:pCNP(CNP),
	pNume(nullptr),
	pSurseVenit(0),
	pVenit(nullptr),
	pCodPostal("000000"),
	pCheltuieliCuUtilitatile(),
	pCheltuieliAlimentare(),
	pCheltuieliCuAsigurari(),
	pCheltuieliDiverse()
{
	this->pNume = new char[strlen(Nume) + 1];
	strcpy(this->pNume, Nume);

	this->pSurseVenit = SurseVenit;

	this->pVenit = new double[SurseVenit];

	for (int i = 0; i < SurseVenit; i++)
	{
		this->pVenit[i] = Venit[i];
	}

	strcpy(this->pCodPostal, CodPostal);

	this->pCheltuieliCuUtilitatile = CheltuieliCuUtilitatile;
	this->pCheltuieliAlimentare = CheltuieliAlimentare;
	this->pCheltuieliCuAsigurari = CheltuieliCuAsigurari;
	this->pCheltuieliDiverse = CheltuieliDiverse;
}

Persoana::Persoana(int SurseVenit,
	double* Venit)
	:pCNP("Fara CNP"),
	pNume(nullptr),
	pSurseVenit(0),
	pVenit(nullptr),
	pCodPostal("000000"),
	pCheltuieliCuUtilitatile(),
	pCheltuieliAlimentare(),
	pCheltuieliCuAsigurari(),
	pCheltuieliDiverse()
{
	this->pNume = new char[strlen("Anonim") + 1];
	strcpy(this->pNume, "Anonim");

	this->pSurseVenit = SurseVenit;

	this->pVenit = new double[SurseVenit];

	for (int i = 0; i < SurseVenit; i++)
	{
		this->pVenit[i] = Venit[i];
	}
}

Persoana::~Persoana()
{
	if (this->pNume != nullptr)
		delete[] this->pNume;
	if (this->pVenit != nullptr)
		delete[] this->pVenit;
}

Persoana::Persoana(const Persoana& source)
	:pCNP(source.pCNP)
{
	this->pNume = new char[strlen(source.pNume) + 1];
	strcpy(this->pNume, source.pNume);

	this->pSurseVenit = source.pSurseVenit;

	this->pVenit = new double[source.pSurseVenit];

	for (int i = 0; i < source.pSurseVenit; i++)
	{
		this->pVenit[i] = source.pVenit[i];
	}

	strcpy(this->pCodPostal, source.pCodPostal);

	this->pCheltuieliCuUtilitatile = source.pCheltuieliCuUtilitatile;
	this->pCheltuieliAlimentare = source.pCheltuieliAlimentare;
	this->pCheltuieliCuAsigurari = source.pCheltuieliCuAsigurari;
	this->pCheltuieliDiverse = source.pCheltuieliDiverse;
}

Persoana& Persoana::operator=(const Persoana& rhs)
{
	if (this != &rhs)
	{
		if (this->pNume != nullptr)
			delete[] this->pNume;
		this->pNume = new char[strlen(rhs.pNume) + 1];
		strcpy(this->pNume, rhs.pNume);

		this->pSurseVenit = rhs.pSurseVenit;

		if (this->pVenit != nullptr)
			delete[] this->pVenit;
		this->pVenit = new double[rhs.pSurseVenit];

		for (int i = 0; i < rhs.pSurseVenit; i++)
		{
			this->pVenit[i] = rhs.pVenit[i];
		}

		strcpy(this->pCodPostal, rhs.pCodPostal);

		this->pCheltuieliCuUtilitatile = rhs.pCheltuieliCuUtilitatile;
		this->pCheltuieliAlimentare = rhs.pCheltuieliAlimentare;
		this->pCheltuieliCuAsigurari = rhs.pCheltuieliCuAsigurari;
		this->pCheltuieliDiverse = rhs.pCheltuieliDiverse;
	}

	return *this;
}

double Persoana::operator[](int index)
{
	if (index >= 0 && index < this->pSurseVenit)
	{
		return this->pVenit[index];
	}
	else
	{
		std::cerr << "Index invalid";
	}
}

double Persoana::operator+(const Persoana& rhs)
{
	double VenitTotal{};

	for (int i = 0; i < this->pSurseVenit; i++)
	{
		VenitTotal += this->pVenit[i];
	}

	for (int i = 0; i < rhs.pSurseVenit; i++)
	{
		VenitTotal += rhs.pVenit[i];
	}

	return VenitTotal;
}

Persoana& Persoana::operator--()
{
	int buff_size = this->pSurseVenit - 1;
	double* buff = new double[buff_size];

	for (int i = 0; i < buff_size; i++)
	{
		buff[i] = this->pVenit[i];
	}

	delete[] this->pVenit;
	this->pSurseVenit = buff_size;
	this->pVenit = buff;

	return *this;
}

Persoana Persoana::operator--(int)
{
	Persoana Temp(*this);
	Persoana::operator--();
	return Temp;
}

Persoana::operator int()
{
	return this->pSurseVenit;
}

bool Persoana::operator!()
{
	double VenitTotal{};

	for (int i = 0; i < this->pSurseVenit; i++)
	{
		VenitTotal += this->pVenit[i];
	}

	return VenitTotal <= 0;
}

bool Persoana::operator<(const Persoana& rhs)
{
	return this->pSurseVenit < rhs.pSurseVenit;
}

bool Persoana::operator==(const Persoana& rhs)
{
	double VenitTotal1{};

	for (int i = 0; i < this->pSurseVenit; i++)
	{
		VenitTotal1 += this->pVenit[i];
	}

	double VenitTotal2{};

	for (int i = 0; i < rhs.pSurseVenit; i++)
	{
		VenitTotal2 += rhs.pVenit[i];
	}

	return(this->pSurseVenit == rhs.pSurseVenit && VenitTotal1 == VenitTotal2);
}

void Persoana::afisare()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "CNP-ul este                        : " << this->pCNP << std::endl
		<< "Numele este                        : " << this->pNume << std::endl
		<< "Numarul surselor de venit este     : " << this->pSurseVenit << std::endl
		<< "Venitul din fiecare sursa este     : [ ";

	for (int i = 0; i < this->pSurseVenit; ++i)
	{
		std::cout << this->pVenit[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Codul postal este               : " << this->pCodPostal << std::endl
		<< "Cheltuielile cu utilitatile sunt   : " << this->pCheltuieliCuUtilitatile << std::endl
		<< "Cheltuielile cu alimentele sunt    : " << this->pCheltuieliCuUtilitatile << std::endl
		<< "Cheltuielile cu asigurarile sunt   : " << this->pCheltuieliCuUtilitatile << std::endl
		<< "Cheltuielile cu diverse sunt       : " << this->pCheltuieliCuUtilitatile << std::endl;

	std::cout << "=============================================" << std::endl << std::endl;
}

void Persoana::SetNume(const char* Nume)
{
	if (Nume != nullptr)
	{
		if (this->pNume != nullptr)
			delete[] this->pNume;
		this->pNume = new char[strlen(Nume) + 1];
		strcpy(this->pNume, Nume);
	}
	else
	{
		std::cerr << "Nume invalid";
	}
}
void Persoana::SetSurseVenit(int SurseVenit)
{
	if (SurseVenit > 0)
	{
		this->pSurseVenit = SurseVenit;
	}
	else
	{
		std::cerr << "Sursele nu pot fi negative";
	}
}
void Persoana::SetVenit(double* Venit)
{
	if (Venit != nullptr)
	{
		if (this->pVenit != nullptr)
			delete[] this->pVenit;

		this->pVenit = new double[this->pSurseVenit];

		for (int i = 0; i < this->pSurseVenit; i++)
		{
			this->pVenit[i] = Venit[i];
		}
	}
	else
	{
		std::cerr << "vecctor gol";
	}
}
void Persoana::SeCodPostal(char CodPostal[7])
{
	strcpy(this->pCodPostal, CodPostal);
}
void Persoana::SetCheltuieliCuUtilitatile(CheltuieliCuUtilitatile CheltuieliCuUtilitatile)
{
	this->pCheltuieliCuUtilitatile = CheltuieliCuUtilitatile;
}
void Persoana::SetCheltuieliAlimentare(CheltuieliAlimentare CheltuieliAlimentare)
{
	this->pCheltuieliAlimentare = CheltuieliAlimentare;
}
void Persoana::SetCheltuieliCuAsigurari(CheltuieliCuAsigurari CheltuieliCuAsigurari)
{
	this->pCheltuieliCuAsigurari = CheltuieliCuAsigurari;
}
void Persoana::SetCheltuieliDiverse(CheltuieliDiverse CheltuieliDiverse)
{
	this->pCheltuieliDiverse = CheltuieliDiverse;
}

std::ostream& operator<<(std::ostream& os, const Persoana& rhs)
{
	os << "=============================================" << std::endl;
	os << "CNP-ul este                        : " << rhs.pCNP << std::endl
		<< "Numele este                        : " << rhs.pNume << std::endl
		<< "Numarul surselor de venit este     : " << rhs.pSurseVenit << std::endl
		<< "Venitul din fiecare sursa este     : [ ";

	for (int i = 0; i < rhs.pSurseVenit; ++i)
	{
		std::cout << rhs.pVenit[i] << " ";
	}
	os << "]" << std::endl;
	os << "Codul postal este               : " << std::endl << rhs.pCodPostal << std::endl
		<< "Cheltuielile cu utilitatile sunt   : " << std::endl << rhs.pCheltuieliCuUtilitatile << std::endl
		<< "Cheltuielile cu alimentele sunt    : " << std::endl << rhs.pCheltuieliAlimentare << std::endl
		<< "Cheltuielile cu asigurarile sunt   : " << std::endl << rhs.pCheltuieliCuAsigurari << std::endl
		<< "Cheltuielile cu diverse sunt       : " << std::endl << rhs.pCheltuieliDiverse << std::endl;

	os << "=============================================" << std::endl << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Persoana& rhs)
{
	std::cout << "Introduceti numele perosanei : ";
	char buff[1000];
	is >> buff;
	delete[] rhs.pNume;
	rhs.pNume = new char[strlen(buff) + 1];
	strcpy(rhs.pNume, buff);

	std::cout << "Introduceti nr de surse de venit: "; is >> rhs.pSurseVenit;
	std::cout << "Introduceti veniturile:" << std::endl;
	delete[] rhs.pVenit;
	rhs.pVenit = new double[rhs.pSurseVenit];
	for (int i = 0; i < rhs.pSurseVenit; ++i)
	{
		std::cout << "\tVenit din sursa nr." << i + 1 << ": ";
		is >> rhs.pVenit[i];
	}

	std::cout << "Introduceti codul postal: "; is >> rhs.pCodPostal;
	std::cout << "Introduceti cheltuielile cu utilitatile: "; is >> rhs.pCheltuieliCuUtilitatile;
	std::cout << "Introduceti cheltuielile cu alimentele: "; is >> rhs.pCheltuieliAlimentare;
	std::cout << "Introduceti cheltuielile cu asigurarile: "; is >> rhs.pCheltuieliCuAsigurari;
	std::cout << "Introduceti cheltuielile cu diverse: "; is >> rhs.pCheltuieliDiverse;
	return is;
}

void Persoana::print(std::ostream& os) const
{
	os << "=============================================" << std::endl;
	os << "CNP-ul este                        : " << this->pCNP << std::endl
		<< "Numele este                        : " << this->pNume << std::endl
		<< "Numarul surselor de venit este     : " << this->pSurseVenit << std::endl
		<< "Venitul din fiecare sursa este     : [ ";

	for (int i = 0; i < this->pSurseVenit; ++i)
	{
		std::cout << this->pVenit[i] << " ";
	}
	os << "]" << std::endl;
	os << "Codul postal este               : " << std::endl << this->pCodPostal << std::endl
		<< "Cheltuielile cu utilitatile sunt   : " << std::endl << this->pCheltuieliCuUtilitatile << std::endl
		<< "Cheltuielile cu alimentele sunt    : " << std::endl << this->pCheltuieliAlimentare << std::endl
		<< "Cheltuielile cu asigurarile sunt   : " << std::endl << this->pCheltuieliCuAsigurari << std::endl
		<< "Cheltuielile cu diverse sunt       : " << std::endl << this->pCheltuieliDiverse << std::endl;

	os << "=============================================" << std::endl << std::endl;

}

void Persoana::AfisareDateFacturi()
{
	std::cout << "DD.MM.YYYY" << std::endl
		<< this->pCheltuieliAlimentare.GetData() << std::endl
		<< this->pCheltuieliCuAsigurari.GetData() << std::endl
		<< this->pCheltuieliCuUtilitatile.GetData() << std::endl
		<< this->pCheltuieliDiverse.GetData() << std::endl
		<< "-----------" << std::endl;
}

double Persoana::CheltuieliTotale()
{
	double Cheltuieli{};
	for (int i{}; i < this->pCheltuieliAlimentare.GetNrAlimente(); ++i)
	{
		Cheltuieli += this->pCheltuieliAlimentare.GetPretAliment()[i];
	}

	for (int i{}; i < this->pCheltuieliCuAsigurari.GetNrMasini(); ++i)
	{
		Cheltuieli += this->pCheltuieliCuAsigurari.GetValoareAsigurare()[i];
	}

	for (int i{}; i < this->pCheltuieliCuUtilitatile.GetNrFacturi(); ++i)
	{
		Cheltuieli += this->pCheltuieliCuUtilitatile.GetValoareFactura()[i];
	}

	for (int i{}; i < this->pCheltuieliDiverse.GetNrCheltuiliEfectuate(); ++i)
	{
		Cheltuieli += this->pCheltuieliDiverse.GetValoareCheltuiala()[i];
	}

	return Cheltuieli;
}

double Persoana::InterogareSoldCurent()
{
	double SoldCurent{};
	for (int i{}; i < this->pSurseVenit; ++i)
	{
		SoldCurent += this->pVenit[i];
	}

	return SoldCurent;
}

void Persoana::StergePersoanaDinFisier(int Rand)
{
	std::ifstream fin("PersoanaInput.txt");
	std::ofstream fout;
	fout.open("temp.txt", std::ios::out);

	char ch;
	int line = 1;
	while (fin.get(ch))
	{
		if (ch == '\n')
			line++;

		if (line != Rand)    
			fout << ch;
	}
	fout.close();
	fin.close();
	remove("PersoanaInput.txt");
	rename("temp.txt", "PersoanaInput.txt");
}
