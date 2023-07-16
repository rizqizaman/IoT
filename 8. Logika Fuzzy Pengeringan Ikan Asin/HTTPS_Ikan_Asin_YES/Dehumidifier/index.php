<?php

	include("connection.php"); 	
	$result=mysqli_query($koneksi,"SELECT * FROM `panas_dingin` ORDER BY `Date_Time` DESC");
	$result2=mysqli_query($koneksi,"SELECT * FROM `panas_dingin` ORDER BY `Date_Time` DESC LIMIT 1");

?>
<html>
	<head>
		<title>Monitoring Suhu & Kelembaban Ikan Asin</title>
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
				<center><h5 style="text-align:right;" class="miring">Data Logging Suhu & Kelembaban</h5></center>
				<hr style="margin-top: 0px; margin-bottom:0px">
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
		</div>
		<br>
		<?php 
			if($result2!==FALSE){
				$ndata=mysqli_num_rows($result);
			    while($lastrow = mysqli_fetch_array($result2)) {
			    	$temp1=$lastrow["Suhu_Panas"];
			    	$lembab1=$lastrow["Kelembaban_Panas"];
			    	$temp2=$lastrow["Suhu_Dingin"];
			    	$lembab2=$lastrow["Kelembaban_Dingin"];
			    	$update_date=$lastrow["Date_Time"];
			    }
			}
				// mysql_free_result($result2);
			// mysql_close();
		?>
		
		<div class="row">
			<div class="col-md-2 col-md-offset-2">
				<div class="panel panel-primary">
  					<div class="panel-heading">
    					<h3 class="panel-title tengah">Navigasi</h3>
  					</div>
  					<div class="panel-body" style="padding:0px;">
    					<table class="table table-stripped table-hover" >
							<tbody>
								<tr class="info">
									<td><span class="glyphicon glyphicon-home"></span><a href="./index.php" style="text-decoration:none;"> Home</a></td>
								</tr>
								<tr>
									<td><span class="glyphicon glyphicon-th-list"></span><a href="./tables.php" style="text-decoration:none;"> Tabel</a></td>
								</tr>
								<tr>
									<td><span class="glyphicon glyphicon-stats"></span><a href="./stats.php" style="text-decoration:none;"> Statistik</td>
								</tr>
							</tbody>
						</table>
  					</div>
				</div>
			</div>
			<div class="col-md-3">
				<table class="table table-bordered">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Suhu (&degC) Room-1</p></center></td>
					</thead>
					<tr class="success">
						
						<td><center><p class="tebel gede" style="margin-top:5px"><?php echo "$temp1";?></p></center></td>
					</tr>
				</table>
			</div>
			<div class="col-md-3">
				<table class="table table-bordered">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Kelembaban (%) Room-1</p></center></td>
					</thead>
					<tr class="info">
						<td><center><p class="tebel gede" style="margin-top:5px"><?php echo "$lembab1";?></p></center></td>
					</tr>
				</table>
			</div>
			<div class="col-md-3">
				<table class="table table-bordered">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Suhu (&degC) Room-2</p></center></td>
					</thead>
					<tr class="success">
						
						<td><center><p class="tebel gede" style="margin-top:5px"><?php echo "$temp2";?></p></center></td>
					</tr>
				</table>
			</div>
			<div class="col-md-3">
				<table class="table table-bordered">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Kelembaban (%) Room-2</p></center></td>
					</thead>
					<tr class="info">
						<td><center><p class="tebel gede" style="margin-top:5px"><?php echo "$lembab2";?></p></center></td>
					</tr>
				</table>
			</div>
			
			
		</div>
		<div class="row">
			<div class="col-md-6 col-md-offset-4">
				<p class="tebel">Ringkasan Data Room-1:</p>
					<table class="table table-striped table-hover">
						<tr>
							<td>Last Update</td>
							<td>:</td>
							<td><?php echo date('Y-M-d H:i:s',strtotime($update_date))?></td>
						</tr>
						<tr>
							<td>Interval Update</td>
							<td>:</td>
							<td>3 menit</td>
						</tr>
						<tr>
							<td>Jumlah Data</td>
							<td>:</td>
							<td><?php echo $ndata?></td>
						</tr>
					</table>
			</div>
			
		</div>
		
		<!-- <div class="row"> -->
			<div class="col-md-6 col-md-offset-4">
				<p class="tebel">Ringkasan Data Room-2:</p>
					<table class="table table-striped table-hover">
						<tr>
							<td>Last Update</td>
							<td>:</td>
							<td><?php echo date('Y-M-d H:i:s',strtotime($update_date))?></td>
						</tr>
						<tr>
							<td>Interval Update</td>
							<td>:</td>
							<td>3 menit</td>
						</tr>
						<tr>
							<td>Jumlah Data</td>
							<td>:</td>
							<td><?php echo $ndata?></td>
						</tr>
					</table>
			</div>
		
    <!-- </div> -->
	</body>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script type="text/javascript" src="./js/modules/data.js"></script>
	<script type="text/javascript" src="./js/modules/exporting.js"></script>
	<script type="text/javascript" src="./js/highcharts.js"></script>
	<script type="text/javascript" src="./js/bootstrap.js"></script>
	
</html>
