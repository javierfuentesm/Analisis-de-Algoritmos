/* Arbol binario de busqueda. Implementación iterativa */
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct Arbol
{
int info;
struct Arbol* izq;
struct Arbol* der;
}arbol;
/* Estructura para las pilas auxiliares. Pilas de árboles. */
typedef struct Pilas
{
arbol* info;
struct Pilas* cimaant;
}pilas;
/* Estructuras para las cola auxiliar. Cola de árboles. */
typedef struct Nodoc
{
arbol* info;
struct Nodoc* sig;
}nodoc;
typedef struct
{
nodoc* prim;
nodoc* ulti;
}colas;
/* Rutinas para manipular el árbol */
void inicializar(arbol ** a);
int vacio(arbol* a);
void insertar(arbol** a, int e);
arbol* construir(arbol* a, int e, arbol* b);
void borrar(arbol** a, int c);
void menor(arbol* a, int* e);
void eliminar( arbol ** a);
void buscar(arbol** a, int c, int* encontrado);
void recorreras(arbol* a);
void recorrerdes(arbol* a);
void recorrerniveles(arbol* a);
void preorden(arbol* a);
void postorden(arbol* a);
/* funciones para el manejo de las pilas auxiliares */

void inicializarpa( pilas** p);
int vaciapa(pilas* p);
void apilarpa(pilas** p, arbol* e);
void desapilarpa(pilas** p, arbol** e);
/* funciones para el manejo de la cola auxiliar */
void inicializarca(colas* c);
int vaciaca(colas c);
void ponerca(colas* c, arbol* e);
void quitarca(colas* c);
void primeroca(colas c, arbol** e);
/* Implementación de las funciones para manipular el árbol */
void inicializar(arbol ** a)
{
*a = NULL;
}
int vacio(arbol* a)
{
return a == NULL;
}
void buscar(arbol** a, int c, int * encontrado)
{
arbol* pactual;
pactual = *a; *encontrado = False;
while ((pactual != NULL) && ! encontrado)
if (pactual->info == c)
{
*encontrado = True;
printf(" %d ", pactual->info);
}
else
if (pactual->info > c)
pactual = pactual->izq ;
else
pactual = pactual->der;
}
arbol* construir(arbol* a, int e, arbol* b)
{
arbol* nuevo;
nuevo = (arbol*)malloc(sizeof(arbol*));
nuevo->info = e;
nuevo->izq = a;
nuevo->der = b;
return nuevo;
}

