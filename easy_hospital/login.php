<?php
require "conn.php";

$user_name = $_POST[user_name];
$user_pass = $_POST[password];
$mysql_qry = "SELECT * FROM employee101.employee_data where username like '$user_name' and password like '$user_pass';";

$result = mysql_query($mysql_qry);
if(mysql_num_rows($result) > 0){
        echo "login success";
}else{
        echo "login not success";
        die('Could not connect to specific database: ' . mysql_error());
}
?>

