solution=$1
brute=$2
gen=$3

g++ -o solution.exe $solution
g++ -o brute.exe $brute
g++ -o gen.exe $gen

i=1

echo "compilation complete"

while [[ i -ne 0 ]] 
do
    echo $i
    i=$((i+1))

    ./gen.exe > in.in
    ./solution.exe < in.in > out.out
    ./brute.exe < in.in > out2.out
    if ! cmp out.out out2.out;
    then
        echo "found difference"
        break
    fi
done