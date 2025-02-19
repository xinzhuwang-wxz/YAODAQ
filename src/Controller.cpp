#include "Controller.hpp"

#include "StatusCode.hpp"
#include "magic_enum.hpp"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/ostream_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "toml.hpp"

Controller::Controller(const std::string& name, const std::string& type) : Module(name,type,yaodaq::CLASS::Controller)
{
  skipConfigFile();
}

void Controller::sendAction(const std::string& action)
{
  auto ac = magic_enum::enum_cast<Actions>(action);
  if(ac.has_value())
  {
    Action a(ac.value());
    sendBinary(a);
  }
  else
    throw Exception(StatusCode::INVALID_PARAMETER, "{} is not a valid Action", action);
}

void Controller::sendCommand(const std::string& command)
{
  Command m_command(command);
  sendBinary(m_command);
}
