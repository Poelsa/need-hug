#! /bin/bash
logFile="logs/gitlogs.txt"
mkdir -p logs
touch logs/gitlogs.txt
date=`date '+%Y-%m-%d %H:%M'`
error=0
> .formatCache

clangFormat=""
if [[ "$OSTYPE" == "linux-gnu" ]]; then
	clangFormat="clang-format-3.8"
elif [[ "$OSTYPE" == "msys" ]]; then
	clangFormat="clang-format.exe"
else
	echo "Unsupported OS: $OSTPYE"
        exit 1
fi

# Find all files that has been changed
files=`git diff --cached -p --diff-algorithm=minimal | grep -a "diff --git" | cut -d" " -f3 | cut -d"/" -f2- | grep -a "\.cpp\|\.hpp"`
echo "[$date] All files: $files" >> $logFile

# Cross reference with deleted files, aka, remove deleted files from format check.
for deletedFile in $(git diff --cached --summary | grep -a delete | cut -d" " -f5)
do
	files=`echo "$files" | grep -a -v $deletedFile`
done

echo -e "Checking formatting in source files."
for file in $(echo "$files")
do
	echo -e "[$date] File: $file." >> $logFile
	echo -e "Checking $file."

	# Get information about the chunks
	for line in $(git diff --cached -p $file | grep -a @@ | cut -d" " -f3 | cut -d"+" -f2)
	do
		echo "[$date] line = $line" >> $logFile
		startLine=$(echo $line | cut -d"," -f1)
		endLine=$(echo $line | cut -d"," -f2)
		endLine=$((startLine + endLine))		
		echo "[$date] startLine = $startLine" >> $logFile
		echo "[$date] endLine = $endLine" >> $logFile
		newCode=`$clangFormat -lines=$startLine:$endLine $file`
		oldCode=`cat $file`
		#echo [$date] $newCode >> $logFile
		#echo [$date] $oldCode >> $logFile
		if [ "$newCode" != "$oldCode" ]; then
			echo -e "Detected problems with formatting on rows $startLine-$endLine"
			echo $file,$startLine,$endLine >> .formatCache
			error=1
		fi
	done
done

if [ $error -ne 0 ]; then
	RED='\033[0;31m'
	PURPLE='\033[0;35m'
	NC='\033[0m' # No Color
	echo -e ""
	echo -e "Format check incomplete, found problems in the following files:"
	echo -e "\t(Run './scripts/format/fromCache.sh' to format these changes.)"
	echo -e ""
	for faultyFile in $(cat .formatCache | cut -d"," -f1)
	do
	echo -e "${RED}\t$faultyFile"
	done
	exit $error
fi

echo -e "Check complete. No problems detected."
exit 0
