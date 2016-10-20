<?php
DEFINE ('DB_USER', 'javastastic');
DEFINE ('DB_PASSWORD', 'AFGuns4Life');
DEFINE ('DB_HOST', '160.153.162.153');
DEFINE ('DB_NAME', 'MahidulsDatabase');
$dbc = @mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME)
OR die('Could not connect to MySQL' . mysqli_connect_error());
?>
