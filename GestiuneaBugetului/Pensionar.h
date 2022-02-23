#pragma once
#include "Persoana.h"
using namespace std;
class Pensionar :
    public Persoana
{
protected:
    int pReducereDePensionar;
public:
    Pensionar();
    Pensionar(string CNP,
        char* Nume,
        int SurseVenit,
        double* Venit,
        char CodPostal[7],
        CheltuieliCuUtilitatile CheltuieliCuUtilitatile,
        CheltuieliAlimentare CheltuieliAlimentare,
        CheltuieliCuAsigurari CheltuieliCuAsigurari,
        CheltuieliDiverse CheltuieliDiverse,
        int ReducereDePensionar);
    ~Pensionar();
    Pensionar(const Pensionar& source);
    Pensionar& operator=(const Pensionar& source);

    virtual void print(std::ostream& os) const override;
    virtual void AfisareDateFacturi() override;
    virtual double CheltuieliTotale() override;
    virtual double InterogareSoldCurent() override;
    virtual void StergePersoanaDinFisier(int Rand);
};

