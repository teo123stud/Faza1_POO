#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Locatie.h"
#include <list>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum tip_eveniment { sportiv, film, teatru };

class Eveniment {

private:
	char* nume_eveniment;
	string data;
	string ora;
	int nr_locuri;
	Locatie locatie;
	tip_eveniment teven;
	int durata;
	string* actori;
	int nr_actori;
	string* protagonisti;
	int nr_protagonisti;
	int** matrice_loc;


public:
	
	//constructor implicit
	
	Eveniment() {
		nume_eveniment = new char[strlen("A") + 1];
		strcpy_s(nume_eveniment, strlen("A") + 1, "A");
		data = "0";
		ora = "0";
		nr_locuri = 0;
		teven = film;
		durata = 0;
		matrice_loc = NULL;

	}


	//constructor cu parametrii
	
	Eveniment(const char* nume_eveniment, tip_eveniment teven, string data, string ora, Locatie loc, int durata) {
		this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
		this->data = data;
		this->ora = ora;
		for (int i = 0; i < loc.getNrRanduri(); i++) {
			this->nr_locuri += loc.getNrLocuriPeRand()[i];
		}
		this->locatie = loc;
		this->teven = teven;
		this->durata = durata;
		int** matrice_loc = new int* [loc.getNrRanduri()];
		for (int i = 0; i < loc.getNrRanduri(); i++)
			matrice_loc[i] = new int[loc.getNrLocuriPeRand()[i]];
		for (int i = 0; i < loc.getNrRanduri(); i++)
			for (int j = 0; j < loc.getNrLocuriPeRand()[i]; j++)
				matrice_loc[i][j] = 0;
		this->matrice_loc = matrice_loc;
	}
	Eveniment(const char* nume_eveniment, string data, string ora, Locatie loc, int durata) {
		this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
		this->data = data;
		this->ora = ora;
		for (int i = 0; i < loc.getNrRanduri(); i++) {
			this->nr_locuri += loc.getNrLocuriPeRand()[i];
		}
		this->locatie = loc;
		this->durata = durata;
		int** matrice_loc = new int* [loc.getNrRanduri()];
		for (int i = 0; i < loc.getNrRanduri(); i++)
			matrice_loc[i] = new int[loc.getNrLocuriPeRand()[i]];
		for (int i = 0; i < loc.getNrRanduri(); i++)
			for (int j = 0; j < loc.getNrLocuriPeRand()[i]; j++)
				matrice_loc[i][j] = 0;
		this->matrice_loc = matrice_loc;
	}
	
	//constructor de copiere
	
