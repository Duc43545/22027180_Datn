Đây là hướng dẫn chi tiết từng bước để tạo 2 file riêng biệt: file firmware mặc định và file bootloader cho board tùy chỉnh my427, dựa trên PX4 Autopilot và PX4-Bootloader.

1️⃣ Chuẩn bị môi trường

Đảm bảo bạn dùng Ubuntu 20.04+ (Windows có thể dùng WSL). Cài các gói cần thiết:

sudo apt update

sudo apt install git python3-pip python3-venv build-essential

sudo pip3 install pyserial empy toml numpy pandas

Clone PX4 Autopilot và PX4-Bootloader:

git clone https://github.com/PX4/PX4-Autopilot.git --recursive

git clone https://github.com/PX4/PX4-Bootloader.git --recursive
cd PX4-Autopilot
bash ./Tools/setup/ubuntu.sh

2️⃣ Chuẩn bị board my427 cho firmware

Vào thư mục boards PX4 và tạo folder my427 và copy file thư mục myf427 từ đây vào :

cd PX4-Autopilot/boards/px4

mkdir myf427

3️⃣ Build firmware mặc định (Default Firmware)

Quay lại thư mục root PX4-Autopilot và chạy:

cd ~/PX4-Autopilot

make px4_my427_default

Kết quả: file firmware px4_my427_default.bin nằm trong build/px4_my427_default/



Sao chép file hwconfig tùy chỉnh cho board my427 từ đây vào folder bootloader của bạn:

cp -r ~/PX4-Bootloader/hwconfig/my427 ~/PX4-Bootloader/hwconfig/my_f427_bl


Folder my_f427_bl sẽ dùng để định nghĩa các thông số board khi build bootloader.

Build bootloader (my_f427_bl)

Chuyển vào thư mục PX4-Bootloader:
cd ~/PX4-Bootloader

Chạy lệnh make cho board my427:
make px4_myf427_bl

Kết quả: file bootloader my_f427_bl.bin nằm trong build/px4_myf427_bl/.
Đây là file riêng biệt, dùng để nạp bootloader cho board my427.

Vào phần mềm Stm32programmer và làm theo các bước:
1. Reset lại chip
2. Nạp firmware my_f427_bl.bin ở địa chỉ 0x08000000
3. Nạp firmware px4_my427_default.bin ở địa chỉ 0x08004000


