#include<iostream>

using namespace std;
//funckja 1/x-to jest ta moje funkcja podca³kowa
double funkcja(double x)
{
	return 1 / x;
}

//funkcja do transformacji ukladu wspolrzednych, stosuje podstawienie "t"
double licz_t(double xp, double xk, double x)
{
	return ((xp + xk) / 2 + ((xk - xp)*x) / 2);
}

//xi-odciête tzw. "punktów Gaussa", -1<xi<1 -zawsze
//Ai-Wspó³czynniki, tzw. "wagi"
//t- tablica do której wpisuje sobie wartoœci które podstawiam jako "t"
double gauss_dwu_wezlowy(double xp, double xk)
{
	double* x = new double[2];
	double* A = new double[2];
	double* t = new double[2];
	double suma = 0;
	x[0] = 0.57735;
	x[1] = -0.57735;
	A[0] = 1, A[1] = 1;
	for (int i = 0; i < 2; i++)
	{
		t[i] = licz_t(xp, xk, x[i]);
		cout << "t" << i << " " << t[i] << "\tf(t) " << funkcja(t[i]) << endl;		//tutaj jest obliczana suma z ostatniego wzoru
		suma = suma + A[i] * funkcja(t[i]);
	}
	return ((xk - xp) / 2)*suma;													//tutaj ta sume z ostatniego wzoru mnoze jeszcze przez wspolczynnik tez ze wzoru
}


double gauss_cztero_wezlowy(double xp, double xk)
{
	double* x = new double[4];
	double* A = new double[4];
	double* t = new double[4];
	double suma = 0;
	x[0] = -0.861136;
	x[1] = -0.339981;
	x[2] = 0.339981;
	x[3] = 0.861136;

	A[0] = 0.347855;
	A[1] = 0.652145;
	A[2] = 0.652145;
	A[3] = 0.347855;

	for (int i = 0; i < 4; i++)
	{
		t[i] = licz_t(xp, xk, x[i]);
		cout << "t" << i << " " << t[i] << "\tf(t) " << funkcja(t[i]) << endl;
		suma = suma + A[i] * funkcja(t[i]);
	}
	return ((xk - xp) / 2)*suma;
}


int main()
{
	cout << "gauss dwuwezlowy od 1 do 2 dla f(x)=1/x   " << gauss_dwu_wezlowy(1, 2) << endl;
	cout << "gauss czterowezlowy od 1 do 2 dla f(x)=1/x   " << gauss_cztero_wezlowy(1, 2) << endl;
	system("pause");
	return 0;
}