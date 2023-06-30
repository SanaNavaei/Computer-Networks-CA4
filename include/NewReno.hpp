#ifndef __NEWRENO_HPP__
#define __NEWRENO_HPP__

#include <iostream>
#include <string>
#include <vector>

#define Slow_Start 0
#define AIMD 1
#define Fast_Recovery 2

#define DATA_SIZE 100000

class NewReno
{
private:
  std::vector<std::string> Mechanism = { "Slow Start", "AIMD", "Fast Recovery", "Fast Retransmit"};
  int LastByteAcked;
  int AckLostPacket;
  int counter, sack_counter;
  int mechanism;
  int cwnd;
  int ssthresh;
  int data_size = DATA_SIZE;
  int rtt;
  int timeout;
  int acked[DATA_SIZE] = {0};
public:
  NewReno(int cwnd_, int ssthresh_);
  void set_timeout();
  void change_mech(int newMech);
  void Mult_cwnd(int num);
  void div_cwnd_by(int num);
  void decrement_size(int num);
  void increment_cwnd(int num);
  void SendData();
  void onRTTUpdate();
  void run();

  int onPacketLoss();

  bool lossProbability();
};

#endif
