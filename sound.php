<?php
$log_file = 'sound_log.txt';		// log file name
$data = $_POST['data'];

$str = $data."\n";	// two fields in one record, the timestamp and postdata

if(file_exists($log_file)){
	$fp = fopen($log_file,"a");
	fwrite($fp, $str);
	fclose($fp);
}else {
	$fp = fopen($log_file, "w");
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored\n";	// echo sth back to the raspberry pi

?>
