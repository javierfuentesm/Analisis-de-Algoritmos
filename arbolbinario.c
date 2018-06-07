//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
struct node
{
    int key;
    struct node *left, *right;
};
  
// Creamos la estructura para el arbol binario de busqueda 
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
struct node* insert(struct node* node, int key)
{
    /* SI el arbol esta vacio regresa un nodo nuevo */
    if (node == NULL) return newNode(key);
 
    /* De otro modo sigue recorriendo el arbol ahcia abajo */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* Regresa el apuntador del nodo que no tuvo cambio  */
    return node;
}

void inorder(struct node *root,int *A,int *contador)
{
    if (root != NULL)
    {
        inorder(root->left);
        A[*contador]=root->key;
        //printf("%d \n", root->key);
        (*contador)++;

        inorder(root->right);
    }
}
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops
	struct node *root = NULL;

   	int *A;// crea el vector
  	int j,aux,cambios,contador;
	
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
    A = (int*)malloc((n+2)*sizeof(int));//reserva memoria para el tamaño que hemos indicado 
    
	meternumeros(A,n);
	root = insert(root, A[0]);
	for (i = 1; i<=n;i++)
	{
		   insert(root, A[i]);
   
		  
	}
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	

	inorder(root,*A,&contador);


	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	imprimir(A,n,utime0,utime1,stime0,stime1,wtime0,wtime1);
	//Cálculo del tiempo de ejecución del programa
	
	//Mostrar los tiempos en formato exponecial
	
	//******************************************************************
		
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

