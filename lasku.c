// stdafx.cpp : source file that includes just the standard includes
// C-projekti.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include <random>

void helppo(void);
void keskivaikea(void);
void vaikea(void);
void ohjeet(void);
void summaTeoria(void);
void erotusTeoria(void);
void tuloTeoria(void);
void osamaaraTeoria(void);
void peruskoulu(void);
void tulostaja(int *pKysymyksenNumero, int *pKokonaismaara, int *pLaskutyyppi, int *pEka, int *pToka, int *pOikeaVastaus, int *pAnnettuVastaus, int *pOikeatVastaukset);
void nimi(char *pNimiTaulu);


int _tmain(int argc, _TCHAR* argv[])
{
	int valintaValikko = 0;
	char nimiTaulu[15];
	char valintaTaso;

	do
	{
		int n = 0;
		system("cls");
		printf("Game Of Superduper\n\n");
		printf("1. Aloita peli\n");
		printf("2. Ohjeet\n");
		printf("3. Tallenna viimeisin tulos tiedostoon\n");
		printf("4. Poistu pelista\n\n");
		printf("© Janne Kari & Tarmo Merimaa (2014)\n");

		fflush(stdin);
		scanf("%d", &valintaValikko);

		system("cls");

		if (valintaValikko == 1)
		{
			printf("Anna nimesi:\n");

			fflush(stdin);
			while ((nimiTaulu[n] = getchar()) != '\n')
			{
				n++;
			}

			nimiTaulu[n] = '\0';
			nimi(nimiTaulu);

			printf("Helppo, keskivaikea, vaikea vai peruskoulutaso? (H, K, V, P)\n");

			fflush(stdin);
			scanf("%c", &valintaTaso);

			if (valintaTaso == 'h' || valintaTaso == 'H')
			{
				helppo();
			}

			else if (valintaTaso == 'k' || valintaTaso == 'K')
			{
				keskivaikea();
			}

			else if (valintaTaso == 'v' || valintaTaso == 'V')
			{
				vaikea();
			}

			else if (valintaTaso == 'p' || valintaTaso == 'P')
			{
				peruskoulu();
			}

			else
			{
				printf("Valintasi oli virheellinen!");
				system("PAUSE");
			}
		}

		else if (valintaValikko == 2)
		{
			ohjeet();
		}

		else if (valintaValikko == 3)
		{
			//tallennus();
		}
	} while (valintaValikko != 4);

	return 0;
}


void helppo(void)

