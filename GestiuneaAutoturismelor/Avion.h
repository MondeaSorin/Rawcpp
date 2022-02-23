#pragma once
#include "Mijloc_De_Transport.h"
using namespace std;

class Avion : public Mijloc_De_Transport
{
	friend ostream& operator<<(ostream& os, const Avion& rhs);
	friend istream& operator>> (istream& is, Avion& rhs);

	static int avioane_inregistrate;
	static constexpr int zilele_saptamanii = 7;
	static  constexpr const char* cod_unic_de_indentificare = "AX000";
protected:
	char* tip_avion;
	double greutate;
	float* km_parcursi_ultima_saptamana;
public:
	Avion()
		: Mijloc_De_Transport(), tip_avion{ nullptr }, greutate{ 0.0 }, km_parcursi_ultima_saptamana{ nullptr }
	{
		this->tip_avion = new char[strlen("Fara tip") + 1];
		strcpy(this->tip_avion, "Fara tip");

		km_parcursi_ultima_saptamana = new float;
		avioane_inregistrate++;
	}

	Avion(const char* marca, double capacitate_rezervor, double km_inscrisi, int nr_zile_functionare, double* istoric_consum, int nr_soferi, Sofer* sofer, char* tip_avion, double greutate, float* km_parcursi_ultima_saptamana)
		:Mijloc_De_Transport(marca, capacitate_rezervor, km_inscrisi, nr_zile_functionare, istoric_consum, nr_soferi, sofer), tip_avion{ nullptr }, greutate{ 0.0 }, km_parcursi_ultima_saptamana{ nullptr }
	{
		if (tip_avion != nullptr)
		{
			this->tip_avion = new char[strlen(tip_avion) + 1];
			strcpy(this->tip_avion, tip_avion);
		}
		else
		{
			this->tip_avion = new char[strlen("Fara tip") + 1];
			strcpy(this->tip_avion, "Fara tip");
		}

		if (greutate > 0)
		{
			this->greutate = greutate;
		}
		else
		{
			throw new exception("Greutate invalida");
		}

		if (km_parcursi_ultima_saptamana != nullptr)
		{
			this->km_parcursi_ultima_saptamana = new float[zilele_saptamanii];
			for (int i{}; i < zilele_saptamanii; ++i)
			{
				this->km_parcursi_ultima_saptamana[i] = km_parcursi_ultima_saptamana[i];
			}
		}
		else
		{
			throw new exception("Vector gol");
		}
	}

	~Avion()
	{
		if (this->tip_avion != nullptr)
			delete[] this->tip_avion;
		if (this->km_parcursi_ultima_saptamana != nullptr)
			delete[] this->km_parcursi_ultima_saptamana;
	}

	Avion(const Avion& source)
		:Mijloc_De_Transport(source)
	{
		this->tip_avion = new char[strlen(source.tip_avion) + 1];
		strcpy(this->tip_avion, source.tip_avion);

		this->greutate = source.greutate;

		this->km_parcursi_ultima_saptamana = new float[zilele_saptamanii];
		for (int i{}; i < zilele_saptamanii; ++i)
		{
			this->km_parcursi_ultima_saptamana[i] = source.km_parcursi_ultima_saptamana[i];
		}
	}

