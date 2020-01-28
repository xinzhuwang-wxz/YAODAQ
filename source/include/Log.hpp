#ifndef LOG_HPP
#define LOG_HPP
#include <string>
#include "Message.hpp"

class Log : public Message
{
public:
  Log(const std::string& content="",const std::string& to="",const std::string& from="");
};

#endif
