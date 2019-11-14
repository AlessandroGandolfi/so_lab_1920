/*
un segnale é una notifica ad un processo che é occorso un certo evento
principali cause:
    - eccezione hardware
    - utente
    - evento software
sono definiti con nomi simbolici con valore intero unico (SIGxxxx)
i valori cambiano a seconda delle implementazioni, quindi é raccomandato usare i nomi simbolici
un segnale viene consegnato ("delivered") ad un processo dopo essere stato generato
il processo che riceve il segnale esegur qualche azione in risposta al segnale
nel lasso di tempo tra la generazione e la consegna del segnale quest'ultimo é pendente ("pending")
*/