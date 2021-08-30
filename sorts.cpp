#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
#include<string>
#include<ctime>
#include<stdio.h>
#include "sorts.h"
//#include <iomanip>
using namespace std;
long t0, t1;

// Prototipos de funciones
// void sort(string nombres[], int count);
void display(string nombres[], int count);
void saveToFile(ofstream& dataOut, string nombres[], int count);

int main()
   {
      double time;
      /*setlocale(LC_ALL, "Spanish");*/
         //Declaracion de variables
      string nombre;
      int count = 0;
      //define un flujo de entrada para el archivo de datos
      ifstream dataIn;

      //Define un flujo de salida para el archivo de datos 
      ofstream dataOut;
      //Abrir el archivo de entrada
      dataIn.open("DATOS.txt");

      //comprobar si el nombre del archivo es válido o no 

      if (dataIn.fail())
      {
         cout << "** Archivo no encontrado **";
         return 1;
      }
      else
      {
            while (getline(dataIn, nombre))
         {
         count++;
         }

         dataIn.close();

         //Creando matriz dinámicamente 
         string* nombres = new string[count];
         //Abrir el archivo de entrada
/*------------------BUBBLE SORT-----------------------*/
         dataIn.open("DATOS.txt");
            for (int i = 0; i < count; i++)
               {
                  getline(dataIn, nombre);
                  nombres[i] = nombre;
               }
         dataIn.close();

         t0=clock();
         bubbleSort(nombres, count);
         t1= clock();
         time = (double(t1 - t0) / CLOCKS_PER_SEC);
         cout<<"\n----------------ORDENAMIENTO BURBUJA-----------"<<endl;
         cout << "El tiempo de ejecucion es: " << t1 - t0 << CLK_TCK << endl;
         cout << "El tiempo en segundo es: " << time << endl;

/*-------------------SELECTION SORT-------------------------*/
         dataIn.open("DATOS.txt");
            for (int i = 0; i < count; i++)
               {
                  getline(dataIn, nombre);
                  nombres[i] = nombre;
               }
         dataIn.close();

         t0=clock();
         selectionSort(nombres, count);
         t1= clock();
         time = (double(t1 - t0) / CLOCKS_PER_SEC);
         cout<<"\n-----------------ORDENAMIENTO POR SELECCION-----------"<<endl;
         cout << "El tiempo de ejecucion es: " << t1 - t0 << CLK_TCK << endl;
         cout << "El tiempo en segundo es: " << time << endl;

/*-------------------INSERTION SORT-----------------------*/
         dataIn.open("DATOS.txt");
            for (int i = 0; i < count; i++)
               {
                  getline(dataIn, nombre);
                  nombres[i] = nombre;
               }
         dataIn.close();

         t0=clock();
         insertionSort(nombres, count);
         t1= clock();
         time = (double(t1 - t0) / CLOCKS_PER_SEC);
         cout<<"\n--------------ORDENAMIENTO INSERCION-----------"<<endl;
         cout << "El tiempo de ejecucion es: " << t1 - t0 << CLK_TCK << endl;
         cout << "El tiempo en segundo es: " << time << endl;

         
      

/*--------------------MERGE SORT----------------------*/
         dataIn.open("DATOS.txt");
            for (int i = 0; i < count; i++)
               {
                  getline(dataIn, nombre);
                  nombres[i] = nombre;
               }
         dataIn.close();
         t0=clock();
         mergeSort(nombres, count);
         t1= clock();
         time = (double(t1 - t0) / CLOCKS_PER_SEC);
         cout<<"\n---------------ORDENAMIENTO MERGE------------"<<endl;
         cout << "El tiempo de ejecucion es: " << t1 - t0 << CLK_TCK << endl;
         cout << "El tiempo en segundo es: " << time << endl;

         
/*---------------QUICK SORT------------------------*/
         dataIn.open("DATOS.txt");
            for (int i = 0; i < count; i++)
               {
                  getline(dataIn, nombre);
                  nombres[i] = nombre;
               }
         dataIn.close();
         t0=clock();
         quickSort(0, count-1, nombres);
         t1= clock();
         time = (double(t1 - t0) / CLOCKS_PER_SEC);
      cout<<"\n-------------ORDENAMIENTO QUICK------------"<<endl;
      cout << "El tiempo de ejecucion es: " << t1 - t0 << CLK_TCK << endl;
      cout << "El tiempo en segundo es: " << time << endl; 
         
         cout << "\nAQUI ESTAN LOS NOMBRES ORDENADOS:" << endl;
         cout << "---------------------------------" << endl;
         display(nombres, count);
         dataOut.open("nombresOrdenados.txt"); //creando y abriendo el archivo de salida
         saveToFile(dataOut, nombres, count);
         dataOut.close(); //Cerrando el archivo de salida.
      }
      system("pause");
      return 0;
}

//Esta función mostrará la matriz de cadenas
void display(string nombres[], int count)
{
   for (int i = 0; i < count; i++)
   {
      cout << nombres[i] << endl;
   }
}

// Esta función guardará la matriz ordenada en el archivo de salida
void saveToFile(ofstream &dataOut, string nombres[], int count)
{

   dataOut << "Names in Ascending Order:" << endl;

   for (int i = 0; i < count; i++)

   {

      dataOut << nombres[i] << endl;
   }
}
