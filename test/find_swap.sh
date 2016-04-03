for i in `ls *.c`
do
    echo $i;
    cat $i|grep swap;
    echo "----------";
done
