/**
 * Quizstunde mit Felix Fritz
 * zu Programmieren 1
 * am 03.12.2018 an der Hochschule Kempten.
 * 
 * Online Compiler Explorer: https://gcc.godbolt.org
 * 
 * Manche Kommentare enthalten noch BONUS-Fragen,
 * die noch behandelt werden koennen.
 * 
 * (c) 2018
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <conio.h>


/**
 * char_to_int - konvertiert ein char in ein int.
 * Das Character '0' hat den Wert 48, '9' ist 57.
 * Ein invalider Input resultiert in -1.
 * 
 * BONUS-Frage 1: Hexadezimalzahlen haben noch die Buchstaben
 * A, B, ..., F mit ihren korrespondierenden Dezimalzahlen 10, 11, ..., 15.
 * Wie kann das bei der Konvertierung implementiert werden?
 */
int char_to_int(char input)
{
    if(input >= '0' && input <= '9')
        return input - '0';
    return -1;
}


/**
 * to_upper_case - konvertiert einen Kleinbuchstaben in einen Grossbuchstaben.
 * Geht nur bei Buchstaben von 'a' bis 'z'.
 * 
 * BONUS-Frage 2: Wie kann eine Funktion to_lower_case implementiert werden,
 * die Grossbuchstaben in Kleinbuchstaben konvertiert?
 */
char to_upper_case(char input)
{
    if(input >= 'a' && input <= 'z')
        return input - ('a' - 'A');
    return input;
}


/**
 * better_strlen - Anzahl der Charaktere in einem String zaehlen.
 * 
 * BONUS-Frage 3: Derzeit werden die beiden Variablen result und x verwendet.
 * Eine Variable ist ueberfluessig. Wie kann unsere for-loop-Loesung mit nur
 * einer Variablen implementiert werden?
 */
int better_strlen(char* input)
{
    int result = 0;

    for(int x = 0; input[x] != '\0'; x++)
        result += 1;

    return result;
}


/**
 * even_better_strlen - strlen Implementierung von Linus Torvalds (fast).
 * 
 * https://github.com/torvalds/linux/blob/master/lib/string.c#L479
 */
int even_better_strlen(const char* input)
{
    const char* c = input;
    while(*c != '\0')
    {
        c++;
    }

    return c - input;
}


/**
 * str_to_int - wandelt einen string in einen int um.
 * 
 * BONUS-Frage 4: Diese Funktion hat einen kleinen Bug!
 * Teste verschiedene Eingabewerte und vergleiche, ob
 * das resultierende Ergebnis den Erwartungen entspricht.
 * 
 * BONUS-Frage 5: Wie kann eine Funktion str_to_float implementiert
 * werden, die einen String in eine Float Zahl verwandelt?
 */
int str_to_int(char* str, bool* success)
{
    int result = 0;

    // vorzeichen ist entweder 1 oder -1.
    // bei einem vorzeichen behaftetem String wird am Ende mit -1 multipliziert.
    int vorzeichen = 1;

    char* ptr = str;
    int tmp;

    *success = true;

    // Ist das String Vorzeichen-behaftet?
    if(*ptr == '-')
    {
        vorzeichen = -1;
        ptr++;
    }

    // Loop durch jede Ziffer im String
    for(; *ptr != '\0'; ptr++)
    {
        tmp = char_to_int(*ptr);

        // Alternativ kann hier ueberprueft werden, ob tmp == -1 ist
        // (siehe char_to_int Implementierung)
        if(tmp < 0 || tmp > 9)
        {
            *success = false;
            break;
        }

        // Overflow vorbeugen!
        // Ist result zu gross, so rutscht die Rechnung ins Negative
        if((result * 10) + tmp < 0)
        {
            *success = false;
            break;
        }

        // Berechnung: Zehnerzahl nach links "verschieben", Einerzahl auf tmp setzen
        result = (result * 10) + tmp;
    }

    return vorzeichen * result;
}


