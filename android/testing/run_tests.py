import sys;
import os;
import time;
from com.android.monkeyrunner import MonkeyRunner, MonkeyDevice;

def orangutan_click(x, y):
  os.system("adb shell \"echo 'tap 186 408 1 200' | /data/orng /dev/input/event0\"");

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

print "Starting activity"
device.startActivity(component=runComponent)

time.sleep(5);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/changelog.png','png')

# try to find OK in changelog. We do not need orangutan here.
for i in [1200, 1100, 1000, 900, 800, 700]:
  device.touch(360, i, MonkeyDevice.DOWN_AND_UP)

time.sleep(2);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/start.png','png')

# Vespery
# Webview ignores monkey events, so we must use orangutan.
orangutan_click(186, 408)

time.sleep(5);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/vespery.png','png')

# Presses the Menu button
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)

orangutan_click(128, 1122)

time.sleep(3);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/menu.png','png')

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
</table>

<h2>Screenshots</h2>

<p> Changelog: <img valign=center height=600 src="changelog.png">
<p> Main screen: <img valign=center height=600 src="start.png">
<p> Menu: <img valign=center height=600 src="menu.png">
<p> Vespers: <img valign=center height=600 src="vespery.png">
</body>
</html>""" % (date_str, date_str, commit_id, version,
              time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()) ));
out.close();
