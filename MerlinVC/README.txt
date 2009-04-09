To build the Merlin library just open the Merlin solution file (Merlin.sln) in
Visual C++ 2008 Express Edition (VC++ 9.0) and Build. Default is to build the Release version of the static library.

MerlinAll.sln is a solution to build the release and debug Merlin libraries and all examples. 
Open MerlinAll.sln and build the solution. The default is static linking and all examples are buildt in Release mode. 
The ROOT example is not built by default. For this example the ROOT libraries and include files are needed and the variable $(ROOTSYS) 
must be set according to your installation.

MerlinAll.sln builds some_example.exe files in MerlinExamples/"some_example_subdir" . They can be started within their directory.