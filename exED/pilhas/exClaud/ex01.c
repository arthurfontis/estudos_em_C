#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;
struct no
{
    int dado;
    p_no prox;
};

typedef struct pilha *p_pilha;
struct pilha
{
    p_no topo;
};

p_pilha criar_pilha()
{
    p_pilha p = malloc(sizeof(struct pilha));
    p->topo = NULL;
    return p;
}

void add_pilha(p_pilha p, int dado)
{
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilhar(p_pilha p)
{
    p_no ultimo = p->topo;
    int dado = ultimo->dado;
    p->topo = p->topo->prox;

    free(ultimo);
    return dado;
}

int balanceado(char *expr)
{
    int ok = 1;
    p_pilha p = criar_pilha();
    for (int i = 0; ok && expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            add_pilha(p, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            if (p->topo == NULL)
            {
                ok = 0;
            }
            else
            {
                char par = desempilhar(p);
                if (expr[i] == ')' && par != '(')
                    ok = 0;
                if (expr[i] == ']' && par != '[')
                    ok = 0;
                if (expr[i] == '}' && par != '{')
                    ok = 0;
            }
        }
    }
    if (p->topo != NULL)
    {
        return ok = 0;
    }

    return ok;
}