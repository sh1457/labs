<?php
	$con = mysql_connect("localhost", "root", "root123") or die("Could not connect!");
	$nam = $_REQUEST["name"];
	$add1 = $_REQUEST["add1"];
	$add2 = $_REQUEST["add2"];
	$email = $_REQUEST["email"];
	print "Inserting '$nam', '$add1', '$add2', '$email' into table...";

	$res = mysql_db_query("weblab", "insert into user values('$nam', '$add1', '$add2', '$email')");
	print "STATUS='$res'";
	if ($res==1)
		print "Data inserted...";
	else
		print "Could not insert...";

	$res2 = mysql_db_query("weblab", "select * from user");

	while ($row = mysql_fetch_row($res2)) {
		print "<br /> | ";
		foreach($row as $col) {
			print $col . " | ";
		}
	}

	mysql_close($con);
?>
