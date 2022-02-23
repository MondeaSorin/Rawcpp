#pragma once
#include "Mijloc_De_Transport.h"
using namespace std;
class Tren : public Mijloc_De_Transport
{
	friend ostream& operator<<(ostream& os, const Tren& rhs);
	friend istream& operator>>(istream& is, Tren& rhs);

	static int trenuri_inregistrate;
	static  constexpr const char* cod_unic_de_indentificare = "TX000";
protected:
	int nr_vagoane;
	int nr_rute;
	string* rute;
	int nr_pasageri;
	int* varsta_pasagerilor;
public:
	Tren()
		: Mijloc_De_Transport(), nr_vagoane{}, nr_rute{}, rute{ nullptr }, nr_pasageri{}, varsta_pasagerilor{ nullptr }
	{
		trenuri_inregistrate++;
	}

	Tren(const char* marca, double capacitate_rezervor, double km_inscrisi, int nr_zile_functionare, double* istoric_consum, int nr_soferi, Sofer* sofer, int nr_vagoane, int nr_rute, string* rute, int nr_pasageri, int* varsta_pasagerilor)
		:Mijloc_De_Transport(marca, capacitate_rezervor, km_inscrisi, nr_zile_functionare, istoric_consum, nr_soferi, sofer), nr_vagoane{}, nr_rute{}, rute{ nullptr }, nr_pasageri{}, varsta_pasagerilor{ nullptr }
	{
		if (nr_vagoane > 0)
		{
			this->nr_vagoane = nr_vagoane;
		}
		else
		{
			throw new exception("Nr vagoane invalid");
		}

		if (nr_rute > 0)
		{
			this->nr_rute = nr_rute;
		}
		else
		{
			throw new exception("Nr rute invalid");
		}

		if (rute != nullptr)
		{
			this->rute = new string[nr_rute];
			for (int i{}; i < nr_rute; ++i)
			{
				this->rute[i] = rute[i];
			}
		}
		else
		{
			throw new exception("Rute inexistente");
		}

		if (nr_pasageri > 0)
		{
			this->nr_rute = nr_pasageri;
		}
		else
		{
			throw new exception("Nu exista pasageri");
		}

		if (varsta_pasagerilor != nullptr)
		{
			this->varsta_pasagerilor = new int[nr_pasageri];
			for (int i{}; i < nr_pasageri; ++i)
			{
				this->varsta_pasagerilor[i] = varsta_pasagerilor[i];
			}
		}
		else
		{
			throw new exception("Nu exista pasageri");
		}
	}

	~Tren()
	{
		if (this->rute != nullptr)
		{
			delete[] this->rute;
		}
		if (this->varsta_pasagerilor)
		{
			delete[] this->varsta_pasagerilor;
		}
	}

	Tren(const Tren& source)
		:Mijloc_De_Transport(source)
	{
		this->nr_vagoane = source.nr_vagoane;

		this->nr_rute = source.nr_rute;

		this->rute = new string[source.nr_rute];
		for (int i{}; i < source.nr_rute; ++i)
		{
			this->rute[i] = source.rute[i];
		}

		this->nr_pasageri = source.nr_pasageri;

		this->varsta_pasagerilor = new int[nr_pasageri];
		for (int i{}; i < nr_pasageri; ++i)
		{
			this->varsta_pasagerilor[i] = source.varsta_pasagerilor[i];
		}
	}

