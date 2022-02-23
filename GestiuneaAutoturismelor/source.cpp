#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include "Sofer.h"
#include "Mijloc_De_Transport.h"
#include "Avion.h"
#include "Masina.h"
#include "Tren.h"
using namespace std;

int main()
{

	int selection{};
	int SoferSelection{};
	int MijlocDeTransportSelection{};
	int MasinaSelection{};
	int AvionSelection{};
	int TrenSelection{};

	ifstream CitireSofer;
	ifstream CitireMijlocDeTransport;
	ifstream CitireMasina;
	ifstream CitireAvion;
	ifstream CitireTren;

	list<Sofer> Soferi;
	Sofer SoferTemp;
	char* nume = new char[100];
	int AniVechime{};
	int NrzileMunca{};
	int* ore_de_munca_pe_zile{ nullptr };
	int NrMasiniConduse{};
	string* marca_masini_conduse{ nullptr };

	list<Mijloc_De_Transport> MijloaceDeTransport;
	Mijloc_De_Transport MijlocDeTransportTemp;
	char* marca = new char[100];
	double CapacitateRezervor{};
	double KmInscrisi{};
	int NrZileFunctionare{};
	double* IstoricConsum{};
	int NrSoferi{};
	Sofer* soferi{ nullptr };

	list<Tren> Trenuri;
	Tren TrenTemp;
	int NrVagoane{};
	int NrRute{};
	string* rute{ nullptr };
	int NrPasageri{};
	int* VarstaPasagerilor{ nullptr };

	list<Avion> Avioane;
	Avion AvionTemp;
	char* TipAvion = new char[100];
	double Greutate{};
	float* KmParcursiInUltimaSaptamana{ nullptr };

	list<Masina> Masini;
	Masina MasinaTemp;
	int NrAccidente;
	int* AnAccidente{ nullptr };
	float AsigurariPlatite{};
	bool AreLocDeCopii{ false };

	ofstream ScriereSofer;
	ofstream ScriereMijlocDeTransport;
	ofstream ScriereMasina;
	ofstream ScriereAvion;
	ofstream ScriereTren;

	list<Sofer> SoferiOut;
	list<Mijloc_De_Transport> MijloaceDeTransportOut;
	list<Masina> MasiniOut;
	list <Tren> TrenuriOut;
	list <Avion> AvioaneOut;

	int ore_de_munca_pe_zile_A[]{ 5, 6, 6, 8 };
	string marca_masini_conduse_A[]{ "Caruta", "Logan", "Dacia" };
	Sofer Alex("Alex", 3, 4, ore_de_munca_pe_zile_A, 3, marca_masini_conduse_A);

	int ore_de_munca_pe_zile_B[]{ 8, 8, 8, 4 };
	string marca_masini_conduse_B[]{ "Urus", "Lamborghini", "Golf" };
	Sofer Gabi("Gabi", 3, 4, ore_de_munca_pe_zile_B, 3, marca_masini_conduse_B);

	double istoric_consum_A[]{ 120.5, 220.6, 333.10 };
	Sofer soferi_A[]{ Alex };
	Mijloc_De_Transport Dacia("Dacia", 15, 10000, 3, istoric_consum_A, 1, soferi_A);

	double istorin_consum_B[]{ 180.9, 190.6, 330.9, 450 };
	Sofer soferi_B[]{ Gabi };
	Mijloc_De_Transport VolksWagen("VolksWagen", 30, 15000, 4, istorin_consum_B, 1, soferi_B);

	MijloaceDeTransportOut.push_back(Dacia);
	MijloaceDeTransportOut.push_back(VolksWagen);

	SoferiOut.push_back(Alex);
	SoferiOut.push_back(Gabi);
	
	double dim{};

	list<Sofer>::iterator it1 = SoferiOut.begin();
	list<Mijloc_De_Transport>::iterator it2 = MijloaceDeTransportOut.begin();


	vector<Mijloc_De_Transport> ListaMijloaceDeTransport;
	int selectieMijlocDeTransportDinLista_A{};
	int selectieMijlocDeTransportDinLista_B{};
	int miIndex{};
	Mijloc_De_Transport miNou;

	vector<Masina> ListaMasini;
	int selectieMasina_A{};
	int selectieMasina_B{};
	int mIndex{};
	Masina mNou;

	vector<Avion> ListaAvioane;
	Avion aNou;

	vector<Tren> ListaTrenuri;
	Tren tNou;

	do
	{
		cout << "GESTIUNEA MIJLOACELOR DE TRANSPOT" << endl
			<< "===========================================" << endl
			<< "1. Sofer" << endl
			<< "2. Mijloc de transport" << endl
			<< "3. Masina" << endl
			<< "4. Avion" << endl
			<< "5. Tren" << endl
			<< "0. Exit" << endl
			<< "===========================================" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:
			do
			{
				cout << "SOFER" << endl
					<< "===========================================" << endl
					<< "1. Citire obiect din fisier txt" << endl
					<< "2. Scriere obiect in fisier bin" << endl
					<< "0. Revenire la meniul anterior" << endl
					<< "===========================================" << endl;

				cin >> SoferSelection;

				switch (SoferSelection)
				{
				case 1:
					CitireSofer.open("SoferInput.txt");

					if (CitireSofer.is_open())
					{
						while (!CitireSofer.eof())
						{
							CitireSofer >> nume >> AniVechime >> NrzileMunca;
							ore_de_munca_pe_zile = new int[NrzileMunca];
							for (int i = 0; i < NrzileMunca; ++i)
							{
								CitireSofer >> ore_de_munca_pe_zile[i];
							}

							CitireSofer >> NrMasiniConduse;
							marca_masini_conduse = new string[NrMasiniConduse];
							for (int i = 0; i < NrMasiniConduse; ++i)
							{
								CitireSofer >> marca_masini_conduse[i];
							}

							SoferTemp.set_nume(nume);
							SoferTemp.set_ani_vechime(AniVechime);
							SoferTemp.set_nr_masini_conduse(NrMasiniConduse);
							SoferTemp.set_marca_masini_conduse(marca_masini_conduse);
							SoferTemp.set_nr_zile_munca(NrzileMunca);
							SoferTemp.set_ore_munca(ore_de_munca_pe_zile);

							Soferi.push_back(SoferTemp);

							for (auto& sofer : Soferi)
							{
								cout << sofer;
							}
						}
					}
					else
					{
						cout << "Fisierul nu a putut fi deschis";
					}

					CitireSofer.close();

					break;
				case 2:
					dim = SoferiOut.size();
					ScriereSofer.open("SoferOutput.bin", ios::binary);
					if (ScriereSofer.is_open())
					{
						ScriereSofer.write((char*)&dim, sizeof(dim));
						for (auto& sofer : SoferiOut)
						{
							dim = strlen(sofer.get_nume()) + 1;
							ScriereSofer.write((char*)&dim, sizeof(dim));

							ScriereSofer.write(sofer.get_nume(), dim);

							dim = sofer.get_ani_vechime();
							ScriereSofer.write((char*)&dim, sizeof(dim));

							dim = sofer.get_nr_zile_munca();
							ScriereSofer.write((char*)&dim, sizeof(dim));
							for (int i{}; i < sofer.get_nr_zile_munca(); ++i)
							{
								ScriereSofer.write((char*)&sofer.get_ore_munca_adresa()[i], sizeof(int));
							}

							dim = sofer.get_nr_masini_conduse();
							ScriereSofer.write((char*)&dim, sizeof(dim));
							for (int i{}; i < sofer.get_nr_masini_conduse(); ++i)
							{
								dim = sofer.get_marca_masini_conduse_adresa()[i].size() + 1;
								ScriereSofer.write((char*)&dim, sizeof(dim));
								ScriereSofer.write((char*)(sofer.get_marca_masini_conduse_adresa()[i].c_str()), dim);
							}
						}

						ScriereSofer.close();
					}
					else
					{
						cout << "nu";
					}

					break;
				case 0:
					cout << "\nRevenire la meniul anterior...\n";
					break;
				default:
					break;
				}
			} while (SoferSelection != 0);

			break;
		case 2:
			do
			{
				cout << "MIJLOC DE TRANSPORT" << endl
					<< "===========================================" << endl
					<< "1. Citire obiect din fisier txt" << endl
					<< "2. Scriere obiect in fisier bin" << endl
					<< "3. Afisare vector curent de obiecte" << endl
					<< "4. Adunarea a 2 obiecte" << endl
					<< "5. Op index[]" << endl
					<< "6. Op --" << endl
					<< "7. Op cast (int)" << endl
					<< "8. Op ==" << endl
					<< "9. Op <" << endl
					<< "10. Printare prin interfata" << endl
					<< "11. Pune muzica" << endl
					<< "12. Foloseste GPS" << endl
					<< "13. Adaugare element in vector" << endl
					<< "0. Revenire in meniul anterior" << endl
					<< "===========================================" << endl;

				cin >> MijlocDeTransportSelection;

				switch (MijlocDeTransportSelection)
				{
				case 1:
					CitireMijlocDeTransport.open("MijlocDeTransportInput.txt");

					if (CitireMijlocDeTransport.is_open())
					{
						while (!CitireMijlocDeTransport.eof())
						{
							CitireMijlocDeTransport >> marca >> CapacitateRezervor >> KmInscrisi >> NrZileFunctionare;
							IstoricConsum = new double[NrZileFunctionare];
							for (int i = 0; i < NrZileFunctionare; ++i)
							{
								CitireMijlocDeTransport >> IstoricConsum[i];
							}

							CitireMijlocDeTransport >> NrSoferi;
							marca_masini_conduse = new string[NrSoferi];
							for (int i = 0; i < NrSoferi; ++i)
							{
								CitireMijlocDeTransport >> soferi[i];
							}

							MijlocDeTransportTemp.set_marca(marca);
							MijlocDeTransportTemp.set_capacitate_rezervor(CapacitateRezervor);
							MijlocDeTransportTemp.set_km_inscrisi(KmInscrisi);
							MijlocDeTransportTemp.set_nr_zile_functionare(NrZileFunctionare);
							MijlocDeTransportTemp.set_istoric_consum(IstoricConsum);
							MijlocDeTransportTemp.set_nr_soferi(NrSoferi);
							MijlocDeTransportTemp.set_sofer(soferi);

							MijloaceDeTransport.push_back(MijlocDeTransportTemp);

							for (auto& mijloc_de_transport : MijloaceDeTransport)
							{
								cout << mijloc_de_transport;
							}
						}

						CitireMijlocDeTransport.close();
					}
					else
					{
						cout << "Fisierul nu a putut fi deschis";
					}

					break;

					break;
				case 2:
					ScriereMijlocDeTransport.open("MijlocDeTransportOutput.bin", ios::binary);
					if (ScriereMijlocDeTransport.is_open())
					{
						dim = MijloaceDeTransportOut.size();
						ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

						for (auto& transport : MijloaceDeTransportOut)
						{
							dim = strlen(transport.get_marca()) + 1;
							ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

							ScriereMijlocDeTransport.write(transport.get_marca(), dim);

							dim = transport.get_capacitate_rezervor();
							ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

							dim = transport.get_km_inscrisi();
							ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

							dim = transport.get_nr_zile_funtionare();
							ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

							for (int i{}; i < transport.get_nr_zile_funtionare(); ++i)
							{
								ScriereMijlocDeTransport.write((char*)&transport.get_istoric_consum_adresa()[i], sizeof(double));
							}

							dim = transport.get_nr_soferi();
							ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));

							for (int i{}; i < transport.get_nr_soferi(); ++i)
							{
								dim = sizeof(transport.get_sofer_adresa()[i]);
								ScriereMijlocDeTransport.write((char*)&dim, sizeof(dim));
							}																			
						}

						ScriereMijlocDeTransport.close();
					}
					break;
				case 3:
					for (auto& element : ListaMijloaceDeTransport)
					{
						cout << element;
					}
					break;
				case 4:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						cout << "Rezultatul este: " << ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A] + ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_B];
					}

					break;
				case 5:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << "Alegeti indexul la care vreti sa cautati:";
						cin >> miIndex;

						cout << (ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A])[miIndex];
					}

					break;
				case 6:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << --ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A];
					}
					break;
				case 7:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << (int)(ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A]);
					}
					break;

				case 8:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A] == ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Cele 2 obiecte sunt elgale" << endl;
						}
						else
						{
							cout << "Cele 2 obiecte sunt diferite" << endl;
						}
					}

					break;

				case 9:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A] < ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Obiectul " << ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A].get_marca() << " este mai mare" << endl;
						}
						else
						{
							cout << "Obiectul " << ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_B].get_marca() << " este mai mare" << endl;
						}
					}

					break;
				case 10:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A].print(cout);
					}
					break;
				case 11:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A].PuneMuzica();
					}
					break;

				case 12:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMijloaceDeTransport.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMijloaceDeTransport.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMijloaceDeTransport[selectieMijlocDeTransportDinLista_A].GPS();
					}
					break;
				case 13:
					cout << "Introduceti noul obiect: ";
					cin >> miNou;
					ListaMijloaceDeTransport.push_back(miNou);
				case 0:
					break;
				default:
					break;
				}
			} while (MijlocDeTransportSelection != 0);

			break;

		case 3:
			do
			{
				cout << "MASINA" << endl
					<< "===========================================" << endl
					<< "1. Citire obiect din fisier txt" << endl
					<< "2. Scriere obiect in fisier bin" << endl
					<< "3. Afisare vector curent de obiecte" << endl
					<< "4. Adunarea a 2 obiecte" << endl
					<< "5. Op index[]" << endl
					<< "6. Op --" << endl
					<< "7. Op cast (int)" << endl
					<< "8. Op ==" << endl
					<< "9. Op <" << endl
					<< "10. Printare prin interfata" << endl
					<< "11. Pune muzica" << endl
					<< "12. Foloseste GPS" << endl
					<< "13. Adaugare element in vector" << endl
					<< "0. Revenire in meniul anterior" << endl
					<< "===========================================" << endl;

				cin >> MasinaSelection;

				switch (MasinaSelection)
				{
				case 1:
					CitireMasina.open("MasinaInput.txt");

					if (CitireMasina.is_open())
					{
						while (!CitireMasina.eof())
						{
							CitireMasina >> NrAccidente;
							AnAccidente = new int[NrAccidente];
							for (int i = 0; i < NrAccidente; ++i)
							{
								CitireMasina >> AnAccidente[i];
							}
							CitireMasina >> AsigurariPlatite >> AreLocDeCopii;

							MasinaTemp.set_nr_accidente(NrAccidente);
							MasinaTemp.set_an_accident(AnAccidente);
							MasinaTemp.set_asigurari_platite_in_ultimul_an(AsigurariPlatite);
							MasinaTemp.set_loc_de_copii(AreLocDeCopii);

							Masini.push_back(MasinaTemp);

							for (auto& masina : Masini)
							{
								cout << masina;
							}
						}

						CitireMasina.close();
					}
					else
					{
						cout << "Fisierul nu a putut fi deschis";
					}
					break;
				case 2:

					break;
				case 3:
					for (auto& element : ListaMasini)
					{
						cout << element;
					}
					break;
				case 4:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						cout << "Rezultatul este: " << ListaMasini[selectieMijlocDeTransportDinLista_A] + ListaMasini[selectieMijlocDeTransportDinLista_B];
					}

					break;
				case 5:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << "Alegeti indexul la care vreti sa cautati:";
						cin >> miIndex;

						cout << (ListaMasini[selectieMijlocDeTransportDinLista_A])[miIndex];
					}

					break;
				case 6:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << --ListaMasini[selectieMijlocDeTransportDinLista_A];
					}
					break;
				case 7:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << (int)(ListaMasini[selectieMijlocDeTransportDinLista_A]);
					}
					break;

				case 8:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaMasini[selectieMijlocDeTransportDinLista_A] == ListaMasini[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Cele 2 obiecte sunt elgale" << endl;
						}
						else
						{
							cout << "Cele 2 obiecte sunt diferite" << endl;
						}
					}

					break;

				case 9:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaMasini[selectieMijlocDeTransportDinLista_A] < ListaMasini[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Obiectul " << ListaMasini[selectieMijlocDeTransportDinLista_A].get_marca() << " este mai mare" << endl;
						}
						else
						{
							cout << "Obiectul " << ListaMasini[selectieMijlocDeTransportDinLista_B].get_marca() << " este mai mare" << endl;
						}
					}

					break;
				case 10:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMijloaceDeTransport[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMasini[selectieMijlocDeTransportDinLista_A].print(cout);
					}
					break;
				case 11:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMasini[selectieMijlocDeTransportDinLista_A].PuneMuzica();
					}
					break;

				case 12:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaMasini.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaMasini.size(); ++i)
						{
							cout << i << ". " << ListaMasini[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaMasini[selectieMijlocDeTransportDinLista_A].GPS();
					}
					break;
				case 13:
					cout << "Introduceti noul obiect: ";
					cin >> mNou;
					ListaMasini.push_back(mNou);
				case 0:
					break;
				default:
					break;
				}
			} while (MasinaSelection != 0);

			break;

		case 4:
			do
			{
				cout << "AVION" << endl
					<< "===========================================" << endl
					<< "1. Citire obiect din fisier txt" << endl
					<< "2. Scriere obiect in fisier bin" << endl
					<< "3. Afisare vector curent de obiecte" << endl
					<< "4. Adunarea a 2 obiecte" << endl
					<< "5. Op index[]" << endl
					<< "6. Op --" << endl
					<< "7. Op cast (int)" << endl
					<< "8. Op ==" << endl
					<< "9. Op <" << endl
					<< "10. Printare prin interfata" << endl
					<< "11. Pune muzica" << endl
					<< "12. Foloseste GPS" << endl
					<< "13. Adaugare element in vector" << endl
					<< "0. Revenire in meniul anterior" << endl
					<< "===========================================" << endl;

				cin >> AvionSelection;

				switch (AvionSelection)
				{
				case 1:
					CitireAvion.open("AvionInput.txt");

					if (CitireAvion.is_open())
					{
						while (!CitireAvion.eof())
						{
							CitireAvion >> TipAvion >> Greutate;
							KmParcursiInUltimaSaptamana = new float[7];
							for (int i = 0; i < 7; ++i)
							{
								CitireAvion >> KmParcursiInUltimaSaptamana[i];
							}

							AvionTemp.set_tip_avion(TipAvion);
							AvionTemp.set_greutate(Greutate);
							AvionTemp.set_km_parcursi_ultima_saptamana(KmParcursiInUltimaSaptamana);

							Avioane.push_back(AvionTemp);

							for (auto& avion : Avioane)
							{
								cout << avion;
							}
						}

						CitireAvion.close();
					}
					else
					{
						cout << "Fisierul nu a putut fi deschis";
					}


					break;
				case 2:

					break;
				case 3:
					for (auto& element : ListaAvioane)
					{
						cout << element;
					}
					break;
				case 4:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						cout << "Rezultatul este: " << ListaAvioane[selectieMijlocDeTransportDinLista_A] + ListaAvioane[selectieMijlocDeTransportDinLista_B];
					}

					break;
				case 5:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << "Alegeti indexul la care vreti sa cautati:";
						cin >> miIndex;

						cout << (ListaAvioane[selectieMijlocDeTransportDinLista_A])[miIndex];
					}

					break;
				case 6:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << --ListaAvioane[selectieMijlocDeTransportDinLista_A];
					}
					break;
				case 7:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << (int)(ListaAvioane[selectieMijlocDeTransportDinLista_A]);
					}
					break;

				case 8:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaAvioane[selectieMijlocDeTransportDinLista_A] == ListaAvioane[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Cele 2 obiecte sunt elgale" << endl;
						}
						else
						{
							cout << "Cele 2 obiecte sunt diferite" << endl;
						}
					}

					break;

				case 9:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaAvioane[selectieMijlocDeTransportDinLista_A] < ListaAvioane[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Obiectul " << ListaAvioane[selectieMijlocDeTransportDinLista_A].get_marca() << " este mai mare" << endl;
						}
						else
						{
							cout << "Obiectul " << ListaAvioane[selectieMijlocDeTransportDinLista_B].get_marca() << " este mai mare" << endl;
						}
					}

					break;
				case 10:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaAvioane[selectieMijlocDeTransportDinLista_A].print(cout);
					}
					break;
				case 11:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaAvioane[selectieMijlocDeTransportDinLista_A].PuneMuzica();
					}
					break;

				case 12:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaAvioane.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaAvioane.size(); ++i)
						{
							cout << i << ". " << ListaAvioane[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaAvioane[selectieMijlocDeTransportDinLista_A].GPS();
					}
					break;
				case 13:
					cout << "Introduceti noul obiect: ";
					cin >> aNou;
					ListaAvioane.push_back(aNou);
				case 0:
					break;
				default:
					break;
				}
			} while (AvionSelection != 0);

			break;

		case 5:
			do
			{
				cout << "TREN" << endl
					<< "===========================================" << endl
					<< "1. Citire obiect din fisier txt" << endl
					<< "2. Scriere obiect in fisier bin" << endl
					<< "3. Afisare vector curent de obiecte" << endl
					<< "4. Adunarea a 2 obiecte" << endl
					<< "5. Op index[]" << endl
					<< "6. Op --" << endl
					<< "7. Op cast (int)" << endl
					<< "8. Op ==" << endl
					<< "9. Op <" << endl
					<< "10. Printare prin interfata" << endl
					<< "11. Pune muzica" << endl
					<< "12. Foloseste GPS" << endl
					<< "13. Adaugare element in vector" << endl
					<< "0. Revenire in meniul anterior" << endl
					<< "===========================================" << endl;

				cin >> TrenSelection;

				switch (TrenSelection)
				{
				case 1:
					CitireTren.open("TrenInput.txt");

					if (CitireTren.is_open())
					{
						while (!CitireTren.eof())
						{
							CitireTren >> NrVagoane >> NrRute;
							rute = new string[NrRute];
							for (int i = 0; i < NrRute; ++i)
							{
								CitireTren >> rute[i];
							}

							CitireTren >> NrPasageri;
							VarstaPasagerilor = new int[NrPasageri];
							for (int i = 0; i < NrPasageri; ++i)
							{
								CitireTren >> VarstaPasagerilor[i];
							}

							TrenTemp.set_nr_vagoane(NrVagoane);
							TrenTemp.set_nr_rute(NrRute);
							TrenTemp.set_rute(rute);
							TrenTemp.set_nr_pasageri(NrPasageri);
							TrenTemp.set_varsta_pasagerilor(VarstaPasagerilor);

							Trenuri.push_back(TrenTemp);


							for (auto& tren : Trenuri)
							{
								cout << tren;
							}
						}

						CitireTren.close();
					}
					else
					{
						cout << "Fisierul nu a putut fi deschis";
					}

					break;
				case 2:

					break;
				case 3:
					for (auto& element : ListaTrenuri)
					{
						cout << element;
					}
					break;
				case 4:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						cout << "Rezultatul este: " << ListaTrenuri[selectieMijlocDeTransportDinLista_A] + ListaTrenuri[selectieMijlocDeTransportDinLista_B];
					}

					break;
				case 5:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << "Alegeti indexul la care vreti sa cautati:";
						cin >> miIndex;

						cout << (ListaTrenuri[selectieMijlocDeTransportDinLista_A])[miIndex];
					}

					break;
				case 6:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << --ListaTrenuri[selectieMijlocDeTransportDinLista_A];
					}
					break;
				case 7:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						cout << (int)(ListaTrenuri[selectieMijlocDeTransportDinLista_A]);
					}
					break;

				case 8:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaTrenuri[selectieMijlocDeTransportDinLista_A] == ListaTrenuri[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Cele 2 obiecte sunt elgale" << endl;
						}
						else
						{
							cout << "Cele 2 obiecte sunt diferite" << endl;
						}
					}

					break;

				case 9:
					cout << "Alegeti 2 obiecte din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}
						cin >> selectieMijlocDeTransportDinLista_A >> selectieMijlocDeTransportDinLista_B;
						if (ListaTrenuri[selectieMijlocDeTransportDinLista_A] < ListaTrenuri[selectieMijlocDeTransportDinLista_B])
						{
							cout << "Obiectul " << ListaTrenuri[selectieMijlocDeTransportDinLista_A].get_marca() << " este mai mare" << endl;
						}
						else
						{
							cout << "Obiectul " << ListaTrenuri[selectieMijlocDeTransportDinLista_B].get_marca() << " este mai mare" << endl;
						}
					}

					break;
				case 10:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaTrenuri[selectieMijlocDeTransportDinLista_A].print(cout);
					}
					break;
				case 11:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaTrenuri[selectieMijlocDeTransportDinLista_A].PuneMuzica();
					}
					break;

				case 12:
					cout << "Alegeti 1 obiect din urmatoarea lista: ";
					if (ListaTrenuri.empty())
					{
						cout << "[ Lista Goala ]";
					}
					else
					{
						for (int i = 0; i < ListaTrenuri.size(); ++i)
						{
							cout << i << ". " << ListaTrenuri[i].get_marca() << endl;
						}

						cin >> selectieMijlocDeTransportDinLista_A;
						ListaTrenuri[selectieMijlocDeTransportDinLista_A].GPS();
					}
					break;
				case 13:
					cout << "Introduceti noul obiect: ";
					cin >> tNou;
					ListaTrenuri.push_back(tNou);
				case 0:
					break;
				default:
					break;
				}
			} while (TrenSelection != 0);

			break;

		case 0:
			break;
		default:
			break;
		}

	} while (selection != 0);

}
