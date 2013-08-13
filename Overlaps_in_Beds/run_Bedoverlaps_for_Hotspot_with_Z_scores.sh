
#!/bin/bash
for t in 1 2 3 4
do echo -n $t$'\t'; 
################################################# K562 ##############################
#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/All/Chr22/Chr22_Sorted/K562_Union_of_Peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/K562_different_z_scores/NPF/wgEncodeUwDnaseK562AlnRep1.hotspot.twopass.fdr0.05.z.${t}.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_K562_TFs_vs_HOTSPOT_Over_Z.txt

############################################### Gm12878 ###############################


#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/All/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/Gm12878_different_z_scores/NPF/wgEncodeUwDnaseGm12878AlnRep1.hotspot.twopass.fdr0.05.z.${t}.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Gm12878_TFs_vs_HOTSPOT_Over_Z.txt

############################################### Helas3 ###############################


./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/All/Chr22/Chr22_Sorted/HelaS3_Union_of_Peaks.npf /nfs/th_group/hk3/Hotspot_V3_Analysis/UW/Helas3_different_z_scores/NPF/wgEncodeUwDnaseHelas3AlnRep1.hotspot.twopass.fdr0.05.z.${t}.npf
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Helas3_TFs_vs_HOTSPOT_Over_Z.txt




#grep -e "^chr22" wgEncodeUwDnaseK562AlnRep1.hotspot.twopass.fdr0.05.bed | awk '{print $1,"\t",$2,"\t",$3,"\t",$4,"\t0\t+\t0\t0\t0\t0"}' > wgEncodeUwDnaseK562AlnRep1.hotspot.twopass.fdr0.05.npf
