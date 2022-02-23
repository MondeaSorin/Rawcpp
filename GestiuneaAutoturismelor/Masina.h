#pragma once
#include "Mijloc_De_Transport.h"
using namespace std;

class Masina : public Mijloc_De_Transport
{
	friend ostream& operator<<(ostream& os, const Masina& rhs);
	friend istream& operator>>(istream& is, Masina& rhs);

	static int masini_inregistrate;
	static  constexpr const char* cod_unic_de_indentificare = "MX000";
protected:;
		 int nr_accidente;
		 int* an_accident;
		 float asigurari_platite_in_ultimul_an;
		 bool loc_de_copii;
public:
	Masina()
		: Mijloc_De_Transport(), nr_accidente{}, an_accident{ nullptr }, asigurari_platite_in_ultimul_an{ 0.0 }, loc_de_copii{ false }
	{
		masini_inregistrate++;
	}

	Masina(const char* marca, double capacitate_rezervor, double km_inscrisi, int nr_zile_functionare, double* istoric_consum, int nr_soferi, Sofer* sofer, int nr_accidente, int* an_accident, float asigurari_platite_in_ultimul_an, bool loc_de_copii)
		: Mijloc_De_Transport(marca, capacitate_rezervor, km_inscrisi, nr_zile_functionare, istoric_consum, nr_soferi, sofer), nr_accidente{}, an_accident{ nullptr }, asigurari_platite_in_ultimul_an{ 0.0 }, loc_de_copii{ false }
	{
		if (nr_accidente > 0)
		{
			this->nr_accidente = nr_accidente;
		}
		else
		{
			throw new exception("Nr accidente negativ");
		}

		if (an_accident != nullptr)
		{
			this->an_accident = new int[nr_accidente];
			for (int i{}; i < nr_accidente; ++i)
			{
				this->an_accident[i] = an_accident[i];
			}
		}
		else
		{
			throw new exception("Vector gol");
		}

		if (asigurari_platite_in_ultimul_an > 0)
		{
			this->asigurari_platite_in_ultimul_an = asigurari_platite_in_ultimul_an;
		}
		else
		{
			throw new exception("Suma scadenta negativa");
		}

		this->loc_de_copii = loc_de_copii;

		masini_inregistrate++;
	}

	~Masina()
	{
		if (this->an_accident != nullptr)
			delete[] this->an_accident;
	}

	Masina(const Masina& source)
		:Mijloc_De_Transport(source)
	{
		this->nr_accidente = source.nr_accidente;

		this->an_accident = new int[nr_accidente];
		for (int i{}; i < nr_accidente; ++i)
		{
			this->an_accident[i] = source.an_accident[i];
		}

		this->asigurari_platite_in_ultimul_an = source.asigurari_platite_in_ultimul_an;

		this->loc_de_copii = source.loc_de_copii;
	}

