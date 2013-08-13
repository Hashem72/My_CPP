#!/bin/bash
for t in 0.001 0.005 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1 0.2 0.3 0.4
do echo -n $t$'\t'; 
#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf /nfs/th_group/hk3/ZINBA_ANALYSIS/UW/Helas3/NPF_Files/ZINBA_OUT_FDR_${t}_narrow_peaks.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee  Union_of_Helas3_13_Common_TFs_vs_ZINBA_NARROW.txt

./BedOverlaps  /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf  /nfs/th_group/hk3/ZINBA_ANALYSIS/UW/Helas3/NPF_Files/ZINBA_OUT_FDR_${t}_broad_peaks.npf
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Helas3_13_Common_TFs_vs_ZINBA_BROAD.txt
 


#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/ZINBA_ANALYSIS/UW/K562/NPF_Files/ZINBA_OUT_FDR_${t}_narrow_peaks.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/HelaS3_TFs_vs_DHS/ZINBA_Vs_29TFs_Narrow.txt


# ./BedOverlaps /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/wgEncodeUwDnaseGm12878HotspotsRep1_chr22.npf /nfs/th_group/hk3/ZINBA_ANALYSIS/UW/K562/NPF_Files/ZINBA_OUT_FDR_0.01_narrow_peaks.npf

# ./BedOverlaps /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/wgEncodeUwDnaseGm12878HotspotsRep1_chr22.npf /nfs/th_group/hk3/ZINBA_ANALYSIS/UW/K562/NPF_Files/ZINBA_OUT_FDR_0.01_broad_peaks.npf

# awk '{print $1,"\t",$2,"\t",$3,"\t",$4,"\t0\t+\t0\t0\t0\t0"}' ZINBA_OUT_FDR_0.01.peaks.bed > ZINBA_OUT_FDR_0.01_narrow_peaks.npf
# awk '{print $2,"\t",$3,"\t",$4,"\t",$1,"\t0\t+\t0\t0\t0\t0"}' ZINBA_OUT_FDR_0.01.peaks > ZINBA_OUT_FDR_0.01_broad_peaks.npf


