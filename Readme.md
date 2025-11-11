# Elm Kernel Port to C


## To use the interactive Docker container (recommended)

This step will take some time to build the docker image, as it checks out the 
LLVM git and builds it. This is set up to support interactive development inside
the container, and will detect and run as your current user.

Follow the advice here on installing Docker, 
[install docker](https://docs.docker.com/engine/install/debian/) 
as well as setting up non-root users to be able to use it, 
[non-root users](https://docs.docker.com/engine/install/linux-postinstall/#manage-docker-as-a-non-root-user).

To confirm it is working correctly run these commands (`newgrp docker` only 
needs to be run if you are not logging out and back in again):

    newgrp docker
    docker run hello-world

To build the docker image:

    docker build -t mlir-dev:bookworm .

To run an interactive session as your user inside the docker container:

    docker run -it --rm -v "$PWD":/work mlir-dev:bookworm bash

Your build artifacts will be owned by you on the host, not root.

Set up the build with:

    cmake --preset ninja-clang-lld-linux

## To work directly on a Debian or other apt-based Linux host

Install the following packages:

    sudo apt install clang lld ninja-build cmake ccache

Next you need to checkout the LLVM project and build and install it on
your system:

    LLVM_VERSION=21.1.4
    git clone --branch "llvmorg-${LLVM_VERSION}" https://github.com/llvm/llvm-project.git

    cd llvm-project
    cmake -S llvm -B build -G Ninja \
    -DLLVM_ENABLE_PROJECTS="mlir" \
    -DLLVM_TARGETS_TO_BUILD="Native;NVPTX;AMDGPU" \
    -DLLVM_ENABLE_ASSERTIONS=ON \
    -DLLVM_ENABLE_RTTI=ON \
    -DMLIR_ENABLE_CMAKE_PACKAGE=ON \
    -DLLVM_ENABLE_ZLIB=OFF \
    -DLLVM_ENABLE_LIBXML2=OFF \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DLLVM_USE_LINKER=lld \
    -DCMAKE_INSTALL_PREFIX=/opt/llvm-mlir

    cmake --build build
    sudo cmake --install build

A CMake preset configuration to build with ninja, clang and lld exists in
`CMakePresets.json`. Set up the build in this project with:

    cmake --preset ninja-clang-lld-linux
