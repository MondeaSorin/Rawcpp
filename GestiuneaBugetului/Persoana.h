#pragma once
#include <string>
#include "Interfata_Persoana.h"
#include "CheltuieliCuUtilitatile.h"
#include "CheltuieliAlimentare.h"
#include "CheltuieliCuAsigurari.h"
#include "CheltuieliDiverse.h"
class Persoana : public Interfata_Persoana
{
	friend std::ostream& operator<<(std::ostream& os, const Persoana& rhs);
	friend std::istream& operator>>(std::istream& is, Persoana& rhs);

	static int pPersoaneActive;
protected:
	const std::string pCNP;
	char* pNume;
	int pSurseVenit;
	double* pVenit;
	char pCodPostal[7];
	CheltuieliCuUtilitatile pCheltuieliCuUtilitatile;
	CheltuieliAlimentare pCheltuieliAlimentare;
	CheltuieliCuAsigurari pCheltuieliCuAsigurari;
	CheltuieliDiverse pCheltuieliDiverse;
public:
	Persoana();
	Persoana(int SurseVenit,
		double* Venit);
	Persoana(const std::string CNP,
		const char* Nume,
		int SurseVenit,
		double* Venit,
		const char CodPostal[7],
		CheltuieliCuUtilitatile CheltuieliCuUtilitatile,
		CheltuieliAlimentare CheltuieliAlimentare,
		CheltuieliCuAsigurari CheltuieliCuAsigurari,
		CheltuieliDiverse CheltuieliDiverse);
	~Persoana();
	Persoana(const Persoana& source);
	Persoana& operator=(const Persoana& rhs);
	double operator[](int index);
	double operator+(const Persoana& rhs);
	Persoana& operator--();
	Persoana operator--(int);
	operator int();
	bool operator!();
	bool operator<(const Persoana& rhs);
	bool operator==(const Persoana& rhs);

	void afisare();

	int GetPersoaneActive() const { return pPersoaneActive; }
	std::string GetCNP() const { return pCNP; }
	char* GetNume() const { return pNume; }
	int GetSurseVenit() const { return pSurseVenit; }
	double* GeVenitAdresa() const { return pVenit; }
	const char* GetCodPostal() const { return pCodPostal; }
	CheltuieliCuUtilitatile GetCheltuieliCuUtilitatile() const { return pCheltuieliCuUtilitatile; }
	CheltuieliAlimentare GetCheltuieliAlimentare() const { return pCheltuieliAlimentare; }
	CheltuieliCuAsigurari GetCheltuieliCuAsigurari() const { return pCheltuieliCuAsigurari; }
	CheltuieliDiverse GetCheltuieliDiverse() const { return pCheltuieliDiverse; }

	void SetNume(const char* Nume);
	void SetSurseVenit(int SurseVenit);
	void SetVenit(double* Venit);
	void SeCodPostal(char CodPostal[7]);
	void SetCheltuieliCuUtilitatile(CheltuieliCuUtilitatile CheltuieliCuUtilitatile);
	void SetCheltuieliAlimentare(CheltuieliAlimentare CheltuieliAlimentare);
	void SetCheltuieliCuAsigurari(CheltuieliCuAsigurari CheltuieliCuAsigurari);
	void SetCheltuieliDiverse(CheltuieliDiverse CheltuieliDiverse);

	virtual void print(std::ostream& os) const override;
	virtual void AfisareDateFacturi() override;
	virtual double CheltuieliTotale();
	virtual double InterogareSoldCurent();
	virtual void StergePersoanaDinFisier(int Rand);
};

