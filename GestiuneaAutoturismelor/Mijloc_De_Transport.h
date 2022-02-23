#pragma once
#include <string>
#include "Interfata_Mijloc_De_Transport.h"
#include "Sofer.h"
using namespace std;
class Mijloc_De_Transport: public Interfata_Mijloc_De_Transport
{
	friend ostream& operator<<(ostream& os, const Mijloc_De_Transport& rhs);
	friend istream& operator>>(istream& is, Mijloc_De_Transport& rhs);

	static int mijloace_de_transpport_inregistrate;
	static  constexpr const char* cod_unic_de_indentificare = "MTX000";
protected:
	char* marca;
	double capacitate_rezervor;
	double km_inscrisi;
	int nr_zile_functionare;
	double* istoric_consum;
	int nr_soferi;
	Sofer* sofer;
public:
	Mijloc_De_Transport()
		:marca{ nullptr }, capacitate_rezervor{ 0.0 }, km_inscrisi{ 0.0 }, nr_zile_functionare{}, istoric_consum{ nullptr }, nr_soferi{}, sofer{ nullptr }
	{
		this->marca = new char[strlen("Fara marca") + 1];
		strcpy(this->marca, "Fara marca");

		mijloace_de_transpport_inregistrate++;
	}

	Mijloc_De_Transport(const char* marca, double capacitate_rezervor, double km_inscrisi, int nr_zile_functionare, double* istoric_consum, int nr_soferi, Sofer* sofer)
		:marca{ nullptr }, capacitate_rezervor{ 0.0 }, km_inscrisi{ 0.0 }, nr_zile_functionare{}, istoric_consum{ nullptr }, nr_soferi{}, sofer{ nullptr }
	{
		if (marca != nullptr)
		{
			this->marca = new char[strlen(marca) + 1];
			strcpy(this->marca, marca);
		}
		else
		{
			this->marca = new char[strlen("Fara marca") + 1];
			strcpy(this->marca, "Fara marca");
		}

		if (capacitate_rezervor > 0)
		{
			this->capacitate_rezervor = capacitate_rezervor;
		}
		else
		{
			throw new exception("Rezervorul nu poate avea capacitate negativa");
		}

		if (km_inscrisi >= 0)
		{
			this->km_inscrisi = km_inscrisi;
		}
		else
		{
			throw new exception("Autonomia nu poate fi inregistrata cu valori negative");
		}

		if (nr_zile_functionare > 0)
		{
			this->nr_zile_functionare = nr_zile_functionare;
		}
		else
		{
			throw new exception("Masina trebuie sa functioneze de cel putin o zi");
		}

		if (istoric_consum != nullptr)
		{
			this->istoric_consum = new double[nr_zile_functionare];
			for (int i{}; i < nr_zile_functionare; ++i)
			{
				this->istoric_consum[i] = istoric_consum[i];
			}
		}
		else
		{
			throw new exception("Vectorul istoricului este gol");
		}

		if (nr_soferi > 0 && nr_soferi <= 2)
		{
			this->nr_soferi = nr_soferi;
		}
		else
		{
			throw new exception("Nr soferi nu poate fi negativ");
		}

		if (sofer != nullptr)
		{
			this->sofer = new Sofer[nr_soferi];
			for (int i{}; i < nr_soferi; ++i)
			{
				this->sofer[i] = sofer[i];
			}
		}

		mijloace_de_transpport_inregistrate++;
	}

	~Mijloc_De_Transport()
	{
		if (this->marca != nullptr)
			delete[] this->marca;
		if (this->istoric_consum != nullptr)
			delete[] this->istoric_consum;
		if (this->sofer != nullptr)
			delete[] this->sofer;
	}

