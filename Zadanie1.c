#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funkcja obliczajaca silnie
double silnia(int x)
{
  int i;
  int result = 1;
  for (i = 2; i <= x; i++) result *= i;
  return result;
}

// Oblicza wartosc funkcji sinus hiperboliczny za pomoca sumy rozwiniecia szeregu Taylora. N-rzad przyblizenia
double Taylor(double x, int N)
{
    int i = 0;
    double result = 0;
    while (i<=N)
    {
      int j = 2*i+1;
      if (i%2==0)
      {
        result += pow(x, (2*i)+1)/silnia((2*i)+1);
      }
      else
      {
        result -= pow(x, (2*i)+1)/silnia((2*i)+1);
      }
      i++;
    }
    return result;
}

double przyblizenie(double result1, double result2)
{
  return fabs(result1-result2);
}


int main (int argc, char **argv)
{
  double x; // Wartosc, dla ktorej bedzie obliczona wartosc sinh
  int n; // Precyzja rozwiniecia szeregu Taylora

  // Sprawdzenie, czy podano tylko parametr x
  if (argc != 3)
  {
    fprintf(stderr, "Podano zla liczbe argumentow!\n");
    return (-1);
  }

  x = atof(argv[1]);
  n = atoi(argv[2]);

  //Sprawdzenie, czy x jest wartoscia miedzy -1 a 1
  if (x<=-1 || x>=1)
  {
    fprintf(stderr, "Podano parametr poza zakresem!\n");
    return(-1);
  }

  //Sprawdzenie, czy n jest wartoscia miedzy 1 a 170
  if (n<1 || n>170)
  {
    fprintf(stderr, "Podano parametr poza zakresem!\n");
    return(-1);
  }

  printf("Wartosc obliczona przy uzyciu funkcji sinh:\t\t%lf\n", sinh(x));

  printf("Wartosc obliczona z sumy rozwiniecia szeregu Taylora:\t%lf\n", Taylor(x, n));

  printf("Dokladnosc przyblizenia:\t\t\t\t%lf\n", przyblizenie(sinh(x), Taylor(x, n)));

  return 0;
}
