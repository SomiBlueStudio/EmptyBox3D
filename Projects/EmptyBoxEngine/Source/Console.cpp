#include "Console.hpp"

namespace io
{
	mutex Console::sm_mutex;
	MessageType Console::sm_type;

	#ifdef WINDOWS_PLATFORM

	HANDLE Console::sm_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	#endif

	void Console::trace(const string& message, const string& file, const string& function, const i32 line, const MessageType type)
	{
		const string str = file.substr(file.find_last_of('\\') + 1);

		print(message + " [" + str + "][" + function + "][" + std::to_string(line) + "]", type);
	}

	void Console::print(const string& message, MessageType type)
	{
		std::lock_guard<std::mutex> lock(sm_mutex);

		#ifdef WINDOWS_PLATFORM

		set_message_type(type);

		#endif

		std::cout << message << std::endl;
	}

	void Console::pause()
	{
		std::lock_guard<std::mutex> lock(sm_mutex);

		#ifdef WINDOWS_PLATFORM

		set_message_type(MessageType::normal);

		#endif

		std::cout << "press any key to continue...";

		std::cin.ignore();
	}

	void Console::set_message_type(MessageType type)
	{
		if (sm_type != type)
		{
			#ifdef WINDOWS_PLATFORM

			SetConsoleTextAttribute(sm_handle, static_cast<WORD>(type));

			#endif

			sm_type = type;
		}
	}
}
