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
* Il programma stampa a video: `La variabile vale: 15, mentre l'intero vale 20`


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
