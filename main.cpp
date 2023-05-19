#include <iostream>
#include <string>
#include <vector>
using namespace std; // Standard kirjasto käyttöön

struct Huone { //Luodaan tietue yhdelle huoneelle
	int huoneNro = 1;
	string varaaja, puhelinNro;
	int yoLkm, varausNro;
	bool varattu = 0; // Jos huone on vapaa, tulee 0
};

void merkkijono() { //Aliohjelma merkkijonon tulostukseen
	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
}

int main() {
	setlocale(LC_ALL, "fi_FI"); //Otetaan ääkköset käyttöön
	srand(time(NULL)); // Lukujen arpomista varten

	int yoLkm, huoneidenLkm, hinta, laskunSumma, varattavaHuone; //Määritetään muuttujat
	int syotteenTarkistus = 0, varausNro;
	int valinta;
	bool virhe;

	vector <Huone> huoneVektori; // Tehdään kaikista huoneista vektori
	huoneidenLkm = (rand() % 40) + 30; // Arvotaan huoneiden kokonaismäärä väliltä 30-70
	hinta = (rand() % 20) + 80; // Arvotaan hinta yhdelle yölle väliltä 80-100 euroa

	cout << "Hei! Tervetuloa Hotelliin.\n";

	bool lippu = true;
	while (lippu !=false){ //Luodaan valikko

		cout << "Haluaisitko tehdä varauksen? Syötä 1= Kyllä tai 0= En, poistu ohjelmasta: ";
		cin >> valinta;

		while (cin.fail()) { //Syötteen tarkistus
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Haluaisitko tehdä varauksen? Syötä 1= Kyllä tai 0= En, poistu ohjelmasta: ";
			cin >> valinta;
		}

		for (int i = 0; i < huoneidenLkm; i++) {
			huoneVektori.push_back({ i + 1 });
		}

		switch (valinta) {

			case 1: //Jos käyttäjä syöttää 1 ja haluaa tehdä varauksen

			merkkijono();

			cout << "\n\n";
			cout << "Hienoa! Huoneita meillä on " << huoneidenLkm << " kappaletta ja\n";
			cout << "hinta yhdelle yölle hotellissamme on " << hinta << " euroa.\n";

			syotteenTarkistus = 0;

			while (syotteenTarkistus == 0) {
				varattavaHuone = (rand() % huoneidenLkm);

				if (huoneVektori[varattavaHuone].varattu == 0) {
					huoneVektori[varattavaHuone].varattu == 1;

					cout << "Sinulle meillä on vapaana huone numerolla " << huoneVektori[varattavaHuone].huoneNro << ".\n\n";

					syotteenTarkistus = 1;
				}
			}

			huoneVektori[varattavaHuone].varausNro = (rand() % 89999) + 10000; // Arvotaan varausnumero väliltä 10 000 - 99 999
			cout << "Syöttäisitkö vielä tietosi, niin saadaan varauksesi tallennettua. \n";

			merkkijono();

			cout << "\n";

			// Kysytään varaajan tiedot

			cout << "Koko nimi: ";
			getline(cin, huoneVektori[varattavaHuone].varaaja); //Etunimelle
			getline(cin, huoneVektori[varattavaHuone].varaaja); //Sukunimelle

			cout << "Puhelinnumero: ";
			cin >> huoneVektori[varattavaHuone].puhelinNro;

			do { //Virheen tarkistus öiden määrälle
				virhe = false;

				cout << "Öiden määrä: ";
				cin >> huoneVektori[varattavaHuone].yoLkm;

				if (cin.fail()) {
					cout << "Virhe. Anna luku uudestaan!\n";
					virhe = true;
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (virhe);

			laskunSumma = hinta * huoneVektori[varattavaHuone].yoLkm;

			cout << "Kiitos varauksestasi. \n";
			cout << "Hintaa tälle vierailullesi tulee " << laskunSumma << " euroa. \n";
			cout << "Varausnumerosi on " << huoneVektori[varattavaHuone].varausNro << ". \n\n";

			break;

			case 0: //Jos käyttäjä syöttää 0, lopetetaan ohjelma

			merkkijono();

			cout << "\n";
			cout << "Näkemiin! Kiitos käynnistäsi ja tervetuloa uudelleen.\n\n";

			return 0;
		}
	}
	return 0;
}
