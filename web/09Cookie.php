<?php
$cookie_name = "lastvisited";
$cookie_value = date("h:m:s a d/m/y");
$expiry = time() + (24 * 60 * 60 * 30);
setcookie($cookie_name, $cookie_value, $expiry);
?>
<html>
  <body>
<?php
if(!isset($_COOKIE[$cookie_name])) {
    echo "Cookie named '" . $cookie_name . "' is not set!";
} else {
    echo "Cookie '" . $cookie_name . "' is set!<br>";
    echo "Value is: " . $_COOKIE[$cookie_name];
}
?>
  </body>
</html>