#!/bin/bash
for t in 0.001 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1 0.2 0.3 0.4 0.5 
do echo -n $t$'\t'; 
    #./BedOverlaps  /nfs/th_group/hk3/SYD_TFS/HelaS3/All/Chr22/Chr22_Sorted/HelaS3_Union_of_Peaks.npf /nfs/th_group/hk3/MACS_ANALYSIS/UW/Helas3/Helas3_${t}_peaks.encodePeak
    #./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/All/Chr22/Chr22_Sorted/K562_Union_of_Peaks.npf /nfs/th_group/hk3/MACS_ANALYSIS/UW/K562/K562_${t}_peaks.encodePeak
./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/Gm12878_Common_With_K562_and_Helas3/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/MACS_ANALYSIS/UW/Gm12878/Gm12878_${t}_peaks.encodePeak
     
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee Union_of_Gm12878_13_Common_TFs_vs_MACS.txt







######################################################
# #!/bin/bash
# for t in 0.5 1 1.5 2 2.5 3 3.5 4 4.5 5;
# do 
#     #echo -n $t$'\n';
#     for l in 200 300 400 500 600 700 800;
#     do 
# 	#echo $l$'\t';
# #	./BedOverlaps /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/wgEncodeUwDnaseGm12878HotspotsRep1_chr22.npf /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/F_Seq_Outputs_for_diff_parameters/chr22_t_${t}_l_${l}.npf
# 	#./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/chr22_t_${t}_l_${l}.npf

# 	./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/Gm12878/F_Seq_Outputs_for_diff_parameters/chr22_t_${t}_l_${l}.npf

# 	done
# done | awk -v $'OFS=\t' '{print $0, ($4+$5)/2}' | tee testing_29TFs_vs_f_seq.txt


