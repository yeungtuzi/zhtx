// alias.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("你目前并没有设定任何 alias。\n");
			return 1;
		} else  {
			write("你目前设定的 alias 有：\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( verb=="alias" )
		return notify_fail("你不能将 \"alias\" 指令设定其他用途。\n");
	else if( verb=="" )
		return notify_fail("你要设什麽 alias？\n");
	else
		return me->set_alias(verb, replace);

	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : alias <欲设定之指令> <系统提供之指令>
 
有时系统所提供之指令需要输入很长的字串, 在使用时(尤其是经常用到的)
或许会感觉不方便, 此时你(□)即可用此一指令设定并替代原有之指令。
 
□例:
	'alias sc score' 会以 sc 取代 score 指令。
	'alias' 後不加参数则列出你所有的替代指令。
	'alias sc' 会消除 sc 这个替代指令。 (如果你有设的话)
 
其中可以用 $1, $2, $3 .... 来取代第一、第二、第三个参数，或是 $* 取代
所有的参数，如：
	'alias pb put $1 in $2'

则每当你(□)打：
	pb bandage bag

就会取代成：
	put bandage in bag

另:关于server-side alias

现在 alias 支持定义一次定义一组命令,命令之间用";"分割.

比如:

你目前设定的 alias 有：
dwd             = s;sd;sd;sd;sd;ed;ed;se;se;e;n;n;ne;nw;n

当你输入dwd的时候,就会依次执行上面这些命令(从武当山三清殿跑到洛阳).

确省情况下,不论";"出现在什么地方,都被作为命令的分割符来对待,
考虑到有可能需要用到;的地方,对 alias 的解析有以下规则:

1. 所有以alias开头的命令不解析";",方便定义.
2. 用$p-来指示不解析这一行的";",不管$p-出现在该行的什么地方
3. 使用者可以set parse_cmd off来强制关闭所有的对";"的解析

by YEUNG 1999/07/25.
	
HELP
);
        return 1;
}