	Mijloc_De_Transport(const Mijloc_De_Transport& source)
	{
		this->marca = new char[strlen(source.marca) + 1];
		strcpy(this->marca, source.marca);

		this->capacitate_rezervor = source.capacitate_rezervor;

		this->km_inscrisi = source.km_inscrisi;

		this->nr_zile_functionare = source.nr_zile_functionare;

		this->istoric_consum = new double[source.nr_zile_functionare];
		for (int i{}; i < source.nr_zile_functionare; ++i)
		{
			this->istoric_consum[i] = source.istoric_consum[i];
		}

		this->nr_soferi = source.nr_soferi;

		this->sofer = new Sofer[source.nr_soferi];
		for (int i{}; i < source.nr_soferi; ++i)
		{
			this->sofer[i] = source.sofer[i];
		}
	}

	Mijloc_De_Transport& operator=(const Mijloc_De_Transport& source)
	{
		if (this != &source)
		{
			if (this->marca != nullptr)
				delete[] this->marca;
			this->marca = new char[strlen(source.marca) + 1];
			strcpy(this->marca, source.marca);

			this->capacitate_rezervor = source.capacitate_rezervor;

			this->km_inscrisi = source.km_inscrisi;

			this->nr_zile_functionare = source.nr_zile_functionare;

			if (this->istoric_consum != nullptr)
				delete[] this->istoric_consum;
			this->istoric_consum = new double[source.nr_zile_functionare];
			for (int i{}; i < source.nr_zile_functionare; ++i)
			{
				this->istoric_consum[i] = source.istoric_consum[i];
			}

			this->nr_soferi = source.nr_soferi;

			if (this->sofer != nullptr)
				delete[] this->sofer;
			this->sofer = new Sofer[source.nr_soferi];
			for (int i{}; i < source.nr_soferi; ++i)
			{
				this->sofer[i] = source.sofer[i];
			}
		}

		return *this;
	}

	double& operator[](int index)
	{
		if (index >= 0 && index < this->nr_zile_functionare)
		{
			return this->istoric_consum[index];
		}
		else
		{
			throw new exception("Indexul nu a putut fi gasit");
		}
	}

	Mijloc_De_Transport operator+(const Mijloc_De_Transport& rhs) const
	{
		char* buff = new char[strlen(this->marca) + strlen(rhs.marca) + strlen("-") + 1];
		strcpy(buff, this->marca);
		strcat(buff, "-");
		strcat(buff, rhs.marca);

		double buff_capacitate_rezervor = this->capacitate_rezervor + rhs.capacitate_rezervor;

		double buff_km_inscrisi = this->km_inscrisi + rhs.km_inscrisi;

		int buff_nr_zile_functionare = this->nr_zile_functionare + rhs.nr_zile_functionare;

		double* buff_istoric_consum = new double[buff_nr_zile_functionare];
		for (int i{}; i < buff_nr_zile_functionare; ++i)
		{
			buff_istoric_consum[i] = this->istoric_consum[i] + rhs.istoric_consum[i];
		}

		int buff_nr_soferi = max(this->nr_soferi, rhs.nr_soferi);
		Sofer* buff_soferi = new Sofer[buff_nr_soferi];
		for (int i{}; i < buff_nr_soferi; ++i)
		{
			if (this->nr_soferi >= rhs.nr_soferi)
			{
				buff_soferi[i] = this->sofer[i];
			}
			else
			{
				buff_soferi[i] = rhs.sofer[i];
			}
		}

		Mijloc_De_Transport Temp(buff, buff_capacitate_rezervor, buff_km_inscrisi, buff_nr_zile_functionare, buff_istoric_consum, buff_nr_soferi, buff_soferi);
		delete[] buff;
		delete[] buff_istoric_consum;
		delete[] buff_soferi;
		return Temp;
	}

	Mijloc_De_Transport& operator--()
	{
		int buff_size = this->nr_zile_functionare - 1;
		double* buff = new double[buff_size];
		for (int i{}; i < buff_size; ++i)
		{
			buff[i] = this->istoric_consum[i];
		}
		delete[] this->istoric_consum;
		this->nr_zile_functionare = buff_size;
		this->istoric_consum = buff;
		return *this;
	}

