#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/sixlowpan-module.h"
#include "ns3/netanim-module.h"
#include "ns3/internet-apps-module.h"
#include "ns3/mobility-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstExperiment");

int main(int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  // Simulation time constants
  const Time startTime = Seconds(1.0);
  const Time stopTime = Seconds(10.0);

  // Set up simulation environment
  Time::SetResolution(Time::NS);
  LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

  // Create nodes
  NodeContainer nodes;
  nodes.Create(10);

  // Set up CSMA channel
  CsmaHelper csma;
  csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
  csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));
  NetDeviceContainer devices = csma.Install(nodes);

  // Set up 6LoWPAN
  SixLowPanHelper sixlowpan;
  NetDeviceContainer slpdevices = sixlowpan.Install(devices);

  // Install Internet stack on nodes
  InternetStackHelper stack;
  stack.Install(nodes);

  // Assign IPv6 addresses to devices
  Ipv6AddressHelper address;
  address.SetBase(Ipv6Address("2001:db8::"), Ipv6Prefix(64));
  Ipv6InterfaceContainer interfaces = address.Assign(devices);

  // Set up IPv6 ping applications
  Ping6Helper ping;
  ping.SetRemote(interfaces.GetAddress(9, 1));
  ApplicationContainer apps = ping.Install(nodes.Get(0));
  apps.Start(startTime);
  apps.Stop(stopTime);

  // Set up node mobility
  for (uint32_t i = 0; i < nodes.GetN(); ++i)
  {
    Ptr<ConstantPositionMobilityModel> mob = CreateObject<ConstantPositionMobilityModel>();
    mob->SetPosition(Vector(i * 100, 0, 0));
    nodes.Get(i)->AggregateObject(mob);
  }

  // Enable ASCII tracing and NetAnim animation
  AsciiTraceHelper asciiTraceHelper;
  csma.EnableAsciiAll(asciiTraceHelper.CreateFileStream("experiment-1.tr"));
  AnimationInterface anim("experiment-1.xml");

  // Run the simulation
  Simulator::Run();
  Simulator::Destroy();
  return 0;
}
