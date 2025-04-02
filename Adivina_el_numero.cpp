#include <iostream>
#include <locale>
#include <random>
using namespace std;


int main(){
  // CODIFICANDO A UTF-8, TODOS LOS CARÁCTERES DE ESPAÑOL APARECEN EN CONSOLA.
  setlocale(LC_ALL, "es_ES.UTF-8");

  //VARIABLES
  int intentos,randomNumber,numUsuario;
  string jugar,seguirJugando,salir;

  //BIENVENIDA
  cout << "\n--------------------------------------------";
  cout << "\n| BIENVENIDO AL JUEGO DE ADIVINA EL NÚMERO |" << endl;
  cout << "--------------------------------------------\n";


  //REGLAS
  cout << "\n[+] REGLAS:" << endl;
  cout << " - Adivinarás un número entre el 1 y el 100." << endl;
  cout << " - Solo tienes 8 intentos." << endl;
  cout << " - Presiona CTRL + C para salir en cualquier momento." << endl;


  //--------------------------INICIO DEL PROCESO------------------------//
  cout << "\n¿Deseas jugar?(s/n) ";
  cin >> jugar;


  //INICIO BUCLE
  intentos = 0;

  //GENERANDO NÚMERO ALEATOREO
  std::random_device rd;  // Dispositivo de entropía
  std::mt19937 gen(rd()); // Generador Mersenne Twister
  std::uniform_int_distribution<int> dist(1, 100);
  randomNumber = dist(gen); 

  if (jugar == "s" || jugar == "S" || jugar == "si" || jugar == "SI" || jugar == "Si" || jugar == "sI"){

    do{
      intentos +=1;

      //REVISANDO NÚMERO DE INTENTOS LIMITE
      if(intentos == 9){
        cout << "\n¡AGOTASTE TODOS TUS INTENTOS!" << endl;
        cout << "\nEl número random era [" << randomNumber << "]" << endl;
        cout << "\n¿Deseas seguir jugando?(s/n) ";
        cin >> seguirJugando;
        cout << "" << endl;

        if (seguirJugando == "s" || jugar == "S" || jugar == "si" || jugar == "SI" || jugar == "Si" || jugar == "sI"){
          intentos = intentos * 0;

          //GENERANDO NÚMERO ALEATOREO
          std::random_device rd;  // Dispositivo de entropía
          std::mt19937 gen(rd()); // Generador Mersenne Twister
          std::uniform_int_distribution<int> dist(1, 100);
          randomNumber = dist(gen);
          jugar = "s";
          continue;
        }
        else if(seguirJugando == "n" || jugar == "N" || jugar == "no" || jugar == "NO" || jugar == "No" || jugar == "nO"){
          cout << "Gracias por jugar, ¡Hasta la próxima!";
          cout << "\n\nPresiona CTRL + C para salir.";
          cin >> salir;
        }
        else{
          cout << ">>> OPCIÓN INVÁLIDA <<<";
          cout << "\n\nPresiona CTRL + C para salir.";
          cin >> salir;
        }
      }

      //ENTRADA DEL USUARIO.
      cout << "\nIntento: " << intentos << ". Te quedan " << ((intentos - 8)*-1) << " intentos.";
      cout << "\nDime un número entre el 1 y el 100: ";
      cin >> numUsuario;

      //REVISANDO SI EL USUARIO INGRESA UN NÚMERO Y NO UNA LETRA.
      if (cin.fail()) {  
        cout << "\n>>> ENTRADA NO VÁLIDA, INTENTALO DE NUEVO <<<" << endl;
        cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        intentos -=1;
        continue;
      } 

      //COMPARANDO NÚMERO RANDOM CON NÚMERO DEL USUARIO.
      else if(numUsuario > 100 || numUsuario < 1){
        cout << "\n>>> EL NÚMERO DEBE ESTAR ENTRE 1 Y 100 <<<" << endl;
        intentos -=1;
        continue;
      }
      else if (numUsuario < randomNumber){
        cout << "\nNúmero muy bajo, sigue intentando." << endl;
      }
      else if (numUsuario > randomNumber){
        cout << "\nNúmero muy alto, sigue intentando." << endl;
      }
      else if (numUsuario == randomNumber){
        cout << "\n¡ADIVINASTE! Te tomó " << intentos << " intentos para lograrlo." << endl;
        cout << "\n¿Deseas seguir jugando?(s/n) ";
        cin >> seguirJugando;
        intentos = intentos * 0;
        
        //GENERANDO NÚMERO ALEATOREO
        std::random_device rd;  // Dispositivo de entropía
        std::mt19937 gen(rd()); // Generador Mersenne Twister
        std::uniform_int_distribution<int> dist(1, 100);
        randomNumber = dist(gen);

        if (seguirJugando == "s" || jugar == "S" || jugar == "si" || jugar == "SI" || jugar == "Si" || jugar == "sI"){
          jugar = "s";
          continue;
        }
        else{
          cout << "\nGracias por jugar, ¡Hasta la próxima!" << endl;
          cout << "\n\nPresiona CTRL + C para salir.";
          cin >> salir;
        }
      }
    } while (intentos < 9);
    
  }

  //SI EL USUARIO NO QUIERE JUGAR.
  else if (jugar == "n" || jugar == "N" || jugar == "no" || jugar == "NO" || jugar == "No" || jugar == "nO"){
    cout << "\nLastima que no quieras jugar, hasta la próxima" << endl;
    cout << "\n\nPresiona CTRL + C para salir.";
    cin >> salir;
  }
  else {
    cout << "\n>>> OPCIÓN INVÁLIDA, VUELVE A INTENTARLO. <<<" << endl;
    cout << "\n\nPresiona CTRL + C para salir.";
    cin >> salir;
  }

  //SALIDA DEL PROGRAMA
  cout << "\n\nPresiona CTRL + C para salir.";
  cin >> salir;

  return 0;
}