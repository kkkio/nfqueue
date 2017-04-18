// basic include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<limits.h>

// network include
#include <linux/netfilter.h>  // for NF_ACCEPT
#include <linux/types.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <libnetfilter_queue/libnetfilter_queue.h>

// local include
#include "nat_table.h"
#include "checksum.h"

struct iphdr *ip;
struct tcphdr *tcp;
nfqnl_msg_packet_hdr *ph;

uint32_t publicIP;
uint32_t lanIP;
uint32_t subnetMask;
unsigned int mask = 0xFFFFFFFF; //255
int packet_num = 0;

int TCPHandler(struct nfq_q_handle *qh,u_int32_t id,int payload_len,unsigned char *loadedData){
  unsigned long s_IP, d_IP; //s_Ip: source ip d_Ip: destination ip
  unsigned short s_Port, d_Port, transport; //s_port: source port d_port: dest port

  s_Ip=ntohl(ip->saddr);
  d_Ip=ntohl(ip->daddr);

  s_port=nto
}

int Callback(struct nfq_q_handle *qh, struct nfgenmsg *msg, struct nfq_data *pkt, void *data){
  ph = nfq_get_msg_packet_hdr(nfa);
  unsigned long id=ntohl(ph->packet_id);
  unsigned char *loadedData;
  unsigned int data_length=nfq_get_payload(nfa, &loadedData);
  ip=(struct iphdr*) loadedData;
  if(ip->protocol==IPPROTO_TCP){
    tcp = (struct tcphdr *)(loadedData + (ip->ihl<<2));
    TCPHandler(qh,id,payload_len, loadedData);
  }
  else{
    print("received unTCP packet");
    return nfq_set_verdict(qh, id, NF_DROP, 0, NULL);
  }

int main(int argc, char ** argv){
  struct nfq_q_handle *qh;
  struct nfnl_handle *nh;
  struct nfq_handle *h;
  int fd,rv;
  char buf[4096];
  struct in_addr* inp = (in_addr*)malloc(sizeof(in_addr));

  if(argc!=4){
    printf("Usage: ./nat <public ip> <internal ip> <subnet mask>\n");
    exit(0);
  }

  // pre-processing
  inet_aton(argv[1],inp);
  publicIP = ntohl(inp->s_addr); // publicIP
  inet_aton(argv[2],inp);
  lanIP = ntohl(inp->s_addr);    // lanIP
  mask

}
