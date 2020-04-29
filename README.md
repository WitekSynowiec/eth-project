# eth-project
for ethworks recruit task

<b>author:</b> Witek Synowiec

about: Project adds two strings that contains mathematic expressions. 

build and testing:
Project contains google test files stored in lib folder. 
In order to start testing it may be necessary to add Run/Debug Configurations and set them to Google Test. In program argument field it’s recommended to type „—gtest_repeat=3”. The alternative option, is to set Run/Debug Configurations to CMakeApplication.

In order to add new tests it is suggested to look into test.cpp file in which there are instructions.

/*/*/*
IMPORTANT! files are written on UNIX system that means it may be necessary for windows users to change slash to backslash in all files. It’s often possible in many IDEs to ctrl+shift+r/ctrl+shift+f to replace all occurances.  
/*/*/*