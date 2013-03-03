import sys;
import time;
from com.android.monkeyrunner import MonkeyRunner, MonkeyDevice;

if len(sys.argv) < 2:
  print "No output dir given!"
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

time.sleep(4);
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)
time.sleep(2);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/changelog.png','png')

# try to find OK in changelog
for i in [1200, 1100, 1000, 900, 800, 700]:
  device.touch(360, i, MonkeyDevice.DOWN)
  device.touch(360, i, MonkeyDevice.UP)

time.sleep(2);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/start.png','png')

# Vespery
device.touch(186, 408, MonkeyDevice.DOWN_AND_UP)

time.sleep(2);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/vespery.png','png')

# Presses the Menu button
device.press('KEYCODE_MENU', MonkeyDevice.DOWN_AND_UP)

device.touch(128, 1122, MonkeyDevice.DOWN)
device.touch(128, 1122, MonkeyDevice.UP)

time.sleep(2);
result = device.takeSnapshot()
result.writeToFile(root_dir + '/menu.png','png')

device.removePackage('sk.breviar.android')

out = open(root_dir + '/index.html', 'w')
out.write("""
<html>
<head></head>
<body>
<h1>Test log</h1>
<p> Changelog: <img src="changelog.png">
<p> Main screen: <img src="start.png">
<p> Menu: <img src="menu.png">
<p> Vespers: <img src="vespery.png">
</body>
</html>""");
out.close();
