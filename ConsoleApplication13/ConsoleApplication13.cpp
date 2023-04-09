#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include <vector>

using namespace std;
Locatie l3(3, new int[3] { 5, 6, 7 }, 3, 3);
Eveniment e1("After", film, "11/02/2022", "13:00", l3, 100);
Eveniment e2("Titanic", film, "11/02/2022", "13:00", l3, 100);
Locatie l4(3, new int[3] { 7, 7, 7 }, 3, 3);
Locatie l5(3, new int[3] { 7, 7, 7 }, 3, 3);
EvenimentTeatru e3("Nebuni din dragoste", teatru, "11/02/2022", "13:00", l4, 100, "Mara Morgeinstein~Ionut Bobonete");
Eveniment e5("Steaua-Dinamo", sportiv, "11/02/2022", "13:00", l5, 100);



void bilet(Eveniment e1, Locatie l1, int loc, int rand) {
	cout << "Creeaza bilet" << endl;
	char* nume_client;
	nume_client = new char[20];
	cout << "Introduceti numele clientului: ";
	cin >> nume_client;
	int varsta;
	cout << "Introduceti varsta clientului: ";
	cin >> varsta;
	Bilet b1(nume_client, varsta, loc, rand, normal, e1);
	cout << b1;
	ofstream m;
	m.open("BileteSalvate");
	m << b1;
	m.close();
	b1.scriereBinar("bile1.bin");
	cout << "-----------";
	cout << "Biletul a fost creat cu succes!" << endl;
	cout << "-----------";
	ifstream f("bile1.bin", ios::binary | ios::in);
	Bilet b;
	Eveniment e;
	b.citireBinar("bile1.bin");

}
void afisare_bilete() {
	ifstream f("bile1.bin", ios::binary | ios::in);
	Bilet b;
	Eveniment e;
	b.citireBinar("bile1.bin");

}


void verifica_id_bilet() {
	{
		int id;
		cout << "Introduceti id-ul biletului pe care doriti sa il verificati: ";
		cin >> id;
		ifstream f("bile1.bin");
		Bilet b;
		b.citireBinar("bile1.bin");
		if (id == b.getid_bilet()) {
			cout << "Biletul cu id-ul " << id << " exista in baza de date!" << endl;
		}
		else {
			cout << "Biletul cu id-ul " << id << " nu exista in baza de date!" << endl;
		}
		f.close();
	}
}





