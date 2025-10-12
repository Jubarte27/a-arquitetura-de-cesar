
typedef unsigned short int WORD;
typedef short int SWORD;

void uint2str (char *, WORD);
void int2str (char *, SWORD);
SWORD str2int (char *);
void void_str2int (SWORD *, char *);

int main()
{
    char str[20];
    SWORD res;

    uint2str(str, 10);

    int2str(str, 10);
    int2str(str, -20);

    res = str2int("32");
    res = str2int("-32");

    void_str2int(&res, "32");
    void_str2int(&res, "-32");

    return 0;
}

/**************************************************************
Função:
    Converte um número de 16 bits SEM sinal para ASCII.
    Coloca o resultado em um string.
    O valor resultante no string possui, sempre, 5 dígitos.
    São colocados zeros à esquerda para preenchimento
Parâmetros:
    n: valor numérico a ser convertido (inteiro sem sinal de 16 bits)
    s: ponteiro para o string onde colocar o resultado
**************************************************************/
WORD  Tab10[] = { 10000, 1000, 100, 10 };
void uint2str (char *s, WORD n) {

    WORD Lacos;
    char dig;
    WORD *pTab10;

    pTab10 = Tab10;
    Lacos = 4;
    do {
        dig = '0';
        while (n >= *pTab10) {
            ++dig;
            n -= *pTab10;
        }
        *s++ = dig;
        ++pTab10;
    } while (--Lacos);

    *s++ = n + '0';
    *s = '\0';
}

/**************************************************************
Função:
    Converte um número de 16 bits COM sinal para ASCII.
    Coloca o resultado em um string.
    O valor resultante terá um sinal negativo, caso o número for negativo.
    Então, seguem 5 dígitos, com o preenchimento de zeros à esquerda.
Parâmetros:
    n: valor numérico a ser convertido (inteiro com sinal de 16 bits)
    s: ponteiro para o string onde colocar o resultado
**************************************************************/
void int2str (char *s, SWORD n) {

    if (n<0) {
        n = -n;
        *s++ = '-';
    }
    uint2str(s, (WORD)n);
}

/**************************************************************
Função:
    Converte o conteúdo ASCII de um string em seu correspondente valor numérico.
    O valor numérico terá 16 bits COM sinal.
    A função não apresenta nenhuma indicação de erro de conversão.
    Nesse caso, o valor numérico é imprevisto.
Parâmetros:
    s: ponteiro para o string onde está o número a ser convertido.
Retorno:
    Retorna o valor numérico calculado
**************************************************************/
SWORD str2int (char *s) {
    WORD neg;
    WORD n;

    neg = 0;
    if ( *s == '-' ) {
        neg = 1;
        ++s;
    }

    n = 0;
    while ( *s != '\0' ) {
        n = 10 * n + (*s - '0');
        ++s;
    }

    if (neg)
        n = -n;

    return n;
}

/**************************************************************
Função:
    Converte o conteúdo ASCII de um string em seu correspondente valor numérico.
    O valor numérico terá 16 bits COM sinal.
    A função não apresenta nenhuma indicação de erro de conversão.
    Nesse caso, o valor numérico é imprevisto.
Parâmetros:
    s: ponteiro para o string onde está o número a ser convertido.
    n: ponteiro para a variável inteira que receberá o resultado.
**************************************************************/
void void_str2int (SWORD *n, char *s) {
    *n = str2int(s);
}


