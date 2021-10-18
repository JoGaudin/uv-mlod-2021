#include <stdio.h>

//Exercice 1

float ticket_price(float plein_tarif, int age_fils){
    float prix_ticket;
    if(age_fils <= 2){
        prix_ticket = plein_tarif*0.1;
    }
    else if (age_fils >= 2 && age_fils <= 12)
    {
        prix_ticket = plein_tarif*0.5;
    }
    else if (age_fils > 12)
    {
        prix_ticket = plein_tarif;
    }
    return prix_ticket;
}

//Exercice 2

void de(int number){
    int count = 0;
    if(number < 3 || number > 18){
        printf("Le nombre n'est pas compris en 3 et 18\n");
    }else{
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 7; j++){
                for(int k = 1; k < 7; k++){
                    if(i+j+k == number){
                        count++;
                        printf("%d%d%d\n", i, j, k);                        
                    }
                }
            }
        }
    }
    printf("compteur : %d\n", count);
}

//Exercice 3

int nombre_parfait(int n){
    int somme = 0;
    for(int i = 1; i < n; i ++){
        if(n%i == 0){
            somme += i;
        }
    }
    if(somme == n){
        return 1;
    }
    return 0;

}

void read(int N){
    for(int j = 0; j < N; j++){
        if(nombre_parfait(j)){
            printf("%d est un nombre parfait\n", j);
        }        
    }
}

//Exercice 4

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier n){
    if(n == 1){
        return 1;
    }else{
        return n*factorielle(n-1);
    }
    return 0;
}

int main(void) {
    //Exercice 1
    //printf("prix du billet : %f\n", ticket_price(prix, age));

    //Exercice 2
    //de(10);

    //Exercice 3
    int N;
    printf("Veuillez saisir un nombre\n");
    scanf("%d", &N);
    read(N);
    

    //Exercice 4
    //int n = 6;
    //printf("Factorielle de %d est : %d\n", n, factorielle(n));
    printf("hello world");

    return 0;
}

