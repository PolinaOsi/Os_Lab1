#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

static const int SUCCESS_OF_CREATION = 0;

void *print(void *whois) {
    for (int i = 0; i < 10; i++) {
        printf("%s%d\n", (char*)whois, i + 1);
    }
    free((char*)whois);
    return EXIT_SUCCESS;
}

int main (int  argc, char *argv[]) {
    pthread_t id_of_thread;
    int LENGHT_OF_STRING = 7;
    char *childText = (char*)malloc(sizeof(char)*LENGHT_OF_STRING);
    strcpy(childText, "child ");
    char *parentText = (char*)malloc(sizeof(char)*LENGHT_OF_STRING);
    strcpy(parentText, "parent ");
    int result_of_creation = pthread_create (&id_of_thread, NULL, print, childText);
    if (result_of_creation != SUCCESS_OF_CREATION) {
        perror("Thread was not created!");
        free(childText);
        exit(EXIT_FAILURE);
    }
    print(parentText);
    pthread_exit(EXIT_SUCCESS);
}
