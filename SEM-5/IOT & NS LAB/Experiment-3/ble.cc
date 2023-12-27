#include <fstream>
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/sixlowpan-module.h"
#include "ns3/lr-wpan-module.h"
#include "ns3/internet-apps-module.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"
#include "ns3/csma-module.h"
#include "ns3/ble-module.h" // adding ble module
#include "ns3/applications-module.h"
#include "ns3/ble-net-device.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("ping6BleExample");

int main (int argc, char **argv)
{
  bool verbose = false;
  CommandLine cmd;
  cmd.AddValue ("verbose", "turn on log components", verbose);
  cmd.Parse (argc, argv);
  Address server_address;

  if (verbose)
    {
      LogComponentEnable ("Ping6BleExample", LOG_LEVEL_INFO);
      LogComponentEnable ("Ipv6EndPointDemux", LOG_LEVEL_ALL);
      LogComponentEnable ("Ipv6L3Protocol", LOG_LEVEL_ALL);
      LogComponentEnable ("Ipv6StaticRouting", LOG_LEVEL_ALL);
      LogComponentEnable ("Ipv6ListRouting", LOG_LEVEL_ALL);
      LogComponentEnable ("Ipv6Interface", LOG_LEVEL_ALL);
      LogComponentEnable ("Icmpv6L4Protocol", LOG_LEVEL_ALL);
      LogComponentEnable ("Ping6Application", LOG_LEVEL_ALL);
      LogComponentEnable ("NdiscCache", LOG_LEVEL_ALL);
      LogComponentEnable ("SixLowPanNetDevice", LOG_LEVEL_ALL);
    }

  NS_LOG_INFO ("Create nodes.");
  NodeContainer nodes;
  nodes.Create (10);//changing number of nodes 10
  
  // Set seed for random numbers
  SeedManager::SetSeed (167);

  // Install mobility
  MobilityHelper mobility;
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");

  Ptr<ListPositionAllocator> nodesPositionAlloc = CreateObject<ListPositionAllocator> ();

  // now as there are no 2 nodes initially only 2 positions are allocated we now exapnd it to
  // 10 nodes
  for(float i=0.0;i<100.0;i+=10.0)
  	nodesPositionAlloc->Add(Vector(i,0,0));

  mobility.SetPositionAllocator (nodesPositionAlloc);
  mobility.Install (nodes);

  NS_LOG_INFO ("Create channels.");
  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", DataRateValue (1000000));
  csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (4)));
  csma.SetDeviceAttribute ("Mtu", UintegerValue (150));
  NetDeviceContainer devContainer = csma.Install (nodes);

  std::cout << "Created " << devContainer.GetN () << " devices" << std::endl;
  std::cout << "There are " << nodes.GetN () << " nodes" << std::endl;

  /* Install IPv4/IPv6 stack */
  NS_LOG_INFO ("Install Internet stack.");
  InternetStackHelper internetv6;
  internetv6.SetIpv4StackInstall (false);
  internetv6.Install (nodes);

  //Now we install the BLE layer
  NS_LOG_INFO("Installing BLE layer: ");
  CsmaHelper ble; NetDeviceContainer ble_temp = ble.Install(nodes);

  NS_LOG_INFO ("Assign addresses.");
  Ipv6AddressHelper ipv6;
  ipv6.SetBase (Ipv6Address ("2001:1::"), Ipv6Prefix (64));
  Ipv6InterfaceContainer i = ipv6.Assign (ble_temp);
  server_address = Address (i.GetAddress (0, 0));

  NS_LOG_INFO ("Create Applications.");
  // upd server
  uint16_t port = 9; // well-known echo port number
  UdpEchoServerHelper server (port);
  ApplicationContainer apps = server.Install (nodes.Get (0));
  apps.Start (Seconds (1.0));
  apps.Stop (Seconds (10.0));

  // udp client
  uint32_t packetSize = 1024;
  uint32_t maxPacketCount = 1;
  Time interPacketInterval = Seconds (1.);
  UdpEchoClientHelper client (server_address, port);
  client.SetAttribute ("MaxPackets", UintegerValue (maxPacketCount));
  client.SetAttribute ("Interval", TimeValue (interPacketInterval));
  client.SetAttribute ("PacketSize", UintegerValue (packetSize));
  apps = client.Install (nodes.Get (1));
  apps.Start (Seconds (2.0));
  apps.Stop (Seconds (10.0));

  //Adding the trace file
  AsciiTraceHelper ascii;
  csma.EnableAsciiAll(ascii.CreateFileStream("blue-udp.tr"));
  csma.EnablePcapAll(std::string("ble-ping6"),true);
  AnimationInterface anim("ble-animator.xml");
  // now we allocate the static positions to the nodes
  float j = 0.0;
  for(int i=0;i<5;i++)
  {
  	anim.SetConstantPosition(nodes.Get(i),j,10.0); // nodes i at y value 10.0
  	anim.SetConstantPosition(nodes.Get(5+i),j,50.0); // nodes 5+i at y value of 50.0 so that i and 5+i are in a line parallel to y-axis
  	j+=10.0;
  }

  NS_LOG_INFO ("Run Simulation.");
  Simulator::Run ();
  Simulator::Destroy ();
  NS_LOG_INFO ("Done.");
}
