todo:
- store picture count in the flash so it doesn't reset at power down
- switch to ISP programming
- remove USB chip
- request stream (when Pi starts, before taking the pic it asks the server if stream is requested
  if it is, start the stream and halt until told otherwise)
- embed extra data in the image (location, camera, time, temperature, humidity etc.)
- add weather station to the camera
- add RTC to arduino so it knows what time it is
- add precise reference voltage generator
- count errors: if PI reported ready to die before 45 seconds, no picture has been taken (no internet?)
