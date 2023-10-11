#include <stdio.h>
#include <stdlib.h>//system()
#include <string.h>
#include <unistd.h>//sleep
#include <stdio_ext.h>//__fpurge()
#include<sys/stat.h>//stat()
#include <locale.h>//setlocale()
#include <time.h>//srand(time())

//funções e variáveis
int mes = 0;//contador de mes
int year=2021;//ano
int *pontmes = &mes, *pontano = &year;
struct projetinho totel,*ponteiro2 = &totel;
int count;//contador universal
void clear();//limpar o terminal
int checkfile();//checar se o arquivo existe
float cript[4],g, aleatory();//variaveis para criptomoedas
void gerarextrato(),checames(),menu_banco(), despesas(), dividas(), pix(), emprestimo(), cotacao(), bradesco_prime(),refile(), valorizacao(),segundomenu(),criptobuy(),criptosell(),investimento(),comida(),transporte(); //funções do banco
FILE *file;//ponteiro p/ arquivo

//onde guarda nome/compras/agua/luz/transporte...
struct projetinho{
  char name[100];
  float transporte;
  float salary;
  float contas[7][12];
  float cript[4];
}user;


//executa o codigo principal
int main(){
    setlocale(LC_ALL, "Portuguese"); //acentuação sem bugs

  if(checkfile("file.txt")){      //verifica o usuario
    file = fopen("file.txt", "r");//se existe, lê os gastos já registrados dele e salva
    
    fscanf(file, "%[^\n]s", &user.name[0]);
    fscanf(file,"%d %d",pontmes,pontano);
    fscanf(file,"%f",&user.salary);
    
    for(int i=0;i<12;i++){ 
    for(int j=0;j<7;j++){
      fscanf(file,"%f",&user.contas[i][j]);
    }}
    fclose(file);                               //fecha o arquivo
    file = fopen("cript.txt","r");
    fscanf(file,"%f\n%f\n%f\n%f\n%f\n%f\n",&cript[0],&cript[1],&cript[2],&user.cript[0],&user.cript[1],&user.cript[2]);
    fclose(file);
  }

  else{
    count =0;
    printf("Por favor informe seu nome: ");     //caso não tenha usado o codigo ainda
    file = fopen("file.txt", "w");              //pergunta o nome e zera as contas 
    scanf("%[^\n]s",user.name);
    fprintf(file,"%s\n%d\n%d\n%f\n",user.name,mes,year,user.salary);
    for(int i=0;i<12;i++){                //faz o arquivo com contas zeradas
    for(int j=0;j<7;j++){
      fprintf(file,"%f\n",user.contas[i][j]);
    }}

    fclose(file);                                   //fecha o arquivo
    float *apoio = &cript[0];
    *apoio =349460.86;
    apoio= &cript[1];
    *apoio =25430.43;       //coloca o valor inicial das criptomoedas
    apoio= &cript[2];
    *apoio = 1.37;
    file = fopen("cript.txt","w");
    fprintf(file,"%f\n%f\n%f\n%f\n%f\n%f", 346566.02,24341.77,1.56,user.cript[0],user.cript[1],user.cript[2]);
    fclose(file); 
  }

  clear();      //limpa o terminal
  menu_banco();
  return 0;
}
//Menu do banco
void menu_banco(){
  count=0;
  printf("=================================\n"
  "Bem-vindo(a) ao Bradesco %s\n"
  "Seu saldo: R$%.2f\n"
  "=================================\n"
  "|           |Menu Bradesco|      |\n"
  "|1 - Despesas                    |\n"
  "|2 - Suas dívidas e pendencias   |\n"
  "|3 - Faça um empréstimo          |\n"
  "|4 - Bradesco Premium,venha junto|\n"
  "|5 - Salário                     |\n"
  "|6 - Agência de Câmbio           |\n"
  "|7 - Pix                         |\n"
  "|8 - Gerar extrato               |\n"
  "|9 - Mais                        |\n"
  "=================================\n",user.name,user.contas[6][mes-1]);
  scanf("%d", &count);
  count == 1?despesas():count==2?dividas():count==3?emprestimo():count==4?bradesco_prime():count==5?valorizacao():count==6?cotacao():count==7?clear(),pix():count ==8?gerarextrato():count==9?clear(),segundomenu():__fpurge(stdin),clear(),puts("Opção inválida"),menu_banco(user);  //opções possiveis
};
//segundo menu do banco
void segundomenu(){
  count=0;
  printf("=================================\n"
  "Bem-vindo(a) ao Bradesco %s\n"
  "Seu saldo: R$%.2f\n"
  "=================================\n"
  "|           |Menu Bradesco|      |\n"
  "|1 - Mercado                     |\n"
  "|2 - Transporte                  |\n"
  "|3 - Investimento                |\n"
  "|9 - Voltar                      |\n"
  "=================================\n",user.name,user.contas[6][mes-1]);
  scanf("%d", &count);
  count == 1? comida(user):count ==2?transporte(user):count ==3?clear(),investimento():count==9?clear(),menu_banco():__fpurge(stdin),clear(),puts("Opção inválida"),menu_banco();  //opções possiveis
};
//função de despesas
void despesas(){
  clear();
  if (user.salary>0){}
  else{
    printf("Nos informe, sobre o seu salario Senhor(a) %s\n",user.name);
    scanf("%f", &user.salary);
    }
    if (user.contas[0][mes]>0){}
    else{
      printf("Quanto gastou de transporte?\n");
      scanf("%f", &user.contas[0][mes]);
    }
    printf("Quanto gastou no mercado?\n");
    scanf("%f", &user.contas[1][mes]);
    printf("Quanto paga na luz?\n");
    scanf("%f", &user.contas[2][mes]);
    printf("Quanto paga de agua em sua casa?\n");
    scanf("%f", &user.contas[3][mes]);
    printf("Quanto foi gasto com aluguel?\n");
    scanf("%f", &user.contas[4][mes]);
    printf("Quanto foi gasto com sua faculdade?\n");
    scanf("%f", &user.contas[5][mes]);
    user.contas[6][mes]= user.salary+user.contas[6][mes-1] - (user.contas[0][mes]+user.contas[1][mes]+user.contas[2][mes]+user.contas[3][mes]+user.contas[4][mes]+user.contas[5][mes]); //salvar o saldo na variavel
    clear();
    printf("---------------------------------------\n"
    "|       Extrato Gerado com Sucesso!    |\n"
    "|%.2f referente à transporte.\n"
    "|%.2f referente à mercado.\n"
    "|%.2f referente à luz.\n"
    "|%.2f referente à agua.\n"
    "|%.2f referente à aluguel.\n"
    "|%.2f referente à faculdade.\n"
    "|Saldo: %.2f\n", user.contas[0][mes]*-1, user.contas[1][mes]*-1, user.contas[2][mes]*-1, user.contas[3][mes]*-1, user.contas[4][mes]*-1, user.contas[5][mes]*-1, user.contas[6][mes]); //organizar prints
    if (mes<11){
      *pontmes+=1;      //passar o mês
    }
    else{
      pontmes = &year;
      *pontmes+=1;
      pontmes = &mes;   //caso o mês seja igual a 11(jan=0,...,11=dez) volta para 0
      *pontmes=0;
    }
    refile();
    menu_banco();
};

