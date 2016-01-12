---
layout: default
---

# Elementi di Programmazione e Sviluppo di Applicazioni

Il seguente documento mira a integrare il materiale presentato di mano in mano nel corso IFTS per la parte riguardante il modulo di *Elementi di Programmazione e Sviluppo di Applicazioni*.

In caso di problemi (link mancanti, problemi di visualizzazione...) si prega di contattare direttamente [Danilo Pianini](mailto:danilo.pianini@unibo.it).

## Lezione 00: presentazione del corso

Questa parte del corso ha le proprie slides in formato `pdf`. Sono reperibili [a questo link](01/slides/slides.pdf).

La macchina virtuale utilizzata nel corso è disponibile [clickando qui](https://mega.nz/#!mVMnnZwR!FaFTpD5LkljwRKaW1f-dH5EGUmp2Sgve_JR8j9uPEXI).

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

## Compilazione di sorgenti scritti in C

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

## Un programma C "vuoto"

{% highlight c %}
int main(void)
{

}
{% endhighlight %}

*Cosa imparare da questo esempio:*

* Ogni programma C ha un "punto d'ingresso" che si chiama `main`
* Un `main` ha un *corpo* racchiuso fra parentesi graffe, che contiene le istruzioni
* C è un linguaggio **case sensitive** (come la stragrande maggioranza dei linguaggi di programmazione), ossia fa differenza fra maiuscole e minuscole: `Main` è diverso da `main` e anche da `mAin`.

## Un programma C che stampa a video

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

## Un programma C con variabili intere

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

## Stampare multiple variabili

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


## Interi come valori booleani

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


## L'istruzione `if`

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

## L'istruzione `else`
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

## Numeri reali: il tipo `double`

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
