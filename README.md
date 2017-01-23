Unified Image Processing Framework
==================================

This program provides a framework for Image Processing allowing you to split your processing chain into
independent, reuseable modules which can also be run stand alone as well as in complex processing chains.
It comes with a Graphical Processing Chain Editor and also a console interface for running the processing
chains and modules.

Installation
------------

We currently do not have precompiled binaries so you have to build it on your own.
See the ["How to build"-section](#how-to-build) on how to do this.

Usage
-----

The Documentation can be found in the [/doc](https://github.com/TU-Berlin-CVRS/uipf/tree/master/doc#documentation)
directory. Check the README.md file there for an overview.

We also have a demo video on vimeo.com: https://vimeo.com/133464857

How to build
------------

### Dependencies

The following dependencies are needed to build:

- yaml-cpp (https://github.com/jbeder/yaml-cpp), will be built by cmake
  - [Boost serialisation](http://www.boost.org/doc/libs/release/libs/serialization/), needs to be available on the system
- [Boost program-options](http://www.boost.org/doc/libs/release/libs/program_options/)
- [Boost graph](http://www.boost.org/doc/libs/release/libs/graph/)
- [Boost filesystem](http://www.boost.org/doc/libs/release/libs/filesystem/)
- [OpenCV](http://opencv.org/), version 2.3 or higher (currently untested with the 3.x branch)
- [Qt 5](http://doc.qt.io/qt-5/index.html), at least 5.3
- libglibmm-2.4

On Debian/Ubuntu you can install the above packages by running the following command:

	sudo apt-get install libboost-serialization-dev libboost-program-options-dev libboost-filesystem-dev libboost-graph-dev libopencv-dev qtbase5-dev qtbase5-dev-tools libglibmm-2.4-dev

The following additional packages may be needed for building C++ code:

    sudo apt-get install build-essential cmake pkg-config

If you want to work on the GUI, you may also want to install Qt Creator:
To install Qt5, you can download '.run' offline or online installer from qt open source community download (https://www.qt.io/download-open-source/#section-2)
(where 'qt-opensource-linux-x64-5.4.2.run' is the downloaded file, use the below command via terminal)

    chmod +x qt-opensource-linux-x64-5.4.2.run
    ./qt-opensource-linux-x64-5.4.2.run

### Building with CMake on Linux

Run the following commands after cloning the repository in the repostiory base directory:

```
mkdir -p code/build
cd code/build
cmake ..
make
sudo make install
```

For a custom installation prefix you may specify it in the `DESTDIR` for the make command, like so:
`make DESTDIR=/tmp/uipf install`, which will install all uipf files under the directory `/tmp/uipf`.

If something goes wrong you may run `make VERBOSE=1` for more detailed output.

For a fast build you can run `make -j 4` where 4 is the number of parallel executions to use. Be careful though, as
this may take a lot of RAM and make the system unstable.

#### Troubleshooting

##### error while loading shared libraries

When running the uipf binary after compiling you may see the following error:
    
    $ uipf
    uipf: error while loading shared libraries: libuipf-module.so.2.0: cannot open shared object file: No such file or directory

Solution: run `sudo ldconfig` to make the linker aware of the newly installed library.

### Building with CMake on Windows

TBD.


How to contribute
-----------------

Please read the [CONTRIBUTING.md](CONTRIBUTING.md) for details.

License
-------

This work is licensed under the BSD 2-clause License.
Check the [LICENSE](LICENSE) file for the license terms.
