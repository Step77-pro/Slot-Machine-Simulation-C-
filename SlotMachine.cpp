#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

enum fruits{
    cherry,
    lemob,
    berry,
    seven,
    bell,
};

fruits spinReel(){
    int index = rand() % 5;
    return static_cast<fruits>(index);
    
   
}
int main() {
    int balance = 0;
    int command = 0;
    
    std::vector<std::string> symbols = {"cherry", "lemon", "berry", "seven", "bell"};
    
    srand(time(0));
    
    while(true){
       
        std::cout << " === SLOT MACHINE ===" << std::endl;
        
        std::cout << "Your Balance:" << balance << std::endl;
        
        std::cout << "1 - Spin" << std::endl << "2 - exit" << std::endl << "3 - Top up money" << std::endl;
        std::cin >> command;
    
        
        if(command == 1){
            
            if(balance < 10){
                std::cout << "Top up Money" << std::endl;
                continue;
            }
                
            fruits r1 = spinReel();
            fruits r2 = spinReel();
            fruits r3 = spinReel();
            
            std::cout << symbols[static_cast<int>(r1)] << " | "
            << symbols [static_cast<int>(r2)] << " | "
            << symbols [static_cast<int>(r3)] << std::endl;
            
            if(r1 == r2 && r2 == r3){
                balance += 50;
                std::cout << "You win!!!" << std::endl;
                }
            else{
                balance -= 10;
                std::cout <<"You lost" << std::endl;
            }
            
        }
        else if(command != 1 && command != 2 && command != 3){
            std::cout << "ERROR" << std::endl;
        }
        else if(command == 3){
            int top_up;
            std::cout << "How much money you want top up:";
            std::cin >> top_up;
            
            if(top_up < 0){
                std::cout << "Wrong number!!!";
                continue;
            }
            balance += top_up;
        }
        else{
            return 0;
        }
       
    }
        
}