	Avion& operator=(const Avion& source)
	{
		if (this != &source)
		{
			Mijloc_De_Transport::operator=(source);

			if (this->tip_avion != nullptr)
				delete[] this->tip_avion;
			this->tip_avion = new char[strlen(source.tip_avion) + 1];
			strcpy(this->tip_avion, source.tip_avion);

			this->greutate = source.greutate;

			if (this->km_parcursi_ultima_saptamana != nullptr)
				delete[] this->km_parcursi_ultima_saptamana;
			this->km_parcursi_ultima_saptamana = new float[zilele_saptamanii];
			for (int i{}; i < zilele_saptamanii; ++i)
			{
				this->km_parcursi_ultima_saptamana[i] = source.km_parcursi_ultima_saptamana[i];
			}
		}
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < zilele_saptamanii)
		{
			return this->km_parcursi_ultima_saptamana[index];
		}
		else
		{
			throw new exception("Indexul nu a putut fi gasit");
		}
	}

	Avion operator+(const Avion& rhs)
	{
		Mijloc_De_Transport buff = Mijloc_De_Transport::operator+(rhs);

		double buff_greutate = this->greutate + rhs.greutate;

		Avion Temp(buff.get_marca(),
			buff.get_capacitate_rezervor(),
			buff.get_km_inscrisi(),
			buff.get_nr_zile_funtionare(),
			buff.get_istoric_consum_adresa(),
			buff.get_nr_soferi(),
			buff.get_sofer_adresa(),
			this->tip_avion,
			buff_greutate,
			this->km_parcursi_ultima_saptamana);
		return Temp;
	}

	Avion& operator--()
	{
		for (int i{}; i < zilele_saptamanii; ++i)
		{
			this->km_parcursi_ultima_saptamana[i] -= 10.5;
		}

		return *this;
	}

	Avion operator--(int)
	{
		Avion Temp(*this);
		operator--();
		return Temp;
	}

	operator double()
	{
		return this->greutate;
	}

	bool operator<(const Avion& rhs)
	{
		return this->greutate < rhs.greutate;
	}

	bool operator==(const Avion& rhs)
	{
		return this->greutate == rhs.greutate;
	}

	char* get_tip_avion() const { return tip_avion; }
	double get_greutate() const { return greutate; }
	float* get_km_parcursi_ultima_saptamana() const { return km_parcursi_ultima_saptamana; }

	void set_tip_avion(const char* tip_avion)
	{
		if (tip_avion != nullptr)
		{
			if (this->tip_avion != nullptr)
				delete[] this->tip_avion;
			this->tip_avion = new char[strlen(tip_avion) + 1];
			strcpy(this->tip_avion, tip_avion);
		}
		else
		{
			if (this->tip_avion != nullptr)
				delete[] this->tip_avion;
			this->tip_avion = new char[strlen("Fara tip") + 1];
			strcpy(this->tip_avion, "Fara tip");
		}
	}

	void set_greutate(double greutate)
	{
		if (greutate > 0)
		{
			this->greutate = greutate;
		}
		else
		{
			throw new exception("Greutate invalida");
		}
	}

	void set_km_parcursi_ultima_saptamana(float* km_parcursi_ultima_saptamana)
	{
		if (km_parcursi_ultima_saptamana != nullptr)
		{
			if (this->km_parcursi_ultima_saptamana != nullptr)
				delete[] this->km_parcursi_ultima_saptamana;
			this->km_parcursi_ultima_saptamana = new float[zilele_saptamanii];
			for (int i{}; i < zilele_saptamanii; ++i)
			{
				this->km_parcursi_ultima_saptamana[i] = km_parcursi_ultima_saptamana[i];
			}
		}
		else
		{
			throw new exception("Vector gol");
		}
	}

	virtual void print(std::ostream& os) const override
	{
		os << (Mijloc_De_Transport)(*this);
		os << "Tipul avionului este: " << this->tip_avion << endl
			<< "Are o greutate de: " << this->greutate << endl
			<< "Istoricul km parcursi in ultima saptamana este: [ ";
		for (int i{}; i < this->zilele_saptamanii; ++i)
		{
			os << this->km_parcursi_ultima_saptamana[i] << " ";
		}
		os << "[" << endl;
	}

	virtual void PuneMuzica()
	{
		cout << "Pornirea muzicii in Avion a fost realizata cu succes!";
	}

	virtual void GPS()
	{
		cout << "Unde Doriti sa ajungeti? (Oras de plecare: Bucuresti - Aeroport Henri-Coanda)";
		string destinatie{};
		cin >> destinatie;
		cout << "Pana la " << destinatie << " sunt 1250 km (Avion)";
	}
};

int Avion::avioane_inregistrate = 0;

ostream& operator<<(ostream& os, const Avion& rhs)
{
	os << (Mijloc_De_Transport)rhs;
	os << "Tipul avionului este: " << rhs.tip_avion << endl
		<< "Are o greutate de: " << rhs.greutate << endl
		<< "Istoricul km parcursi in ultima saptamana este: [ ";
	for (int i{}; i < rhs.zilele_saptamanii; ++i)
	{
		os << rhs.km_parcursi_ultima_saptamana[i] << " ";
	}
	os << "[" << endl;
	return os;
}

istream& operator>> (istream& is, Avion& rhs)
{
	cout << "Introduceti tipul avionului: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.tip_avion;
	rhs.tip_avion = new char[strlen(buff) + 1];
	strcpy(rhs.tip_avion, buff);

	cout << "Introduceti greutatea avionului: ";
	is >> rhs.greutate;

	cout << "Introduceti km parcursi in ultima saptamana:";
	for (int i{}; i < rhs.zilele_saptamanii; ++i)
	{
		cout << "\tZiua " << i + 1 << ": ";
		is >> rhs.km_parcursi_ultima_saptamana[i];
	}

	return is;
}
