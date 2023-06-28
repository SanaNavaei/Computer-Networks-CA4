#ifndef __RENO_HPP__
#define __RENO_HPP__

#include <iostream>

#define Slow_Start 0
#define Congestion_Avoidence 1
#define Fast_Recovery 2
#define Fast_Retransmit 3

class Reno
{
private: 
  std::vector<std::string> Mechanism;
  std::string mechanism;
  int cwnd;
  int ssthresh;
  int data_size;
  int should_sent_again;
  int not_ACKed_yet;

public:
  Reno(Mechanism_/*attributes*/);
  void change_mech(std::string newMech);
  void Mult_cwnd(int num);
  void decrement_size(int num);
  void increment_cwnd(int num);
  void SendData();
}

#endif
