#include <iostream>
#include <ctime>


using namespace std;

void Rock(int num){
    
    if(num == 1){
        cout << "The Computer chose Rock" << endl;
        cout << "It is a tie!! " << endl;
    }
        
    if(num == 2){
        cout << "The Computer chose Paper" << endl;
        cout << "You lost!!! " << endl;
    }

    if(num == 3){
        cout << "The Computer chose Scissor" << endl;
        cout << "You Won!!! " << endl;
    }
}

void Paper(int num){
    
    if(num == 1){
        cout << "The Computer chose Rock" << endl;
        cout << "You Won!! " << endl;
    }
        
    if(num == 2){
        cout << "The Computer chose Paper" << endl;
        cout << "You Tied!!! " << endl;
    }

    if(num == 3){
        cout << "The Computer chose Scissor" << endl;
        cout << "You Lost!!! " << endl;
    }
}

void Scissor(int num){
    
    if(num == 1){
        cout << "The Computer chose Rock" << endl;
        cout << "You Lost!! " << endl;
    }
        
    if(num == 2){
        cout << "The Computer chose Paper" << endl;
        cout << "You Won!!! " << endl;
    }

    if(num == 3){
        cout << "The Computer chose Scissor" << endl;
        cout << "You Tied!!! " << endl;
    }
}

int main(){
    int choice;
    cout << "Rock ......... 1" << endl;
    cout << "Paper......... 2" << endl;
    cout << "Scissor....... 3" << endl;

    cout << "Choose the number: " << endl;
    cin >> choice;

    srand(time(0));

    int num = rand() % 3 + 1;
    
    switch(choice){
        case 1:
            Rock(num);
            break;
            
        case 2:
            Paper(num);
            break;
            
        case 3:
            Scissor(num);
            break;
    }
    
    return 0;
}