#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ExceptieZileMunca
	:public exception
{
public:
	ExceptieZileMunca() noexcept = default;
	virtual ~ExceptieZileMunca() = default;

	virtual const char* what() const noexcept
	{
		return "Nu poate lucara mai mult de 7 zile pe saptamana";
	}
};

class ExceptieMarireSalariu
	:public exception
{
public:
	ExceptieMarireSalariu() noexcept = default;
	virtual ~ExceptieMarireSalariu() = default;

	virtual const char* what() const noexcept
	{
		return "Angajatii cu salariu peste 5000 de lei nu sunt eligibili";
	}
};

class Angajat // clasa cu toti operatorii
{
private:
	char* nume;
	int nr_zile_munca;
	int* ore_de_munca_pe_zi;
	double salariu;
public:
	Angajat()
		:nume(nullptr), nr_zile_munca(0), ore_de_munca_pe_zi(nullptr), salariu(0.0)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");

		this->ore_de_munca_pe_zi = new int;
		*ore_de_munca_pe_zi = 0;
	}

	Angajat(const char* nume,
		int nr_zile_munca,
		int* ore_de_munca_pe_zi,
		double salariu)
		:nume(nullptr), nr_zile_munca(0), ore_de_munca_pe_zi(nullptr), salariu(0.0)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			throw new exception("Nume invalid");
		}

		if (nr_zile_munca > 0)
		{
			if (nr_zile_munca <= 7)
			{
				this->nr_zile_munca = nr_zile_munca;
			}
			else
			{
				throw ExceptieZileMunca{};
			}
		}
		else
		{
			throw new exception("Zile munca negative");
		}

		if (ore_de_munca_pe_zi != nullptr)
		{
			this->ore_de_munca_pe_zi = new int[nr_zile_munca];
			for (int i{}; i < nr_zile_munca; ++i)
			{
				this->ore_de_munca_pe_zi[i] = ore_de_munca_pe_zi[i];
			}
		}

		if (salariu > 0.00)
		{
			this->salariu = salariu;
		}
		else
		{
			throw new exception("Salariu negativ");
		}
	}

	Angajat(int nr_zile_munca,
		int* ore_de_munca_pe_zi,
		double salariu)
		:nume(nullptr), nr_zile_munca(0), ore_de_munca_pe_zi(nullptr), salariu(0.0)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");

		if (nr_zile_munca > 0)
		{
			if (nr_zile_munca <= 7)
			{
				this->nr_zile_munca = nr_zile_munca;
			}
			else
			{
				throw ExceptieZileMunca{};
			}
		}
		else
		{
			throw new exception("Zile munca negative");
		}

		if (ore_de_munca_pe_zi != nullptr)
		{
			this->ore_de_munca_pe_zi = new int[nr_zile_munca];
			for (int i{}; i < nr_zile_munca; ++i)
			{
				this->ore_de_munca_pe_zi[i] = ore_de_munca_pe_zi[i];
			}
		}

		if (salariu > 0.00)
		{
			this->salariu = salariu;
		}
		else
		{
			throw new exception("Salariu negativ");
		}
	}

	Angajat(const Angajat& source)
	{
			this->nume = new char[strlen(source.nume) + 1];
			strcpy(this->nume, source.nume);
	
			this->nr_zile_munca = source.nr_zile_munca;
			
			this->ore_de_munca_pe_zi = new int[source.nr_zile_munca];
			for (int i{}; i < source.nr_zile_munca; ++i)
			{
				this->ore_de_munca_pe_zi[i] = source.ore_de_munca_pe_zi[i];
			}

			this->salariu = source.salariu;
	}

	~Angajat()
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->ore_de_munca_pe_zi != nullptr)
			delete[] this->ore_de_munca_pe_zi;
	}

	Angajat& operator=(const Angajat& source)
	{
		if (this != &source)
		{
			delete[] this->nume;
			this->nume = new char[strlen(source.nume) + 1];
			strcpy(this->nume, source.nume);

			this->nr_zile_munca = source.nr_zile_munca;

			delete[] this->ore_de_munca_pe_zi;
			this->ore_de_munca_pe_zi = new int[source.nr_zile_munca];
			for (int i{}; i < source.nr_zile_munca; ++i)
			{
				this->ore_de_munca_pe_zi[i] = source.ore_de_munca_pe_zi[i];
			}

			this->salariu = source.salariu;
		}

		return *this;
	}

	double operator+(const Angajat& obj)
	{
		return this->salariu + obj.salariu;
	}

	double operator-(const Angajat& obj)
	{
		return this->salariu - obj.salariu;
	}

	Angajat& operator++()
	{
		if (this->salariu < 5000)
		{
			this->salariu += 1000;
		}
		else
		{
			throw ExceptieMarireSalariu{};
		}
		return *this;
	}

	Angajat operator++(int)
	{
		Angajat Temp(*this);
		Angajat::operator++();
		return Temp;
	}

	Angajat& operator--()
	{
		for (int i{}; i < this->nr_zile_munca; ++i)
		{
			this->ore_de_munca_pe_zi[i] -= 1;
		}

		return *this;
	}

	Angajat operator--(int)
	{
		Angajat Temp(*this);
		Angajat::operator--();
		return Temp;
	}

	double operator[](int index)
	{
		if (index >= 0 && index < this->nr_zile_munca)
		{
			return this->ore_de_munca_pe_zi[index];
		}
		else
		{
			throw new exception("Index invalid");
		}
	}

	operator double()
	{
		return this->salariu;
	}

	double operator*(const Angajat& rhs)
	{
		return this->salariu * rhs.salariu;
	}

	double operator/(const Angajat& rhs)
	{
		return this->salariu / rhs.salariu;
	}
	
	bool operator==(const Angajat& rhs)
	{
		return this->salariu == rhs.salariu;
	}

	bool operator<(const Angajat& rhs)
	{
		return this->salariu < rhs.salariu;
	}

	bool operator>(const Angajat& rhs)
	{
		return this->salariu > rhs.salariu;
	}

	friend ostream& operator<<(ostream& os, const Angajat& rhs)
	{
		os << "====================== ANGAJAT ======================" << endl
			<< "Numele angajatului este: " << rhs.nume << endl
			<< "Aceste munceste: " << rhs.nr_zile_munca << " zile pe saptamana" << endl
			<< "Per zi lucratoare, " << rhs.nume << " munceste: [ ";
		for (int i{}; i < rhs.nr_zile_munca; ++i)
		{
			os << rhs.ore_de_munca_pe_zi[i] << " ";
		}

		os << "] ore" << endl
			<< "Salariul acestuia este: " << rhs.salariu << " RON" << endl;
		os << "=====================================================" << endl << endl;

		return os;
	}

	friend istream& operator>>(istream& is, Angajat& rhs)
	{
		char aux[100];
		cout << "Introduceti numele angajatului: ";
		is >> aux;
		delete[] rhs.nume;
		rhs.nume = new char[strlen(aux) + 1];
		strcpy(rhs.nume, aux);

		cout << "Introduceti cate zile munceste pe saptamana: "; is >> rhs.nr_zile_munca;
		cout << "Introduceti cat lucreaza per fiecare zi: " << endl;
		delete[] rhs.ore_de_munca_pe_zi;
		rhs.ore_de_munca_pe_zi = new int[rhs.nr_zile_munca];
		for (int i{}; i < rhs.nr_zile_munca; ++i)
		{
			cout << "\tZiua " << i + 1 << ": "; is >> rhs.ore_de_munca_pe_zi[i];
		}

		cout << "Introduceti salariul acestuia: "; is >> rhs.salariu;
		cout << endl;

		return is;
	}

	friend ofstream& operator<<(ofstream& of, const Angajat& rhs)
	{
		int dim{};
		dim = strlen(rhs.nume) + 1;
		of.write((char*)&dim, sizeof(dim));
		of.write(rhs.nume, dim);

		of.write((char*)&rhs.nr_zile_munca, sizeof(int));

		for (int i{}; i < rhs.nr_zile_munca; ++i)
		{
			of.write((char*)&rhs.ore_de_munca_pe_zi[i], sizeof(int));
		}

		of.write((char*)&rhs.salariu, sizeof(double));

		return of;
	}

	friend ifstream& operator>>(ifstream& ifs, Angajat& rhs)
	{
		int dim{};
		char aux[100];

		ifs.read((char*)&dim, sizeof(dim));
		ifs.read(aux, dim);
		delete[] rhs.nume;
		rhs.nume = new char[strlen(aux) + 1];
		strcpy(rhs.nume, aux);

		ifs.read((char*)&rhs.nr_zile_munca, sizeof(int));

		for (int i{}; i < rhs.nr_zile_munca; ++i)
		{
			ifs.read((char*)&rhs.ore_de_munca_pe_zi[i], sizeof(int));
		}

		ifs.read((char*)&rhs.salariu, sizeof(double));

		return ifs;
	}

	char* get_nume() { return nume; }
	int get_nr_zile_munca() { return nr_zile_munca; }
	int* get_ore_de_munca_pe_zi_adresa() { return ore_de_munca_pe_zi; }
	double get_salariu() { return salariu; }

};

