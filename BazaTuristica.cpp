#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

struct Unitati
{                                          ///var pentru unit []
	char cod[20];
	char nume[20];
	char tip;
	int confort;
	int nrCamere;
	float pretTot;
}unit[20];

struct Camere
{                                       ///Var pentru cam []
	char cod[20];        /// codul camerei
	char codU[20];      /// codul unitatii
	int np;            /// nr paturilor
	float pret;       ///
	bool tf;         /// telefon
	bool tv;        /// Televizor
}cam[20];

struct Turist
{                                    /// var pentru t[]
	char cod[20]; ///codul turistului
	char nume[20];
	char prenume[20];

	char seriaB[20];      ///Seria buletinului
	int nb;              ///Nr buletinului

	int zc;    /// ziua cazarii
	int lc;   /// luna cazarii
	int ac;  /// anul cazarii

	int zp;     /// ziua plecarii
	int lp;    /// luna plecarii
	int ap;   ///anul precarii

	char codC[20];  /// codul camerei
}t[20];

void addTurist()                   /// 1) Inregistreaza turistul
{
    cout<<endl;                        ///afisarea in consola
	cout<<"Codul turistului : ";
	cin>>t[0].cod;
	cout<<"Numele turistului : ";
	cin>>t[0].nume;
	cout<<"Prenume turistului : ";
	cin>>t[0].prenume;

	cout<<"Seria buletinului : ";
	cin>>t[0].seriaB;
	cout<<"Numarul buletinului : ";
	cin>>t[0].nb;

	cout<<"Ziua cazarii : ";
	cin>>t[0].zc;
	cout<<"Luna cazarii : ";
	cin>>t[0].lc;
	cout<<"Anul cazarii : ";
	cin>>t[0].ac;

	cout<<"Ziua plecarii : ";
	cin>>t[0].zp;
	cout<<"Luna plecarii : ";
	cin>>t[0].lp;
	cout<<"Anul plecarii : ";
	cin>>t[0].ap;

	cout<<"Codul camerei : ";
	cin>>t[0].codC;

	ofstream f("Turisti.txt",ios::app);      /// afisarea in fisier

	f<<t[0].cod<<" ";
	f<<t[0].nume<<" ";
	f<<t[0].prenume<<" ";
	f<<t[0].seriaB<<" ";
	f<<t[0].nb<<" ";
	f<<t[0].zc<<" ";
	f<<t[0].lc<<" ";
	f<<t[0].ac<<" ";
	f<<t[0].zp<<" ";
	f<<t[0].lp<<" ";
	f<<t[0].ap<<" ";
	f<<t[0].codC<<endl;
	cout<<endl;

	f.close();
}

void deleteEx()                  /// 2) Scoate de la evidenta
{
	ifstream f("Turisti.txt");
	int n=0;
	while(!f.eof())
	{
		n++;                   /// citirea din fisier
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
	}

	int zi,luna,an;             /// date care se afiseaza in consola
	cout<<endl;
	cout<<"Introduceti data de azi : (zi luna an)";
	cin>>zi;
	cin>>luna;
	cin>>an;

	ofstream g("Turisti.txt");   /// pentru a scoate de la evidenta un turist cu autorul datei

	for(int i=1;i<n;i++)
	{
		int auxzi=t[i].zp-zi;
		int auxluna=t[i].lp-luna;
		int auxan=t[i].ap-an;
		if(auxan>=0)
		{
			if(auxluna>=0)
			{
				if(auxzi>=0)
				{
					g<<t[i].cod<<" ";       /// citirea din fisier
					g<<t[i].nume<<" ";
					g<<t[i].prenume<<" ";
					g<<t[i].seriaB<<" ";
					g<<t[i].nb<<" ";
					g<<t[i].zc<<" ";
					g<<t[i].lc<<" ";
					g<<t[i].ac<<" ";
					g<<t[i].zp<<" ";
					g<<t[i].lp<<" ";
					g<<t[i].ap<<" ";
					g<<t[i].codC<<endl;
				}
			}
		}
	}
}

void updateCazare()           /// 3) Prelungeste cazarea
{
	ifstream f("Turisti.txt");
	int n=0;
	while(!f.eof())
	{
		n++;                /// citirea din fisier
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
	}
    cout<<endl;                      ///afisarea la consola
	cout<<"Introduceti codul persoanei : ";
	char cod[20];
	cin>>cod;

	cout<<"Introduceti surplusul de zile : ";
	int zile1;
	cin>>zile1;

	ofstream g("Turisti.txt");   /// aici prelungim termenul de cazare
	for(int i=1;i<n;i++)
	{
		int zile=zile1+t[i].zp;
		int luni=t[i].lp;
		if(zile>30)
		{
			luni+=zile/30;
			zile-=30*(zile/30);
		}
		int ani=t[i].ap;
		if(luni>=12)
		{
			ani+=luni/12;
			luni-=12*(luni/12);
		}
			g<<t[i].cod<<" ";
			g<<t[i].nume<<" ";
			g<<t[i].prenume<<" ";
			g<<t[i].seriaB<<" ";
			g<<t[i].nb<<" ";
			g<<t[i].zc<<" ";
			g<<t[i].lc<<" ";
			g<<t[i].ac<<" ";
		if(strcmp(t[i].cod,cod)==0)
		{
			g<<zile<<" ";
			g<<luni<<" ";
			g<<ani<<" ";
		}
		else
		{
			g<<t[i].zp<<" ";
			g<<t[i].lp<<" ";
			g<<t[i].ap<<" ";
		}
			g<<t[i].codC<<endl;
	}
}

