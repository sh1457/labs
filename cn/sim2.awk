#!usr/bin/awk -f


BEGIN{
  tcpsend = 0;
  tcpdrop = 0;
  cbrsend = 0;
  cbrdrop = 0;
  tcpDropRatio = 0.0;
  cbrDropRatio = 0.0;
  tcpArriveRatio = 0.0;
  cbrArriveRatio = 0.0;
}
{
  src = $3;
  des = $4;
  type = $5;
  event = $1;
  if( (src=="0") && (des=="2") && (event=="+") )
     tcpsend = tcpsend + 1;
  if( (src=="1") && (des=="2") && (event=="+") )
     cbrsend = cbrsend + 1;
  if(event=="d" && type=="tcp")
     tcpdrop = tcpdrop + 1;
   if(event=="d" && type=="cbr")
     cbrdrop = cbrdrop + 1;
}
END{
 printf "Total # of TCP packets sent=%d\n", tcpsend;
 printf "Total # of CBR packets sent=%d\n", cbrsend;
 printf "Total # of TCP packets dropped=%d\n", tcpdrop;
 printf "Total # of CBR packets dropped=%d\n", cbrdrop;


 tcpArriveRatio = (tcpsend-tcpdrop)/tcpsend;
 printf "The TCP arrival ratio=%f\n", tcpArriveRatio;
 tcpDropRatio = tcpdrop/tcpsend;
 printf "The TCP drop ratio=%f\n", tcpDropRatio;


 cbrArriveRatio = (cbrsend-cbrdrop)/cbrsend;
 printf "The CBR arrival ratio=%f\n", cbrArriveRatio;
 cbrDropRatio = cbrdrop/cbrsend;
 printf "The CBR drop ratio=%f\n", cbrDropRatio;
}
