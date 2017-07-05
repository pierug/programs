<?php
require "conn.php";
$name = "Ben";//$_POST[user_name];
$surname = "Smith";//$_POST[password];
$age = 33;//$_POST[user_name];
$username = "pierug";//$_POST[user_name];
$password = "123";//$_POST[password];
$mysql_qry = "INSERT INTO employee101.employee_data (name,surname,age,username,password) values ('$name','$surname','$age','$username','$password');";

if($conn->query($mysql_qry) === TRUE){
        echo "INSERT SUCCESS";
}else{
        echo "INSERT not success";
        die("error" . mysql_error());
}
$conn->close();
?>