//feature de dividas
void dividas(){
  clear();
  float cash, price;
  printf("Nos informe o preço do produto.\n");
  scanf("%f", &price);
  printf("Informe o quanto tinha no momento para efetuar esse pagamento.\n");
  scanf("%f", &cash);
  float resut = price - cash;
  printf("O senhor deve %.2f reais a loja/dono do produto.\n", resut);
  menu_banco();
};
//feature de emprestimo
void emprestimo(){
  clear();
  float value, emptotal;
  printf("De quanto seria o emprestimo? \n");
  scanf("%f", &value);
  if(value> 20000){
    printf("\npara emprestimo com valores superiores a 20.000 o juros é de 5%%\n");
    printf("Em quantos meses pretende pagar?\n");
    scanf("%d", &count);
    emptotal = value+(value/100)*5;
    emptotal= emptotal/count;
    user.contas[6][mes-1] += value;
    refile();
    printf("O valor mensal será de %.2f\n", emptotal);
  }
  else{
    printf("Em quantos meses pretende pagar?\n");
    scanf("%d", &count);
    float emptotal;
    emptotal = value+(value/100)*3.5;
    emptotal= emptotal/count;  
    printf("O valor mensal será de %.2f", emptotal);
  }
  menu_banco();
};
//feature Bradesco Prime
void bradesco_prime(){
  clear();
  printf("Bom dia senhor(a) %s, como você esta hoje?.", user.name);
  printf("Venho aqui para lhe contar a novidade do bradesco premium, nele você terá muitos beneficios como por exemplo:\n");
  printf("Compra de euro e dólar no Auto-Atendimento\n");
  printf("Desconto em ingressos para eventos como cinema e teatro.\n");
  printf("Prime Tv e muito mais!\n");
  printf("Gostaria de se juntar a nós?\n");
  scanf("%f", &user.salary);
  printf("Obrigado pela resposta, aguarde que o retornaremos!");
  menu_banco();
  };