	Mijloc_De_Transport operator--(int)
	{
		Mijloc_De_Transport Temp(*this);
		operator--();
		return Temp;
	}

	operator double()
	{
		return this->km_inscrisi;
	}

	operator char* ()
	{
		return *this;
	}

	Mijloc_De_Transport operator!()
	{
		char* buff = new char[strlen(this->marca) + 1];
		strcpy(buff, this->marca);
		for (int i{}; i < strlen(buff); ++i)
		{
			buff[i] = toupper(buff[i]);
		}

		Mijloc_De_Transport Temp(buff, this->capacitate_rezervor, this->km_inscrisi, this->nr_zile_functionare, this->istoric_consum, this->nr_soferi, this->sofer);
		delete[] buff;
		return Temp;
	}

	bool operator<(const Mijloc_De_Transport& rhs)
	{
		return this->km_inscrisi < rhs.km_inscrisi;
	}

	bool operator==(const Mijloc_De_Transport& rhs)
	{
		if (this->capacitate_rezervor != rhs.capacitate_rezervor)
			return false;
		if (this->nr_zile_functionare != rhs.nr_zile_functionare)
			return false;
		if (this->km_inscrisi != rhs.km_inscrisi)
			return false;
		if (this->nr_soferi != rhs.nr_soferi)
			return false;

		return true;
	}

	char* get_marca() const { return marca; }
	double get_capacitate_rezervor() const { return capacitate_rezervor; }
	double get_km_inscrisi() const { return km_inscrisi; }
	int get_nr_zile_funtionare() const { return nr_zile_functionare; }
	double* get_istoric_consum_adresa() const { return istoric_consum; }
	int get_nr_soferi() const { return nr_soferi; }
	Sofer* get_sofer_adresa() const { return sofer; }

	void set_marca(const char* nume)
	{
		if (nume != nullptr)
		{
			if (this->marca != nullptr)
				delete[] this->marca;
			this->marca = new char[strlen(nume) + 1];
			strcpy(this->marca, nume);
		}
		else
		{
			throw new exception("Marca introdua este goala");
		}
	}
	void set_capacitate_rezervor(double capacitate_rezervor)
	{
		if (capacitate_rezervor > 0)
		{
			this->capacitate_rezervor = capacitate_rezervor;
		}
		else
		{
			throw new exception("Capacitatea nu poate fi negativa");
		}
	}
	void set_km_inscrisi(double km_inscrisi)
	{
		if (km_inscrisi > 0)
		{
			this->capacitate_rezervor = km_inscrisi;
		}
		else
		{
			throw new exception("Km inscrisi nu poate fi negativi");
		}
	}
	void set_nr_zile_functionare(int nr_zile_functionare)
	{
		if (nr_zile_functionare > 0)
		{
			this->nr_zile_functionare = nr_zile_functionare;
		}
		else
		{
			throw new exception("Nu poate functiona 0 zile!");
		}
	}
	void set_istoric_consum(double* istoric_consum)
	{
		if (istoric_consum != nullptr)
		{
			if (this->istoric_consum != nullptr)
				delete[] this->istoric_consum;
			this->istoric_consum = new double[nr_zile_functionare];
			for (int i = 0; i < nr_zile_functionare; i++)
			{
				this->istoric_consum[i] = istoric_consum[i];
			}
		}
	}
	void set_nr_soferi(int nr_soferi)
	{
		if (nr_soferi > 0)
		{
			this->nr_soferi = nr_soferi;
		}
		else
		{
			throw new exception("Prea putini soferi");
		}
	}
	void set_sofer(Sofer* sofer)
	{
		if (sofer != nullptr)
		{
			if (this->sofer != nullptr)
				delete[] this->sofer;
			this->sofer = new Sofer[nr_soferi];
			for (int i = 0; i < nr_soferi; i++)
			{
				this->sofer[i] = sofer[i];
			}
		}
		else
		{
			throw new exception("Nici o marca de masini nu a fost gasita");
		}
	}

