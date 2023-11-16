#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main (int argc, char **argv){
    int fd;
    char buff[1024];

    //controllo argomenti
    if (argc != 2){
        fprintf(stderr,"\nutilizzo: copy_input filename\n");
        exit(1);
    }

    //creo il file con la systemma call open, co relativi flag
    //e permessi 0644 rw-r--r--
    fd=open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd < 0){
        fprintf(stderr,"\nerrore: cannot create the file %s\n", argv[1]);
        exit(2);
    }

    //utilizzo di fgets, preleva la line ada uno stream
    printf("inserisci <end> per uscire...");
    printf("inserisci una stringa: ");
    fgets(buff, 1024, stdin);

    //se uso fgets avro in buff anche il carattere di new line
    //se uso scanf faccio il controllo solo con fine (senza /n)
    while (strcmp(buff, "end\n") != 0){
        write (fd, buff, strlen(buff));
        printf ("inserisci un altra stringa: ");
        fgets(buff, 1024, stdin);
    }
    close(fd);
    return 0;
}