//Fecha: 24/07/2024
//Autora: Nayeli Cruz
//1) Utilice el programa de conversión de NUMEROS a LETRAS realizado en clases 
//y complete hasta el número 999.999.999
//Además:  en el mismo programa, diseñe una función que genere 100 números aleatorios
//comprendidos entre 1 y 999.999.999. LA función debe imprimir el valor numérico y su equivalente en letras.
//Recuerde que no debe crear más arrays de los que ya están definidos.




#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis",
"siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince",
"dieciseis", "diecisiete", "dieciocho", "diecinueve"};

const string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta",
"sesenta", "setenta", "ochenta", "noventa"};

const string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos",
"seiscientos", "setecientos", "ochocientos", "novecientos"};

// Devuelve las unidades del array de string
string GetUnidades(int num) {
  return unidades[num];
}

// Devuelve las decenas del array de string
string GetDecenas(int num) {
  int x = num / 10;
  int resto = num % 10;
  string AUX = "";

  if (num < 20) {
    AUX = GetUnidades(num);
  } else {
    AUX = decenas[x];
    AUX = resto > 0 ? AUX + " y " + GetUnidades(resto) : AUX + "";
  }

  return AUX;
}

// Devuelve las centenas del array string
string GetCentenas(int num) {
  int x = num / 100;
  int resto = num % 100;
  string AUX = "";

  if (num < 100) {
    AUX = GetDecenas(num);
  } else {
    AUX = centenas[x];
    AUX = resto > 0 ? AUX + " " + GetDecenas(resto) : AUX;
  }
  return AUX;
}

// Devuelve en letras los números de mil en adelante
string GetMiles(int num) {
  int miles = num / 1000;
  int resto = num % 1000;
  string AUX = "";

  if (num < 1000) {
    AUX = GetCentenas(num);
  } else {
    if (miles == 1) {
      AUX = "mil";
    } else {
      AUX = GetCentenas(miles) + " mil";
    }
    if (resto > 0) {
      if (resto < 100) {
        AUX = AUX + " " + GetDecenas(resto);
      } else {
        AUX = AUX + " " + GetCentenas(resto);
      }
    }
  }

  return AUX;
}

string Convertir(int num) {
  string partes[4] = {"", "mil", "millón", "mil millones"};
  string resultado = "";
  int parte = 0;

  while (num > 0) {
    int res = num % 1000;
    num /= 1000;
    string strParte = GetCentenas(res);

    if (parte == 2) {
      if (res == 1) {
        resultado = partes[parte] + " " + resultado;
      } else {
        resultado = strParte + " millones " + resultado;
      }
    } else if (parte == 1 && res == 1) {
      resultado = partes[parte] + " " + resultado;
    } else if (strParte != "") {
      resultado = strParte + " " + partes[parte] + " " + resultado;
    }
    parte++;
  }

  return resultado;
}

void GenerarNumerosAleatorios() {
  srand(time(0));

  for (int i = 0; i < 100; ++i) {
    int num = rand() % 999999999 + 1;
    cout << "El número: " << num << " en letras es: " << Convertir(num) << endl;
  }
}

int main() {
  int numeros[] = {9, 27, 496, 8623, 94517, 476249, 159753468};

  for (int n : numeros) {
    cout << "El número: " << n << " en letras es: " << Convertir(n) << endl;
  }

  cout << "\nGenerando 100 números aleatorios:\n";
  GenerarNumerosAleatorios();

  return 0;
}
