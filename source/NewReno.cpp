#include "../include/NewReno.hpp"
#include <chrono>
#include <random>
#include <cmath>

NewReno::NewReno(int cwnd_, int ssthresh_)
{
  cwnd = cwnd_;
  ssthresh = ssthresh_;
  mechanism = Slow_Start;
  LastByteAcked = 0;
  timeout = 0;
  rtt = 0;
}

void NewReno::set_timeout()
{
  timeout = 2;
}

void NewReno::change_mech(int newMech)
{
  mechanism = newMech;
  std::cout << "Mechanism is " << Mechanism[mechanism] << " now!\n";
}

void NewReno::Mult_cwnd(int num)
{
  cwnd = cwnd * num;
}

void NewReno::div_cwnd_by(int num)
{
  cwnd = cwnd / 2;
}

void NewReno::decrement_size(int num)
{
  data_size -= num;
}

void NewReno::increment_cwnd(int num)
{
  cwnd += num;
}

bool NewReno::lossProbability()
{
  double x = static_cast<double>((std::pow(10 * 1000, static_cast<double>(cwnd - 1) / (999)) - 1) / 9999);
  int p = static_cast<int>(1000 * x);
  return (rand() % 1000) < p;
}

void NewReno::SendData()
{
  if (timeout != 0)
    return;

  int AckTemp = LastByteAcked;
  for (int i = AckTemp; i < DATA_SIZE && i < AckTemp + cwnd + sack_counter; i++)
  {
    bool lossProb = lossProbability();
    if(acked[i])
    {
      if(counter == 0)
      {
        LastByteAcked += 1;
        data_size -= 1;
      }
      sack_counter += 1;
    }
    else if(lossProb)
    {
      counter += 1;
      acked[i] = 0;
    }
    else if(counter == 0)
    {
      LastByteAcked += 1;
      data_size -= 1;
      acked[i] = 1;
    }
    else
    {
      AckLostPacket += 1;
      acked[i] = 1;
      if (AckLostPacket == 3)
        break;
    }
  }
}

int NewReno::onPacketLoss()
{
  if(timeout == 0)
  {
    if(AckLostPacket >= 3)
    {
      div_cwnd_by(2);
      ssthresh = cwnd > 1 ? cwnd : 1;
      change_mech(Fast_Recovery);
      return 1;
    }
    if(counter != 0)
    {
      div_cwnd_by(2);
      ssthresh = cwnd > 1 ? cwnd : 1;
      cwnd = 1;
      change_mech(Slow_Start);
      set_timeout();
      return 1;
    }
    return 0;
  }
  timeout -= 1;
  return 1;
}

void NewReno::onRTTUpdate()
{
  if(mechanism == Slow_Start)
  {
    if (cwnd == ssthresh)
      change_mech(AIMD);
    if (cwnd < ssthresh)
      Mult_cwnd(2);
    else if(cwnd > ssthresh)
      cwnd = ssthresh;
  }
  else if(mechanism == Fast_Recovery)
  {
    change_mech(AIMD);
    increment_cwnd(1);
  }
  else if(mechanism == AIMD)
  {
    increment_cwnd(1);
  }
}

void NewReno::run()
{
  while(data_size > 0)
  {
    counter = 0;
    sack_counter = 0;
    AckLostPacket = 0;
    SendData();
    rtt++;
    if(onPacketLoss() == 0)
      onRTTUpdate();

    std::cout << "NewReno: cwnd = " << cwnd << ", ssthresh = " << ssthresh << ", rtt = " << rtt << std::endl;
  }
}
