// open() restituisce unsigned int file descriptor o -1 nel caso di errore generico
// se voglio vedere errore specifico consulto errno
// int open(const char *pathname, int flags)
// uso file descriptor in programma per interagire con il file per operazioni di lettura, scrittura e riposizionamento

// valori file descriptor aperti automaticamente da unix all'avvio del programma per mappatura con dispositivo esterno
// posso cambiare mappatura ad altri file o dispositivi
// inizializzati in lib
// 0 stdin, standard input, flusso di input da tastiera
// 1 stdout, standard output, flusso di output a schermo
// 2 stderr, standard error output, finestra testuale della shell, flusso output errori a schermo

// valori dopo vengono settati all'apertura di ulteriori file
// valori simbolici di maschere da usare per definire accesso a file in secondo parametro
// O_RDONLY
// O_WRONLY
// O_RDWR

// esempio apertura in sola lettura
int fd = open({str pathname}, O_RDONLY);

// file creation flags
// O_APPEND, scrive in coda e non dal primo byte sovrascrivendo il contenuto
// O_CREAT, crea file al pathname specificato se non esistente
// O_TRUNC, se il file esiste giá "tronca" i suoi byte a 0 (da usare nel caso si voglia cancellare contenuto)
// esempio apertura in lettura scrivendo dal fondo del contenuto giá presente
int fd = open({str pathname}, O_RDONLY | O_APPEND);

// la creat() é l'equivalente di chiamare un open() con i flags O_CREAT|O_WRONLY|O_TRUNC

// errori
// EACCESS accesso al file negato o il file non esiste
// EEXIST file giá esistente usando flags O_CREAT o O_EXCL

// l'offset del file che specifica a che byte si é fermata operazione precedente (e da che byte opererá la prossima operazione)

// read() legge byte in file
// restituisce numero di byte effettivamente letti, -1 in caso di errore
// errno in caso di codice specifico
// ssize_t read(int fd, void *buf, size_t count)
// primo parametro fd
// secondo parametro puntatore a zona dove va a copiare ció che legge
// terzo parametro numero di byte da leggere
// offset viene incrementato in base al terzo parametro o numero di byte in file se minore di count

// esempio lettura e stampa di valori letti
char buf[512];
int n = read(fd, buf, 512); // se riesce a leggerli tutti n verrá valorizzato anche a 512
                            // in buf verranno salvati i 512 byte
while(i < 512) {
    printf("%c", buf[i++]);
}

// lseek() modifica offset a un certo valore (?)
// off_t lseek(int fd, off_t offset, int whence)
// primo parametro fd del file
// secondo parametro byte di modifica di offset a partire dal terzo parametro (di solito)
// terzo parametro usa cost simb, setta offset del file a quel valore
// SEEK_SET viene usata per settare l'offset del file al secondo parametro
// SEEK_CUR all'offset del file vengono aggiunti offset (secondo parametro) byte
// SEEK_END viene usata per settare l'offset del file alla fine di esso

// close() serve a liberare risorse riguardanti file e chiuderlo
// ha come parametro il fd del file