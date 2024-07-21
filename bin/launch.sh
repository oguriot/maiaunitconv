#! /bin/bash

#Get the libraries path, which is the current dir/lib
#current dir/parent/lib
lib_opencv_dir=`pwd`/../lib/opencv2.4.6
lib_qt_dir=`pwd`/../lib/qt5.2.0

#Got it, add it to the system lib path
#Then show it
#echo $LD_LIBRARY_PATH:$lib_dir

#And set it
LD_LIBRARY_PATH=$lib_opencv_dir:$lib_qt_dir:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

#Also, add the current dir to the binary path
PATH=$current_dir:$PATH
export PATH

exec MaiaUnitConv &
