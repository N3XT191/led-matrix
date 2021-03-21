#define HIGH 1
#define LOW 0
#define OUTPUT 1

#include <iostream>

void digitalWrite(int gpio, int level){
    std::cout << "Setting " << gpio << " to " << level  << "\n";
}

int digitalRead(int gpio){
    std::cout << "Reading " << gpio << "\n";
    return 1;
}
void wiringPiSetup(){
    std::cout << "wiring Pi Setup\n";
}

void pinMode(int gpio, int mode){
    std::cout << "pin " << gpio << ", mode " << mode <<"\n"; 
}


