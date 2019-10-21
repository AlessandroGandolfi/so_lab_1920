// open() restituisce unsigned int file descriptor o -1 nel caso di errore generico
// se voglio vedere errore specifico consulto errno
// int open(const char *pathname, int flags)
// uso file descriptor in programma per interagire con il file per operazioni di lettura, scrittura e riposizionamento

// valori file descriptor aperti automaticamente da unix all'avvio del programma
// 0 stdin, flusso di input
// 1 stdout, flusso di output
// 2 stderr, finestra testuale della shell, usato per errori

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

// la creat() é l'equivalente di chiamare un open() con i file O_CREAT|O_WRONLY|O_TRUNC

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

// esempio lettura
char buf[512];
int n = read(fd, buf, 512); // se riesce a leggerli tutti n verrá valorizzato anche a 512
                            // in buf verranno salvati i 512 byte
while(i < 512) {
    printf("%c", buf[i++]);
}

// lseek({int}) modifica offset a un certo valore (?)