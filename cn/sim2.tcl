set ns [new Simulator]
set f [open sim2.tr w]
set nf [open sim2.nam w]


$ns trace-all $f
$ns namtrace-all $nf


proc finish {} {
global f nf ns
$ns flush-trace
close $f
close $nf
exec nam sim2.nam &
exec awk -f sim2.awk sim2.tr &
exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]


$n0 label "TCP SOURCE"
$n1 label "UDP SOURCE"
$n2 label "ROUTER"
$n3 label "SINK"


$ns color 1 red
$ns color 2 blue


$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2.75Mb 20ms DropTail


$ns queue-limit $n2 $n3 20


set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0


set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0


$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.002


set null0 [new Agent/TCP]
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0


set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0


set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0


set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink


$ftp0 set maxPkts_ 1000
$ftp0 set packetSize_ 300
$ns connect $tcp0 $sink
$udp0 set class_ 1
$tcp0 set class_ 2


$ns at 0.1 "$cbr0 start"
$ns at 1.0 "$ftp0 start"
$ns at 4.0 "$ftp0 stop"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"


$ns run
