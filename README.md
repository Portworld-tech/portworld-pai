# portworld-pai

1. Code Download
git clone https://github.com/Portworld-tech/portworld-pai.git

2. Environment Configuration
   
sudo apt-get install repo git ssh make gcc libssl-dev liblz4-tool \
expect g++ patchelf chrpath gawk texinfo chrpath diffstat binfmt-support \
qemu-user-static live-build bison flex fakeroot cmake \
unzip device-tree-compiler python-pip ncurses-dev python-pyelftools

4. Debian Compilation

1) Kernel Compilation
   ./build.sh lunch
   rk356x-linux-5.10$ ./build.sh lunch
   Log colors: message notice warning error fatal

Parsing supported commands...

Log saved at /home/liu_lin3/ycx_work/github_sdk/rk356x-linux-5.10/output/sessions/2024-10-22_19-19-37

   Pick a defconfig:

   1. rockchip_defconfig
   2. rockchip_rk3566_evb2_lp4x_v10_32bit_defconfig
   3. rockchip_rk3566_evb2_lp4x_v10_defconfig
   4. rockchip_rk3568_evb1_ddr4_v10_32bit_defconfig
   5. rockchip_rk3568_evb1_ddr4_v10_defconfig
   6. rockchip_rk3568_evb8_lp4_v10_32bit_defconfig
   7. rockchip_rk3568_evb8_lp4_v10_defconfig
   8. rockchip_rk3568_pai_ddr4_v10_defconfig
   9. rockchip_rk3568_pcie_ep_lp4x_v10_defconfig

   
The kernel configuration for Portworld Pi is rockchip_rk3568_pai_ddr4_v10_defconfig, 
so select 8.

   Then execute `./build.sh kernel` to compile the kernel.


2. Debian Compilation
   RK_ROOTFS_SYSTEM=debian ./build.sh

   After the compilation is complete, the compiled image will be generated in the rockdev directory.

4. Flashing
   The flashing tool can be found at: `tools/windows/RKDevTool/RKDevTool_Release/RKDevTool.exe`
