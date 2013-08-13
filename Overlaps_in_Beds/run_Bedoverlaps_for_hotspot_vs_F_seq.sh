#!/bin/bash
for t in 0.001 0.005 0.01 0.05 0.1 0.5 1 1.5 2 2.5 3 3.5 4 4.5 5 5.5 6 6.5
do echo -n $t$'\t';
	#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/All/Chr22/Chr22_Sorted/K562_Union_of_Peaks.npf /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/K562/F_Seq_Outputs_for_different_t_Parameters/chr22_t_${t}.npf
#done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_K562_Full_Sets_of_TFs_vs_F_Seq.txt


	./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/Gm12878_Common_With_K562_and_Helas3/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/F_Seq_Outputs_for_different_t_Parameters/chr22_t_${t}.npf
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Gm12878_13_Common_TFs_vs_F_Seq.txt



