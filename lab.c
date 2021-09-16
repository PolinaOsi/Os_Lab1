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
    return NULL;
}

int main (int  argc, char *argv[]) {
    pthread_t id_of_thread;
    int result_of_creation = pthread_create (&id_of_thread, NULL, print, "child ");
    if (result_of_creation != SUCCESS_OF_CREATION) {
        perror("Thread was not created!");
        exit(EXIT_FAILURE);
    }
    print("parent ");
    pthread_exit(EXIT_SUCCESS);
}
