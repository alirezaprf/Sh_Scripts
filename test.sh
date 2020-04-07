#!/bin/sh
file="/var/log/re_usage.log"




!(test -f $file) && echo "date,memory,cpu" > $file



while true; do
echo -n `date +"[%Y-%m-%d %H:%M:%S]"` >> $file 
total=`cat /proc/meminfo  | awk 'FNR==1 {print $2}' `
free=`cat /proc/meminfo  | awk 'FNR==2  {print $2}' `

used=`echo "$total-$free" | bc -l `

#echo $used

res=`echo "$used/$total" | bc -l `

printf ",%.2f," $res  >> $file 

awk '{printf "%.2f\n", $1}' /proc/loadavg  >> $file



#df -h | awk '$NF=="/"{printf "%s\b,",$5}' >> $file
#top -bn1 | grep load | awk '{printf "%.2f\n", $(NF-2)*100}' >>$file
#iotop -ob -n 1 | grep %
#echo  "-------------------------\n average : "
#cat /proc/loadavg
#memory  /proc/mrminfo
#cpu	/proc/cpuifno
sleep 2
done 
