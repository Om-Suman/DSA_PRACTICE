#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void showWinner(char player,char computer);

int main() {
    char player;
    char computer;
    player = getUserChoice();
    std::cout<<"Your choice is ";
    showChoice(player);
    computer = getComputerChoice();
    std::cout<<"Computer choice is ";
    showChoice(computer);
    showWinner(player,computer);

    return 0;
}


char getUserChoice(){
    char player ;
    std::cout<<"*************** This is a rock-paper-sccissor game ***********8\n";
    do {
        std::cout<<"choose one of the following\n";
        std::cout<<"r: rock\n";
        std::cout<<"p: paper\n";
        std::cout<<"s: scissor\n";
        std::cin>>player;
        }
           while (player!='r' && player!='p' && player!='s');
           return player;

}

char getComputerChoice(){
    int choice;
    srand(time(NULL));
    choice = rand() % 3 + 1 ; 

    switch (choice)
    {
    case 1: return 'r';
    case 2: return 'p';
    case 3: return 's';
}
return 0;
}

void showChoice(char choice){
    switch(choice) {
        case 'r':std::cout<<"rock\n";
                 break;
        case 'p':std::cout<<"paper\n";
                 break;
        case 's':std::cout<<"sccissors\n";
                 break;
    }
}

void showWinner(char player,char computer){
    switch (player) {
        case 'r' : if (computer == 'r'){
                        std::cout<<"It's tie!\n";
                    }
                    else if (computer == 'p'){
                        std::cout<<"You won!\n";
                    }
                    else {
                        std::cout<<"Computer won!\n";
                    }
        case 'p' : if (computer == 'r'){
                        std::cout<<"Computer won!\n";
                    }
                    else if (computer == 'p'){
                        std::cout<<"It's tie!\n";
                    }
                    else {
                        std::cout<<"You won!\n";
                    }
        case 's' : if (computer == 's'){
                        std::cout<<"It's tie!\n";
                    }
                    else if (computer == 'p'){
                        std::cout<<"You won!\n";
                    }
                    else {
                        std::cout<<"Computer won!\n";
                    }
    }
}