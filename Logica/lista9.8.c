{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyPxTThqMruXSkdnHKujzF8I"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"FCwGKFdig5Qs"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","    int opcao, dias, encerradas=0;\n","    float diaria, total, taxa, totalgeral;\n","    do {\n","        printf(\"Faça um algoritmo que apresente as seguintes opções ao recepcionista: \\n 1. encerrar a conta de um hóspede \\n 2. verificar número de contas encerradas \\n 3. finalizar a execução\\n Escolha uma opção: \\n\");\n","        scanf(\" %d\", &opcao);\n","\n","        switch(opcao) {\n","            case 1:\n","                printf(\"Digite o número de diárias: \");\n","               scanf(\"%d\", &dias);\n","              if(dias<15) {\n","                taxa = dias * 7.5;\n","              }\n","                else if(dias==15) {\n","                  taxa = dias * 6.5;\n","                }\n","                  else{\n","                    taxa = dias * 5;\n","                  }\n","                total = dias * 50 + taxa;\n","                printf(\"O valor total é de: %.2f\\n\", total);\n","              encerradas++;\n","              totalgeral += total;\n","                break;\n","            case 2:\n","                printf(\"O número de contas encerradas é: %d. O valor total arrecadado é de: %.2f\\n\", encerradas, totalgeral);\n","                break;\n","            case 3:\n","                printf(\"Finalizar a execução...\\n\");\n","                break;\n","            default:\n","                printf(\"Opção inválida. Por favor, escolha novamente.\\n\");\n","        }\n","    } while (opcao != 3);\n","    return 0;\n","}"]}]}