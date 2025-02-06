typedef struct _TItem;
typedef struct celula;
typedef struct _TLista;


//procedimentos e funçoes basicas
void TLista_Inicia(TLista *pLista);
int TLista_EhVazia(TLista *pLista);
int Tlista_Insere(TLista *pLista, TItem x);
int TLista_RetiraPrimeiro(TLista *pLista, TItem *px);
void TLista_Imprime(TLista *PLista);