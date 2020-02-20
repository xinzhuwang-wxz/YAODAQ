#include "CLI/CLI.hpp"
#include "Board.hpp"

int main(int argc, char** argv)
{  
  CLI::App app{"Dump"};
  int port{80};
  app.add_option("-p,--port",port, "Port to listen")->check(CLI::Range(0,65535));
  std::string host{"127.0.0.1"};
  app.add_option("-i,--ip",host, "IP of the server")->check(CLI::ValidIPV4);
  std::string loggerName="Board1";
  app.add_option("-n,--name",loggerName, "Name of the mode")->check([](const std::string & t){if(t=="") return "Name is empty"; else return "" ;},"Not Empty","Test is name is empty");
  try 
  {
    app.parse(argc, argv);
  } 
  catch (const CLI::ParseError &e) 
  {
    spdlog::error("{}",e.what());
    return e.get_exit_code();
  }
  
  WebsocketClient::setURL("ws://"+host+":"+std::to_string(port)+"/");
  
  Board::setConfigFile("../confs/Configs.toml");
  
  Module toto(loggerName);
  while(1)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  return 0;
}
