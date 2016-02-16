---
layout: default
---

# Elementi di Programmazione e Sviluppo di Applicazioni

Il seguente documento mira a integrare il materiale presentato di mano in mano nel corso IFTS per la parte riguardante il modulo di *Elementi di Programmazione e Sviluppo di Applicazioni*.

In caso di problemi (link mancanti, problemi di visualizzazione...) si prega di contattare direttamente [Danilo Pianini](mailto:danilo.pianini@unibo.it).

## Lezione 00: presentazione del corso

Questa parte del corso ha le proprie slides in formato `pdf`. Sono reperibili [a questo link](01/slides/slides.pdf).

La macchina virtuale utilizzata nel corso è disponibile [clickando qui](https://mega.nz/#!LME2VLTa!2kivBCadVDo-hHcoxVbhJazkvw7r4Euk1QqxWroggYc).

## Lezione 01: primi esperimenti col linguaggio C, compilazione

### Il linguaggio C

Il linguaggio C è un linguaggio di programmazione nato negli anni 70 (ufficialmente nel 1972) per mano principalmente di [Dennis Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie), [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson), e [Brian Kernighan](https://en.wikipedia.org/wiki/Brian_Kernighan).
L'obiettivo del linguaggio era quello di consentire di riscrivere il sistema operativo [UNIX](https://en.wikipedia.org/wiki/Unix), prima scritto in assembler, con un linguaggio di "livello più alto", (ossia capace di esprimere in modo succinto sequenze di istruzioni assembly anche complicate), nonché più *portabile* (ossia il cui codice potesse essere utilizzato su più macchine).

Dati i requisiti, C è un linguaggio fatto da esperti e indirizzato ad esperti, che espone fin da subito alcuni dettagli - anche subdoli - del sistema sottostante.
A fare da contraltare alla sua difficoltà (se confrontato a linguaggi moderni) c'è la capacità di produrre software particolarmente veloce.
A causa di questa importante caratteristica, C è **molto** utilizzato tutt'oggi, in particolare su sistemi "performance critical" (sistemi operativi, simulatori, sistemi embedded...) e sistemi dove si ha necessità di controllare direttamente l'hardware.
Il linguaggio C ebbe un successo molto ampio, che ne fecero nascere dei "dialetti", cui seguirono una serie di tentativi di standardizzazione ad opera di ISO/IEC, che richiesero comunque quasi 20 anni per arrivare al primo risultato:

* **ISO/IEC 9899:1990** -- Comunemente detto **ANSI C** o **C89** -- 1990
* **ISO/IEC 9899:1999** -- Comunemente detto **C99** -- 1999
* C1X (non ancora ufficialmente standardizzato...) -- Comunemente detto **C11** -- 1999

### Interpreti e compilatori

I linguaggi di programmazione si dividono in due sottogruppi: linguaggi compilati e linguaggi interpretati.

Nei linguaggi interpretati, un componente software detto **interprete** ha la responsabilità di leggere il codice scritto nel linguaggio di programmazione e *interpretarlo*, ossia far eseguire alla macchina le azioni necessarie a portarlo a termine.
L'interprete fa una sorta di traduzione "al volo" fra il linguaggio scritto nel codice sorgente ed il linguaggio macchina (comprensibile al processore).
Questa operazione richiede delle risorse, ed i linguaggi interpretati sono normalmente considerevolmente più lenti dei linguaggi compilati (non è raro che lo stesso programma scritto in un linguaggio compilato funzioni dalle 10 alle 100 volte più velocemente).
Il vantaggio di utilizzare un interprete riguarda principalmente la *portabilità*: una volta che il programma è stato scritto, sarà eseguibile su tutte le piattaforme per cui è disponibile un interprete.
Ad esempio, il linguaggio "shell script" visto nel modulo di sistemi operativi è un linguaggio interpretato: lo stesso programma scritto in questo linguaggio funziona su un Rasperry PI (architettura ARM6) con Linux che su Macbook (architettura x86-64) con MacOS.
Altri esempi di linguaggi interpretati (almeno nella loro versione originale) sono Python, PHP (ad esempio Facebook è scritto per la maggior parte in PHP), MATLAB, Perl...

Nei linguaggi compilati, un componente software detto **compilatore** si occupa di *tradurre* il programma scritto nel codice sorgente in un *file binario eseguibile* direttamente dalla macchina.
Il file binario prodotto, essendo direttamente eseguibile della macchina senza necessità di ulteriori passaggi, non è soggetto all'overhead dovuto all'interpretazione, ed ha prestazioni molto elevate.
Lo svantaggio dell'approccio riguarda la portabilità.
Infatti è necessario ricompilare:

* Ogni volta che si fa una modifica al codice nel programma sorgente
* Ogni volta che si utilizza un sistema operativo diverso (salvo rarissime eccezioni in cui due sistemi operativi diversi hanno la medesima [Application Binary Interface (ABI)](https://en.wikipedia.org/wiki/Application_binary_interface))
* Ogni volta che si utilizza una CPU di un'architettura diversa (le CPU con architettura ARM dei vostri smartphone, ad esempio, non "capiscono" le istruzioni macchina dei vostri PC con architettura x86-64, e viceversa)

### Compilazione di sorgenti scritti in C

Esistono [numerosi compilatori per il linguaggio C](https://en.wikipedia.org/wiki/List_of_compilers#C_compilers).
I più importanti sono:

* **GCC C** -- Creato dal progetto [GNU](https://www.gnu.org/home.en.html), è una sorta di standard de facto. Supporta molte diverse piattaforme, fra cui Windows (tramite MinGW e Cycwin), UNIX (quindi Linux, BSD e MacOS), nonché sistemi più particolari come AmigaOS.
È il compilatore che utilizzeremo in questo corso.
* Visual C++ Espress -- Creato da Microsoft, compila solo eseguibili compatibili con Windows.
* Clang -- È un compilatore C particolarmente innovativo basato su [LLVM (Low Level Virtual Machine)](https://en.wikipedia.org/wiki/LLVM), in grado di produrre binari per qualunque piattaforma. Il sistema operativo MacOS X a partire dalla versione 10.7 ed il sistema operativo iOS (quello di iPhone e iPad) sono compilati utilizzando LLVM/Clang. È possibile che in futuro rimpiazzi GCC C come standard de-facto.

Per quanto riguarda GCC C, è possibile eseguirlo lanciando in un terminale UNIX il comando `gcc` (d'ora in poi ci riferiremo al compilatore semplicemente come `gcc`).
Ad esempio:
{% highlight bash %}
gcc nomefile.c
{% endhighlight %}
cerca nella directory corrente il file `nomefile.c`, se lo trova ed è un file C valido produce un file binario chiamato `a.out`, eseguibile dalla macchina corrente.

### Un programma C "vuoto"

{% highlight c %}
int main(void)
{

}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Ogni programma C ha un "punto d'ingresso" che si chiama `main`
* Un `main` ha un *corpo* racchiuso fra parentesi graffe, che contiene le istruzioni
* C è un linguaggio **case sensitive** (come la stragrande maggioranza dei linguaggi di programmazione), ossia fa differenza fra maiuscole e minuscole: `Main` è diverso da `main` e anche da `mAin`.

### Un programma C che stampa a video

{% highlight c %}
int main(void)
{
  printf("Hello, world!\n");
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Ogni istruzione C termina con `;`
* L'istruzione `printf` è un tipo di istruzione che si chiama *chiamata a funzione* (la vedremo in dettaglio più avanti)
* Qualunque chiamata a funzione ha la forma `nomefunzione(argomento1, argomento2, ..., argomentoN)`, ossia un nome di funzione, seguito da una sequenza di argomenti separati da virgole racchiusi fra parentesi tonde
* In questo caso, il nome è `printf` e l'unico argomento è `"Hello, World!"`
* Vediamo anche il primo esempio di stringa di testo. In C una stringa di testo è un insieme di caratteri alfanumerici racchiusa fra due doppi apici `"`
* Il carattere speciale `\n` sta per "new line", e manda a capo il testo
* Le istruzioni inserite dentro un *corpo* (fra parentesi graffe) vanno *indentate*, ossia vanno "spostate" più internamente. Questo non è obbligatorio per far compilare il programma, ma è importante per rendere il codice *leggibile* e quindi *usabile anche da altri* (e da voi stessi a distanza di tempo!).
* Se compilato ed eseguito, questo programma stampa a video il testo `Hello, world!`, quindi va a capo

### Un programma C con variabili intere

{% highlight c %}
int main(void)
{
  int a;
  a = 10 + 5;
  printf("La variabile vale: %d\n", a);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile definire delle variabili, ossia dei "contenitori" con un nome dentro i quali è possibile scrivere dei valori
* Per definire una variabile, è necessario specificarne il *tipo* (in questo caso `int`) seguito dal *nome* (in questo caso `a`)
* Per assegnare un valore ad una variabile si utilizza l'operatore di *assegnamento* `=`, che vuole a sinistra il nome della variabile, e a destra il valore da scrivere nella variabile
* È possibile fare operazioni aritmetiche fra `int`: qui vediamo la somma (operatore `+`), ma sono disponibili anche la sottrazione (`-`), la moltiplicazione (`*`) e la divisione (`/`)
* È possibile stampare a video una variabile o un altro valore intero usando la `printf`. Per farlo, bisogna specificare, all'interno della stringa che viene passata come primo argomento, un "formattatore", ossia un carattere `%` seguito da una lettera che specifica come "interpretare" la variabile, ossia che significato darle. La variabile viene presa dal secondo argomento
* Il programma stampa a video la scritta `La variabile vale: 15`

### Stampare multiple variabili

{% highlight c %}
int main(void)
{
  int a;
  a = 10 + 5;
  printf("La variabile vale: %d, mentre l'intero vale %d\n", a, 20);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile stampare più variabili (o valori). Ciascun formattatore prende l'argomento successivo della `printf` (il primo formattatore prende il secondo argomento, il secondo formattatore prende il terzo argomento, e così via) e lo interpreta come specificato (in questo caso, avendo entrambi il formattatore `%d`, vengono entrambi interpretati come interi).
* Il programma stampa a video la scritta `La variabile vale: 15, mentre l'intero vale 20`.


### Interi come valori booleani

{% highlight c %}
int main(void)
{
  int a;
  a = 10 < 5;
  printf("La variabile vale: %d, mentre l'intero vale %d\n", a, 20);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* In C non esistono i concetti di "vero" e "falso" (a differenza di molti dei linguaggi più moderni). In C i valori booleani (ossia, vero oppure falso) vengono espressi attraverso i numeri interi. In particolare: il valore "falso" vale `0`, mentre qualunque altro valore viene interpretato come "vero".
* Qui vediamo l'operatore minore `<`, ma sono disponibili anche gli operatori maggiore `>` e uguale `==` -- si notino i *2* simboli di "=" successivi: un singolo simbolo `=` significa infatti *assegnamento*, non uguaglianza. Questi operatori prendono in ingresso due interi (uno a destra ed uno a sinistra) e restituiscono `1` (valore intero) se l'espressione è vera, e `0` se l'espressione è falsa.
* Il programma stampa a video: `La variabile vale: 0, mentre l'intero vale 20`


### L'istruzione `if`

{% highlight c %}
int main(void)
{
  int a;
  a = 10;
  if (a > 5) {
    printf("A è maggiore di 5\n");
  }
  printf("Ho finito\n");
}
{% endhighlight %}

*Cosa imparare da questo esempio:*
* L'istruzione `if` consente di eseguire un gruppo di istruzioni solo se una condizione è valida. La condizione va messa fra parentesi tonde, e deve essere un numero intero. Come discusso prima, questo numero viene interpretato come segue: 0 --> *falso*, qualunque altro valore --> *vero*. Se la condizione è vera, vengono eseguite tutte le istruzioni dentro il blocco racchiuso da graffe.
* Sia che la condizione sia vera, sia che sia falsa, al termine dell'esecuzione dell'`if` vengono eseguite le istruzioni successive.
* Il programma stampa a video `A è maggiore di 5`, va a capo, quindi stampa `Ho finito`, quindi va a capo nuovamente.
* Se la condizione fosse stata `a < 5`, il programma avrebbe stampato solo `Ho finito`.
* In realtà se c'è una sola istruzione all'interno dell'`if` è possibile omettere le parentesi graffe. Questa pratica è *fortemente sconsigliata* e conduce facilmente a bug.

### L'istruzione `else`
{% highlight c %}
int main(void)
{
  int a;
  a = 10;
  if (a < 5) {
    printf("A è maggiore di 5\n");
  } else {
    printf("A è minore di 5\n");
  }
  printf("Ho finito\n");
}
{% endhighlight %}

*Cosa imparare da questo esempio:*
* L'istruzione `if` può essere corredata con l'istruzione `else`. Nel caso in cui la condizione dell'`if` sia falsa (ossia `0`), verranno eseguite le istruzioni dentro il blocco `else`.
* Sia che la condizione sia vera, sia che sia falsa, al termine dell'esecuzione dell'`if` con `else` vengono eseguite le istruzioni successive.
* Il programma stampa a video `A è minore di 5`, va a capo, quindi stampa `Ho finito`, quindi va a capo nuovamente.


{% highlight c %}
/*
 * Questo è un commento multilinea.
 * Comincia con una slash seguita da un asterisco, e termina quando viene trovato un asterisco seguito da una slash
 */
int main(void)
{
  // questo è un commento a singola linea
  int a;
  a = 10;
  if (a < 5) {
    printf("A è maggiore di 5\n"); // È possibile commentare anche dopo il codice
  } else {
    printf("A è minore di 5\n");
  }
  printf("Ho finito\n");
//  printf("Questo codice è commentato, e non verrà compilato");
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile commentare il codice, ed è anzi importante farlo, ad esempio per spiegare in linguaggio naturale cosa il codice che avete scritto fa.
* È possibile commentare una singola riga di codice utilizzando `//`. Questo tipo di commento comincia dove si scrive `//` e termina quando si va a capo.
* È possibile fare commenti multi-linea. In questo caso il commento comincia con `/*` e termina con `*/`. Tutto quello scritto fra questi simboli sarà considerato un commento, e non sarà compilato.
* È possibile utilizzare i commenti per escludere (magari temporaneamente) delle righe di codice dalla compilazione (ad esempio per delle prove).
* Il programma stampa a video `A è minore di 5`, va a capo, quindi stampa `Ho finito`, quindi va a capo nuovamente. Si noti che la penultima riga è commentata, e non sarà eseguita.

### Numeri reali: il tipo `double`

{% highlight c %}
int main(void)
{
  int a;
  a = 10;
  double b;
  b = 3.45;
  printf("La variabile intera vale: %d, mentre la variabile reale vale %f\n", a, b);
  printf("La somma vale: %f", a + b);
  double c;
  c = 4 / 3;
  printf("Attenzione! Se si dividono due interi, il risultato è un intero anche se lo si assegna ad un double: %f", c);
  double d;
  d = 4.0 / 3;
  printf("Se si specifica il numero "con il punto", allora diventa double: %f", d);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* `double` è il tipo dei numeri reali
* Per stampare il tipo `double` con la `printf` si utilizza il formattatore `%f`
* Le operazioni fra due `int` (anche le divisioni!) restituiscono un `int`, e anche se poi vengono assegnate ad un `double` l'errore di approssimazione rimane!
* L'approssimazione nella divisione fra interi è sempre per difetto
* È possibile specificare che un numero è di tipo `double` scrivendo esplicitamente il numero "con la virgola": ad esempio `3.0` (anche se ha un valore che potrebbe essere rappresentato precisamente da un intero) è di tipo `double`.
* Un'operazione matematica fra due `double` restituisce un `double`, un'operazione matematica fra un `int` e un double restituisce un `double`
* Un'operazione logica fra due `double` (e.g. `>`, `<`, `==`) restituisce un `int`.

## Lezione 02: Input con `scanf` e istruzioni per l'iterazione

### Calcolatrice in C

{% highlight c %}
int main(void)
{
    printf("Inserire il primo valore: ");
    int var1;
    scanf("%d", &var1);
    printf("Inserire il secondo valore: ");
    int var2;
    scanf("%d", &var2);
    printf("%d + %d = %d\n", var1, var2, var1 + var2);
    printf("%d - %d = %d\n", var1, var2, var1 - var2);
    printf("%d * %d = %d\n", var1, var2, var1 * var2);
    if (var2) { // equivale a: if (var2 != 0) {
        printf("%d / %d = %d\n", var1, var2, var1 / var2);
    } else {
        printf("Niente divisioni per zero!\n");
    }
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* La funzione `scanf` prende in ingresso una stringa che contiene dei formattatori (ad esempio `%d`) e si aspetta in input dall'utente una stringa analoga sul terminale, dalla quale estrarrà i dati che metterà nelle variabili che vengono passati come argomenti aggiuntivi.
* Le variabili in ingresso alla `scanf` vanno prefisse dal simbolo `&`. Il motivo sarà più chiaro in seguito.
* La divisione per zero provoca un errore e va sempre evitata

### Le istruzioni di iterazione: `while` e `for`

{% highlight c %}
int main(void)
{
    int volte;
    printf("Inserire numero: ");
    scanf("%d", &volte);
    int i = 0;
    while(i < volte) {
        printf("Ciao per la %desima volta!\n", i + 1);
        i = i + 1;
    }
    for (int j = 0; j < volte; j = j + 1) {
        printf("Ciao per la %desima volta!\n", j + 1);
    }
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Le istruzioni `for` e `while` servono a ripetere un certo numero di volte una sequenza di operazioni, fin tanto che una condizione è valida.
* È possibile utilizzare una variabile intera per contare quante volte si "entra" in un ciclo, ed uscire dopo un certo numero di "giri": è sufficiente dire che il suo valore deve essere inferiore a quello del numero di volte che vogliamo entrare.
* `while` prende in ingresso una condizione booleana (che in C è comunque rappresentata da un `int`). Se la condizione è vera (ossia, se l'intero risultante è diverso da 0) viene eseguito il corpo del `while`, ossia tutte le istruzioni fra parentesi graffe. Una volta eseguite le istruzioni, viene ricontrollata la condizione, e se vera vengono ri-eseguite le istruzioni del corpo. Si continua a controllare la condizione / eseguire il corpo fin quando la condizione è vera. Quando (se) la condizione diventa falsa, si esce dal `while` e si va all'istruzione successiva.
* `for` è molto simile a `while`. È una sorta di `while` arricchito con:
  1. un'operazione da eseguire una sola volta prima di entrare nel ciclo. È particolarmente utile per definire e inizializzare una nuova variabile su cui contare;
  2. un'operazione da eseguire al termine del ciclo. È particolarmente utile per incrementare (o decrementare) un conteggio.
* È possibile definire e inizializzare le variabili su una sola linea (ad esempio `int a = 5;`)
* **ATTENZIONE --** le vecchie versioni del compilatore `gcc` utilizzano di default lo standard C89. In questo standard, C non supporta l'inizializzazione di variabili come prima istruzione del `for`. Il consiglio è quello di compilare utilizzando l'opzione `-std=c99` (e.g. `gcc -std=c99 programma.c`). L'alternativa è quella di dichiarare la variabile *prima* del ciclo, nello scope più esterno.

### Errori di looping
{% highlight c %}
int main(void)
{
    int volte = 1
    int i = 0;
    while(i < volte) {
        printf("Ciao per la %desima volta!\n", i + 1);
    }
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Se la condizione del `while` o del `for` è sempre vera (in questo caso `i` vale sempre `0`, `volte` vale sempre `1`, e quindi `i < volte` equivale sempre a `0 < 1`, che è sempre vera), si genera un ciclo infinito.
* Il programma entra nel ciclo e non ne esce mai più!
* Bisogna stare attenti, quando si programma, a non avere il caso di cicli "infiniti".
* Se, per errore, si scrive un programma che non termina e lo si lancia, è possibile terminarlo premendo contemporaneamente i tasti Control e C sul terminale. Questa combinazione di tasti invia (tramite sistema operativo) un segnale di stop al programma, che  termina forzatamente.
* È anche possibile (ma più laborioso e sconveniente) terminare il programma dal gestore grafico dei processi (ad esempio il task manager di Windows, o un qualunque gestore di processi Linux).

### Operatori relazionali in C

Gli operatori relazionali confrontano due operandi (a destra e a sinistra dell'operatore) e restituiscono un `int` che rappresenta il valore di verità della formula espressa (`0` se falsa, `1` se vera).
Questi operatori sono fondamentali per poter esprimere delle condizioni, che ci consentiranno di scrivere programmi che usano `if`, `for`, e `while`.
C (così come Java, ma anche come molti altri linguaggi di programmazione), offre i seguenti operatori relazionali:

* Minore -- `<` -- restituisce `1` se il valore a sinistra del simbolo è più piccolo del valore a destra del simbolo, `0` altrimenti
* Maggiore -- `>` -- restituisce `1` se il valore a sinistra del simbolo è più grande del valore a destra del simbolo, `0` altrimenti
* Minore-uguale -- `<=` -- restituisce `0` se il valore a destra del simbolo è più grande del valore a sinistra del simbolo, `1` altrimenti
* Maggiore-uguale -- `>=` -- restituisce `0` se il valore a sinistra del simbolo è più piccolo del valore a destra del simbolo, `1` altrimenti
* Uguaglianza -- `==` -- restituisce `1` se il valore a destra del simbolo è uguale a quello a sinistra del simbolo, `0` altrimenti. **Attenzione!** in C (ma anche in C++, Java, C#, Python, e tantissimi altri linguaggi) il simbolo `=` non significa "uguale" ma "assegnamento", ossia *scrive* nella variabile a sinistra del simbolo il risultato delle operazioni a destra del simbolo. Se si vogliono confrontare due valori occorre utilizzare invece `==` (due uguali di fila).
* Diversità -- `!=` -- restituisce `0` se il valore a destra del simbolo è uguale a quello a sinistra del simbolo, `1` altrimenti.

### Calcolo dell'elevamento a potenza

{% highlight c %}
int main(void)
{
  printf("Inserire elevamento a potenza: ");
  int base;
  int esponente;
  scanf("%d^%d", &base, &esponente);
  int res = 1; // risultato parziale
  for (int i = 0; i < esponente; i = i + 1) {
      res = res * base;
  }
  printf("risultato = %d\n", res);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Questa è una delle possibili soluzioni. Esistono decine (centinaia, migliaia...) di altre soluzioni che vanno benissimo.
* Lo stesso identico algoritmo può essere scritto utilizzando `while`.
* Si noti l'uso di una variabile (`i` in questo caso) che fa da contatore: questo algoritmo funziona moltiplicando `base` per sé stesso tante volte quanto dice l'esponente (applica la definizione di elevamento a potenza). `i` è usato per tenere il conto di quante volte l'operazione di moltiplicazione è già stata fatta.

*Esempio di esecuzione "su carta" dell'algoritmo*

0. stampo a video `Inserire elevamento a potenza: `
1. creo base
2. creo esponente
3. supponiamo che l'utente inserisca `4^3` → `base = 4`, `esponente = 3`
5. creo `res`, `res = 1`
6. creo `i`, `i = 0`
7. `i < esponente` ? → 0 < 3 ? sì
8. `res = res * base` → `res` = 1 * 4 → `res = 4`
9. `i = i + 1` = 0 + 1 = 1 → `i = 1`
10. `i < esponente` ? → 1 < 3 ? sì
11. `res` = 4 * 4 → `res = 16`
12. `i` = 1 + 1 → `i = 2`
13. `i < esponente` ? → 2 < 3 ? sì
14. `res` = 16 * 4 → `res = 64`
15. `i` = 2 + 1 → `i = 3`
16. `i < esponente` ? → 3 < 3 → no
17. stampo a video `risultato = 64`

### Calcolo dell'elevamento a potenza -- versione avanzata

{% highlight c %}
int main(void)
{
  printf("Inserire elevamento a potenza: ");
  int num;
  int pow;
  scanf("%d^%d", &num, &pow);
  int res = 1;
  for (; pow; pow--) {
      res *= num;
  }
  printf("risultato = %d\n", res);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile lasciare "vuote" le istruzioni di inizializzazione e fine ciclo di un `for`, nel qual caso non viene eseguita alcuna operazione: `for(; 1;)` è esattamente equivalente a `while(1)`
* È possibile incrementare utilizzando l'operatore `++` e decrementare utilizzando l'operatore `--`. L'uso di questi operatori è **sconsigliato**, ma potreste trovarli nel codice scritto da altri (il loro uso è molto comune, specie come ultima istruzione dei cicli `for`)
* È possibile utilizzare gli operatori `+=`, `-=`, `*=`, `/=` per scrivere in modo succinto un'operazione matematica che cambia il valore di una variabile. Ad esempio, `a = a + b` può esser scritto `a += b`. Come per `++` e `--`, il loro utilizzo è sconsigliato almeno fin quando non sarete esperti di programmazione C, ma potreste comunque incontrare questi operatori nel codice scritto da altri
* A volte è possibile "risparmiare" una variabile contatore decrementando un valore che non verrà utilizzato in futuro (in questo caso `pow`). Tale pratica è sconsigliata, perché rende il codice più difficile da capire in cambio di un "risparmio" di memoria trascurabile. Ancora una volta, però, può capitarvi il caso in cui dobbiate mettere mano a del codice scritto da altri che fa uso di questa pratica

### Esercizio: calcolo della somma di un numero arbitrario di numeri
{% highlight c %}
int main(void)
{
    int times;
    printf("Inserire un numero intero positivo: ");
    scanf("%d", &times);
    int s = 0;
    for (; times > 0; times--) {
        int v;
        printf("Inserisci un intero: ");
        scanf("%d", &v);
        s += v;
    }
    printf("La somma dei numeri inseriti è: %d\n", s);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile utilizzare i cicli `for` e `while` per eseguire iterativamente (più volte) qualunque operazione (incluse ovviamente `printf` e `scanf`)


## Lezione 03: chiamata a funzione, cambi di base, tipi numerici

### Scrittura e chiamata di una funzione

{% highlight c %}
int somma(int a, int b)
{
    return a + b;
}

int getInput(void)
{
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    return num;
}

int main(void)
{
    int times = getInput();
    int s = 0;
    printf("I numeri inseriti d'ora in poi saranno sommati\n");
    for (; times > 0; times--) {
        int v = getInput();
        s = somma(s, v);
    }
    printf("La somma dei numeri inseriti è: %d\n", s);
}

{% endhighlight %}

*Cosa imparare da questo esempio:*

* Una funzione è il modo in cui si può spezzare un programma C in sotto-programmi.
* Una funzione ha un nome, degli argomenti di ingresso, e un tipo di ritorno.
* Non possono esistere due funzioni con lo stesso nome in C (anche se hanno numero o tipo di parametri diversi).
* La prima cosa che va espressa è il tipo di ritorno, in questo caso sempre `int`. Se la funzione fa delle operazioni ma non restituisce nulla, è possibile usare il tipo di ritorno `void`
* Gli argomenti vanno scritti dopo il nome fra parentesi. Possono essere in numero arbitrario, e all'atto di definizione della funzione per ciascuno si specifica il tipo ed un nome (si veda la funzione `somma`). Nel caso in cui non vi siano argomenti, è possibile scrivere `void` fra le parentesi (si veda la funzione `getInput`).
* Nel caso in cui vi sia un valore atteso (ossia, nel caso in cui la funzione non restituisca `void`), una volta che il risultato è pronto è possibile restituirlo e dichiarare conclusa la computazione della funzione utilizzando l'istruzione `return` seguita dal risultato.
* Anche `printf`, `scanf` e `main` sono delle funzioni.
* Per chiamare una funzione, è sufficiente scrivere il suo nome seguito, fra parentesi tonde, dagli argomenti su cui la funzione dovrà lavorare separati da `,`. Ad esempio `somma(3, 4)` chiama la funzione `somma` mettendo come primo argomento il valore `3` e come secondo argomento il valore `4`
* Affinché il compilatore "trovi" una funzione nel momento in cui compila, tale funzione deve essere definita **prima** del punto in cui è chiamata. Quindi, ad esempio, se dentro `main` chiamiamo `getInput`, allora `getInput` deve essere definita prima di `main`.
* Si noti (per chi ha fatto analisi matematica) che la sintassi è simile a quella classica dell'analisi, e.g. `y = f(x)`.
* Nel caso in cui la funzione non accetti alcun argomento, è possibile chiamarla senza passare alcun parametro. Attenzione però: le parentesi vanno comunque messe! Diversamente il compilatore cercherà una variabile, e darà un errore perché non definita. Si veda ad esempio la chiamata a `getInput()`.
* Quando si esegue una chiamata a funzione, vengono copiati i valori negli argomenti della funzione, quindi si "salta" alla prima istruzione della funzione e si comincia ad eseguire. Si continua ad eseguire fino a che non viene raggiunta una istruzione di `return`, oppure (nel caso in cui la funzione restituisca `void`) fino a che le istruzioni nel corpo della funzione non sono finite.
* Si noti che ora il `main` è molto più "snello" e facile da leggere: invece di avere esplicitamente scritte le chiamate a `printf` seguite da chiamate a `scanf`, abbiamo isolato il sotto-problema di acquisire input dall'utente in una funzione separata.

### Ricorsività

{% highlight c %}
int fattoriale(int a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}

int getInput(void)
{
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    return num;
}

int main(void)
{
    printf("Il fattoriale è: %d\n", fattoriale(getInput()));
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* **Premessa --** La funzione fattoriale calcola il prodotto di tutti i numeri interi positivi minori e uguali al numero passato (e.g. 5! = 5 * 4 * 3 * 2 * 1 = 120). Si fa notare che 5! = 5 * 4!, ossia che il fattoriale di un numero arbitrario n può essere definito come n * (n - 1)! (ricordandosi che 0! = 1).  È molto usata in statistica nei problemi combinatori (ad esempio se avete 5 palline diverse in una scatola, e le togliete a caso, in quanti diversi ordini possono venir fuori? Possono creare 5! = 120 combinazioni). [Si rimanda a Wikipedia per ulteriori dettagli](https://it.wikipedia.org/wiki/Fattoriale).
* Una funzione può chiamare sé stessa. In questo caso, si dice che la funzione è *ricorsiva*
* Ogni volta che viene chiamato `fattoriale` per un numero maggiore di `0`, la funzione richiama sé stessa con un valore più piccolo, e ricostruisce il valore moltiplicando "all'indietro"
* È possibile usare il risultato di funzioni come argomento di funzioni: si veda `fattoriale(getInput())`: prima viene calcolato `getInput()`, il suo risultato viene dato in pasto a `fattoriale`, il risultato di `fattoriale` viene quindi passato a `printf`.

### Tipi di dato numerici

| Tipo | Formattatore | Significato | Dimensione in bit [1] |
|:---:|:-------------: | :------------: | :-: |
| `int` | `%d` | intero (positivo o negativo) | 32
| `long` | `%ld` | intero (positivo o negativo) | 64
| `unsigned int` | `%u` | intero positivo | 32
| `unsigned long` | `%lu` | intero (positivo o negativo) | 64
| `float` | `%f` | reale | 32
| `double` | `%lf` | intero (positivo o negativo) | 64

**[1] su Linux 64bit, su altre piattaforme potrebbe cambiare!**

### Cast

È possibile chiedere di convertire esplicitamente un tipo in un altro esplicitando fra parentesi il tipo "destinazione", ad esempio `int a = (int) 3.4 * 5.6`. C è molto permissivo, e se il cast non viene scritto a mano, lo fa comunque. Questa permissività è spesso fonte di errori! Meglio sempre esplicitare il cast, per segnalare a chi legge il codice che sapete cosa state facendo (e.g. passando da un reale ad un intero perdete precisione). Altri linguaggi (e.g. Java) rifiutano di compilare se si fanno delle conversioni che potrebbero portare a perdita di precisione senza un cast esplicito.

### Fattoriale più preciso

{% highlight c %}
int fattoriale(int a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}

unsigned long fattorialeLong(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattorialeLong(a - 1);
}

int getInput(void)
{
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    return num;
}

int main(void)
{
    float d;
    for (int i = 0; i < 100000; i++){
        d = d + 0.00003;
    }
    printf("%lf\n", d);
    int input = getInput();
    printf("Il fattoriale (long) è: %ld\n", fattorialeLong((unsigned long) input));
    printf("Il fattoriale (int) è: %d\n", fattoriale(input));
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* I tipi di dato interi possono andare in *overflow*, ossia "sforare" il loro valore massimo. Se lo si sfora, C "scarta" la parte più significativa. Per capire, si immagini di avere a disposizione solo quattro caselle dove poter scrivere dei numeri decimali. Il massimo numero che potremmo scrivere sarebbe 9999. Ora si immagini di voler sommare il numero presente in quattro caselle con quello presente in altre quattro caselle e mettere il risultato in quattro caselle. Se si sommano 300 e 1233 ad esempio, il risultato è 1533 e non ci sono problemi. Se si sommano invece 9997 e 100, il risultato "sfora" le caselle disponibili. Quando questo succede, si parla di overflow. C esegue comunque la somma, ma taglia i valori più significativi. Nel nostro esempio con le caselle, il risultato invece di 10097, sarebbe semplicemente 97 (viene scartata la parte più significativa, ovvero le caselle più a destra, finché non ne restano quattro). In C le caselle sono bit, ed hanno valore binario.
* Tipi diversi hanno precisione diversa: si noti come `fattorialeLong` continui a dare risultati giusti anche quando `fattoriale` (che usa gli `int`) comincia a dare risultati sbagliati.
* Nel caso di numeri con segno, un bit (il più significativo) viene utilizzato per scrivere il segno.

### Binario, ottale, esadecimale

I numeri possono essere rappresentati in molti modi. Il sistema decimale (con dieci cifre) che utilizziamo abitualmente non è l'unico: ad esempio i computer "ragionano" in binario (ossia, con due cifre). È possibile creare sistemi con numero arbitrario di cifre (ossia di simboli disponibili), esempi notevoli sono il sistema ottale (8 cifre) ed esadecimale (16 cifre). La tabellina seguente mostra alcuni numeri nei diversi formati.

| Base 2 (binario) | Base 8 (ottale)  | Base 10 (decimale) | Base 16 (esadecimale) |
| :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 |
| 10 | 2 | 2 | 2 |
| 11 | 3 | 3 | 3 |
| 100 | 4 | 4 | 4 |
| 101 | 5 | 5 | 5 |
| 110 | 6 | 6 | 6 |
| 111 | 7 | 7 | 7 |
| 1000 | 10 | 8 | 8 |
| 1001 | 11 | 9 | 9 |
| 1010 | 12 | 10 | A |
| 1011 | 13 | 11 | B |
| 1100 | 14 | 12 | C |
| 1101 | 15 | 13 | D |
| 1110 | 16 | 14 | E |
| 1111 | 17 | 15 | F |
| 10000 | 20 | 16 | 10 |
| 10001 | 21 | 17 | 11 |
| 10010 | 22 | 18 | 12 |
| 10011 | 23 | 19 | 13 |
| 10100 | 24 | 20 | 14 |
| 11110 | 36 | 30 | 1E |
| 11111111 | 377 | 255 | FF |

Si noti come ciascuna cifra ottale corrisponde al valore di tre bit, e come ogni cifra esadecimale corrisponda al valore decimale di quattro bit. Per questa ragione, sono spesso usati.

In C, è possibile scrivere numeri utilizzando il formato ottale premettendo uno `0` al numero, ed in formato esadecimale premettendo `0x` al numero.
Ad esempio: `int v = 036` ha come valore decimale `30` (se stampato in una `printf` con formattatore `%d`, mostra a schermo `30`).
Ad esempio: `int v = 0x1D` ha come valore decimale `35` (se stampato in una `printf` con formattatore `%d`, mostra a schermo `35`).
Attenzione quindi, in particolare, a non prefiggere `0` quando scrivete un numero intero!

## Lezione 04: operatori, prototipi, header files, direttiva `#include`, puntatori

### Operatori in C

Gli operatori sono operazioni fornite dal linguaggio che consentono la manipolazione dei tipi di dato pre-esistenti.
Ciascun operatore ha una propria *arità*, ossia il numero di argomenti che richiede per poter funzionare (ad esempio, la somma richiede due argomenti, la negazione uno).
Gli operatori con arità 1 possono essere prefissi (ossia vegono prima dell'operando, come la negazione) o postfissi (vengono dopo l'operando).
Gli operatori con arità 2 possono essere prefissi (ossia vegono prima degli operandi) oppure infissi (ossia appaiono fra i due operandi, come nel caso della somma: `2 + 3`).

___

**OPERATORI MATEMATICI**

Si tratta di operatori che prendono in ingresso numeri e restituiscono numeri. Come visto in precedenza, in caso di operazioni fra numeri di tipo diverso (e.g. fra `int` e `float`) viene preso il tipo più "preciso". Se il tipo degli operandi coincide, allora il tipo del risultato è il medesimo.

| Nome | Simbolo  | Arità | Posizione | Esempio |
| :-: | :-: | :-: | :-: | :-: |
| somma | `+` | 2 | infisso | `5 + 3` -- restituisce `8` |
| sotrazione | `-` | 2 | infisso | `5 - 3` -- restituisce `2` |
| moltiplicazione | `*` | 2 | infisso | `5 * 3` -- restituisce `15` |
| divisione | `/` | 2 | infisso | `5 / 3` -- restituisce `1` |
| modulo (resto della divisione per) | `%` | 2 | infisso | `5 % 3` -- restituisce `2` |

___

**OPERATORI LOGICI**

Si tratta di operatori che prendono in ingresso booleani e restituiscono booleani.
Come visto in precedenza, essendo C in realtà sprovvisto del concetto di booleano, questi operatori prendono in ingresso numeri, interpretando `0` come falso e qualunque altro numero come vero.
Restituiscono `1` se l'operazione ha come risultato vero, e `0` se ha come risultato falso

| Nome | Simbolo  | Arità | Posizione | Esempio |
| :-: | :-: | :-: | :-: | :-: |
| and | `&&` | 2 | infisso | `1 && 0` -- restituisce `0` |
| or | `||` | 2 | infisso | `1 || 0` -- restituisce `1` |
| negazione | `!` | 1 | prefisso | `!0` -- restituisce `1` |

___

**OPERATORI BIT A BIT**

Si tratta di operatori "bitwise" che prendono in ingresso stringhe di bit e restituiscono stringhe di bit.
Questi operatori prendono gli argomenti passati, ne ignorano l'interpretazione e guardano esclusivamente al loro contenuto in termini di sequenza di bit.
Quando hanno più di un argomento, i valori degli argomenti sono confrontati confrontando uno ad uno i bit in posizione corrispondente.
Sono particolarmente utili quando è necessario manipolare una sequenza di bit, ad esempio per inviare comandi ad un dispositivo esterno (e.g. un motore elettrico).
Non vanno confusi con gli operatori logici! I risultati restituiti sono completamente *diversi*!

| Nome | Simbolo  | Arità | Posizione | Esempio |
| :-: | :-: | :-: | :-: | :-: |
| and | `&` | 2 | infisso | `3 & 4` -- restituisce `0` |
| or | `|` | 2 | infisso | `3 | 4` -- restituisce `7` |
| xor | `^` | 2 | infisso | `3 ^ 5` -- restituisce `6` |
| shift a destra con segno | `>>` | 2 | infisso | `-4 >> 1` -- restituisce `-2` |
| shift a sinistra | `<<` | 2 | infisso | `-4 << 1` -- restituisce `-8` |
| shift a destra senza segno | `>>>` | 2 | infisso | `-4 >>> 1` -- restituisce `2147483646` |
| negazione | `~` | 1 | prefisso | `~0` -- restituisce `-1` |

___

### Prototipi di funzione

{% highlight c %}
int fattoriale(int);

int getInput(void);

int main(void)
{
    printf("Il fattoriale è: %d\n", fattoriale(getInput()));
    return 0;
}

int fattoriale(int a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}

int getInput(void)
{
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    return num;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Il compilatore C richiede che una funzione sia definita *prima* del punto in cui viene chiamata. Questo limita la potenza espressiva, ad esempio non sarebbe possibile fare funzioni "mutuamente ricorsive", dove una richiama l'altra, perché ce ne sarebbe sempre una non definita nel momento in cui viene chiamata.
* Per superare questa limitazione, è possibile dichiarare i *prototipi* delle funzioni prima della loro effettiva implementazione.
* Il prototipo della funzione include il tipo di ritorno, il nome, ed il tipo e numero degli argomenti (ma non il loro nome). Non include il corpo (si noti che non ci sono le parentesi graffe).
* Il compilatore "sa" che la funzione è definita, e compila senza problemi anche se non conosce l'implementazione, che aggiungerà solo dopo.
* La funzione `main` è una funzione come le altre, ed essendo il suo tipo di ritorno dichiarato `int` deve restituire un intero al termine dell'esecuzione. Questo intero ha il significato di "codice d'errore": se il main termina restituendo `0` allora il programma ha terminato senza errori, altrimenti il valore restituito indica il codice d'errore.

### La direttiva `#include`

-- file `math/fattoriale.c` --
{% highlight c %}
unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}
{% endhighlight %}

-- file `usefact.c` --
{% highlight c %}
#include "math/fattoriale.c"

int main(void)
{
    printf("Il fattoriale di 5 è: %lu\n", fattoriale(5));
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile spezzare un programma C in più file.
* In effetti, è una buona pratica farlo, perché un singolo file enorme diventerebbe molto difficile da manutenere. Si pensi ad esempio cosa succederebbe se l'intero kernel Linux, di circa 20 milioni di righe di codice, fosse in un solo file! Sarebbe impossibile leggerlo ed usarlo.
* È possibile chiedere al *preprocessore* del compilatore di *copiare* il contenuto di un file dentro un altro file tramite la direttiva `#include`.
* La direttiva `include` va fatta seguire dalla posizione del file che si vuole includere, relativa alla posizione del file in cui la `#include` si trova, messa fra doppi apici (`"`).
* `#include` viene eseguita *prima* della vera compilazione, e costituisce una vera e propria copia del contenuto di un file dentro un altro.
* Nel caso in cui si scriva l'`#include` per due volte, il file verrà copiato per due volte , generando un errore di compilazione perché la stessa funzione è definita più volte. Questo fatto crea un grosso problema, perché potremmo volere includere dei file che a loro volta includono altri file, e rischieremmo di trovarci nell'impossibilità di compilare a causa di questi include confliggenti.
* Nel caso in cui due sorgenti si importino l'un l'altro, il preprocessore comincia a copiare uno dentro l'altro ad oltranza, fin quando non termina con un errore.

### La guardia `#ifndef` / `#define` / `#endif`

-- file `math/fattoriale.c` --
{% highlight c %}
#ifndef FATTORIALE_C
#define FATTORIALE_C

unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}
#endif
{% endhighlight %}

-- file `utility.c` --
{% highlight c %}
#include "math/fattoriale.c"

void printFattoriale(int n)
{
    printf("%d! = %lu", n, fattoriale(n));
}
{% endhighlight %}

-- file `usefact.c` --
{% highlight c %}
#include "math/fattoriale.c"
#include "utility.c"

int main(void)
{
    printf("Il fattoriale di 5 è: %lu\n", fattoriale(5));
    printFattoriale(8);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile istruire il preprocessore perché copi ciascun file al più una sola volta.
* Il modo di istruirlo a fare questa cosa è tramite l'utilizzo di una direttiva `#ifndef`, seguita da un nome, e terminata da una direttiva `#endif`. All'interno di questo blocco, si utilizza la direttiva `#define` seguita dallo stesso nome usato dopo `#ifndef`.
* Questa direttiva nel suo complesso si legge come: «se non è ancora stato definito questo nome, definisci il nome, quindi copia tutto quello che c'è fino ad `#endif`. Altrimenti, non copiare nulla. In ogni caso, copia tutto quello che sta dopo `#endif`».
* Nel caso in esame, sia `utility.c` che `usefact.c` includono `fattoriale.c`. Senza le guardie, la compilazione di `usefact.c` darebbe un errore, perché la funzione `fattoriale` sarebbe definita due volte (a causa del fatto che `usefact.c` sarebbe copiato dentro `utility.c`, e poi sia `utility.c` con la sua copia di `fattoriale.c` che `fattoriale.c` sarebbero copiati dentro `usefact.c`). Con la guardia, il file viene copiato una sola volta, consentendo quindi la compilazione.
* È bene che il nome assegnato dopo `#ifndef` corrisponda al nome del file scritto in maiuscolo, con il `.` sostituito da un `_`. Questo evita il fatto che due persone utilizzino lo stesso nome per due file diversi, causando l'impossibilità di includere entrambi.

### Librerie e file header

--file `fattoriale.h` --
{% highlight c %}
#ifndef FATTORIALE_H
#define FATTORIALE_H

unsigned long fattoriale(unsigned long);

#endif
{% endhighlight %}

--file `fattoriale.c` --
{% highlight c %}
#include "fattoriale.h"

unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}
{% endhighlight %}

--file `usofattoriale.c` --
{% highlight c %}
#include "fattoriale.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("5! = %lu\n", fattoriale(5));
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È buona prassi dichiarare i prototipi delle funzioni che si implementano in un file c in file header (estensione .h), magari corredati da un commento. In questo modo, chi fa uso delle funzioni può limitarsi ad importare gli header, ignorando l'implementazione (principio ingegneristico di [information hiding](https://it.wikipedia.org/wiki/Incapsulamento_(informatica))).
* È possibile compilare i file che non contengono un main specificando che desideriamo creare una *libreria*, ossia una collezione di funzioni che non realizzano un programma, ma offrono supporto alla scrittura di programmi.
* Per compilare un file C come libreria si utilizza la flag `-c` in `gcc`. La compilazione con questa flag produce un file oggetto (estensione `.o` su Linux) che rappresenta una libreria.
* Ad esempio, in questo caso, è necessario per prima cosa compilare `fattoriale.c` con il comando `gcc -c fattoriale.c`. Il compilatore creerà il file `fattoriale.o`. Ora è possibile compilare il file `usofattoriale.c` utilizzando il comando `gcc fattoriale.o usofattoriale.c`. `gcc` sarà in grado di trovare la funzione corretta dentro `fattoriale.o` grazie al prototipo dichiarato in `fattoriale.h`. Si noti che *è necessario specificare i file oggetto da utilizzare quando si compila, o il compilatore darà errore lamentandosi che una funzione è definita implicitamente*.
* Abbiamo finora utilizzato funzioni come `printf` come se fossero oggetti magici. In realtà sono funzioni scritte in C esattamente come le nostre! Dove sono? Sono distribuite (precompilate) come parte del sistema operativo, e i loro prototipi sono contenuti in file header contenuti in una cartella di sistema.
* Quando si utilizzano tali funzioni, è bene importare gli header dove sono definiti. Quando si vuole importare uno header che si trova installato nel sistema, si usa la direttiva `#include <headerdisistema.h>` (dove a `headerdisistema.h` va sostituito il vero nome del file). Si noti l'uso delle parentesi angolari (minore e maggiore,  `<>`) in luogo dei doppi apici (`""`).
* Nella macchina virtuale del corso, questi header si trovano nella directory `/usr/include/`: potete aprirli e leggerli!
* Le funzioni `printf` e `scanf` si trovano in `stdio.h` (sta per "Standard Input/Output")
* Altre librerie molto utili si trovano in `stdlib.h` (Standard Library), `string.h` (manipolazione di stringhe di testo), e `math.h` (funzioni matematiche).

### Puntatori

{% highlight c %}
#include <stdio.h>

int main(void)
{
    int a = 8;
    int *b = &a;
    int c = *b;
    *b = c - 1;
    printf("Valore di a: %d\n", a); // 7
    printf("Valore di c: %d\n", c); // 8
    printf("Valore di b: %p\n", b); // Numero esadecimale, e.g. 0x7ffeb83c1b1c
    printf("Indirizzo in memoria di a: %p\n", &a); // Uguale a prima, e.g. 0x7ffeb83c1b1c
    printf("Indirizzo in memoria di b: %p\n", &b); // Indirizzo diverso! E.g. 0x7ffeb83c1b10
    printf("Indirizzo in memoria di c: %p\n", &c); // Altro indirizzo, e.g.  0x7ffeb83c1b0c
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* In C abbiamo la possibilità di manipolare gli *indirizzi* di memoria in cui i dati sono scritti. Un tipo di dato che rappresenta un indirizzo prende il nome di "puntatore".
* Per dichiarare che una variabile non contiene un dato ma un indirizzo, si utilizza il tipo del dato puntato seguito da un asterisco. Ad esempio, l'indirizzo a cui risiede una variabile `int` è di tipo `int *`. L'indirizzo a cui risiede una variabile di tipo `long` è di tipo `long *`.
* È possibile anche chiedere l'indirizzo di una variabile che contiene un indirizzo: se supponiamo che `x` sia un `int`, `y` un puntatore ad `x` e `z` un puntatore ad `y`, i loro tipi saranno rispettivamente `int` per `x`, `int *` per `y`, e `int **` per `z`.
* Per sapere a quale indirizzo in memoria risiede una variabile, è possibile utilizzare l'operatore unario prefisso reference: `&`. Questo operatore prende in ingresso una variabile di qualunque tipo e restituisce un puntatore alla stessa. Se la variabile in ingresso è di tipo `int`, allora il tipo di ritorno sarà `int *` (puntatore ad intero). Se la variabile in ingresso fosse `double`, il tipo di ritorno sarebbe `double *` (puntatore a double). Se il tipo d'ingresso fosse `float *` (puntatore a `float`) allora il tipo di ritorno sarebbe `float **` (puntatore ad un puntatore a float). È possibile andare avanti all'infinito: se la variabile in ingresso fosse di tipo `int ****` (puntatore ad un puntatore ad un puntatore ad un puntatore ad intero), il risultato sarebbe di tipo `int *****` (puntatore ad un puntatore ad un puntatore ad un puntatore ad un puntatore ad intero).
* Per accedere alla variabile puntata da un puntatore si utilizza l'operatore unario deference: `*`. **Attenzione**: si tratta dello stesso simbolo utilizzato per la moltiplicazione e per la definizione del tipo puntatore, ma ha un significato completamente diverso! L'operazione di deference prende una variabile, la interpreta come indirizzo, e va in memoria a quell'indirizzo.
* Cosa succede nell'esempio:
  0. Viene creata una variabile `a`, ad esempio all'indirizzo `0x7ffeb83c1b1c` (l'indirizzo può cambiare ad ogni esecuzione).
  0. Nella variabile `a` viene scritto il valore `8`: all'indirizzo `0x7ffeb83c1b1c` ci sarà scritto il numero `8`.
  0. Viene creata una variabile `b` di tipo `int *` (puntatore ad intero), ad esempio all'indirizzo `0x7ffeb83c1b10`.
  0. Viene scritto nella variabile `b` l'indirizzo della variabile `a`: all'indirizzo `0x7ffeb83c1b10` ci sarà dunque scritto il numero `0x7ffeb83c1b1c`.
  0. Viene crata una variabile `c` di tipo `int`, supponiamo all'indirizzo `0x7ffeb83c1b0c`
  0. Viene scritto in `c` il valore *puntato da* `b`: grazie all'operatore di deference, si legge il contenuto di `b`, ossia `0x7ffeb83c1b1c`, si va a quell'indirizzo di memoria e si legge cosa c'è scritto. In questo caso, ci sarà scritto `8`. Disegnando i puntatori come frecce, l'operazione di deference equivale a "percorrere la freccia"
  0. Viene scritto, nella zona di memoria *puntata da* `b`, il valore di `c - 1`. Come sopra, si va quindi a prendere il contenuto di `b`, ossia `0x7ffeb83c1b1c`, e si scrive a quell'indirizzo il risultato dell'operazione. Essendo quell'indirizzo l'indirizzo in cui si trova la variabile `a`, abbiamo modificato il valore di `a`!

### Errori di segmentazione

{% highlight c %}
#include <stdio.h>

int main(void)
{
    int a = 8;
    int *b = &a;
    int c = *b;
    // Questo programma è BUGGATO!
    printf("Quanto vale? %d\n", *((int *)((long) c)));  // Segmentation fault
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Bisogna fare attenzione quando si utilizzano i puntatori! Il sistema operativo è responsabile di decidere quali processi possono leggere e scrivere in memoria e dove, ed in caso di accessi illegali termina immediatamente il processo in corso. Un accesso illegale ad un segmento di memoria che non appartiene all'applicazione prende il nome di *errore di segmentazione* o *segmentation fault*.
* Gli errori in Windows come `la memoria non poteva essere read` o `la memoria non poteva essere written` sono dovuti a deference illegali (spesso bug del programma).
* Quando capita un errore di segmentazione su Linux, l'applicazione viene terminata e viene scritto `Segmentation fault` sul terminale. Su Windows, appare una finestra del sistema operativo che "cerca una soluzione online al problema".
* Il compilatore dà dei warning quando si usano i puntatori in modo poco ortodosso: bisogna sforzarsi di leggere e capire questi warning!
* È possibile ingannare il compilatore eseguendo dei cast (conversioni di tipo) successivi -- ovviamente, non va fatto.

### Esempio di uso dei puntatori

{% highlight c %}
#include <stdio.h>

void f(int *c, int *d)
{
    int temp = *c;
    *c = *d;
    *d = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    printf("PRIMA: a = %d, b = %d\n", a, b); // a = 10, b = 20
    f(&a, &b);
    printf("DOPO: a = %d, b = %d\n", a, b); // a = 20, b = 10
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* I puntatori consentono di effettuare operazioni altrimenti impossibili, in questo esempio ad esempio si invertono i valori di due variabili appartenenti alla funzione chiamante!
* Assicurarsi di aver compreso in modo *cristallino* cosa avviene quando si esegue questo esempio, ed in particolare cosa fa l'istruzione `*c = *d;`!

## Lezione 05: memoria dinamica, stringhe e strutture dati

### La macro `sizeof` e la funzione `malloc`

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("Valore di sizeof(int): %d\n", sizeof(int));
    printf("Valore di sizeof(long): %d\n", sizeof(long));
    printf("Valore di sizeof(double): %d\n", sizeof(double));
    printf("Valore di sizeof(int *): %d\n", sizeof(int *));
    int *a = (int *) malloc(sizeof(int));
    printf("Valore di a: %p\n", a);
    printf("Valore puntato da a: %d\n", *a);
    *a = 22;
    printf("Valore di a: %p\n", a);
    printf("Valore puntato da a: %d\n", *a);
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* `malloc` è una funzione che prende in ingresso un `int` e restituisce un `void *`
* La funzione `malloc` richiede al sistema operativo di allocare della memoria per il processo corrente. L'argomento della funzione è il numero di celle di memoria (ossia di byte) che si desidera avere.
* La funzione `malloc` restituisce un puntatore all'area di memoria che il sistema operativo mette a disposizone. Non potendo sapere quale tipo di dato sarà ospitato in quell'area di memoria, il tipo di ritorno è `void *`
* `void *` è il tipo che in C identifica un puntatore ad un'area di memoria il cui contenuto è sconosciuto.
* Affinché sia possibile utilizzare in modo appropriato quell'area di memoria, è bene convertire il tipo `void *` restituito da `malloc` nel tipo che andremo ad usare effettivamente (nell'esempio `int *`). Tale conversione si effettua con un cast.
* Ricordarsi a memoria la dimensione in byte di qualunque tipo di dato è proibitivo (specialmente, vedremo poi, quando si utilizzano strutture dati). Inoltre, la dimensione dei tipi di dato potrebbe cambiare da piattaforma a piattaforma! Ad esempio, `int *` ha dimensione 4 byte (2 bit) nei sistemi a 32bit e 8 byte (64bit) nei sistemi a 64bit.
* Per superare questa difficoltà, il compilatore C mette a disposizione la macro `sizeof`, che prende in ingresso il *tipo* di dato e lo sostituisce con la sua dimensione in byte per la piattaforma corrente.
* Una macro è un'istruzione che viene eseguita prima della compilazione vera e propria, ed il cui risultato viene "scritto" nel file che si sta per compilare (esattamente come per `#include`)

### Array dinamici

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int size = 100;
    int *a = (int *) malloc(size * sizeof(int));
    for(int i = 0; i < size; i = i + 1) {
        a[i] = i * 2; // Equivale a: *(a + i) = i * 2;
    }
    for (int i = 0; i < size; i++) {
        printf("Indirizzo %p, valore %d\n", a + i, a[i]);
    }
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile allocare spazio in memoria per più oggetti dello stesso tipo, semplicemente moltiplicando la macro `sizeof` per il numero di oggetti che vogliamo conservare in quell'area.
* Il numero di oggetti da creare può essere stabilito a run-time, ad esempio usando una variabile.
* Allocare spazio per più entità attraverso una `malloc` costruisce un cosiddetto "array dinamico".
* Abbiamo ora un problema: sappiamo utilizzare l'operatore deference (`*`, unario) per "percorrere" un puntatore ed ottenere il valore puntato. Nel caso di un array dinamico, però, questo restituirebbe semplicemente il primo elemento. Per accedere ad elementi successivi, è possibile utilizzare l'*aritmetica dei puntatori*, ossia: le somme e le sottrazioni fra puntatori e interi "spostano" avanti e indietro il puntatore lungo la memoria. Conseguentemente, il primo elemento di un array `a`, che avremmo normalmente deferenziato come `*a`, può essere deferenziato come `*(a + 0)`. Con questa scrittura, è facile capire che il secondo elemento di `a` sarà `*(a + 1)` (parti dall'indirizzo `a`, vai avanti una volta di tante celle quanto è grande l'oggetto puntato da `a`, quindi esegui il deference). Allo stesso modo, il terzo elemento sarà `*(a + 2)` (a partire da `a`, vai avanti due volte di tante celle quanto è grande l'oggetto puntato da `a`, quindi deferenzia).
* Si noti come, con la scrittura di cui sopra, il primo elemento di un array sia in posizione `0` (si somma `0` ad `a`), il secondo elemento sia in posizione `1` (si somma `1` ad `a`) e così via.
* C consente di usare una scrittura più compatta ed intuitiva per accedere ad un array dinamico rispetto alla somma di puntatori e interi seguita da deference: è possibili utilizzare l'accesso "con indice". Per accedere all'elemento `n`-esimo di un array `a`, si può utilizzare `a[n]`. Questa scrittura è equivalente a `*(a + n)`.

### Array di array e funzione `free`

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int sx = 5;
    int sy = 8;
    int **matrix = (int **) malloc(sx * sizeof(int *));
    for (int i = 0; i < sx; i = i + 1) {
        matrix[i] = (int *) malloc(sy * sizeof(int));
    }
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            // *(*(matrix + i) + j) = (i + 1) * j;
            matrix[i][j] = (i + 1) * j;
        }
    }
    matrix[0][0] = 144;
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < sx; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* È possibile allocare spazio in memoria per array di puntatori. In questo caso, si ottiene un puntatore a puntatori.
* È possibile procedere un numero di volte arbitrario (puntatore a puntatori a puntatori ... a puntatori)
* È possibile utilizzare dei cicli `for` innestati per riempire, scorrere e creare array di array
* Per prima cosa si crea l'array più esterno (che contiene gli altri) e quindi via via quelli più interni.
* Per accedere ad un elemento di un array di array, è possibile utilizzare due volte l'operatore di accesso a posizione (tre volte per array di array di array, etc.).
* Si noti come l'uso dell'operatore suddetto sia più intutitivo rispetto all'aritmetica dei puntatori con uso dell'operatore di deference: `*(*(matrix + i) + j)` diventa molto più semplicemente `matrix[i][j]` (si legge matrix di i di j).
* La memoria che è stata allocata ma che non sarà più utilizzata va *liberata*, ossia va marcata come riutilizzabile (il sistema operativo potrà riassegnarla ad altri processi, o anche a questo in futuro). Se la memoria suddetta non viene liberata correttamente, l'applicazione ogni volta si riserverà dei pezzetti di memoria e non li rilascerà mai, finendo con il saturare la memoria RAM della macchina (oppure finendo con l'essere terminata dal sistema operativo per uso eccessivo di memoria).
* Per liberare la memoria allocata dinamicamente con `malloc` si utilizza la funzione `free`.
* `free` prende in ingresso un puntatore e libera la memoria dinamica ad esso associata.
* Bisogna fare molta attenzione in caso di puntatori a puntatori: se si libera prima la memoria allocata al primo puntatore, sarà poi *impossibile* liberare quella allocata ai puntatori puntati dal primo: bisogna liberare *prima* la memoria allocata più "internamente".
* Questo tipo di errore è piuttosto subdolo: invertendo l'ultimo `for` e l'ultima istruzione `free`, si ottiene un programma sbagliato, che viene però compilato senza errori, e (spesso) eseguito senza errori. Proprio perché difficile da "riprodurre" si tratta di uno dei bug più difficili da eliminare!
* Il carattere speciale `\t` (tabular) è utile per spaziare omogeneamente colonne di caratteri.

### Stringhe di testo in C

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "Dimensione di un char: %d\n";
    printf(str, sizeof(char));
    char *nome = "Pluto";
    printf("Il nome del cane è: %s, di lunghezza %d\n", nome, strlen(nome));

    char *test = (char *) malloc(1000 * sizeof(char));
    test[0] = 'i';
    test[1] = 'f';
    test[2] = 't';
    test[3] = 's';
    test[4] = '\0';
    printf("La stringa è: %s, ed è lunga %d\n", test, strlen(test));
    printf("La stringa %s è uguale a %s? %d\n", "ifts", test, strcmp(test, "ifts"));
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* In C, il tipo `char` rappresenta un singolo carattere [ASCII](http://www.asciitable.com/)
* Si può creare un char mettendo il simbolo desiderato fra singoli apici, ad esempio per creare un char con valore `a` si scrive `'a'`.
* Il formattatore per il tipo `char` è `%c`
* Le stringhe di testo in C altro non sono che `char *`, contenenti tutti e `char` della stringa in sequenza e terminate dal carattere speciale `\0` (null).
* Le stringhe, essendo `char *`, possono essere manipolate esattamente come qualunque array (create con `malloc`, accedute posizionalmente, etc.).
* Il primo argoento della `printf` è un `char *`: ora che sappiamo creare variabili di questo tipo, possiamo anche cambiare dinamicamente il testo stampato da `printf` (o letto da `scanf`). È anche possibile stampare delle stringhe utilizzando il formattatore `%s`, in quel caso la stringa passata come argomento successivo verrà inserita al posto del formattatore.
* Non importa quanto grande sia lo spazio allocato per una stringa: essa si considera terminata solo quando viene incontrato il carattere `\0`.
* **Attenzione**: questo significa anche che una stringa alla quale manca il terminatore `\0`, se stampata ad esempio, verrà letta fino ad *oltre* la sua dimensione, ossia finché non verrà incontrato in memoria un byte che (più o meno per caso) valga `\0`. Questo significa che *molto facilmente* si otterranno errori di segmentazione se le stringhe che create non saranno propriamente "null-terminate".
* Esiste una libreria standard [cstring](http://www.cplusplus.com/reference/cstring/), il cui header è nominato `string.h`, che contiene un insieme di utilità per la manipolazione di stringhe.
* Esempi di funzioni disponibili in cstring sono:
  0. `char *strcpy(char *, char*)` -- restituisce una copia di una stringa.
  0. `char *strcat(char *, char*)` -- concatena due stringhe.
  0. `int strcmp(char *, char*)` -- confronta due stringhe, restituisce `0` se sono uguali, un numero diverso da `0` se non lo sono.
  0. `int strlen(char *)` -- restituisce la lunghezza di una stringa.

### Strutture dati

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct umano {
    char *nome;
    char *cognome;
    int anni;
};

void printUmano(struct umano *soggetto)
{
    printf("%s %s ha %d anni.\n", soggetto -> nome, soggetto -> cognome, soggetto -> anni);
}

struct umano *creaUmano(char *nome, char *cognome, int anni)
{
    struct umano *risultato = (struct umano*) malloc(sizeof(struct umano));
    // Di seguito, tre modi equivalenti per accedere ai campi!
    (*risultato).nome = nome;
    risultato[0].cognome = cognome;
    risultato -> anni = anni;
    return risultato;
}

int main(void)
{
    struct umano *mestesso = creaUmano("Danilo", "Pianini", 100);
    printUmano(mestesso);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* C consente di definire strutture dati personalizzate.
* Le strutture dati possono a loro volta contenere delle strutture dati
* La struttura dati è uno dei meccanismi più potenti che C mette a disposizione: essa consente infatti di organizzare le informazioni in maniera tale che riproducano il "dominio" del programma: un software che debba gestire, ad esempio, una scuola, non dovrà sempre lavorare con numeri e stringhe, ma potrà avere una struttura dati per ciascuna delle proprie *astrazioni*, ad esempio studente, docente, aula, classe, istituto...
* Una struttura dati comincia con la parola chiave `struct` ed è seguita da un nome, che costituisce anche il nome del tipo. Ad esempio, se creassi una `struct pippo`, il nome del tipo (che andrà ripetuto ogni volta che si dichiara una variabile con quel tipo) è `struct pippo`. Se si utilizza solo `pippo`, omettendo la keyword `struct`, il compilatore lancia un errore.
* Una struttura dati è composta da *campi*. I campi rappresentano lo *stato* della struttura dati, ossia ciò di cui è composta.
* Per accedere ai campi di una struct si utilizza l'operatore binario infisso `.`. L'operatore `.` prende la struttura dati a sinistra dell'operatore ed accede al campo scritto a destra.
* La macro `sizeof` funziona anche con i tipi `struct`, per cui è possibile creare puntatori (e quindi array) di `struct` arbitrarie.
* Il modo più comune di utilizzare le `struct` è tramite puntatori, che evitano inutili duplicazioni in memoria.
* Nel caso in cui si utilizzi un puntatore ad una struttura dati, è comunque possibile accedere ai campi utilizzando `.`. Bisogna avere però la cura di dereferenziare prima la variabile che si sta usando, utilizzando l'operatore `*`. Ad esempio, se si ha in mano una variabile `a` di tipo `struct pippo *` e si desidera accedere al campo `coda` della struttura suddetta, bisognerà scrivere `(*pippo).coda`. Le parentesi sono necessarie, perché l'operatore `.` è più prioritario dell'operatore `*`. Se omesse, si accederebbe al campo coda di un puntatore (campo non esistente), con risultati imprevedibili, e si effettuerebbe poi un reference, che molto probabilmente risulterebbe in un segmentatio fault.
* Essendo molto comune lavorare con i puntatori, esiste un operatore binario infisso che consente di evitare l'uso congiunto degli operatori `.` e `*` quando si manipola un puntatore a `struct`. Questo è l'operatore `->`, che, anche intuitivamente, simboleggia un deference seguito dall'accesso ad un campo. L'esempio precedente `(*pippo).coda` si srive quindi in modo equivalente `pippo -> coda`.

### Definizione di nuovi tipi con `typedef`

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct persona {
    char *nome;
    char *cognome;
    int anni;
};

typedef struct persona umano;

void printUmano(umano *soggetto)
{
    printf("%s %s ha %d anni.\n", soggetto -> nome, soggetto -> cognome, soggetto -> anni);
}

umano *creaUmano(char *nome, char *cognome, int anni) {
    umano *risultato = (umano*) malloc(sizeof(umano));
    risultato -> nome = nome;
    risultato -> cognome = cognome;
    risultato -> anni = anni;
    return risultato;
}

int main(void)
{
    umano *mestesso = creaUmano("Danilo", "Pianini", 100);
    printUmano(mestesso);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* C consente di definire nuovi tipi di dato utilizando l'istruzione `typedef`.
* `typedef` va seguita dal nome precedente del tipo, seguito poi dal nuovo nome del tipo.
* Ad esempio, `typedef int intero` definisce un nuovo tipo di dato di nome `intero`, che è lo stesso tipo di `int`. Dopo l'istruzione descritta prima, sarà legittimo scrivere ad esempio `intero a = 10`.
* È particolarmente utile utilizzare `typedef` in congiunzione con `struct`: questo consente di risparmiare la scrittura della keyword `struct` ogni volta che si utilizza la struttura dati.
* Nell'esempio, `struct persona` e `umano` sono tipi di dato utilizzabili intercambiabilmente.

### Definizione di nuovi tipi con `typedef`

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct persona {
    char *nome;
    char *cognome;
    int anni;
};

typedef struct persona umano;

void printUmano(umano *soggetto)
{
    printf("%s %s ha %d anni.\n", soggetto -> nome, soggetto -> cognome, soggetto -> anni);
}

umano *creaUmano(char *nome, char *cognome, int anni) {
    umano *risultato = (umano*) malloc(sizeof(umano));
    risultato -> nome = nome;
    risultato -> cognome = cognome;
    risultato -> anni = anni;
    return risultato;
}

int main(void)
{
    umano *mestesso = creaUmano("Danilo", "Pianini", 100);
    printUmano(mestesso);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* C consente di definire nuovi tipi di dato utilizando l'istruzione `typedef`.

### Uso congiunto di `struct` e `typedef`

{% highlight c %}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct umano {
    char *nome;
    char *cognome;
    int anni;
} umano;

void printUmano(umano *soggetto)
{
    printf("%s %s ha %d anni.\n", soggetto -> nome, soggetto -> cognome, soggetto -> anni);
}

umano *creaUmano(char *nome, char *cognome, int anni) {
    umano *risultato = (umano*) malloc(sizeof(umano));
    risultato -> nome = nome;
    risultato -> cognome = cognome;
    risultato -> anni = anni;
    return risultato;
}

int main(void)
{
    umano *mestesso = creaUmano("Danilo", "Pianini", 100);
    printUmano(mestesso);
    return 0;
}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Molto spesso, la definizione delle `struct` viene scritta direttamente all'interno dei `typedef`. Questo compatta la scrittura, ma va tenuto a mente che `struct` e `typedef` sono due operazioni completamente *distinte*.

### Applicazione C completa

A [questo indirizzo](https://bitbucket.org/danysk/finf-a-function-drawer) è disponibile un esempio di applicazione C completa, che include anche l'interfaccia grafica. Quest'applicazione fa uso delle librerie [Glib](https://wiki.gnome.org/Projects/GLib) per la gestione dei dati interni e [GTK+3](http://www.gtk.org/) (insieme a [GDK](https://developer.gnome.org/gdk3/stable/) e [cairo](http://cairographics.org/)) per il disegno delle finestre su schermo.

La gran parte del codice utilizzato dovrebbe esservi comprensibile.

Con ulteriore allenamento, partendo dalle basi studiate in queste cinque lezioni, dovreste essere in grado di comprendere ed apportare modifiche a software esistente scritto in linguaggio C.

## Lezione 06 (OOP1): elementi di programmazione ad oggetti e Java

### Ingegneria del Software e OOP

Argomenti trattati

* Il problema della complessità dei sistemi software moderni
* Ciclo di vita del software (analisi, progettazione implementazione, post-codifica)
* Problem domain vs solution domain
* I paradigmi di programmazione
* Il paradigma ad oggetti, elementi principali

### Java vs C

Argomenti trattati

* JVM e compilatore Java
* Compilazione ed esecuzione di HelloWorld
* Tipi primitivi (int, double, boolean)
* Definizione di variabili di tipi primitivi e String
* Costruttori di programmazione strutturata di base (if, while, for)
* Definizioni e chiamate di funzioni locali

Codice mostrato:

* [HelloWorld.java](06/HelloWorld.java)
* [Primo.java](06/Primo.java)
* [Secondo.java](06/Secondo.java)
* [Funzione.java](06/Funzione.java)
* [Primo.java](06/Primo.java)

## Lezione 07 (OOP2): Classi, campi e metodi

Metodologia di sviluppo

* Design dell'interfaccia della classe (UML e come scheletro della classe)
* Specifica del comportamento atteso (con classe di test/collaudo)
* Implementazione dello stato degli oggetti (campi, tassativamente privati)
* Implementazione dei metodi (uso di this per accedere ai campi)
* Verifica del test

Codice:

* [07/07-code.zip](07/07-code.zip)

## Lezione 08 (OOP3): Costruttori, codice statico, librerie

Argomenti

* Il costruttore come modalità flessibile per impostare lo stato iniziale di un oggetto
* Classi immutabili, campo final
* Metodi statici
* Import di classi e package
* Librerie: String, Math, java.util.Date

Codice:

* [08/08-code.zip](08/08-code.zip)

Esercizi proposti:

* si propongo 4 esercizi, in ordine Point2D, Point3D, Person e SquareGenerator
* per ognuno si fornisce un test che dovrà essere soddisfatto, e l'impalcatura della classe, da completare opportunamente
* il docente rimane a disposizione per controllare le vostre soluzioni funzionanti
* trovate lo zip del codice qui: [08/03-esercizi.zip](08/03-esercizi.zip)

## Lezione 09 (OOP4): Composizione e array

Argomenti

* Principi: Single Responsibility Principle (SRP), e Don't Repeat Yourself (DRY)
* Composizione come meccanismo di riuso
* Puntatore null e NullPointerException
* Array
* Argomenti da linea di comando

Codice:

* [08/08-code.zip](09/09-code.zip)

## Lezione 10 (OOP5): Eclipse come IDE, Interfacce e principio di sostituibilità

Argomenti

* Integrated Development Environments
* Eclipse come esempio di IDE
* Struttura del workspace, struttura dei progetti
* Creazione di nuovi progetti
* Strumenti per la compilazione automatizzata e l'esecuzione in-IDE
* Prospettive e viste, configurabilità dell'ambiente grafico
* Strumenti per la generazione di codice: generazione di stub di classi, autocompletamento del codice, strumenti di refactoring
* Utilizzo del debugger: inserimento di breakpoints, lancio in modalità debug, visualizzazione del valore delle variabili a virtual machine sospesa, operazioni di step-into e step-over, hot code injection
* L'interfaccia come contratto o specifica di una categoria di oggetti
* Classi che implementano interfacce
* Sostituibilità di una interfaccia con la classe che la implementa: *se C è una classe che implementa l'interfaccia I, tutti gli oggetti dichiarati di tipo I in un programma possono essere sostituiti con oggetti di tipo C senza intaccare la funzionalità del programma*
* Progettazione di interfacce *prima* di fornire la loro implementazione

Codice:

* [Codice direttamente importabile in Eclipse](10/ifts09.zip)

## Lezione 11 (OOP6): Ereditarietà e polimorfismo

Argomenti

* Estensione di classi
* Subclassing come metodo per evitare duplicazioni di codice
* Override di metodi delle superclassi
* Chiamata di metodi e costruttori della classe padre: la keyword `super`
* Limitazioni all'estensione tramite l'uso di `final`
* Estensione e subtyping
* Polimorfismo e sostuibilità di superclassi con sottoclassi
* La classe `Object` come radice della gerarchia delle classi
* Uso congiunto di classe e interfacce, ereditarietà multipla con interfacce, [pattern Adapter](https://it.wikipedia.org/wiki/Adapter_pattern) (cenno)
* La notazione UML come linguaggio grafico (solo diagramma delle classi, uso non rigoroso)
* Classi astratte, differenza fra classi astratte e interfacce, la keyword `abstract`, il [pattern Teplate Method (cenni)](https://it.wikipedia.org/wiki/Template_method)
* Tipi primitivi vs. wrapper types, autoboxing, autodeboxing
* Tipi compile-time e tipi run-time e loro identificazione: la keyord `instanceof`, l'operatore di cast
* Copie difensive e side effects (ripasso)

Slide (con codice):

* Ereditarietà
* Polimorfismo

Gli studenti sono invitati ad *esercitarsi*: ad esempio, una volta studiato e compreso il codice delle slide, possono provare a riprodure il programma, e ad estenderlo, ad esempio:

* Creare un contatore che conti solo i numeri pari, partendo da `Counter`
* Creare un contatore di Fibonacci, che ad ogni  `increment()` vada al numero successivo della [serie di Fibonacci](https://it.wikipedia.org/wiki/Successione_di_Fibonacci) (1, 1, 2, 3, 5, 8, 13, 21, 34, 55...)
* In ogni esercizio, sfruttare *al massimo* l'ereditarietà per usare il codice delle superclassi

## Slide per tutta la parte di object oriented programming

Il seguente materiale, preso dal corso OOP tenuto a Cesena, è utilizzabile come materiale didattico integrativo per i contenuti visti fin'ora.

* http://campus.unibo.it/194314/
* http://campus.unibo.it/194315/
* http://campus.unibo.it/198298/
* http://campus.unibo.it/198299/
* http://campus.unibo.it/200264/
