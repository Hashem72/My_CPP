#!/bin/bash
TF=/nfs/th_group/hk3/SYD_TFS/K562/Peak_Unions_All_Tfs/union_of_peaks_from_29_tfs.npf

outputFile=/nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/$1/$1_overlap_results.txt 
echo " output file is: "$outputFile

for x in $1;
do 
     path=/nfs/th_group/hk3/Hotspot_vs_F_Seq/UW/$x
    FSEQ=${path}/F_Seq_Output_Chr22.npf
    HS=${path}/wgEncodeUwDnase${x}HotspotsRep1_chr22.npf
    ./BedOverlaps ${TF}  ${HS}
    ./BedOverlaps ${TF}  ${FSEQ}
    ./BedOverlaps ${HS}  ${FSEQ}
    done | awk -v $'OFS=\t' '{print $0, ($4+$5)/2}' | tee ${outputFile}
    
