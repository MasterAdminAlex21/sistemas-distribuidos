#include <stdio.h>
#include <signal.h>

void tratar_alarma(int num){
   printf("Señal %d\n",num);
}



int main(void)
{
   struct sigaction act;
   sigset_t mask;
   /* especifica el manejador */
   act.sa_handler = (void *)tratar_alarma; /*funcion a ejecutar */
   act.sa_flags = 0; /* Ninguna accion especifica */
   
   /* Se bloquea la señal 3 SIGQUIT */
   sigemptyset(&mask);
   //sigaddset(&mask, SIGQUIT);
   //sigaddset(&mask, SIGALRM);
   sigaddset(&mask, SIGTSTP);
   sigprocmask(SIG_SETMASK, &mask, NULL);
   sigaction(SIGALRM, &act, NULL);
   for(;;){
      ualarm(500000,0); /* se arma el temporizador */
      printf("UNO\n");
      pause(); /* se suspende el proceso hasta que se reciba la señal */
      printf("DOS\n");
   }
}

/*



*/
