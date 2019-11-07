#include <iostream>
#include <cmath>
using namespace std;

double prostokonty(double *wiel,int czesci,double x0,double xn,int stopien)
{
	double wartosc=0;
	double suma=0;
	double przedzial = xn - x0;
	double deltaX = przedzial / czesci;
	double srednia = x0 + deltaX/ 2;
	for (int i = 0; i < czesci; i++)
	{
		for (int j = 0; j <= stopien; j++) {
			wartosc = wartosc + abs(pow(srednia, j)*wiel[j]);
		}
		suma = suma + abs(deltaX * wartosc);
		wartosc = 0;
		srednia = srednia + deltaX;
	}
	return suma;
}

double trapezy(double *wiel, int czesci, double x0, double xn, int stopien)
{
	double lewawartosc = 0;
	double prawawartosc = 0;
	double suma = 0;
	double przedzial = xn - x0;
	double deltaX = przedzial / czesci;

	for (int i = 0; i < czesci; i++)
	{
		for (int j = 0; j <= stopien; j++) {
			lewawartosc = abs(lewawartosc + pow(x0, j)*wiel[j]);
			prawawartosc = abs(prawawartosc + pow(x0+deltaX, j)*wiel[j]);
		}
		suma = suma + abs((lewawartosc+prawawartosc)*deltaX/2);
		lewawartosc = 0;
		prawawartosc = 0;
		x0 = x0 + deltaX;
	}
	return suma;
}

int main() {
	int stopien,czesci;
	double x0, xn;
	cout << "podaj stopien wielomianu: " << endl;
	cin >> stopien;
	double *wiel = new double[stopien+1];
	for (int i = 0; i < stopien + 1; i++) {
		cout << "podaj wspolczinnik " << i << endl;
		cin >> wiel[i];
	}
	cout << "podaj poczatek przedzialu " << endl;
	cin >> x0;
	cout << "koniec przedzialu " << endl;
	cin >> xn;
	cout << "podaj ilosc czesci " << endl;
	cin >> czesci;
	double wynik = prostokonty(wiel, czesci, x0, xn, stopien);
	cout << wynik << endl;
	wynik = trapezy(wiel, czesci, x0, xn, stopien);
	cout << wynik << endl;
	cout << endl;
	system("pause");
	return 0;
}