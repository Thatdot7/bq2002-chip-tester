# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\Documents\GitHub\bq2002-chip-tester\bq2002 Tester\bq2002 Tester.cydsn\bq2002 Tester.cyprj
# Date: Sat, 27 Jun 2015 14:52:01 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ResolutionClk} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list [get_pins {ClockBlock/udb_div_0}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for E:\Documents\GitHub\bq2002-chip-tester\bq2002 Tester\bq2002 Tester.cydsn\TopDesign\TopDesign.cysch
# Project: E:\Documents\GitHub\bq2002-chip-tester\bq2002 Tester\bq2002 Tester.cydsn\bq2002 Tester.cyprj
# Date: Sat, 27 Jun 2015 14:51:58 GMT
