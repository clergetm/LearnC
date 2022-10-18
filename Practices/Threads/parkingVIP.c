#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/**
 * Structure de synchronisation
*/
typedef struct synchro_s {
    int nb_libre, nb_VIP_attente;
    pthread_mutex_t mutex;
    pthread_cond_t condition_normal;
    pthread_cond_t condition_VIP;
} synchro_t;

void * entrer_parking(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_t tid = pthread_self();
    pthread_mutex_lock(&(st->mutex));
        printf("Thread : %x - Entrer parking\n",(unsigned int) tid);
        while(st->nb_libre == 0)
            pthread_cond_wait(&(st->mutex),&(st->condition_normal));
        
        st->nb_libre--;
    pthread_mutex_unlock(&(st->mutex));

    return;
}

void * entrer_VIP(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_t tid = pthread_self();
    pthread_mutex_lock(&(st->mutex)); 
            printf("-VIP-Thread : %x - Entrer parking\n",(unsigned int) tid);

        while(st->nb_libre == 0)
            pthread_cond_wait(&(st->mutex),&(st->condition_VIP));
        st->nb_libre--;
        st->nb_VIP_attente--;
    pthread_mutex_unlock(&(st->mutex));
}

void * sortir_parking(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_mutex_lock(&(st->mutex));
    pthread_t tid = pthread_self();
        printf("Thread : %x - Sortir parking\n",(unsigned int) tid);

        st->nb_libre++;
        if(st->nb_VIP_attente){
            printf("-VIP-Thread : %x - Signal\n",(unsigned int) tid);
            pthread_cond_signal(&(st->condition_VIP));
        } else {
            printf("-Thread : %x - Signal\n",(unsigned int) tid);
            pthread_cond_signal(&(st->condition_normal));
        }
    
    pthread_mutex_unlock(&(st->mutex));

    return;
}


void * sortir_VIP(void *arg){
    synchro_t * st = (synchro_t *)arg;
    pthread_mutex_lock(&(st->mutex));
    pthread_t tid = pthread_self();
        printf("-VIP-Thread : %x - Sortir parking\n",(unsigned int) tid);

        st->nb_libre++;
        if(st->nb_VIP_attente){
            printf("-VIP-Thread : %x - Signal\n",(unsigned int) tid);
            pthread_cond_signal(&(st->condition_VIP));
        }
    
    pthread_mutex_unlock(&(st->mutex));

    return;
}

void * voiture(void *arg){
    entrer_parking(arg);
    pthread_t tid = pthread_self();
    srand((int) tid);

    usleep(rand()/ RAND_MAX * 1000000000);
    sortir_parking(arg);
    return;
}

void * voiture_VIP(void *arg){
    entrer_VIP(arg);
    pthread_t tid = pthread_self();
    srand((int) tid);

    usleep(rand()/ RAND_MAX * 1000000000000000000000000000);
    sortir_VIP(arg);
    return;
}

#define NB_VOITURE 100
#define NB_VIP 10
int main(int argc,char **argv){
    synchro_t MY_PARKING;
    MY_PARKING.nb_libre = NB_VOITURE;
    MY_PARKING.nb_VIP_attente = NB_VOITURE/10;
    pthread_mutex_init(&MY_PARKING.mutex,NULL);
    pthread_cond_init(&MY_PARKING.condition_normal,NULL);
    pthread_cond_init(&MY_PARKING.condition_VIP,NULL);
    pthread_t* tids[NB_VOITURE];

    // 100 places libres pour 110 voitures (100 normales | 10 VIP)
    /* for(int i = 0; i < NB_VIP; i++){
        pthread_create(&tids[i],NULL,voiture_VIP,&MY_PARKING);
    } */
    for(int i = 0; i < NB_VOITURE; i++){
        if(i % 10 == 0)
            pthread_create(&tids[i],NULL,voiture_VIP,&MY_PARKING);
        else
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