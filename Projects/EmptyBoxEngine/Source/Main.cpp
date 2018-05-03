#include "ConsoleMessages.hpp"

i32 main() 
{
	io::PRINT("Hello", io::MessageType::alert);
	io::PRINT("Hello", io::MessageType::warning);
	io::PRINT("Hello", io::MessageType::success);
	io::PRINT("Hello", io::MessageType::normal);
	io::PRINT("Hello", io::MessageType::important);

	io::TRACE("Hello", io::MessageType::alert);
	io::TRACE("Hello", io::MessageType::warning);
	io::TRACE("Hello", io::MessageType::success);
	io::TRACE("Hello", io::MessageType::normal);
	io::TRACE("Hello", io::MessageType::important);

	io::PAUSE();

	return 0;
}
