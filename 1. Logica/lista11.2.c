{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyMd8QWbyHsTHEGEp3Y2xiRm"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"4j3sFXxGTBEr"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","int qalunos, mat, dia, mes, cont = 1;\n","float media=0, np, mp, nf, tn, mf;\n","\n","  printf(\"Escreva a quantidade de alunos: \\n\");\n","  scanf(\"%d\", &qalunos);\n","\n","    while (cont<=qalunos) {\n","      printf(\"Escreva a matrícula, nota provisória e data de entrega (00 0 01 04): \\n\");\n","      scanf(\"%d %f %d %d\", &mat, &np, &dia, &mes);\n","      cont++;\n","      tn+=np;\n","      if(mes<=4 && dia<=20){ nf=np;\n","      }\n","      else if(mes<=5 && dia<=2){ nf=np-2;\n","      }\n","      else if(mes<=6 && dia<=30){ nf=np/2;\n","        }\n","      else { nf=0;\n","      }\n","      printf(\"A nota final do aluno %d é: %.2f\\n\", mat, nf);\n","      mf+=nf;\n","    }\n","  mp = tn/qalunos;\n","  media = mf/qalunos;\n","  printf(\"A média de notas provisórias é %.2f.\\n\", mp);\n","  printf(\"A média de notas finais é %.2f.\\n\", media);\n","\n","return 0;\n","}"]}]}