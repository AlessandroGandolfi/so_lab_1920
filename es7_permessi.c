// operatori | (or), & (and), ~ (not)
// | usato per settare uno o piú bit di un insieme di flags per permessi di file
// & usato per verificare i flags dei permessi del file aperto
// ~ nega flags, ha prioritá su | e &

// uso numero equivalente in decimale di bit per permessi
#define RD 2    // definizione maschera lettura file
                // bit seconda posizione
#define WR 4    // definizione maschera scrittura file
                // bit terza posizione
#define NOTRD 0xfd  // definizione maschera not read in esadecimale
                    // soluzione non corretta in base a macchina per lunghezza interi
                    // potrebbe essere 0xfffd su altre macchine, meglio usare ~

// esempio |
// metto in lettura il file a
a:  0110 1001
    0000 0010
    ---------
    0110 1011 a | RD

// metto in scrittura il file a
a:  0110 1001
    0000 0100
    ---------
    0110 1101 a | WR

// posso fare anche a|RD|WR

// esempio &
// controllo che il file aperto sia in scrittura
a:  0110 1001
    0000 0100
    ---------
    0000 0000 a & WR

// possibile utilizzo
if(a & WR) {

} else {

}

// esempio ~
a:  0100 0111
    ---------
    1011 1000 ~a

a:  0110 1011
    1111 1101
    --------- 
    0110 1001 a & ~RD