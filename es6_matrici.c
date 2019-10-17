const int totrows = 2, totcols = 3;
int a[totrows][totcols];

// normale utilizzo 
a[i][j]; // riga i, colonna j

// singolo puntatore, come array
a[i * totcols + j]; // = a[i][j]

// tramite puntatore diretto
*(a + (i * totcols + j));