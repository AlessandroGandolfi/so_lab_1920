// campi allocati a stesso indirizzo di memoria
// programmatore tiene conto di cosa é salvato nel momento di utilizzo 
// una struttura potrebbe tenere piú byte di quelli calcolati dalla somma dei tipi dei campi a causa dei vincoli di allineamento
// prende tanti byte quanti ne servono per salvare il campo che ne richiede di piú
union label {
    int i;  // 4 byte
    long t; // 8 byte
    char c; // 1 byte
} u;

// esempio utilizzo
u.t = 6.7;
u.i += 6;

// weekdays puó assumere solo i valori nelle graffe
enum weekdays { LUN = 0, MAR = 1, MER = 2, GIO = 3, VEN = 4 };
enum weekdays d;
// per il compilatore sono uguali
d = LUN;
d = 0;

// usando il typedef
enum _weekdays { LUN, MAR, MER, GIO, VEN };
typedef enum _weekdays weekdays;
// oppure
typedef enum { LUN, MAR, MER, GIO, VEN } weekdays;

weekdays d;

// esempio enum per un boolean
typedef enum { false, true } boolean;
boolean a = false;
