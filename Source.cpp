#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

#include "OutputBuffer.h"

void renderCharArea(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = 'A' + (x + y) % 26;
            std::cout << c;
        }
        std::cout << "\r";
    }
}

void printWithDelay(std::string text, int delay)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}


void renderBuffer(char* buffer, int delay) {
    int i = 0;
    while (buffer[i]) {
        std::cout << buffer[i++] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void renderStringCharByChar(const std::string& str, int msDelayPerChar) {
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(msDelayPerChar));
        std::cout << "\r";
    }
}

char* readTextFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (file) {
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);
        char* buffer = new char[length];
        file.read(buffer, length);
        file.close();

        return buffer;
    }
    else {
        std::cout << "Failed to open file" << std::endl;
        return nullptr;
    }
}


int main() {
    
    char red[] = "\033[1;31m Dicks!\033[0m";
    char green[] = "\033[1;31m Over!\033[0m";
    char blue[] = "\033[1;31m Vaginas!\033[0m";

    /*
        C way
    */
    if (1)
    {
        printf("%s", red);
        printf("%s", green);
        printf("%s", blue);
    }
    
    /*
        C++ way
    */
    // Red
    std::cout << "\033[1;31m Dicks!\033[0m";
    // Green
    std::cout << "\033[1;32m Over!\033[0m" ;
    std::cout << "\033[1;34m Vaginas!\033[0m";
    // Blue
    


    OutputBuffer *testBuffer = new OutputBuffer();
    testBuffer->SetTextFileAsBuffer("C:/Users/arrom/OneDrive/Desktop/buffershit.vuvu");
    testBuffer->RenderBufferWithConstantDelay(15);

    return 0;
}
