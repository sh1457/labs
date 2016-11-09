#!/usr/bin/awk -f
BEGIN {
	cbrpkt = 0;
	tcppkt = 0;
}
{
	if(($1 == "d") && ($5 == "cbr"))
	{
		cbrpkt = cbrpkt + 1;
	}
	if(($1 == "d") && ($5 == "tcp"))
	{
		tcppkt = tcppkt + 1;
	}
}
END {
	printf ("No of CBR packets dropped %d\n",cbrpkt);
	printf ("No of TCP packets dropped %d\n",tcppkt);
}
