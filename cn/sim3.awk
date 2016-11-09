#!/usr/bin/awk -f


BEGIN {
  drop = 0;
}
{
  if( ($1 == "d") && ($5 == "ping") ) {
    drop = drop + 1;
  }
}
END {
  printf "No. of dropped pings : %d\n", drop;
}
