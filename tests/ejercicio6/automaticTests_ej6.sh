
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio6.cpp -o ejercicio6

# Probar todos los casos
for test in tests/ejercicio6/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio6 < $test > tests/ejercicio6/$base.mio.out.txt
    ./compare.sh tests/ejercicio6/$base.mio.out.txt tests/ejercicio6/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done