	Eveniment(const Eveniment& e) {
		this->nume_eveniment = new char[strlen(e.nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(e.nume_eveniment) + 1, e.nume_eveniment);
		this->data = e.data;
		this->ora = e.ora;
		for (int i = 0; i < locatie.getNrRanduri(); i++) {
			this->nr_locuri += locatie.getNrLocuriPeRand()[i];
		}
		this->nr_locuri = e.nr_locuri;
		this->locatie = e.locatie;
		this->teven = e.teven;
		this->durata = e.durata;
		int** matrice_loc = new int* [locatie.getNrRanduri()];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			matrice_loc[i] = new int[locatie.getNrLocuriPeRand()[i]];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
				matrice_loc[i][j] = e.matrice_loc[i][j];
		this->matrice_loc = matrice_loc;

	}
	
	//supraincarcae operatorul =(de atribuire)

	Eveniment& operator=(const Eveniment& e) {
		if (this != &e) {
			if (this->nume_eveniment != NULL)
				delete[] this->nume_eveniment;
			this->nume_eveniment = new char[strlen(e.nume_eveniment) + 1];
			strcpy_s(this->nume_eveniment, strlen(e.nume_eveniment) + 1, e.nume_eveniment);
			this->data = e.data;
			this->ora = e.ora;
			for (int i = 0; i < locatie.getNrRanduri(); i++) {
				this->nr_locuri += locatie.getNrLocuriPeRand()[i];
			}
			this->nr_locuri = e.nr_locuri;
			this->locatie = e.locatie;
			this->teven = e.teven;
			this->durata = e.durata;
			int** matrice_loc = new int* [locatie.getNrRanduri()];
			for (int i = 0; i < locatie.getNrRanduri(); i++)
				matrice_loc[i] = new int[locatie.getNrLocuriPeRand()[i]];
			for (int i = 0; i < locatie.getNrRanduri(); i++)
				for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
					matrice_loc[i][j] = e.matrice_loc[i][j];
			this->matrice_loc = matrice_loc;

		}
		return *this;
	}

	
	//setteri si getteri

	void setNumeEveniment(const char* nume_eveniment) {
		if (this->nume_eveniment != NULL)
			delete[] this->nume_eveniment;
		this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
	}

	char* getNumeEveniment() {
		char* copie = new char[strlen(this->nume_eveniment) + 1];
		strcpy_s(copie, strlen(this->nume_eveniment) + 1, this->nume_eveniment);
		return copie;
	}

	void setData(string data) {
		this->data = data;

	}


	string getData() {
		return this->data;
	}

	void setOra(string ora) {
		this->ora = ora;
	}

	void setDurata(int durata) {
		if (durata)
			this->durata = durata;
	}

	int getDurata() {
		return this->durata;
	}

	string getOra() {
		return this->ora;
	}

	void setNrLocuri(int nr_locuri) {
		if (nr_locuri > 0)
			this->nr_locuri = nr_locuri;
	}

	int getNrLocuri() {
		return this->nr_locuri;
	}

	void setLocatie(Locatie locatie) {
		this->locatie = locatie;
	}

	Locatie getLocatie() {
		return this->locatie;
	}

	void setTipEveniment(tip_eveniment teven) {
		if (teven == 0 || teven == 1 || teven == 2)
			this->teven = teven;
	}

	tip_eveniment getTipEveniment() {
		return this->teven;
	}


	bool verifica_loc_liber(int** matrice_loc, int x, int y) {
		bool ok = false;
		if (x < locatie.getNrRanduri() && y < locatie.getNrLocuriPeRand()[x - 1]) {
			if (matrice_loc[x - 1][y - 1] == 0) {
				ok = true;
			}
			
			
	}
		return ok;
		
	}
	
	void setMatrice(int** matrice_loc) {
		if (this->matrice_loc != NULL) {
			for (int i = 0; i < locatie.getNrRanduri(); i++)
				delete[] this->matrice_loc[i];
			delete[] this->matrice_loc;
		}
		this->matrice_loc = new int* [locatie.getNrRanduri()];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			this->matrice_loc[i] = new int[locatie.getNrLocuriPeRand()[i]];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
				this->matrice_loc[i][j] = matrice_loc[i][j];
		
	}
	
	
	int** getMatrice() {
		int** copie = new int* [locatie.getNrRanduri()];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			copie[i] = new int[locatie.getNrLocuriPeRand()[i]];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
				copie[i][j] = this->matrice_loc[i][j];
		return copie;
	}

	int** getMatriceLoc() {
		int** copie = new int* [locatie.getNrRanduri()];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			copie[i] = new int[locatie.getNrLocuriPeRand()[i]];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
				copie[i][j] = this->matrice_loc[i][j];
		return copie;
		
	}
	

	//acestea sunt gandite intr-un scenariu pentru teatru, daca i se ofera utilizatorului posibilitatea de a vedea actorii si
	//intr-un scenariu pentru film, daca i se ofera utilizatorului posibilitatea de a vedea actorii 
	//nu am realizat-o si pentru evenimentul sportiv pana in acest punct

	void setNrActori(int nr_actori) {
		if (nr_actori)
			this->nr_actori = nr_actori;
	}

	int getNrActori() {
		return this->nr_actori;
	}

	void setNrProtagonisti(int nr_protagonisti) {
		if (nr_protagonisti)
			this->nr_protagonisti = nr_protagonisti;
	}

	int getNrProtagonisti() {
		return this->nr_protagonisti;
	}

	void setActori(string* actori, int nr_actori) {
		if (this->actori != NULL)
			delete[] this->actori;
		this->actori = new string[nr_actori];
		for (int i = 0; i < nr_actori; i++)
			this->actori[i] = actori[i];
		this->nr_actori = nr_actori;
	}

	string* getActori() {
		string* copie = new string[this->nr_actori];
		for (int i = 0; i < this->nr_actori; i++)
			copie[i] = this->actori[i];
		return copie;
	}

	void setProtagonisti(string* protagonisti, int nr_protagonisti) {
		if (this->protagonisti != NULL)
			delete[] this->protagonisti;
		this->protagonisti = new string[nr_protagonisti];
		for (int i = 0; i < nr_protagonisti; i++)
			this->protagonisti[i] = protagonisti[i];
		this->nr_protagonisti = nr_protagonisti;
	}


	string* getProtagonisti() {
		string* copie = new string[this->nr_protagonisti];
		for (int i = 0; i < this->nr_protagonisti; i++)
			copie[i] = this->protagonisti[i];
		return copie;
	}


	//desctructor 
	
	~Eveniment() {
		if (this->nume_eveniment != NULL)
			delete this->nume_eveniment;
	}

	//operator !

	bool operator!() {
		if (this->nr_locuri != 0) return true;
		else return false;
	}

	//operator +

	Eveniment operator+(int valoare) {
		Eveniment copie = *this;
		copie.nr_locuri = nr_locuri + valoare;
		return copie;
	}

	//metoda posibile prelungiri pentru un meci de fotbal

	void posibileprelungiri(int minute_posibile_prelungiri) {
		if (teven == sportiv) durata += minute_posibile_prelungiri;
		cout << "Noua durata este: " << durata << endl;
	}


	

	//metoda ocupa loc

	bool OcupaLoc(Locatie& loc, int x, int y) {
		bool ok = false;
		if (x < loc.getNrRanduri() && y < loc.getNrLocuriPeRand()[x - 1]) {
			if (matrice_loc[x - 1][y - 1] == 0) {
				matrice_loc[x - 1][y - 1] = 1;
				cout << "Loc rezervat cu succes!";
				nr_locuri--;
				cout << "Nr locuri ramase: " << nr_locuri;
				cout << endl;
				ok = true;
			}
			else { cout << "Locul este deja ocupat"; }
			cout << "Situatii locuri ocupate" << endl;
			for (int i = 0; i < loc.getNrRanduri(); i++) {
				for (int j = 0; j < loc.getNrLocuriPeRand()[i]; j++) {
					cout << matrice_loc[i][j] << " ";
				}
				cout << endl;
			}
		}
		return ok;
	}

	//setter ocupare matruce

		
		
	
	
	//getter ocupare matrice
	
	int** getOcupareMatrice() {
		int** copie = new int* [locatie.getNrRanduri()];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			copie[i] = new int[locatie.getNrLocuriPeRand()[i]];
		for (int i = 0; i < locatie.getNrRanduri(); i++)
			for (int j = 0; j < locatie.getNrLocuriPeRand()[i]; j++)
				copie[i][j] = this->matrice_loc[i][j];
		return copie;
	}

	//urmaroarele metode functioneaza doar pentru cazul teatru


	void afiseazaactoriteatru() {
		if (teven == teatru) {
			actori = new string[nr_actori];
			for (int i = 0; i < nr_actori; i++)
				cout << actori[i] << endl;
		}
	}



	
	void afiseazaprotagonisti() {
		if (teven == film) {
			protagonisti = new string[nr_protagonisti];
			for (int i = 0; i < nr_protagonisti; i++)
				cout << protagonisti[i] << endl;
		}
	}

	

	//supraincarcarea operatorilor de citire si afisare

	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);

};