{
	system("cls");

	int kysymysMaara, i, x, pisteet = 0, eka, toka, tulos, vastaus;

	srand(time(NULL));

	printf("Monta kysymysta haluat etta sinulta kysytaan?\n");

	fflush(stdin);
	scanf("%d", &kysymysMaara);

	for (i = 0; i < kysymysMaara; i++) //vetaa setin lapi niin monta kertaa ku kayttaja haluu
	{
		x = rand() % 2; //arpoo numeron valilla 0-1

		if (x == 0) //plus lasku
		{
			eka = rand() % 20;
			toka = rand() % 20;
			tulos = eka + toka;

			printf("\n\nMika on seuraavan laskun tulos:\n%d + %d = ?\n", eka, toka);
			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((helppo_2))\n paina ENTER"); //virhekoodi (helppo_2)
				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else if (x == 1) //miinus lasku
		{
			eka = rand() % 20;
			toka = rand() % 20;

			tulos = eka - toka;

			printf("Mika on seuraavan laskun tulos:\n%d - %d = ?\n", eka, toka);

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((helppo_2))\n paina ENTER"); //virhekoodi (helppo_3)
				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else
		{
			printf("tapahtui virhe! ((helppo_1))\n paina ENTER"); //virhekoodi (helppo_1)
			fflush(stdin);
			getchar();
		}
	}

	printf("\n\nPisteesi on %d/%d\nPaina ENTER palataksesi menuun\n", pisteet, kysymysMaara);
	system("PAUSE");
}

//sisaltaa seurvaat virhekoodit
//keski_1
//keski_2
//keski_3
//keski_4
//keski_5
void keskivaikea(void)
{
	system("cls");

	int kysymysMaara, i, x, pisteet = 0, eka, toka, tulos, vastaus;
	float jako_tulos;

	srand(time(NULL));

	printf("Monta kysymysta haluat etta sinulta kysytaan?\n");

	fflush(stdin);
	scanf("%d", &kysymysMaara);

	for (i = 0; i < kysymysMaara; i++) //vetaa setin lapi niin monta kertaa ku kayttaja haluu
	{
		x = rand() % 4; //arpoo numeron valilla 0-3

		if (x == 0) //plus lasku
		{
			eka = rand() % 100;
			toka = rand() % 100;

			tulos = eka + toka;

			printf("\n\nMika on seuraavan laskun tulos:\n%d + %d = ?\n", eka, toka);

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");

			}

			else
			{
				printf("tapahtui virhe! ((keski_2))\n paina ENTER"); //virhekoodi (keski_2)
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else if (x == 1) //miinus lasku
		{
			eka = rand() % 100;
			toka = rand() % 100;

			tulos = eka - toka;

			printf("Mika on seuraavan laskun tulos:\n%d - %d = ?\n", eka, toka);

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");

				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((keski_3))\n paina ENTER"); //virhekoodi (keski_3)

				fflush(stdin);
				getchar();
			}
			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else if (x == 2) //kerto lasku
		{
			eka = rand() % 10;
			toka = rand() % 10;

			tulos = eka * toka;

			printf("Mika on seuraavan laskun tulos:\n%d x %d = ?\n", eka, toka); //x kertomerkkina koska * saattaa aiheuttaa onglemia

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((keski_4))\n paina ENTER"); //virhekoodi (keski_4)

				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else if (x == 3) //jako lasku
		{
			eka = rand() % 100;
			toka = rand() % 10;

			while (toka == 0)
			{
				toka = rand() % 10;
			}

			jako_tulos = eka / toka;

			printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n%d / %d = ?\n", eka, toka); //x kertomerkkina koska * saattaa aiheuttaa onglemia

			fflush(stdin);
			scanf("%d", &vastaus);

			if ((vastaus > jako_tulos - 1) && (vastaus < jako_tulos + 1))
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != jako_tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((keski_5))\n paina ENTER"); //virhekoodi (keski_5)

				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, (int *)&jako_tulos, &vastaus, &pisteet);
		}

		else
		{
			printf("tapahtui virhe! ((keski_1))\n paina ENTER"); //virhekoodi (keski_1)

			fflush(stdin);
			getchar();
		}
	}

	printf("\n\nPisteesi on %d/%d\nPaina ENTER palataksesi menuun", pisteet, kysymysMaara);

	fflush(stdin);
	getchar();
}

//sisaltaa seurvaat virhekoodit
//vaikea_1
//vaikea_2
//vaikea_3
//vaikea_4
//vaikea_5
//vaikea_6
//vaieka_7

void vaikea(void)
{

	system("cls");

	int kysymysMaara, i, x, pisteet = 0, eka, toka, tulos, vastaus;

	int kerto_vastaus, jako_vastaus;
	float jako_tulos, kerto_tulos;

	srand(time(NULL));

	printf("Monta kysymysta haluat etta sinulta kysytaan?\n");

	fflush(stdin);
	scanf("%d", &kysymysMaara);

	for (i = 0; i < kysymysMaara; i++) //vetaa setin lapi niin monta kertaa ku kayttaja haluu
	{
		x = rand() % 4; //arpoo numeron valilla 0-3

		if (x == 0) //plus lasku
		{
			eka = rand() % 100;
			toka = rand() % 100;

			printf("\n\nMika on seuraavan laskun tulos:\n%d + ? = %d\n", eka, toka);

			fflush(stdin);
			scanf("%d", &vastaus);

			tulos = toka - eka;

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((vaikea_2))\n paina ENTER"); //virhekoodi (vaieka_2)

				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}

		else if (x == 1) //miinus lasku
		{
			x = rand() % 2; //arpoo etta kysytaanko vahentajaa vai vahennettavaa

			if (x == 0) //kysyy vahentajaa
			{
				eka = rand() % 100;
				toka = rand() % 100;

				printf("Mika on seuraavan laskun tulos:\n%d - ? = %d", eka, toka);

				fflush(stdin);
				scanf("%d", &vastaus);

				tulos = toka - eka;

				if (vastaus == tulos)
				{
					printf("\noikein\n\n\n");
					pisteet++; //oikea vastaus niin lisataan piste
				}

				else if (vastaus != tulos)
				{
					printf("\nvaarin\n\n\n");
				}

				else
				{
					printf("tapahtui virhe! ((vaikea_3))\n paina ENTER"); //virhekoodi (vaikea_3)

					fflush(stdin);
					getchar();
				}

				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
			}

			else if (x == 1) //kysyy vahennettavaa
			{
				eka = rand() % 50;
				toka = rand() % 100;

				x = rand() % 40;

				toka = toka - x;

				printf("Mika on seuraavan laskun tulos:\n? - %d = %d", eka, toka);

				fflush(stdin);
				scanf("%d", &vastaus);

				tulos = toka + eka;

				if (vastaus == tulos)
				{
					printf("\noikein\n\n\n");
					pisteet++; //oikea vastaus niin lisataan piste
				}

				else if (vastaus != tulos)
				{
					printf("\nvaarin\n\n\n");
				}

				else
				{
					printf("tapahtui virhe! ((vaikea_6))\n paina ENTER"); //virhekoodi (vaikea_6)

					fflush(stdin);
					getchar();
				}

				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
			}
		}

		else if (x == 2) //kerto lasku
		{
			eka = rand() % 10;

			while (eka == 0)
			{
				eka = rand() % 10;
			}

			toka = rand() % 50;

			while (toka < 10)
			{
				toka = rand() % 50;
			}

			printf("Mika on seuraavan laskun tulos:(pyorista kokonaislukuun)\n%d x ? = %d\n", eka, toka); //x kertomerkkina koska * saattaa aiheuttaa onglemia

			fflush(stdin);
			scanf("%d", &vastaus);

			kerto_tulos = toka / eka + 0.5;

			if ((vastaus < kerto_tulos + 1) && (vastaus > kerto_tulos - 1))
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != kerto_tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((vaikea_4))\n paina ENTER"); //virhekoodi (vaikea_4)

				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, (int *)&kerto_tulos, &vastaus, &pisteet);
		}

		else if (x == 3) //jako lasku
		{
			x = rand() % 2;

			if (x == 0) //jakaja
			{
				eka = rand() % 100;
				toka = rand() % 10;

				while (eka < 10)
				{
					eka = rand() % 100;
				}

				printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n%d / ? = %d\n", eka, toka);

				fflush(stdin);
				scanf("%d", &vastaus);

				jako_tulos = vastaus * toka;

				if ((vastaus > jako_tulos - 1) && (vastaus < jako_tulos + 1))
				{
					printf("\noikein\n\n\n");
					pisteet++; //oikea vastaus niin lisataan piste
				}

				else if (vastaus != tulos)
				{
					printf("\nvaarin\n\n\n");
				}

				else
				{
					printf("tapahtui virhe! ((keski_5))\n paina ENTER"); //virhekoodi (keski_5)

					fflush(stdin);
					getchar();
				}

				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, (int*)&jako_tulos, &vastaus, &pisteet);
			}

			else if (x == 0) //jakaja
			{
				eka = rand() % 10;
				toka = rand() % 100;

				while (toka < 10)
				{
					toka = rand() % 100;
				}

				printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n? / %d = %d\n", eka, toka);

				fflush(stdin);
				scanf("%d", &vastaus);

				jako_tulos = eka * toka;

				if ((vastaus > jako_tulos - 1) && (vastaus < jako_tulos + 1))
				{
					printf("\noikein\n\n\n");
					pisteet++; //oikea vastaus niin lisataan piste
				}

				else if (vastaus != tulos)
				{
					printf("\nvaarin\n\n\n");
				}

				else
				{
					printf("tapahtui virhe! ((vaikea_5))\n paina ENTER"); //virhekoodi (vaikea_7)

					fflush(stdin);
					getchar();
				}

				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, (int *)&jako_tulos, &vastaus, &pisteet);
			}
		}

		else
		{
			printf("tapahtui virhe! ((vaikea_1))\n paina ENTER"); //virhekoodi (vaikea_1)

			fflush(stdin);
			getchar();
		}
	}

	printf("\n\nPisteesi on %d/%d\nPaina ENTER palataksesi menuun", pisteet, kysymysMaara);

	fflush(stdin);
	getchar();
}


