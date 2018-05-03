#pragma once

#include "Types.hpp"
#include "ConsoleColors.hpp"

namespace io
{
	enum class MessageType : u8
	{
		alert  = RED,
		normal = MAGENTA,

		warning = YELLOW,
		success = GREEN,

		important = WHITE,
	};

	class Console
	{
	public:
		Console() = delete;

		static void trace(const string& message, const string& file, const string& function, i32 line, MessageType type);
		static void print(const string& message, MessageType type);

		static void pause();

	private:
		static void set_message_type(MessageType type);

		static mutex sm_mutex;
		static MessageType sm_type;

		#ifdef WINDOWS_PLATFORM

		static HANDLE sm_handle;

		#endif
	};
}
