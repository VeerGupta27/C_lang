#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char computer_choice(int c);
void check_winner(char cc, char spx);

int main(){

//seeding the random number
srand(time(0));
int random_number= (rand()%(100-9+1))+9;

//taking users choice
char spx;
printf("Enter S,P,X for stone, paper, scissors respectively : ");
scanf("%c",&spx);



//tacking computers choice
char cc= computer_choice(random_number);
printf("Computer choose : %c\n",cc);
check_winner(cc, spx);

return 0;
}



char computer_choice(int c){
// for creating computer's choice

char computer_choice;

if(c>1 && c<=40){
    computer_choice='S';
}

if(c>40 && c<=80){
    computer_choice='P';
}

else{
    computer_choice='X';
}

return computer_choice;
}

//for checking the winner
void check_winner(char computer, char user){

//comparision when computer's choice is Stone
if (computer=='S'){
    switch(user){
       
        case 'S':
           printf("its a tie");
            break;

        case 'P':
           printf("User won");
            break;

        case 'X':
           printf("Coputer won");
            break;
    }
}

 //comparision when computer's choice is Paper
else if (computer=='P'){
    switch(user){
       
        case 'P':
           printf("its a tie");
            break;

        case 'X':
           printf("User won");
            break;

        case 'S':
           printf("Coputer won");
            break;

    }

    }
    
    
    //comparision when computer's choice is Scissor
else{
    switch(user){
       
        case 'X':
           printf("its a tie");
            break;

        case 'S':
           printf("User won");
            break;

        case 'P':
           printf("Coputer won");
            break;

    }



}
}