void expirat()              /// 4) expira cazarea
{
	ifstream f("Turisti.txt");
	int n=0;
	while(!f.eof())
	{
		n++;            /// citire
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
	}

	int zi,luna,an;                       /// afisare in consola
	cout<<endl;
	cout<<"Introduceti data de azi : (zi luna an)";
	cin>>zi;
	cin>>luna;
	cin>>an;

	ofstream g("Expirat.txt");

	for(int i=1;i<n;i++)                    /// aici am folosit aux o variabila ce va schimba cu locul
	{
		int auxzi=t[i].zp-zi;
		int auxluna=t[i].lp-luna;
		int auxan=t[i].ap-an;
		if(auxan==0)
		{
			if(auxluna==0)
			{
				if(auxzi==0)
				{
					g<<t[i].cod<<" ";   /// codul de afisare
					g<<t[i].nume<<" ";
					g<<t[i].prenume<<" ";
					g<<t[i].seriaB<<" ";
					g<<t[i].nb<<" ";
					g<<t[i].zc<<" ";
					g<<t[i].lc<<" ";
					g<<t[i].ac<<" ";
					g<<t[i].zp<<" ";
					g<<t[i].lp<<" ";
					g<<t[i].ap<<" ";
					g<<t[i].codC<<endl;
				}
			}
		}
	}
	g.close();
}

void utilitDispon()       /// 5) unitati disponibile
{    /// ATENTIE !!! : atunci cind sunt =>5 turisti in fisierul Turisti.txt functia nu va
    ///arata nimic deoarece nu mai sunt uniati de cazare
	ifstream f("Turisti.txt");  /// Cu ajutorul acestei functii putem vede modelul camerei
	int n=0;
	while(!f.eof())
	{
		n++;           /// codul de citire din fisier
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
    }
	f.close();

	ifstream ff("Unitati.txt");
	int m=0;
	while(!ff.eof())
	{
		m++;
		ff>>unit[m].cod;
		ff>>unit[m].nume;
		ff>>unit[m].tip;
		ff>>unit[m].confort;
		unit[m].nrCamere=0;
	}
	ff.close();

	ifstream fff("Camere.txt");
	int w=0;
	while(!fff.eof())
	{
		w++;
		fff>>cam[w].cod;
		fff>>cam[w].codU;
		fff>>cam[w].np;
		fff>>cam[w].pret;
		fff>>cam[w].tf;
		fff>>cam[w].tv;
	}
	fff.close();

	for(int i=1;i<w;i++)        /// partea logica
	{
		for(int ii=1;ii<m;ii++)
		{
			if(strcmp(cam[i].codU,unit[ii].cod)==0)
			{
				unit[ii].nrCamere++;
			}
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int ii=1;ii<w;ii++)
		{
			if(strcmp(t[i].codC,cam[ii].cod)==0)
			{
				for(int iii=1;iii<m;iii++)
				{
					if(strcmp(cam[ii].codU,unit[iii].cod)==0)
					{
						unit[iii].nrCamere--;
					}
				}
			}
		}
	}

	for(int i=1;i<m;i++)
	{
		if(unit[i].nrCamere>0)
		{
			cout<<endl;                /// afisarea la consola  , rezultatul codului de mai sus
			cout<<unit[i].cod<<" ";
			cout<<unit[i].nume<<" ";
			cout<<unit[i].tip<<" ";
			cout<<unit[i].confort<<endl;
		}

	}
	cout<<endl;
cout<<"Mai multe unitati nu exista ! "<<endl;

}

void camereDupaLocui() /// 6) Atributele camerelor
{
	ifstream f("Turisti.txt");               /// aceasta functie ne afiseaza cu ce este echipata camera
	int n=0;
	while(!f.eof())
	{
		n++;             /// codul de citire
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
	}

	ifstream fff("Camere.txt");
	int w=0;
	while(!fff.eof())
	{
		w++;
		fff>>cam[w].cod;
		fff>>cam[w].codU;
		fff>>cam[w].np;
		fff>>cam[w].pret;
		fff>>cam[w].tf;
		fff>>cam[w].tv;
	}
	fff.close();                         /// partea logica

	for(int i=1;i<n;i++)
	{
		for(int ii=1;ii<w;ii++)
		{
			if(strcmp(t[i].codC,cam[ii].cod)==0)
			{
				cam[ii].np--;
			}
		}
	}

	for(int i=1;i<w;i++)
	{
		for(int ii=i;ii<w;ii++)
		{
			if(cam[i].np>cam[ii].np)
			{
				cam[0]=cam[i];
				cam[i]=cam[ii];
				cam[ii]=cam[0];
			}
		}
	}

	for(int i=1;i<w;i++)
	{
		cout<<endl;                 /// ceea ce se afiseaza la consola
		cout<<cam[i].cod<<" ";
		cout<<cam[i].codU<<" ";
		cout<<cam[i].pret<<" ";
		cout<<cam[i].tf<<" ";
		cout<<cam[i].tv<<endl;
}}

