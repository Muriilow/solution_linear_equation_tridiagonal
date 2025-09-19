#!/bin/bash

# Script simplificado
PROGRAM="resolveEDO"
DATA="tmp"

# Conseguindo o valod do stdin na variavel DATA
cat > "$DATA"

# Executando o programa com a variavel DATA
./$PROGRAM < "$DATA" 2>&1 | grep -v "Running without Marker API."

# Executar com likwid e filtrando as informacoes
RESULT=$(likwid-perfctr -C 0 -g FLOPS_DP -O -m ./$PROGRAM < "$DATA" 2>&1 | grep "FP_ARITH_INST_RETIRED_SCALAR_DOUBLE")

rm $DATA
# Printando o resultado do likwid sem o contador de performance 
echo "$RESULT" | awk -F ',' '{print $1 "," $3}'
