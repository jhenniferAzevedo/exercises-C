normal="\033[0m"
vermelho="\033[0;31m"
verde="\033[0;32m"

echo "Rodando os testes..."
echo 

machine=''
unameOut="$(uname -s)"
case "${unameOut}" in
    CYGWIN*)    machine=-win;;
    MINGW*)     machine=-win;;
esac

count=0
corrected=0
for f in $(ls testes/*.in)

do
    let count=count+1
    echo "---------------------------------------------"
    echo "TESTE NÚMERO ${count}"
    output="$(./a $f)"
    expected_output="$(cat $f-out$machine)"
    teste_ok=0
    echo "teste de execução do programa:"
    if [ $? -eq 0 ] ; then
      teste_ok=1
      echo -e "O programa executou com retorno CORRETO (zero)."
    else
      echo -e "[$vermelho Falha $normal]O programa não encerrou com o retorno esperado (zero) não ocorreu."
    fi
    if [ $teste_ok -eq 1 ]; then 
        echo "Arquivo de teste $f. Entrada Fornecida:"
        echo "$(cat $f)"
        echo "Saída esperada: "
        echo "$expected_output"
        echo "Seu programa gerou a seguinte saída:"
        echo "$output"

        if [ "$output" = "$expected_output" ] ; then
          echo -e "[$verde Ok $normal] Passou: A saída está correta"
          let corrected=corrected+1
        else
          echo -e "[$vermelho Falha $normal] A saída NÃO está conforme esperado"
          #exit 1
        fi
    fi  
done

echo "-----------------------------------------------------------"
echo
if [ $count -eq $corrected ]; then
  echo -e "$verde Passou em TODOS os testes.$normal"
  exit 0
else
  echo -e "$vermelho Não passou em todos os testes.$normal"
  exit 1
fi
