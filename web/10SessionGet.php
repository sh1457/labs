<?php
session_start();
?>
<!DOCTYPE html>
<html>
  <body>
<?php
echo "User is " . $_SESSION["name"] . ".<br>";
echo "Age is " . $_SESSION["age"] . ".";
?>
  </body>
</html>