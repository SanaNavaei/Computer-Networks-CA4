#include "../include/Reno.hpp"

Reno::Reno(int cwnd_, int ssthresh_)
{
  cwnd = cwnd_;
  ssthresh = ssthresh_;
  mechanism = Slow_Start;
  LastByteAcked = 0;
  timeout = 0;
  rtt = 0;
}

void Reno::set_timeout()
{
  timeout = 2;
}

void Reno::change_mech(int newMech)
{
  mechanism = newMech;
  std::cout << "Mechanism is " << Mechanism[mechanism] << " now!\n";
}

void Reno::Mult_cwnd(int num)
{
  cwnd = cwnd * num;
}

void Reno::div_cwnd_by(int num)
{
  cwnd = cwnd / 2;
}

void Reno::decrement_size(int num)
{
  data_size -= num;
}

void Reno::increment_cwnd(int num)
{
  cwnd += num;
}

void Reno::SendData()
{
  if(mechanism == Mechanism[Fast_Retransmit])
  {
    should_sent_again = cwnd - 1;
    if(should_sent_again > 0)
      return;
    change_mech(Mechanism[Congestion_Avoidence]); 
    not_ACKed_yet -= 1;
  }
  else
  {
    decrement_size(1);
    if(mechanism == Mechansim[Slow_Start])
    {
      if(cwnd > ssthresh || cwnd == ssthresh)
      {
        change_mech(Mechanism[Congestion_Avoindence]);  
      }
      else
      {
        Mult_cwnd(2);
      }
    }
    else if(mechanism == Mechanism[Congestion_Avoidence])
    {
      increment_cwnd(1);
    }
    else if(mechanism == Mechanism[Fast_Reconvery])
    {
      div_cwnd_by(2);
      ssthresh = cwnd;
      change_mech(Mechansim[Fast_Retransmit]);
    }
  }
}

int Reno::onPacketLoss()
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

void Reno::run()
{
  while(data_size > 0)
  {
    counter = 0;
    AckLostPacket = 0;
    SendData();
    rtt++;
    if(onPacketLoss() == 0)
      onRTTUpdate();

    std::cout << "Reno: cwnd = " << cwnd << ", ssthresh = " << ssthresh << ", rtt = " << rtt << std::endl;
  }
}
