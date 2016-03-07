#!/bin/bash

BUNDLE="bundle.sh"

if [ $# -eq 0 ]
then
	echo "Insufficient Arguments!"
	exit
fi

echo "#!/bin/bash" > $BUNDLE

for i in $*
do
	echo "echo Extracting "$i >> $BUNDLE
	echo "cat > "$i" << EOF " >> $BUNDLE
	cat $i >> $BUNDLE
	echo "EOF" >> $BUNDLE
done

chmod +x $BUNDLE

exit
