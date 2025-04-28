
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio1.cpp -o ejercicio1

# Probar todos los casos
for test in tests/ejercicio1/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio1 < $test > tests/ejercicio1/$base.mio.out.txt
    ./compare.sh tests/ejercicio1/$base.mio.out.txt tests/ejercicio1/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done