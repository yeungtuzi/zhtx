// by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;
string look_shenxiang();

void create()
{
	set("short", "岳坟");
	set("long", @LONG
		这是武穆公岳飞的坟墓，里面似乎有什么秘密。相传岳飞被害后，
留下武穆遗书，江湖中许多人为之拼死争夺。几十年前该书却失去踪影，会不会在
这儿，四周空荡荡的，只有大殿中央有一蹲巨大无朋的岳飞像(shenxiang)，上面好
象有什么东西，不知怎样才能上去。
LONG
	);
	set("exits", ([
		"out" : __DIR__"shuidi",
])); 
	set("item_desc", ([
	"shenxiang" : (: look_shenxiang :),
	]));
	setup();
}                      

string look_shenxiang()
{
	return GRN"只见神像上写到：老夫一生忠于君主。凡我传人，\n"
"这“忠君”和“爱国”是一定要记在心上的。\n\n 岳飞\n"NOR;
}                                     

void init()
{
	add_action("do_climb", "climb");
} 
                                            
int do_climb(string arg)
{
        object me;
	// 2026-04-30: unused variable commented out
	// object obj;
	object ob;
	ob = this_player();
        
        if ( !arg || arg != "shenxiang" )
                return notify_fail("你要爬什麽?\n");
        
        me=this_player();
        
        if ( ((int)me->query_skill("dodge") < 50) ) { 
                tell_object(me, "你轻功太低，爬不上去。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<200))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
 
        me->receive_damage("gin",15);
        me->receive_damage("kee",10);
        message_vision("$N手脚并用，慢慢地往上爬。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N终于爬了上去。\n",me);
                this_player()->move(__DIR__"xding");
                message("vision","$N眼前是一块小平台.\n",
	environment(me),me);
        	tell_room(__DIR__"yuefen","$N爬上了神像。\n",me);
                return(1);
        }
        return(1);
}
  


                                                