void insertar(arbol ** a, int e)
{
arbol* pactual;
int encontradositio;
if (vacio(*a))
*a = construir(NULL, e, NULL);
else
{
pactual = *a; encontradositio = False;
while (! encontradositio)
if (pactual->info == e)
encontradositio = True;
else
if (pactual->info > e)
if (pactual->izq == NULL)
{
pactual->izq = construir(NULL, e, NULL);
encontradositio = True;
}
else
pactual = pactual->izq;
else
if (pactual->der == NULL)
{
pactual->der = construir(NULL, e, NULL);
encontradositio = True;
}
else
pactual = pactual->der;
}
}
void menor(arbol* a, int * e)
{
arbol* pactual;
pactual = a;
while (pactual->izq != NULL)
pactual = pactual->izq;
*e = pactual->info;
}
void eliminar( arbol ** a)
{
arbol* auxi;
int e;
if ((*a)->izq == NULL)
{
auxi = *a; *a = (*a)->der;
free(auxi);
}
else
if ((*a)->der == NULL)
{
auxi = *a; *a = (*a)->izq;
free(a);
}
else
{
menor((*a)->der, &e); (*a)->info = e;
borrar(&(*a)->der, e);
}
}
void borrar(arbol** a, int c)
{
arbol* pactual;
int buscando;
if (*a != NULL)
if ((*a)->info == c)
eliminar(a);
else
{
pactual = *a; buscando = True;
while (buscando)
if (pactual->info > c)
if (pactual->izq == NULL)
buscando = False;
else
if (pactual->izq->info == c)
{
eliminar(& pactual->izq);
buscando = False;
}
else
pactual = pactual->izq;
else
if (pactual->der == NULL )
buscando = False;
else
if (pactual->der->info == c)
{
eliminar(& pactual->der);
buscando = False;
}
else
pactual = pactual->der;
}
}
void recorreras(arbol* a)
{
arbol* pactual;
pilas* pila;
inicializarpa(&pila);
pactual = a;
while (! vacio(pactual) || ! vaciapa(pila))
if (pactual == NULL)
{
desapilarpa(&pila, & pactual);
printf(" %d ", pactual->info);
pactual = pactual->der;
}
else
{
apilarpa(&pila, pactual);
pactual = pactual->izq;
}
}
void recorrerdes(arbol* a)
{
arbol* pactual;
pilas* pila;
inicializarpa(&pila); pactual = a;
while (! vacio(pactual) || ! vaciapa(pila))
if (pactual == NULL)
{
desapilarpa(& pila, & pactual);
printf(" %d ", pactual->info);
pactual = pactual->izq;
}
else
{
apilarpa(& pila, pactual);
pactual = pactual->der;
}
}
void recorrerniveles(arbol* a)
{
arbol* pactual;
colas cola;
if (! vacio(a))
{
inicializarca(& cola); pactual = a; ponerca(&cola, a);
while (! vaciaca(cola))
{
primeroca(cola, &pactual); quitarca(&cola);
printf(" %d ", pactual->info);
if (! vacio(pactual->izq))
ponerca(&cola, pactual->izq);
if (! vacio(pactual->der))
ponerca(&cola, pactual->der);
}
}
}
void preorden(arbol* a)
{
pilas* pila;
arbol* pactual;
inicializarpa(&pila);
pactual = a;
while (! vaciapa(pila) || ! vacio(pactual))
if (vacio(pactual))
desapilarpa(&pila, &pactual);
else
{
printf(" %d ", pactual->info);
apilarpa(&pila, pactual->der);
pactual = pactual->izq ;
}
}
void postorden(arbol* a)
{
pilas* pila;
pilas* vuelta;
arbol* pactual;
inicializarpa(& pila);
inicializarpa(& vuelta);
pactual = a;
while (! vaciapa(pila) || ! vacio(pactual))
if (vacio(pactual))
desapilarpa(& pila, & pactual);
else
{
apilarpa(& vuelta, pactual);
apilarpa(& pila, pactual->izq);
pactual = pactual->der;
};
while (! vaciapa(vuelta))
{
desapilarpa(&vuelta, &pactual);
printf(" %d ", pactual->info);
}
}


int main()
{
int nm;
arbol* a;
char pausa;
inicializar (&a);
printf("Deme numero (0 -> Fin): ");
scanf("%d", &nm);
while (nm !=0)
{
insertar(&a,nm);
printf("Deme numero (0 -> Fin): ");
scanf("%d", &nm);
}
printf("Preorden: \n");
preorden(a);
puts("");
printf("Postorden: \n");
postorden(a);
puts("");
printf("Niveles: \n");
recorrerniveles(a);
puts("");
pausa = getch();
return 0;
}
/* Pila de árboles. Implementación */
void inicializarpa(pilas** p)
{
*p = NULL;
}
void desapilarpa(pilas **p, arbol ** a)
{
pilas *nn;
if (vaciapa(*p))
exit (1);
*a = (*p)->info;
nn =*p;
*p = nn->cimaant;
free(nn);
}
int vaciapa(pilas *p)
{
return p == NULL;
}
void apilarpa(pilas** p, arbol* elemento)
{
pilas * nn;
nn = (pilas*)malloc(sizeof(pilas*));
nn->info = elemento;
nn->cimaant = *p;
*p=nn;
}
void inicializarca(colas* c)
{
(*c).prim = NULL;
(*c).ulti = NULL;
}
/* Cola de arboles. Implementación */
void ponerca(colas* c, arbol* e)
{
nodoc * nn;
nn = (nodoc*)malloc(sizeof(nodoc*));
nn->info = e;
nn->sig = NULL;
if (vaciaca(*c))
(*c).prim=nn;
else
(*c).ulti->sig = nn;
(*c).ulti = nn;
}
void quitarca(colas* c)
{
nodoc* nn;
if (vaciaca(*c))
exit (1);
nn = (*c).prim;
(*c).prim = (*c).prim->sig;
if ((*c).prim == NULL)
(*c).ulti = NULL;
free(nn);
}
int vaciaca(colas c)
{
return (c.prim == NULL) && (c.ulti == NULL);
}
void primeroca(colas c, arbol** e)
{
*e = c.prim->info;
}