ostream& operator<<(ostream& out, Eveniment e) {
	out << "Numele evenimentului este: " << e.nume_eveniment << endl;
	out << "Data este: " << e.data << endl;
	out << "Ora este: " << e.ora << endl;
	out << "Numarul de locuri este: " << e.nr_locuri << endl;
	switch (e.teven) {
	case 0:out << "Tip eveniment: sportiv" << endl; break;
	case 1:out << "Tip eveniment: film" << endl; break;
	case 2:out << "Tip eveniment: teatru" << endl; break;
	default:
		out << "normal" << endl; break;
	}
	out << e.locatie << endl;
	out << "Durata este: " << e.durata << endl;
	out << "Matrice locuri: " << endl;
	for (int i = 0; i < e.locatie.getNrRanduri(); i++) {
		for (int j = 0; j < e.locatie.getNrLocuriPeRand()[i]; j++) {
			out << e.matrice_loc[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Eveniment& e) {
	cout << "Numele evenimentului este: ";
	char buffer[50];
	in >> buffer;
	if (e.nume_eveniment != NULL)
		delete e.nume_eveniment;
	e.nume_eveniment = new char[strlen(buffer) + 1];
	strcpy_s(e.nume_eveniment, strlen(buffer) + 1, buffer);
	cout << "Data este: ";
	in >> e.data;
	cout << "Ora este: ";
	in >> e.ora;
	cout << "Numarul de locuri este: ";
	in >> e.nr_locuri;
	string tip_eveniment;
	in >> tip_eveniment;
	if (tip_eveniment == "sportiv")
		e.teven = sportiv;
	else if (tip_eveniment == "film")
		e.teven = film;
	else if (tip_eveniment == "teatru")
		e.teven = teatru;
	else
		e.teven = sportiv;
	cout << "Locatia este: ";
	in >> e.locatie;
	cout << "Durata este: ";
	in >> e.durata;
	return in;
}

class EvenimentTeatru :public Eveniment {
private:
	string actori;
	
public:
	
	EvenimentTeatru() :Eveniment() {
		actori = "";
	}

	EvenimentTeatru(const char* nume_eveniment, tip_eveniment teven, string data, string ora, Locatie loc, int durata, string actori) :Eveniment( nume_eveniment,teven,data, ora,loc,durata) {
		this->actori = actori;
	}

	EvenimentTeatru(const EvenimentTeatru& e) :Eveniment(e) {
		this->actori = e.actori;
	}

	EvenimentTeatru& operator=(const EvenimentTeatru& e) {
		Eveniment::operator=(e);
		this->actori = e.actori;
		return *this;
	}

	~EvenimentTeatru() {
		actori = "";
	}

	string getActori() {
		return actori;
	}

	void setActori(string actori) {
		this->actori = actori;
	}

	friend ostream& operator<<(ostream& out, EvenimentTeatru e);
	friend istream& operator>>(istream& in, EvenimentTeatru& e);
};

ostream& operator<<(ostream& out, EvenimentTeatru e) {
	out << (Eveniment)e;
	out << "Actori: " << e.actori << endl;
	return out;
}

istream& operator>>(istream& in, EvenimentTeatru& e) {
	in >> (Eveniment&)e;
	cout << "Actori: ";
	in >> e.actori;
	return in;
}



	
class VirtualEvenimenimentSportiv {
protected:
	int nr_jucatori;
	int nr_rezerve;
	string suprafata_joc;
	
	public:
		virtual int jucatori() = 0;
		virtual int rezerve() = 0;
		virtual string suprafata();
		virtual void afiseaza();

		
		
};


string VirtualEvenimenimentSportiv::suprafata()
{
	return string();
}

void VirtualEvenimenimentSportiv::afiseaza()
{
	
}

class Fotbal : public VirtualEvenimenimentSportiv {
	
public:
	int jucatori() {
		return 11;
	}
	int rezerve() {
		return 7;
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}
	
};
	
class Handbal : public VirtualEvenimenimentSportiv {
	
	public:
	int jucatori() 
	{
		return 7;
	}
	int rezerve() {
		return 5;
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}
};

class Volei : public VirtualEvenimenimentSportiv {
	
	public:
	int jucatori() 
	{
		return 6;
	}
	int rezerve() {
		return 6; 
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}
};


