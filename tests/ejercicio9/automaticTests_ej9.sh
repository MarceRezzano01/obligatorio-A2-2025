
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio9.cpp -o ejercicio9

# Probar todos los casos
for test in tests/ejercicio9/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio9 < $test > tests/ejercicio9/$base.mio.out.txt
    ./compare.sh tests/ejercicio9/$base.mio.out.txt tests/ejercicio9/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done