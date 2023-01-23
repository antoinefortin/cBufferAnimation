#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

class OutputBuffer
{
public:
	OutputBuffer();

	void DebugSelfBuffer();
	
	
	void SetBuffer(char* );
	void RenderBufferWithConstantDelay(int  msDelay);
	
	void SetTextFileAsBuffer(const std::string& filePath);
	void clearBuffer();

private:
	char* charBuffer;

};

