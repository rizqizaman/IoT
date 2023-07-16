<?php

	include("connection.php"); 	
	$result=mysqli_query($koneksi,"SELECT * FROM `panas_dingin` ORDER BY `Date_Time` DESC");
	// $result1=mysqli_query($koneksi,"SELECT * FROM `dingin` ORDER BY `Date` DESC");
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
				<center><h5 style="text-align:right;" class="miring">Data Logging Suhu & Kelembaban</h5></center>
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
								<tr>
									<td><span class="glyphicon glyphicon-th-list" ></span><a href="./tables.php" style="text-decoration:none;"> Tabel</a></td>
								</tr>
								<tr  class="info">
									<td><span class="glyphicon glyphicon-stats"></span><a href="./stats.php" style="text-decoration:none;"> Statistik</td>
								</tr>
							</tbody>
						</table>
  					</div>
				</div>	
			</div>
			<div class="col-md-6">
				<div id="container1">
						
				</div>
				<div id="container2">
						
				</div>
				<div id="container3">
						
				</div>
				<div id="container4">
					<br>
				</div>
				
						<?php 
		  					if($result!==FALSE){
							    while($row = mysqli_fetch_array($result)) {
									// extract $row;
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
				
			
			</div>
		</div>
	</body>
</html>

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script type="text/javascript" src="./js/modules/data.js"></script>
	<script type="text/javascript" src="./js/modules/exporting.js"></script>
	<script type="text/javascript" src="./js/highcharts.js"></script>
	<script type="text/javascript" src="./js/bootstrap.js"></script>
	<script>
		var chart = new Highcharts.Chart({
		      chart: {
		         renderTo: 'container1'
		      },
			  title: {
		            text: 'Grafik Data Suhu (Panas)'
		        },
				
			  xAxis: {
		    title: {
		        enabled: true,
		        text: 'Hours of the Day'
		    },
		    type: 'datetime',

		    dateTimeLabelFormats : {
		        hour: '%I %p',
		        minute: '%I:%M %p'
		    }
		},
		      series: [{
		         data: [<?php echo join($data1, ',') ?>]
		      }]
		});
		</script>
		<script>
			var chart1 = new Highcharts.Chart({
		      chart: {
		         renderTo: 'container2'
		      },
			  title: {
		            text: 'Grafik Data Kelembaban (Panas)'
		        },
				
			  xAxis: {
		    title: {
		        enabled: true,
		        text: 'Hours of the Day'
		    },
		    type: 'datetime',

		    dateTimeLabelFormats : {
		        hour: '%I %p',
		        minute: '%I:%M %p'
		    }
		},
		      series: [{
		         data: [<?php echo join($data2, ',') ?>]
		      }]
		});
		</script>
		<script>
		var chart = new Highcharts.Chart({
		      chart: {
		         renderTo: 'container3'
		      },
			  title: {
		            text: 'Grafik Data Suhu (Dingin)'
		        },
				
			  xAxis: {
		    title: {
		        enabled: true,
		        text: 'Hours of the Day'
		    },
		    type: 'datetime',

		    dateTimeLabelFormats : {
		        hour: '%I %p',
		        minute: '%I:%M %p'
		    }
		},
		      series: [{
		         data: [<?php echo join($data3, ',') ?>]
		      }]
		});
		</script>
		<script>
			var chart1 = new Highcharts.Chart({
		      chart: {
		         renderTo: 'container4'
		      },
			  title: {
		            text: 'Grafik Data Kelembaban (Dingin)'
		        },
				
			  xAxis: {
		    title: {
		        enabled: true,
		        text: 'Hours of the Day'
		    },
		    type: 'datetime',

		    dateTimeLabelFormats : {
		        hour: '%I %p',
		        minute: '%I:%M %p'
		    }
		},
		      series: [{
		         data: [<?php echo join($data4, ',') ?>]
		      }]
		});
		</script>