void ohjeet(void)
{
	system("cls");

	char vastaus;
	int teoriaVastaus;

	printf("Pelin tarkoituksena on opettaa sen pelaajaa laskemaan erilaisia laskutoimituksia.\n");
	printf("Peli sisaltaa kolme eri vaikeusastetta: helpon, keskivaikean seka vaikean.\n");
	printf("\tHelppo: plus- ja miinuslaskuja arvoilla valilta 0-100.\n");
	printf("\tKeskivaikea: plus- ja miinuslaskut seka kerto- ja jakolaskut valilta 0-10.\n");
	printf("\tVaikea: taydennystehtavia jokaisesta laskutoimituksesta valilta 0-10.\n\n");
	printf("Aluksi peli kysyy pelaajan nimen seka kuinka monta kysymysta pelaaja haluaa.\n");
	printf("Peli antaa aina yhden kysymyksen kerrallaan ja odottaa pelaajan vastausta.\n");
	printf("Vastauksen jalkeen peli ilmoittaa, oliko vastaus oikein vai vaarin seka antaa seuraavan kysymyksen.\n");
	printf("Kun pelaajan antama maara kysymyksia on kayty lapi, ilmoittaa peli oikeiden vastausten maaran.\n");
	printf("Alun valikosta voit tarkistaa omat pistemaarasi aikaisempien pelien osalta.\n");
	printf("Haluatko lukea teoriaa jostakin laskutoimituksesta? (k/e)\n");

	fflush(stdin);
	scanf("%c", &vastaus);

	if (vastaus == 'k' || vastaus == 'K')
	{
		system("cls");

		printf("Mista laskutoimituksesta haluaisit lisatietoa?\n");
		printf("1. Summa eli pluslaskut\n");
		printf("2. Erotus eli miinuslaskut\n");
		printf("3. Tulo eli kertolaskut\n");
		printf("4. Osamaara eli jakolaskut\n");

		fflush(stdin);
		scanf("%d", &teoriaVastaus);

		if (teoriaVastaus == 1)
		{
			system("cls");

			summaTeoria();
		}

		else if (teoriaVastaus == 2)
		{
			system("cls");

			erotusTeoria();
		}

		else if (teoriaVastaus == 3)
		{
			system("cls");

			tuloTeoria();
		}

		else if (teoriaVastaus == 4)
		{
			system("cls");

			osamaaraTeoria();
		}

		else
		{
			printf("Valintaa kyseisella numerolla ei ole olemassa");

			system("pause");
		}
	}

	else
	{
		printf("Palataan valikkoon.");

		system("pause");
	}
}


