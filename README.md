# About this Fork
The aim of this fork is to provide a more portable version of dvo-slam which does not require other softwares such as ROS.

c++17 recommended, for [alignment of Eigen structs](https://eigen.tuxfamily.org/dox/group__TopicUnalignedArrayAssert.html)

Uses the following packages:

- Eigen3
- PCL (this fork was tested on v1.11)
- OpenCV
- VTK

# Building
## Notes on PCL
Possible due to building from source, I have to manually set some definitions for the PCL package in the CMakeLists.txt for dvo_core (line 39) and dvo_slam (line 26). Please check/adjust for your own installation before attempting to build.

## 1. dvo_core
1. cd /path/to/dvo\_slam/dvo\_core/build
2. cmake -DCMAKE\_BUILD\_TYPE=Release ..
3. make

## 2. g2o
If you already have a g2o installation on your computer, please skip this. Otherwise:

1. cd /path/to/dvo\_slam/g2o/build
2. cmake -DCMAKE\_BUILD\_TYPE=Release ..
3. make

## 3. dvo_slam
If building with your pre-existing g2o installation, please replace lines 49-51 and 78-82 of the CMakeLists.txt with your own configuration.

1. cd /path/to/dvo\_slam/dvo\_slam/build
2. cmake -DCMAKE\_BUILD\_TYPE=Release ..
3. make

# Usage

## Include directories

- /path/to/dvo\_slam/dvo\_core/include
- /path/to/dvo\_slam/dvo\_slam/include

If using the provided g2o:

- /path/to/dvo\_slam/g2o/include
- /path/to/dvo\_slam/g2o/build

## Libraries
Please be mindful of the order: both g2o and dvo\_core must be linked before g2o\_slam.

- /path/to/dvo\_slam/dvo\_slam/build/libdvo\_slam.a
- /path/to/dvo\_slam/dvo\_core/build/libdvo\_core.a
- tbb, pthread

If using the provided g2o:

- /path/to/dvo\_slam/g2o/lib/*.so

Otherwise (from the original dvo\_slam/dvo\_slam/CMakeLists.txt):

- #${G2O\_CORE\_LIBRARY}
- #${G2O\_SOLVER\_DENSE}
- #${G2O\_SOLVER\_EIGEN}
- #${G2O\_TYPES\_SLAM3D}

