#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Locatie.h"
#include "Eveniment.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


enum tip_bilet { vip, normal, categoria1, categoria2, loja, peluza, tribuna1, tribuna2 };

class Bilet {
private:
	char* nume_client;
	float pret_bilet;
	int nr_loc;
	int nr_rand;
	Eveniment even;
	Locatie loc;
	const int nr_bilet_vandut_zi;
	static int nr_bilete;
	tip_bilet tip;
	int varsta;
	int id_bilet;



public:
	
	//constructor implicit
	
	Bilet() :nr_bilet_vandut_zi(nr_bilete++) {
		nume_client = new char[strlen("A") + 1];
		strcpy_s(nume_client, strlen("A") + 1, "A");
		pret_bilet = 0;
		nr_loc = 0;
		nr_rand = 0;
		tip = normal;
		varsta = 0;

	}

	//constructor cu parametrii
	
	Bilet(const char* nume_client, int varsta, int nr_loc, int nr_rand, tip_bilet tip, Eveniment even) :nr_bilet_vandut_zi(nr_bilete++) {
		this->nume_client = new char[strlen(nume_client) + 1];
		strcpy_s(this->nume_client, strlen(nume_client) + 1, nume_client);
		this->nr_loc = nr_loc;
		this->nr_rand = nr_rand;
		this->tip = tip;
		this->even = even;
		this->varsta = varsta;
		if (varsta < 7) {
			this->pret_bilet = 0;
	}
		else {
			if (tip == vip) {
				this->pret_bilet = 100;
			}
			if (tip == normal) {
				this->pret_bilet = 50;
			}
			if (tip == categoria1) {
				this->pret_bilet = 40;
			}
			if (tip == categoria2) {
				this->pret_bilet = 30;
			}
			if (tip == loja) {
				this->pret_bilet = 20;
			}
			if (tip == peluza) {
				this->pret_bilet = 10;
			}
			if (tip == tribuna1) {
				this->pret_bilet = 5;
			}
			if (tip == tribuna2) {
				this->pret_bilet = 2;
			}
		}
		
	}

	//constructor de copiere

	Bilet(const Bilet& b) :nr_bilet_vandut_zi(nr_bilete++) {
		this->nume_client = new char[strlen(b.nume_client) + 1];
		strcpy_s(this->nume_client, strlen(b.nume_client) + 1, b.nume_client);
		this->pret_bilet = b.pret_bilet;
		this->nr_loc = b.nr_loc;
		this->nr_rand = b.nr_rand;
		this->even = b.even;
		this->tip = b.tip;
		this->varsta = b.varsta;
		
	}

	//supraincarcarea operatorului =
	

	Bilet& operator=(const Bilet& b) {
		if (this != &b) {
			if (this->nume_client != NULL)
				delete[] this->nume_client;
			this->nume_client = new char[strlen(b.nume_client) + 1];
			strcpy_s(this->nume_client, strlen(b.nume_client) + 1, b.nume_client);
			this->pret_bilet = b.pret_bilet;
			this->nr_loc = b.nr_loc;
			this->nr_rand = b.nr_rand;
			this->even = b.even;
			this->tip = b.tip;
			this->varsta = b.varsta;
		}
		return *this;
	}

	//setteri si gatteri

	void setNumeClient(const char* nume_client) {
		if (this->nume_client != NULL)
			delete[] this->nume_client;
		this->nume_client = new char[strlen(nume_client) + 1];
		strcpy_s(this->nume_client, strlen(nume_client) + 1, nume_client);
	}

	char* getNumeClient() {
		char* copie = new char[strlen(this->nume_client) + 1];
		strcpy_s(copie, strlen(this->nume_client) + 1, this->nume_client);
		return copie;
	}

	void setPretBilet(float pret_bilet) {
		if (pret_bilet) {
			this->pret_bilet = pret_bilet;
		}
	}

	float getPretBilet() {
		return this->pret_bilet;
	}

	void setNrLoc(int nr_loc) {
		this->nr_loc = nr_loc;
	}

	int getNrLoc() {
		return this->nr_loc;
	}

	void setNrRand(int nr_rand) {
		this->nr_rand = nr_rand;
	}

	void setvarsta(int varsta) {
		this->varsta = varsta;
	}

	void setTip(tip_bilet tip) {
		this->tip = tip;
	}

	tip_bilet getTip() {
		return this->tip;
	}

	int getvarsta() {
		return this->varsta;
	}

	int getNrRand() {
		return this->nr_rand;
	}

	void setEveniment(Eveniment even) {
		this->even = even;
	}


	Eveniment getEveniment() {
		return this->even;
	}

