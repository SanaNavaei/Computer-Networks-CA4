#ifndef __BBR_HPP__
#define __BBR_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define Startup 0
#define drain 1
#define probeBW 2
#define probeRTT 3

#define DATA_SIZE 300000

class BBR
{
private:
  std::vector<std::string> Mechanism = { "Startup", "drain", "probeBW", "probeRTT"};
  int mechanism;
  int timeout;
  int cwnd;
  int LastByteAcked;
  int counter = 0;
  int rtt2 = 5;
  int data_size = DATA_SIZE;
  int acked[DATA_SIZE] = {0};
  int rtt;
  int drainage;
  int probabilityCount;
  int initialCwnd;

public:
  BBR(int cwnd_);
  void change_mech(int newMech);
  void Mult_cwnd(int num);
  void SendData();
  void onRTTUpdate();
  void run();

  int onPacketLoss();

  bool lossProbability();
};

#endif
