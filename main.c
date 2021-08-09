#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define pri_arreglo 100
#define pri_float 110
#define pri_char 50

///PROTOTIPADOS
int cargaUnArreglo(int a[],int v,int d);///Ejercicio 1
void muestraArreglo(int a[], int v,int d );///Ejercicio 2
int sulmaArreglo(int a[], int v, int dim);///Ejercicio 3
void pasaArreloPila(int a[], int v,Pila *p);///Ejercicio 4
float cargaArreglofloats(float a[], int v, int dim);///Ejercicio 5
void muestraArreglofloat(float a[], int v);///Ejercicio 5b
float sumaArreglofloats(float a[], int v);///Ejercicio 5c
int buscaElemento(int a[], int v, int dato);///Ejercicio 6
int cargaArregloChar(char a[], int v, int d);///Ejercicio 6
void muetraArregloChar(char a[], int v);///Ejercicio 6b
void insertaCaracter(char a[], int v, char dato);///Ejercicio 7
int maximoValor(int a[], int v);///Ejercicio 8
int arregloCapicua(int a[], int v);///Ejercicio 9
void invierteArreglo(int a[], int v);///Ejercicio 10
int buscaPosMenor(int a[],int v,int pos);///Ejercicio 11a
void ordenaSeleccion(int a[], int v);///Ejercicio 11a2
int insertaUnElemento(int a[], int ultimaPos,int dato);///Ejercicio 11b
void ordenaPorInsercion(int a[], int v);///Ejercicio 11b2


int main()
{
    int arreglo[pri_arreglo];
    int val=0;
    int dim=100;
    int opcion=0,sumando=0,bandera=0,datoBusca=0;
    Pila pilita;
    inicpila(&pilita);
    float arregloFloat[pri_float];
    int vFloat=0;
    int dFloat=110;
    float sumaFlotantes=0;
    char arregloChar[pri_char];
    int vChar=0;
    int dimChar=50;
    char caracter=0;

    do{
        system("cls");
        menuTp4();
        scanf("%d",&opcion);

        switch(opcion){
        case 1:val=cargaUnArreglo(arreglo,val,dim);break;
        case 2:muestraArreglo(arreglo,val,dim);break;
        case 3:sumando=sulmaArreglo(arreglo,val,dim);
               printf("\nLA SUMA DE LOS ELEMENTOS DEL ARREGLO ES:%d\n",sumando);
        break;
        case 4:pasaArreloPila(arreglo,val,&pilita);
               printf("\nMOSTRANDO PILA CON DATOS\n");
               mostrar(&pilita);
        break;
        case 5: vFloat=cargaArreglofloats(arregloFloat,vFloat,dFloat);
        break;
        case 6:muestraArreglofloat(arregloFloat,vFloat);
        break;
        case 7:sumaFlotantes=sumaArreglofloats(arregloFloat,vFloat);
               printf("\nLA SUMA DE LOS ELEMENTOS DEL ARREGLO ES:%.2f\n",sumaFlotantes);
            break;
        case 8: printf("\nINGRESE DATO A BUSCAR: ");
                scanf("%d",&datoBusca);
                bandera=buscaElemento(arreglo,val,datoBusca);
                if(bandera==1){
                   printf("\nEL DATO %d SE ENCUENTRA EN EL ARREGLO\n",datoBusca);
                }
                else{
                    printf("\nEL DATO %d NO SE ENCUENTRA EN EL ARREGLO\n",datoBusca);
                }
            break;
        case 9: vChar=cargaArregloChar(arregloChar,vChar,dimChar);
            break;
        case 10: muetraArregloChar(arregloChar,vChar);
            break;
        case 11:
            printf("\nINGRESE EL CARACTER A INSERTAS: ");
            fflush(stdin);
            scanf("%c",&caracter);
            insertaCaracter(arregloChar,vChar,caracter);
            break;
        case 12:bandera=maximoValor(arreglo,val);
                printf("\nEL MAXIMO VALOR DEL ARREGLO ES:%d\n",bandera);
            break;
        case 13:bandera=arregloCapicua(arreglo,val);
                if(bandera==1){
                    printf("\nEL ARREGLO ES CAPICUA\n");
                }
                else{
                    printf("\nEL ARREGLO NO ES CAPICUA\n");
                }
             break;
        case 14:invierteArreglo(arreglo,val); break;
        case 15:ordenaSeleccion(arreglo,val);break;
        case 16:ordenaPorInsercion(arreglo,val);break;
        case 17:break;
        }
        system("pause");

    }while(opcion!=27);
    return 0;
}

