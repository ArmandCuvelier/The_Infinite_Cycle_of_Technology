#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

//Skill is a data structur who keep the differents skills about the hero. This skill is usefull to determinate the winner of a fight
    typedef struct{
        int HP;
        int ATQ;
        int DEF;
        int niveau;
    }skill;

//function who create a mini game. The user must enter the same number as displayed. It will repeat in function of the parameter max.
int mission_task(int max) {

    int number;//Variable who are a number aleatory
    int i;//Variable who count the number of iterations
    int answer;//Variable who keep the answer of the user
    int valuetype;//Variable who keep 1 if the user don't write an integer. Else 0;
    srand(time(NULL));
    
    for (i = 0; i < max; i++) {
        number = rand() % 10;
        printf("\n%i", number);
        valuetype=0;
        while (!valuetype) {
            if (scanf("%d", &answer) != 1) {
                while (getchar() != '\n');
                    printf("Error");
            }
            else {
                if (answer == number) {
                    valuetype = 1;
                }
                else {
                    printf("Error");
                }
            }
        }
    }
    return 0;
}

//function who create an opponent and his skill who depends of the chapter
skill create_opponent(int nbchapter, char language[]){
    skill opponent;
    srand(time(NULL));
    switch (nbchapter)
    {
    case 0 :
        opponent.HP=2;
        opponent.ATQ=2;
        opponent.DEF=2;
        break;
    case 1 :
        opponent.HP= rand()%12;
        opponent.ATQ= rand()%12;
        opponent.DEF= rand()%12;
        break;
    case 2 :
        opponent.HP= rand()%14;
        opponent.ATQ= rand()%14;
        opponent.DEF= rand()%14;
        break;
    case 3 :
        opponent.HP= rand()%16;
        opponent.ATQ= rand()%16;
        opponent.DEF= rand()%16;
        break;
    case 4 :
        opponent.HP= rand()%18;
        opponent.ATQ= rand()%18;
        opponent.DEF= rand()%18;
        break;
    default:
        opponent.HP=0;
        opponent.ATQ=0;
        opponent.DEF=0;
        break;
    }
    opponent.niveau=(opponent.ATQ+opponent.DEF+opponent.HP)/3;
    if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
        printf("An opponent at level %i attacks you\n", opponent.niveau);
    }
    else{
        printf("Un adversaire au niveau %i vous attaque\n", opponent.niveau);
    }
    return opponent;
}

//function who create an opponent and compare the skill of the opponent and the hero. It return the number of skill who are greater than or equal
int fight( int ATQ, int DEF, int HP, int nbchapter, char language[]){
    skill opponent;
    int result;
    result=0;
    opponent = create_opponent(nbchapter,language);
    if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
        printf("\nYour skills : \nATQ : %i DEF : %i HP : %i\n\n",ATQ,DEF,HP);
        printf("Les compétences de votre opposant : \nATQ : %i DEF : %i HP : %i\n\n",opponent.ATQ,opponent.DEF,opponent.HP);
    }
    else{
        printf("\nVos compétences : \nATQ : %i DEF : %i HP : %i\n\n",ATQ,DEF,HP);
        printf("Les compétences de votre opposant : \nATQ : %i DEF : %i HP : %i\n\n",opponent.ATQ,opponent.DEF,opponent.HP);
    }
    if (DEF>=opponent.DEF){
       result+=1;
    }
    if (ATQ>=opponent.ATQ){
        result+=1;
    }
    if (HP>=opponent.HP){
        result+=1;
    }
    return result;
}

