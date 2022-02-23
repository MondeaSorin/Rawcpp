#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class CheltuieliAlimentare
{
	friend std::ostream& operator<<(std::ostream& os, const CheltuieliAlimentare& rhs);
	friend std::istream& operator>>(std::istream& is, CheltuieliAlimentare& rhs);
private:
	char* aData;
	int aNrAlimente;
	double* aPretAliment;
	char aNrBonFiscal[10];
public:
	CheltuieliAlimentare();
	CheltuieliAlimentare(const char* Data,
		int NrAlimente,
		double* PretAliment,
		const char NrBonFiscal[10]);
	CheltuieliAlimentare(int NrAlimente,
		double* PretAliment);
	~CheltuieliAlimentare();
	CheltuieliAlimentare(const CheltuieliAlimentare& source);
	CheltuieliAlimentare& operator=(const CheltuieliAlimentare& rhs);
	double operator[](int index);
	double operator+(const CheltuieliAlimentare& rhs);
	CheltuieliAlimentare& operator--();
	CheltuieliAlimentare operator--(int);
	operator int();
	//CheltuieliAlimentare operator!();
	bool operator==(const CheltuieliAlimentare& rhs);
	bool operator<(const CheltuieliAlimentare& rhs);

	void afisare();

	char* GetData() const { return aData; }
	int GetNrAlimente() const { return aNrAlimente; }
	double* GetPretAliment() const { return aPretAliment; }
	const char* GetNrBonFiscal() const { return aNrBonFiscal; }

	void SetData(const char* Data);
	void SetNrAlimente(int NrAlimente);
	void SetPretAliment(double* PretAlimen);
	void SetNrBonFiscal(char NrBonFiscal[10]);
};