void afisaretip() {
	cout << "Bine ai venit! Selecteaza tip eveniment!" << endl;
	cout << "Alege tip eveniment:" << endl;
	cout << "1. Film" << endl;
	cout << "2. Teatru" << endl;
	cout << "3. Sport" << endl;
	cout << "Alege optiunea: ";
	int a;
	cin >> a;
	switch (a) {
	case 1:
		cout << "Tip bilet:" << endl;
		cout << "1. Normal" << endl;
		cout << "2. VIP" << endl;
		cout << "Alege tipul biletului: ";
		int b;
		cin >> b;
		if (b == 1) {
			cout << "Alege film la CinemaMax";
			cout << endl;
			cout << "1.After" << endl;
			cout << "2.Titanic" << endl;
			int optiuneata;
			cin >> optiuneata;
			if (optiuneata == 1) {
			
					cout << "De la randul 2 pana la randul " << l3.getNrRanduri() << endl;
					for (int i = 1; i < l3.getNrRanduri(); i++) {
						cout << "Randul " << i + 1 << "are " << l3.getNrLocuriPeRand()[i] << "locuri ";
						cout << endl;
					}
					cout << endl;
					int r, s;
					cout << "Rand: ";
					cin >> r;
					cout << "Loc: ";
					cin >> s;
					if (r != 1 && s >= 1) {
						if (r <= l3.getNrRanduri() && s <= l3.getNrLocuriPeRand()[r - 1]) {
							ifstream f("AfterMovie.txt", ios::in);
							int** matrice = new int* [l3.getNrRanduri()];
							for (int i = 0; i < l3.getNrRanduri(); i++) {
								matrice[i] = new int[l3.getNrLocuriPeRand()[i]];
							}
							for (int i = 0; i < l3.getNrRanduri(); i++) {
								for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
									f >> matrice[i][j];
								}
							}
							f.close();
							if (e1.verifica_loc_liber(matrice, r, s) == true) {
								matrice[r - 1][s - 1] = 1;

								//scrie
								ofstream f1("AfterMovie.txt", ios::out);
								for (int i = 0; i < l3.getNrRanduri(); i++) {
									for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
										f1 << matrice[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								//verifica daca locule  liber in matrice


								//seteaza matricea evenimentului e cu valorea matricei din fisier citite
								e1.setMatrice(matrice);
								e1.getMatrice();
								cout << e1;
								bilet(e1, l3, r, s);
							}
							else {
								cout << "Loc ocupat!";
							}
						}
						else {
							cout << "Ai introdus loc VIP.Reincearca!";
							cout << endl;
						}
					}
					else {
						cout << "Invalid";
						cout << endl;
					}
					break;
			}
			if (optiuneata == 2) {
				cout << "De la randul 2 pana la randul " << l3.getNrRanduri() << endl;
				for (int i = 1; i < l3.getNrRanduri(); i++) {
					cout << "Randul " << i + 1 << "are " << l3.getNrLocuriPeRand()[i] << "locuri ";
					cout << endl;
				}
				cout << endl;
				int rs, sr;
				cout << "Rand: ";
				cin >> rs;
				cout << "Loc: ";
				cin >> sr;
				if (rs != 1 && sr >= 1) {


					// citeste matricea din fisierul text AfterMovie, ocupa loc si apoi rescrie in fisier
					if (rs <= l3.getNrRanduri() && rs <= l3.getNrLocuriPeRand()[rs - 1]) {
						ifstream f("Titanic.txt", ios::in);
						int** matrice = new int* [l3.getNrRanduri()];
						for (int i = 0; i < l3.getNrRanduri(); i++) {
							matrice[i] = new int[l3.getNrLocuriPeRand()[i]];
						}
						for (int i = 0; i < l3.getNrRanduri(); i++) {
							for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
								f >> matrice[i][j];
							}
						}
						f.close();
						if (e1.verifica_loc_liber(matrice, rs, sr) == true) {
							matrice[rs - 1][sr - 1] = 1;
							ofstream f1("Titanic.txt", ios::out);
							for (int i = 0; i < l3.getNrRanduri(); i++) {
								for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
									f1 << matrice[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e2.setMatrice(matrice);
							e2.getMatrice();
							cout << e2;
							bilet(e2, l3, rs, sr);
						}
						else {
							cout << "Loc ocupat!";
						}
					}
				else {
					cout << "Ai introdus loc VIP.Reincearca!";
					cout << endl;
				}
			}
				else {
					cout << "Locul nu este disponibil!" << endl;

				}

			}
			break;
		}


		if (b == 2) {
			cout << "Alege film la CinemaMax";
			cout << endl;
			cout << "1.After" << endl;
			cout << "2.Titanic" << endl;
			int optiuneata2;
			cin >> optiuneata2;
			if (optiuneata2 == 1) {
				cout << "Randul 1, locurile de la 1 la " << l3.getNrLocuriPeRand()[0] << endl;
				cout << endl;
				int m, n;
				cout << "Rand: ";
				cin >> m;
				cout << "Loc";
				cin >> n;
				if (m == 1 && n >= 1 && n <= l3.getNrLocuriPeRand()[m - 1]) {
					ifstream f("AfterMovie.txt", ios::in);
					int** matrice = new int* [l3.getNrRanduri()];
					for (int i = 0; i < l3.getNrRanduri(); i++) {
						matrice[i] = new int[l3.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l3.getNrRanduri(); i++) {
						for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e1.verifica_loc_liber(matrice, m, n) == true) {
						matrice[m - 1][n - 1] = 1;
						ofstream f1("AfterMovie.txt", ios::out);
						for (int i = 0; i < l3.getNrRanduri(); i++) {
							for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e1.setMatrice(matrice);
						e1.getMatrice();
						cout << e1;

						bilet(e1, l3, m, n);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Nu ai introdus loc VIP";
					cout << endl;
				}
				break;
			}
			if (optiuneata2 == 2) {
				cout << "Randul 1, locurile de la 1 la " << l3.getNrLocuriPeRand()[0] << endl;
				cout << endl;
				int mn, nm;
				cout << "Rand: ";
				cin >> mn;
				cout << "Loc: ";
				cin >> nm;
				if (mn == 1 && nm >= 1 && nm <= l3.getNrLocuriPeRand()[mn - 1]) {
					ifstream f("Titanic.txt", ios::in);
					int** matrice = new int* [l3.getNrRanduri()];
					for (int i = 0; i < l3.getNrRanduri(); i++) {
						matrice[i] = new int[l3.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l3.getNrRanduri(); i++) {
						for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e2.verifica_loc_liber(matrice, mn, nm) == true) {
						matrice[mn - 1][nm - 1] = 1;
						ofstream f1("Titanic.txt", ios::out);
						for (int i = 0; i < l3.getNrRanduri(); i++) {
							for (int j = 0; j < l3.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e2.setMatrice(matrice);
						e1.getMatrice();
						cout << e2;
						bilet(e2, l3, mn, nm);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Nu ai introdus loc VIP";
					cout << endl;
				}

			}
			break;
		}

		break;

	case 2:

		cout << "Tip bilet:" << endl;
		cout << "1. Categoria 1" << endl;
		cout << "2. Categoria 2" << endl;
		cout << "3. Loja" << endl;
		int c;
		cin >> c;
		if (c == 1) {
			cout << "Alege piesa teatru la TNB";
			cout << endl;
			cout << "1.Nebuni din dragoste" << endl;
			int optiunea4;
			cin >> optiunea4;
			if (optiunea4 == 1) {
				cout << "Randurile 1,2 fara locul 1, unde exista: " << l4.getNrRanduri() << " randuri" << endl;
				cout << endl;
				int ft, t;
				cout << "Rand: ";
				cin >> t;
				cout << "Loc: ";
				cin >> ft;
				if (t == 1 || t == 2 && ft != 1 && ft <= l4.getNrLocuriPeRand()[t - 1]) {
					ifstream f("Nebuni.txt", ios::in);
					int** matrice = new int* [l4.getNrRanduri()];
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						matrice[i] = new int[l4.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e3.verifica_loc_liber(matrice, ft, t) == true) {
						matrice[t - 1][ft - 1] = 1;
						ofstream f1("Nebuni.txt", ios::out);
						for (int i = 0; i < l4.getNrRanduri(); i++) {
							for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e3.setMatrice(matrice);
						e3.getMatrice();
						cout << e3;
						bilet(e3, l4, ft, t);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Locul nu este disponibil!" << endl;
				}
			}
			break;
		}
		if (c == 2) {
			cout << "Alege piesa teatru la TNB";
			cout << endl;
			cout << "1.Nebuni din dragoste" << endl;
			int optiunea5;
			cin >> optiunea5;
			if (optiunea5 == 1) {
				cout << "Toate locurile, fara randurile 1 si 2 si locul 1 de pe toate randurile, unde exista: " << l4.getNrRanduri() << " randuri" << endl;
				cout << endl;
				int u, p;
				cout << "Rand: ";
				cin >> u;
				cout << "Loc: ";
				cin >> p;
				if (p > 1 && p <- l4.getNrLocuriPeRand()[u - 1] && u>2 && u <=l4.getNrRanduri()) {
					ifstream f("Nebuni.txt", ios::in);
					int** matrice = new int* [l4.getNrRanduri()];
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						matrice[i] = new int[l4.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e3.verifica_loc_liber(matrice, u, p) == true) {
						matrice[u - 1][p - 1] = 1;
						ofstream f1("Nebuni.txt", ios::out);
						for (int i = 0; i < l4.getNrRanduri(); i++) {
							for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e3.setMatrice(matrice);
						e3.getMatrice();
						cout << e3;
						bilet(e3, l4, p, u);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Locul nu este disponibil!" << endl;

				}
			}
			break;
		}

		if (c == 3) {
			cout << "Alege piesa teatru la TNB";
			cout << endl;
			cout << "1.Nebuni din dragoste" << endl;
			int optiunea6;
			cin >> optiunea6;
			if (optiunea6 == 1) {
				cout << "Locul 1 de pe fiecare rand, unde exista: " << l4.getNrRanduri() << " randuri" << endl;
				cout << endl;
				int k, j;
				cout << "Rand: ";
				cin >> k;
				cout << "Loc: ";
				cin >> j;
				if (j == 1 && k >= 1 && k <= l4.getNrRanduri()) {
					ifstream f("Nebuni.txt", ios::in);
					int** matrice = new int* [l4.getNrRanduri()];
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						matrice[i] = new int[l4.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l4.getNrRanduri(); i++) {
						for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e3.verifica_loc_liber(matrice, k, j) == true) {
						matrice[k - 1][j - 1] = 1;
						ofstream f1("Nebuni.txt", ios::out);
						for (int i = 0; i < l4.getNrRanduri(); i++) {
							for (int j = 0; j < l4.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e3.setMatrice(matrice);
						e3.getMatrice();
						cout << e3;
						bilet(e3, l4, k, j);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Locul nu este disponibil!" << endl;
				}
			}
		}
		break;


	case 3:
		cout << "Tip bilet:" << endl;
		cout << "1. Peluza" << endl;
		cout << "2. Tribuna 1" << endl;
		cout << "3. Tribuna 2" << endl;
		int d;
		cin >> d;
		if (d == 1) {
			cout << "Alege eveniment sportiv:";
			cout << endl;
			cout << "1.Meci Steaua- Dinamo" << endl;
			int optiunea7;
			cin >> optiunea7;
			if (optiunea7 == 1) {
				cout << "Primul si ultimul loc de pe fiecare rand unde exista: " << endl;
				for (int i = 0; i < l5.getNrRanduri(); i++) {
					cout << "Randul " << i + 1 << "are" << l5.getNrLocuriPeRand()[i] << "locuri ";
					cout << endl;
				}
				int v, o;
				cout << "Rand: ";
				cin >> v;
				cout << "Loc: ";
				cin >> o;
				if (o== 1 || o == l5.getNrLocuriPeRand()[v - 1] && v >= 1 && v <= l5.getNrRanduri()) {
					ifstream f("Meci.txt", ios::in);
					int** matrice = new int* [l5.getNrRanduri()];
					for (int i = 0; i < l5.getNrRanduri(); i++) {
						matrice[i] = new int[l5.getNrLocuriPeRand()[i]];
					}
					for (int i = 0; i < l5.getNrRanduri(); i++) {
						for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
							f >> matrice[i][j];
						}
					}
					f.close();
					if (e5.verifica_loc_liber(matrice, v, o) == true) {
						matrice[v - 1][o - 1] = 1;
						ofstream f1("Meci.txt", ios::out);
						for (int i = 0; i < l5.getNrRanduri(); i++) {
							for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
								f1 << matrice[i][j] << " ";
							}
							f1 << endl;
						}
						f1.close();
						e5.setMatrice(matrice);
						e5.getMatrice();
						cout << e5;
						bilet(e5, l5, v, o);
					}
					else {
						cout << "Loc ocupat!";
					}
				}
				else {
					cout << "Nu ai introdus loc Peluza";
					cout << endl;
				}

			}
			if (d == 2) {
				cout << "Alege eveniment sportiv:";
				cout << endl;
				cout << "1.Meci Steaua- Dinamo" << endl;
				int optiunea8;
				cin >> optiunea8;
				if (optiunea8 == 1) {

					for (int i = 0; i < l5.getNrRanduri() - 1; i++) {
						cout << "Randul " << i + 1 << " locurile 2-" << l5.getNrLocuriPeRand()[i] - 1;
						cout << endl;
					}
					int q, w;
					cout << "Rand: ";
					cin >> q;
					cout << "Loc: ";
					cin >> w;
					if (q >= 1 && q <= l5.getNrRanduri() - 1 && w > 1 && w < l5.getNrLocuriPeRand()[q - 1]) {
						ifstream f("Meci.txt", ios::in);
						int** matrice = new int* [l5.getNrRanduri()];
						for (int i = 0; i < l5.getNrRanduri(); i++) {
							matrice[i] = new int[l5.getNrLocuriPeRand()[i]];
						}
						for (int i = 0; i < l5.getNrRanduri(); i++) {
							for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
								f >> matrice[i][j];
							}
						}
						f.close();
						if (e5.verifica_loc_liber(matrice, q, w) == true) {
							matrice[q - 1][w - 1] = 1;
							ofstream f1("Meci.txt", ios::out);
							for (int i = 0; i < l5.getNrRanduri(); i++) {
								for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
									f1 << matrice[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e5.setMatrice(matrice);
							e5.getMatrice();
							cout << e5;
							bilet(e5, l5, q, w);
						}
						else {
							cout << "Loc coupat!";
						}
					}
					else {
						cout << "Nu ai introdus loc Tribuna1";
						cout << endl;
					}
				}
				break;
			}
			if (d == 3) {
				cout << "Alege eveniment sportiv:";
				cout << endl;
				cout << "1.Meci Steaua- Dinamo" << endl;
				int optiunea9;
				cin >> optiunea9;
				if (optiunea9 == 1) {
					int f = l5.getNrRanduri();
					cout << "Randul " << f << " locurile de la 2 la " << l5.getNrLocuriPeRand()[f - 1] - 1;
					cout << endl;
					int ab, cd;
					cout << "Rand: ";
					cin >> ab;
					cout << "Loc: ";
					cin >> cd;
					if (ab == l5.getNrRanduri() && cd > 1 && cd <= l5.getNrLocuriPeRand()[ab - 1] - 1) {
						ifstream f("Meci.txt", ios::in);
						int** matrice = new int* [l5.getNrRanduri()];
						for (int i = 0; i < l5.getNrRanduri(); i++) {
							matrice[i] = new int[l5.getNrLocuriPeRand()[i]];
						}
						for (int i = 0; i < l5.getNrRanduri(); i++) {
							for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
								f >> matrice[i][j];
							}
						}
						f.close();
						if (e5.verifica_loc_liber(matrice, ab, cd) == true) {
							ofstream f1("Meci.txt", ios::out);
							for (int i = 0; i < l5.getNrRanduri(); i++) {
								for (int j = 0; j < l5.getNrLocuriPeRand()[i]; j++) {
									f1 << matrice[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e5.setMatrice(matrice);
							e5.getMatrice();
							cout << e5;
							bilet(e5, l5, ab, cd);
						}
						else {
							cout << "Loc ocupat!";
						}
					}
					else {
						cout << "Nu ai introdus locul de la tribuna 2";
						cout << endl;
					}

				}
			}
			break;
		}
		break;
	}
	
}



void citire_din_fisiere() {

	//citeste datele de intrare din fisiere si creeaza bilet

	std::ifstream f("Locatii.txt");
	int nr_randuri;
	f >> nr_randuri;
	int* nr_locuri_pe_rand = new int[nr_randuri];
	for (int i = 0; i < nr_randuri; i++) {
		f >> nr_locuri_pe_rand[i];
	}
	int nr_stingatoare;
	f >> nr_stingatoare;
	int iesiri_urgenta;
	f >> iesiri_urgenta;
	Locatie locatie(nr_randuri, nr_locuri_pe_rand, nr_stingatoare, iesiri_urgenta);
	f.close();


	std::ifstream f1("Eveniment.txt");
	char* nume = new char[20];
	f1 >> nume;
	string data;
	f1 >> data;
	string ora;
	f1 >> ora;
	int durata;
	f1 >> durata;
	Eveniment eveniment(nume, data, ora, locatie, durata);
	f1.close();


	//citeste nume client, varsta, loc, rand, tip_bilet, tip_eveniment


	std::ifstream f2("Bilete.txt");
	char* nume_client = new char[20];
	f2 >> nume_client;
	int varsta;
	f2 >> varsta;
	int rand;
	f2 >> rand;
	int loc;
	f2 >> loc;
	string tip;
	f2 >> tip;
	tip_bilet tipb;
	if (tip == "vip") {
		tipb = vip;
	}
	else if (tip == "normal") {
		tipb = normal;
	}
	else if (tip == "peluza") {
		tipb = peluza;
	}

	Bilet bilet1(nume_client, varsta, rand, loc, tipb, eveniment);
	eveniment.OcupaLoc(locatie, rand, loc);
	f2.close();
	
	

	
	
}


		
	
	


void lansare_console_txt() {
	
		int optiune;
		int r;
			cout << "1. Consola" << endl;
			cout << "2. ConsoleAplication13 dat.txt" << endl;
			cout << "Optiunea: ";
			cin >> optiune;
			if (optiune == 1) {
				afisaretip();
				cout << "Continui? ";
				cout << "1.DA";
				cout << "2.NU";
				cin >> r;
				while (r == 1) {
						afisaretip();
	            cin >> r;
				}

			}
			else if (optiune == 2) {
				citire_din_fisiere();
			}
			else {
				cout << "Optiunea nu exista" << endl;
			}
		
}
	

void meniu_mic() {
	cout << "---------------------------------";
	cout << endl;
	cout << " Bine ai venit la TicketulTau! ";
	cout << endl;
	cout << "---------------------------------";
	cout << endl;
	cout << "Esti administrator sau client? ";
	cout << endl;
	cout << "----------------------------------";
	cout << endl;
	cout << "1. Administrator";
	cout << endl;
	cout << "2. Client";
	cout << endl;
	cout << "Optiunea: ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Alege optiune: ";
		cout << "1.Vezi bilete existente!";
		cout << endl;
		cout << "2.Verifica daca un ID este valid!";
		cout << endl;
		cout << "3.Creeaza o locatie!";
		cout << endl;
		cout << "4.Creeaza un eveniment!";
		int gr;
		cin >> gr;
		if (gr == 1) {
			afisare_bilete();
		}
		if (gr == 2) {
			int h;
			cin >> h;
			verifica_id_bilet();
		}
		if (gr == 3) {
			int nr_randuri;
			cout << "Introduceti numarul de randuri: ";
			cin >> nr_randuri;
			int* nr_locuri_pe_rand = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++) {
				cout << "Introduceti numarul de locuri pe randul " << i + 1 << ": ";
				cin >> nr_locuri_pe_rand[i];
			}
			int nr_stingatoare;
			cout << "Introduceti numarul de stingatoare: ";
			cin >> nr_stingatoare;
			int iesiri_urgenta;
			cout << "Introduceti numarul de iesiri de urgenta: ";
			cin >> iesiri_urgenta;
			Locatie locatie(nr_randuri, nr_locuri_pe_rand, nr_stingatoare, iesiri_urgenta);
			cout << locatie;
		}
		if (gr == 4) {
			char* nume = new char[20];
			cout << "Introduceti numele evenimentului: ";
			cin >> nume;
			string data;
			cout << "Introduceti data evenimentului: ";
			cin >> data;
			string ora;
			cout << "Introduceti ora evenimentului: ";
			cin >> ora;
			int durata;
			cout << "Introduceti durata evenimentului: ";
			cin >> durata;
			Locatie locatie;
			cin >> locatie;
			Eveniment eveniment(nume, data, ora, locatie, durata);
			cout << eveniment;
		}
		break;
	case 2:
		cout << "1.Cumpara bilet";
		cout << endl;
		cout << "2.Vezi evenimentele ce se desfasoara in curand";
		cout << endl;
		cout << "3.Informatii despre evenimentul sportiv";
		cout << endl;
		cout << "4.Vezi discount-uri:";
		cout << endl;
		int lo;
		cin >> lo;
		if (lo == 1) {
			lansare_console_txt();
			break;
		}
		if (lo == 2){
			
				cout << "Tip eveniment: ";
				cout << "1.Film";
				cout << "2.Teatru";
				cout << "3.Sport";
			
				int j;
				cin >> j;
				if (j == 1) {
					list < Eveniment> nume_evenimente;
					nume_evenimente.push_back(e1);
					nume_evenimente.push_back(e2);
					list < Eveniment> ::iterator it;
					for (it = nume_evenimente.begin(); it != nume_evenimente.end(); it++) {
						cout << (*it).getNumeEveniment() << endl;
					}
					cout << endl;
					break;
				}
				if (j == 2) {
					list <Eveniment> nume_eveniment_teatru;
					nume_eveniment_teatru.push_back(e3);
					list <Eveniment> ::iterator it;
					for (it = nume_eveniment_teatru.begin(); it != nume_eveniment_teatru.end(); it++) {
						cout << (*it).getNumeEveniment() << endl;
					}
					cout << endl;
					break;

				}
				if (j == 3) {
					list <Eveniment> nume_eveniment_sport;
					nume_eveniment_sport.push_back(e5);
					list <Eveniment> ::iterator it;
					for (it = nume_eveniment_sport.begin(); it != nume_eveniment_sport.end(); it++) {
						cout << (*it).getNumeEveniment() << endl;
					}
					cout << endl;
					break;

				}
				break;
			}
		
		if (lo == 3) {
			cout << "Alege sportul";
			cout << endl;
			cout << "1.Fotbal";
			cout << endl;
			cout << "2.Handbal";
			cout << endl;
			cout << "3.Volei";
			cout << endl;
			cout << "Introdu optiunea ta: ";
			int gt;
			cin >> gt;
			if (gt == 1) {
				Fotbal f1;
				f1.jucatori();
				f1.rezerve();
				f1.suprafata();
				f1.afiseaza();
				break;
			}
			if (gt == 2) {
				Handbal h1;
				h1.rezerve();
				h1.jucatori();
				h1.suprafata();
				h1.afiseaza();
				break;
			}
			if (gt == 3) {
				Volei v1;
				v1.rezerve();
				v1.jucatori();
				v1.suprafata();
				v1.afiseaza();
				break;
			}
			break;
		}
		if (lo == 4) {
			cout << "Ai un vucher cadou? Introdu codul si iti vom arata pretul cu discount!";
			Bilet b;
			cout << "Pret intreg:";
			cout << endl;
			int a;
			cin >> a;
			cout << "Cod voucher:";
			cout << endl;
			int c;
			cin >> c;
			b.voucher_cadou(a, c);
		}
	
	default:

		break;
	}

}

	
		int main() {

			meniu_mic();
	
		}
	
	