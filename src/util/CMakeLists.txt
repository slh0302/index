set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_COMPILER g++)

set(
	LIB_SRC_LIST
	faster_rcnn.cpp
	)
set(
	LIB_INDEX
	index.cpp
	)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/../caffe-fast-rcnn/include
	${PROJECT_SOURCE_DIR}/../caffe-fast-rcnn/include/caffe
	${PROJECT_SOURCE_DIR}/..//lib/nms
	/usr/include
	/usr/local/include
	/usr/include/python2.7
	/usr/local/
	/opt/intel/mkl/include
	/usr/local/cuda/include
	)
add_library(faster_rcnn SHARED ${LIB_SRC_LIST})
add_library(index SHARED ${LIB_INDEX})
