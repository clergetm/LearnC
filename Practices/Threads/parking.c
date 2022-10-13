#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/**
 * Structure de synchronisation
*/
typedef struct synchro_s {
    int nb_libre;
    pthread_mutex_t mutex;
    pthread_cond_t condition;
} synchro_t;

void * entrer_parking(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_t tid = pthread_self();
    pthread_mutex_lock(&(st->mutex));
        printf("Thread : %x - Entrer parking\n",(unsigned int) tid);
        while(st->nb_libre == 0)
            pthread_cond_wait(&(st->mutex),&(st->condition));
        
        st->nb_libre--;
    pthread_mutex_unlock(&(st->mutex));

    return;
}

void * sortin_parking(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_mutex_lock(&(st->mutex));
    pthread_t tid = pthread_self();
        printf("Thread : %x - Sortir parking\n",(unsigned int) tid);

        st->nb_libre++;
        pthread_cond_signal(&(st->condition));
    
    pthread_mutex_unlock(&(st->mutex));

    return;
}

void * voiture(void *arg){
    entrer_parking(arg);
    pthread_t tid = pthread_self();
    srand((int) tid);

    usleep(rand()/ RAND_MAX * 10000);
    sortin_parking(arg);
    return;
}

#define NB_VOITURE 100
int main(int argc,char **argv){
    synchro_t MY_PARKING;
    MY_PARKING.nb_libre = NB_VOITURE;
    pthread_mutex_init(&MY_PARKING.mutex,NULL);
    pthread_cond_init(&MY_PARKING.condition,NULL);
    pthread_t* tids[NB_VOITURE];
    for(int i = 0; i < NB_VOITURE; i++){
        pthread_create(&tids[i],NULL,voiture,&MY_PARKING);
    }

    for(int j = 0; j < NB_VOITURE; j++){
        if(pthread_join(tids[j],NULL) != 0){ 
            printf("Erreur Join [%d]",j);
            return -1;
        }
    }
    printf("END MAIN\n");

    pthread_mutex_destroy(&(MY_PARKING.mutex));
    return 0;
}