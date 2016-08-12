#!/bin/bash
fork() {
	while(true)
	do
		sleep 2
		echo "inside fork process"
	done
}	

echo "trying fork in shell"

fork &

echo "after  fork in shell"


