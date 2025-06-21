
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio8.cpp -o ejercicio8

# Probar todos los casos
for test in tests/ejercicio8/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio8 < $test > tests/ejercicio8/$base.mio.out.txt
    ./compare.sh tests/ejercicio8/$base.mio.out.txt tests/ejercicio8/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done