void menuTp4(){
printf("\n\t\t..::TRABAJO PRATICO N4::..\n");
printf("Opc 1:CARGA UN ARREGLO POR TECLADO");
printf("\nOpc 2:MUESTRA UN ARREGLO CARGADO POR TECLADO");
printf("\nOpc 3:SUMANDO ELEMENTOS DEL ARREGLO");
printf("\nOpc 4:PASA ELEMENTOS DE UNA ARREGLO A UNA PILA");
printf("\nOpc 5:CARGA ARREGLO DE NUMEROS DECIMALES");
printf("\nOpc 6:MUESTRA ARREGLO DE NUMEROS DECIMALES");
printf("\nOpc 7:SUMA DATOS DE ARREGLO FLOTANTES");
printf("\nOpc 8:BUSCA UN ELEMENTO EN UN ARREGLO CON EL METODO BANDERA");
printf("\nOpc 9:CARGAR UN ARREGLO DE CARACTERES");
printf("\nOpc 10:MUESTRA UN ARREGLO DE CARACTERES");
printf("\nOpc 11:INSERTA UN DATO EN UN ARREGLO DE CARACTER");
printf("\nOpc 12:OBTIENE EL MAXIMO CARACTER DE UN ARREGLO");
printf("\nOpc 13:VERIFICA SI UN ARREGLO ES CAPICUA");
printf("\nOpc 14:INVIERTE LOS DATOS DE UN ARREGLO");
printf("\nOpc 15:ORDENA UN ARREGLO POR METODO DE SELECCION");
printf("\nOpc 16:ORDENA UN ARREGLO POR METODO DE INSERCION");
printf("\nOpc 17:");

printf("\nINGRESE UNA OPCION:");
}

