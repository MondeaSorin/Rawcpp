#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Sofer
{
	friend ostream& operator<<(ostream& os, const Sofer& rhs);
	friend istream& operator>>(istream& is, Sofer& rhs);

	static int soferi_inregistrati;
	static  constexpr const char* cod_unic_de_indentificare = "SX000";
private:
	char* nume;
	int ani_vechime;
	int nr_zile_munca;
	int* ore_de_munca;
	int nr_masini_conduse;
	string* marca_masini_conduse;
public:
	Sofer()
		: nume{ nullptr }, ani_vechime{}, nr_zile_munca{}, ore_de_munca{ nullptr }, nr_masini_conduse{}, marca_masini_conduse{ nullptr }
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");

		this->ore_de_munca = new int;
		*ore_de_munca = 0;

		soferi_inregistrati++;
	}

	Sofer(const char* nume, int ani_vechime, int nr_zile_munca, int* ore_de_munca, int nr_masini_conduse, const string* marca_masini_conduse)
		:nume{ nullptr }, ani_vechime{}, nr_zile_munca{}, ore_de_munca{ nullptr }, nr_masini_conduse{}, marca_masini_conduse{ nullptr }
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			this->nume = new char[strlen("Anonim") + 1];
			strcpy(this->nume, "Anonim");
		}

		if (ani_vechime > 0)
		{
			this->ani_vechime = ani_vechime;
		}
		else
		{
			throw new exception("Vechimea nu poate fi negativa");
		}

		if (nr_zile_munca > 0 && nr_zile_munca <= 5)
		{
			this->nr_zile_munca = nr_zile_munca;
		}
		else
		{
			throw new exception("Nu poate lucra 0 zile pe saptamana!");
		}

		if (ore_de_munca != nullptr)
		{
			this->ore_de_munca = new int[nr_zile_munca];
			for (int i = 0; i < nr_zile_munca; i++)
			{
				this->ore_de_munca[i] = ore_de_munca[i];
			}
		}

		if (nr_masini_conduse > 0)
		{
			this->nr_masini_conduse = nr_masini_conduse;
		}
		else
		{
			throw new exception("Nu este calificat fara sa fi condus cel putin o masina");
		}

		if (marca_masini_conduse != nullptr)
		{
			this->marca_masini_conduse = new string[nr_masini_conduse];
			for (int i = 0; i < nr_masini_conduse; i++)
			{
				this->marca_masini_conduse[i] = marca_masini_conduse[i];
			}
		}
		else
		{
			throw new exception("Nici o marca de masini nu a fost gasita");
		}

		soferi_inregistrati++;
	}

	~Sofer()
	{
		if (nume != nullptr)
		{
			delete[] this->nume;
		}

		if (this->ore_de_munca != nullptr)
		{
			delete[] this->ore_de_munca;
		}

		if (this->marca_masini_conduse != nullptr)
		{
			delete[] this->marca_masini_conduse;
		}
	}

	Sofer(const Sofer& source)
	{
		this->nume = new char[strlen(source.nume) + 1];
		strcpy(this->nume, source.nume);

		this->ani_vechime = source.ani_vechime;

		this->nr_zile_munca = source.nr_zile_munca;

		this->ore_de_munca = new int[nr_zile_munca];
		for (int i{}; i < nr_zile_munca; ++i)
		{
			this->ore_de_munca[i] = source.ore_de_munca[i];
		}

		this->nr_masini_conduse = source.nr_masini_conduse;

		this->marca_masini_conduse = new string[nr_masini_conduse];
		for (int i{}; i < nr_masini_conduse; ++i)
		{
			this->marca_masini_conduse[i] = source.marca_masini_conduse[i];
		}

		soferi_inregistrati++;
	}

	Sofer& operator=(const Sofer& source)
	{
		if (this != &source)
		{
			if (this->nume != nullptr)
				delete[] this->nume;
			this->nume = new char[strlen(source.nume) + 1];
			strcpy(this->nume, source.nume);

			this->ani_vechime = source.ani_vechime;

			this->nr_zile_munca = source.nr_zile_munca;

			if (ore_de_munca != nullptr)
				delete[] this->ore_de_munca;
			this->ore_de_munca = new int[nr_zile_munca];
			for (int i{}; i < nr_zile_munca; ++i)
			{
				this->ore_de_munca[i] = source.ore_de_munca[i];
			}

			this->nr_masini_conduse = source.nr_masini_conduse;

			if (this->marca_masini_conduse != nullptr)
				delete[] this->marca_masini_conduse;
			this->marca_masini_conduse = new string[nr_masini_conduse];
			for (int i{}; i < nr_masini_conduse; ++i)
			{
				this->marca_masini_conduse[i] = source.marca_masini_conduse[i];
			}

			soferi_inregistrati++;
		}
		return *this;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->nr_zile_munca)
		{
			return ore_de_munca[index];
		}
		else
		{
			throw new exception("Indexul nu a putut fi gasit");
		}
	}

	Sofer operator+(const Sofer& rhs) const
	{
		char* buff = new char[strlen(this->nume) + strlen(rhs.nume) + strlen("-") + 1];
		strcpy(buff, this->nume);
		strcat(buff, "-");
		strcat(buff, rhs.nume);

		int buff_vechime = max(this->ani_vechime, rhs.ani_vechime);

		int buff_nr_zile_munca = min(this->nr_zile_munca, rhs.nr_zile_munca);

		int* buff_ore_de_munca = new int[buff_nr_zile_munca];
		for (int i{}; i < buff_nr_zile_munca; ++i)
		{
			buff_ore_de_munca[i] = this->ore_de_munca[i] + rhs.ore_de_munca[i];
		}

		int buff_nr_masini_conduse = this->nr_masini_conduse + rhs.nr_masini_conduse;
		string* buff_masini_conduse = new string[buff_nr_masini_conduse];
		for (int i{}; i < this->nr_masini_conduse; ++i)
		{
			buff_masini_conduse[i] = this->marca_masini_conduse[i];
		}

		for (int i{}; i < rhs.nr_masini_conduse; ++i)
		{
			buff_masini_conduse[i + this->nr_masini_conduse] = rhs.marca_masini_conduse[i];
		}

		Sofer Temp(buff, buff_vechime, buff_nr_zile_munca, buff_ore_de_munca, buff_nr_masini_conduse, buff_masini_conduse);
		delete[] buff;
		delete[] buff_ore_de_munca;
		delete[] buff_masini_conduse;
		return Temp;
	}

	Sofer& operator--()
	{
		int buff_size = this->nr_masini_conduse - 1;
		string* buff = new string[buff_size];
		for (int i{}; i < buff_size; ++i)
		{
			buff[i] = this->marca_masini_conduse[i];
		}
		delete[] this->marca_masini_conduse;
		this->nr_masini_conduse = buff_size;
		this->marca_masini_conduse = buff;
		return *this;
	}

	Sofer operator--(int)
	{
		Sofer Temp(*this);
		operator--();
		return Temp;
	}

	operator int()
	{
		return this->ani_vechime;
	}

	Sofer operator!()
	{
		char* buff = new char[strlen(this->nume) + 1];
		strcpy(buff, this->nume);
		for (int i{}; i < strlen(buff); ++i)
		{
			buff[i] = toupper(buff[i]);
		}

		Sofer Temp(buff, this->ani_vechime, this->nr_zile_munca, this->ore_de_munca, this->nr_masini_conduse, this->marca_masini_conduse);
		delete[] buff;
		return Temp;
	}

	bool operator<(const Sofer& rhs)
	{
		int total_ore_munca_a{};
		for (int i{}; i < this->nr_zile_munca; ++i)
		{
			total_ore_munca_a += this->ore_de_munca[i];
		}

		int total_ore_munca_b{};
		for (int i{}; i < rhs.nr_zile_munca; ++i)
		{
			total_ore_munca_b += rhs.ore_de_munca[i];
		}

		return total_ore_munca_a < total_ore_munca_b;
	}

	bool operator==(const Sofer& rhs)
	{
		return this->ani_vechime == rhs.ani_vechime;
	}

	char* get_nume() const { return this->nume; }
	int get_ani_vechime() const { return this->ani_vechime; }
	int get_nr_zile_munca() const { return this->nr_zile_munca; }
	int* get_ore_munca_adresa() const { return this->ore_de_munca; }
	void get_ore_munca()
	{
		cout << "[ ";
		for (int i{}; i < this->nr_zile_munca; ++i)
		{
			cout << this->ore_de_munca[i] << " ";
		}
		cout << "]" << endl;
	}
	int get_nr_masini_conduse() const { return this->nr_masini_conduse; }
	string* get_marca_masini_conduse_adresa() const { return this->marca_masini_conduse; }
	void get_marca_masini_conduse()
	{
		cout << "[ ";
		for (int i{}; i < this->nr_masini_conduse; ++i)
		{
			cout << this->marca_masini_conduse[i] << " ";
		}
		cout << "]" << endl;
	}

	void set_nume(const char* nume)
	{
		if (nume != nullptr)
		{
			if (this->nume != nullptr)
				delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			throw new exception("Numele introdus este gol");
		}
	}
	void set_ani_vechime(int ani_vechime)
	{
		if (ani_vechime > 0)
		{
			this->ani_vechime = ani_vechime;
		}
		else
		{
			throw new exception("Vechimea nu poate fi negativa");
		}
	}
	void set_nr_zile_munca(int nr_zile_munca)
	{
		if (nr_zile_munca > 0)
		{
			this->nr_zile_munca = nr_zile_munca;
		}
		else
		{
			throw new exception("Nu poate lucra 0 zile pe saptamana!");
		}
	}
	void set_ore_munca(int* ore_de_munca)
	{
		if (ore_de_munca != nullptr)
		{
			if (this->ore_de_munca != nullptr)
				delete[] this->ore_de_munca;
			this->ore_de_munca = new int[nr_zile_munca];
			for (int i = 0; i < nr_zile_munca; i++)
			{
				this->ore_de_munca[i] = ore_de_munca[i];
			}
		}
	}
	void set_nr_masini_conduse(int nr_masini_conduse)
	{
		if (nr_masini_conduse > 0)
		{
			this->nr_masini_conduse = nr_masini_conduse;
		}
		else
		{
			throw new exception("Nu este calificat fara sa fi condus cel putin o masina");
		}
	}
	void set_marca_masini_conduse(string* marca_masini_conduse)
	{
		if (marca_masini_conduse != nullptr)
		{
			if (this->marca_masini_conduse != nullptr)
				delete[] this->marca_masini_conduse;
			this->marca_masini_conduse = new string[nr_masini_conduse];
			for (int i = 0; i < nr_masini_conduse; i++)
			{
				this->marca_masini_conduse[i] = marca_masini_conduse[i];
			}
		}
		else
		{
			throw new exception("Nici o marca de masini nu a fost gasita");
		}
	}

	void afisare()
	{
		cout << "================================================================================" << endl
			<< setw(20) << left << "Nume"
			<< setw(20) << left << "Vechime"
			<< setw(20) << left << "Ore munca saptamana"
			<< setw(20) << left << "Numar masini conduse" << endl
			<< setw(20) << left << this->nume
			<< setw(20) << left << this->ani_vechime
			<< setw(20) << left << this->nr_zile_munca
			<< setw(20) << left << this->nr_masini_conduse << endl << endl << endl << endl
			<< setw(26) << left << "Program saptamanal de lucru" << endl
			<< setw(16) << left << "Luni"
			<< setw(16) << left << "Marti"
			<< setw(16) << left << "Miercuri"
			<< setw(16) << left << "Joi"
			<< setw(16) << left << "Vineri" << endl;
		for (int i = 0; i < this->nr_zile_munca; i++)
		{
			cout << setw(16) << left << this->ore_de_munca[i];
		}

		cout << endl << endl << endl;
		cout << endl << setw(26) << left << "Marca masini conduse" << endl;
		for (int i{}; i < this->nr_masini_conduse; ++i)
		{
			cout << this->marca_masini_conduse[i] << endl;
		}

		cout << "================================================================================" << endl << endl;
	}
};

