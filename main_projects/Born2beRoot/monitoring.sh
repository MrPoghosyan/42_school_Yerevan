#!/bin/bash

# Համակարգի մասին տեղեկություններ ստանալը:
#
ARCH=$(uname -a)  # OS ճարտարապետություն և միջուկի տարբերակ:
PHYS_CPU=$(lscpu | grep "Socket(s)" | awk '{print $2}')  # Ֆիզիկական պրոցեսորների քանակը:
VIRT_CPU=$(nproc)  # Վիրտուալ պրոցեսորների քանակը:
MEM_TOTAL=$(free -m | awk '/^Mem:/{print $2}')  # Ընդհանուր RAM (MB):
MEM_USED=$(free -m | awk '/^Mem:/{print $3}')  # Օգտագործված RAM (MB):
MEM_PERC=$(awk "BEGIN {printf \"%.2f\", ($MEM_USED/$MEM_TOTAL)*100}")  # RAM-ի օգտագործման տոկոս:
DISK_TOTAL=$(df -h --total | grep "total" | awk '{print $2}')  # Սկավառակի ընդհանուր չափը:
DISK_USED=$(df -h --total | grep "total" | awk '{print $3}')  # Օգտագործված տարածք:
DISK_PERC=$(df -h --total | grep "total" | awk '{print $5}')  # Սկավառակի օգտագործման տոկոս:
CPU_LOAD=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')  # CPU բեռնվածություն (%):
LAST_BOOT=$(who -b | awk '{print $3, $4}')  # Վերջին վերաբեռնման ամսաթիվը և ժամը:
LVM_USE=$(lsblk | grep "lvm" &> /dev/null && echo "yes" || echo "no")  # LVM-ն օգտագործվու՞մ է:
TCP_CONN=$(ss -t | grep ESTAB | wc -l)  # Ակտիվ TCP կապերի քանակը:
USER_LOG=$(who | wc -l)  # Օգտագործողների թիվը սերվերում:
IPV4_ADDR=$(hostname -I | awk '{print $1}')  # Սերվերի IPv4 հասցեն:
MAC_ADDR=$(ip link show | awk '/ether/ {print $2}' | head -n 1)  # MAC հասցե:
SUDO_CMDS=$(journalctl _COMM=sudo | grep COMMAND | wc -l)  # Sudo հրամանների քանակը:

# Արտադրեք տվյալները wall հրամանի միջոցով:
#
wall <<EOF
#Architecture: $ARCH
#CPU physical : $PHYS_CPU
#vCPU : $VIRT_CPU
#Memory Usage: $MEM_USED/$MEM_TOTAL MB ($MEM_PERC%)
#Disk Usage: $DISK_USED/$DISK_TOTAL ($DISK_PERC)
#CPU load: $CPU_LOAD%
#Last boot: $LAST_BOOT
#LVM use: $LVM_USE
#Connections TCP : $TCP_CONN ESTABLISHED
#User log: $USER_LOG
#Network: IP $IPV4_ADDR ($MAC_ADDR)
#Sudo : $SUDO_CMDS cmd
EOF
