<?php
   	include("connection.php");
   	
   	//$link=Connection();
   date_default_timezone_set("Asia/Jakarta");
   $Suhu_Panas=$_GET["Suhu_Panas"];
   $Kelembaban_Panas=$_GET["Kelembaban_Panas"];
   $Suhu_Dingin=$_GET["Suhu_Dingin"];
   $Kelembaban_Dingin=$_GET["Kelembaban_Dingin"];
   
$sql = "INSERT INTO `panas_dingin` (`Suhu_Panas`, `Kelembaban_Panas`,
                     `Suhu_Dingin`, `Kelembaban_Dingin`) VALUES ('$Suhu_Panas','$Kelembaban_Panas','$Suhu_Dingin','$Kelembaban_Dingin')";
if($koneksi->query($sql)===TRUE){
   echo "OK";
}else{
   echo "error" .$koneksi->error;
}
$koneksi->close();
		
	
?>
