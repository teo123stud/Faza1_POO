#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


class Locatie {
private:
	int nr_randuri;
	int* nr_locuri_pe_rand;
	int nr_stingatoare;
	int iesiri_urgenta;


public:
	
	//constructor implicit

	Locatie() {
		nr_randuri = 0;
		nr_locuri_pe_rand = NULL;
		nr_stingatoare = 0;
		iesiri_urgenta = 0;
	}

	//constructor cu parametrii

	Locatie(int nr_randuri, const int* nr_locuri_pe_rand, int nr_stingatoare, int iesiri_urgenta)
	{
		this->nr_randuri = nr_randuri;
		this->nr_locuri_pe_rand = new int[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
			this->nr_locuri_pe_rand[i] = nr_locuri_pe_rand[i];
		this->nr_stingatoare = nr_stingatoare;
		this->iesiri_urgenta = iesiri_urgenta;
	}
	
	//constructor copiere

	Locatie(const Locatie& l)
	{
		this->nr_randuri = l.nr_randuri;
		this->nr_locuri_pe_rand = new int[l.nr_randuri];
		for (int i = 0; i < l.nr_randuri; i++)
			this->nr_locuri_pe_rand[i] = l.nr_locuri_pe_rand[i];
		this->nr_stingatoare = l.nr_stingatoare;
		this->iesiri_urgenta = l.iesiri_urgenta;

	}

	//supraincarcarea operatorului de atribuire

	Locatie& operator=(const Locatie& l)
	{
		if (this != &l) {
			this->nr_randuri = l.nr_randuri;
			if (this->nr_locuri_pe_rand != NULL)
				delete[] this->nr_locuri_pe_rand;
			this->nr_locuri_pe_rand = new int[l.nr_randuri];
			for (int i = 0; i < l.nr_randuri; i++)
				this->nr_locuri_pe_rand[i] = l.nr_locuri_pe_rand[i];
			this->nr_stingatoare = l.nr_stingatoare;
			this->iesiri_urgenta = l.iesiri_urgenta;
		}
		return *this;
	}

	//getteri si setteri

	void setNrRanduri(int nr_randuri)
	{
		if (nr_randuri) {
			this->nr_randuri = nr_randuri;
		}
	}

	int getNrRanduri()
	{
		return this->nr_randuri;
	}

	void setNrLocuriPeRand(int* nr_locuri_pe_rand)
	{
		if (this->nr_locuri_pe_rand != NULL)
			delete[] this->nr_locuri_pe_rand;
		this->nr_locuri_pe_rand = new int[this->nr_randuri];
		for (int i = 0; i < this->nr_randuri; i++)
			this->nr_locuri_pe_rand[i] = nr_locuri_pe_rand[i];
	}

	int* getNrLocuriPeRand()
	{
		return this->nr_locuri_pe_rand;
	}

	void setNrStongatoare(int nr_stingatoare)
	{
		if (nr_stingatoare) {
			this->nr_stingatoare = nr_stingatoare;
		}
	}

	void setNrIesiri(int iesiri_urgenta)
	{
		if (iesiri_urgenta) {
			this->iesiri_urgenta = iesiri_urgenta;
		}
	}

	int getNrStingatoare()
	{
		return this->nr_stingatoare;
	}

	int getNrIesiri()
	{
		return this->iesiri_urgenta;
	}

	//destructor

	~Locatie()
	{
		if (this->nr_locuri_pe_rand != NULL)
			delete[] this->nr_locuri_pe_rand;

	}
	//operator ==
	bool operator==(Locatie l) {
		if (this->nr_randuri == l.nr_randuri)
			return true;
		else
			return false;
	}

	//operator >=

	bool operator>=(Locatie l) {
		if (this->nr_randuri >= l.nr_randuri)
			return true;
		else
			return false;
	}

	//metoda verifica iesiri

	void verificaiesiri(Locatie l) {
		if (l.iesiri_urgenta > 0) cout << "EXISTA IESIRI URGENTA IN LOCATIE";
		else {
			cout << "NU EXISTA IESIRI URGENTA IN LOCATIE";
		}
	}

	//verifica stingatoare

	void verificastingatoare(Locatie l) {
		if (l.nr_stingatoare > 0) cout << "EXISTA STINGATOARE URGENTA IN LOCATIE";
		else {
			cout << "NU EXISTA STINGATOARE URGENTA IN LOCATIE";
		}
	}

	//supraincarcarea operatorilor de citire si afisare

	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
};

ostream& operator<<(ostream& out, Locatie l) {

	out << "Numarul de randuri este: " << l.nr_randuri << endl;
	out << "Numarul de locuri pe rand este: ";
	cout << endl;
	for (int i = 0; i < l.nr_randuri; i++) {
		out << l.nr_locuri_pe_rand[i] << " ";
		out << endl;
	}
	out << "Numarul de iesiri urgenta este: " << l.iesiri_urgenta << endl;
	out << "Numarul de stingatoare este: " << l.nr_stingatoare << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l) {

	cout << "Numarul de randuri este: ";
	in >> l.nr_randuri;
	if (l.nr_locuri_pe_rand != NULL)
		delete[] l.nr_locuri_pe_rand;
	l.nr_locuri_pe_rand = new int[l.nr_randuri];
	cout << "Numarul de locuri pe rand este: ";
	for (int i = 0; i < l.nr_randuri; i++)
		in >> l.nr_locuri_pe_rand[i];
	cout << "Numarul de iesiri urgenta este:";
	in >> l.iesiri_urgenta;
	cout << "Numarul de stingatoare este: ";
	in >> l.nr_stingatoare;
	return in;
}
