<?php
header("Last-Modified:".gmdate("D, d M Y H:i:s")." GMT");
?>

<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=windows-1250">
	<meta name="Author" content="Juraj Videky">
	<link rel="stylesheet" type="text/css" href="../breviar.css">
	<title>Seznam soubor� v adres��i</title>
</head>
<body>

<h2>Seznam soubor� v adres��i <tt>include_cz</tt></h2>

<?
/**
 * Change the path to your folder.
 *
 * This must be the full path from the root of your
 * web space. If you're not sure what it is, ask your host.
 *
 * Name this file index.php and place in the directory.
 *
 * Source: http://www.totallyphp.co.uk/scripts/directory_lister.htm
 */

// Define the full path to your folder from root
$path = "/data/www/www.breviar.sk/include_cz/";

// Open the folder
$dir_handle = @opendir($path) or die("Nedok�u otev��t adres�� $path");

//this is a function I wrote to sort out the contents of the directory date wise for display.
$content_array = array();

//Load Directory Into Array
$i=0;
while ($file = readdir($dir_handle))
if ($file != "." && $file != ".." && $file != "index.php")
{
	$content_array[$i][0] = $file;
	$content_array[$i][1] = date ("Y-m-d H:i:s", filemtime($path."/".$file));
	$i++;
}
//close the directory handle
closedir($dir_handle);

//these lines sort the contents of the directory by the date
foreach($content_array as $res)
	$sortAux[] = $res[1];
array_multisort($sortAux, SORT_DESC, $content_array); 

//print
echo "\n<table>";
echo "\n<tr><th>Soubor</th><th>Posledn� modifikace</th></tr>";
foreach($content_array as $res)
	echo "\n<tr><td><a href=\"".$res[0]."\">$res[0]</a></td><td>".$res[1]."</td></tr>";
	// $res[0].">".$res[1];

echo "\n</table>";

?>

<br>
<hr>
<center><font size=-1>� 1999-2007 <a href="mailto:videky@breviar.sk">Juraj Vid�ky</a></font></center>

</body>
</html>