/**
 * str_to_upper - macht aus allen Kleinbuchstaben Grossbuchstaben.
 * Es wird mittels memory allocation Speicher reserviert
 * => nicht vergessen, das Ergebnis freizusetzen (free)!
 * 
 * Wenn nicht genug Speicher da ist, wird NULL zurueckgegeben.
 */
char* str_to_upper(char* str)
{
    int x;
    char* result = malloc((strlen(str) + 1) * sizeof(char));
    // alternativ:
    // char* result = calloc(strlen(str) + 1, sizeof(char));

    // Nicht genug Speicher?
    if(result == NULL)
        return NULL;

    for(x = 0; x < strlen(str); x++)
    {
        result[x] = to_upper_case(str[x]);
    }

    // 0-terminierende Zeichenketten!
    // was passiert, wenn diese Zeile weggelassen wird?
    result[x] = '\0';

    return result;
}


/**
 * test_functions - testet (fast) alle unsere Funktionen
 * Schlaegt ein Test fehl so wird das ganze Programm abgebrochen
 */
void test_functions()
{
    /* Teste char_to_int */
    assert(0 == char_to_int('0'));
    assert(1 == char_to_int('1'));
    assert(2 == char_to_int('2'));
    assert(3 == char_to_int('3'));
    assert(4 == char_to_int('4'));
    assert(5 == char_to_int('5'));
    assert(6 == char_to_int('6'));
    assert(7 == char_to_int('7'));
    assert(8 == char_to_int('8'));
    assert(9 == char_to_int('9'));
    assert(-1 == char_to_int('A'));
    assert(-1 == char_to_int('a'));

    /* Teste to_upper_case */
    assert('A' == to_upper_case('a'));
    assert('B' == to_upper_case('b'));
    assert('N' == to_upper_case('n'));
    assert('X' == to_upper_case('x'));
    assert('Y' == to_upper_case('y'));
    assert('Z' == to_upper_case('z'));
    assert('A' == to_upper_case('A'));
    assert('B' == to_upper_case('B'));
    assert('Y' == to_upper_case('Y'));
    assert('Z' == to_upper_case('Z'));
    assert('0' == to_upper_case('0'));
    assert('9' == to_upper_case('9'));

    /* Teste better_strlen */
    assert(5 == better_strlen("hello"));
    assert(2 == better_strlen("hi"));
    assert(0 == better_strlen(""));

    /* Teste str_to_int */
    bool b;
    assert(0 == str_to_int("0", &b));
    assert(b == true);

    assert(1 == str_to_int("1", &b));
    assert(b == true);

    assert(-1 == str_to_int("-1", &b));
    assert(b == true);

    assert(1234560 == str_to_int("0001234560", &b));
    assert(b == true);

    // undefiniertes Ergebnis nicht testen
    str_to_int("123.123", &b);
    assert(b == false);

    str_to_int("818B2", &b);
    assert(b == false);

    str_to_int("818b2", &b);
    assert(b == false);
    // Tipp zu BONUS-Frage 4: Was sind Extremfaelle, die
    // in diesem Test noch nicht abgedeckt wurden?

    /* Teste str_to_upper */
    char* result;
    result = str_to_upper("abcdefghijklmnopqrstuvwxyz");
    assert(strcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", result) == 0);
    free(result);

    result = str_to_upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    assert(strcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", result) == 0);
    free(result);

    result = str_to_upper("0123456789!.-(),/x");
    assert(strcmp("0123456789!.-(),/X", result) == 0);
    free(result);

    /* Wenn das Programm hierhin kommt, so waren alle Tests erfolgreich */
}



int main()
{
    test_functions();
    printf("Alle tests erfolgreich abgeschlossen\n");

    printf("Sag was dazu: ");
    char c;
    while((c = getchar()) != '\n')
    {
        printf("%c", to_upper_case(c));
    }
    printf("\n");

    _getch();

    return 0;
}