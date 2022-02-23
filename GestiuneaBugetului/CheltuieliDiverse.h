#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class CheltuieliDiverse
{
	friend std::ostream& operator<<(std::ostream& os, const CheltuieliDiverse& rhs);
	friend std::istream& operator>>(std::istream& is, CheltuieliDiverse& rhs);
private:
	char* dData;
	int dNrCheltuiliEfectuate;
	double* dValoareCheltuiala;
	char dDenumireProdus[50];
public:
	CheltuieliDiverse();
	CheltuieliDiverse(int NrCheltuiliEfectuate,
		double* ValoareCheltuiala);
	CheltuieliDiverse(const char* Data,
		int NrCheltuiliEfectuate,
		double* ValoareCheltuiala,
		const char DenumireProdus[50]);
	~CheltuieliDiverse();
	CheltuieliDiverse(const CheltuieliDiverse& source);
	CheltuieliDiverse& operator=(const CheltuieliDiverse& rhs);
	double operator[](int index);
	double operator+(const CheltuieliDiverse& rhs);
	CheltuieliDiverse& operator--();
	CheltuieliDiverse operator--(int);
	operator int();
	CheltuieliDiverse operator!();
	bool operator<(const CheltuieliDiverse& rhs);
	bool operator==(const CheltuieliDiverse& rhs);

	void afisare();

	char* GetData() const { return dData; }
	int GetNrCheltuiliEfectuate() const { return dNrCheltuiliEfectuate; }
	double* GetValoareCheltuiala() const { return dValoareCheltuiala; }
	const char* GetDenumireProdus() const { return dDenumireProdus; }

	void SetData(const char* Data);
	void SetNrCheltuiliEfectuate(int NrCheltuiliEfectuate);
	void SetValoareCheltuiala(double* ValoareCheltuiala);
	void SetDenumireProdus(char DenumireProdus[50]);
};