class InterfataCompanie
{
	friend ostream& operator<<(ostream& os, const InterfataCompanie& rhs);
public:
	virtual ~InterfataCompanie() = default;
	virtual void print(ostream& os) const  = 0;
};

ostream& operator<<(ostream& os, const InterfataCompanie& rhs)
{
	rhs.print(os);
	return os;
}

class Companie // clasa abstracta && clasa prin compunere
	:public InterfataCompanie
{
	friend ostream& operator<<(ostream& os, const Companie& rhs);
private:
	int nr_angajati;
	Angajat* angajati;
public:
	Companie()
		:nr_angajati(0), angajati(nullptr) { }

	Companie(int nr_angajati,
		Angajat* angajati)
		:nr_angajati(0), angajati(nullptr)
	{
		if (nr_angajati > 0)
		{
			this->nr_angajati = nr_angajati;
		}
		else
		{
			throw new exception("nr angajati negativ");
		}

		if (angajati != nullptr)
		{
			this->angajati = new Angajat[nr_angajati];
			for (int i{}; i < nr_angajati; ++i)
			{
				this->angajati[i] = angajati[i];
			}
		}
		else
		{
			throw new exception("Vector gol");
		}
	}

	~Companie()
	{
		if (this->angajati != nullptr)
			delete[] this->angajati;
	}

	Companie(const Companie& source)
	{
		this->nr_angajati = source.nr_angajati;

		this->angajati = new Angajat[source.nr_angajati];
		for (int i{}; i < source.nr_angajati; ++i)
		{
			this->angajati[i] = source.angajati[i];
		}
	}

	Companie& operator=(const Companie& source)
	{
		if (this != &source)
		{
			this->nr_angajati = source.nr_angajati;

			delete[] this->angajati;
			this->angajati = new Angajat[source.nr_angajati];
			for (int i{}; i < source.nr_angajati; ++i)
			{
				this->angajati[i] = source.angajati[i];
			}
		}

		return *this;
	}

	friend ofstream& operator<<(ofstream& of, const Companie& rhs)
	{
		of.write((char*)&rhs.nr_angajati, sizeof(int));
		for (int i{}; i < rhs.nr_angajati; ++i)
		{
			of << rhs.angajati[i];
		}

		return of;
	}

	friend ifstream& operator>>(ifstream& ifs, Companie& rhs)
	{
		int dim = 0;
		ifs.read((char*)&rhs.nr_angajati, sizeof(int));

		for (int i{}; i < rhs.nr_angajati; ++i)
		{
			ifs >> rhs.angajati[i];
		}

		return ifs;
	}

	virtual void print(ostream& os) const override
	{
		os << "==================== COMPANIE ====================" << endl
			<< "Compania are un numar de: " << this->nr_angajati << " angajati" << endl
			<< "Angajatii sunt: " << endl;
		for (int i{}; i < this->nr_angajati; ++i)
		{
			os << this->angajati[i] << endl;
		}
		os << "===================================================" << endl << endl;
	}

	virtual void InterogareClasa() const = 0;

	int get_nr_angajati() const { return nr_angajati; }
	Angajat* get_angajat_adresa() const  { return angajati; }

	void set_nr_angajati(int nr_angajati)
	{
		if (nr_angajati > 0)
		{
			this->nr_angajati = nr_angajati;
		}
		else
		{
			throw new exception("nr angajati invalid");
		}
	}

	void set_angajati(int nr_angajati, Angajat* angajati)
	{
		if (angajati != nullptr)
		{
			delete[] this->angajati;
			this->angajati = new Angajat[nr_angajati];
			for (int i{}; i < nr_angajati; i++)
			{
				this->angajati[i] = angajati[i];
			}
		}
		else
		{
			throw new exception("pointer gol");
		}
	}
};

