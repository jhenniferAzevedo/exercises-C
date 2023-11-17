# Atividade Avaliativa de Programação N2 – 2022/1

Uma escola de idiomas ministrará um curso intensivo de 1 ano. Serão abertas 2 turmas de no
máximo 5 alunos em cada. Os alunos recebem 3 notas ao longo do ano, a média aritmética destas
notas consiste na média final do aluno e a nota para receber o certificado é no mínimo 7,0
pontos. O aluno deve ter também no máximo 10 faltas, caso contrário será reprovado por falta.
Se o aluno tiver média final abaixo de 5,0 também será reprovado. O aluno que não foi aprovado,
nem reprovado, terá a chance de fazer uma prova substitutiva.

Elabore um programa em linguagem C que leia para cada aluno, seu nome, suas 3 notas, sua
frequência e mostre um dos os seguintes relatórios:

- **Consulta por aluno**:
Dado o número do aluno e de sua turma, mostre seu **nome**, suas **notas**, sua **média final**,
sua **frequência** e **uma das mensagens**: “Reprovado por falta”, “Reprovado por nota”,
“Certificado Liberado” ou “Fará substitutiva”.
- **Consulta por turma**:
Dado o número da turma, mostre **quantos alunos tem a turma**,
quantos tiveram **média final acima de 8**, quantos alunos tiveram algum zero em suas notas,
quantos **farão prova substitutiva** e qual é a **média de notas geral** da turma.

Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.

Obs.: Implementar pelo menos uma função que receba como parâmetros média final e frequência de
um aluno e retorne 0 se foi reprovado por falta, 1 se reprovado por nota, 2 se o certificado foi
liberado ou 3 se fará prova substitutiva.
