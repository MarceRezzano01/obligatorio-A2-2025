
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio7.cpp -o ejercicio7

# Probar todos los casos
for test in tests/ejercicio7/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio7 < $test > tests/ejercicio7/$base.mio.out.txt
    ./compare.sh tests/ejercicio7/$base.mio.out.txt tests/ejercicio7/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done