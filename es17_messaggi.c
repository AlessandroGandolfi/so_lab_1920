/*
le code di messaggi sono simili ai pipe con 2 differenze:
    - i messaggi sono delimitati, i processi comunicano in unitá di messaggi e non stream byte indefiniti
    - ogni messaggio contiene un attributo di tipo intero che ne definisce il tipo

nel msgsz non devo tenere conto dei byte dell'mtype
in strutture per definire messaggi non ha senso inserire puntatori perché passando messaggi tra 
    processi, il proc destinatario non ha accesso alle aree di memoria del proc mittente
    quindi per passare stringhe non uso malloc ma char[n] per memorizzazione differente
*/