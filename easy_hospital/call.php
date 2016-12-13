<?php
require "conn.php";
$now = new DateTime();
$dataNow = $now->format("Y-m-d");
$timeNow = $now->format("H:i:s");
$patientID = $_GET['pi'];
$status= $_GET['st'];
$mysql_qry = "INSERT INTO EasyHospital_db.Calls (Calls.ID_Patient,Calls.Date,Calls.Time,Calls.Status,Calls.idnurses') values ('$patientID','$dataNow','$timeNow','$status','0');";
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
