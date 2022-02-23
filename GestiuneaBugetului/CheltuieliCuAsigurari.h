#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class CheltuieliCuAsigurari
{
	friend std::ostream& operator<<(std::ostream& os, const CheltuieliCuAsigurari& rhs);
	friend std::istream& operator>>(std::istream& is, CheltuieliCuAsigurari& rhs);
private:
	char* asData;
	int asNrMasini;
	double* asValoareAsigurare;
	char asValabilitate[20];
public:
	CheltuieliCuAsigurari();
	CheltuieliCuAsigurari(int NrMasini,
		double* ValoareAsigurare);
	CheltuieliCuAsigurari(const char* Data,
		int NrMasini,
		double* ValoareAsigurare,
		const char Valabilitate[20]);
	~CheltuieliCuAsigurari();
	CheltuieliCuAsigurari(const CheltuieliCuAsigurari& source);
	CheltuieliCuAsigurari& operator=(const CheltuieliCuAsigurari& rhs);
	double operator[](int index);
	double operator+(const CheltuieliCuAsigurari& rhs);
	CheltuieliCuAsigurari& operator--();
	CheltuieliCuAsigurari operator--(int);
	operator int();
	CheltuieliCuAsigurari operator!();
	bool operator<(const CheltuieliCuAsigurari& rhs);
	bool operator==(const CheltuieliCuAsigurari& rhs);

	void afisare();

	char* GetData() const { return asData; }
	int GetNrMasini() const { return asNrMasini; }
	double* GetValoareAsigurare() const { return asValoareAsigurare; }
	const char* GetValabilitate() const { return asValabilitate; }

	void SetData(const char* Data);
	void SetNrMasini(int NrMasini);
	void SetValoareAsigurare(double* ValoareAsigurare);
	void SetValabilitate(char Valabilitate[20]);
};

