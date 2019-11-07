#include <iostream>
#include <random>
#include <cmath>
using namespace std;
//funkcja dla ktorej obliczamy calke
double func(double x) {
	return x*x*x+2;
}
double simpson(double xp, double xk, int n)
{
	double x;			//xp-poczatek przedzialu, xk koniec przedzialu
	double dx = (xk - xp) / (double)n;			//male przedzialy w ktorych bede liczyc wartosci

	double calka = 0;
	double s = 0;
	for (int i = 1; i < n; i++) {
		x = xp + i * dx;						//przedzial w ktorym akurat licze, potem przesuwam sie o dx
		s += func(x - dx / 2);					//obl wartosc funkcji dla srodka przedzialu
		calka += func(x);						//obl wartosc funkcji dla konca przedzialu
	}		

	s += func(xk - dx / 2);						//do tego "s" ktory obl w for dodaje jeszcze wartosc funkcji dla srodka ostatniego przedzialu
	return calka = (dx / 6) * (func(xp) + func(xk) + 2 * calka + 4 * s);		//wzor z prezentacji

}

double monteCarlo(double xp, double xk,int n,int d) {
	double suma = 0;
	double suma2;
	double przedzial = abs(xk - xp);
	double malyPrzedzial = przedzial / n;
	double xxp = xp;
	double xxk = xk;
	double *tab2 = new double[d];
	//double tab[4] = {1.5,2.6,3.8,4.5};
	//double *tab = new double[3*n];
	double div = RAND_MAX / przedzial;
	for (int i = 0; i < n; i++) {
		suma2 = 0;
		for (int j = 0; j < d; j++) {
	
			//tab2[j] = ((xxp + malyPrzedzial)-xxp)* ((double)rand() / (double)RAND_MAX) + xxp;
			//cout << tab2[j] << endl;
			suma2 = suma2 + func(((xxp + malyPrzedzial) - xxp)* ((double)rand() / (double)RAND_MAX) + xxp);
		}
		suma2 = suma2 / d;
		xxp = xxp + malyPrzedzial;
		suma = suma + suma2;
	}
	suma = suma / n;
	return suma*przedzial;
}

int main() {
	double xp, xk, dx;
	int i, n,d;
	cout << "Podaj poczatek przedzialu calkowania" << endl;;
	cin >> xp;

	cout << "Podaj koniec przedzialu calkowania"<<endl;
	cin >> xk;

	cout << "Podaj dokladnosc calkowania" << endl;
	cin >> n;
	cout << "Podaj ilosc punktow" << endl;
	cin >> d;
	


	cout << "Simpson. Wartosc calki wynosi w przyblizeniu " << simpson(xp, xk, n) << endl;
	cout << "Monte Carlo. Wartosc calki wynosi w przyblizeniu " << monteCarlo(xp, xk, n,d) << endl;
	system("pause");
	return 0;
}