
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio3.cpp -o ejercicio3

# Probar todos los casos
for test in tests/ejercicio3/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio3 < $test > tests/ejercicio3/$base.mio.out.txt
    ./compare.sh tests/ejercicio3/$base.mio.out.txt tests/ejercicio3/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done