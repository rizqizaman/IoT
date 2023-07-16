<?php

	include("connection.php"); 	
	$result=mysqli_query($koneksi,"SELECT * FROM `panas_dingin` ORDER BY `Date_Time` DESC LIMIT 10");
?>
<html>
	<head>
		<title>Statistik Data Harian Rata-Rata</title>
		<link rel="stylesheet" href="./css/style.css">
		<link rel="stylesheet" href="./css/bootstrap.css">
	</head>
	<body>
		<div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h3 style="text-align:right;" class="hijau tebel">Logging Suhu & Kelembaban</h3></center>
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
		</div>
		<div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h5 style="text-align:right;" class="miring">Data Logging suhu & Kelembaban</h5></center>
				<hr style="margin-top: 0px; margin-bottom:0px">
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
		</div>
		<br>
		<div class="row">
			<div class="col-md-2 col-md-offset-2">
				<div class="panel panel-primary">
  					<div class="panel-heading">
    					<h3 class="panel-title tengah">Navigasi</h3>
  					</div>
  					<div class="panel-body" style="padding:0px;">
    					<table class="table table-stripped table-hover" >
							<tbody>
								<tr>
									<td><span class="glyphicon glyphicon-home"></span><a href="./index.php" style="text-decoration:none;"> Home</a></td>
								</tr>
								<tr class="info">
									<td><span class="glyphicon glyphicon-th-list" ></span><a href="./tables.php" style="text-decoration:none;"> Tabel</a></td>
								</tr>
								<tr>
									<td><span class="glyphicon glyphicon-stats"></span><a href="./stats.php" style="text-decoration:none;"> Statistik</td>
								</tr>
							</tbody>
						</table>
  					</div>
				</div>	
			</div>
			
			<th colspan="2"><p class="tebel">Tabel Data Suhu (&degC) & Kelembaban (%) Room-1 & Room-2:</p></th>
			<!-- <div class="col-md-2 col-md-offset-3"> -->
			<div class="col-md-5">
				
				<table class="table table-striped table-bordered align-left">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Tanggal</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Suhu (&degC) Room-1</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Kelembaban (%) Room-1</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Suhu (&degC) Room-2</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Kelembaban (%) Room-2</p></center></td>
					</thead>
					<tbody>
						<?php 
		  					if($result!==FALSE){
							    while($row = mysqli_fetch_array($result)) 
								{
									//extract $row;
							        printf("<tr><td> &nbsp;%s </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td>", 
						            $row["Date_Time"], $row["Suhu_Panas"], $row["Kelembaban_Panas"], $row["Suhu_Dingin"], $row["Kelembaban_Dingin"]);
								    $value = $row['Suhu_Panas'];
								    $value1= $row['Kelembaban_Panas'];
									$value2= $row['Suhu_Dingin'];
								    $value3= $row['Kelembaban_Dingin'];
									$timestamp = strtotime($row['Date_Time'])*60000;
								   	$data1[] = "[$timestamp, $value]";
								   	$data2[] = "[$timestamp, $value1]";
								   	$data3[] = "[$timestamp, $value2]";
								   	$data4[] = "[$timestamp, $value3]";
							    }
								// json_encode($data);
							    mysqli_free_result($result);
							    // mysqli_close();
							}
      					?>
					</tbody>
					
				
			</div>
			</div>
	</body>
</html>

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script type="text/javascript" src="./js/modules/data.js"></script>
	<script type="text/javascript" src="./js/modules/exporting.js"></script>
	<script type="text/javascript" src="./js/highcharts.js"></script>
	<script type="text/javascript" src="./js/bootstrap.js"></script>