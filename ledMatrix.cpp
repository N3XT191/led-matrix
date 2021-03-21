#include <bitset>
#include <wiringPi.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <curl/curl.h>

#define PIN_CS 27
#define PIN_CLK 22
#define PIN_DIN 17
#define CLK_DELAY_US 1

std::vector<std::vector<bool>>&  numberToMatrix(std::vector<std::vector<bool>>&  number, unsigned int y){
    switch(y){
        case 0: 
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][0] = 1;
            number[1][4] = 1;
            number[2][0] = 1;
            number[2][4] = 1;
            number[3][0] = 1;
            number[3][4] = 1;
            number[4][0] = 1;
            number[4][4] = 1;
            number[5][0] = 1;
            number[5][4] = 1;
            number[6][0] = 1;
            number[6][4] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 1: 
            number[0][2] = 1;
            number[1][1] = 1;
            number[1][2] = 1;
            number[2][2] = 1;
            number[3][2] = 1;
            number[4][2] = 1;
            number[5][2] = 1;
            number[6][2] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 2: 
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][0] = 1;
            number[1][4] = 1;
            number[2][4] = 1;
            number[3][3] = 1;
            number[4][2] = 1;
            number[5][1] = 1;
            number[6][0] = 1;
            number[7][0] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            number[7][4] = 1;
            break;

        case 3: 
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][0] = 1;
            number[1][4] = 1;
            number[2][4] = 1;
            number[3][2] = 1;
            number[3][3] = 1;
            number[4][4] = 1;
            number[5][4] = 1;
            number[6][0] = 1;
            number[6][4] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 4: 
            number[0][3] = 1;
            number[1][2] = 1;
            number[1][3] = 1;
            number[2][1] = 1;
            number[2][3] = 1;
            number[3][0] = 1;
            number[3][3] = 1;
            number[4][0] = 1;
            number[4][1] = 1;
            number[4][2] = 1;
            number[4][3] = 1;
            number[4][4] = 1;
            number[5][3] = 1;
            number[6][3] = 1;
            number[7][3] = 1;
            break;

        case 5: 
            number[0][0] = 1;
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[0][4] = 1;
            number[1][0] = 1;
            number[2][0] = 1;
            number[3][0] = 1;
            number[3][1] = 1;
            number[3][2] = 1;
            number[3][3] = 1;
            number[4][4] = 1;
            number[5][4] = 1;
            number[6][0] = 1;
            number[6][4] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 6: 
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][1] = 1;
            number[2][0] = 1;
            number[3][0] = 1;
            number[3][1] = 1;
            number[3][2] = 1;
            number[3][3] = 1;
            number[4][0] = 1;
            number[4][4] = 1;
            number[5][0] = 1;
            number[5][4] = 1;
            number[6][0] = 1;
            number[6][4] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 7: 
            number[0][0] = 1;
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[0][4] = 1;
            number[1][4] = 1;
            number[2][3] = 1;
            number[3][3] = 1;
            number[4][2] = 1;
            number[5][2] = 1;
            number[6][1] = 1;
            number[7][1] = 1;
            break;

        case 8: 
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][0] = 1;
            number[1][4] = 1;
            number[2][0] = 1;
            number[2][4] = 1;
            number[3][1] = 1;
            number[3][2] = 1;
            number[3][3] = 1;
            number[4][0] = 1;
            number[4][4] = 1;
            number[5][0] = 1;
            number[5][4] = 1;
            number[6][0] = 1;
            number[6][4] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            number[7][3] = 1;
            break;

        case 9:
            number[0][1] = 1;
            number[0][2] = 1;
            number[0][3] = 1;
            number[1][0] = 1;
            number[1][4] = 1;
            number[2][0] = 1;
            number[2][4] = 1;
            number[3][0] = 1;
            number[3][4] = 1;
            number[4][1] = 1;
            number[4][2] = 1;
            number[4][3] = 1;
            number[4][4] = 1;
            number[5][4] = 1;
            number[6][3] = 1;
            number[7][1] = 1;
            number[7][2] = 1;
            break;

    }
    return number;
}

void print(std::vector<std::vector<std::vector<bool>>>& numbers){
    for(auto number: numbers){
        for(auto line: number){
            for(auto pixel: line){
                std::cout << (pixel ? "O": " ");
            }
            std::cout << "\n";
        }
        std::cout << "--------\n";
    }
}

