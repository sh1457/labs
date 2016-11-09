<?php
session_start();
?>
<!DOCTYPE html>
<html>
  <body>
<?php
$_SESSION["name"] = "Sujith";
$_SESSION["age"] = "22";
echo "Session variables are set.";
?>
  </body>
</html>