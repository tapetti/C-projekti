// stdafx.cpp : source file that includes just the standard includes
// C-projekti.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information


#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
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
void tuloste (void);
void edellinen(void);


int _tmain(int argc, _TCHAR* argv[])
{
	int valintaValikko = 0;
	char nimiTaulu[15];
	char valintaTaso;

	do  //Kunnes valinta on 5 (exit)
	{
		int n = 0;
		system("cls");
		printf("Game Of Superduper\n\n");
		printf("1. Aloita peli\n");
		printf("2. Ohjeet\n");
		printf("3. Peruskoulutason top-10\n");
		printf("4. Tulosta edellisen pelin tilasto\n");
		printf("5. Poistu pelista\n\n");
		printf("© Janne Kari & Tarmo Merimaa (2014)\n");


		fflush(stdin);			//Tyhjennetaan puskuri
		scanf("%d", &valintaValikko); //Valinta

		system("cls");		//Tyhjennetaan naytto


		if (valintaValikko == 1)  //Jos valinta on 1
		{
			printf("Anna nimesi:\n");

			fflush(stdin);	//Puskurin tyhjennys
			while ((nimiTaulu[n] = getchar()) != '\n')	//Nimen tallennus
			{
				n++;
			}


			nimiTaulu[n] = '\0';	//NULL-termination getcharia varten
			nimi(nimiTaulu);		//Kutsutaan funktiota


			printf("Helppo, keskivaikea, vaikea vai peruskoulutaso? (H, K, V, P)\n");


			fflush(stdin);		//Tyhjennetaan puskuri
			scanf("%c", &valintaTaso); //Valinta


			if (valintaTaso == 'h' || valintaTaso == 'H') //Jos helppo
			{
				helppo(); //Kutsutaan helppo-funktitoa
			}


			else if (valintaTaso == 'k' || valintaTaso == 'K') //Jos keskivaikea
			{
				keskivaikea(); //Kutsutaan keskivaikea-funktiota
			}


			else if (valintaTaso == 'v' || valintaTaso == 'V') //Jos vaikea
			{
				vaikea(); //Kutsutaan vaikea-funktiota
			}


			else if (valintaTaso == 'p' || valintaTaso == 'P') //Jos peruskoulu
			{
				peruskoulu(); //Kutsutaan peruskoulu-funktiota
			}


			else //Jos valinta on jotain muuta
			{
				printf("Valintasi oli virheellinen!");
				system("PAUSE");
			}
		}

		else if (valintaValikko == 2) //Jos valinta on 2
		{
			ohjeet(); //Kutsutaan ohjeet-funktiota
		}

		else if (valintaValikko == 3) //Jos valinta on 3
		{
			tuloste(); //Kutsutaan tuloste-funktiota
		}

		else if (valintaValikko == 4) //Jos valinta on 4
		{
			edellinen(); //Kutsutaan edellinen-funktiota
		}

	} while (valintaValikko != 5);	//Looppi jatkuu kunnes valinta on 5 (exit)


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


	int kysymysMaara, i, x, pisteet = 0, eka, toka, tulos, vastaus, jako_tulos_kokonaisluku;
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


			jako_tulos = ((float)eka) / toka;
			jako_tulos_kokonaisluku = jako_tulos + 0.5;

			printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n%d / %d = ?\n", eka, toka); //x kertomerkkina koska * saattaa aiheuttaa onglemia


			fflush(stdin);
			scanf("%d", &vastaus);


			if ((vastaus > jako_tulos_kokonaisluku - 1) && (vastaus < jako_tulos_kokonaisluku + 1))
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}


			else if (vastaus != jako_tulos_kokonaisluku)
			{
				printf("\nvaarin\n\n\n");
			}


			else
			{
				printf("tapahtui virhe! ((keski_5))\n paina ENTER"); //virhekoodi (keski_5)


				fflush(stdin);
				getchar();
			}


			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &jako_tulos_kokonaisluku, &vastaus, &pisteet);
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

	int kerto_vastaus, jako_vastaus, jako_tulos_kokonaisluku, kerto_tulos_kokonaisluku;
	float jako_tulos, kerto_tulos;


	srand(time(NULL));


	printf("Monta kysymysta haluat etta sinulta kysytaan?\n");


	fflush(stdin);
	scanf("%d", &kysymysMaara);


	for (i = 0; i < kysymysMaara; i++) //vetaa setin lapi niin monta kertaa ku kayttaja haluu
	{
		x = rand() % 4; //arpoo numeron valilla 0-3
		x = 2;

		if (x == 0) //plus lasku
		{
			x = 4;

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
				x = 5;

				eka = rand() % 100;
				toka = rand() % 100;


				printf("Mika on seuraavan laskun tulos:\n%d - ? = %d\n", eka, toka);


				fflush(stdin);
				scanf("%d", &vastaus);


				tulos = eka - toka;


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
				x = 6;

				int vahennettava;

				eka = rand() % 50;
				toka = rand() % 100;


				vahennettava = rand() % 40;


				toka = toka - vahennettava;


				printf("Mika on seuraavan laskun tulos:\n? - %d = %d\n", eka, toka);


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
			x = 7;

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


			kerto_tulos = ((float)toka) / eka;
			kerto_tulos_kokonaisluku = kerto_tulos + 0.5;


			if ((vastaus < kerto_tulos_kokonaisluku + 1) && (vastaus > kerto_tulos_kokonaisluku - 1))
			{
				printf("\noikein\n\n\n");
				pisteet++; //oikea vastaus niin lisataan piste
			}


			else if (vastaus != kerto_tulos_kokonaisluku)
			{
				printf("\nvaarin\n\n\n");
			}


			else
			{
				printf("tapahtui virhe! ((vaikea_4))\n paina ENTER"); //virhekoodi (vaikea_4)


				fflush(stdin);
				getchar();
			}

			tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &kerto_tulos_kokonaisluku, &vastaus, &pisteet);
		}


		else if (x == 3) //jako lasku
		{
			x = rand() % 2;


			if (x == 0) //jakaja
			{
				x = 8;

				eka = rand() % 100;
				toka = rand() % 10;


				while (eka < 10)
				{
					eka = rand() % 100;
				}

				while (toka == 0)
				{
					toka = rand() % 10;
				}

				printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n%d / ? = %d\n", eka, toka);


				fflush(stdin);
				scanf("%d", &vastaus);


				jako_tulos = ((float)eka) / toka;
				jako_tulos_kokonaisluku = jako_tulos + 0.5;

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


				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &jako_tulos_kokonaisluku, &vastaus, &pisteet);
			}


			else if (x == 1) //jakaja
			{
				x = 9;


				eka = rand() % 10;
				toka = rand() % 100;

				while (eka == 0)
				{
					eka = rand() % 10;
				}

				while (toka < 10)
				{
					toka = rand() % 100;
				}
					

				printf("Mika on seuraavan laskun tulos (pyorista kokonaislukuun):\n? / %d = %d\n", eka, toka);


				fflush(stdin);
				scanf("%d", &vastaus);


				jako_tulos_kokonaisluku = eka * toka;


				if ((vastaus > jako_tulos_kokonaisluku - 1) && (vastaus < jako_tulos_kokonaisluku + 1))
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


				tulostaja(&i, &kysymysMaara, &x, &eka, &toka, &jako_tulos_kokonaisluku, &vastaus, &pisteet);
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
	system("cls");		//Tyhjennetaan naytto

	char vastaus;
	int teoriaVastaus;

	printf("Pelin tarkoituksena on opettaa sen pelaajaa laskemaan erilaisia\nlaskutoimituksia.\n\n");
	printf("Peli sisaltaa kolme eri vaikeusastetta: helpon, keskivaikean seka vaikean.\n");
	printf("\tHelppo: plus- ja miinuslaskuja arvoilla valilta 0-100.\n");
	printf("\tKeskivaikea: plus- ja miinuslaskut seka kerto- ja jakolaskut\n\tvalilta 0-10.\n");
	printf("\tVaikea: taydennystehtavia jokaisesta laskutoimituksesta valilta 0-10.\n\n");
	printf("Aluksi peli kysyy pelaajan nimen seka kuinka monta kysymysta pelaaja haluaa.\n");
	printf("Peli antaa aina yhden kysymyksen kerrallaan ja odottaa pelaajan vastausta.\n");
	printf("Vastauksen jalkeen peli ilmoittaa, oliko vastaus oikein vai vaarin seka\nantaa seuraavan kysymyksen.\n\n");
	printf("Kun pelaajan antama maara kysymyksia on kayty lapi, ilmoittaa peli oikeiden\nvastausten maaran.\n\n");
	printf("Alun valikosta voit tarkistaa omat pistemaarasi aikaisempien pelien osalta.\n\n");
	printf("Haluatko lukea teoriaa jostakin laskutoimituksesta? (k/e)\n");


	fflush(stdin);		//Tyhjennetaan puskuri
	scanf("%c", &vastaus);	//Otetaan vastaus


	if (vastaus == 'k' || vastaus == 'K')		//Vastauksen ollessa kylla
	{
		system("cls");	//Tyhjennetaan naytto


		printf("Mista laskutoimituksesta haluaisit lisatietoa?\n");
		printf("1. Summa eli pluslaskut\n");
		printf("2. Erotus eli miinuslaskut\n");
		printf("3. Tulo eli kertolaskut\n");
		printf("4. Osamaara eli jakolaskut\n");


		fflush(stdin);		//Tyhjennetaan puskuri
		scanf("%d", &teoriaVastaus);	//Otetaan vastaus


		if (teoriaVastaus == 1) //Jos vastaus 1
		{
			system("cls");
			summaTeoria();	//Kutsutaan summaTeoria funktiota
		}


		else if (teoriaVastaus == 2) //Jos vastaus 2
		{
			system("cls");
			erotusTeoria();	//Kutsutaan erotusTeoria funktiota
		}


		else if (teoriaVastaus == 3) //Jos vastaus 3
		{
			system("cls");
			tuloTeoria(); //Kutsutaan tuloTeoria funktiota
		}


		else if (teoriaVastaus == 4) //Jos vastaus 4
		{
			system("cls");
			osamaaraTeoria(); //Kutsutaan osamaaraTeoria funktiota
		}


		else //Jos vastaus ei mikaan edella mainituista
		{
			printf("\nValintaa kyseisella numerolla ei ole olemassa.\n");
			system("pause"); //Pysaytetaan ohjelma, kunnes painaa jotain nappainta
		}
	}


	else // Jos vastaus ei mikaan neljasta
	{
		printf("Palataan valikkoon.\n");
		system("pause");
	}
}