ostream& operator<<(ostream& os, const Companie& rhs)
{
	rhs.print(os);
	return os;
}

class Multinationala
	:public Companie
{
	friend ostream& operator<<(ostream& os, const Multinationala& rhs);
private:
	int nr_sucursale;
public:
	Multinationala()
		:Companie(), nr_sucursale(0)
	{

	}

	Multinationala(int nr_angajati,
		Angajat* angajati,
		int nr_sucursale)
		:Companie(nr_angajati, angajati), nr_sucursale(0)
	{
		if (nr_sucursale > 0)
		{
			this->nr_sucursale = nr_sucursale;
		}
		else
		{
			throw new exception("NR sucursale negativ");
		}
	}

	Multinationala(const Multinationala& rhs)
		:Companie(rhs) 
	{
		this->nr_sucursale = rhs.nr_sucursale;
	}

	Multinationala& operator=(const Multinationala& source)
	{
		if (this != &source)
		{
			Companie::operator=(source);
			this->nr_sucursale = source.nr_sucursale;
		}
	}

	friend ofstream& operator<<(ofstream& of, const Multinationala& rhs)
	{
		of << (Companie&)(rhs);
		of.write((char*)&rhs.nr_sucursale, sizeof(int));

		return of;
	}

	friend ifstream& operator>>(ifstream& ifs, Multinationala& rhs)
	{
		int dim{};
		ifs.read((char*)&dim, sizeof(dim));
		rhs.set_nr_angajati(dim);

		ifs >> (Companie&)rhs;
		/*Angajat* angajati_temp = new Angajat[dim];

		for (int i{}; i < rhs.get_nr_angajati(); ++i)
		{
			ifs.read((char*)&angajati_temp[i], dim);
		}
		rhs.set_angajati(dim, angajati_temp);*/

		ifs.read((char*)&rhs.nr_sucursale, sizeof(int));

		return ifs;
	}

	virtual void print(ostream& os) const override
	{

		os << "==================== MULTINATIONALA ====================" << endl
			<< "Compania are un numar de: " << Companie::get_nr_angajati() << " angajati" << endl
			<< "Angajatii sunt: " << endl;
		for (int i{}; i < this->Companie::get_nr_angajati(); ++i)
		{
			os << Companie::get_angajat_adresa()[i] << endl;
		}
		os << "Multinationala are un nr de: " << this->nr_sucursale << " sucursale" << endl;
		os << "=========================================================" << endl << endl;
	}

	virtual void InterogareClasa() const override
	{
		cout << "Obiect din clasa Multinationala" << endl;
	}
};

