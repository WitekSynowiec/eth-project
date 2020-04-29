# eth-project
for ethworks recruit task

<b>author:</b> Witek Synowiec

<b>about:</b> Project adds two strings that contains mathematic expressions. 

<b>build and testing:</b><br>
In order to start testing it may be necessary to add Run/Debug Configurations and set them to Google Test. In program argument field it’s recommended to type „—gtest_repeat=3”. The alternative option, is to set Run/Debug Configurations to CMakeApplication.

Project contains google test files that arestored in the lib folder. The source code for my application is stored in the com folder.

In order to add new tests it is suggested to look into test.cpp file in which there are instructions.

#########
<b>IMPORTANT!</b> files are written on UNIX system that means it may be necessary for windows users to change slash to backslash in all files. It’s often possible in many IDEs to ctrl+shift+r/ctrl+shift+f to replace all occurances.  
