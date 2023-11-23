#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char **argv)
{
    char s[20];
    char f[10];
    int c=0, i, e;
    printf("\nscrivi una frase stampa al contrario: ");
    scanf("%s", s);
    c=strlen(s);
    e=c-1;
    for (i=0;i<c;i++)
    {
        f[i]=s[e];
        e--;
    }
    printf("%s\n", f);
    printf("\n\n");
}