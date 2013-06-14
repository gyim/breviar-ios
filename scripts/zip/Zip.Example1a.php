<?php
// Example. Zip all .html files in the current directory and send the file for Download.
$fileDir = './';

include_once("Zip.php");
$fileTime = date("D, d M Y H:i:s T");

$zip = new Zip();
$zip->setComment("Example Zip file.\nCreated on " . date('l jS \of F Y h:i:s A'));
$zip->addFile("Hello World!", "hello.txt");

if ($handle = opendir($fileDir)) {
	/* This is the correct way to loop over the directory. */
	while (false !== ($file = readdir($handle))) {
		if (strpos($file, ".html") !== false) {
			$pathData = pathinfo($fileDir . $file);
			$fileName = $pathData['filename'];

			$zip->addFile(file_get_contents($fileDir . $file), $file, filectime($fileDir . $file));
		}
	}
}

$zip->sendZip("ZipExample1a.zip");
?>