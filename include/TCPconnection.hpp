#ifndef __TCPCONNECTION_HPP__
#define __TCPCONNECTION_HPP__

#include <iostream>
#include <vector>
#include "../include/Reno.hpp"
#include "../include/NewReno.hpp"
#include "../include/BBR.hpp"

class TCPconnection 
{
private: 
  std::vector<std::string> Mechanism = { "Slow Start", "Congestion Avoidence", "Fast Recovery", "Fast Retransmit"};

public:
  TCPconnection();
  void run();
};

#endif
