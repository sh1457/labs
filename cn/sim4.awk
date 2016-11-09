#!/usr/bin/awk -f


BEGIN {
	cbrPktReceived = 0;
	totalPktReceived = 0;
	ftpPktReceived = 0;
	Tput = 0.0;
}
{
	src = $3;
	des = $4;
	type = $5;
	event = $1;
	if( (event=="+") && (src=="2") && (des=="6") && (type=="cbr") )
		cbrPktReceived++;
	if( ($1=="+") && ($3=="2") && ($4=="6") && (type=="tcp") )
		ftpPktReceived++;
	totalPktReceived = cbrPktReceived + ftpPktReceived;
}
END {
	Tput = (( totalPktReceived * 500 * 8 ) / ( 8 * 1000000 ));
	printf "Throughput : %f\n", tput;
	printf "Total No. of cbrPktReceived : %d\n", cbrPktReceived;
	printf "Total No. of ftpPktReceived : %d\n", ftpPktReceived;
}
