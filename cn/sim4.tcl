set ns [new Simulator]
set f [open sim4.tr w]
set nf [open sim4.nam w]
$ns trace-all $f
$ns namtrace-all $nf


proc finish {} {
	global f nf ns
	$ns flush-trace
	close $f
	close $nf 
	exec nam sim4.nam &
	exec awk -f sim4.awk sim4.tr &
	exit 0
}


for {set i 0} {$i < 10} {incr i} {
	set n($i) [$ns node]
}
$ns make-lan "$n(0) $n(1) $n(2) $n(3) $n(4)" 1Mb 10ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n(5) $n(6) $n(7) $n(8) $n(9)" 1Mb 10ms LL Queue/DropTail Mac/802_3
$ns duplex-link $n(2) $n(6) 1Mb 30ms DropTail


Mac/802_3 set datarate_ 10Mb


set udp0 [new Agent/UDP]
$ns attach-agent $n(0) $udp0


set cbr0 [new Application/Traffic/CBR] 
$cbr0 attach-agent $udp0


$cbr0 set packetSize_ 700
$cbr0 set Interval_ 0.10


set tcp0 [new Agent/TCP]
$ns attach-agent $n(3) $tcp0


set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set packetSize_ 200


set null0 [new Agent/Null]
$ns attach-agent $n(7) $null0


set sink0 [new Agent/TCPSink]
$ns attach-agent $n(8) $sink0


$ns connect $udp0 $null0
$ns connect $tcp0 $sink0


set err [new ErrorModel]
$ns lossmodel $err $n(2) $n(6)
$err set rate_ 0.1


$ns at 1.0 "$cbr0 start"
$ns at 1.0 "$ftp0 start"
$ns at 4.0 "$cbr0 stop"
$ns at 5.0 "$ftp0 stop"
$ns at 6.0 "finish"


$ns run
