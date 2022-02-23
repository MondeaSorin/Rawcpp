#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class CheltuieliCuUtilitatile
{
	friend std::ostream& operator<<(std::ostream& os, const CheltuieliCuUtilitatile& rhs);
	friend std::istream& operator>>(std::istream& is, CheltuieliCuUtilitatile& rhs);
private:
	char* uData;
	int uNrFacturi;
	double* uValoareFactura;
	char uCodClient[25];
public:
	CheltuieliCuUtilitatile();
	CheltuieliCuUtilitatile(int NrFacturi,
		double* ValoareFactura);
	CheltuieliCuUtilitatile(const char* Data,
		int NrFacturi,
		double* ValoareFactura,
		const char CodClient[25]);
	~CheltuieliCuUtilitatile();
	CheltuieliCuUtilitatile(const CheltuieliCuUtilitatile& source);
	CheltuieliCuUtilitatile& operator=(const CheltuieliCuUtilitatile& rhs);
	double operator[](int index);
	double operator+(const CheltuieliCuUtilitatile& rhs);
	CheltuieliCuUtilitatile& operator--();
	CheltuieliCuUtilitatile operator--(int);
	operator int();
	CheltuieliCuUtilitatile operator!();
	bool operator<(const CheltuieliCuUtilitatile& rhs);
	bool operator==(const CheltuieliCuUtilitatile& rhs);

	void afisare();

	char* GetData() const { return uData; }
	int GetNrFacturi() const { return uNrFacturi; }
	double* GetValoareFactura() const { return uValoareFactura; }
	const char* GetCodClient() const { return uCodClient; }

	void SetData(const char* Data);
	void SetNrFacturi(int NrFacturi);
	void SetValoareFactura(double* ValoareFactura);
	void SetCodClient(char CodClient[25]);
};