void summaTeoria(void)
{
	char vastaus;
	int harjVastaus;


	printf("Summa- eli pluslaskuissa on tarkoituksena lisata yhteen kaksi tai useampi\nannettu arvo.\n\n");
	printf("Esimerkkina: Sinulla on kaksi omenaa. Saat viela kolme omenaa lisaa.\nKuinka monta omenaa sinulla on yhteensa?\n\n");
	printf("Sama kysymys voidaan ilmaista luvuilla.\n");
	printf("Kahteen omenaan (2) lisataan (+) kolme omenaa (3), joten niiden yhteismaara (=) on?\n\n");
	printf("Nain ollen voidaan muodostaa lauseke: 2 + 3 = ?\n");
	printf("Laskemalla yhteen luvut kaksi (2) ja kolme (3) saadaan yhteensa viisi (5)\n");
	printf("Nain ollen vastaus kysymykseen on viisi omenaa\n\n");
	printf("Haluatko tehda harjoitustehtavan? (k/e)\n");


	fflush(stdin);			//Tyhjennetaan puskuri
	scanf("%c", &vastaus); //Otetaan vastaus

	system("cls");		//Tyhjennetaan naytto


	if (vastaus == 'k' || vastaus == 'K')	//Jos kylla
	{
		do //Kunnes vastaus on oikein
		{
			printf("Naet kaksi koiraa. Koirien joukkoon saapuu viela yksi koira.\n");
			printf("Sama numeroin: 2 + 1 = ?\n");
			printf("Montako koiraa naet?\n");


			fflush(stdin); //tyhjennetaan puskuri
			scanf("%d", &harjVastaus); //Otetaan vastaus


			if (harjVastaus == 3) //Jos vastaus on oikein
			{
				printf("\nVastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);
				system("pause");
			}

			else //Jos vastaus on vaarin
			{
				printf("\nVastauksesi %d oli vaarin. Yrita uudelleen!\n", harjVastaus);
				system("pause");
				system("cls");
			}


		} while (harjVastaus != 3); //Looppi pyorii kunnes vastaus on oikein
	}


	else //Jos jotain muuta kuin k(ylla)
	{
		printf("Palataan valikkoon.\n"); //Palataan valikkoon, reaktio nappainta painamalla
		system("pause");
	}
}




void erotusTeoria(void)
{
	char vastaus;
	int harjVastaus;


	printf("Erotus- eli miinuslaskun (tai vahennyslaskun) ideana on vahentaa ensimmaisena\nannetusta luvusta toinen annettu luku.\n\n");
	printf("Esimerkiksi: Kolme varista istuu aidalla. Yksi lahtee pois. Montako varista\njaa aidalle istumaan?\n\n");
	printf("Sama voidaan ilmaista numeroin eli lukuarvoilla\n");
	printf("Kolme varista (3). Variksista lahtee pois (-) yksi. Variksia aidalla\nyhteensa (=) ?\n");
	printf("Eli: 3 - 1 = ?\n\n");
	printf("Vahentamalla luvusta kolme (3) luku yksi (1) saadaan vastaukseksi kaksi (2)\n");
	printf("Eli 3 - 1 = 2\n");
	printf("Vastaus on siis kaksi varista\n\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");


	fflush(stdin);		//Tyhjennetaan puskuri
	scanf("%c", &vastaus);		//Otetaan vastaus

	system("cls");	//Tyhjennetaan naytto


	if (vastaus == 'k' || vastaus == 'K')	//Jos kylla
	{
		do
		{
			printf("Viisi norsua kavelee jonossa. Yksi norsuista lahtee pois jonosta.\n");
			printf("Sama numeroin: 5 - 1 = ?\n");
			printf("Montako norsua on viela jonossa?\n");

			fflush(stdin);			//Tyhjennetaan puskuri
			scanf("%d", &harjVastaus);		//Vastaus


			if (harjVastaus == 4) //Jos vastaus on oikein
			{
				printf("\nVastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);
				system("pause");
			}


			else  //Jos vastaus on vaarin
			{
				printf("\nVastauksesi %d oli vaarin. Yrita uudeleen!\n", harjVastaus);
				system("pause");
				system("cls");
			}
		} while (harjVastaus != 4); //Looppi jatkuu kunnes vastataan oikein
	}


	else //Jos jotain muuta kuin k(ylla)
	{
		printf("Palataan valikkoon.\n");
		system("pause");
	}
}




void tuloTeoria(void)
{
	char vastaus;
	int harjVastaus;


	printf("Tulo- eli kertolaskun tarkoituksena on moninkertaistaa jokin luku.\n\n");
	printf("Esimerkiksi luvun 3 kaksinkertaistaminen voitaisiin merkita 3 * 2 = 6.\n");
	printf("Tama tarkoittaa sita, etta lukuun nolla lisataan ensimmainen luku (eli 3)\nniin monta kertaa kuin kerroin meille nayttaa (tassa tapauksessa 2)\n");
	printf("Nain ollen sama lasku voidaan ajatella muodossa 3 + 3 = 6\n\n");
	printf("Esimerkiksi: Sinulla on kaksi omenaa. Omenoiden maara kolminkertaistetaan.\nKuinka monta omenaa sinulla on lopuksi?\n\n");
	printf("Sama voidaan ilmaista lukuarvoin eli numeroilla.\n");
	printf("Sinulla on kaksi omenaa (2), joiden lukumaara kerrotaan (*) kolmella (3).\nLopuksi sinulla on omenoita (=) ?\n");
	printf("Eli 2 * 3 = ?\n\n");
	printf("Kuten aikaisemmassakin esimerkissa, voidaan laskutoimitus muuttaa myos\nsummamuotoon.\n");
	printf("Eli 2 + 2 + 2 = ?\n");
	printf("Nain ollen vastaukseksi saadaan kuusi (6) omenaa.\n\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");


	fflush(stdin);			//Tyhjennetaan puskuri
	scanf("%c", &vastaus);	//Vastaus
	
	system("cls");		//Tyhjennetaan naytto
	
	if (vastaus == 'k' || vastaus == 'K')	//Jos kylla
	{
		do //Kunnes vastaus on oikein
		{
			printf("Jaakaapissa on kolme viilia. Kun katsot jaakaappiin uudelleen, huomaat,\netta viilien maara on kaksinkertaistunut.\n");
			printf("Eli 3 * 2 = ?\n");
			printf("Montako viilia jaakaapissa on?\n");

			fflush(stdin);				//Tyhjennetaan puskuri
			scanf("%d", &harjVastaus);	//Vastaus


			if (harjVastaus == 6)		//Jos oikein
			{
				printf("\nVastauksesi %d on oikein! Hyvin tehty!\n", harjVastaus);
				system("pause");
			}

			else //Muussa tapauksessa
			{
				printf("\nVastauksesi %d on vaarin. Yrita uudelleen!\n", harjVastaus);
				printf("(Vihje: Muuta laskutoimitus summamuotoon)\n");
				system("pause");
				system("cls");
			}
		} while (harjVastaus != 6);		//Looppi jatkuu, kunnes vastaus on oikein
	}


	else //Jos ei halua harjoituskysymysta
	{
		printf("Palataan valikkoon.\n");
		system("pause");
	}
}




void osamaaraTeoria(void)
{
	char vastaus;
	int harjVastaus;


	printf("Osamaara- eli jakolaskun tarkoituksena on jakaa ensimmaisena annettu luku\nsita seuraavalla luvulla.\n\n");
	printf("Esimerkiksi luvun kuusi (6) jakaminen kolmella (3) voitaisiin\nmerkita 6 / 3 = 2.\n\n");
	printf("Jakolasku onkin kertolaskun vastakohta eli jos luku kaksi (2) kerrotaan (*)\nluvulla kolme (3) ja jaetaan (/) sen jalkeen luvulla kolme (3) saadaan taas\nalkuperainen luku kaksi (2)\n");
	printf("Eli numeroin 2 * 3 / 3 = 2.\n\n");
	printf("Esimerkki: Sinulla on kuusi karkkia. Ilkea Janne syo karkeista puolet.\nKuinka monta karkkia sinulle jaa?\n\n");
	printf("Sama voidaan kirjoittaa lukuarvoin eli numeroin.\n");
	printf("Kuudesta (6) karkistasi ilkea Janne syo puolet (/2)\n");
	printf("Eli 6/2 = ?\n");
	printf("Nain ollen sinulle jaa kolme (3) karkkia eli 6/2 = 3.\n\n");
	printf("Haluatko harjoitustehtavan? (k/e)\n");


	fflush(stdin);			//Tyhjennetaan puskuri
	scanf("%c", &vastaus);	//Vastaus

	system("cls");		//Tyhjennetaan naytto


	if (vastaus == 'k' || vastaus == 'K')	//Jos kylla
	{
		do
		{
			printf("Aidilla on yhdeksan euroa rahaa. Rahat jaetaan tasan Matille, Tepolle\nja Sepolle.\n");
			printf("Eli 9 / 3 = ?\n");
			printf("Kuinka paljon kukin heista saa rahaa?\n");

			fflush(stdin);			//Tyhjennetaan puskuri
			scanf("%d", &harjVastaus);	//Vastaus


			if (harjVastaus == 3)	//Jos vastaus on oikein
			{
				printf("\nVastauksesi %d oli oikein! Hyvin tehty!\n", harjVastaus);
				system("pause");
			}


			else  //Jos vastaus on vaarin
			{
				printf("\nVastauksesi %d oli vaarin. Yrita uudelleen!\n", harjVastaus);
				printf("(Vihje: Monellako luku kolme (henkiloiden lukumaara) pitaa kertoa, jotta\nrahaa olisi yhteensa 9e)\n");
				system("pause");
				system("cls");
			}
		} while (harjVastaus != 3); //Looppi jatkuu kunnes vastaus on oikein
	}


	else //Jos ei halua kysymyksia
	{
		printf("Palataan valikkoon.\n");
		system("pause");
	}
}

void peruskoulu(void) //peruskoululaisille sopivia laskuja
{
	system("cls");

	int i = 0, k, pisteet=0, kysymysmaara = 0, x, eka, toka, tulos, vastaus = 0, nimi, tarkastus = 0, z = 0; //alustetaan kaikki tarvittavat
	FILE *taulu, *pnimi; //pari filu pointteria

	srand(time(NULL)); //randomin alustus

	printf("Lopeta luvulla (-100)\n");
	printf("Tilastoille paasemiseksi pitaa vastata vahintaan 10 kysymykseen.\n"); //vaaditaan minimi kysymysmäärä jotta vastaamalla yhteen ei pääse kärkeen

	typedef struct { //kaiken perusta eli käytettävä struktuuri
		char nimi[20];
		int k_maara;
		int o_vastaus;
		float prossa;
	}TOP;

	TOP Top[10]; //tehdään 10 tollasta koska tilastot pitää 10 yllä
	TOP Nyk; // käytössä olevalle oma jotta voidaan verrata tilastoihin

	for (i = 0; i < 10; i++) //pistetaulukon alustus
	{
		strcpy(Top[i].nimi, "tyhja");
		Top[i].k_maara = 10;
		Top[i].o_vastaus = 0;
		Top[i].prossa = 0;
	}

	taulu = fopen("perus.txt", "r"); //avataan tiedosto

	if (taulu == NULL) //jos ei ole olemassa niin tehdään 0% pohjustus
	{
		taulu = fopen("perus.txt", "w");

		for (i = 0; i < 10; i++)
		{
			fprintf(taulu, "%s %d %d %.f\n", Top[i].nimi, Top[i].k_maara, Top[i].o_vastaus, Top[i].prossa);
		}
		fclose(taulu);
	}
	else //jos on olemassa niin luetaan muistiin nykyiset top pelaajat
	{
		for (i = 0; i < 10; i++)
		{
			fscanf(taulu, "%s %d %d %f", &Top[i].nimi, &Top[i].k_maara, &Top[i].o_vastaus, &Top[i].prossa);
		}
		fclose(taulu);
	}
	pnimi = fopen("tulos.txt", "r"); //haetaan nimi joka on tallennettu tiedostoon
	fscanf(pnimi, "%s", &Nyk.nimi);
	fclose(pnimi);

	do //aloitetaan peli ja pelataan kunnes saadaan -100 luku käyttäjältä
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
			tulostaja(&kysymysmaara, &kysymysmaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
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
				tulostaja(&i, &kysymysmaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
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
			tulostaja(&i, &kysymysmaara, &x, &eka, &toka, &tulos, &vastaus, &pisteet);
		}
	} while (vastaus != -100); //kun saadaan -100 niin lopetetaan

	if (kysymysmaara > 9) //vaaditaan vähintään 10 kysymystä jotta pääsisi tilastoille
	{
		//kopioidaan tulokset structuuriin josta niitä on helpompi käsitellä
		Nyk.k_maara = kysymysmaara - 1;
		Nyk.o_vastaus = pisteet;
		Nyk.prossa = ((float)pisteet / (kysymysmaara - 1));
		Nyk.prossa = Nyk.prossa * 100;

		do //alkaa käymään läpi taulukkoa
		{
			for (i = 0; i < 10 && tarkastus == 0; i++) //tätä toistetaan joko 10 kertaa jolloin kaikki on käyty läpi tai kun on sijoitettu top listaan
			{
				if (Nyk.prossa > Top[i].prossa) //vertailu
				{
					for (k = i; k < 10; k++) //tämä kopioi kaikki loput yhden alaspäin
						{
							strcpy(Top[9-z].nimi, Top[9-z-1].nimi);
							Top[9-z].k_maara = Top[9-z-1].k_maara;
							Top[9-z].prossa = Top[9-z-1].prossa;
							Top[9-z].o_vastaus = Top[9-z-1].o_vastaus;
							z++;
						}
						strcpy(Top[i].nimi, Nyk.nimi); // tässä kopioidaan pelaajan tilastot oikealle paikalle
						Top[i].k_maara = Nyk.k_maara;
						Top[i].o_vastaus = Nyk.o_vastaus;
						Top[i].prossa = Nyk.prossa;

						tarkastus++; //checksum kondikseen jotta ei jäädä loppiin
				}
				else //ihan vaan varmuudeksi varmistamassa virheiden varalta
				{
				}
			}
		} while (tarkastus == 0 && i != 10); //joko pojot ei riittänyt tilastoihin tai sitten ollaan jo sijoitettu pelaaja top listaan

		if (tarkastus == 1) //jos pelaaja pääsi top listaan niin tarkastus on 1 ja kerrotaan se hänelle
		{
				taulu = fopen("perus.txt", "w");
				z = i + 1;
				for (i = 0; i < 10; i++)
				{
					fprintf(taulu, "%s %d %d %.f\n", Top[i].nimi, Top[i].k_maara, Top[i].o_vastaus, Top[i].prossa); //tallennetaan päivitetyt tilastot
				}

				fclose(taulu);
				printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
				printf("Paasit parhaimmiston joukkoon!!! Onneksi olkoon!\n");
				printf("Olet %d paras pelaaja\n", z);
				system("PAUSE");
		}

		else if (tarkastus == 0 && i == 10) //taulukko käyty läpi ja pisteet ei riittänyt tilastoihin
		{
			printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
			printf("Valitettavasti pisteesi eivat riita tilastoille paasemiseksi. :(\n");
			printf("Parempi onni ensi kerralla!!\n");
			system("PAUSE");
		}
	}

	else if (kysymysmaara < 10) //jos vastasi alle 10 kysymykseen
	{
		printf("Pisteesi on %d / %d\n", pisteet, kysymysmaara - 1);
		printf("Vastasit alle 10:neen kysymykseen, joten pisteitasi ei tallenneta\n");
		system("PAUSE");
	}
	else
	{
		printf("tapahtui jotain kummaa"); //ihan vaan kaiken varalta
	}
	fflush(stdin); //jotta ei kävisi mitään hassua
}

void tulostaja(int *pKysymyksenNumero, int *pKokonaismaara, int *pLaskutyyppi, int *pEka, int *pToka, int *pOikeaVastaus, int *pAnnettuVastaus, int *pOikeatVastaukset)
{

	FILE *pTiedosto;		//Osoitin tiedostoon
	
	pTiedosto = fopen("tulos.txt", "a+");	//Avataan tiedosto lisäystä varten (append)
	
	if (pTiedosto != NULL)	//Jos tiedoston avaaminen onnistuu
	{
		
		fprintf(pTiedosto, "Kysymys %d/%d\n", *pKysymyksenNumero + 1, *pKokonaismaara);
		//Tulostetaan kysymyksen numero
		
		if (*pLaskutyyppi == 0)	//Normaalit pluslaskut
		{
			fprintf(pTiedosto, "%d + %d = ?\n", *pEka, *pToka);
		}

		
		else if (*pLaskutyyppi == 1) //Normaali miinus
		{
			fprintf(pTiedosto, "%d - %d = ?\n", *pEka, *pToka);
		}

		
		else if (*pLaskutyyppi == 2) //Normaali kerto
		{
			fprintf(pTiedosto, "%d * %d = ?\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 3) //Normaali jako
		{
			fprintf(pTiedosto, "%d / %d = ?\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 4) //Vaikea plus
		{
			fprintf(pTiedosto, "%d + ? = %d\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 5) //Vaikea miinus #1
		{
			fprintf(pTiedosto, "%d - ? = %d\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 6) //Vaikea miinus #2
		{
			fprintf(pTiedosto, "? - %d = %d\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 7) //Vaikea kerto
		{
			fprintf(pTiedosto, "%d * ? = %d\n", *pEka, *pToka);
		}

		
		else if (*pLaskutyyppi == 8) //Vaikea jako #1
		{
			fprintf(pTiedosto, "%d / ? = %d\n", *pEka, *pToka);
		}


		else if (*pLaskutyyppi == 9) //Vaikea jako #2
		{
			fprintf(pTiedosto, "? / %d = %d\n", *pEka, *pToka);
		}


		else
		{
			printf("Tapahtui virhe\n");
		}


		if (*pAnnettuVastaus == *pOikeaVastaus) //Jos vastaus on oikein, tulostetaan se tiedostoon
		{
			fprintf(pTiedosto, "Antamasi vastaus oli %d. Vastaus oli oikein.\n\n", *pAnnettuVastaus);
		}


		else  //Muuten tulostetaan vaarin
		{
			fprintf(pTiedosto, "Antamasi vastaus oli %d. Vastaus oli vaarin.\n\n", *pAnnettuVastaus);
		}


		if (*pKysymyksenNumero + 1 == *pKokonaismaara) //Jos kysymysmaara tulee tayteen
		{
			fprintf(pTiedosto, "Oikeita vastauksia oli %d kokonaismaarasta %d", *pOikeatVastaukset, *pKokonaismaara);
		}
		fclose(pTiedosto);		//Suljetaan tiedosto
	}
}


void tuloste (void)
{

    FILE *pTiedosto;		//osoitin tiedostoon

    int i = 0;			//indeksi looppia varten

	char muuttuja;
	
    pTiedosto = fopen("perus.txt", "r");		//Avataan tiedosto

	printf("Nimi, kysymysmaara, oikeat pisteet, oikeellisuusprosentti\n\n");

    while ((muuttuja = fgetc(pTiedosto)) != EOF)		//Merkki kerrallaan, kunnes tiedoston loppu
	{
		printf("%c", muuttuja);		//Tulostetaan merkki kerrallaan
	}

    fclose (pTiedosto);		//Suljetaan tiedosto
	system("pause");
}



void nimi(char *pNimiTaulu)
{
	FILE *pTiedosto;		//Osoitin tiedostoon, avataan se

	pTiedosto = fopen("tulos.txt", "w");	//Write, jotta aiemmat tulokset poistuisivat

	fprintf(pTiedosto, "%s\n\n", pNimiTaulu);	//Tulostetaan nimi tiedostoon
	
	fclose(pTiedosto);
}


void edellinen(void)
{
	FILE *pTiedosto;		//Osoitin tiedostoon
	
	char muuttuja;
	
	pTiedosto = fopen("tulos.txt", "r");	//Avataan tiedosto lukemista varten

	while((muuttuja = fgetc(pTiedosto)) != EOF) //Luetaan merkki kerrallaan tiedostosta
	{
		printf("%c", muuttuja);			//Tulostetaan merkki kerrallaan
	}

	printf("\n\n");			
	fclose(pTiedosto);		//Suljetaan tiedosto

	system("pause");
}