std::vector<std::vector<std::vector<bool>>>&  numbersToMatrix(std::vector<std::vector<std::vector<bool>>>& numbers, unsigned int x){
    for(int i = 0; i < 5; i++){
        int y = x % 10;
        x = x/10;
        numbers[i] = numberToMatrix(numbers[i], y);
    }

    return numbers;
}
 static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::vector<std::vector<bool>> createDisplay(std::vector<std::vector<std::vector<bool>>> numbers, int indicatorPos){
	std::vector<std::vector<bool>> data;	

	for(int i = 0; i < 8; i++){
		std::vector<bool> row;
		for(int j = 4; j >= 0; j--){
			for( int k = 0; k < 6; k++){
				row.push_back(numbers[j][i][k]);
			}
		}	
		row.push_back(0);
		row.push_back(0);
		data.push_back(row);
	}
	data[indicatorPos][31] = true;

	return data;
}

uint16_t generateMessage(int row, bool* pixels){
    uint16_t v = 0;

    for (int i = 0; i<8 ; i++){
        if(pixels[i]){
            v |= 1 << i;
        }
    }
    v |= (row + 1) << 8;
    return v;
}

void sendClock(){
   digitalWrite(PIN_CLK, LOW);
   usleep(CLK_DELAY_US);
   digitalWrite(PIN_CLK, HIGH);
   usleep(CLK_DELAY_US);
}

void sendMessages(std::vector<uint16_t>& messages){
    digitalWrite(PIN_CS, LOW);

    for(auto message: messages){
        for(int i = 15; i >= 0; i--){
            digitalWrite(PIN_DIN, ((message >> i) & 1) ? HIGH : LOW);
            sendClock();
        }
    }

    digitalWrite(PIN_CS, HIGH);
}

void writeDisplay(std::vector<std::vector<bool>> data){
	for(int i = 0; i < 8; i++){
		std::vector<uint16_t> messages;
		std::vector<bool> row = data[i];
		for(int j = 3; j >= 0; j--){
			bool shortRow[8];
			for(int k = 0; k < 8; k++){
				shortRow[k] = data[i][k+8*j];
			}
			messages.push_back(generateMessage(7-i, shortRow));	
		}
		sendMessages(messages);
	}
}

void gpioSetup(){
    wiringPiSetupGpio();
    pinMode(PIN_CS, OUTPUT);
    pinMode(PIN_DIN, OUTPUT);
    pinMode(PIN_CLK, OUTPUT);
    int rows[] = {12, 16, 20, 21};
    int columns[] = {6, 13, 19, 26};
    for(auto pin: rows){
        pinMode(pin, OUTPUT);
    }
    for(auto pin: columns){
        pinMode(pin, INPUT);
    }
}

void sendAll(uint16_t message){
	std::vector<uint16_t> messages = {message, message, message, message};
	sendMessages(messages);
}

void clearAll(){
	bool zeros[] =  {0,0,0,0,0,0,0,0};
	for(int i = 0; i< 8; i++){
		sendAll(generateMessage(i,zeros));
	}
}
void tryUpdate(int indicator){
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    char url[] = "http://bitter.li:2000/pages";
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    readBuffer.replace(readBuffer.find("{"),readBuffer.find(":")+1,"");

    int x = std::stoi(readBuffer);

    assert(x <= 99999);

    std::vector<std::vector<std::vector<bool>>> numbers(5,std::vector<std::vector<bool>>(8, std::vector<bool>(6)));

    writeDisplay(createDisplay(numbersToMatrix(numbers, x), indicator));
}

std::vector<bool> scanAll(){
    int rows[] = {12, 16, 20, 21};
    int columns[] = {6, 13, 19, 26};

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
                std::cout << "reading brightness\n";
                sendAll(0x0a00 + number);
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
int main(){
	gpioSetup();
	sendAll(0x0b07); //enable all rows
	sendAll(0x0a03); //set brightness low-ish
	clearAll();
	sendAll(0x0c01); //turn on

	/*std::vector<std::vector<bool>> data;
	for(int i = 0; i < 8; i++){
		std::vector<bool> row;
		for(int j = 0; j < 32; j++){
			row.push_back((i+j+1) % 2);
		}
		data.push_back(row);
	}
	writeDisplay(data);*/

	bool dir = true;
	int indicator = 0;
	int brightness = 3;
	while(true){
		try{
			tryUpdate(indicator);
                        std::vector<bool> keysPressed = scanAll();
                        selectMode(keysPressed);
			if(dir){
				if(indicator < 7)
					indicator++;
				else{
					indicator--;
					dir = false;
				}

			} else{
				if(indicator > 0)
					indicator--;
				else {
					indicator++;
					dir = true;
				}
			}
		} catch(...){

		}
	}
}
