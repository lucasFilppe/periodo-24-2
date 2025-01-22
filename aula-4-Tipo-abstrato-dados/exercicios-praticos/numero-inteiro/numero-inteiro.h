typedef struct vetor Vetor;

Vetor* Vetor_Cria(int tamanho);

void Vetor_Libera(Vetor* v);

int Vetor_Get(Vetor* v, int indice); 

void Vetor_Set(Vetor* v, int indice, int valor);

void Vetor_Imprime(Vetor* v);