//feature de contar aumentos
void valorizacao(){
  clear();
  float apoio,aumento;
    if (user.salary > 0){}
    else{
      printf("Informe o seu Salario: ");
      scanf("%f", &user.salary);
  }
  printf("Quanto receberá de aumento?\n");
  scanf("%f",&aumento);
  apoio= aumento;
  aumento= (aumento*100)/user.salary;
  printf("O seu aumento será de: %.2f%%",aumento);
  user.salary += apoio;
  menu_banco();
};
//feature de cotação de dolar
void cotacao(){
  clear();
  float dol, eur, cash;
  printf("Bem vindo a sala internacional do bradesco\n");
  printf("Insira seu dinheiro em reais:\n");
  scanf("%f", &cash);
  dol = cash / 5.46;
  eur = cash / 6.25;
  printf("O senhor(a) ira receber %.2f doláres\nO Dolar está a 5.48\n", dol);
  printf("O senhor(a) ira receber %.2f euros\nO Euro está a 6.35\n", eur);
  sleep(1);
  menu_banco();
};
//feature de Pix
void pix(){
  puts("-----------------Pix-------------------");
  float fake;
  double nmr;
  printf("|1 Enviar\n|2 Receber\n|3 voltar\n");
  scanf("%d",&count);
  switch(count){
    case 1:
    clear();
    printf("Quanto deseja enviar?\n");
    scanf("%f",&fake);
    (fake>user.contas[6][mes]+user.contas[6][mes-1]) ? printf("Saldo insuficiente\n") ,pix(): 0;
    printf("Digite o Número ou o CPF da destinatario\n");
    scanf("%lf",&nmr);
    printf("R$%.2f enviados para %.0lf\n", fake,nmr);
    user.contas[6][mes-1] -= fake;
    pix();
    break;

    case 2:
    clear();
    printf("Quanto deseja receber?\n");
    scanf("\n%f",&fake);
    printf("Número ou CPF do remetente?\n");
    scanf("%lf",&nmr);
    puts("Carregando...");
    sleep(5);
    printf("R$%.2f Recebidos de %.0lf\n",fake,nmr);
    user.contas[6][mes-1]+=fake;
    pix();
    break;

    case 3:
    clear();
    menu_banco();
    break;

    default:
    clear();
    puts("Opção inválida");
    __fpurge(stdin),
    pix();
    break;
    menu_banco();
  }}
