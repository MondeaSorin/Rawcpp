#pragma once
#include "Persoana.h"

using namespace std;

class Student :
    public Persoana
{
protected:
    string pAnCurent;
    int pReducereDeStudent;
public:
    Student();
    Student(string CNP,
        char* Nume,
        int SurseVenit,
        double* Venit,
        char CodPostal[7],
        CheltuieliCuUtilitatile CheltuieliCuUtilitatile,
        CheltuieliAlimentare CheltuieliAlimentare,
        CheltuieliCuAsigurari CheltuieliCuAsigurari,
        CheltuieliDiverse CheltuieliDiverse,
        string AnCurent,
        int ReducereStudent);
    ~Student();
    Student(const Student& source);
    Student& operator=(const Student& source);

    virtual void print(std::ostream& os) const override;
    virtual void AfisareDateFacturi() override;
    virtual double CheltuieliTotale() override;
    virtual double InterogareSoldCurent() override;
    virtual void StergePersoanaDinFisier(int Rand);
};

