<?php
require "conn.php";


$now = new DateTime();

$dataNow = $now->format("Y-m-d");
$timeNow = $now->format("H:i:s");

$patientID = $_GET['pi'];
$patient_temperature= $_GET['pt'];
$ambient_temperature= $_GET['at'];
$humidity= $_GET['h'];

$mysql_qry = "INSERT INTO EasyHospital_db.Temperatures (Temperatures.ID_Patient,Temperatures.Patient_temperature,Temperatures.Measure_time,Temperatures.Measureure','$humidity');";

echo $mysql_qry;
$result = mysql_query($mysql_qry);

if($result){
        echo "INSERT SUCCESS";
}else{
        echo "INSERT not success";
        die("error" . mysql_error());
}
$conn->close();
?>
