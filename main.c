#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct narzedzie {
    char nazwa[20];
    int ilosc;
    int dzienWyp, miesiacWyp, rokWyp;
    int okresWyp;
    struct narzedzie *next;
} narz;

typedef struct osoba {
    char imie[20];
    char nazwisko[50];
    narz *narzedzia;
    struct osoba *next;
} os;

void dodaj_narz(narz**);
int dlugosc_listy(narz**);
void edytuj_narz(narz**);
void usun_narz(narz**);
void wyswietl_wyp(narz**);
void wyswietl_niewyp(narz**);
void dodaj_os(os**);
void usun_os(os**);
void wyswietl_os(os**);

int main()
{
    narz *listaN = NULL;
    os *listaO = NULL;
    int wybor = -1;
    while(1) {
        system("cls");
        printf("----- MENU -----\n\n");
        printf("1. Dodaj narzedzie\n");
        printf("2. Edytuj narzedzie\n");
        printf("3. Usun narzedzie\n");
        printf("4. Wyswietl wypozyczone narzedzia\n");
        printf("5. Wyswietl niewypozyczone narzedzia\n\n");
        printf("6. Dodaj osobe\n");
        printf("7. Usun osobe\n");
        printf("8. Wyswietl dane osoby na podstawie nazwiska(lub jego poczatku)\n\n");
        printf("9. Zamknij program\n\n\n");
        printf("Co wykonac? (1-9) ");
        scanf("%d", &wybor);
        while(wybor < 1 || wybor > 9) {
            printf("\nNiepoprawny numer opcji, podaj jeszcze raz!\n\nCo wykonac? (1-9) ");
            scanf("%d", &wybor);
        }
        switch(wybor) {
            case 1:
                printf("\n*** Dodawanie narzedzia ***\n\n");
                dodaj_narz(&listaN);
                break;
            case 2:
                printf("\n*** Edytowanie narzedzia ***\n\n");
                edytuj_narz(&listaN);
                break;
            case 3:
                printf("\n*** Usuwanie narzedzia ***\n\n");
                usun_narz(&listaN);
                break;
            case 4:
                printf("\n*** Wyswietlanie wypozyczonych narzedzi ***\n\n");
                wyswietl_wyp(&listaN);
                break;
            case 5:
                printf("\n*** Wyswietlanie niewypozyczonych narzedzi ***\n\n");
                wyswietl_niewyp(&listaN);
                break;
            case 6:
                printf("\n*** Dodawanie osoby ***\n\n");
                dodaj_os(&listaO);
                break;
            case 7:
                printf("\n*** Usuwanie osoby ***\n\n");
                usun_os(&listaO);
                break;
            case 8:
                printf("\n*** Wyswietlanie danych osoby na podstawie nazwiska(lub jego poczatku)***\n\n");
                wyswietl_os(&listaO);
                break;
            case 9:
                return 0;
        }
    }
    return 0;
}

void dodaj_narz(narz **lista) {
    narz *pom;
    pom = malloc(sizeof(narz*));
    printf("Podaj nazwe: ");
    scanf("%s", pom->nazwa);
    printf("Podaj ilosc wypozyczen: ");
    scanf("%d", &(pom->ilosc));
    printf("Podaj date wypozyczenia(dzien miesiac rok): ");
    scanf("%d %d %d", &pom->dzienWyp, &pom->miesiacWyp, &pom->rokWyp);
    printf("Podaj okres wypozyczenia w dniach: ");
    scanf("%d", &pom->okresWyp);


    /* funkcja dodaj ponizej (dodaje wezel do listy) */
    pom->next = NULL;
    if((*lista) == NULL) {
        *lista = pom;
    } else {
        narz *wsk = *lista;
        while(wsk->next != NULL) {
            wsk = wsk->next;
        }
        wsk->next = pom;
    }
    free(pom);
}

int dlugosc_listy(narz **listaN) {
    int i;
    narz *wsk = *listaN;
    if((*listaN) == NULL)
        return 0;
    else {
        i = 1;
        narz *wsk = *listaN;
        while(wsk->next != NULL) {
            i++;
            wsk = wsk->next;
        }
    }
    return i;
}

void edytuj_narz(narz **listaN) {
    int n, i, dl_listy = dlugosc_listy(&listaN), wybor;
    char nowaNazwa[20];
    printf("Podaj numer narzedzia na liscie ktore chcesz edytowac: ");
    scanf("%d", &n);
    while(n < 0 || n > dl_listy) {
        printf("Podaj poprawny numer narzedzia! Musi on sie miescic w przedziale <1; %d>\n", dl_listy);
        scanf("%d", &n);
    }
    //if((*lista) == NULL) {
        //printf("Lista pusta!");
    //} else {
        narz *wsk = *listaN;
        i = 1;
        while(wsk->next != NULL) {
            i++;
            wsk = wsk->next;
        }
        printf("Wybrales narzedzie nr %d na liscie. Obecne dane narzedzia to:\nNazwa: %s\nIlosc: %d\nData wypozyczenia: %d.%d.%d\nOkres wypozyczenia: %d dni\n\nCo chcesz w nim zmienic?\n1. Nazwe\n2. Ilosc\n3. Date wypozyczenia\n4. Okres wypozyczenia\n\nTwoj wybor (1-4): ", n, wsk->nazwa, wsk->ilosc, wsk->dzienWyp, wsk->miesiacWyp, wsk->rokWyp, wsk->okresWyp);
        scanf("%d", &wybor);
        while(wybor < 1 || wybor > 4) {
            printf("Niepoprawny numer opcji, podaj jeszcze raz!\n\nTwoj wybor: ");
            scanf("%d", &wybor);
        }
        switch(wybor) {
            case 1:
                printf("\nPodaj nowa nazwe: ");
                gets(nowaNazwa);
                strcpy(wsk->nazwa, nowaNazwa);
                //wsk->nazwa = nowaNazwa;
                break;
            case 2:
                printf("\nPodaj nowa ilosc: ");
                scanf("%d", &wsk->ilosc);
                break;
            case 3:
                printf("\nPodaj nowa date wypozyczenia(dzien miesiac rok): ");
                scanf("%d %d %d", &wsk->dzienWyp, &wsk->miesiacWyp, &wsk->rokWyp);
                break;
            case 4:
                printf("\nPodaj nowy okres wypozyczenia w dniach: ");
                scanf("%d", &wsk->okresWyp);
                break;
        }
    //}
}

void usun_narz(narz **listaN) {

}

void wyswietl_wyp(narz **listaN) {

}

void wyswietl_niewyp(narz **listaN) {

}

void dodaj_os(os **listaO) {

}

void usun_os(os **listaO) {

}

void wyswietl_os(os **listaO) {

}
