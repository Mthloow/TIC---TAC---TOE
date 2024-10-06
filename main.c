#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>


void plateau_morpion(char plateau[]){
    printf("%c  | %c | %c\n", plateau[0], plateau[1], plateau[2]);
    printf("-----------\n");
    printf("%c  | %c | %c\n", plateau[3], plateau[4], plateau[5]);
    printf("-----------\n");
    printf("%c  | %c | %c\n", plateau[6], plateau[7], plateau[8]);
}

bool combinaison_victoire(char plateau[]){

    const int combinaison[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}
    };
    for (int i = 0; i < 8; i++)
    {
       if (plateau[combinaison[i][0]] == plateau[combinaison[i][1]] &&
            plateau[combinaison[i][1]] == plateau[combinaison[i][2]] &&
            plateau[combinaison[i][0]] != ' ')
        {
            return true;
        }
    }
    return false;
}


bool verification_plateau(char plateau[]){

    for (int i = 0; i < 9; i++)
    {
        if (plateau[i] != 'X' && plateau[i] != 'O')
        {
            return false;
        }        
    }
return true;
}

void tour_ordinateur(char plateau[]){ 

    srand(time(NULL));
    int placement_ordinateur;

    do{
        placement_ordinateur = rand() % 9;

    } while (plateau[placement_ordinateur] != ' ');

    plateau[placement_ordinateur] = 'X';
}

void tour_joueur(char plateau[]){

    int placement_joueur;

    do{
        printf("Choissisez où jouer entre 0 et 8 : \n");
        scanf("%d", &placement_joueur);

    } while (placement_joueur < 0 || placement_joueur > 8 || plateau[placement_joueur] != ' ');

    plateau[placement_joueur] = 'O';
}

 


int main(){
    char plateau[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool partie_terminer;
    char nom_du_joueur[45];
    char nouvelle_partie;
    
    printf("Bienvenue dans la partie de tic - tac - toe !!!\n");
    printf("Veuillez entrer votre nom pour la partie : \n");
    scanf("%s",nom_du_joueur);
    printf("\n");

    do {
        for (int i = 0; i < 9; i++)
        {
            plateau[i] = ' ';
        }
        
            partie_terminer = false;
            plateau_morpion(plateau);

        while (!partie_terminer)
        {

            tour_joueur(plateau);
            plateau_morpion(plateau);

            if (combinaison_victoire(plateau))
            {
                printf("%s a gagné !\n",nom_du_joueur);
                partie_terminer = true;
            }

            if (verification_plateau(plateau) && !partie_terminer)
            {
                printf("Match Nul !!\n");
                partie_terminer = true;
            }
            
            if (!partie_terminer)
            {
                printf("\n\n");
                printf("Tour de l'ordinateur\n");
                tour_ordinateur(plateau);
                plateau_morpion(plateau);
                sleep(2);

                if (combinaison_victoire(plateau))
                {
                    printf("L'ordinateur a gagné !\n");
                    partie_terminer = true;
                }
            }
        } 

        do {
            printf("Voulez vous rejouer ? (y/n) : ");
            scanf(" %c", &nouvelle_partie);

        } while (nouvelle_partie != 'y' && nouvelle_partie != 'n');
        
        if (nouvelle_partie == 'y')
        {
            system("clear");
        }
        
    }while (nouvelle_partie == 'y');
    
    printf("Merci d'avoir joué !!! \n");
    return 0;
}
