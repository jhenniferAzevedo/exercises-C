normal="\033[0m"
vermelho="\033[0;31m"
verde="\033[0;32m"

# Essas linhas definem algumas variáveis para controle de cores no terminal 
# usando códigos de escape ANSI. Elas são usadas posteriormente para imprimir 
# mensagens coloridas.

echo "Rodando os testes..."
echo 

# Aqui, o script imprime uma mensagem informando que os testes estão sendo 
# executados.

machine=''
unameOut="$(uname -s)"
case "${unameOut}" in
    CYGWIN*)    machine=-win;;
    MINGW*)     machine=-win;;
esac

# Essas linhas determinam o tipo de sistema operacional em que o script está 
# sendo executado (Cygwin ou MinGW no caso de sistemas Windows).

count=0
corrected=0

# Duas variáveis, count e corrected, são inicializadas para contar o número 
# total de testes e o número de testes corretamente passados, respectivamente.

for f in $(ls testes/*.in)

# Um loop for percorre todos os arquivos com a extensão ".in" no diretório 
# "testes".

do
    let count=count+1
    echo "---------------------------------------------"
    echo "TESTE NÚMERO ${count}"
    output="$(./a $f)"
    expected_output="$(cat $f-out$machine)"

    # Para cada arquivo de entrada, o script incrementa o contador e executa o 
    # programa (./a) com o arquivo de entrada atual. Ele também lê o arquivo de 
    # saída esperado correspondente.

    teste_ok=0
    echo "teste de execução do programa:"
    if [ $? -eq 0 ] ; then
      teste_ok=1
      echo -e "O programa executou com retorno CORRETO (zero)."
    else
      echo -e "[$vermelho Falha $normal]O programa não encerrou com o retorno esperado (zero) não ocorreu."
    fi
    
    # O script verifica se a execução do programa anterior foi bem-sucedida 
    # (código de retorno zero) e define a variável teste_ok de acordo.

    if [ $teste_ok -eq 1 ]; then 
        echo "Arquivo de teste $f. Entrada Fornecida:"
        echo "$(cat $f)"
        echo "Saída esperada: "
        echo "$expected_output"
        echo "Seu programa gerou a seguinte saída:"
        echo "$output"

        # O script verifica se o teste foi bem-sucedido (se teste_ok é igual a 1) 
        # e, se sim, imprime informações sobre o arquivo de teste, a entrada 
        # fornecida, a saída esperada e a saída gerada pelo programa.

        if [ "$output" = "$expected_output" ] ; then
          echo -e "[$verde Ok $normal] Passou: A saída está correta"
          let corrected=corrected+1
        else
          echo -e "[$vermelho Falha $normal] A saída NÃO está conforme esperado"
          #exit 1
        fi
    fi  
done

# Finalmente, o script compara a saída gerada pelo programa com a saída esperada. 
# Se forem iguais, considera o teste como passado, incrementa o contador de testes 
# corretos e imprime uma mensagem correspondente. Se não, imprime uma mensagem de 
# falha.

echo "-----------------------------------------------------------"
echo
if [ $count -eq $corrected ]; then
  echo -e "$verde Passou em TODOS os testes.$normal"
  exit 0
else
  echo -e "$vermelho Não passou em todos os testes.$normal"
  exit 1
fi
