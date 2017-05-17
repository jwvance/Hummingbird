# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mgronber\Desktop\Hummingbird\Hummingbird(Continuous Output).cydsn\Hummingbird(Continuous Output).cyprj
# Date: Wed, 17 May 2017 02:14:38 GMT
#set_units -time ns
create_clock -name {ADC_MIC_theACLK(routed)} -period 983.33333333333314 -waveform {0 491.666666666667} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {ADC_UI_IntClock(routed)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 16.666666666666664 -waveform {0 8.33333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 16.666666666666664 -waveform {0 8.33333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 16.666666666666664 -waveform {0 8.33333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {ADC_MIC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 59 119} -nominal_period 983.33333333333314 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_UI_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 61 121} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_3}]]


# Component constraints for C:\Users\mgronber\Desktop\Hummingbird\Hummingbird(Continuous Output).cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mgronber\Desktop\Hummingbird\Hummingbird(Continuous Output).cydsn\Hummingbird(Continuous Output).cyprj
# Date: Wed, 17 May 2017 02:14:18 GMT