	void setLocatie(Locatie loc) {
			this->loc = loc;
	}

	Locatie getLocatie() {
		return this->loc;
	}

	int getNrBiletVandutZi() {
		return this->nr_bilet_vandut_zi;
	}

	int getid_bilet() {
			return this->id_bilet;
	}
	
	//destructor 
	~Bilet() {
		if (this->nume_client != NULL)
			delete this->nume_client;
	}

	//meoda voucher_cadou

	void voucher_cadou(int cod_voucher) {
		if (cod_voucher == 1234) {
			this->pret_bilet = pret_bilet - (pret_bilet * 10 / 100);
			cout << "Pretul cu discount este: " << pret_bilet << endl;
		}
		else {
			cout << "Codul voucherului este gresit.Nu ai reducere momentan! :( ";
		}
	}

	//metoda discount
	void aplicarediscount() {
		if (varsta>=7 && varsta < 14) {
			pret_bilet = pret_bilet - (pret_bilet * 20 / 100);
			cout << "Pretul cu discount pentru adolescent este: " << pret_bilet << endl;
		}
	}

	

	//operator cast

	explicit operator float() {
		return this->pret_bilet;
	}

	//operator -
	Bilet operator-(int valoare) {
		Bilet copie = *this;
		copie.pret_bilet = copie.pret_bilet - 10;
		return copie;
	}
	

	//aici am scris o metoda de generare bilet cu id aleator

	int id(Bilet& b) {

		srand((unsigned)time(NULL));

		for (int i = 1; i <= 5; i++) {
			int random = 100 + (rand() % 101);
			return random;

		}
	}


	//aici am inceput sa ma gandesc cum sa abordez faza 2, in acre trebuie sa verific daca biletul este valid
	//iau in calcul crearea unui vector in care sa salvez id-urile create si apoi sa verific daca id-ul biletului introdus este valid, prin compararea cu elementele din vector


	void verifica_bilet_valid(const int id_bil) {
		if (this->id_bilet == id_bil) cout << "ID VALID";
		else cout << "ID INVALID";
	}

	//supraincarcarea operatorilor de citire si afisare

	friend ostream& operator<<(ostream& out, Bilet b);
	friend istream& operator>>(istream& in, Bilet& b);

};
int Bilet::nr_bilete = 0;

ostream& operator<<(ostream& out, Bilet b)
{
	out << "Nume client: " << b.nume_client << endl;
	out << "Pret bilet: " << b.pret_bilet << endl;
	out << "Numar loc: " << b.nr_loc << endl;
	out << "Numar rand: " << b.nr_rand << endl;
	switch (b.tip) {
	case 0:out << "Tip bilet: vip" << endl; break;
	case 1:out << "Tip bilet: normal" << endl; break;
	case 2:out << "Tip bilet: categoria1 " << endl; break;
	case 3:out << "Tip bilet: categoria2 " << endl; break;
	case 4:out << "Tip bilet: loja " << endl; break;
	case 5:out << "Tip bilet: tribuna1 " << endl; break;
	case 6:out << "Tip bilet: tribuna2 " << endl; break;
	case 7:out << "Tip bilet: peluza " << endl; break;
	}
	out << "Eveniment: " << b.even;
	out << "Id bilet: " << b.id(b) << endl;
	out << " Nr bilete vandute azi: " << b.nr_bilet_vandut_zi << endl;
	return out;

}

istream& operator>>(istream& in, Bilet& b) {
	cout << "Numele clientului este: ";
	char buffer[50];
	in >> buffer;
	if (b.nume_client != NULL)
		delete b.nume_client;
	b.nume_client = new char[strlen(buffer) + 1];
	strcpy_s(b.nume_client, strlen(buffer) + 1, buffer);
	cout << "Pretul biletului este: ";
	in >> b.pret_bilet;
	cout << "Numarul locului este: ";
	in >> b.nr_loc;
	cout << "Numarul randului este: ";
	in >> b.nr_rand;
	cout << "Tip bilet este: ";
	string tip_bilet;
	in >> tip_bilet;
	if (tip_bilet == "normal")
		b.tip = normal;
	else if (tip_bilet == "vip")
		b.tip = vip;
	else if (tip_bilet == "categoria1")
		b.tip = categoria1;
	else if (tip_bilet == "categoria2")
		b.tip = categoria2;
	else if (tip_bilet == "loja")
		b.tip = loja;
	else if (tip_bilet == "peluza")
		b.tip = peluza;
	else if (tip_bilet == "tribuna1")
		b.tip = tribuna1;
	else if (tip_bilet == "tribuna2")
		b.tip = tribuna2;

	cout << "Evenimentul este: ";
	in >> b.even;
	return in;
}
