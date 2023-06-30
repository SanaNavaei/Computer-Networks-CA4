#include "../include/BBR.hpp"

BBR::BBR(int cwnd_)
{
    mechanism = Startup;
    timeout = 0;
    rtt = 0;
    cwnd = cwnd_;
    drainage = 0.3;
    probabilityCount = 30;
}

void BBR::change_mech(int newMech)
{
  mechanism = newMech;
  std::cout << "Mechanism is " << Mechanism[mechanism] << " now!\n";
}

void BBR::Mult_cwnd(int num)
{
  cwnd = cwnd * num;
}

bool BBR::lossProbability()
{
  double x = static_cast<double>((std::pow(10 * 1000, static_cast<double>(cwnd - 1) / (999)) - 1) / 9999);
  int p = static_cast<int>(1000 * x);
  return rand() % 1000 < p;
}

void BBR::SendData()
{
    if (timeout != 0)
      return;
    
    int AckTemp = LastByteAcked;
    for (int i = AckTemp; i < DATA_SIZE && i < AckTemp + cwnd; i++)
    {
      bool lossProb = lossProbability();
      if(lossProb)
        counter = 1;
      else if(counter == 0)
      {
        LastByteAcked += 1;
        data_size -= 1;
        acked[i] = 1;
      }
      else
        break;
    }
}

void BBR::onRTTUpdate()
{
  if (mechanism == Startup)
    Mult_cwnd(2);
  else if(mechanism == drain)
  {
    Mult_cwnd(1 - drainage);
    drainage = drainage - 0.02;
  }
  else if(mechanism == probeBW)
    cwnd += 0.25 * cwnd;
  else if(mechanism == probeRTT)
    cwnd = 30;
}

int BBR::onPacketLoss()
{
  if(counter == 1 && mechanism == Startup)
    change_mech(drain);
  if (mechanism == drain)
    change_mech(probeBW);

  return 0;
}

void BBR::run()
{
  while(data_size > 0)
  {
    counter = 0;
    SendData();
    rtt++;
    if(onPacketLoss() == 0)
    {
        probabilityCount -= 1;
        if(probabilityCount == 30)
        {
            change_mech(probeBW);
            cwnd = initialCwnd;
        }
        if (probabilityCount == 0)
        {
            probabilityCount = 35;
            change_mech(probeRTT);
            initialCwnd = cwnd;
        }
        onRTTUpdate();
    }

    std::cout << "BBR: cwnd = " << cwnd << ", rtt = " << rtt << std::endl;
  }
}