//Function who ask the user beetween 2 possibilities. The user may know the good way because it says in the text. If the user fail, the function return a variable resultat.
int labyrinth(char language[]){
    char tab[8];//Array of the good choice in MAJ to win the game
    char tab2[8];//Array of the good choice in MIN to win the game
    char answer[2];//Variable who keep the answer of the questions
    int result=0;//Variable who keep the information about if the user win this game
    int i=0;//Variable who count the numnber of iteration in the while

    //The good choices in MAJ
    tab[0]='L';
    tab[1]='L';
    tab[2]='R';
    tab[3]='L';
    tab[4]='R';
    tab[5]='R';
    tab[6]='R';
    tab[7]='L';

    //The good choices in MIN
    tab2[0]='l';
    tab2[1]='l';
    tab2[2]='r';
    tab2[3]='l';
    tab2[4]='r';
    tab2[5]='r';
    tab2[6]='r';
    tab2[7]='l';

    while (result == 0 && i <=7){

            if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
                printf("Left(L) or Right(R)");
                scanf("%s",&answer);
                if (tab[i] != answer[0] && tab2[i] != answer[0]){
                    result=1;
                }
                i++;
            }
            else{
                printf("Gauche(L) ou Droite(R)");
                scanf("%s",&answer);
                if (tab[i] != answer[0] && tab2[i] != answer[0]){
                    result=1;
                }
                i++;
            }
        }

    return result;
}

//function who are the game of rock, paper and scissors. Here, the user have 100% of chance to win because the opponent already choose the bad possibilities.
int rock_paper_scissors(char language[]){

    char answer[2];//Variable who keep the answer of the questions

    if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
        printf("Choose Rock (R), Paper (P), ou Scissors (S) : ");
        scanf("%s",&answer);
        while (answer[0] != 'P' && answer[0] != 'R' && answer[0] != 'S' && answer[0] != 'p' && answer[0] != 'r' && answer[0] != 's'){
            printf("Error");
            scanf("%s",&answer);
        }
        if (answer[0] == 'R'|| answer[0] == 'r') {
            printf("Your opponent choose the scissors. You win !\n");
        }
        else if (answer[0] == 'S' || answer[0] == 's') {
            printf("Your opponent choose the paper. You win !\n");

        }
        else {
            printf("Your opponent choose the rock. You win !\n");
        }
    }
    else{
        printf("Choisissez Pierre (R), Papier (P), ou Ciseaux (S) : ");
        scanf("%s",&answer);
        while (answer[0] != 'P' && answer[0] != 'R' && answer[0] != 'S' && answer[0] != 'p' && answer[0] != 'r' && answer[0] != 's'){
            printf("Error");
            scanf("%s",&answer);
        }
        if (answer[0] == 'R' || answer[0] == 'r') {
            printf("Votre adversaire a choisi le ciseau. Vous gagnez !\n");
        }
        else if (answer[0] == 'S' || answer[0] == 's') {
            printf("Votre adversaire a choisi le papier. Vous gagnez !\n");

        }
        else {
            printf("Votre adversaire a choisi la pierre. Vous gagnez !\n");
        }
    }
}