ostream& operator<<(ostream& os, const Multinationala& rhs)
{
	rhs.print(os);
	return os;
}

class CompanieAeriana
	:public Companie
{
	friend ostream& operator<<(ostream& os, const CompanieAeriana& rhs);
private:
	int nr_avioane;
public:
	CompanieAeriana()
		:Companie(), nr_avioane(0)
	{

	}

	CompanieAeriana(int nr_angajati,
		Angajat* angajati,
		int nr_avioane)
		:Companie(nr_angajati, angajati), nr_avioane(0)
	{
		if (nr_avioane > 0)
		{
			this->nr_avioane = nr_avioane;
		}
		else
		{
			throw new exception("nr avioane invalid");
		}
	}

	virtual void print(ostream& os) const override
	{
		os << "==================== COMPANIE AERIANA ====================" << endl
			<< "Compania are un numar de: " << Companie::get_nr_angajati() << " angajati" << endl
			<< "Angajatii sunt: " << endl;
		for (int i{}; i < this->Companie::get_nr_angajati(); ++i)
		{
			os << Companie::get_angajat_adresa()[i] << endl;
		}
		os << "Compania are un nr de: " << this->nr_avioane << " avioane" << endl;
		os << "==========================================================" << endl << endl;
	}

	virtual void InterogareClasa() const override
	{
		cout << "Clasa CompaniaAeriana" << endl;
	}

};