	virtual void print(std::ostream& os) const override
	{
		os << "================================" << endl
			<< "Marca               : " << this->marca << endl
			<< "Capacitate rezervor : " << this->capacitate_rezervor << endl
			<< "Km parcursi         : " << this->km_inscrisi << endl
			<< "Nr zile Functionare : " << this->nr_zile_functionare << endl
			<< "Isooric km parcuri  : [ ";
		for (int i{}; i < this->nr_zile_functionare; ++i)
		{
			os << this->istoric_consum[i] << " ";
		}
		os << "]" << endl
			<< "Numar soferi        : " << this->nr_soferi << endl
			<< "================================" << endl << endl
			<< "Soferi:" << endl << endl;
		for (int i{}; i < this->nr_soferi; ++i)
		{
			os << this->sofer[i] << endl << endl;
		}
	}

	virtual void PuneMuzica()
	{
		cout << "Pornirea muzicii in mijlocul de transport a fost realizata cu succes!";
	}

	virtual void GPS()
	{
		cout << "Unde Doriti sa ajungeti? (Oras de plecare: Bucuresti)";
		string destinatie{};
		cin >> destinatie;
		cout << "Pana la " << destinatie << " sunt 250 km";
	}
};

ostream& operator<<(ostream& os, const Mijloc_De_Transport& rhs)
{
	os << "================================" << endl
		<< "Marca               : " << rhs.marca << endl
		<< "Capacitate rezervor : " << rhs.capacitate_rezervor << endl
		<< "Km parcursi         : " << rhs.km_inscrisi << endl
		<< "Nr zile Functionare : " << rhs.nr_zile_functionare << endl
		<< "Isooric km parcuri  : [ ";
	for (int i{}; i < rhs.nr_zile_functionare; ++i)
	{
		os << rhs.istoric_consum[i] << " ";
	}
	os << "]" << endl
		<< "Numar soferi        : " << rhs.nr_soferi << endl
		<< "================================" << endl << endl
		<< "Soferi:" << endl << endl;
	for (int i{}; i < rhs.nr_soferi; ++i)
	{
		os << rhs.sofer[i] << endl << endl;
	}
	return os;
}

istream& operator>>(istream& is, Mijloc_De_Transport& rhs)
{
	char buff[1000];
	cout << "Introduceti Marca: "; is >> buff;
	delete[] rhs.marca;
	rhs.marca = new char[strlen(buff) + 1];
	strcpy(rhs.marca, buff);

	cout << "Introduceti capacitatea rezervorului: ";
	is >> rhs.capacitate_rezervor;

	cout << "Introduceti nr de km efectuati: ";
	is >> rhs.km_inscrisi;

	cout << "Introduceti nr de zile de functionare: ";
	is >> rhs.nr_zile_functionare;

	cout << "Introduceti istoricul kilometrilor parcursi: " << endl;
	delete[] rhs.istoric_consum;
	rhs.istoric_consum = new double[rhs.nr_zile_functionare];
	for (int i{}; i < rhs.nr_zile_functionare; ++i)
	{
		cout << "\tZiua" << i + 1 << ": ";
		is >> rhs.istoric_consum[i];
	}

	cout << "Introduceti nr de soferi: ";
	is >> rhs.nr_soferi;

	cout << "Introduceti Soferii: " << endl;
	delete[]rhs.sofer;
	rhs.sofer = new Sofer[rhs.nr_soferi];
	for (int i{}; i < rhs.nr_soferi; ++i)
	{
		cout << "\tSofer nr " << i + 1 << ": " << endl;
		is >> rhs.sofer[i];
	}

	return is;
}

int Mijloc_De_Transport::mijloace_de_transpport_inregistrate = 0;


