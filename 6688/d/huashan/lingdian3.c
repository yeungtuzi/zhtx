//lingdian3.c西侧殿
//By Emote
inherit ROOM;
#include <ansi.h>

int do_turn(string arg);
string look_shibei();
void create()
{
	set("short","西侧殿");
	set("long",
@LONG
这里是濪灵殿的西侧殿，这里放着历代文人骚客所书的赞颂西岳华山的
书法珍品，其中最著名的就是东汉恒帝延熹八年的《西岳华山庙碑》，还有
还有宋拓“长恒”，“华阴”，“四明”等珍贵摹本。不过你可不能随便动这些东
西。
LONG);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"lingdian1",
]));
   	set("can_push",2);

	set("item_desc", ([
                "shibei": (: look_shibei :),
                "石碑"   : (: look_shibei :),
                "《西岳华山庙碑》": (: look_shibei :),
        ]));
        setup();
        
	
}
 
void init()
{
	add_action("do_turn","turn");	
}

int do_turn(string arg)
{
	object ppl=this_player();
	string target,dir;
       if( !arg || sscanf(arg, "%s %s", target, dir)!=2 )
	  return notify_fail("你要推什么？");
	if(target=="石碑" || target=="shibei")
	{
	   
	   if(ppl->query("force")<50
	   || !query("can_push"))
	      return notify_fail("你用尽全身力气去推石碑，可是石碑纹丝不动。\n");
	   if(dir=="left")
	   {
	   	add("can_push",-1);
	   	set("pusher",ppl->query("id"));
	   	message_vision("$N用尽全身力气，大喝一声，结果石碑缓缓转动了一个方向。",ppl);
	   	return 1;	
	   }
	   else if(dir=="right")
	   	{
	   				add("can_push",-1);
	   				delete("pusher");
	   				message_vision("$N用尽全身力气，大喝一声，结果石碑缓缓转动了一个方向，挪回了原位。",ppl);
	   				return 1;
	   	}
                return 0;
	
	}	
        return 0;
}

string look_shibei()
{
	return "这块石碑表面十分光滑，好象有人经常触抹一样。\n";	
}
