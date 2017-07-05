
 <?php
$servername = "localhost";
$username = "adam";
$password = "polonez1";
$dbname = "employee101";

$conn = mysql_connect($servername, $username, $password);
$con_result = mysql_select_db($dbname, $conn);
?>