int main(){

    char language[3];// Variable who keep the information about the choice of the languages
    char pseudo[20];//Variable who keep the name of the hero
    int age;//Variable who keep the age of the hero
    char sex[2];//Variable who keep the sex of the hero
    char faction[2];//Variable who keep the information about the faction of the hero
    skill hero;//Variable who contains the skill of the hero 
    int counter = 0;//Variable who count the lines in the read of a fill to stop the read
    char agreement[4];//Variable who keep the agreement of the user about the start of the 
    char *game_choose;//Variable who are the fill of the inreoduction depending on the language
    char *game_choose2;//Variable whoh are the fill of the chapter 1 depending of the language
    char *game_choose3;//Variable whoh are the fill of the chapter 2 depending of the language
    char *game_choose4;//Variable whoh are the fill of the chapter 3 depending of the language
    char *game_choose5;//Variable whoh are the fill of the introduction of the end depending of the language
    char *game_choose6;//Variable whoh are the fill of the end 1 depending of the language
    char *game_choose7;//Variable whoh are the fill of the end 2 depending of the language
    int endprog=0;//Variable who keep the information about the exit of the user : 1 to exit and 0 to continue
    int nbchapter;//Variable who keep the number of the chapter. The prologue is 0
    int result;//Variable who keep the result of a fight
    char answer[2];//Variable who keep the answer of the questions
    float percentage=0;//Variable who keep the information about the percentage of the game

    //We ask the user about the choice of the language 
    while (strcmp(language, "GB") != 0  && strcmp(language, "gb") != 0 && strcmp(language, "FR") != 0 && strcmp(language, "fr") != 0) {
        printf("English(GB) / Français(FR)");
        scanf("\n%2s",language);
    }

    //So, in function of the language choosen, we defined the file english or the file french
    if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
        game_choose = "./IntroductionGB.txt";
        game_choose2 = "./Chapter1GB.txt";
        game_choose3 = "./Chapter2GB.txt";
        game_choose4 = "./Chapter3GB.txt";
        game_choose5 = "./End_introGB.txt";
        game_choose6 = "./End1GB.txt";
        game_choose7 = "./End2GB.txt";
    }
    else{
        if (strcmp(language, "FR") == 0 || strcmp(language, "fr") == 0){
            game_choose = "./IntroductionFR.txt";
            game_choose2 = "./Chapter1FR.txt";
            game_choose3 = "./Chapter2FR.txt";
            game_choose4 = "./Chapter3FR.txt";
            game_choose5 = "./End_introFR.txt";
            game_choose6 = "./End1FR.txt";
            game_choose7 = "./End2FR.txt";
        }
    }

    //Introduction

    //Open the file of the introduction
    FILE *game = fopen(game_choose, "r");
    struct stat sb;
    stat(game_choose , &sb);
    char *essai=malloc(sb.st_size);

    //Read the file line by line until : 
    //  - All the lines of the file were read
    //  - The variable endprog is 1
    while ((fscanf(game , "%[^\n] " , essai) !=EOF) && endprog != 1) {
        printf("%s\n" , essai);
        counter++;//The variable counter corresponds to the line number

        //So the variable counter allows to add something at a specific line
        switch (counter){

            //For 1, it ask the user about his desire to start the game. It will also verify if the user answer with the right thing. If he don't want, it will end the programm
            case 1:
                scanf("%s",agreement);
                while (strcmp(agreement, "OUI") != 0  && strcmp(agreement, "oui") != 0 && strcmp(agreement, "NON") != 0 && strcmp(agreement, "non") != 0  && strcmp(agreement, "YES") != 0  && strcmp(agreement, "yes") != 0 && strcmp(agreement, "no") != 0 && strcmp(agreement, "NO") != 0) {
                    printf("Error\n");
                    scanf("%s",agreement);
                }
                if (strcmp(agreement, "NON") == 0 || strcmp(agreement, "non") == 0 || strcmp(agreement, "NO") == 0 || strcmp(agreement, "no") == 0){
                    nbchapter=0;
                    fclose(game);
                    endprog=1;
                }
                printf("\n");
                break;

            //For 4, it will add some space
            case 4:
                printf("\n");
                break;

            //For 4, it will add some space and initialize the chapter at 0 for the prologue
            case 5:
                printf("\n");
                nbchapter=0;
                break;

            //For 7, it will ask about the name of the hero
            case 7:
                scanf("%s", pseudo);
                break;

            //For 7, it will ask about the age of the hero. If the age is inferior at 18, the programm end because the game is PEGI 18
            case 8:
                scanf("%d", &age);
                if (age<18){
                    printf("PEGI 18\n");
                    fclose(game);
                    endprog=1;
                }
                break;
            
            //For 9, it will ask about the sex of the hero and it will also verify if the user answer with the right thing
            case 9:
                scanf("%s", sex);
                while (strcmp(sex, "H") != 0  && strcmp(sex, "F") != 0 && strcmp(sex, "M") != 0 && strcmp(sex, "W") != 0  && strcmp(sex, "h") != 0  && strcmp(sex, "f") != 0 && strcmp(sex, "w") != 0 && strcmp(sex, "m") != 0){
                    printf("Error\n");
                    scanf("%s",sex);
                }
                break;

            //For 13, it will ask about the choice of the factions and depending of the choose, the competence will be initialize. It will also verify if the user answer with the right thing
            case 13:
                scanf("%s",faction);
                while (strcmp(faction, "W") != 0  && strcmp(faction, "w") != 0 && strcmp(faction, "C") != 0 && strcmp(faction, "c") != 0 && strcmp(faction, "S") != 0 && strcmp(faction, "s") != 0) {
                    printf("Error\n");
                    scanf("%s",faction);
                }

                if (strcmp(faction, "S") == 0 || strcmp(faction, "s") == 0){
                    hero.HP=8;
                    hero.ATQ=10;
                    hero.DEF=12;
                }
                else{
                    if (strcmp(faction, "c") == 0 || strcmp(faction, "C") == 0){
                        hero.HP=12;
                        hero.ATQ=8;
                        hero.DEF=10;
                    }
                    else{
                        hero.HP=10;
                        hero.ATQ=12;
                        hero.DEF=8;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n",hero.ATQ, hero.DEF, hero.HP);
                break;

            //For 15, it will add some space
            case 15 :
                printf("\n");
                break;
            
            //For 16, it will start a mini-game with the function mission_task
            case 16 :
                mission_task(3);
                break;
            
            //For 21, it will whange the skill of the hero depending of the food
            case 21 :
                scanf("%s",answer);
                while (strcmp(answer, "S") != 0 && strcmp(answer, "s") != 0 && strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0  && strcmp(answer, "p") != 0  && strcmp(answer, "P") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "S") == 0 || strcmp(answer, "S") == 0){
                    hero.HP += 2;
                }
                if (strcmp(answer, "p") == 0 || strcmp(answer, "P") == 0){
                    hero.DEF += 1;
                }
                if (strcmp(answer, "h") == 0 || strcmp(answer, "H") == 0){
                    hero.ATQ -= 1;
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n",hero.ATQ, hero.DEF, hero.HP);
                break;

            //For 26, it will determinate if the user win a fighth. If he don't win, he lose the game and the programm end. Else, the game continue.
            case 26 :
                result=fight(hero.ATQ,hero.DEF,hero.HP,nbchapter,language);
                if (result!=2 && result!=3){
                    printf("Game Over");
                    fclose(game);
                    endprog=1;
                }
                break;

            //For 27, the user decides where he win a point of skill because he win a fight
            case 27 :
                scanf("%s",answer);
                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                    hero.HP+=1;
                }
                else{
                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                        hero.ATQ+=1;
                    }
                    else{
                        hero.DEF+=1;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;
            
            //Add space for the chapter 1
            case 28 :
                printf("\n");
                break;

            default:
                break;
        }
    }

    //Close the file
    fclose(game);

    //Chapter 1

    //Open the file of the chapter 1
    FILE *game2 = fopen(game_choose2, "r");
    struct stat sb2;
    stat(game_choose2 , &sb2);
    char *essai2=malloc(sb2.st_size);

    //Reset the varable counter because it will count the line in the file
    counter=0;

    //Read the file line by line until : 
    //  - All the lines of the file were read
    //  - The variable endprog is 1
    while ((fscanf(game2 , "%[^\n] " , essai2) !=EOF) && endprog != 1) {
        printf("%s\n" , essai2);
        counter++;//The variable counter corresponds to the line number

        switch (counter)
        {

            //For 1, it will add some space and initialize the chapter at 1 for the chapter 1
            case 1:
                printf("\n");
                nbchapter=1;
                getchar();
                getchar();
                break;
            
            //For 7 ,it will whange the skill of the hero depending of the choice about the drink.If he accept to drink, there are 3 possibilities :
            // - game over
            // - +1 in each skill
            // - -1 in each skill
            // - nothing
            case 7 :
                scanf("%s",answer);
                if (strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0){
                    srand(time(NULL));
                    result=rand()%4;
                    switch (result){
                        case 0 :
                            break;
                        
                        case 1 :
                            hero.ATQ+=1;
                            hero.DEF+=1;
                            hero.HP+=1;
                            printf("HP+1, ATQ+1, DEf+1");
                            printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                            break;
                        
                        case 2 : 
                            hero.ATQ-=1;
                            hero.DEF-=1;
                            hero.HP-=1;
                            printf("HP-1, ATQ-1, DEf-1");
                            printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                            break;
                        
                        case 3 :
                            printf("Game Over");
                            fclose(game2);
                            endprog=1;
                            break;

                        default:
                            break;
                    }
                }
                break;

            //For 13, it will start a mini-game with the function mission_task
            case 13 :
                mission_task(5);
                break;

            //For 14 and 22, the user decides where he win a point of skill
            case 14 :
            case 22 :
                scanf("%s",answer);
                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                    hero.HP+=1;
                }
                else{
                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                        hero.ATQ+=1;
                    }
                    else{
                        hero.DEF+=1;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;

            //For 18, the user decides the direction. If he takes the left path, he find a chest but he had to turn around.
            case 18 :
                scanf("%s",answer);
                while (strcmp(answer, "L") != 0 && strcmp(answer, "l") != 0 && strcmp(answer, "r") != 0 && strcmp(answer, "R") != 0 ) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "L") == 0 || strcmp(answer, "l") == 0){
                    if (strcmp(language, "FR") == 0 || strcmp(language, "fr") == 0){
                        printf("Vous trouvez un coffre mais hélas le chemin est sans issue. Vous faites demi-tour.");
                    }
                    else{
                        printf("You find a chest but unfortunately the path is dead end. You turn around.");
                    }
                    printf("\n\nATQ+1");
                    hero.ATQ+=1;
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;
            
            //For 21, it will determinate if the user win a fighth. If he don't win, he lose the game and the programm end. Else, the game continue.
            case 21 :
                result=fight(hero.ATQ,hero.DEF,hero.HP,nbchapter,language);
                if (result!=2 && result!=3){
                    printf("Game Over");
                    fclose(game2);
                    endprog=1;
                }
                break;

            //Add space for the chapter 2
            case 28 :
                printf("\n");
                break;

            default:
                break;
        }
    }

    //Close the file
    fclose(game2);

    //Chapter 2

    //Open the file of the chapter 2
    FILE *game3 = fopen(game_choose3, "r");
    struct stat sb3;
    stat(game_choose3 , &sb3);
    char *essai3=malloc(sb3.st_size);

    //Reset the varable counter because it will count the line in the file
    counter=0;

    //Read the file line by line until : 
    //  - All the lines of the file were read
    //  - The variable endprog is 1
    while ((fscanf(game3 , "%[^\n] " , essai3) !=EOF) && endprog != 1) {
        printf("%s\n" , essai3);
        counter++;
        switch (counter)
        {
            //For 1, it will add some space and initialize the chapter at 2 for the chapter 2
            case 1:
                printf("\n");
                nbchapter=2;
                getchar();
                getchar();
                break;

            //For 19 ,it will whange the skill of the hero depending of the choice about the recipe. Depending to the recipe, there are 3 possibilities :
            // - +1 in DEF
            // - +1 in each skill
            // - -1 in each skill
            case 19 :
                scanf("%s",answer);
                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "B") != 0  && strcmp(answer, "b") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "B") == 0 || strcmp(answer, "b") == 0){
                    printf("HP+1 ATQ+1 DEF+1");
                    hero.HP+=1;
                    hero.ATQ+=1;
                    hero.DEF+=1;
                }
                else{
                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                        printf("HP-1 ATQ-1 DEF-1");
                        hero.HP-=1;
                        hero.ATQ-=1;
                        hero.DEF-=1;
                    }
                    else{
                        printf("DEF+1");
                        hero.DEF+=1;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;

            //For 23, it will determinate if the user win a fighth. If he don't win, he lose the game and the programm end. Else, the game continue.
            case 23 :
                result=fight(hero.ATQ,hero.DEF,hero.HP,nbchapter,language);
                if (result!=2 && result!=3){
                    printf("Game Over");
                    fclose(game3);
                    endprog=1;
                }
                break;

            //For 24, 32 and 42, the user decides where he win a point of skill
            case 24 :
            case 32 :
            case 42 :
                scanf("%s",answer);
                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                    hero.HP+=1;
                }
                else{
                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                        hero.ATQ+=1;
                    }
                    else{
                        hero.DEF+=1;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;
            
            //For 28, the user decides the direction. If he takes the left path, he find a chest but he had to turn around.
            case 28 :
                scanf("%s",answer);
                while (strcmp(answer, "C") != 0 && strcmp(answer, "c") != 0 && strcmp(answer, "G") != 0 && strcmp(answer, "g") != 0 ) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "g") == 0 || strcmp(answer, "G") == 0){
                    if (strcmp(language, "FR") == 0 || strcmp(language, "fr") == 0){
                        printf("Vous trouvez un coffre.");
                    }
                    else{
                        printf("You find a chest.");
                    }
                    printf("\n\nATQ-1");
                    hero.ATQ-=1;
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;

            //For 31, it will start a mini-game with the function mission_task
            case 31 :
                mission_task(4);
                break;

            //Add space for the chapter 3
            case 14 :
            case 21 :
            case 33 :
                printf("\n");
                break;

            default:
                break;
        }
    }

    //Close the file
    fclose(game3);

    //Chapter 3

    //Open the file of the chapter 3
    FILE *game4 = fopen(game_choose4, "r");
    struct stat sb4;
    stat(game_choose4 , &sb4);
    char *essai4=malloc(sb4.st_size);

    //Reset the varable counter because it will count the line in the file
    counter=0;

    //Read the file line by line until : 
    //  - All the lines of the file were read
    //  - The variable endprog is 1
    while ((fscanf(game4 , "%[^\n] " , essai4) !=EOF) && endprog != 1) {
        printf("%s\n" , essai4);
        counter++;
        switch (counter)
        {
            //For 1, it will add some space and initialize the chapter at 3 for the chapter 3
            case 1:
                printf("\n");
                nbchapter=3;
                getchar();
                getchar();
                break;

            case 14 :
                result=labyrinth(language);
                if (result==1){
                    printf("Game Over");
                    fclose(game3);
                    endprog=1;
                }
                break;
            
            case 34 :
                rock_paper_scissors(language);
                break;

            //For 15, 21 and 35, the user decides where he win a point of skill
            case 15 :
            case 21 :
            case 35 :
                scanf("%s",answer);
                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }
                if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                    hero.HP+=1;
                }
                else{
                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                        hero.ATQ+=1;
                    }
                    else{
                        hero.DEF+=1;
                    }
                }
                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                break;
            
            //Add space
            case 19 :
            case 23 :
            case 27 :
            case 33 :
            case 37 :
            case 40 :
                printf("\n");
                break;

            default:
                break;
        }
    }

    //Close the file
    fclose(game4);

    //Chapter 4

    //Open the file of the chapter 4
    FILE *game5 = fopen(game_choose5, "r");
    struct stat sb5;
    stat(game_choose5 , &sb5);
    char *essai5=malloc(sb5.st_size);

    //Reset the varable counter because it will count the line in the file
    counter=0;

    //Read the file line by line until : 
    //  - All the lines of the file were read
    //  - The variable endprog is 1
    while ((fscanf(game5 , "%[^\n] " , essai5) !=EOF) && endprog != 1) {
        printf("%s\n" , essai5);
        counter++;
        switch (counter)
        {
            //For 1, it will add some space and initialize the chapter at 4 for the chapter 4
            case 1 :
                printf("\n");
                nbchapter=4;
                break;
            
            //For 6, the user decide the end of the game. Depending of the choice, it will start a file
            case 6 :
                scanf("%s",answer);
                while (strcmp(answer, "E") != 0 && strcmp(answer, "e") != 0 && strcmp(answer, "C") != 0 && strcmp(answer, "c") != 0) {
                    printf("Error\n");
                    scanf("%s",answer);
                }

                //For the end 1
                if (strcmp(answer, "E") == 0 || strcmp(answer, "e") == 0){
                    FILE *game6 = fopen(game_choose6, "r");
                    struct stat sb6;
                    stat(game_choose6 , &sb6);
                    char *essai6=malloc(sb6.st_size);
                    counter=0;
                    while ((fscanf(game6 , "%[^\n] " , essai6) !=EOF) && endprog != 1) {
                        printf("%s\n" , essai6);
                        counter++;
                        switch (counter){

                        //For 1, the user decides where he win a point of skill and the nbchapter is 5 because it's the end
                        case 1 :
                            nbchapter=5;
                            scanf("%s",answer);
                            while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                                printf("Error\n");
                                scanf("%s",answer);
                            }
                            if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                                hero.HP+=1;
                            }
                            else{
                                if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                                    hero.ATQ+=1;
                                }
                                else{
                                    hero.DEF+=1;
                                }
                            }
                            printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                            break;
                        
                            default:
                                break;
                        }
                    }
                }

                //For the end 2
                else{
                    FILE *game7 = fopen(game_choose7, "r");
                    struct stat sb7;
                    stat(game_choose7 , &sb7);
                    char *essai7=malloc(sb7.st_size);
                    counter=0;
                    while ((fscanf(game7 , "%[^\n] " , essai7) !=EOF) && endprog != 1) {
                        printf("%s\n" , essai7);
                        counter++;
                        switch (counter){

                            //For 1, the user decides where he win a point of skill and the nbchapter is 5 because it's the end
                            case 1 :
                            case 19 :
                                scanf("%s",answer);
                                while (strcmp(answer, "H") != 0 && strcmp(answer, "h") != 0 && strcmp(answer, "A") != 0 && strcmp(answer, "a") != 0  && strcmp(answer, "d") != 0  && strcmp(answer, "D") != 0) {
                                    printf("Error\n");
                                    scanf("%s",answer);
                                }
                                if (strcmp(answer, "H") == 0 || strcmp(answer, "h") == 0){
                                    hero.HP+=1;
                                }
                                else{
                                    if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0){
                                        hero.ATQ+=1;
                                    }
                                    else{
                                        hero.DEF+=1;
                                    }
                                }
                                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                                break;
                            
                            //For 10, the user have 3 possiblities :
                            // - go to left and attack a guard
                            // - go to the center but it's a trap. So, it's game over
                            // - go to right and nothing happen
                            case 10 :
                                scanf("%s",answer);
                                while (strcmp(answer, "L") != 0 && strcmp(answer, "l") != 0 && strcmp(answer, "C") != 0 && strcmp(answer, "c") != 0  && strcmp(answer, "r") != 0  && strcmp(answer, "R") != 0) {
                                    printf("Error\n");
                                    scanf("%s",answer);
                                }
                                if (strcmp(answer, "l") == 0 || strcmp(answer, "L") == 0){
                                    result=fight(hero.ATQ,hero.DEF,hero.HP,nbchapter+1,language);
                                    if (result!=2 && result!=3){
                                        printf("Game Over");
                                        fclose(game3);
                                        endprog=1;
                                    }
                                }
                                else{
                                    if (strcmp(answer, "C") == 0 || strcmp(answer, "c") == 0){
                                        printf("Game Over");
                                        fclose(game3);
                                        endprog=1;
                                    }
                                }
                                printf("\nATQ : %i DEF : %i HP : %i\n\n", hero.ATQ, hero.DEF, hero.HP);
                                break;

                                //For 20, nb chapter is 5 beacuse it's the end
                                case 20:
                                    nbchapter=5;

                            default:
                                break;
                        }
                    }
                fclose(game5);
                    endprog=1;
                }
                

        default:
            break;
        }
    }

    //The variable counter corresponds to the line number
    //Calculate the progression in the adventure
    percentage=(nbchapter*100)/5;
    if (strcmp(language, "GB") == 0 || strcmp(language, "gb") == 0){
        printf("\nYou have reached %f %% of the game", percentage);
    }
    else{
        if (strcmp(language, "FR") == 0 || strcmp(language, "fr") == 0){
            printf("\nTu es arrivé à %f %% du jeu", percentage);
        }
    }

    //Allows the program to not close immediatly after
    printf("\nEND\n");
    getchar();
    getchar();
    return 0;
}