void pretMediu()    /// 7) Pretul mediu la cazare
{
	ifstream f("Turisti.txt"); ///Pretul mediu la cazare
	int n=0;
	while(!f.eof())
	{
		n++;
		f>>t[n].cod;
		f>>t[n].nume;
		f>>t[n].prenume;
		f>>t[n].seriaB;
		f>>t[n].nb;
		f>>t[n].zc;
		f>>t[n].lc;
		f>>t[n].ac;
		f>>t[n].zp;
		f>>t[n].lp;
		f>>t[n].ap;
		f>>t[n].codC;
	}

	ifstream fff("Camere.txt");
	int w=0;
	while(!fff.eof())
	{
		w++;
		fff>>cam[w].cod;
		fff>>cam[w].codU;
		fff>>cam[w].np;
		fff>>cam[w].pret;
		fff>>cam[w].tf;
		fff>>cam[w].tv;
	}
	fff.close();

	float pret=0;
	for(int i=1;i<n;i++)
	{
		for(int ii=1;ii<w;ii++)
		{
			if(strcmp(t[i].codC,cam[ii].cod)==0)
			{
				pret+=cam[ii].pret;
			}
		}
	}

	cout<<endl;
	cout<<"Pretul mediu : "<<pret/(n-1)<<endl;
	cout<<endl;
}

void cmsLocC()   /// 8) Cel mai scump si cel mai ieftin loc de cazare
{
	ifstream ff("Unitati.txt");
	int m=0;
	while(!ff.eof())
	{
		m++;
		ff>>unit[m].cod;
		ff>>unit[m].nume;
		ff>>unit[m].tip;
		ff>>unit[m].confort;
		unit[m].nrCamere=0;
	}
	ff.close();

	ifstream fff("Camere.txt");
	int w=0;
	while(!fff.eof())
	{
		w++;
		fff>>cam[w].cod;
		fff>>cam[w].codU;
		fff>>cam[w].np;
		fff>>cam[w].pret;
		fff>>cam[w].tf;
		fff>>cam[w].tv;

	}
	fff.close();

	int max=0;
	int rez=1;
	for(int i=1;i<m;i++)
	{
		int sum=0;
		for(int ii=1;ii<w;ii++)
		{
			if(strcmp(cam[ii].codU,unit[i].cod)==0)
			sum+=cam[ii].pret;
		}
		if(sum>max)
		{
			max=sum;
			rez=i;
		}
	}

	cout<<endl;
	cout<<unit[rez].cod<<" ";
	cout<<unit[rez].nume<<" ";
	cout<<unit[rez].tip<<" ";
	cout<<unit[rez].confort<<endl;
	cout<<endl;
}

int main()    /// Afisarea meniului
{
	while(1)    ///aici am decis sa folosesc culori , pentru a face un oare care interes fata de meniu
	{   cout<<endl;
	    cout<<"       ";
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),144);  ///Coloarea rosie - 12 , fon albastru 144
        cout<<"...MENIU..."<<endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);    /// pentru a reveni la culoarea normala (alba)

	    cout<<"1: Inregistreaza turistul"<<endl;             ///interfata meniului
	    cout<<"2: Scoate de la evidenta"<<endl;
	    cout<<"3: Prelungeste cazarea"<<endl;
	    cout<<"4: Expira cazarea"<<endl;
	    cout<<"5: Unitati disponibile"<<endl;
	    cout<<"6: Atributele camerelor"<<endl;
	    cout<<"7: Pretul mediu la cazare"<<endl;
	    cout<<"8: Cel mai scump/ieftin loc de cazare"<<endl;
	    cout<<endl;

        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),9);   ///Culoarea albasta
	    cout<<"* Alege un punct din meniu * : ";
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);

		int a;
		cin>>a;   /// cu var <<a>> putem sa ne deplasam prin MENIU

		switch(a)
		{
			case 1: addTurist();break;            ///  Inregistreaza turistul
			case 2: deleteEx();break;            ///  Scoate de la evidenta
			case 3: updateCazare();break;       ///  Prelungeste cazarea
			case 4: expirat();break;           ///  expira cazarea
			case 5: utilitDispon();break;     ///  unitati disponibile
			case 6: camereDupaLocui();break; ///  Atributele camerelor
			case 7: pretMediu();break;      ///  Pretul mediu la cazare
			case 8: cmsLocC();break;       ///  Cel mai scump si cel mai ieftin loc de cazare
		}
	}

system ("pause");
	return 0;
}

/// versiune program 1.8
