
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio5.cpp -o ejercicio5

# Probar todos los casos
for test in tests/ejercicio5/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio5 < $test > tests/ejercicio5/$base.mio.out.txt
    ./compare.sh tests/ejercicio5/$base.mio.out.txt tests/ejercicio5/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done