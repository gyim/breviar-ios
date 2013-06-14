<?php
/*
 * Functions for zip.php and ebook.php
 */

/*
 * Translations
 */
function t($text) {
	global $lang;

	$trans['sk'] = array(
		'breviary' => 'breviar',
		'Breviary' => 'Breviar',
		'http://breviary.com' => 'http://breviar.sk',		);
	$trans['cz'] = array(
		'Breviary' => 'Breviar',
		'http://breviary.com' => 'http://ebreviar.cz',		);
	$trans['hu'] = array(
		'Breviary' => 'Zsolozsma',
		'breviary' => 'zsolozsma',
		'The whole prayers of the breviary for a month.' => 'A zsolozsma szövege egy hónapon át.',
		'http://breviary.com' => 'http://zsolozsma.katolikus.hu',
		'Notices' => 'Megjegyzések',
		);
		
	if(isset($trans[$lang][$text])) return $trans[$lang][$text];
	else return $text;
}

/*
 * Get the datas about the celebrations of the day
 */
function getCelebrationsXML($date,$lang,$options = array()) {
	$year = date('Y',strtotime($date));
	$month = date('m',strtotime($date));
	$day = date('d',strtotime($date));

	$file = "http://breviar.sk/cgi-bin/l.cgi?qt=pxml&d=".$day."&m=".$month."&r=".$year."&j=".$lang;
	$fields_string = makegeturl($options);
	$context = stream_context_create(array("http"=>array(
  		"method" => "POST",
  		"header" => "Content-Type: application/x-www-form-urlencoded\r\n" .
  		"Content-Length: ". strlen($fields_string) . "\r\n",
  		"content" => $fields_string,
	))); 
	$xmlcontent = file_get_contents($file, false, $context); 
	
	$xml = simplexml_load_string($xmlcontent);
	return $xml;
}
 
function getBreviarFile($GET,$POST,$encoding = '') {
	if($encoding == '') $encoding = 'UTF-8//IGNORE';
 
	$file = "http://breviar.sk/cgi-bin/l.cgi?".makegeturl($GET);
	$fields_string = makegeturl($POST);
	$context = stream_context_create(array("http"=>array(
		"method" => "POST",
		"header" => "Content-Type: application/x-www-form-urlencoded\r\n" .
		"Content-Length: ". strlen($fields_string) . "\r\n",
		"content" => $fields_string,
	))); 
	
	$file = iconv('cp1250',$encoding, file_get_contents($file, false, $context));
	return $file;
 }
 
 /*
  * Force a file to download
  */
function getdownload($filename,$path = '') {
	if($path == '') $path = './ebook/';	
	header("Content-Disposition: attachment; filename=" . urlencode($filename));    
	header("Content-Type: application/force-download");
	header("Content-Type: application/download");
	$fp = fopen($path.$filename, "r"); 
	while (!feof($fp))
	{
		echo fread($fp, 65536); 
		flush(); // this is essential for large downloads
	}  
	fclose($fp); 
}

function makegeturl($array = array()) {
	$geturl = "";
    if(is_array($array)) foreach($array as $key=>$value) { $geturl .= $key.'='.$value.'&'; }
    rtrim($geturl,'&');	
	return $geturl;
}

?>