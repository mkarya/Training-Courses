#!/bin/bash


airthmatic_operation() {
   case $oper in 
	 "addition") 
		result=$(expr "$first" + "$second")
	;;
	 "subtraction") 
		result=$(expr "$first" - "$second")
	;;
	"multiplication")
		result=$(expr $first \* $second)
	;;
	"division")
		result=$(expr "$first" / "$second")
	;;
	*)
		result="0"
		echo "operation is not valid"
	;;
   esac
   return $result

}

first="43"
second="23"
oper="addition"

airthmatic_operation

echo $?

echo "subtraction operation"
oper="subtraction"

airthmatic_operation

echo $?

echo "multiplication operation"
oper="multiplication"

airthmatic_operation

echo $?

echo "division operation"
oper="division"

airthmatic_operation

echo $?
