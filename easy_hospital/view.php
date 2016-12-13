<?php
require "conn.php";
$patientID = $_POST[patientID];
$mysql_qry = "SELECT hour, substances FROM EasyHospital_db.chemicals where ID_patient'$patientID';";

$result = mysql_query($mysql_qry);
$data_array = array();
while($data = mysql_fetch_assoc($result)){
        $data_array['chem_info'][] = $data;
}
mysql_close($conn);
echo json_encode($data_array);
?>


