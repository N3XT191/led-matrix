#include <vector>
#include "gpio.h"

std::vector<bool> scanAll(){
    int rows[] = {1, 2, 3, 4};
    int columns[] = {1, 2, 3, 4};

    std::vector<bool> keysPressed = std::vector<bool>(16,0);
    for(int i = 0; i < 4; i++){
        digitalWrite(columns[i], HIGH);
        for(int j = 0; j < 4; j++){
           keysPressed[4*i+j] = digitalRead(rows[j]); 
        }
    }

    return keysPressed;
}

void setBrightness(){
    int numbers[] = {5,6,7,8,9,10,11,13,14,15};
    bool pressed = false;
    do{
        std::vector<bool> keysPressed = scanAll(); 
        for(auto number: numbers){
            if(keysPressed[number]){
                std::cout << "brightness to " << number << "\n";
                pressed = true;
            }
        }
    } while (!pressed);
}

void setCurrentPage(){

}

void addBook(){

}

void displayModes(){

}

void selectMode(std::vector<bool> keysPressed) {
    if(keysPressed[0])
        setBrightness();
    else if(keysPressed[1])
        setCurrentPage();
    else if(keysPressed[2])
        addBook();
    else{
        for(int i = 4; i < 16; i++){
            if(keysPressed[i]){
                displayModes();
                return;
            }
        }
    }

}

int main(){
    std::vector<bool> keysPressed = scanAll();
    selectMode(keysPressed);
}