	Tren& operator=(const Tren& source)
	{
		if (this != &source)
		{
			Mijloc_De_Transport::operator=(source);

			this->nr_vagoane = source.nr_vagoane;

			this->nr_rute = source.nr_rute;

			if (this->rute != nullptr)
				delete[] this->rute;
			this->rute = new string[source.nr_rute];
			for (int i{}; i < source.nr_rute; ++i)
			{
				this->rute[i] = source.rute[i];
			}

			this->nr_pasageri = source.nr_pasageri;

			if (this->varsta_pasagerilor != nullptr)
				delete[] this->varsta_pasagerilor;
			this->varsta_pasagerilor = new int[nr_pasageri];
			for (int i{}; i < nr_pasageri; ++i)
			{
				this->varsta_pasagerilor[i] = source.varsta_pasagerilor[i];
			}
		}

		return *this;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->nr_pasageri)
		{
			return this->varsta_pasagerilor[index];
		}
		else
		{
			throw new exception("Indexul nu a putut fi gasit");
		}
	}

	Tren operator+(const Tren& rhs)
	{
		Mijloc_De_Transport buff = Mijloc_De_Transport::operator+(rhs);
		int buff_nr_vagoane = this->nr_vagoane + rhs.nr_vagoane;
		int buff_nr_rute = this->nr_rute + rhs.nr_rute;

		string* buff_rute = new string[buff_nr_rute];
		for (int i{}; i < this->nr_rute; ++i)
		{
			buff_rute[i] = this->rute[i];
		}

		for (int i{}; i < rhs.nr_rute; ++i)
		{
			buff_rute[i + this->nr_rute] = rhs.rute[i];
		}

		Tren Temp(buff.get_marca(),
			buff.get_capacitate_rezervor(),
			buff.get_km_inscrisi(),
			buff.get_nr_zile_funtionare(),
			buff.get_istoric_consum_adresa(),
			buff.get_nr_soferi(),
			buff.get_sofer_adresa(),
			buff_nr_vagoane,
			buff_nr_rute,
			buff_rute,
			this->nr_pasageri,
			this->varsta_pasagerilor);
		delete[] buff_rute;

		return Temp;
	}

	Tren& operator--()
	{
		int buff_size = this->nr_pasageri - 1;
		int* buff = new int[buff_size];
		for (int i{}; i < buff_size; ++i)
		{
			buff[i] = this->varsta_pasagerilor[i];
		}
		delete[] this->varsta_pasagerilor;
		this->nr_pasageri = buff_size;
		this->varsta_pasagerilor = buff;
		return *this;
	}

	Tren operator--(int)
	{
		Tren Temp(*this);
		operator--();
		return Temp;
	}

	operator int()
	{
		return this->nr_vagoane;
	}

	bool operator<(const Tren& rhs)
	{
		return this->nr_pasageri < rhs.nr_pasageri;
	}

	bool operator==(const Tren& rhs)
	{
		return this->nr_rute == rhs.nr_rute;
	}

	int get_nr_vagoane() const { return nr_vagoane; }
	int get_nr_pasageri() const { return nr_pasageri; }
	int* get_varsta_pasagerilor_adresa() const { return varsta_pasagerilor; }
	int get_nr_rute() const { return nr_rute; }
	string* get_rute_adresa() const { return rute; }

	void set_nr_vagoane(int nr_vagoane)
	{
		if (nr_vagoane > 0)
		{
			this->nr_vagoane = nr_vagoane;
		}
		else
		{
			throw new exception("Nr vagoane invalid");
		}
	}

	void set_nr_rute(int nr_rute)
	{
		if (nr_rute > 0)
		{
			this->nr_rute = nr_rute;
		}
		else
		{
			throw new exception("Nr rute invalid");
		}
	}

	void set_rute(string* rute)
	{
		if (rute != nullptr)
		{
			if (this->rute != nullptr)
				delete[] this->rute;
			this->rute = new string[nr_rute];
			for (int i{}; i < nr_rute; ++i)
			{
				this->rute[i] = rute[i];
			}
		}
		else
		{
			throw new exception("Rute inexistente");
		}
	}

	void set_nr_pasageri(int nr_pasageri)
	{
		if (nr_pasageri > 0)
		{
			this->nr_rute = nr_pasageri;
		}
		else
		{
			throw new exception("Nu exista pasageri");
		}
	}

	void set_varsta_pasagerilor(int* varsta_pasagerilor)
	{
		if (varsta_pasagerilor != nullptr)
		{
			if (this->varsta_pasagerilor != nullptr)
				delete[] this->varsta_pasagerilor;
			this->varsta_pasagerilor = new int[nr_pasageri];
			for (int i{}; i < nr_pasageri; ++i)
			{
				this->varsta_pasagerilor[i] = varsta_pasagerilor[i];
			}
		}
		else
		{
			throw new exception("Nu exista pasageri");
		}
	}

	virtual void print(std::ostream& os) const override
	{
		os << (Mijloc_De_Transport)(*this) << endl
			<< "Nr vagoane: " << this->nr_vagoane << endl
			<< "Nr rute: " << this->nr_rute << endl
			<< "Rute: [ ";
		for (int i{}; i < this->nr_rute; ++i)
		{
			os << this->rute[i] << " ";
		}
		os << "]" << endl;
	}

	virtual void PuneMuzica()
	{
		cout << "Pornirea muzicii in Tren a fost realizata cu succes!";
	}

	virtual void GPS()
	{
		cout << "Unde Doriti sa ajungeti? (Oras de plecare: Bucuresti)";
		string destinatie{};
		cin >> destinatie;
		cout << "Pana la " << destinatie << " sunt 250 km (Tren)";
	}
};

int Tren::trenuri_inregistrate = 0;

ostream& operator<<(ostream& os, const Tren& rhs)
{
	os << (Mijloc_De_Transport)rhs << endl
		<< "Nr vagoane: " << rhs.nr_vagoane << endl
		<< "Nr rute: " << rhs.nr_rute << endl
		<< "Rute: [ ";
	for (int i{}; i < rhs.nr_rute; ++i)
	{
		os << rhs.rute[i] << " ";
	}
	os << "]" << endl;
	return os;
}

istream& operator>>(istream& is, Tren& rhs)
{
	cout << "Introduceti numarul de vagonae: ";
	is >> rhs.nr_vagoane;
	cout << "Introduceti numarul de rute: ";
	is >> rhs.nr_rute;
	cout << "Introduceti rutele: " << endl;
	for (int i{}; i < rhs.nr_rute; ++i)
	{
		string buff;
		cout << "\tRuta " << i + 1 << ": ";
		is >> buff;
		rhs.rute[i] = buff;
	}
	cout << "Introduceti nr de pasageri: ";
	is >> rhs.nr_pasageri;

	cout << "Introduceti varstele pasagerilor:" << endl;
	for (int i{}; i < rhs.nr_pasageri; ++i)
	{
		cout << "\tPasagerul " << i + 1 << ": ";
		is >> rhs.varsta_pasagerilor[i];
	}

	return is;
}
