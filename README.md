# Autonomous Camera


Simple Arduino Nano controller that supplies power to Respberry Pi Camera.
Every 10 minutes the controller turns on the camera to allow it to take
a picture then it waits for response from the Raspberry and turns it off.
It detects light to only take pictures during the day and monitors charging
of the battery.


todo:
- store picture count in the flash so it doesn't reset at power down (DONE)
- switch to ISP programming (DONE)
- remove USB chip (DONE)
- request stream (when Pi starts, before taking the pic it asks the server if stream is requested
  if it is, start the stream and halt until told otherwise)
- embed extra data in the image (location, camera, time, temperature, humidity etc.)
- add weather station to the camera
- add RTC to arduino so it knows what time it is
- add precise reference voltage generator
- count errors: if PI reported ready to die before 45 seconds, no picture has been taken (no internet?)