void summaTeoria(void)
{
	char vastaus;
	int harjVastaus;

	printf("Summa- eli pluslaskuissa on tarkoituksena lisata yhteen kaksi tai useampi annettu arvo\n");
	printf("Esimerkkina: Sinulla on kaksi omenaa. Saat viela kolme omenaa lisaa. Kuinka monta omenaa sinulla on yhteensa?\n\n");
	printf("Sama kysymys voidaan ilmaista luvuilla.\n");
	printf("Kahteen omenaan (2) lisataan (+) kolme omenaa (3), joten niiden yhteismaara (=) on?\n");
	printf("Nain ollen voidaan muodostaa lauseke: 2 + 3 = ?\n");
	printf("Laskemalla yhteen luvut kaksi (2) ja kolme (3) saadaan yhteensa viisi (5)\n");
	printf("Nain ollen vastaus kysymykseen on viisi omenaa\n");
	printf("Haluatko tehda harjoitustehtavan? (k/e)\n");

	fflush(stdin);
	scanf("%c", &vastaus);

	system("cls");

	if (vastaus == 'k' || vastaus == 'K')
	{
		do
		{
			printf("Naet kaksi koiraa. Koirien joukkoon saapuu viela yksi koira.\n");
			printf("Sama numeroin: 2 + 1 = ?\n");
			printf("Montako koiraa naet?\n");

			fflush(stdin);
			scanf("%d", &harjVastaus);

			if (harjVastaus == 3)
			{
				printf("Vastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);

				system("pause");
			}

			else
			{
				printf("Vastauksesi %d oli vaarin. Yrita uudelleen!\n", harjVastaus);

				system("pause");
			}

		} while (harjVastaus != 3);
	}

	else
	{
		printf("Palataan valikkoon.");

		system("pause");
	}
}


void erotusTeoria(void)
{
	char vastaus;
	int harjVastaus;

	printf("Erotus- eli miinuslaskun (tai vahennyslaskun) ideana on vahentaa ensimmaisena annetusta luvusta toinen annettu luku.\n");
	printf("Esimerkiksi: Kolme varista istuu aidalla. Yksi lahtee pois. Kuinka monta varista jaa aidalle istumaan?\n\n");
	printf("Sama voidaan ilmaista numeroin eli lukuarvoilla\n");
	printf("Kolme varista (3). Variksista lahtee pois (-) yksi. Variksia aidalla yhteensa (=) ?\n");
	printf("Eli: 3 - 1 = ?\n");
	printf("Vahentamalla luvusta kolme (3) luku yksi (1) saadaan vastaukseksi kaksi (2)\n");
	printf("Eli 3 - 1 = 2\n");
	printf("Vastaus on siis kaksi varista\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");

	fflush(stdin);
	scanf("%c", &vastaus);

	system("cls");

	if (vastaus == 'k' || vastaus == 'K')
	{
		do
		{
			printf("Viisi norsua kavelee jonossa. Yksi norsuista lahtee pois jonosta.\n");
			printf("Sama numeroin: 5 - 1 = ?\n");
			printf("Montako norsua on viela jonossa?\n");

			fflush(stdin);
			scanf("%d", &harjVastaus);

			if (harjVastaus == 4)
			{
				printf("Vastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);

				system("pause");
			}

			else
			{
				printf("Vastauksesi %d oli vaarin. Yrita uudeleen!\n", harjVastaus);

				system("pause");
			}
		} while (harjVastaus != 4);
	}

	else
	{
		printf("Palataan valikkoon.");

		system("pause");
	}
}


void tuloTeoria(void)
{
	char vastaus;
	int harjVastaus;

	printf("Tulo- eli kertolaskun tarkoituksena on moninkertaistaa jokin luku.\n");
	printf("Esimerkiksi luvun 3 kaksinkertaistaminen voitaisiin merkita 3 * 2 = 6.\n");
	printf("Tama tarkoittaa sita, etta lukuun nolla lisataan ensimmainen luku (eli 3) niin monta kertaa kuin kerroin meille nayttaa (tassa tapauksessa 2)\n");
	printf("Nain ollen sama lasku voidaan ajatella muodossa 3 + 3 = 6\n");
	printf("Esimerkiksi: Sinulla on kaksi omenaa. Omenoiden maara kolminkertaistetaan. Kuinka monta omenaa sinulla on lopuksi?\n");
	printf("Sama voidaan ilmaista lukuarvoin eli numeroilla.\n");
	printf("Sinulla on kaksi omenaa (2), joiden lukumaara kerrotaan (*) kolmella (3). Lopuksi sinulla on omenoita (=) ?\n");
	printf("Eli 2 * 3 = ?\n");
	printf("Kuten aikaisemmassakin esimerkissa, voidaan laskutoimitus muuttaa myos summamuotoon.\n");
	printf("Eli 2 + 2 + 2 = ?\n");
	printf("Nain ollen vastaukseksi saadaan kuusi (6) omenaa.\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");

	fflush(stdin);
	scanf("%c", &vastaus);

	system("cls");

	if (vastaus == 'k' || vastaus == 'K')
	{
		do
		{
			printf("Jaakaapissa on kolme viilia. Kun katsot jaakaappiin uudelleen, huomaat, etta viilien maara on kaksinkertaistunut.\n");
			printf("Eli 3 * 2 = ?\n");
			printf("Montako viilia jaakaapissa on?\n");

			fflush(stdin);
			scanf("%d", &harjVastaus);

			if (harjVastaus == 6)
			{
				printf("Vastauksesi %d on oikein! Hyvin tehty!\n", harjVastaus);

				system("pause");
			}

			else
			{
				printf("Vastauksesi %d on vaarin. Yrita uudelleen!\n", harjVastaus);
				printf("(Vihje: Muuta laskutoimitus summamuotoon)\n");

				system("pause");
			}
		} while (harjVastaus != 6);
	}

	else
	{
		printf("Palataan valikkoon.");

		system("pause");
	}
}


void osamaaraTeoria(void)
{
	char vastaus;
	int harjVastaus;

	printf("Osamaara- eli jakolaskun tarkoituksena on jakaa ensimmaisena annettu luku sita seuraavalla luvulla.\n");
	printf("Esimerkiksi luvun kuusi (6) jakaminen kolmella (3) voitaisiin merkita 6 / 3 = 2.\n");
	printf("Jakolasku onkin kertolaskun vastakohta eli jos luku kaksi (2) kerrotaan (*) luvulla kolme (3) ja jaetaan (/) sen jalkeen luvulla kolme (3) saadaan taas alkuperainen luku kaksi (2)\n");
	printf("Eli numeroin 2 * 3 / 3 = 2.\n");
	printf("Esimerkki: Sinulla on kuusi karkkia. Ilkea Janne syo karkeista puolet. Kuinka monta karkkia sinulle jaa?\n");
	printf("Sama voidaan kirjoittaa lukuarvoin eli numeroin.\n");
	printf("Kuudesta (6) karkistasi ilkea Janne syo puolet (/2)\n");
	printf("Eli 6/2 = ?\n");
	printf("Nain ollen sinulle jaa kolme (3) karkkia eli 6/2 = 3.\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");

	fflush(stdin);
	scanf("%c", &vastaus);

	system("cls");

	if (vastaus == 'k' || vastaus == 'K')
	{
		do
		{
			printf("aidilla on yhdeksan euroa rahaa. Rahat jaetaan tasan Matille, Tepolle ja Sepolle.\n");
			printf("Eli 9 / 3 = ?\n");
			printf("Kuinka paljon kukin heista saa rahaa?\n");

			fflush(stdin);
			scanf("%d", &harjVastaus);

			if (harjVastaus == 3)
			{
				printf("Vastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);

				system("pause");
			}

			else
			{
				printf("Vastauksesi %d oli vaarin. Yrita uudelleen!\n", harjVastaus);
				printf("(Vihje: Monellako luku kolme (henkiloiden lukumaara) pitaa kertoa, jotta rahaa olisi yhteensa 9e)\n");
				system("pause");
			}
		} while (harjVastaus != 3);
	}

	else
	{
		printf("Palataan valikkoon.");

		system("pause");
	}
}


void peruskoulu(void)
{
	system("cls");

	int i = 0, k, kysymysmaara = 0, x, eka, toka, tulos, vastaus = 0, nimi, tarkastus = 0, z = 1;
	FILE *taulu, *pnimi;
	float pisteet = 0;

	srand(time(NULL));

	printf("Lopeta luvulla (-100)\n");
	printf("Tilastoille paasemiseksi pitaa vastata vahintaan 10 kysymykseen.\n");

	typedef struct {
		char nimi[20];
		int k_maara;
		int o_vastaus;
		float prossa;
	}TOP;

	TOP Top[10];
	TOP Nyk;

	for (i = 0; i < 10; i++) //pistetaulukon alustus
	{
		strcpy(Top[i].nimi, "tyhja");
		Top[i].k_maara = 10;
		Top[i].o_vastaus = 0;
		Top[i].prossa = 0;
	}

	taulu = fopen("perus.txt", "r+");

	if (taulu == NULL)
	{
		taulu = fopen("perus.txt", "w");

		for (i = 0; i < 10; i++)
		{
			fprintf(taulu, "%s, %d, %d, %.f\n", Top[i].nimi, Top[i].k_maara, Top[i].o_vastaus, Top[i].prossa);
		}
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			taulu = fopen("perus.txt", "r");
			fscanf(taulu, "%s, %d, %d, %.f\n", &Top[i].nimi, &Top[i].k_maara, &Top[i].o_vastaus, &Top[i].prossa);
		}
	}

	pnimi = fopen("tulos.txt", "r");
	fscanf(pnimi, "%s", &Nyk.nimi);
	fclose(pnimi);

	do
	{
		x = rand() % 3; //arpoo numeron valilla 0-1

		if (x == 0) //plus lasku
		{
			kysymysmaara++;

			eka = rand() % 101;
			toka = rand() % 101;

			tulos = eka + toka;

			printf("\n\nMika on seuraavan laskun tulos:\n%d + %d = ?\n", eka, toka);

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((helppo_2))\n paina ENTER"); //virhekoodi (helppo_2)

				fflush(stdin);
				getchar();
			}
		}

		else if (x == 1) //miinus lasku
		{
			eka = rand() % 101;
			toka = rand() % 101;

			tulos = eka - toka;

			if (tulos >= 0)
			{
				printf("Mika on seuraavan laskun tulos:\n%d - %d = ?\n", eka, toka);

				fflush(stdin);
				scanf("%d", &vastaus);

				if (vastaus == tulos)
				{
					printf("\noikein\n\n\n");
					pisteet++; //oikea vastaus niin lisataan piste
				}

				else if (vastaus != tulos)
				{
					printf("\nvaarin\n\n\n");
				}

				else
				{
					printf("tapahtui virhe! ((helppo_2))\n paina ENTER"); //virhekoodi (helppo_3)

					fflush(stdin);
					getchar();
				}
				kysymysmaara++;
			}

			else
			{
			}
		}

		else if (x == 2) //kerto lasku
		{
			eka = rand() % 11;
			toka = rand() % 11;

			tulos = eka * toka;

			printf("Mika on seuraavan laskun tulos:\n%d x %d = ?\n", eka, toka); //x kertomerkkina koska * saattaa aiheuttaa onglemia

			fflush(stdin);
			scanf("%d", &vastaus);

			if (vastaus == tulos)
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}

			else if (vastaus != tulos)
			{
				printf("\nvaarin\n\n\n");
			}

			else
			{
				printf("tapahtui virhe! ((vaikea_4))\n paina ENTER"); //virhekoodi (vaikea_4)

				fflush(stdin);
				getchar();
			}
			kysymysmaara++;
		}
	} while (vastaus != -100);

	if (kysymysmaara > 9)
	{
		Nyk.k_maara = kysymysmaara - 1;
		Nyk.o_vastaus = pisteet;
		Nyk.prossa = (pisteet / (kysymysmaara - 1));

		do
		{
			for (i = 0; i < 10 && tarkastus == 0; i++)
			{
				if (Nyk.prossa > Top[i].prossa)
				{
					do
					{
						for (k = (10 - i); k > 0; k--) //laita välimuuttuja
						{
							strcpy(Top[i + z].nimi, Top[i + (z + 1)].nimi);
							Top[i + z].k_maara = Top[i + (z + 1)].k_maara;
							Top[i + z].o_vastaus = Top[i + (z + 1)].o_vastaus;
							Top[i + z].prossa = Top[i + (z + 1)].prossa;
							z++;
						}
						strcpy(Top[i].nimi, Nyk.nimi);
						Top[i].k_maara = Nyk.k_maara;
						Top[i].o_vastaus = Nyk.o_vastaus;
						Top[i].prossa = Nyk.prossa;

						tarkastus++;
					} while (tarkastus == 0);
				}
				else
				{
				}
			}
		} while (tarkastus == 0 && i != 10);

		

		if (tarkastus == 1)
		{
			for (z = 0; z < 1; z++)
			{
				taulu = fopen("perus", "w");

				for (i = 0; i < 10; i++)
				{
					fprintf(taulu, "%s, %d, %d, %.f\n", Top[i].nimi, Top[i].k_maara, Top[i].o_vastaus, Top[i].prossa);
				}

				fclose(taulu);
				printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
				printf("Pääsit parhaimmiston joukkoon!!! Onneksi olkoon!\n");
				system("PAUSE");
			}
		}

		else if (tarkastus == 0 && i == 10)
		{
			printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
			printf("Valitettavasti pisteesi eivat riita tilastoille paasemiseksi. :(\n");
			printf("Parempi onni ensi kerralla!!\n");
			system("PAUSE");
		}
	}

	else if (kysymysmaara < 10)
	{
		printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
		printf("Vastasit alle 10:neen kysymykseen, joten pisteitäsi ei tallenneta\n");
		system("PAUSE");
	}
	else
	{
		printf("tapahtui jotain kummaa");
	}
}


