#include "iostream"
//prototipos de funciones
void bubbleSort(std::string nombres[], int count);
void selectionSort(std::string nombres[], int count);
void insertionSort(std::string nombres[], int count);
void mergeSort(std::string nombres[], int count);
void sortSubArray(std::string nombres[], int low, int high, int count);
void merge(std::string nombres[], int left, int middle1, int middle2, int right, int count);
void quickSort(int primero, int ultimo, std::string nombres[]);



void bubbleSort(std::string nombres[], int count)
{
   int start;
   int i, j;
   std::string temp;
   for ( i = 0; i < count-1; i++)
      for( j=i+1; j < count ; j++)
      {
         //if(nombres[i].compare(nombres[j])>0)
         if(nombres[i].compare(nombres[j])>0)
         {
            temp = nombres[i];
            nombres[i] = nombres[j];
            nombres[j] = temp;
         }
      }
}

void selectionSort(std::string nombres[], int count)
{
   int start;
   std::string temp;
   for (int i = count - 1; i > 0; --i)
   {
      start = 0;
      for (int j = 1; j <= i; ++j)
      {
         if (nombres[j].compare(nombres[start]) > 0)
         {
            start = j;
         }
         temp = nombres[start];
         nombres[start] = nombres[i];
         nombres[i] = temp;
      }
   }
}



void insertionSort(std::string nombres[], int count)
{
   int i,j;
   std::string temp;
   for (int i = 1; i < count; i++)
   {
      temp= nombres[i];
      for (int j = i-1; j >= 0 && temp.compare(nombres[j]) < 0 ; j--)
      { 
         nombres[j+1]=nombres[j];
      }
      nombres[j+1]=temp;
   }
}

void mergeSort(std::string nombres[], int count)
{
   sortSubArray(nombres, 0, count - 1, count);
} 

// funcion que ordena un fragmento del array 
void sortSubArray(std::string nombres[], int low, int high, int count)
{
   // caso base de prueba: el tamaño de la matriz es 1 
   if ((high - low) >= 1) { // si no es el caso base ... 
      int middle1 = (low + high) / 2;
      int middle2 = middle1 + 1;
        
      // dividir array en dos y ordenar cada mitad en forma recursiva
      sortSubArray(nombres, low, middle1, count); // primera mitad 
      sortSubArray(nombres, middle2, high, count); // segunda mitad
        
      // mezclar dos arrays ordenados  
      merge(nombres, low, middle1, middle2, high, count);
   } 
}

// fusiona dos subarreglos ordenados en un subarreglo ordenado
void merge(std::string nombres[], int left, int middle1, 
   int middle2, int right, int count)
{
   int leftIndex = left; // índice en subarreglo izquierdo 
   int rightIndex = middle2; //indexa en el subarreglo derecho 
   int combinedIndex = left; // indexar en una matriz temporal
   std::string tempArray[count]; //matriz temporal  
    
   // fusionar los subarreglos hasta que se alcance el final de uno 
   while (leftIndex <= middle1 && rightIndex <= right) 
   {
      // colocar el más pequeño de los dos elementos actuales en el resultado 
      //  y pasar al siguiente espacio en el subarreglo
      if (nombres[leftIndex].compare(nombres[rightIndex])<=0) 
      {
         tempArray[combinedIndex++] = nombres[leftIndex++];
      } 
      else 
      {
         tempArray[combinedIndex++] = nombres[rightIndex++];
      } 
   }
    
   if (leftIndex == middle2) { //si al final del subarreglo izquierdo ... 
      while (rightIndex <= right) { //copiar el subarreglo correcto 
         tempArray[combinedIndex++] = nombres[rightIndex++];
      } 
   } 
   else { //si al final del subarreglo derecho ...
      while (leftIndex <= middle1) { // copiar el subarreglo izquierdo 
         tempArray[combinedIndex++] = nombres[leftIndex++];
      } 
   } 
    
   //copiar valores de nuevo en la matriz original 
   for (size_t i = left; i <= right; i++) {
      nombres[i] = tempArray[i];
   } 
}

void quickSort(int primero, int ultimo, std::string nombres[])
{
   std::string temp;
   int i=primero;
   int j=ultimo;
   std::string central=nombres[(primero+ultimo)/2];
   do
   {
      while(central.compare(nombres[i])>0) i++;//salta todos los elementos que sean menores que el elemento central
      while(central.compare(nombres[j])<0) j--;//salta todos los elementos que sean mayores que el elemento central
      if(i<=j)
      {
         temp=nombres[i];
         nombres[i]=nombres[j];
         nombres[j]=temp;
         i++;
         j--;
      }
   } while(i<=j);
   if(primero<j) quickSort(primero,j,nombres);//acá todos los elementos a la izquierda de central son menores
   if(ultimo<i) quickSort(i, ultimo, nombres);//acá todos los elementos a la derecha de central son mayores
}


