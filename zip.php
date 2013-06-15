<?php
include_once 'scripts/functions.php';
include_once 'scripts/zip/Zip.php'; // @link https://github.com/Grandt/PHPZip

if(!isset($_REQUEST['r']) OR !is_numeric($_REQUEST['r'])) $year = date('Y'); else $year = $_REQUEST['r']; 
if(!isset($_REQUEST['m']) OR $_REQUEST['m'] > 12 OR $_REQUEST['m'] < 1 )  $month = date('m'); else $month = $_REQUEST['m']; 
if(!isset($_REQUEST['j']) OR !in_array($_REQUEST['j'],array('sk','cz','hu'))) $lang = 'sk'; else $lang = $_REQUEST['j'];
//if(!isset($_REQUEST['type']) OR !in_array($_REQUEST['type'],array('txt','html'))) $type = 'html'; else $type = $_REQUEST['type'];
$type = 'html';

$zippath = './ebook/';
$filename = t('breviary')."_".$year."-".$month;
if($type != 'html') $filename .= '_'.$type;

/* If the file exists we don't need to generate it 
 *
 * You can force the script to generate the file
 * sending @force = true by POST or GET
 */
$filexists = $zippath.$filename.'.zip';
if(file_exists($filexists) AND $_REQUEST['force'] != true ) {		
	getdownload($filename.'.zip',$zippath);
	exit;
} /**/

$pages = array();
/* go through the month day by day */
$dayscount = cal_days_in_month(CAL_GREGORIAN, $month, $year);	
for($day = 1; $day <= $dayscount; $day ++) {

	/* GET celebrations data */
	$options = array(); // TODO: set the possible options!
	$celebrations = getCelebrationsXML($year."-".$month."-".sprintf('%02d', $day),$lang,$options);
	
	/* DOWNLOAD files */
	foreach($celebrations->CalendarDay->Celebration as $celebration) {
		$attributes = $celebration->attributes();
	
		$GET = array(
			'qt' => 'pdt',
			'd' => $day,'m' => $month,'r' => $year,'j' => $lang,'p' => '*',
			'ds' => $attributes['Id']);
		$POST = $options; // TODO: set the possible options!
		
		$pages[] = array(
			'content' => getBreviarFile($GET,$POST,'UTF-8'),
			'name' => t('breviary')."_".$year.$month.sprintf('%02d', $day)."_".$attributes['Id']		
			);
		
	}
}

/* ZIP the pages */
$zip = new Zip();
$zip->setComment(t('The whole prayers of the breviary for a month.'));

foreach($pages as $page) {
	$page = preg_replace("/\/breviar.css/i",'breviar.css',$page);
	$page = preg_replace("/charset=windows-1250\"/i",'charset=utf-8"',$page);
	
	
	$zip->addFile($page['content'], $page['name'].".html");
}
$cssData = file_get_contents('http://breviar.sk/breviar.css');
$zip->addFile($cssData,"breviar.css");

$zip->finalize(); // as we are not using getZipData or getZipFile, we need to call finalize ourselves.
/* save it */
$zip->setZipFile($zippath.$filename.".zip");
/* send it */
$zip->sendZip($filename.".zip");

	
?>