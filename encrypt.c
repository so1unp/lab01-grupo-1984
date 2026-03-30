#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>   

void encriptar_byte(unsigned char c) {
    unsigned char basura;
    // 1. Enviamos 7 bytes aleatorios
    for (int i = 0; i < 7; i++) {
        basura = (unsigned char)rand();
        if (write(1, &basura, 1) == -1) {
            perror("Error al escribir basura");
            exit(EXIT_FAILURE);
        }
    }
    // 2. Enviamos el byte real 
    if (write(1, &c, 1) == -1) {
        perror("Error al escribir mensaje");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    
    // Inicializamos la semilla
    srand(time(NULL)); 

    if (argc > 1) {
        // El mensaje viene por argumento
        char *mensaje = argv[1];
        for (int i = 0; mensaje[i] != '\0'; i++) {
            encriptar_byte((unsigned char)mensaje[i]);
        }
    } else {
        unsigned char buffer;
        while (read(0, &buffer, 1) > 0) {
            encriptar_byte(buffer);
        }
    }

    exit(EXIT_SUCCESS);
}