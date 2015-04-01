SMBCast
===================

Description
-----------
This small repository is for an in house shakemap broadcaster. It will read from the shakemap XML and create a table and broadcast over email and SMS. The SMS will only contain the names and peak acceleration of the three most accelerated stations(Hopefully).

----------


Usage
-------------
This program has a GUI interface as well as a commandline interface. In order to use the command line interface (for automation purposes) first be sure that all emails are accounted for in the Email.cfg file that is automatically generated. This can be configured easily in the GUI under the email settings tab. The program can be launched as so:

    ./SMBCast -n -f <Shakemap XML File>

 - -n or --no-gui: supresses GUI creation
 - -f FileName or --smFile FileName: Substitute FileName for the name of your file
 - --help: help info
 - --version: version info

If no flags are input the GUI Version will show up. Here you can configure SMS & EMail. You can also manually open files and send them using the send button.

TO DO:
------

 - Highlight Strongest Accelerations. 
 - Implement SMS.

Acknowledgement:
----------------

 - The PRSMP for their help and support
 - USGS for their development of the shakemap standards.
 - The QT Development Team for their awesome QT Library.