ostream& operator<<(ostream& os, const Sofer& rhs)
{
	os << "================================================================================" << endl
		<< setw(20) << left << "Nume"
		<< setw(20) << left << "Vechime"
		<< setw(20) << left << "Ore munca saptamana"
		<< setw(20) << left << "Numar masini conduse" << endl
		<< setw(20) << left << rhs.nume
		<< setw(20) << left << rhs.ani_vechime
		<< setw(20) << left << rhs.nr_zile_munca
		<< setw(20) << left << rhs.nr_masini_conduse << endl << endl << endl << endl
		<< setw(26) << left << "Program saptamanal de lucru" << endl
		<< setw(16) << left << "Luni"
		<< setw(16) << left << "Marti"
		<< setw(16) << left << "Miercuri"
		<< setw(16) << left << "Joi"
		<< setw(16) << left << "Vineri" << endl;
	for (int i = 0; i < rhs.nr_zile_munca; i++)
	{
		os << setw(16) << left << rhs.ore_de_munca[i];
	}

	os << endl << endl << endl;
	os << endl << setw(26) << left << "Marca masini conduse" << endl;
	for (int i{}; i < rhs.nr_masini_conduse; ++i)
	{
		os << rhs.marca_masini_conduse[i] << endl;
	}

	os << "================================================================================" << endl << endl;

	return os;

}

