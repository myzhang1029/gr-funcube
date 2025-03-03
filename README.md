gr-funcube is an linux oot-module for gnuradio to implement a funcube dongle and a funcube dongle pro+ source.  
On linux it autodetects the correct soundcard from /proc/asound/cards.  
This idea was taken from the osmosdr drivers.

To control the device the hidapi usb version is used.

1. **Dependencies:**  
&nbsp;  
 gnuradio (>= 3.10 ) with pybind  
 libhidapi
 libusb  

2. **Installation:**    
&nbsp;  
 The build process is cmake based.  
 So get the latest code from https://github.com/dl1ksv/gr-funcube  
 and change to the code directory. There  
 &nbsp;  
 mkdir build  
 cd build  
 cmake -DCMAKE_INSTALL_PREFIX= "path to gnuradio installation" ../  
 make  
 su  
 make install  
 &nbsp;        
 After that executing grc  you'll find in the section Funcube  
 &nbsp;  
 Funcube Dongle  
 Funcube Dongle control  
 Funcube Dongle Pro+  
 Funcube Dongle Pro+ control

     **Hint:**  
     You can install gr-funcube to an other directory than "path to gnuradio installation". But then you have to add
     the location of your python modules to the PYTHONPATH environment variable and add the location of
     the lib to the LD_LIBRARY_PATH environment variable.

     To see the newly created blocks in grc you have to set the local_blocks_path entry in ~/.gnuradio/config.conf.
     Example: If you choose /usr/local/oot as installation directory, you have to set 
     local_blocks_path = /usr/local/oot/share/gnuradio/grc/blocks
     
3.   **Important:**  
    &nbsp;  
Don't forget the udev rules:  
For instance:  
&nbsp;  
    ## Udev rules for the Funcube Dongle Pro (0xfb56) and Pro+ (0xfb31)   
    ## HIDAPI/libusb:  
SUBSYSTEMS=="usb" ATTRS{idVendor}=="04d8" ATTRS{idProduct}=="fb56" MODE:="0666"    
SUBSYSTEMS=="usb" ATTRS{idVendor}=="04d8" ATTRS{idProduct}=="fb31" MODE:="0666"  
    ## HIDAPI/hidraw:  
KERNEL=="hidraw*", ATTRS{busnum}=="1", ATTRS{idVendor}=="04d8", ATTRS{idProduct}=="fb56", MODE="0666"  
KERNEL=="hidraw*", ATTRS{busnum}=="1", ATTRS{idVendor}=="04d8", ATTRS{idProduct}=="fb31", MODE="0666"  

4. **Installation example for Ubuntu**  
&nbsp;  
 cd \$HOME  
sudo apt install libusb-1.0-0-dev libudev-dev libhidapi-dev  
gnuradio-config-info --prefix  
git clone https://github.com/dl1ksv/gr-funcube.git  
cd \$HOME/gr-funcube  
mkdir build  
cd build  
cmake -DCMAKE_INSTALL_PREFIX=\<prefix from gnuradio-config-info\> ../  
make  
sudo make install  
sudo ldconfig  
cd /etc/udev/rules.d  
sudo cp \$HOME/gr-funcube/50-funcube.rules ./  
sudo udevadm control --reload-rules  
sudo udevadm trigger  
&nbsp;  
&nbsp;  
 The names of the packages that are required for build may differ between Linux distros.

5.    **Usage**  
&nbsp;  
 Four modules are available:  
&nbsp;  
    fcd_control  
    fcd  
    fcdpp_control  
    funcube  
&nbsp;  
 The control modules only controls the dongles, while the other modules control the dongles and provide the IQ samples.
All modules accept messages to control the frequency. That was the reason to introduce the control modules.
&nbsp;  
    The fcd modules where introduced, as gnuradio 3.8 does not contain gr-fcd any longer.  
See the examples of a simple fm receiver in the examples directory or see a more complex example in in gr-display


6.    **Credits**  
    &nbsp;  
Some code is taken from qthid-4.1 by Alexandru Csete, OZ9AEC.  
Thanks to Michael Dickens, who gave valuable hints for implementing message in hier2_blocks.  
Thanks to Barry Duggan for the installation example for Ubuntu  
