# NotesForGraphics


[主办方主页](http://games-cn.org/)
[课程主页](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html)
[PPT](http://games-cn.org/graphics-intro-ppt-video/)


## Prepare for task env

```
brew install eigen

brew install opencv@2

brew tap brewsci/science

brew install pkg-config

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/

ln -s /usr/local/Cellar/opencv@2/2.4.13.7_7/lib/pkgconfig/opencv.pc $PKG_CONFIG_PATH
```

After everything have done , when you run this command  `pkg-config --cflags --libs opencv`  will see this:
```
-I/usr/local/Cellar/opencv@2/2.4.13.7_7/include/opencv -I/usr/local/Cellar/opencv@2/2.4.13.7_7/include -L/usr/local/Cellar/opencv@2/2.4.13.7_7/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
```

I'm using Xcode as my C++ IDE, create a command line Project for Task1.

Add this to your project.

Add following to `Header Search Paths` (Eigen requires the first dependency.)
```
/usr/local/include
/usr/local/Cellar/opencv@2/2.4.13.7_7/include
```

PS 直接双击 Header Search Paths 后面的空白区域填写， 会有一个弹窗然后点+号开始写    不用单独写下面的 Debug 和 release

And make it no-recursive. (Though medium blog says this should set recursive, I found if set recursive would cause fatal error when building)

Then add this to `library search path`.
```
/usr/local/Cellar/opencv@2/2.4.13.7_7/lib
```

Add `pkg-config --cflags --libs opencv` output to `Other Linker Flags`
```
-I/usr/local/Cellar/opencv@2/2.4.13.7_7/include/opencv -I/usr/local/Cellar/opencv@2/2.4.13.7_7/include -L/usr/local/Cellar/opencv@2/2.4.13.7_7/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

```

## TroubleShotting

### install opecv2
https://www.learnopencv.com/install-opencv3-on-macos/

https://medium.com/beesightsoft/macos-mojave-10-14-3-setup-environment-for-opencv4-0-1-c-develop-fcae955d6b33


### install eigen for mac
https://stackoverflow.com/questions/35658420/installing-eigen-on-mac-os-x-for-xcode

### Undefined symbols for architecture x86_64: error
https://stackoverflow.com/questions/24985713/opencv-undefined-symbols-for-architecture-x86-64-error


### xcode No member named 'FILE' in the global namespace
https://stackoverflow.com/questions/30638320/xcode-cstdlib-no-member-named-xxx-in-the-global-namespace