istream& operator>>(istream& is, Sofer& rhs)
{
	cout << "Introduceti numele: ";
	char buff[1000];
	is >> buff;
	delete[] rhs.nume;
	rhs.nume = new char[strlen(buff) + 1];
	strcpy(rhs.nume, buff);

	cout << "Introduceti de cati ani conduce soferul: ";
	is >> rhs.ani_vechime;

	cout << "Introduceti cate zile pe saptamana munceste: ";
	is >> rhs.nr_zile_munca;

	cout << "Introduceti orarul cu orele de munca" << endl;
	delete[] rhs.ore_de_munca;
	rhs.ore_de_munca = new int[rhs.nr_zile_munca];
	for (int i{}; i < rhs.nr_zile_munca; ++i)
	{
		cout << "\tZiua " << i + 1 << ": ";
		is >> rhs.ore_de_munca[i];
	}

	cout << "Introduceti cate masini a condus pana acum: ";
	is >> rhs.nr_masini_conduse;

	cout << "Introduceti marcile masinilor conduse" << endl;
	delete[] rhs.marca_masini_conduse;
	rhs.marca_masini_conduse = new string[rhs.nr_masini_conduse];

	for (int i{}; i < rhs.nr_masini_conduse; ++i)
	{
		string buff;
		cout << "\tMasina " << i + 1 << ": ";
		//is.ignore();
		//is.clear();
		//getline(is, buff);

		is >> buff; //getline imi ignora primul caracter

		rhs.marca_masini_conduse[i] = buff;
	}
	return is;
}

int Sofer::soferi_inregistrati = 0;

