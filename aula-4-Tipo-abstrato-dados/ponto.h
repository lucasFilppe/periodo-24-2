/*Tad Ponto(x,y)*/

#ifndef ponto_h
#define ponto_h

//somente o nome do novo tipo
typedef struct ponto Ponto; //não é vissivel para o usuario

//aloca dinamicamente mémoria para um ponto com coordenadas x e y
Ponto* PontoCria( float x, float y);

//libera a memoria alocada para um ponto
void PontoLibera(Ponto** p);

//devolve as coordenadas de um ponto
void PontoAcessa(Ponto* p, float* x, float* y);

//atribui novos valores a um ponto
void PontoAtribui(Ponto* p, float x, float y);

//calculA a distancia entre dois pontos
float PontoDistancia(Ponto *p1, Ponto* p2);

#endif
