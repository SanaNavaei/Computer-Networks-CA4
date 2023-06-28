#ifndef __TCPCONNECTION_HPP__
#define __TCPCONNECTION_HPP__

#include <iostream>

class TCPconnection 
{
private: 
  int cwnd;
  int ssthresh
  int rtt;
public:
  TCPconnection();
  void run();
}

#endif
