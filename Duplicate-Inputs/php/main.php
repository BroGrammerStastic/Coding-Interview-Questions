<?php
require_once('mysqli_connect.php');
mysqli_select_db(MahidulsDatabase,$dbc);
$myArray = $_POST['getVal'];
$myArray = json_decode($myArray);


global $dbc;
$result = mysqli_query($dbc, "SELECT * FROM inputValues") OR die("failed: " . mysql_error());
$insert  = "INSERT INTO inputValues(";
$val  = " VALUES(";
$Id = implode(', ', array_map(function($c) {
  return  ucfirst($c->ID);
}, $myArray));
$VAL = implode(', ', array_map(function($c) {
  return $c->Value;
}, $myArray));
$insert .= $Id . ")";
$val .= $VAL . ");";
$insert .= $val;

if (mysqli_query($dbc, $insert)) {
    echo "New record created successfully";
} else {
    echo "Error: " . $insert . "\n" . mysqli_error($dbc);
}
?>
