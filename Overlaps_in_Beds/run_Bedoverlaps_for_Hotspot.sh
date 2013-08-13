#!/bin/bash
for t in 0.001 0.005 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1 0.2
do echo -n $t$'\t'; 
################################################# K562 ##############################
#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/All/Chr22/Chr22_Sorted/K562_Union_of_Peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/K562/NPFs/wgEncodeUwDnaseK562AlnRep1.hotspot.twopass.fdr${t}.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_K562_TFs_vs_HOTSPOT.txt


############################################### Gm12878 ###############################


#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/All/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/Gm12878/NPFs/wgEncodeUwDnaseGm12878AlnRep1.hotspot.twopass.fdr${t}.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Gm12878_TFs_vs_HOTSPOT.txt

############################################### Helas3 ###############################


./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/All/Chr22/Chr22_Sorted/HelaS3_Union_of_Peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/Helas3/NPFs/wgEncodeUwDnaseHelas3AlnRep1.hotspot.twopass.fdr${t}.npf
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Helas3_TFs_vs_HOTSPOT.txt

