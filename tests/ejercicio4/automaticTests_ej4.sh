
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio4.cpp -o ejercicio4

# Probar todos los casos
for test in tests/ejercicio4/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio4 < $test > tests/ejercicio4/$base.mio.out.txt
    ./compare.sh tests/ejercicio4/$base.mio.out.txt tests/ejercicio4/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done