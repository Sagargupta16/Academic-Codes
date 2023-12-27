#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv6-static-routing-helper.h"
#include "ns3/ipv6-routing-table-entry.h"
#include "ns3/sixlowpan-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Que2");

int main(int argc, char *argv[]) {
  CommandLine cmd;
  cmd.Parse(argc, argv);

  LogComponentEnable("Que2", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create(10); // Create 10 nodes

  CsmaHelper csma;
  csma.SetChannelAttribute("DataRate", StringValue("100kbps"));
  csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

  NetDeviceContainer csmaDevices = csma.Install(nodes);

  InternetStackHelper internet;
  internet.Install(nodes);

  Ipv6AddressHelper ipv6;
  ipv6.SetBase("2001:db8::", Ipv6Prefix(64));

  Ipv6InterfaceContainer interfaces;
  interfaces = ipv6.Assign(csmaDevices);

  // Enable 6LowPAN on all nodes
  SixLowPanHelper sixlowpan;
  NetDeviceContainer sixlowpanDevices = sixlowpan.Install(csmaDevices);

  // Install a UDP client and server
  UdpEchoServerHelper echoServer(9);
  ApplicationContainer serverApps = echoServer.Install(nodes.Get(9)); // Node 9 is the server
  serverApps.Start(Seconds(1.0));
  serverApps.Stop(Seconds(10.0));

  UdpEchoClientHelper echoClient(interfaces.GetAddress(9, 1), 9);
  echoClient.SetAttribute("MaxPackets", UintegerValue(1));
  echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
  echoClient.SetAttribute("PacketSize", UintegerValue(1024));

  ApplicationContainer clientApps = echoClient.Install(nodes.Get(0)); // Node 0 is the client
  clientApps.Start(Seconds(2.0));
  clientApps.Stop(Seconds(10.0));

  // Enable ASCII trace
  AsciiTraceHelper asciiTraceHelper;
  csma.EnableAsciiAll(asciiTraceHelper.CreateFileStream("Ass2.tr"));

  // Enable animation
  AnimationInterface anim("Ass2.xml");

  Simulator::Stop(Seconds(11.0));
  Simulator::Run();
  Simulator::Destroy();

  return 0;
}
