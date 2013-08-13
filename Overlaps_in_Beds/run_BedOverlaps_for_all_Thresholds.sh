 for t in  -1 -0.5 0 0.5 1 1.5 2 2.5 3 3.5 4 4.5 5; 



#########################################################      K562   ##############################
# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/K562_Common_With_Gm12878_and_Helas3/Chr22/Chr22_Sorted/K562_union_of_peaks.npf /nfs/th_group/hk3/UW_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization_For_Revision/wgEncodeUwDnaseK562AlnRep1_chr22_with_scores_less_than_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/K562_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_UW_K562.txt

# do echo -n $t$'\t'; 
 #   ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/K562_Common_With_Gm12878_and_Helas3/Chr22/Chr22_Sorted/K562_union_of_peaks.npf /nfs/th_group/hk3/UW_DNaseI_HS/K562_For_Paper_Analysis/Randomly_Removed_Tags/F_SEQ_OUTPUTS/wgEncodeUwDnaseK562AlnRep1_chr22_with_bias_scores_${t}.npf
 #   done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/K562_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_UW_K562_Randomly_Removed_Tags.txt



# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/K562_Common_With_Gm12878_and_Helas3/Chr22/Chr22_Sorted/K562_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization_For_Revision/wgEncodeOpenChromDnaseK562AlnRep1_chr22_with_scores_less_than_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/K562_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_K562.txt

# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/K562_Common_With_Gm12878_and_Helas3/Chr22/Chr22_Sorted/K562_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization_for_Duke_with_UW_motif/wgEncodeOpenChromDnaseK562Alnrep1_chr22_with_scores_less_than_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/K562_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_K562_with_UW_Motif.txt



 
##################################################    HelaS3      ###############################################

 # do echo -n $t$'\t'; 
 #   ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/Helas3_For_Paper_Analysis/Threshold_Optimization/wgEncodeOpenChromDnaseHelas3AlnRep1_chr22_with_scores_less_than_${t}.npf
 #   done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/HelaS3_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_HelaS3.txt


 do echo -n $t$'\t'; 
   ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/Helas3_For_Paper_Analysis/Threshold_Optimization_for_Duke_with_UW_motif/wgEncodeOpenChromDnaseHelas3Alnrep1_chr22_with_scores_less_than_${t}.npf
   done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/HelaS3_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_HelaS3_UW_Motif.txt




# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf /nfs/th_group/hk3/UW_DNaseI_HS/Helas3_For_Paper_Analysis/Threshold_Optimization/wgEncodeUwDnaseHelas3Alnrep1_chr22_with_scores_less_than_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/HelaS3_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_UW_HelaS3.txt



 # do echo -n $t$'\t'; 
 #   ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/HelaS3/HelaS3_common_With_K562_and_GM12878/Chr22/Chr22_Sorted/HelaS3_union_of_peaks.npf /nfs/th_group/hk3/UW_DNaseI_HS/Helas3_For_Paper_Analysis/Randomly_Removed_Tags/F_SEQ_OUTPUTS/wgEncodeUwDnaseHelas3Alnrep1_chr22_with_scores_less_than_${t}.npf
 #   done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/HelaS3_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_UW_HelaS3_Randomly_Removed_Tags.txt



################################################   GM12878      ##############################




# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/Gm12878_Common_With_K562_and_Helas3/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/Gm12878_For_Paper_Analysis/Randomly_Removed_Tags/F_SEQ_OUTPUTS/wgEncodeOpenChromDnaseGm12878Alnrep1_chr22_with_bias_scores_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/GM12878_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_Gm12878_Randomly_Removed_Tags.txt


# do echo -n $t$'\t'; 
#    ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/Gm12878/Gm12878_Common_With_K562_and_Helas3/Chr22/Chr22_Sorted/GM12878_union_of_peaks.npf /nfs/th_group/hk3/Duke_DNaseI_HS/Gm12878_For_Paper_Analysis/Threshold_Optimization_for_Duke_with_UW_motif/wgEncodeOpenChromDnaseGm12878Alnrep1_chr22_with_scores_less_than_${t}.npf
#    done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/GM12878_TFs_vs_DHS/Common_Set_SensSpec_Union_of_TFs_vs_Duke_Gm12878_UW_Motif.txt






##########################   archive of some old commands  ################


# for t in -3 -2.5 -2 -1.5 -1 -0.5 0 0.5 1 1.5 2 2.5 3 3.5 4; do echo -n $t$'\t'; java gfftools.CountOverlappingBases combined-tfbs2-chr22.gff  wgEncodeUwDnaseK562AlnRep1_chr22_with_biasness_scores_less_than_${t}.gff; done | awk -v $'OFS=\t' '{print $0, ($4+$5)/2}' | tee sensspec2.txt





# do echo -n $t$'\t'; 
# ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/Duke_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization/wgEncodeOpenChromDnaseK562AlnRep1_chr22_with_biasness_scores_less_${t}.npf
 #done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee sensspec_29TFs_vs_Duke_K562_Revision.txt

 # do echo -n $t$'\t'; 
 #  ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/UW_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization/wgEncodeUwDnaseK562AlnRep1_chr22_with_biasness_scores_less_than_${t}.npf
 #  done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee sensspec_29TFs_vs_UW_K562_Revision.txt


# do echo -n $t$'\t'; 
#   ./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf /nfs/th_group/hk3/UW_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization_For_Revision/Randomly_Removed_Tags/F_SEQ_OUTPUTS/wgEncodeUwDnaseK562AlnRep1_chr22_with_bias_scores_${t}.npf
#   done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee /nfs/users/nfs_h/hk3/My_CPlusPlus/Overlaps_in_Beds/K562_TFs_vs_DHS/sensspec_29TFs_vs_UW_K562_Randomly_Moved_Tags.txt
