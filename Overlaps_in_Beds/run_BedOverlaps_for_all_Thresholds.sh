 for t in -3 -2.5 -2 -1.5 -1 -0.5 0 0.5 1 1.5 2 2.5 3 3.5 4; 
do echo -n $t$'\t'; 
./BedOverlaps /nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_10_tfs.narrowPeak /nfs/th_group/hk3/UW_DNaseI_HS/K562_For_Paper_Analysis/Threshold_Optimization/wgEncodeUwDnaseK562AlnRep1_chr22_with_biasness_scores_less_than_${t}.npf
done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee sensspec2.txt

# for t in -3 -2.5 -2 -1.5 -1 -0.5 0 0.5 1 1.5 2 2.5 3 3.5 4; do echo -n $t$'\t'; java gfftools.CountOverlappingBases combined-tfbs2-chr22.gff  wgEncodeUwDnaseK562AlnRep1_chr22_with_biasness_scores_less_than_${t}.gff; done | awk -v $'OFS=\t' '{print $0, ($5+$6)/2}' | tee sensspec2.txt
