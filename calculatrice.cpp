#define _CRT_SECURE_NO_WARNINGS // Pour le warning sur scanf
#include <stdio.h>
#include<windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    //menu 
  
    int continuer = 1;
    int choix = 0;
    int chiffre1 = 0;
    int chiffre2 = 0;
    int operateur = 0;
    int nbrTour = 0;
    int resultat[256];
    do 
    {
        printf("Bienvenue sur la calculatrice\n");
        printf("-----MENU------\n");
        printf("1 - Faire un calcule\n");
        printf("2 - Afficher l'historique\n");
        printf("3 - Quitter la calculatrice\n");
        printf("Quel est votre choix : ");
        int retour = scanf("%d", &choix);
    
        switch (choix)
        {
        case 1 :
            printf("\n");
            printf("Entrez votre premier chiffre : ");
            scanf("%d", &chiffre1);
            printf("choisir son opérateur : \n");
            printf("1 - +\n");
            printf("2 - -\n");
            printf("3 - *\n");
            printf("4 - /\n");
            scanf("%d", &operateur);
            printf("Entrez votre deuxieme chiffre : ");
            scanf("%d", &chiffre2);

            if (operateur == 1)
            {
                char ecrit = printf("%d + %d = %d\n", chiffre1, chiffre2, chiffre1 + chiffre2);
                resultat[nbrTour] = chiffre1 + chiffre2;
                nbrTour++;
                break;
            }
            else if (operateur == 2)
            {
                printf("%d - %d = %d\n", chiffre1, chiffre2, chiffre1 - chiffre2);
                resultat[nbrTour] = chiffre1 - chiffre2;
                nbrTour++;
                break;
            }
            else if (operateur == 3)
            {
                printf("%d x %d = %d\n", chiffre1, chiffre2, chiffre1 * chiffre2);
                resultat[nbrTour] = chiffre1 * chiffre2;
                nbrTour++;
                break;
            }
            else
            {
                if (chiffre2 != 0)
                {
                    printf("%d / %d = %d\n", chiffre1, chiffre2, chiffre1 / chiffre2);
                    resultat[nbrTour] = chiffre1 / chiffre2;
                    nbrTour++;
                    continuer = 0;
                }
                else {
                    printf("Erreur, impossible de diviser par 0\n");
                    continuer = 0;
                }
                
            }
            printf("\n");
            break;
        case 2 :
            printf("\n");
            if (nbrTour == 0) {
                printf("Vous n'avez pour l'instant pas d'historique.\n");
            }
            else {
                printf("--------------Voici l'historique-------------\n");
                for (int i = 0; i < nbrTour; i++)
                {
                    printf("%d) %d\n", i + 1, resultat[i]);

                }
            }
            printf("\n");
            break;
        case 3 :
            exit(0);
        default:
            printf("\n");
            printf("ce choix n'existe pas\n");
            printf("\n");
            break;
        }
        printf("Voulez vous continuer : [1 - OUI] [0 - NON] : ");
        scanf("%d", &continuer);
        printf("\n");
    } while (continuer);
    
}