#include "Pensionar.h"
#include <fstream>

using namespace std;


Pensionar::Pensionar()
	:Persoana()
{
	this->pReducereDePensionar = 0;
}

Pensionar::Pensionar(string CNP,
	char* Nume,
	int SurseVenit,
	double* Venit,
	char CodPostal[7],
	CheltuieliCuUtilitatile CheltuieliCuUtilitatile,
	CheltuieliAlimentare CheltuieliAlimentare,
	CheltuieliCuAsigurari CheltuieliCuAsigurari,
	CheltuieliDiverse CheltuieliDiverse,
	int ReducereDePensionar)
	:Persoana(CNP,
		Nume,
		SurseVenit,
		Venit,
		CodPostal,
		CheltuieliCuUtilitatile,
		CheltuieliAlimentare,
		CheltuieliCuAsigurari,
		CheltuieliDiverse)
{
	this->pReducereDePensionar = ReducereDePensionar;
}

Pensionar::~Pensionar() { }

Pensionar::Pensionar(const Pensionar& source)
	:Persoana(source)
{
	this->pReducereDePensionar = source.pReducereDePensionar;
}

Pensionar& Pensionar::operator=(const Pensionar& source)
{
	if (this != &source)
	{
		Persoana::operator=(source);
		this->pReducereDePensionar = source.pReducereDePensionar;
	}

	return *this;
}

void Pensionar::print(std::ostream& os) const
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
		<< "Cheltuielile cu diverse sunt       : " << std::endl << this->pCheltuieliDiverse << std::endl
		<< "Reducerea Pensionarului este       : " << std::endl << this->pReducereDePensionar << std::endl;


	os << "=============================================" << std::endl << std::endl;

}

void Pensionar::AfisareDateFacturi()
{
	std::cout << "DD.MM.YYYY" << std::endl
		<< this->pCheltuieliAlimentare.GetData() << std::endl
		<< this->pCheltuieliCuAsigurari.GetData() << std::endl
		<< this->pCheltuieliCuUtilitatile.GetData() << std::endl
		<< this->pCheltuieliDiverse.GetData() << std::endl
		<< "-----------" << std::endl;
}

double Pensionar::CheltuieliTotale()
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

	return Cheltuieli - ((static_cast<double>(pReducereDePensionar)/100)) * Cheltuieli;
}

double Pensionar::InterogareSoldCurent()
{
	double SoldCurent{};
	for (int i{}; i < this->pSurseVenit; ++i)
	{
		SoldCurent += this->pVenit[i];
	}

	return SoldCurent;
}

void Pensionar::StergePersoanaDinFisier(int Rand)
{
	std::ifstream fin("PensionarInput.txt");
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
	remove("PensionarInput.txt");
	rename("temp.txt", "PensionarInput.txt");
}
