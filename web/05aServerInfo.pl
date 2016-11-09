#!/usr/bin/perl

print "content-type: text/html \n\n";
print "<html><head><title>Server Information</title></head>";
print "<body bgcolor='green'><h1><u>Server Information displayed below</u></h1>";
print "<table border=1><tr>";
print "<td>Environment Variable</td>";
print "<td>Value</td></tr>";
foreach $item(sort keys %ENV) {
  print "<td>$item</td>";
  print "<td>$ENV{$item}</td></tr>";
}
print "</body></html>";