void tulostaja(int *pKysymyksenNumero, int *pKokonaismaara, int *pLaskutyyppi, int *pEka, int *pToka, int *pOikeaVastaus, int *pAnnettuVastaus, int *pOikeatVastaukset)
{

	FILE *pTiedosto;

	pTiedosto = fopen("tulos.txt", "a+");

	if (pTiedosto != NULL)
	{
		fprintf(pTiedosto, "Kysymys %d/%d\n", *pKysymyksenNumero + 1, *pKokonaismaara);

		if (*pLaskutyyppi == 0)
		{
			fprintf(pTiedosto, "%d + %d = ?\n", *pEka, *pToka);
		}

		else if (*pLaskutyyppi == 1)
		{
			fprintf(pTiedosto, "%d - %d = ?\n", *pEka, *pToka);
		}

		else if (*pLaskutyyppi == 2)
		{
			fprintf(pTiedosto, "%d * %d = ?\n", *pEka, *pToka);
		}

		else if (*pLaskutyyppi == 3)
		{
			fprintf(pTiedosto, "%d / %d = ?\n", *pEka, *pToka);
		}

		else
		{
			printf("Tapahtui virhe\n");
		}

		if (*pAnnettuVastaus == *pOikeaVastaus)
		{
			fprintf(pTiedosto, "Antamasi vastaus oli %d. Vastaus oli oikein.\n\n", *pAnnettuVastaus);
		}

		else
		{
			fprintf(pTiedosto, "Antamasi vastaus oli %d. Vastaus oli vaarin.\n\n", *pAnnettuVastaus);
		}

		if (*pKysymyksenNumero + 1 == *pKokonaismaara)
		{
			fprintf(pTiedosto, "Oikeita vastauksia oli %d kokonaismaarasta %d", *pOikeatVastaukset, *pKokonaismaara);
		}
		fclose(pTiedosto);
	}
}


void nimi(char *pNimiTaulu)
{
	FILE *pTiedosto;

	pTiedosto = fopen("tulos.txt", "w");

	fprintf(pTiedosto, "%s\n\n", pNimiTaulu);

	fclose(pTiedosto);
}
