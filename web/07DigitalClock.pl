#!/usr/bin/perl

use CGI':standard';

print "Refresh:1 \n";
print "content-type: text/html \n\n";
print "<html><head><title>Digital Clock</title></head><body><h1><u>Digital Clock</u></h1>";
($s, $m, $h)=localtime(time());
print "<h2>$h : $m : $s</h2>";
print "</body></html>";