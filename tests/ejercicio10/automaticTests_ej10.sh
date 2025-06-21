
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio10.cpp -o ejercicio10

# Probar todos los casos
for test in tests/ejercicio10/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio10 < $test > tests/ejercicio10/$base.mio.out.txt
    ./compare.sh tests/ejercicio10/$base.mio.out.txt tests/ejercicio10/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done