ostream& operator<<(ostream& os, const CompanieAeriana& rhs)
{
	rhs.print(os);
	return os;
}

class VectorCompanie
{
private:
	vector<Companie*> companii;
public:
	VectorCompanie()
	{

	}

	VectorCompanie(vector<Companie*> companii)
	{
		if (companii.size() > 0)
		{
			for (auto& obj : companii)
			{
				this->companii.push_back(obj);
			}
		}
	}

	friend ostream& operator<<(ostream& os, const VectorCompanie& rhs)
	{
		for (auto& obj : rhs.companii)
		{
			os << *obj;
		}
		return os;
	}


};


int main()
{
	int ore_de_munca[]{ 4,4,5,5 };
	Angajat Ion("Ion", 4, ore_de_munca, 3500);
	cout << Ion;

	Angajat Gol;
	//cin >> Gol;
	cout << Gol;

	Gol = Ion;
	cout << Gol;

	Angajat Copie(Ion);
	cout << Copie;

	int ore_de_munca_2[]{ 8,8,8,7,8 };
	Angajat Andreea("Andreea", 5, ore_de_munca_2, 4500);

	if (Copie == Ion)
	{
		cout << "au acelasi salariu" << endl;
	}
	else
	{
		cout << "au salariu diferit" << endl;
	}

	if (Ion < Andreea)
		cout << "Ion are salariul mai mic" << endl;
	if (Andreea > Ion)
		cout << "Andreea are salariul mai mare" << endl;

	cout << Ion + Andreea;
	cout << Andreea - Ion;
	cout << ++Ion;
	cout << Ion++;
	cout << Ion;
	try
	{
		++Ion;
		
	}
	catch (const ExceptieMarireSalariu& ex)
	{
		cerr << "Ion are deja salariul peste 5000 de lei" << endl;
	} 

	cout << --Ion;
	cout << Ion--;
	cout << Ion;

	cout << Ion * Andreea << endl;
	cout << Ion / Andreea << endl;

	int ore_err[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	try
	{
		Angajat Eroare("Eroare", 9, ore_err, 6600);
	}
	catch (const ExceptieZileMunca& ex)
	{
		cerr << "\nAngajatul nu poate munci mai mult de 7 zile pe saptamana" << endl;
	}

	ofstream fout;
	fout.open("Angajati.bin", ios::binary | ios::out);
	if (fout.is_open())
	{
		fout << Ion;
		fout.close();
	}
	else
	{
		cout << "Fisierul nu a fost gasit!" << endl;
	}

	ifstream fin;
	fin.open("Angajati.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		fin >> Gol;
		fin.close();
	}
	else
	{
		cout << "Fisierul nu a fost gasit!" << endl;
	}

	cout << Gol;

	cout << endl << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ANGAJAT END ANGAJAT END ANGAJAT END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

	
	Companie* c1 = new Multinationala(1, new Angajat[1]{ Ion }, 4);
	ofstream fout2;
	fout2.open("Multinationala.bin", ios::binary | ios::out);
	if (fout2.is_open())
	{
		fout2 << *c1;
		fout2.close();
	}
	else
	{
		cout << "Fisierul nu a fost gasit!" << endl;
	}

	ifstream fin2;
	fin2.open("Multinationala.bin", ios::binary | ios::in);
	if (fin2.is_open())
	{
		fin2 >> *c1;
		fin2.close();
	}
	else
	{
		cout << "Fisierul nu a fost gasit!" << endl;
	}

	cout << *c1;

	c1->InterogareClasa(); //late bindin, polimorfism

	Companie* c2 = new CompanieAeriana(1, new Angajat[1]{ Andreea }, 10);
	c2->InterogareClasa();

	vector<Companie*> vec;
	vec.push_back(c1);
	vec.push_back(c2);

	VectorCompanie companii(vec);
	cout << companii;
}
