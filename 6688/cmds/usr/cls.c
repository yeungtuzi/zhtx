// cls.c build by maht

inherit F_CLEAN_UP;
int do_nothing(string input);

int main(object who,string arg)
{   int i;
    if((string)who->query("env/term")!="zMUD")
        write("[2J[0;0H");
    else
    {
        write(@TEXT
// time.c

inherit F_CLEAN_UP;
  int main(object me, string arg)
 {
  int i;
  int times;
  times=15
   for(i=0;i<times;i++)
TEXT );
    for(i=0;i<15;i++)
	printf("\n");
    }
    write("按ＥＮＴＥＲ继续……");
    input_to((:do_nothing:));
return 1;
}
int do_nothing(string input)
{
    return 1;
}

int help(object who)
{
    write(@HELP
这个指令可以清除你的屏幕。

对于象zMUD一类的不很好支持ansi的远程登陆软体，可以
set term zMUD,这样就有一段程序在你的屏幕上……
HELP );
    return 1;
}
