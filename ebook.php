<?php
include_once 'scripts/functions.php';
include_once("scripts/epub/EPub.php"); // @link https://github.com/Grandt/PHPePub
include_once 'scripts/htmlpurifier/library/HTMLPurifier.auto.php'; // @link http://htmlpurifier.org/

if(!isset($_REQUEST['r']) OR !is_numeric($_REQUEST['r'])) $year = date('Y'); else $year = $_REQUEST['r']; 
if(!isset($_REQUEST['m']) OR $_REQUEST['m'] > 12 OR $_REQUEST['m'] < 1 )  $month = date('m'); else $month = $_REQUEST['m']; 
if(!isset($_REQUEST['j']) OR !in_array($_REQUEST['j'],array('sk','cz','hu'))) $lang = 'sk'; else $lang = $_REQUEST['j'];
if(!isset($_REQUEST['type']) OR !in_array($_REQUEST['type'],array('mobi','epub'))) $type = 'epub'; else $type = $_REQUEST['type'];

$filename = t('breviary')."_".$year."-".$month;
$ebookpath = './exported/';


/* If the file exists we don't need to generate it 
 *
 * You can force the script to generate the file
 * sending @force = true by POST or GET
 */
$filexists = $ebookpath.$filename.'.'.$type;
	if(file_exists($filexists) AND $_REQUEST['force'] != true) {		
		getdownload($filename.'.'.$type);
		exit;
	} elseif( $type == 'mobi' AND file_exists($ebookpath.$filename.'.epub') AND $_REQUEST['force'] != true) {
		exec('./kindlegen '.$ebookpath.$filename.'.epub -c2 -o '.$filename.'.mobi',$output,$return_var);
		getdownload($filename.'.mobi');	
	
	} /* */

	
$dayscount = cal_days_in_month(CAL_GREGORIAN, $month, $year);
	
$tmp = HTMLPurifier_Config::createDefault();
$purifier = new HTMLPurifier($tmp);
$tmp = false;
/*
 * The definitions for the Ebook
 */

$epub = new EPub();
htmlschema();
$title = t('Breviary').' '.$year.'/'.$month;
$copyright = t('Copyright: Juraj Vidéky, László Elek SJ');
$description = t('The whole prayers of the breviary for a month.');
$identifier = "http://breviar.sk/".$year."/".$month."/".$type;
// Title and Identifier are mandatory!
$epub->setTitle($title);
$epub->setIdentifier($identifier, EPub::IDENTIFIER_URI); // Could also be the ISBN number, prefered for published books, or a UUID.
$epub->setLanguage($lang); 
$epub->setDescription($description);
$epub->setAuthor(t('Breviary'),t('Breviary')); 
$epub->setPublisher('Breviary', 'http://breviary.com'); // I hope this is a non existant address :) 
$epub->setDate(time()); // Strictly not needed as the book date defaults to time().
$epub->setRights($copyright); 
$epub->setSourceURL("http://zsolozsma.katolikus.hu/ebook.php");


$cssData = file_get_contents('http://breviar.sk/breviar.css');
//echo $cssData; exit;
$epub->addCSSFile("styles.css", "css1", $cssData);
/*
 * The Cover / First page
 */
$cover = $content_start . "<h1>".t('Breviary')."</h1>\n<h2>".$year."/".$month."</h2>
	<br />*<br />
	<br />*<br />
	$description<br />
	$copyright<br />
	".date('Y.m.d')."\n" . $content_end;
$epub->addChapter(t("Notices"), "Cover.html", $cover);

$chapternum = 1;
for($day = 1; $day <= $dayscount; $day ++) {
	set_time_limit(60);
	//echo $year."-".$month."-".$day.";
	
	/*  Load the day's XML  */
	$xml = getCelebrationsXML($year."-".$month."-".sprintf('%02d', $day),$lang,$options);
	
	/* 
	 *  Load every celebration of the day 
	 */
	 foreach($xml->CalendarDay->Celebration as $celebration) {
		$attributes = $celebration->attributes();
		$attributes['Id'];
		
		$CelebrationTitle = strip_tags($celebration->StringTitle->asXML(),'<br/>');
		$CelebrationShortTitle = preg_replace('/^(.*?)(|(\<br\/\>.*?))$/i','$1',$CelebrationTitle);
		
		$GET = array(
			'qt' => 'pdt',
			'd' => $day,'m' => $month,'r' => $year,'j' => $lang,'p' => '*',
			'ds' => $attributes['Id']);
		$POST = $options; // TODO: set the possible options!		
		$prayerspage = getBreviarFile($GET,$POST,'UTF-8');
		
		/* Clear the html page */
		$prayerspage = preg_replace('/^.*?<body>(.*?)<\/body.*?$/si','$1',$prayerspage);
		
		//echo $prayerspage; 
		$prayers = preg_split('/<\!--\[skipping SPOL_CAST\]-->/i',$prayerspage);
		unset($prayers[0]);
		
		$prayerspage = $purifier->purify($prayerspage);
		
		$chaptercontent = $content_start . "<h1>".$CelebrationTitle."</h1>" . strip_tags($prayerspage,'<br/><br><p><center><b><span>').$content_end;
		$epub->addChapter($month."/".$day." ".$CelebrationShortTitle, "Chapter".sprintf('%04d', $chapternum).".html", $chaptercontent);		
		$chapternum++;
	}
	//if($day>5) break;
}
$epub->finalize(); // Finalize the book, and build the archive.

$epub->saveBook($filename, './ebook');

if($type == 'epub') {
	// Send the book to the client. ".epub" will be appended if missing.
	$zipData = $epub->sendBook($title);
} elseif($type == 'mobi') {
	exec('./kindlegen '.$ebookpath.$filename.'.epub -c2 -o '.$filename.'.mobi',$output,$return_var);
	//print_R($return_var);	echo "XXX"; 	print_R($output);
	getdownload($filename.'.mobi');
}	


function htmlschema() {
	global $content_start, $content_end;
	global $year,$month;
	
	$content_start =
		"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
		. "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"\n"
		. "    \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n"
		. "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
		. "<head>"
		. "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n"
		. "<link rel=\"stylesheet\" type=\"text/css\" href=\"styles.css\" />\n"
		. "<title>".t('Breviary')." - ".$year.'-'.$month."</title>\n"
		. "</head>\n"
		. "<body>\n";

	$content_end = "</body>\n</html>\n";
}


?>