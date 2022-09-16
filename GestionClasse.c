#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int jour ;
    int mois ;
    int annee ;
    }date ;
typedef struct{
    char * nom;
    char * prenom;
    date dateN ;
    int age ;
}personne ;
void TriTable(personne* T, int size){
	int i,j;
    for (  i = 0 ; i< size-1 ; i++){
            for( j = i+1 ; j<size ; j++){
                if (T[j].age>T[i].age){
                    personne ech = T[j] ;
                        T[j] = T[i] ;
                        T[i]= ech ;
                }
            }
    }
    for( i = 0 ; i<size ; i++){
        printf("nom : %s \t prenom : %s \t age : %d ans \n",T[i].nom,T[i].prenom,T[i].age);

}
}
void moyenne(personne* T, int size){
    int Moyenne ,Somme,i;
    for ( i = 0 ; i< size ; i++){
        Somme += T[i].age ;
    }
    Moyenne = Somme / size ;
    printf("la moyenne d'age est %d\n",Moyenne);



    }

int calcAge(int day, int month, int year){
	int presentDay = 16 ,presentMonth = 9 ,presentYear = 2022;
	if(month > presentMonth){
		return presentYear - year -1;
	}
	if(month == presentMonth && day > presentDay){
		return presentYear - year -1;
	}
	
	return presentYear - year ;
	
	
}

int main(){
    int Taille,NTaille,i ;
    do{
    printf("donner les nombres de personnes ");
    scanf("%d",&Taille);
    printf("\n================================\n");
    }while(Taille<=0 );
    personne *personnes= malloc(Taille * sizeof(personne)) ;

    for( i = 0 ; i<Taille ; i++){
        printf("Veuillez saisir le prenom de personne numero %d : ",i+1);
        scanf("%s",personnes[i].prenom);
        printf("Veuillez saisir le nom de %s   :",personnes[i].prenom);
        scanf("%s",personnes[i].nom);
        printf("Veuillez saisir la date Naissance de %s: 'JJ/MM/AAAA' \n",personnes[i].prenom);
        scanf("%d/%d/%d",&personnes[i].dateN.jour,&personnes[i].dateN.mois,&personnes[i].dateN.annee);

        personnes[i].age = calcAge(personnes[i].dateN.jour,personnes[i].dateN.mois,personnes[i].dateN.annee);
        printf("age : %d\n",personnes[i].age);
        printf("\n******************************************\n");
    }

        printf("\n\n\n******************************************\n\n\n");
        printf("***********la liste d'eleve***********\n\n\n");
        for( i = 0 ; i<Taille ; i++){
            printf("nom : %s \t prenom : %s \t age : %d ans \n",personnes[i].nom,personnes[i].prenom,personnes[i].age);
        }
        printf("\n\n===================================================================\n\n\n");
        printf("=========================la liste d'information avant le tri avec l'age===================\n\n\n");
        TriTable(personnes,Taille);
        printf("\n\n============================================================\n");
        printf("==================le plus grand eleve===================\n\n\n");
        printf("%s %s est le plus grand personne dans la liste d'age : %d",personnes[0].prenom,personnes[0].nom,personnes[0].age);
        printf("\n\n============================================================\n");
        printf("====================le plus petit eleve=================\n\n\n");
        printf("%s %s est le plus petit personne dans la liste d'age : %d",personnes[Taille-1].prenom,personnes[Taille-1].nom,personnes[Taille-1].age);
        printf("\n\n==============================================================\n");
        printf("===============la moyenne d'age des eleves==================\n\n\n");
        int moy ;
        char reponse ;
        moyenne(personnes,Taille);
        printf("Veux-tu ajouter un d'autre element (O/N)");
        scanf(" %c",&reponse);
            while(reponse=='O' || reponse == 'o'){
            printf("saisir le nombre d'element  ajouter : ");
            scanf("%d",&NTaille);
            Taille = Taille + NTaille ;
            personnes = realloc(personnes ,Taille * sizeof(personne));
            for( i = Taille-NTaille ; i<Taille ; i++){
        printf("Veuillez saisir le prenom de personne numero %d : ",i+1);
        scanf("%s",personnes[i].prenom);
        printf("Veuillez saisir le nom de %s   :",personnes[i].prenom);
        scanf("%s",personnes[i].nom);
        printf("Veuillez saisir la date Naissance de %s: 'JJ/MM/AAAA' \n",personnes[i].prenom);
        scanf("%d/%d/%d",&personnes[i].dateN.jour,&personnes[i].dateN.mois,personnes[i].dateN.annee);
        personnes[i].age = calcAge(personnes[i].dateN.jour,personnes[i].dateN.mois,personnes[i].dateN.annee);
        
        printf("\n======================================================\n");
    }

        printf("\n\n\n===================================================\n\n\n");
        printf("=====================la liste d'eleve====================\n\n\n");
        for( i = 0 ; i<Taille ; i++){
            printf("nom : %s \t prenom : %s \t age : %d ans \n",personnes[i].nom,personnes[i].prenom,personnes[i].age);
        }
        printf("\n\n=====================================================\n\n\n");
        printf("***********la liste d'information avant le tri avec l'age***********\n\n\n");
        TriTable(personnes,Taille);
        printf("\n\n=====================================================\n");
        printf("===================le plus grand eleve====================\n\n\n");
        printf("%s %s est le plus grand personne dans la liste d'age : %d",personnes[0].prenom,personnes[0].nom,personnes[0].age);
        printf("\n\n=========================================================\n");
        printf("======================le plus grand eleve======================\n\n\n");
        printf("%s %s est le plus petit personne dans la liste d'age : %d",personnes[Taille-1].prenom,personnes[Taille-1].nom,personnes[Taille-1].age);
        printf("\n\n========================================================\n");
        printf("=========================la moyenne d'age des eleves====================\n\n\n");
        int moy ;
        moyenne(personnes,Taille);
        printf("Veux-tu ajouter un d'autre element (O/N)");
        scanf(" %c",&reponse);
        }

    return 0;
}
