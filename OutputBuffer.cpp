#include "OutputBuffer.h"

OutputBuffer::OutputBuffer()
{
}

void OutputBuffer::DebugSelfBuffer()
{
	std::cout << charBuffer;
}

void OutputBuffer::RenderBufferWithConstantDelay(int msDelay)
{
    int i = 0;
    while (charBuffer[i]) {
        std::cout << charBuffer[i++] << std::flush; 
        std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
    }
}


void OutputBuffer::SetTextFileAsBuffer(const std::string& filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (file)
    {
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);
        char* buffer = new char[length];
        file.read(buffer, length);
        file.close();

        charBuffer = buffer;
    
    }

    else {
        std::cout << "Failed to open file" << std::endl;
        // make it pointer based for testing yo
        //return nullptr;
    }
}


void OutputBuffer::SetBuffer(char* buffer)
{
    charBuffer = buffer;
}