//feature de comprar criptomoedas
void criptobuy(){
  int contador;
    aleatory();
  printf("Seu Saldo: R$%.2f\n\n", user.contas[6][mes-1]);

  printf("Valores:\n\n");
  g<0?printf("Valor do bitcoin: %.2f, caiu %.2f%%\n",cript[0]= cript[0]+(cript[0]/100)*g,g):printf("Valor do bitcoin: %.2f, subiu %.2f%%\n",cript[0]= cript[0]+(cript[0]/100)*g,g); //verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  aleatory();


  g<0?printf("Valor do etherium: %.2f, desceu %.2f%%\n",cript[1]= cript[1]+(cript[1]/100)*g,g):printf("Valor do etherium: %.2f, subiu %.2f%%\n",cript[1]= cript[1]+(cript[1]/100)*g,g); //verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  aleatory();
  
  g<0?printf("Valor do dogecoin: %.2f, desceu %.2f%%\n",cript[2]= cript[2]+(cript[2]/100)*g,g):printf("Valor do dogecoin: %.2f, subiu %.2f%%\n",cript[2]= cript[2]+(cript[2]/100)*g,g);//verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  refile();

  printf("\n====================\n|1 Comprar bitcoin\n|2 Comprar etherium\n|3 Comprar dogecoin\n|9 voltar\n====================\n");
  scanf("%d",&contador);
  if( contador == 9)clear(),investimento();
  if(contador != 1 && contador != 2 && contador != 3 && contador != 9){
    clear();
    __fpurge(stdin);
    puts("Opção inválida");
    criptobuy();
  }
  else{
  printf("quanto deseja investir?\n");
  scanf("%f",&g);
  g > user.contas[6][mes-1]?clear(),puts("Saldo insuficiente"),criptobuy():printf("");
  if(contador == 1){
    user.cript[0]+=g/cript[0];
    user.contas[6][mes-1]-=g;
    refile();
    criptobuy();
  }
  else if(contador == 2){
    user.cript[1]+=g/cript[1];
    user.contas[6][mes-1]-=g;
    refile();
    criptobuy();
  }
  else if(contador == 3){
    user.cript[2]+=g/cript[2];
    user.contas[6][mes-1]-=g;
    refile();
    criptobuy();
  }}
}
//feature bender criptomoedas
void criptosell(){
  int contador;
  printf("Seu Saldo: R$%.2f\n\n", user.contas[6][mes-1]);
  aleatory();

  printf("Valores:\n\n");
  g<0?printf("|Valor do bitcoin: %.2f, desceu %.2f%% |\n",cript[0]= cript[0]+(cript[0]/100)*g,g):printf("|Valor do bitcoin: %.2f, subiu %.2f%%   |\n",cript[0]= cript[0]+(cript[0]/100)*g,g);//verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  aleatory();


  g<0?printf("|Valor do etherium: %.2f, desceu %.2f%% |\n",cript[1]= cript[1]+(cript[1]/100)*g,g):printf("|Valor do etherium: %.2f, subiu %.2f%%   |\n",cript[1]= cript[1]+(cript[1]/100)*g,g);//verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  aleatory();
  
  g<0?printf("|Valor do dogecoin: %.2f, desceu %.2f%%     |\n",cript[2]= cript[2]+(cript[2]/100)*g,g):printf("|Valor do dogecoin: %.2f, subiu %.2f%%       |\n",cript[2]= cript[2]+(cript[2]/100)*g,g);//verifica se a moeda desvalorizou ou não e printa caiu ou subiu


  refile();
  printf("====================\n\n|1 Vender bitcoin\n|2 Vender etherium\n|3 Vender dogecoin\n|9 Voltar\n====================\n");
  scanf("%d",&contador);
  switch(contador){

  case 1:
    if(user.cript[0]>0)printf("");  //verifica se ele tem a moeda 
    else clear(),printf("Você não tem bitcoins\n"),criptosell();//caso nn tenha volta
    printf("Deseja vender %f bitcoins?\n|1 Sim\n|2 Não\n", user.cript[0]);
    scanf("%d",&contador);
    if(contador == 1){
      user.contas[6][mes-1]+= user.cript[0]*cript[0];
      user.cript[0]=0;
      criptosell();}
    else if(contador == 2){
      criptosell();}
    else{
      printf("Opção invalida\n");
      __fpurge(stdin);
      criptosell();}
  break;

  case 2:
    if(user.cript[1]>0)printf("");  //verifica se ele tem a moeda 
    else clear(),printf("Você não tem etherium\n"),criptosell();//caso nn tenha volta
    printf("Deseja vender %f etherium?\n|1 Sim\n|2 Não\n", user.cript[1]);
    scanf("%d",&contador);
    if(contador == 1){
      user.contas[6][mes-1]+= user.cript[1]*cript[1]; //aumenta com o valor da moeda
      user.cript[1]=0;  //zera oq o usuario tem
      criptosell();}
    else if(contador == 2){
      criptosell();}
      //count
    else{
      printf("Opção invalida\n");
      __fpurge(stdin);
      criptosell();}
  break;

  case 3:
    if(user.cript[2]>0)printf("");  //verifica se ele tem a moeda 
    else clear(),printf("Você não tem dogecoins\n"),criptosell(); //caso nn tenha volta
    printf("Deseja vender %f dogecoins?\n|1 Sim\n|2 Não\n", user.cript[2]);
    scanf("%d",&contador);
    if(contador == 1){
      user.contas[6][mes-1]+= user.cript[2]*cript[2]; //aumenta com o valor da moeda
      user.cript[2]=0;  //zera o que o usuario tem
      criptosell();}
    else if(contador == 2){
      criptosell();}
    else{
      printf("Opção invalida\n");
      __fpurge(stdin);
      criptosell();}
  break;

  case 9:
    clear();
    investimento(); //volta

  default:
    __fpurge(stdin);
    clear();
    puts("Opção invalida"); //caso não exista volta, limpa e printa invalida
    criptosell();
    }
}
//feature de compra/venda de criptomoedas
void investimento(){
  count = 0;
  printf("Bem Vindo ao BitMart\n\n");
  printf("Seu Saldo: R$%.2f\n\n", user.contas[6][mes-1]);
  srand(time(NULL));
  printf("====================\n|1 Minha carteira\n|2 Comprar moedas\n|3 Vender moedas\n|9 Voltar\n====================\n");
  scanf("%d",&count);
  switch(count){

  case 1:
  clear();
  printf("Você tem:\n%f bitcoins\n%f etheriums\n%f dogecoins\n", user.cript[0],user.cript[1],user.cript[2]);
  investimento();
  break;

  case 2:
  clear();
  criptobuy();
  break;

  case 3:
  clear();
  criptosell();
  break;

  case 9:
  clear();
  menu_banco();
  break;

  default:
  clear();
  __fpurge(stdin);
  printf("Opção invalida\n");
  investimento();
  }
}
//função para gerar html com o extrato mensal
void gerarextrato(){
  char meses[37]="JanFevMarAbrMaiJunJulAgoSetOutNovDez";
  clear();
  printf("Deseja Imprimir:\n|1 últimos 12 Meses\n|2 último mês\n|3 Voltar\n");
  scanf("%d",&count);
  if(count == 1){
  file = fopen("Extrato_ano.html", "w");
  fprintf(file,"<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<title>Projeto</title>\n<style>\n table{\nborder-style: outset;\nborder-width:medium;\nbackground-color:SteelBlue;\nbox-shadow: 10px 10px 10px 10px black;}\ntr{\nborder-style: groove;}\nth{\nborder-style: groove;}\nbody{\nbackground-color: Thistle;\n}\n</style></head>\n<body>\n<p style=text-align:center>%d</p>\n<table id=\"tablee\">\n<tr>\n",year);
  for(count =0; count<36;count+=3){
    fprintf(file,"<th>%c%c%c</th>\n",meses[count],meses[count+1],meses[count+2]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Aquamarine\">Transpote: %.2f</td>\n", user.contas[0][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"SpringGreen\">Mercado: %.2f</td>\n", user.contas[1][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Yellow\">Energia: %.2f</td>\n", user.contas[2][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"Gold\">Água: %.2f</td>\n", user.contas[3][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"CornflowerBlue\">Aluguel: %.2f</td>\n", user.contas[4][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"RosyBrown\">Faculdade: %.2f</td>\n", user.contas[5][count]);}
  fprintf(file,"</tr>\n");
  for(count = 0; count<12;count++){
    fprintf(file,"<td bgcolor=\"LightCoral\">Saldo: %.2f</td>\n", user.contas[6][count]);}
  fprintf(file,"</table>\n</body>\n</html>");
  fclose(file);
  puts("Extrato impresso!");
  }
  else if(count == 2){
  file = fopen("Extrato_mes.html", "w"); //cria um arquivo para o mes
  //escreve o basico do html e depois as contas no arquivo
  fprintf(file,"<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<title>Projeto</title>\n<style>\n table{\nborder-style: outset;\nborder-width:medium;\nbackground-color:SteelBlue;\nbox-shadow: 10px 10px 10px 10px black;}\ntr{\nborder-style: groove;}\nth{\nborder-style: groove;}\nbody{\nbackground-color: Thistle;\n} \n</style></head>\n<body>\n<p style=text-align:center>%d</p>\n<table id=\"tablee\">\n<tr>\n",year);
  fprintf(file,"<th>%c%c%c</th>\n</tr>\n<td bgcolor=\"Aquamarine\">Transpote: %.2f</td>\n</tr>\n<td bgcolor=\"SpringGreen\">Mercado: %.2f</td>\n</tr>\n<td bgcolor=\"Yellow\">Energia: %f</td>\n</tr>\n<td bgcolor=\"Gold\">Água: %.2f</td>\n</tr>\n<td bgcolor=\"CornflowerBlue\">Aluguel: %.2f</td>\n</tr>\n<td bgcolor=\"RosyBrown\">Faculdade: %f</td>\n</tr>\n<td bgcolor=\"LightCoral\">Saldo: %.2f</td>\n</tr>\n</table>\n</body>\n</html>",meses[mes*3],meses[mes*3+1],meses[mes*3+2], user.contas[0][mes-1],user.contas[1][mes-1],user.contas[2][mes-1],user.contas[3][mes-1],user.contas[4][mes-1],user.contas[5][mes-1],user.contas[6][mes-1]);
  fclose(file);
  puts("Extrato impresso!");
  }
  else if(count == 3){
    clear();
    menu_banco();
  }
  else{
    __fpurge(stdin);
    puts("Opção inválida");
    gerarextrato();
  }
  menu_banco();
}
//função para atualizar os arquivos
void refile(){
  file = fopen("file.txt","w");//reescreve o arquivo de contas toda vez que for feito as despesas
  fprintf(file,"%s\n%d\n%d\n%f\n",user.name,mes,year,user.salary);
  for(int i=0;i<12;i++){
    for(int j=0;j<7;j++){
      fprintf(file,"%f\n",user.contas[i][j]);
    }
  }
  fclose (file);
  file = fopen("cript.txt","w");//reescreve o arquivo de criptomoedas toda vez
  fprintf(file,"%f\n%f\n%f\n%f\n%f\n%f\n",cript[0],cript[1],cript[2],user.cript[0],user.cript[1],user.cript[2]);
  fclose (file);
}
//feature de mercado
void comida(){
  count = 0;
  float feito1, coisa, pp;
  printf("---------------------------------\n|Bem vindo ao Walmart:\n|1 - Pão Francês\n|2 - frios\n|3 - frutas\n|4 - Carne\n|5 - Condimentos\n|6 - Ofertas do Dia\n|7 - Voltar\n---------------------------------\n");
  scanf("%d", &count);
  switch (count){
    case 1:
    coisa = 16.90;
    printf("1kg Pão Frances custa 16.90R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"),comida():printf("troco: %.2f\n", pp),comida();
    break;

    case 2:
    coisa = 35.65;
    printf("O 500g de frios é 35.65R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"),comida():printf("troco: %.2f\n", pp),comida();
    break;

    case 3:
    coisa = 6.50;
    printf("O kilo da Batata custa 6.50R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"),comida():printf("troco: %.2f\n", pp),comida();
    break;

    case 4:
    coisa = 70;
    printf("O kilo da carne custa 70R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"),comida():printf("troco: %.2f\n", pp),comida();
    break;

    case 5:
    coisa = 7;
    printf("Os condimentos custa 7R$\n");
    scanf("%f", &feito1);
    pp = (feito1 - coisa);
    pp < 0 ? printf("Ta pobre em amigo\n"),comida():printf("troco: %.2f\n", pp),comida();
    break;

    case 7:
    menu_banco();
    case 6:
    clear();
    count = 0;
    printf("Qual oferta gostaria de ver?\n|1 Segunda-feira\n|2 Terça-feira\n|3 Quarta-feira\n|4 Quinta-feira|\n|5 Sexta-feira\n|6 Sabado|\n|7 Domingo|\n|8 Voltar|\n");
    scanf("%d", &count);
    float res,pp,coisa;
    switch(count){
      case 1:
      coisa = 3;
      printf("O chocolate Biz está 3R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): printf("Saldo insuficiente\n"),comida();
      break;

      case 2:
      coisa = 5.50;
      printf("Refrigerante Coca-cola 5.50R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): printf("Saldo insuficiente\n"),comida();
      break;

      case 3:
      coisa = 2;
      printf("Bolacha salgada/doce 2R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): clear(),printf("Saldo insuficiente\n"),comida();
      break;

      case 4:
      coisa = 7;
      printf("Salgadinho cheetos 7R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): clear(),printf("Saldo insuficiente\n"),comida();
      break;

      case 5:
      coisa= 2.89;
      printf("Detergente está 2.89R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): clear(),printf("Saldo insuficiente\n"),comida();
      break;

      case 6:
      coisa = 41.50;
      printf("Amaciante está 13R$\nShaampo clear-men 8.50R$\nCaixa de leite está 20R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): clear(),printf("Saldo insuficiente\n"),comida();
      break;

      case 7:
      coisa = 10;
      printf("O suco DeValle está 10R$\nFarinha está 6R$\n");
      scanf("%f", &pp);
      res = pp - coisa;
      0 <= res ? clear(),printf("Saldo Restante: %.2f\n",res),comida(): printf("Saldo insuficiente\n"),comida();
      break;

      case 8:
      clear();
      comida();
      break;

      default:
      __fpurge(stdin);
      clear();
      printf("Opção invalida\n");
      comida();
    }
    default:
    __fpurge(stdin);
    clear();
    printf("Opção invalida\n");
    comida();
  }
}
//feature de condução
void transporte(struct projetinho user){
  printf("Em qual setor o você mora?\n"
  "----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
  scanf("%d",&count);
  if (count == 1 || count == 2 || count == 3 || count == 4 || count == 5){
    printf("E aonde você estuda? \n");
    printf("----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
    scanf("%d", &count);
    printf("E aonde você trabalha?\n"
    "----------------------------\n1 SP\n2 SBC\n3 SA\n4 SCS\n5 SM\n----------------------------\n");
    scanf("%d",&count);
    printf("Como você vai de sua casa para seu serviço?\n"
    "----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    float ex, ex2;
    scanf("%d",&count);
    if (count == 1){
      ex = 4.40;
    }
    else if(count == 2){
      ex = 9.98;
    }
    else if(count == 3){
      ex = 0;
    }
    else if (count == 4){
      ex = 0;
    }
    else if (count == 5){
      ex = 10;
    }
    else{
      __fpurge(stdin);
    clear();
    puts("Opção inválida");
    transporte(user);
    }
    printf("Como você vai do seu serviço á sua faculdade?\n"
    "----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    scanf("%d",&count);
    if (count == 1){
      ex2 = 4.40;
      ex=ex+ex2;
    }
    else if(count == 2){
      ex2 = 9.98;
      ex=ex+ex2;
    }
    else if(count == 3){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 4){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 5){
      ex2 = 10;
      ex=ex+ex2;
    }
    else{
      __fpurge(stdin);
    clear();
    puts("Opção inválida");
    transporte(user);
    }
    printf("Como você vai da sua faculdade á sua Residencia?\n"
    "----------------------------\n1 Metro\n2 Carro\n3 Bike\n4 Andando\n5 Uber\n----------------------------\n");
    scanf("%d",&count);
    if (count == 1){
      ex2 = 4.40;
      ex=ex+ex2;
    }
    else if(count == 2){
      ex2 = 9.98;
      ex=ex+ex2;
    }
    else if(count == 3){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 4){
      ex2 = 0;
      ex=ex+ex2;
    }
    else if (count == 5){
      ex2 = 10;
      ex=ex+ex2;
    }
    else{
      __fpurge(stdin);
    clear();
    puts("Opção inválida");
    transporte(user);
    }
    user.transporte = ex;
  printf("%s você gastou %.2f no transfer hoje\n", user.name, ex);
  }
  else{
    __fpurge(stdin);
    clear();
    puts("Opção inválida");
    transporte(user);
  }
  menu_banco();
}
//função de limpar o terminal
void clear(){
  system("@cls||clear");
}
//função de checar existencia de arquivo
int checkfile(const char* filename){
    struct stat buffer;
    int existencia = stat(filename,&buffer);
    if(existencia == 0)
        return 1;
    else  
        return 0;
}
//função que gera floats aleatorios
float aleatory(){
  g = (float)rand()/(float)(RAND_MAX/3);
  g>2?g = g*0.1*-1: 0;
  return g;
}