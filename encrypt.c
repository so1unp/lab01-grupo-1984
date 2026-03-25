#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>  
#include <string.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    char buffer;
    if (argc > 1) {
        // Si el mensaje viene en argv[1]
        char *message = argv[1];
        int largo = strlen(message);

        for (int i = 0; i < largo; i++) {
            //los 7 randoms
            write7randoms();
            // el verdadero byte
            write(1, &message[i], 1);
        }
    } else {
        // si viene de la otra salida
        while (read(0, &buffer, 1) > 0) {
            // Generar 7 bytes de basura
            write7randoms();
            // Escribir el byte que acabamos de leer
            write(1, &buffer, 1);
        }
    }

    exit(EXIT_SUCCESS);
}

void write7randoms(){
    for (int j = 0; j < 7; j++) {
        char garbage = (char)(rand() % 256);
        write(1, &garbage, 1); 
    }
            
}
