set ns [new Simulator]
set file [open sim1.tr w]
$ns trace-all $file
set namfile [open sim1.nam w]
$ns namtrace-all $namfile
set tcpfile [open sim1.tcp w]
Agent/TCP set trace_all_oneline_ true


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]


$n0 label "UDP source"
$n1 label "TCP source"
$n2 label "sink/null"


$ns duplex-link $n0 $n1 3Mb 1ms DropTail
$ns duplex-link $n1 $n2 3Mb 1ms DropTail


$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient down


$ns queue-limit $n0 $n1 20
$ns queue-limit $n1 $n2 20
$ns duplex-link-op $n0 $n1 queuePos 0.5
$ns duplex-link-op $n1 $n2 queuePos 0.5


set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp $null
$udp set fid_ 0
$ns color 0 blue


set tcp [new Agent/TCP]
$ns attach-agent $n1 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$ns color 1 red


$tcp attach-trace $tcpfile
$tcp trace cwnd_


set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
set ftp [new Application/FTP]
$ftp attach-agent $tcp


$ns at 1.0 "$cbr start"
$ns at 1.5 "$ftp start"
$ns at 3.0 "$ftp stop"
$ns at 3.5 "$cbr stop"
$ns at 4.0 "finish"
proc finish {} {
	global ns file namfile tcpfile
	$ns flush-trace
	close $file
	close $namfile
	close $tcpfile
	exec nam sim1.nam &
	exec awk -f sim1.awk sim1.tr &
	exit 0
}


$ns run
