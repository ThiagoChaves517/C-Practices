// Hello, devs!
//
//This code in specific was delivered to broken previously and send as a homework for the "Sistemas Operacionais" subject in UFAM, 
//oriented by professor André Carvalho.
//
//Our mission was to fix a multithreading program that had no protection against race conditions: we needed to make the program "thread-safe". 
//Here is my result of making it "thread-safe" with semaphores and other mecanisms.

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t mutex1;
sem_t mutexBuffer1;
sem_t mutexBuffer2;

sem_t cheio1;
sem_t vazio1;
sem_t cheio2;
sem_t vazio2;

int max;
int loops;
int *buffer1,*buffer2;

int consome1  = 0;
int produz1 = 0;
int consome2  = 0;
int produz2= 0;


#define MAX (10)
int consumidores = 1;
int produtores = 1;
int nambos = 1;

int totalDeProducao = 0;
int totalConsumido = 0;

void produz(int valor, int buf) {
   totalDeProducao++;
   if(buf==1){
      sem_wait(&mutexBuffer1);
      buffer1[produz1] = valor;

      produz1 = (produz1+1) % max;
      sem_post(&mutexBuffer1);

   }else{
      sem_wait(&mutexBuffer2);
      buffer2[produz2] = valor;

      produz2 = (produz2+1) % max;
      sem_post(&mutexBuffer2);

   }
}

int consome(int buf) {
   int tmp; 
   totalConsumido++;
   if(buf==1){
      sem_wait(&mutexBuffer1);
      tmp = buffer1[consome1];
      consome1 = (consome1+1) % max;
      sem_post(&mutexBuffer1);
   }else{
      sem_wait(&mutexBuffer2);
      tmp = buffer2[consome2];
      consome2 = (consome2+1) % max;
      sem_post(&mutexBuffer2);
   }

   return tmp;
}

void *produtor(void *arg) {
   int i;
   for (i = 1; i <= loops; i++) {
      sem_wait(&vazio1); 
      sem_wait(&mutex1);
         
      produz(i, 1);
      printf("Produtor #%lld produziu %d em Buffer 1\n", (long long int) arg, i);
      //printf("Produzido: %d\n\n", totalDeProducao);

      sem_post(&mutex1);
      sem_post(&cheio1);
   }
   printf("Produtor %d finalizado\n\n", *((int*)arg));
   return NULL;
}

void *consumidor(void *arg) {
   int tmp = 0;
   while (totalConsumido < loops) {
      
      sem_wait(&cheio2);
      sem_wait(&mutex1);

      tmp = consome(2);
      printf("Consumidor #%lld consumiu %d de Buffer 2\n", (long long int) arg, tmp);
      //printf("Consumido: %d\n\n", totalConsumido);

      sem_post(&mutex1);
      sem_post(&vazio2);
   }

   printf("Consumidor %d finalizado\n\n", *((int*)arg));

   return NULL;
}

void *ambos(void *arg) {
   int tmp = 0;
   while (totalConsumido < loops) {
   //--------------------------------------------------------------

      sem_wait(&cheio1);
      sem_wait(&mutex1);

      tmp = consome(1);
      printf("Ambos #%lld consumiu %d em Buffer 1\n", (long long int) arg, tmp);

      sem_post(&mutex1);
      sem_post(&vazio1);

   //--------------------------------------------------------------

      sem_wait(&vazio2);
      sem_wait(&mutex1);

      produz(tmp, 2);
      printf("Ambos #%lld produziu %d em Buffer 2\n", (long long int) arg, tmp);

      sem_post(&mutex1);
      sem_post(&cheio2);
      
   //--------------------------------------------------------------
   }
   printf("Ambos %d finalizado\n\n", *((int*)arg));
   return NULL;
}

int main(int argc, char *argv[]) {
   if (argc != 6) {
      fprintf(stderr, "uso: %s <tambuffer> <loops> <produtores> <consumidores> <ambos>\n", argv[0]);
      exit(1);
   }
   max   = atoi(argv[1]);
   loops = atoi(argv[2]);
   produtores = atoi(argv[3]);
   consumidores = atoi(argv[4]);
   nambos = atoi(argv[5]);
   assert(consumidores <= MAX);

   buffer1 = (int *) malloc(max * sizeof(int));
   buffer2 = (int *) malloc(max * sizeof(int));
   int i;

   for (i = 0; i < max; i++) {
      buffer1[i] = 0;
      buffer2[i] = 0;
   }

   sem_init(&mutex1, 0, 1); //Semáforo Binário
   sem_init(&mutexBuffer1, 0, 1); //Semáforo Binário
   sem_init(&mutexBuffer2, 0, 1); //Semáforo Binário

   sem_init(&vazio1, 0, max); 
   sem_init(&cheio1, 0, 0); 
   sem_init(&vazio2, 0, max); 
   sem_init(&cheio2, 0, 0); 

   pthread_t pid[MAX], cid[MAX], aid[MAX];
    int id[MAX];
    for (i = 0; i < consumidores; i++) {
        id[i] = i + 1;
        pthread_create(&cid[i], NULL, consumidor, &id[i]);
    }
    for (i = 0; i < nambos; i++) {
        id[i] = i + 1;
        pthread_create(&aid[i], NULL, ambos, &id[i]);
    }
    for (i = 0; i < produtores; i++) {
        id[i] = i + 1;
        pthread_create(&pid[i], NULL, produtor, &id[i]);
    }

   for (i = 0; i < consumidores; i++) {
        pthread_join(cid[i], NULL);
    }
    for (i = 0; i < nambos; i++) {
        pthread_join(aid[i], NULL);
    }
    for (i = 0; i < produtores; i++) {
        pthread_join(pid[i], NULL);
    }

   return 0;
}


