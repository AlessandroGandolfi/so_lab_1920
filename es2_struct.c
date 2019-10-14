// etichetta usata come se fosse tipo di dato in dichiarazioni seguenti
struct point {
    double x;
    double y;
    double z;
};

// dichiarazione variabili o, p1, p2, p3 di tipo struct point 
struct point o, p1, p2, p3;

// valorizzazioni attributi strutture
o.x = 0;

// "creazione" struttura java
struct int_array_of_ten {
    int a[10];
    int length = 10;
};

struct int_array_of_ten pippo;
pippo.a[3];
pippo.length; // 10
