#ifndef __TCPCONNECTION_HPP__
#define __TCPCONNECTION_HPP__

#include <iostream>
#include <vector>

class TCPconnection 
{
private: 
  std::vector<std::string> Mechanism = { "Slow Start", "Congestion Avoidence", "Fast Recovery", "Fast Retransmit"};

public:
  TCPconnection();
  //std::vector<std::string> get_mechanisms();
  void run();
}

#endif
