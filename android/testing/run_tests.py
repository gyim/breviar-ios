import sys;
import os;
import time;
from com.android.monkeyrunner import MonkeyRunner, MonkeyDevice;

def orangutan_click(x, y):
  os.system("adb shell \"echo 'tap %d %d 1 200' | /data/orng /dev/input/event0\"" % (x, y));

def stable_snapshot(file):
  stableImage = False 
  while not stableImage: 
      result = device.takeSnapshot() 
      MonkeyRunner.sleep(5)
      result2 = device.takeSnapshot() 
      stableImage = result2.sameAs(result, 0.5) 
  result2.writeToFile(file,'png') 

if len(sys.argv) < 5:
  print "Usage: run_tests.py <dir> <date> <commit id> <version>"
  sys.exit(1)

root_dir = sys.argv[1]

device = MonkeyRunner.waitForConnection()
device.installPackage('bin/Breviar-release.apk')
package = 'sk.breviar.android'
activity = 'sk.breviar.android.Breviar'
runComponent = package + '/' + activity

device.wake()

#set fixed date
os.system("adb shell 'date 1362343193' >/dev/null 2>/dev/null")

print "Starting activity"
device.startActivity(component=runComponent)
time.sleep(3)

stable_snapshot(root_dir + '/changelog.png')

# try to find OK in changelog. We do not need orangutan here.
for i in [1200, 1100, 1000, 900, 800, 700]:
  device.touch(360, i, MonkeyDevice.DOWN_AND_UP)

stable_snapshot(root_dir + '/start.png')

# Vespery
# Webview ignores monkey events, so we must use orangutan.
orangutan_click(186, 408)

stable_snapshot(root_dir + '/vespers.png')

# Presses the Menu button
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)
time.sleep(1)
orangutan_click(128, 1122)

stable_snapshot(root_dir + '/menu.png')

# Turn on switches
orangutan_click(40, 500)
orangutan_click(40, 600)

# Test language switch (Hungarian)
orangutan_click(300, 300)

stable_snapshot(root_dir + '/start-hu.png')

# Switch to Czech
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)
time.sleep(1)
orangutan_click(128, 1122)
time.sleep(1)
orangutan_click(300, 200)

stable_snapshot(root_dir + '/start-cz.png')

orangutan_click(186, 408)

stable_snapshot(root_dir + '/vespers-cz.png')

# Test volume button scrolling
device.press('KEYCODE_VOLUME_DOWN', MonkeyDevice.DOWN_AND_UP)
time.sleep(1)
stable_snapshot(root_dir + '/vespers-cz-vol-scroll.png')

# Go back home
orangutan_click(300, 1150)
time.sleep(1)
stable_snapshot(root_dir + '/start-cz-2.png')

# Show settings
orangutan_click(268, 727)

# Day mode
device.press('KEYCODE_VOLUME_DOWN', MonkeyDevice.DOWN_AND_UP)
device.press('KEYCODE_VOLUME_DOWN', MonkeyDevice.DOWN_AND_UP)
orangutan_click(43, 262)
stable_snapshot(root_dir + '/start-cz-3.png')

orangutan_click(406, 540)
stable_snapshot(root_dir + '/start-cz-day.png')

device.removePackage('sk.breviar.android')

date_str = sys.argv[2]
commit_id = sys.argv[3]
version = sys.argv[4]

out = open(root_dir + '/index.html', 'w')
out.write("""
<html>
<head>
<title>Nightlies %s</title>
</head>
<body>
<h1>Nightlies %s - Test Results</h1>

<table>
<tr> <td>Commit id:</td><td>%s</td> </tr>
<tr> <td>Version:</td><td>%s</td> </tr>
<tr> <td>Ran on:</td><td>%s</td> </tr>
<tr> <td>Apk:</td><td><a href="../breviar.apk">breviar.apk</a></td> </tr>
</table>

<p>
Links: <a href="../..">all nightlies</a>, <a href="../../../releases">all releases</a>,
<a href="..">this nightly</a>

<h2>Screenshots</h2>

<p> Changelog: <img valign=center height=600 src="changelog.png">
<p> Main screen: <img valign=center height=600 src="start.png">
<p> Vespers: <img valign=center height=600 src="vespers.png">
<p> Menu: <img valign=center height=600 src="menu.png">
<p> Main screen, CZ: 
  <img valign=center height=600 src="start-cz.png">,
  <img valign=center height=600 src="start-cz-2.png">,
  <img valign=center height=600 src="start-cz-3.png">,
  <img valign=center height=600 src="start-cz-day.png">
<p> Vespers, CZ: <img valign=center height=600 src="vespers-cz.png">
<p> Vespers, CZ, scorll: <img valign=center height=600 src="vespers-cz-vol-scroll.png">
<p> Main screen, HU: <img valign=center height=600 src="start-hu.png">

<h2>Make release</h2>
<p>
<form action="release.php" method="post">
  <input type="submit" value="Release this nightly!">
</form>

</body>
</html>""" % (date_str, date_str, commit_id, version,
              time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()) ));
out.close();

out = open(root_dir + '/release.php', 'w')
out.write("""
<html>
<head>
<title>Releasing %s</title>
</head>
<body>
<?php
$dir = "%s/../../../releases/%s";
if (is_dir($dir)) {
  echo "This version already exists in releases!";
  die(0);
} else {
  exec("rm -rf $dir; mkdir -p $dir; cp -R %s/.. $dir; chmod -R go+rX $dir");
}
?>
Released, check 
<a href="../../../releases">here.</a>
</body>
</html>""" % (date_str, root_dir, version, root_dir));
out.close();

