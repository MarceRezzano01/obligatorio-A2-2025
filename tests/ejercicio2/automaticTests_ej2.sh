
#CODIGO PARA TESTEAR AUTOMATICAMENTE TODOS LOS CASOS REALIZADO CON CHATGPT

#!/bin/bash
# Ir al directorio raíz del proyecto
cd ../..

# Compilar el ejercicio
g++ ejercicio2.cpp -o ejercicio2

# Probar todos los casos
for test in tests/ejercicio2/*.in.txt; do
    base=$(basename $test .in.txt)
    echo "Testing $base:"
    ./ejercicio2 < $test > tests/ejercicio2/$base.mio.out.txt
    ./compare.sh tests/ejercicio2/$base.mio.out.txt tests/ejercicio2/$base.out.txt
    if [ $? -eq 0 ]; then
        echo " Test $base passed"
    else
        echo " Test $base failed"
    fi
    echo "-------------------"
done