	Masina& operator=(const Masina& source)
	{
		if (this != &source)
		{
			Mijloc_De_Transport::operator=(source);

			this->nr_accidente = source.nr_accidente;

			if (this->an_accident != nullptr)
				delete[] this->an_accident;
			this->an_accident = new int[nr_accidente];
			for (int i{}; i < nr_accidente; ++i)
			{
				this->an_accident[i] = source.an_accident[i];
			}

			this->asigurari_platite_in_ultimul_an = source.asigurari_platite_in_ultimul_an;

			this->loc_de_copii = source.loc_de_copii;
		}
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->nr_accidente)
		{
			return this->an_accident[index];
		}
		else
		{
			throw new exception("Indexul nu a putut fi gasit");
		}
	}

	Masina operator+(const Masina& rhs)
	{
		Mijloc_De_Transport buff = Mijloc_De_Transport::operator+(rhs);
		float buff_asigurari = this->asigurari_platite_in_ultimul_an + rhs.asigurari_platite_in_ultimul_an;

		Masina Temp(buff.get_marca(),
			buff.get_capacitate_rezervor(),
			buff.get_km_inscrisi(),
			buff.get_nr_zile_funtionare(),
			buff.get_istoric_consum_adresa(),
			buff.get_nr_soferi(),
			buff.get_sofer_adresa(),
			this->nr_accidente,
			this->an_accident,
			buff_asigurari,
			this->loc_de_copii);

		return Temp;
	}

	Masina& operator--()
	{
		int buff_size = this->nr_accidente - 1;
		int* buff = new int[buff_size];
		for (int i{}; i < buff_size; ++i)
		{
			buff[i] = this->an_accident[i];
		}
		delete[] this->an_accident;
		this->nr_accidente = buff_size;
		this->an_accident = buff;
		return *this;
	}

	Masina operator--(int)
	{
		Masina Temp(*this);
		operator--();
		return Temp;
	}

	operator int()
	{
		return this->nr_accidente;
	}

	bool operator<(const Masina& rhs)
	{
		return this->asigurari_platite_in_ultimul_an < rhs.asigurari_platite_in_ultimul_an;
	}

	bool operator==(const Masina& rhs)
	{
		return this->asigurari_platite_in_ultimul_an == rhs.asigurari_platite_in_ultimul_an;
	}

	int get_nr_accidente() const { return nr_accidente; }
	int* get_an_accident_adresa() const { return an_accident; }
	float get_asigurari_platite_in_ultimul_an() const { return asigurari_platite_in_ultimul_an; }
	bool get_loc_copil() const { return loc_de_copii; }

	void set_nr_accidente(int nr_accidente)
	{
		if (nr_accidente > 0)
		{
			this->nr_accidente = nr_accidente;
		}
		else
		{
			throw new exception("Nr accidente negativ");
		}
	}

	void set_an_accident(int* an_accident)
	{
		if (an_accident != nullptr)
		{
			if (this->an_accident != nullptr)
				delete[] this->an_accident;
			this->an_accident = new int[nr_accidente];
			for (int i{}; i < nr_accidente; ++i)
			{
				this->an_accident[i] = an_accident[i];
			}
		}
		else
		{
			throw new exception("Vector gol");
		}
	}

	void set_asigurari_platite_in_ultimul_an(float asigurari_platite_in_ultimul_an)
	{
		if (asigurari_platite_in_ultimul_an > 0)
		{
			this->asigurari_platite_in_ultimul_an = asigurari_platite_in_ultimul_an;
		}
		else
		{
			throw new exception("Suma scadenta negativa");
		}
	}

	void set_loc_de_copii(bool loc_de_copii)
	{
		this->loc_de_copii = loc_de_copii;
	}

	virtual void print(std::ostream& os) const override
	{
		os << (Mijloc_De_Transport)(*this);
		os << "Nr de accidente avut: " << this->nr_accidente << endl
			<< "Anul accidentelor este: [ ";
		for (int i{}; i < this->nr_accidente; ++i)
		{
			os << this->an_accident[i] << " ";
		}
		os << "[" << endl
			<< "Valoarea asigurarilor platite in ultimul an este: " << this->asigurari_platite_in_ultimul_an << endl
			<< "Are loc de copii: " << this->loc_de_copii << endl;
	}

	virtual void PuneMuzica()
	{
		cout << "Pornirea muzicii in Masina a fost realizata cu succes!";
	}

	virtual void GPS()
	{
		cout << "Unde Doriti sa ajungeti? (Oras de plecare: Bucuresti";
		string destinatie{};
		cin >> destinatie;
		cout << "Pana la " << destinatie << " sunt 333 km (Masina)";
	}
};

int Masina::masini_inregistrate = 0;

ostream& operator<<(ostream& os, const Masina& rhs)
{
	os << (Mijloc_De_Transport)rhs;
	os << "Nr de accidente avut: " << rhs.nr_accidente << endl
		<< "Anul accidentelor este: [ ";
	for (int i{}; i < rhs.nr_accidente; ++i)
	{
		os << rhs.an_accident[i] << " ";
	}
	os << "[" << endl
		<< "Valoarea asigurarilor platite in ultimul an este: " << rhs.asigurari_platite_in_ultimul_an << endl
		<< "Are loc de copii: " << rhs.loc_de_copii << endl;
	return os;
}

istream& operator>>(istream& is, Masina& rhs)
{
	cout << "Introduceti nr de accidente: "; is >> rhs.nr_accidente;
	cout << "Introduceti anul accidentelor:" << endl;
	for (int i{}; i < rhs.nr_accidente; ++i)
	{
		cout << "Accidentul " << i + 1 << ": ";
		is >> rhs.an_accident[i];
	}
	cout << "Introduceti valoarea asigurarilor: "; is >> rhs.asigurari_platite_in_ultimul_an;
	cout << "Introduceti daca are loc pentru copii: "; is >> rhs.loc_de_copii;
	return is;
}



