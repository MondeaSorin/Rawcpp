#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include "Persoana.h"

using namespace std;

int main(int argc, char** argv)
{
	int StergeRand{};
	double dim{};

	for (int i{}; i < argc; i++)                 
	{
		cout << argv[i] << endl;
	}											

	string NumeUtilizator;

	cout << "Introduceti numele utilizatorului: "; cin >> NumeUtilizator;
	
	fstream RaportUtilizatori;
	RaportUtilizatori.open("RapoarteUtilizatori.txt", ios::out | ios::app);
	if (RaportUtilizatori.is_open())
	{
		RaportUtilizatori << NumeUtilizator << endl;
		RaportUtilizatori.close();
	}
	else
	{
		cout << "nu exista";
	}


	int Selection{};
	ifstream PersoanaInput;
	ofstream PersoanaOutput;

	list<Persoana> lp;
	Persoana p;
	string CNP;
	char* Nume = new char[100];
	int SurseVenit{};
	double* Venit{ nullptr };
	char CodPostal[7];

	CheltuieliCuUtilitatile cCheltuieliCuUtilitatile;
	char* uData = new char[100];
	int uNrFacturi{};
	double* uValoareFactura{nullptr};
	char uCodClient[25];
	
	CheltuieliAlimentare cCheltuieliAlimentare;
	char* aData = new char[100];
	int aNrAlimente{};
	double* aPretAliment {nullptr};
	char aNrBonFiscal[10];

	CheltuieliCuAsigurari cCheltuieliCuAsigurari;
	char* asData = new char[100];
	int asNrMasini{};
	double* asValoareAsigurare{nullptr};
	char asValabilitate[20];

	CheltuieliDiverse cCheltuieliDiverse;
	char* dData = new char[100];
	int dNrCheltuiliEfectuate{};
	double* dValoareCheltuiala{nullptr};
	char dDenumireProdus[50];

	do 
	{
		cout << endl;
		cout << "==================== MENIU ====================" << endl
			<< "(1)  Citire date din fisier text" << endl
			<< "(2)  Salvare date in fisier binar" << endl
			<< "(3)  Adaugare obiect in lista" << endl
			<< "(4)  Interogare lista utilizatori" << endl
			<< "(5)  Afisare date facturi" << endl
			<< "(6)  Interogare sold curent" << endl
			<< "(7)  Afisare date facturi" << endl
			<< "(8)  Cheltuieli totale" << endl
			<< "(9)  Eliminarea unei cheltuieli din fisier" << endl
			<< "(0)  Iesire din aplicatie" << endl
			<< "===============================================" << endl << endl;

		cout << "Selectati Optiunea: ";

		cin >> Selection;

		switch (Selection)
		{
		case 1:
			PersoanaInput.open(argv[1]);
			if (PersoanaInput.is_open())
			{
				while (!PersoanaInput.eof())
				{
					PersoanaInput >> CNP >> Nume >> SurseVenit;
					Venit = new double[SurseVenit];
					for (int i{}; i < SurseVenit; ++i)
					{
						PersoanaInput >> Venit[i];
					}

					PersoanaInput >> CodPostal >> uData >> uNrFacturi;
					
					uValoareFactura = new double[uNrFacturi];
					for (int i{}; i < uNrFacturi; ++i)
					{
						PersoanaInput >> uValoareFactura[i];
					}

					PersoanaInput >> uCodClient >> aData >> aNrAlimente;

					aPretAliment = new double[aNrAlimente];
					for (int i{}; i < aNrAlimente; ++i)
					{
						PersoanaInput >> aPretAliment[i];
					}

					PersoanaInput >> aNrBonFiscal >> asData >> asNrMasini;

					asValoareAsigurare = new double[asNrMasini];
					for (int i{}; i < asNrMasini; ++i)
					{
						PersoanaInput >> asValoareAsigurare[i];
					}

					PersoanaInput >> asValabilitate >> dData >> dNrCheltuiliEfectuate;

					dValoareCheltuiala = new double[dNrCheltuiliEfectuate];
					for (int i{}; i < dNrCheltuiliEfectuate; ++i)
					{
						PersoanaInput >> dValoareCheltuiala[i];
					}

					PersoanaInput >> dDenumireProdus;

					cCheltuieliCuUtilitatile.SetData(uData);
					cCheltuieliCuUtilitatile.SetNrFacturi(uNrFacturi);
					cCheltuieliCuUtilitatile.SetValoareFactura(uValoareFactura);
					cCheltuieliCuUtilitatile.SetCodClient(uCodClient);

					cCheltuieliAlimentare.SetData(aData);
					cCheltuieliAlimentare.SetNrAlimente(aNrAlimente);
					cCheltuieliAlimentare.SetPretAliment(aPretAliment);
					cCheltuieliAlimentare.SetNrBonFiscal(aNrBonFiscal);

					cCheltuieliCuAsigurari.SetData(asData);
					cCheltuieliCuAsigurari.SetNrMasini(asNrMasini);
					cCheltuieliCuAsigurari.SetValoareAsigurare(asValoareAsigurare);
					cCheltuieliCuAsigurari.SetValabilitate(asValabilitate);

					cCheltuieliDiverse.SetData(dData);
					cCheltuieliDiverse.SetNrCheltuiliEfectuate(dNrCheltuiliEfectuate);
					cCheltuieliDiverse.SetValoareCheltuiala(dValoareCheltuiala);
					cCheltuieliDiverse.SetDenumireProdus(dDenumireProdus);

					p.SetNume(Nume);
					p.SetSurseVenit(SurseVenit);
					p.SetVenit(Venit);
					p.SetCheltuieliAlimentare(cCheltuieliAlimentare);
					p.SetCheltuieliCuAsigurari(cCheltuieliCuAsigurari);
					p.SetCheltuieliCuUtilitatile(cCheltuieliCuUtilitatile);
					p.SetCheltuieliDiverse(cCheltuieliDiverse);

					lp.push_back(p); 

					for (auto& obiect : lp)
					{
						cout << obiect << endl;
					}
				}
				PersoanaInput.close();
			}
			else
			{
				cout << "Fisierul nu a putut fi deschis cu succes" << endl;
			}
			break;

		case 2:
			PersoanaOutput.open("PersoanaOutput.bin", ios::out | ios::binary | ios::app);
			if (PersoanaOutput.is_open())
			{
				for (auto& obiect : lp)
				{
					dim = strlen(obiect.GetNume()) + 1;
					PersoanaOutput.write(reinterpret_cast<char*>(obiect.GetNume()), sizeof(dim) + 1);

					dim = obiect.GetSurseVenit();
					PersoanaOutput.write(reinterpret_cast<char*>(&dim), sizeof(dim));

					for (int i{}; i < obiect.GetSurseVenit(); ++i)
					{
						PersoanaOutput.write(reinterpret_cast<char*>(&obiect.GeVenitAdresa()[i]), sizeof(double));
					}

					dim = strlen(obiect.GetCodPostal()) + 1;
					PersoanaOutput.write(obiect.GetCodPostal(), sizeof(dim));

					dim = strlen(obiect.GetCheltuieliAlimentare().GetData() + 1);
					PersoanaOutput.write(reinterpret_cast<char*>(&dim), sizeof(dim));
					strcpy(aData, obiect.GetCheltuieliAlimentare().GetData());
					PersoanaOutput.write(reinterpret_cast<char*>(&aData), dim);

					dim = obiect.GetCheltuieliAlimentare().GetNrAlimente();
					PersoanaOutput.write(reinterpret_cast<char*>(&dim), sizeof(dim));

					delete[] aPretAliment;
					aPretAliment = new double[dim];
					for (int i{}; i < dim; ++i)
					{
						aPretAliment[i] = obiect.GetCheltuieliAlimentare().GetPretAliment()[i];
						PersoanaOutput.write(reinterpret_cast<char*>(&aPretAliment[i]), sizeof(dim));
					}

					dim = strlen(obiect.GetCheltuieliAlimentare().GetNrBonFiscal() + 1);
					strcpy(aNrBonFiscal, obiect.GetCheltuieliAlimentare().GetNrBonFiscal());
					PersoanaOutput.write(reinterpret_cast<char*>(&dim), sizeof(dim)) ;

					PersoanaOutput.write(reinterpret_cast<char*>(&aNrBonFiscal), dim);

				}
				PersoanaOutput.close();
			}
			else
			{
				cout << "fisierul nu exista";
			}

			break;
		case 3:
			cin >> p;
			lp.push_back(p);

			break;

		case 4:
			RaportUtilizatori.open("RapoarteUtilizatori.txt", ios::in);
			if (RaportUtilizatori.is_open())
			{
				while (!RaportUtilizatori.eof())
				{
					RaportUtilizatori >> NumeUtilizator;
					cout << NumeUtilizator << endl;
				}
				RaportUtilizatori.close();
			}
			else
			{
				cout << "Fisierul nu a putut fi deschis";
			}

			break;
		case 5:
			for (auto& element : lp)
			{
				element.AfisareDateFacturi();
			}

			break;
		case 6:
			for (auto& element : lp)
			{
				cout << element.InterogareSoldCurent();
			}

			break;
		case 7:
			for (auto& element : lp)
			{
				element.AfisareDateFacturi();
			}

			break;
		case 8:
			for (auto& element : lp)
			{
				cout << element.CheltuieliTotale();
			}

			break;
		case 9:
			for (auto& element : lp)
			{
				cin >> StergeRand;
				element.StergePersoanaDinFisier(StergeRand);
			}
			break;

		case 0:
			cout << "La revedere\n\n";

			break;
		default :
			cout << endl << "Eroare!" << endl;
		} 
	} while (Selection != 0);
}
