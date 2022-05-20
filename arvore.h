struct Arv {
    int info;
    struct Arv *esq, *dir;
};
typedef struct Arv Arv;

Arv* arv_criavazia (void);
Arv* arv_cria (int c, Arv* e, Arv* d);
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
void arv_imprime (Arv* a);
void incrementar(Arv *a, int x);
Arv* primeiro_maior_que_x(Arv* a, int x);
void abb_imprime (Arv* a);
Arv* abb_busca (Arv* r, int v);
Arv* abb_insere (Arv* a, int v);
Arv* abb_cria (void);