///Ejercicio 1
int cargaUnArreglo(int a[],int v,int d){

char opcion=0;
printf("\n..::CARGANDO DATOS AL ARREGLO::..\n");

while(v<d&&opcion!=27){
system("cls");
printf("INGRESE DATOS AL ARREGLO: ");
scanf("%d",&a[v]);

v++;
printf("\nPresione ESC para finalizar, si no otra tecla pra continuar......\n");
opcion=getch();
}

return v;
}
///Ejercicio 2
void muestraArreglo(int a[], int v,int d ){

int i=0;

for(i=0;i<v;i++){
    printf("[%d]\n",a[i]);
  }
}
///Ejercicio 3
int sulmaArreglo(int a[], int v, int dim){

int sumaFinal=0,i=0;

for(i=0;i<v;i++){

 sumaFinal=sumaFinal+a[i];
}
return sumaFinal;
}
///Ejercicio 4
void pasaArreloPila(int a[], int v,Pila *p){ //--->Se pone puntero ya que nos indica la direccion de memoria

int i=0;

for(i=0;i<v;i++){
    apilar(p,a[i]);
  }
}
///Ejercicio 5
float cargaArreglofloats(float a[], int v, int dim){

srand(time(NULL));
char opcion=0;
int cont=0;

printf("\n..::CARGARGANDO ARREGLO DE FLOTANTES::..\n");
while(v<dim&&opcion!=27){

printf("INGRESE DATOS AL ARREGLO[%d]: ",cont+1);
scanf("%f",&a[v]);
///a[v]=(float)rand()%100;

cont++,
v++;
printf("\nPresione ESC si desea salir, si no otra tecla.......\n");
opcion=getch();
system("cls");
}

return v;
}
///Ejercicio 5 b
void muestraArreglofloat(float a[], int v){

int i=0;

for(i=0;i<v;i++){

 printf("\n[%d]:%.2f\n",i+1,a[i]);
  }
}
///Ejercicio 5c
float sumaArreglofloats(float a[], int v){

float sumaTotal=0;
int i=0;

for(i=0;i<v;i++){
    sumaTotal=sumaTotal+a[i];
 }
return sumaTotal;
}
///Ejercicio 6
int buscaElemento(int a[], int v, int dato){

int flag=0,i=0;

while(i<v&&flag==0){

if(a[i]==dato){
    flag=1;
}
 i++;
}

return flag;
}
///Ejercicio 7
int cargaArregloChar(char a[], int v, int d){

int i=0;
char opcion=0;

printf("\n..:::CARGANDO ARREGLO CON DATOS CHAR::..\n");

while(v<d&&opcion!=27){

printf("INGRESE CARACTERES: ");
fflush(stdin);
scanf("%c-",&a[v]);

v++;
printf("\nPresine ESC para salir, si no presione otra tecla.....\n");
opcion=getch();
}

return v;
}
///Ejercicio 7b
void muetraArregloChar(char a[], int v){
int i=0;

for(i=0;i<v;i++){

printf("%c\n",a[i]);
  }
}
///Ejercicio 7b
void insertaCaracter(char a[], int v, char dato){

int i=v-1;

while(i<v&&a[i]>dato){
a[i+1]=a[i];
i--;

}
a[i+1]=dato;

return i;
}
///Ejercicio 8
int maximoValor(int a[], int v){

int i=0,maximo=0;

for(i=0;i<v;i++){

if(maximo<a[i]){
    maximo=a[i];
  }
}
return maximo;
}
///Ejercicio 9
int arregloCapicua(int a[], int v){

int flag=0,i=0,j=v-1;

while(i<v){
if(a[i]==a[j]){
    flag=1;
}
i++;
j--;
}

return flag;
}
///Ejercicio 10
void invierteArreglo(int a[], int v){

int i=0,j=v-1,aux=0;

while(i<j-1){

 aux=a[i];
 a[i]=a[j];
 a[j]=aux;

 i++;
 j--;
  }
}
///Ejercicio 11
///Ordenamiento por seleccion
void ordenaSeleccion(int a[], int v){

int aux,posMenor;
int i=0;

while(i<v-1){
    posMenor=buscaPosMenor(a,v,i);
    aux=a[posMenor];
    a[posMenor]=a[i];
    a[i]=aux;
    i++;
   }
}
///Busca la posicion menor de un arreglo con datos ( sirve para funcion ordenamiento por seleccion)
int buscaPosMenor(int a[],int v,int pos){

int i=pos,posMenor=i;
i++;
while(i<v){
    if(a[i]<a[posMenor]){
        posMenor=i;
    }
    i++;
}
return posMenor;
}
///Ejercicio 11 b ORDENACION POR INSERCION
 void ordenaPorInsercion(int a[], int v){
 int i=0;

 while(i<v-1){
  insertaUnElemento(a,i,a[i+1]);
  i++;
   }
 }
///Funcion que inserta un elemento (se usa para ordenacion por insecion)
int insertaUnElemento(int a[], int ultimaPos,int dato){

int i=ultimaPos;

while(i>0&&dato<a[i]){

    a[i+1]=a[i];
    i--;
}
a[i+1]=dato;

return i;
}

/*
1-Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el
 usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
  elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
2-Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.
3-Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.
4-Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
5-Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión
100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado
al arreglo)
6-Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
7-Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
 conservando el orden.
8-Realizar una función que obtenga el máximo carácter de un arreglo dado.
9-Realizar una función que determine si un arreglo es capicúa.
10-Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
11-Ordenar un arreglo según los siguientes métodos:
Selección
Inserción
12-Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos
de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.
*/
