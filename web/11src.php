<?php
	$con = mysql_connect("localhost", "root", "root123") or die("Could not connect!");
	$name = $_REQUEST["name"];
	$qry = "select * from user where name = '$name'";
	$result = mysql_db_query("weblab", $qry);

	while ($row = mysql_fetch_row($result)) {
		print " | ";
		foreach($row as $col)
	 		print $col . " | ";
	}

	mysql_close($con);
?>
