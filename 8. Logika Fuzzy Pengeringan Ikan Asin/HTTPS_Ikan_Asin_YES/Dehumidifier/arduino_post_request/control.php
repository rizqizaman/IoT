<?php

	include("connection.php"); 	
	$result=mysqli_query($koneksi,"SELECT * FROM `data_kualitas` ORDER BY `date_time` DESC LIMIT 10");
?>
<html>
	<head>
		<title>Sistem Kendali Mesin Pencucian Simplisia</title>
		<link rel="stylesheet" href="./css/style.css">
		<link rel="stylesheet" href="./css/bootstrap.css">
	</head>
	<body>
		<div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h3 style="text-align:right;" class="hijau tebel">Logging Control Simplisia</h3></center>
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
		</div>
		<div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h5 style="text-align:right;" class="miring">Logging Control Simplisia</h5></center>
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
								<tr>
									<td><span class="glyphicon glyphicon-user"></span><a href="./control.php" style="text-decoration:none;"> Kontrol</td>
								</tr>
							</tbody>
						</table>
  					</div>
				</div>	
			</div>
			<div class="col-md-6">
				<p class="tebel">Tabel Data Suhu (&degC) & Tingkat Kekeruhan:</p>
				<table class="table table-striped table-bordered">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Tanggal</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Suhu (&degC)</p></center></td>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px;">Tingkat Kekeruhan</p></center></td>
					</thead>
					<tbody>
						<?php 
		  					if($result!==FALSE){
							    while($row = mysqli_fetch_array($result)) 
								{
									// extract $row;
							        printf("<tr><td> &nbsp;%s </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td></tr>", 
						            $row["date_time"], $row["ph1"], $row["ph2"], $row["suhu"], $row["status"]);
								    $value = $row['ph2'];
								    $value2= $row['ph2'];
								    $value3 = $row['suhu'];
									$value4= $row['status'];
									$timestamp = strtotime($row['date_time'])*1000;
								   	$data1[] = "[$timestamp, $value]";
								   	$data2[] = "[$timestamp, $value2]";
								   	$data3[] = "[$timestamp, $value3]";
								   	$data4[] = "[$timestamp, $value4]";
							    }
								// json_encode($data);
							    mysqli_free_result($result);
							    // mysqli_close();
							}
      					?>
					</tbody>
				</table>
			</div>
		</div>
	</body>
</html>

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script type="text/javascript" src="./js/modules/data.js"></script>
	<script type="text/javascript" src="./js/modules/exporting.js"></script>
	<script type="text/javascript" src="./js/highcharts.js"></script>
	<script type="text/javascript" src="./js/bootstrap.js"></script>